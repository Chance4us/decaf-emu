#ifdef DECAF_VULKAN

#include "tiling_tests.h"
#include "addrlib_helpers.h"
#include "test_helpers.h"

#include <common/align.h>
#include <libgpu/gpu7_tiling_vulkan.h>
#include <vector>

#include "vulkan_helpers.h"

static gpu7::tiling::vulkan::Retiler gVkRetiler;

static inline void
compareTilingToAddrLib(const gpu7::tiling::SurfaceDescription& desc,
                       std::vector<uint8_t>& input,
                       uint32_t firstSlice, uint32_t numSlices)
{
   // Set up AddrLib to generate data to test against
   auto addrLib = AddrLib { };

   auto alibUntiled = std::vector<uint8_t> { };
   auto gpu7Untiled = std::vector<uint8_t> { };
   auto alibTiled = std::vector<uint8_t> { };
   auto gpu7Tiled = std::vector<uint8_t> { };

   // Compute surface info
   auto alibInfo = addrLib.computeSurfaceInfo(desc, 0, 0);
   auto gpu7Info = gpu7::tiling::computeSurfaceInfo(desc, 0);

   REQUIRE(gpu7Info.surfSize == alibInfo.surfSize);
   REQUIRE(input.size() >= gpu7Info.surfSize);

   alibUntiled.resize(alibInfo.surfSize);
   alibTiled.resize(alibInfo.surfSize);
   gpu7Untiled.resize(gpu7Info.surfSize);
   gpu7Tiled.resize(gpu7Info.surfSize);

   // AddrLib
   {
      addrLib.untileSlices(desc, 0, input.data(), alibUntiled.data(), firstSlice, numSlices);
      addrLib.tileSlices(desc, 0, alibUntiled.data(), alibTiled.data(), firstSlice, numSlices);
   }

   // Get the sizes we will use for our buffers.  We oversize the work
   // buffers to avoid errors causing buffer overruns which crash my GPU.
   auto surfSize = gpu7Info.surfSize;
   auto uploadSize = gpu7Info.surfSize;
   auto workSize = gpu7Info.surfSize * 2;

   // Create input/output buffers
   auto uploadBuffer = allocateSsboBuffer(uploadSize, SsboBufferUsage::CpuToGpu);
   auto inputBuffer = allocateSsboBuffer(workSize, SsboBufferUsage::Gpu);
   auto untiledOutputBuffer = allocateSsboBuffer(workSize, SsboBufferUsage::Gpu);
   auto tiledOutputBuffer = allocateSsboBuffer(workSize, SsboBufferUsage::Gpu);
   auto untiledDownloadBuffer = allocateSsboBuffer(surfSize, SsboBufferUsage::CpuToGpu);
   auto tiledDownloadBuffer = allocateSsboBuffer(surfSize, SsboBufferUsage::CpuToGpu);

   // Upload to the upload buffer
   uploadSsboBuffer(uploadBuffer, input.data(), uploadSize);

   {
      // Allocate a command buffer and fence
      auto cmdBuffer = allocSyncCmdBuffer();
      beginSyncCmdBuffer(cmdBuffer);

      // Barrier our host writes the transfer reads
      globalVkMemoryBarrier(cmdBuffer.cmds, vk::AccessFlagBits::eHostWrite, vk::AccessFlagBits::eTransferRead);

      // Clear the input/output buffers to a known value so its obvious if something goes wrong
      cmdBuffer.cmds.fillBuffer(inputBuffer.buffer, 0, surfSize, 0xffffffff);
      cmdBuffer.cmds.fillBuffer(inputBuffer.buffer, surfSize, workSize - surfSize, 0xfefefefe);
      cmdBuffer.cmds.fillBuffer(untiledOutputBuffer.buffer, 0, surfSize, 0x00000000);
      cmdBuffer.cmds.fillBuffer(untiledOutputBuffer.buffer, surfSize, workSize - surfSize, 0x01010101);
      cmdBuffer.cmds.fillBuffer(tiledOutputBuffer.buffer, 0, surfSize, 0x00000000);
      cmdBuffer.cmds.fillBuffer(tiledOutputBuffer.buffer, surfSize, workSize - surfSize, 0x01010101);

      // Copy the data
      cmdBuffer.cmds.copyBuffer(uploadBuffer.buffer, inputBuffer.buffer, { vk::BufferCopy(0, 0, uploadSize) });

      // Barrier our transfers to the shader reads
      globalVkMemoryBarrier(cmdBuffer.cmds, vk::AccessFlagBits::eTransferWrite, vk::AccessFlagBits::eShaderRead);

      // Dispatch the actual retile
      auto retileInfo = gpu7::tiling::computeRetileInfo(gpu7Info);

      auto tiledFirstSliceIndex = align_down(firstSlice, retileInfo.microTileThickness);
      auto tiledSliceOffset = tiledFirstSliceIndex * retileInfo.thinSliceBytes;
      auto untiledSliceOffset = firstSlice * retileInfo.thinSliceBytes;

      auto untileHandle = gVkRetiler.untile(retileInfo,
                                            cmdBuffer.cmds,
                                            untiledOutputBuffer.buffer, untiledSliceOffset,
                                            inputBuffer.buffer, tiledSliceOffset,
                                            firstSlice, numSlices);

      // Barrier between these to force the pipeline flush
      globalVkMemoryBarrier(cmdBuffer.cmds, vk::AccessFlagBits::eShaderWrite, vk::AccessFlagBits::eShaderRead);

      auto tileHandle = gVkRetiler.tile(retileInfo,
                                        cmdBuffer.cmds,
                                        tiledOutputBuffer.buffer, tiledSliceOffset,
                                        untiledOutputBuffer.buffer, untiledSliceOffset,
                                        firstSlice, numSlices);

      // Put a barrier from the shader writes to the transfers
      globalVkMemoryBarrier(cmdBuffer.cmds, vk::AccessFlagBits::eShaderWrite, vk::AccessFlagBits::eTransferRead);

      // Copy the output buffer to the download buffer
      cmdBuffer.cmds.copyBuffer(untiledOutputBuffer.buffer, untiledDownloadBuffer.buffer, { vk::BufferCopy(0, 0, surfSize) });
      cmdBuffer.cmds.copyBuffer(tiledOutputBuffer.buffer, tiledDownloadBuffer.buffer, { vk::BufferCopy(0, 0, surfSize) });

      // Put a barrier from the transfer writes to the host reads
      globalVkMemoryBarrier(cmdBuffer.cmds, vk::AccessFlagBits::eTransferWrite, vk::AccessFlagBits::eHostRead);

      // End, execute and free this buffer
      endSyncCmdBuffer(cmdBuffer);
      execSyncCmdBuffer(cmdBuffer);
      freeSyncCmdBuffer(cmdBuffer);

      // Free the retiler resources we used
      gVkRetiler.releaseHandle(untileHandle);
      gVkRetiler.releaseHandle(tileHandle);
   }

   // Capture the retiled data from the GPU
   downloadSsboBuffer(untiledDownloadBuffer, gpu7Untiled.data(), surfSize);
   downloadSsboBuffer(tiledDownloadBuffer, gpu7Tiled.data(), surfSize);

   // Free the buffers associated with this
   freeSsboBuffer(uploadBuffer);
   freeSsboBuffer(inputBuffer);
   freeSsboBuffer(untiledOutputBuffer);
   freeSsboBuffer(tiledOutputBuffer);
   freeSsboBuffer(untiledDownloadBuffer);
   freeSsboBuffer(tiledDownloadBuffer);

   // Compare that the images match
   CHECK(compareImages(gpu7Untiled, alibUntiled));
   CHECK(compareImages(gpu7Tiled, alibTiled));
}

