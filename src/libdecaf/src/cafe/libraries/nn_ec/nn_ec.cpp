#include "nn_ec.h"

namespace cafe::nn_ec
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

   registerCatalogSymbols();
   registerItemListSymbols();
   registerLibSymbols();
   registerMemoryManagerSymbols();
   registerMoneySymbols();
   registerQuerySymbols();
   registerRootObjectSymbols();
   registerShoppingCatalogSymbols();
}

} // namespace cafe::nn_ec
