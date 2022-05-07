#pragma once
#include "cafe_nn_ipc_client_command.h"

#include "cafe/libraries/coreinit/coreinit_ios.h"
#include "nn/ios/nn_ios_error.h"
#include "nn/nn_result.h"

namespace nn::ipc
{

class Client
{
public:
   Result initialise(virt_ptr<const char> device);
   Result close();
   bool isInitialised() const;

   template<typename CommandType>
   Result sendSyncRequest(const ClientCommand<CommandType> &command)
   {
      return sendSyncRequest(command.getCommandData());
   }

private:
   Result sendSyncRequest(const detail::ClientCommandData &command);

private:
   cafe::coreinit::IOSHandle mHandle { -1 };
};

} // namespace nn::ipc