TEST_CASE("vkTiling")
{
   for (auto& layout : sTestLayout) {
      SECTION(fmt::format("{}x{}x{} s{}n{}",
                          layout.width, layout.height, layout.depth,
                          layout.testFirstSlice, layout.testNumSlices))
      {
         for (auto& mode : sTestTilingMode) {
            SECTION(fmt::format("{}", tileModeToString(mode.tileMode)))
            {
               for (auto& format : sTestFormats) {
                  SECTION(fmt::format("{}bpp{}", format.bpp, format.depth ? " depth" : ""))
                  {
                     auto surface = gpu7::tiling::SurfaceDescription { };
                     surface.tileMode = mode.tileMode;
                     surface.format = format.format;
                     surface.bpp = format.bpp;
                     surface.width = layout.width;
                     surface.height = layout.height;
                     surface.numSlices = layout.depth;
                     surface.numSamples = 1u;
                     surface.numLevels = 1u;
                     surface.bankSwizzle = 0u;
                     surface.pipeSwizzle = 0u;
                     surface.dim = gpu7::tiling::SurfaceDim::Texture2DArray;
                     surface.use = format.depth ?
                        gpu7::tiling::SurfaceUse::DepthBuffer :
                        gpu7::tiling::SurfaceUse::None;

                     compareTilingToAddrLib(surface,
                                            sRandomData,
                                            layout.testFirstSlice,
                                            layout.testNumSlices);
                  }
               }
            }
         }
      }
   }
}

struct PendingVkPerfEntry
{
   gpu7::tiling::SurfaceDescription desc;
   uint32_t firstSlice;
   uint32_t numSlices;

   gpu7::tiling::SurfaceInfo info;
   SsboBuffer uploadBuffer;
   SsboBuffer inputBuffer;
   SsboBuffer outputBuffer;

   gpu7::tiling::vulkan::RetileHandle handle;
};

