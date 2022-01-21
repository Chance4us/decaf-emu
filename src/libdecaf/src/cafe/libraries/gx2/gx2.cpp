#include "gx2.h"
#include "gx2_debug.h"
#include "gx2r_resource.h"

namespace cafe::gx2
{

static int32_t
rpl_entry(coreinit::OSDynLoad_ModuleHandle moduleHandle,
          coreinit::OSDynLoad_EntryReason reason)
{
   internal::initialiseDebug();
   internal::initialiseGx2rAllocator();
   return 0;
}

void
Library::registerSymbols()
{
   RegisterEntryPoint(rpl_entry);

   registerLibraryDependency("coreinit");
   registerLibraryDependency("tcl");

   registerApertureSymbols();
   registerCbPoolSymbols();
   registerClearSymbols();
   registerContextStateSymbols();
   registerCounterSymbols();
   registerDebugCaptureSymbols();
   registerDisplaySymbols();
   registerDisplayListSymbols();
   registerDrawSymbols();
   registerEventSymbols();
   registerFenceSymbols();
   registerFetchShadersSymbols();
   registerFormatSymbols();
   registerMemorySymbols();
   registerQuerySymbols();
   registerRegistersSymbols();
   registerSamplerSymbols();
   registerShadersSymbols();
   registerStateSymbols();
   registerSurfaceSymbols();
   registerTempSymbols();
   registerTessellationSymbols();
   registerTextureSymbols();
   registerGx2rBufferSymbols();
   registerGx2rDisplayListSymbols();
   registerGx2rDrawSymbols();
   registerGx2rMemorySymbols();
   registerGx2rResourceSymbols();
   registerGx2rShadersSymbols();
   registerGx2rSurfaceSymbols();
}

} // namespace cafe::gx2
