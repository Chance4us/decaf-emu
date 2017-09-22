#pragma once
#include "ios_kernel_enum.h"
#include "ios/ios_result.h"

#include <cstdint>
#include <libcpu/be2_struct.h>
#include <common/structsize.h>

namespace ios::kernel
{

using HeapID = int32_t;
struct HeapBlock;

struct Heap
{
   be2_phys_ptr<void> base;
   be2_val<ProcessID> pid;
   be2_val<uint32_t> size;
   be2_phys_ptr<HeapBlock> firstFreeBlock;
   be2_val<uint32_t> errorCountAllocOutOfMemory;
   be2_val<uint32_t> errorCountFreeBlockNotInHeap;
   be2_val<uint32_t> errorCountExpandInvalidBlock;
   be2_val<uint32_t> errorCountCorruptedBlock;
   be2_val<HeapFlags> flags;
   be2_val<uint32_t> currentAllocatedSize;
   be2_val<uint32_t> largestAllocatedSize;
   be2_val<uint32_t> totalAllocCount;
   be2_val<uint32_t> totalFreeCount;
   be2_val<uint32_t> errorCountFreeUnallocatedBlock;
   be2_val<uint32_t> errorCountAllocInvalidHeap;
   be2_val<HeapID> id;
};
CHECK_OFFSET(Heap, 0x00, base);
CHECK_OFFSET(Heap, 0x04, pid);
CHECK_OFFSET(Heap, 0x08, size);
CHECK_OFFSET(Heap, 0x0C, firstFreeBlock);
CHECK_OFFSET(Heap, 0x10, errorCountAllocOutOfMemory);
CHECK_OFFSET(Heap, 0x14, errorCountFreeBlockNotInHeap);
CHECK_OFFSET(Heap, 0x18, errorCountExpandInvalidBlock);
CHECK_OFFSET(Heap, 0x1C, errorCountCorruptedBlock);
CHECK_OFFSET(Heap, 0x20, flags);
CHECK_OFFSET(Heap, 0x24, currentAllocatedSize);
CHECK_OFFSET(Heap, 0x28, largestAllocatedSize);
CHECK_OFFSET(Heap, 0x2C, totalAllocCount);
CHECK_OFFSET(Heap, 0x30, totalFreeCount);
CHECK_OFFSET(Heap, 0x34, errorCountFreeUnallocatedBlock);
CHECK_OFFSET(Heap, 0x38, errorCountAllocInvalidHeap);
CHECK_OFFSET(Heap, 0x3C, id);
CHECK_SIZE(Heap, 0x40);

struct HeapBlock
{
   be2_val<HeapBlockState> state;
   be2_val<uint32_t> size;
   be2_phys_ptr<HeapBlock> prev;
   be2_phys_ptr<HeapBlock> next;
};
CHECK_OFFSET(HeapBlock, 0x00, state);
CHECK_OFFSET(HeapBlock, 0x04, size);
CHECK_OFFSET(HeapBlock, 0x08, prev);
CHECK_OFFSET(HeapBlock, 0x0C, next);
CHECK_SIZE(HeapBlock, 0x10);

Result<HeapID>
IOS_CreateHeap(phys_ptr<void> ptr,
               uint32_t size);

Result<HeapID>
IOS_CreateLocalProcessHeap(phys_ptr<void> ptr,
                           uint32_t size);

Result<HeapID>
IOS_CreateCrossProcessHeap(uint32_t size);

Error
IOS_DestroyHeap(HeapID id);

phys_ptr<void>
IOS_HeapAlloc(HeapID id,
              uint32_t size);

phys_ptr<void>
IOS_HeapAllocAligned(HeapID id,
                     uint32_t size,
                     uint32_t alignment);

phys_ptr<void>
IOS_HeapRealloc(HeapID id,
                phys_ptr<void> ptr,
                uint32_t size);

Error
IOS_HeapFree(HeapID id,
             phys_ptr<void> ptr);

Error
IOS_HeapFreeAndZero(HeapID id,
                    phys_ptr<void> ptr);

} // namespace ios::kernel