TEST_CASE("vkTilingPerf", "[!benchmark]")
{
   // Set up AddrLib to generate data to test against
   auto addrLib = AddrLib { };

   // Get some random data to use
   auto& untiled = sRandomData;

   // Some place to store pending tests
   std::vector<PendingVkPerfEntry> pendingTests;

   // Generate all the test cases to run
   auto& layout = sPerfTestLayout;
   for (auto& mode : sTestTilingMode) {
      for (auto& format : sTestFormats) {
         auto surface = gpu7::tiling::SurfaceDescription { };
         surface.tileMode = mode.tileMode;
         surface.format = format.format;
         surface.bpp = format.bpp;
         surface.width = layout.width;
         surface.height = layout.height;
         surface.numSlices = layout.depth;
         surface.numSamples = 1u;
         surface.numLevels = 1u;
         surface.bankSwizzle = 0u;
         surface.pipeSwizzle = 0u;
         surface.dim = gpu7::tiling::SurfaceDim::Texture2DArray;
         surface.use = format.depth ?
            gpu7::tiling::SurfaceUse::DepthBuffer :
            gpu7::tiling::SurfaceUse::None;

         PendingVkPerfEntry test;
         test.desc = surface;
         test.firstSlice = layout.testFirstSlice;
         test.numSlices = layout.testNumSlices;
         pendingTests.push_back(test);
      }
   }

   // Set up all the tests
   for (auto& test : pendingTests) {
      // Compute some needed surface information
      auto info = gpu7::tiling::computeSurfaceInfo(test.desc, 0);
      auto surfSize = static_cast<uint32_t>(info.surfSize);

      // Make sure our test data is big enough
      REQUIRE(untiled.size() >= info.surfSize);

      // Create input/output buffers
      auto uploadBuffer = allocateSsboBuffer(surfSize, SsboBufferUsage::CpuToGpu);
      auto inputBuffer = allocateSsboBuffer(surfSize, SsboBufferUsage::Gpu);
      auto outputBuffer = allocateSsboBuffer(surfSize, SsboBufferUsage::Gpu);

      // Upload to the upload buffer
      uploadSsboBuffer(uploadBuffer, untiled.data(), surfSize);

      // Store the state between setup loops
      test.info = info;
      test.uploadBuffer = uploadBuffer;
      test.inputBuffer = inputBuffer;
      test.outputBuffer = outputBuffer;
   }

   // Copy our uploaded data to the input buffers
   {
      auto cmdBuffer = allocSyncCmdBuffer();
      beginSyncCmdBuffer(cmdBuffer);

      for (auto& test : pendingTests) {
         auto surfSize = static_cast<uint32_t>(test.info.surfSize);

         // Barrier our host writes the transfer reads
         globalVkMemoryBarrier(cmdBuffer.cmds, vk::AccessFlagBits::eHostWrite, vk::AccessFlagBits::eTransferRead);

         // Set up the input/output buffers on the GPU
         cmdBuffer.cmds.copyBuffer(test.uploadBuffer.buffer,
                                   test.inputBuffer.buffer,
                                   { vk::BufferCopy(0, 0, surfSize) });

         // Barrier our transfers to the shader reads
         globalVkMemoryBarrier(cmdBuffer.cmds, vk::AccessFlagBits::eTransferWrite, vk::AccessFlagBits::eShaderRead);
      }

      endSyncCmdBuffer(cmdBuffer);
      execSyncCmdBuffer(cmdBuffer);
      freeSyncCmdBuffer(cmdBuffer);
   }

   // Run the retiles
   {
      auto cmdBuffer = allocSyncCmdBuffer();
      beginSyncCmdBuffer(cmdBuffer);

      for (auto& test : pendingTests) {
         // Calculate data on how to retile
         auto retileInfo = gpu7::tiling::computeRetileInfo(test.info);

         auto tiledFirstSliceIndex = align_down(test.firstSlice, retileInfo.microTileThickness);
         auto tiledSliceOffset = tiledFirstSliceIndex * retileInfo.thinSliceBytes;
         auto untiledSliceOffset = test.firstSlice * retileInfo.thinSliceBytes;

         // Dispatch the actual retile
         auto handle = gVkRetiler.untile(retileInfo,
                                         cmdBuffer.cmds,
                                         test.outputBuffer.buffer, untiledSliceOffset,
                                         test.inputBuffer.buffer, tiledSliceOffset,
                                         test.firstSlice, test.numSlices);

         // Save some information for freeing later
         test.handle = handle;
      }

      endSyncCmdBuffer(cmdBuffer);

      BENCHMARK(fmt::format("processing ({} retiles)", pendingTests.size()))
      {
         execSyncCmdBuffer(cmdBuffer);
      };

      freeSyncCmdBuffer(cmdBuffer);
   }

   // Clean up all our resources used...
   for (auto& test : pendingTests) {
      // Free the retiler resources we used
      gVkRetiler.releaseHandle(test.handle);

      // Free the buffers we allocated
      freeSsboBuffer(test.uploadBuffer);
      freeSsboBuffer(test.inputBuffer);
      freeSsboBuffer(test.outputBuffer);
   }
}

bool vulkanBeforeStart()
{
   if (!initialiseVulkan()) {
      return false;
   }

   // Initialize our retiler
   gVkRetiler.initialise(gDevice);
   return true;
}

bool vulkanAfterComplete()
{
   return shutdownVulkan();
}

#endif // DECAF_VULKAN
