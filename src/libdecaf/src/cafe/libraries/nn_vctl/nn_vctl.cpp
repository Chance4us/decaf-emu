#include "nn_vctl.h"

namespace cafe::nn_vctl
{

static int32_t
rpl_entry(coreinit::OSDynLoad_ModuleHandle moduleHandle,
          coreinit::OSDynLoad_EntryReason reason)
{
   return 0;
}

void
Library::registerSymbols()
{
   RegisterEntryPoint(rpl_entry);

   registerClientSymbols();
}

} // namespace cafe::nn_vctl
