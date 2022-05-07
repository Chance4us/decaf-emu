#include "nn_dbg_result_string.h"
#include "nn/acp/nn_acp_result.h"
#include "nn/act/nn_act_result.h"

namespace nn::dbg
{

const char *
GetLevelString(nn::Result result)
{
   if (result.isLegacyRepresentation()) {
      switch (result.level()) {
      case nn::Result::LEGACY_LEVEL_INFO:
         return "LEVEL_INFO";
      case nn::Result::LEGACY_LEVEL_RESET:
         return "LEVEL_RESET";
      case nn::Result::LEGACY_LEVEL_REINIT:
         return "LEVEL_REINIT";
      case nn::Result::LEGACY_LEVEL_PERMANENT:
         return "LEVEL_PERMANENT";
      case nn::Result::LEGACY_LEVEL_TEMPORARY:
         return "LEVEL_TEMPORARY";
      default:
         return "<unknown>";
      }
   } else {
      switch (result.level()) {
      case nn::Result::LEVEL_SUCCESS:
         return "LEVEL_SUCCESS";
      case nn::Result::LEVEL_FATAL:
         return "LEVEL_FATAL";
      case nn::Result::LEVEL_USAGE:
         return "LEVEL_USAGE";
      case nn::Result::LEVEL_STATUS:
         return "LEVEL_STATUS";
      case nn::Result::LEVEL_END:
         return "LEVEL_END";
      default:
         return "<unknown>";
      }
   }
}

const char *
GetModuleString(nn::Result result)
{
   if (result.isLegacyRepresentation()) {
      switch (result.module()) {
      case nn::Result::LEGACY_MODULE_COMMON:
         return "MODULE_COMMON";
      case nn::Result::LEGACY_MODULE_NN_KERNEL:
         return "MODULE_NN_KERNEL";
      case nn::Result::LEGACY_MODULE_NN_UTIL:
         return "MODULE_NN_UTIL";
      case nn::Result::LEGACY_MODULE_NN_FILE_SERVER:
         return "MODULE_NN_FILE_SERVER";
      case nn::Result::LEGACY_MODULE_NN_LOADER_SERVER:
         return "MODULE_NN_LOADER_SERVER";
      case nn::Result::LEGACY_MODULE_NN_TCB:
         return "MODULE_NN_TCB";
      case nn::Result::LEGACY_MODULE_NN_OS:
         return "MODULE_NN_OS";
      case nn::Result::LEGACY_MODULE_NN_DBG:
         return "MODULE_NN_DBG";
      case nn::Result::LEGACY_MODULE_NN_DMNT:
         return "MODULE_NN_DMNT";
      case nn::Result::LEGACY_MODULE_NN_PDN:
         return "MODULE_NN_PDN";
      case nn::Result::LEGACY_MODULE_NN_GX:
         return "MODULE_NN_GX";
      case nn::Result::LEGACY_MODULE_NN_I2C:
         return "MODULE_NN_I2C";
      case nn::Result::LEGACY_MODULE_NN_GPIO:
         return "MODULE_NN_GPIO";
      case nn::Result::LEGACY_MODULE_NN_DD:
         return "MODULE_NN_DD";
      case nn::Result::LEGACY_MODULE_NN_CODEC:
         return "MODULE_NN_CODEC";
      case nn::Result::LEGACY_MODULE_NN_SPI:
         return "MODULE_NN_SPI";
      case nn::Result::LEGACY_MODULE_NN_PXI:
         return "MODULE_NN_PXI";
      case nn::Result::LEGACY_MODULE_NN_FS:
         return "MODULE_NN_FS";
      case nn::Result::LEGACY_MODULE_NN_DI:
         return "MODULE_NN_DI";
      case nn::Result::LEGACY_MODULE_NN_HID:
         return "MODULE_NN_HID";
      case nn::Result::LEGACY_MODULE_NN_CAMERA:
         return "MODULE_NN_CAMERA";
      case nn::Result::LEGACY_MODULE_NN_PI:
         return "MODULE_NN_PI";
      case nn::Result::LEGACY_MODULE_NN_PM:
         return "MODULE_NN_PM";
      case nn::Result::LEGACY_MODULE_NN_PMLOW:
         return "MODULE_NN_PMLOW";
      case nn::Result::LEGACY_MODULE_NN_FSI:
         return "MODULE_NN_FSI";
      case nn::Result::LEGACY_MODULE_NN_SRV:
         return "MODULE_NN_SRV";
      case nn::Result::LEGACY_MODULE_NN_NDM:
         return "MODULE_NN_NDM";
      case nn::Result::LEGACY_MODULE_NN_NWM:
         return "MODULE_NN_NWM";
      case nn::Result::LEGACY_MODULE_NN_SOCKET:
         return "MODULE_NN_SOCKET";
      case nn::Result::LEGACY_MODULE_NN_LDR:
         return "MODULE_NN_LDR";
      case nn::Result::LEGACY_MODULE_NN_ACC:
         return "MODULE_NN_ACC";
      case nn::Result::LEGACY_MODULE_NN_ROMFS:
         return "MODULE_NN_ROMFS";
      case nn::Result::LEGACY_MODULE_NN_AM:
         return "MODULE_NN_AM";
      case nn::Result::LEGACY_MODULE_NN_HIO:
         return "MODULE_NN_HIO";
      case nn::Result::LEGACY_MODULE_NN_UPDATER:
         return "MODULE_NN_UPDATER";
      case nn::Result::LEGACY_MODULE_NN_MIC:
         return "MODULE_NN_MIC";
      case nn::Result::LEGACY_MODULE_NN_FND:
         return "MODULE_NN_FND";
      case nn::Result::LEGACY_MODULE_NN_MP:
         return "MODULE_NN_MP";
      case nn::Result::LEGACY_MODULE_NN_MPWL:
         return "MODULE_NN_MPWL";
      case nn::Result::LEGACY_MODULE_NN_AC:
         return "MODULE_NN_AC";
      case nn::Result::LEGACY_MODULE_NN_HTTP:
         return "MODULE_NN_HTTP";
      case nn::Result::LEGACY_MODULE_NN_DSP:
         return "MODULE_NN_DSP";
      case nn::Result::LEGACY_MODULE_NN_SND:
         return "MODULE_NN_SND";
      case nn::Result::LEGACY_MODULE_NN_DLP:
         return "MODULE_NN_DLP";
      case nn::Result::LEGACY_MODULE_NN_HIOLOW:
         return "MODULE_NN_HIOLOW";
      case nn::Result::LEGACY_MODULE_NN_CSND:
         return "MODULE_NN_CSND";
      case nn::Result::LEGACY_MODULE_NN_SSL:
         return "MODULE_NN_SSL";
      case nn::Result::LEGACY_MODULE_NN_AMLOW:
         return "MODULE_NN_AMLOW";
      case nn::Result::LEGACY_MODULE_NN_NEX:
         return "MODULE_NN_NEX";
      case nn::Result::LEGACY_MODULE_NN_FRIENDS:
         return "MODULE_NN_FRIENDS";
      case nn::Result::LEGACY_MODULE_NN_RDT:
         return "MODULE_NN_RDT";
      case nn::Result::LEGACY_MODULE_NN_APPLET:
         return "MODULE_NN_APPLET";
      case nn::Result::LEGACY_MODULE_NN_NIM:
         return "MODULE_NN_NIM";
      case nn::Result::LEGACY_MODULE_NN_PTM:
         return "MODULE_NN_PTM";
      case nn::Result::LEGACY_MODULE_NN_MIDI:
         return "MODULE_NN_MIDI";
      case nn::Result::LEGACY_MODULE_NN_MC:
         return "MODULE_NN_MC";
      case nn::Result::LEGACY_MODULE_NN_SWC:
         return "MODULE_NN_SWC";
      case nn::Result::LEGACY_MODULE_NN_FATFS:
         return "MODULE_NN_FATFS";
      case nn::Result::LEGACY_MODULE_NN_NGC:
         return "MODULE_NN_NGC";
      case nn::Result::LEGACY_MODULE_NN_CARD:
         return "MODULE_NN_CARD";
      case nn::Result::LEGACY_MODULE_NN_CARDNOR:
         return "MODULE_NN_CARDNOR";
      case nn::Result::LEGACY_MODULE_NN_SDMC:
         return "MODULE_NN_SDMC";
      case nn::Result::LEGACY_MODULE_NN_BOSS:
         return "MODULE_NN_BOSS";
      case nn::Result::LEGACY_MODULE_NN_DBM:
         return "MODULE_NN_DBM";
      case nn::Result::LEGACY_MODULE_NN_CFG:
         return "MODULE_NN_CFG";
      case nn::Result::LEGACY_MODULE_NN_PS:
         return "MODULE_NN_PS";
      case nn::Result::LEGACY_MODULE_NN_CEC:
         return "MODULE_NN_CEC";
      case nn::Result::LEGACY_MODULE_NN_IR:
         return "MODULE_NN_IR";
      case nn::Result::LEGACY_MODULE_NN_UDS:
         return "MODULE_NN_UDS";
      case nn::Result::LEGACY_MODULE_NN_PL:
         return "MODULE_NN_PL";
      case nn::Result::LEGACY_MODULE_NN_CUP:
         return "MODULE_NN_CUP";
      case nn::Result::LEGACY_MODULE_NN_GYROSCOPE:
         return "MODULE_NN_GYROSCOPE";
      case nn::Result::LEGACY_MODULE_NN_MCU:
         return "MODULE_NN_MCU";
      case nn::Result::LEGACY_MODULE_NN_NS:
         return "MODULE_NN_NS";
      case nn::Result::LEGACY_MODULE_NN_NEWS:
         return "MODULE_NN_NEWS";
      case nn::Result::LEGACY_MODULE_NN_RO:
         return "MODULE_NN_RO";
      case nn::Result::LEGACY_MODULE_NN_GD:
         return "MODULE_NN_GD";
      case nn::Result::LEGACY_MODULE_NN_CARDSPI:
         return "MODULE_NN_CARDSPI";
      case nn::Result::LEGACY_MODULE_NN_EC:
         return "MODULE_NN_EC";
      case nn::Result::LEGACY_MODULE_NN_WEBBRS:
         return "MODULE_NN_WEBBRS";
      case nn::Result::LEGACY_MODULE_NN_TEST:
         return "MODULE_NN_TEST";
      case nn::Result::LEGACY_MODULE_NN_ENC:
         return "MODULE_NN_ENC";
      case nn::Result::LEGACY_MODULE_NN_PIA:
         return "MODULE_NN_PIA";
      case nn::Result::LEGACY_MODULE_APPLICATION:
         return "MODULE_APPLICATION";
      }
   } else {
      switch (result.module()) {
      case nn::Result::MODULE_COMMON:
         return "MODULE_COMMON";
      case nn::Result::MODULE_NN_IPC:
         return "MODULE_NN_IPC";
      case nn::Result::MODULE_NN_BOSS:
         return "MODULE_NN_BOSS";
      case nn::Result::MODULE_NN_ACP:
         return "MODULE_NN_ACP";
      case nn::Result::MODULE_NN_IOS:
         return "MODULE_NN_IOS";
      case nn::Result::MODULE_NN_NIM:
         return "MODULE_NN_NIM";
      case nn::Result::MODULE_NN_PDM:
         return "MODULE_NN_PDM";
      case nn::Result::MODULE_NN_ACT:
         return "MODULE_NN_ACT";
      case nn::Result::MODULE_NN_NGC:
         return "MODULE_NN_NGC";
      case nn::Result::MODULE_NN_ECA:
         return "MODULE_NN_ECA";
      case nn::Result::MODULE_NN_NUP:
         return "MODULE_NN_NUP";
      case nn::Result::MODULE_NN_NDM:
         return "MODULE_NN_NDM";
      case nn::Result::MODULE_NN_FP:
         return "MODULE_NN_FP";
      case nn::Result::MODULE_NN_AC:
         return "MODULE_NN_AC";
      case nn::Result::MODULE_NN_CONNTEST:
         return "MODULE_NN_CONNTEST";
      case nn::Result::MODULE_NN_DRMAPP:
         return "MODULE_NN_DRMAPP";
      case nn::Result::MODULE_NN_TELNET:
         return "MODULE_NN_TELNET";
      case nn::Result::MODULE_NN_OLV:
         return "MODULE_NN_OLV";
      case nn::Result::MODULE_NN_VCTL:
         return "MODULE_NN_VCTL";
      case nn::Result::MODULE_NN_NEIA:
         return "MODULE_NN_NEIA";
      case nn::Result::MODULE_NN_SPM:
         return "MODULE_NN_SPM";
      case nn::Result::MODULE_NN_EMD:
         return "MODULE_NN_EMD";
      case nn::Result::MODULE_NN_EC:
         return "MODULE_NN_EC";
      case nn::Result::MODULE_NN_CIA:
         return "MODULE_NN_CIA";
      case nn::Result::MODULE_NN_SL:
         return "MODULE_NN_SL";
      case nn::Result::MODULE_NN_ECO:
         return "MODULE_NN_ECO";
      case nn::Result::MODULE_NN_TRIAL:
         return "MODULE_NN_TRIAL";
      case nn::Result::MODULE_NN_NFP:
         return "MODULE_NN_NFP";
      case nn::Result::MODULE_NN_TEST:
         return "MODULE_NN_TEST";
      }
   }

   return "<unknown>";
}

const char *
GetSummaryString(nn::Result result)
{
   if (!result.isLegacyRepresentation()) {
      return "SUMMARY_SUCCESS";
   }

   switch (result.legacySummary()) {
   case nn::Result::LEGACY_SUMMARY_SUCCESS:
      return "SUMMARY_SUCCESS";
   case nn::Result::LEGACY_SUMMARY_NOTHING_HAPPENED:
      return "SUMMARY_NOTHING_HAPPENED";
   case nn::Result::LEGACY_SUMMARY_WOULD_BLOCK:
      return "SUMMARY_WOULD_BLOCK";
   case nn::Result::LEGACY_SUMMARY_OUT_OF_RESOURCE:
      return "SUMMARY_OUT_OF_RESOURCE";
   case nn::Result::LEGACY_SUMMARY_NOT_FOUND:
      return "SUMMARY_NOT_FOUND";
   case nn::Result::LEGACY_SUMMARY_INVALID_STATE:
      return "SUMMARY_INVALID_STATE";
   case nn::Result::LEGACY_SUMMARY_NOT_SUPPORTED:
      return "SUMMARY_NOT_SUPPORTED";
   case nn::Result::LEGACY_SUMMARY_INVALID_ARGUMENT:
      return "SUMMARY_INVALID_ARGUMENT";
   case nn::Result::LEGACY_SUMMARY_WRONG_ARGUMENT:
      return "SUMMARY_WRONG_ARGUMENT";
   case nn::Result::LEGACY_SUMMARY_CANCELLED:
      return "SUMMARY_CANCELLED";
   case nn::Result::LEGACY_SUMMARY_STATUS_CHANGED:
      return "SUMMARY_STATUS_CHANGED";
   case nn::Result::LEGACY_SUMMARY_INTERNAL:
      return "SUMMARY_INTERNAL";
   }

   return "<unknown>";
}

static const char *
GetLegacyDescriptionString(nn::Result result)
{
   switch (result.description()) {
   case nn::Result::LEGACY_DESCRIPTION_SUCCESS:
      return "DESCRIPTION_SUCCESS";
   case nn::Result::LEGACY_DESCRIPTION_TIMEOUT:
      return "DESCRIPTION_TIMEOUT";
   case nn::Result::LEGACY_DESCRIPTION_OUT_OF_RANGE:
      return "DESCRIPTION_OUT_OF_RANGE";
   case nn::Result::LEGACY_DESCRIPTION_ALREADY_EXISTS:
      return "DESCRIPTION_ALREADY_EXISTS";
   case nn::Result::LEGACY_DESCRIPTION_CANCEL_REQUESTED:
      return "DESCRIPTION_CANCEL_REQUESTED";
   case nn::Result::LEGACY_DESCRIPTION_NOT_FOUND:
      return "DESCRIPTION_NOT_FOUND";
   case nn::Result::LEGACY_DESCRIPTION_ALREADY_INITIALIZED:
      return "DESCRIPTION_ALREADY_INITIALIZED";
   case nn::Result::LEGACY_DESCRIPTION_NOT_INITIALIZED:
      return "DESCRIPTION_NOT_INITIALIZED";
   case nn::Result::LEGACY_DESCRIPTION_INVALID_HANDLE:
      return "DESCRIPTION_INVALID_HANDLE";
   case nn::Result::LEGACY_DESCRIPTION_INVALID_POINTER:
      return "DESCRIPTION_INVALID_POINTER";
   case nn::Result::LEGACY_DESCRIPTION_INVALID_ADDRESS:
      return "DESCRIPTION_INVALID_ADDRESS";
   case nn::Result::LEGACY_DESCRIPTION_NOT_IMPLEMENTED:
      return "DESCRIPTION_NOT_IMPLEMENTED";
   case nn::Result::LEGACY_DESCRIPTION_OUT_OF_MEMORY:
      return "DESCRIPTION_OUT_OF_MEMORY";
   case nn::Result::LEGACY_DESCRIPTION_MISALIGNED_SIZE:
      return "DESCRIPTION_MISALIGNED_SIZE";
   case nn::Result::LEGACY_DESCRIPTION_MISALIGNED_ADDRESS:
      return "DESCRIPTION_MISALIGNED_ADDRESS";
   case nn::Result::LEGACY_DESCRIPTION_BUSY:
      return "DESCRIPTION_BUSY";
   case nn::Result::LEGACY_DESCRIPTION_NO_DATA:
      return "DESCRIPTION_NO_DATA";
   case nn::Result::LEGACY_DESCRIPTION_INVALID_COMBINATION:
      return "DESCRIPTION_INVALID_COMBINATION";
   case nn::Result::LEGACY_DESCRIPTION_INVALID_ENUM_VALUE:
      return "DESCRIPTION_INVALID_ENUM_VALUE";
   case nn::Result::LEGACY_DESCRIPTION_INVALID_SIZE:
      return "DESCRIPTION_INVALID_SIZE";
   case nn::Result::LEGACY_DESCRIPTION_ALREADY_DONE:
      return "DESCRIPTION_ALREADY_DONE";
   case nn::Result::LEGACY_DESCRIPTION_NOT_AUTHORIZED:
      return "DESCRIPTION_NOT_AUTHORIZED";
   case nn::Result::LEGACY_DESCRIPTION_TOO_LARGE:
      return "DESCRIPTION_TOO_LARGE";
   case nn::Result::LEGACY_DESCRIPTION_INVALID_SELECTION:
      return "DESCRIPTION_INVALID_SELECTION";
   default:
      return "<unknown>";
   }
}

static const char *
GetAcpDescriptionString(nn::Result result)
{
   if (result == acp::ResultInvalidParameter) {
      return "INVALID_PARAMETER";
   } else if (result == acp::ResultInvalidFile) {
      return "INVALID_FILE";
   } else if (result == acp::ResultInvalidXmlFile) {
      return "INVALID_XML_FILE";
   } else if (result == acp::ResultFileAccessMode) {
      return "FILE_ACCESS_MODE";
   } else if (result == acp::ResultInvalidNetworkTime) {
      return "INVALID_NETWORK_TIME";
   } else if (result == acp::ResultInvalid) {
      return "INVALID";
   }

   if (result == acp::ResultFileNotFound) {
      return "FILE_NOT_FOUND";
   } else if (result == acp::ResultDirNotFound) {
      return "DIR_NOT_FOUND";
   } else if (result == acp::ResultDeviceNotFound) {
      return "DEVICE_NOT_FOUND";
   } else if (result == acp::ResultTitleNotFound) {
      return "TITLE_NOT_FOUND";
   } else if (result == acp::ResultApplicationNotFound) {
      return "APPLICATION_NOT_FOUND";
   } else if (result == acp::ResultSystemConfigNotFound) {
      return "SYSTEM_CONFIG_NOT_FOUND";
   } else if (result == acp::ResultXmlItemNotFound) {
      return "XML_ITEM_NOT_FOUND";
   } else if (result == acp::ResultNotFound) {
      return "NOT_FOUND";
   }

   if (result == acp::ResultFileAlreadyExists) {
      return "FILE_ALREADY_EXISTS";
   } else if (result == acp::ResultDirAlreadyExists) {
      return "DIR_ALREADY_EXISTS";
   } else if (result == acp::ResultAlreadyExists) {
      return "ALREADY_EXISTS";
   }

   if (result == acp::ResultAlreadyDone) {
      return "ALREADY_DONE";
   }

   if (result == acp::ResultInvalidRegion) {
      return "INVALID_REGION";
   } else if (result == acp::ResultRestrictedRating) {
      return "RESTRICTED_RATING";
   } else if (result == acp::ResultNotPresentRating) {
      return "NOT_PRESENT_RATING";
   } else if (result == acp::ResultPendingRating) {
      return "PENDING_RATING";
   } else if (result == acp::ResultNetSettingRequired) {
      return "NET_SETTING_REQUIRED";
   } else if (result == acp::ResultNetAccountRequired) {
      return "NET_ACCOUNT_REQUIRED";
   } else if (result == acp::ResultNetAccountError) {
      return "NET_ACCOUNT_ERROR";
   } else if (result == acp::ResultBrowserRequired) {
      return "BROWSER_REQUIRED";
   } else if (result == acp::ResultOlvRequired) {
      return "OLV_REQUIRED";
   } else if (result == acp::ResultPincodeRequired) {
      return "PINCODE_REQUIRED";
   } else if (result == acp::ResultIncorrectPincode) {
      return "INCORRECT_PINCODE";
   } else if (result == acp::ResultInvalidLogo) {
      return "INVALID_LOGO";
   } else if (result == acp::ResultDemoExpiredNumber) {
      return "DEMO_EXPIRED_NUMBER";
   } else if (result == acp::ResultDrcRequired) {
      return "DRC_REQUIRED";
   } else if (result == acp::ResultAuthentication) {
      return "AUTHENTICATION";
   }

   if (result == acp::ResultNoFilePermission) {
      return "NO_FILE_PERMISSION";
   } else if (result == acp::ResultNoDirPermission) {
      return "NO_DIR_PERMISSION";
   } else if (result == acp::ResultNoPermission) {
      return "NO_PERMISSION";
   }

   if (result == acp::ResultUsbStorageNotReady) {
      return "USB_STORAGE_NOT_READY";
   } else if (result == acp::ResultBusy) {
      return "BUSY";
   }

   if (result == acp::ResultCancelled) {
      return "CANCELLED";
   }

   if (result == acp::ResultDeviceFull) {
      return "DEVICE_FULL";
   } else if (result == acp::ResultJournalFull) {
      return "JOURNAL_FULL";
   } else if (result == acp::ResultSystemMemory) {
      return "SYSTEM_MEMORY";
   } else if (result == acp::ResultFsResource) {
      return "FS_RESOURCE";
   } else if (result == acp::ResultIpcResource) {
      return "IPC_RESOURCE";
   } else if (result == acp::ResultResource) {
      return "RESOURCE";
   }

   if (result == acp::ResultNotInitialised) {
      return "NOT_INITIALISED";
   }

   if (result == acp::ResultAccountError) {
      return "ACCOUNT_ERROR";
   }

   if (result == acp::ResultUnsupported) {
      return "UNSUPPORTED";
   }

   if (result == acp::ResultDataCorrupted) {
      return "DATA_CORRUPTED";
   } else if (result == acp::ResultSlcDataCorrupted) {
      return "SLC_DATA_CORRUPTED";
   } else if (result == acp::ResultMlcDataCorrupted) {
      return "MLC_DATA_CORRUPTED";
   } else if (result == acp::ResultUsbDataCorrupted) {
      return "USB_DATA_CORRUPTED";
   } else if (result == acp::ResultDevice) {
      return "DEVICE";
   }

   if (result == acp::ResultMediaNotReady) {
      return "MEDIA_NOT_READY";
   } else if (result == acp::ResultMediaBroken) {
      return "MEDIA_BROKEN";
   } else if (result == acp::ResultOddMediaNotReady) {
      return "ODD_MEDIA_NOT_READY";
   } else if (result == acp::ResultOddMediaBroken) {
      return "ODD_MEDIA_BROKEN";
   } else if (result == acp::ResultUsbMediaNotReady) {
      return "USB_MEDIA_NOT_READY";
   } else if (result == acp::ResultUsbMediaBroken) {
      return "USB_MEDIA_BROKEN";
   } else if (result == acp::ResultMediaWriteProtected) {
      return "MEDIA_WRITE_PROTECTED";
   } else if (result == acp::ResultUsbWriteProtected) {
      return "USB_WRITE_PROTECTED";
   } else if (result == acp::ResultMedia) {
      return "MEDIA";
   }

   if (result == acp::ResultEncryptionError) {
      return "ENCRYPTION_ERROR";
   } else if (result == acp::ResultMii) {
      return "MII";
   }

   if (result == acp::ResultFsaFatal) {
      return "FSA_FATAL";
   } else if (result == acp::ResultFsaAddClientFatal) {
      return "FSA_ADD_CLIENT_FATAL";
   } else if (result == acp::ResultMcpTitleFatal) {
      return "MCP_TITLE_FATAL";
   } else if (result == acp::ResultMcpPatchFatal) {
      return "MCP_PATCH_FATAL";
   } else if (result == acp::ResultMcpFatal) {
      return "MCP_FATAL";
   } else if (result == acp::ResultSaveFatal) {
      return "SAVE_FATAL";
   } else if (result == acp::ResultUcFatal) {
      return "UC_FATAL";
   } else if (result == acp::ResultFatal) {
      return "FATAL";
   }

   return "<unknown>";
}

static const char *
GetActDescriptionString(nn::Result result)
{
   if (result == act::ResultMailAddressNotConfirmed) {
      return "MAIL_ADDRESS_NOT_CONFIRMED";
   } else if (result == act::ResultLibraryError) {
      return "LIBRARY_ERROR";
   } else if (result == act::ResultNotInitialised) {
      return "NOT_INITIALISED";
   } else if (result == act::ResultAlreadyInitialised) {
      return "ALREADY_INITIALISED";
   } else if (result == act::ResultBusy) {
      return "BUSY";
   } else if (result == act::ResultNotImplemented) {
      return "NOT_IMPLEMENTED";
   } else if (result == act::ResultDeprecated) {
      return "DEPRECATED";
   } else if (result == act::ResultDevelopmentOnly) {
      return "DEVELOPMENT_ONLY";
   } else if (result == act::ResultInvalidArgument) {
      return "INVALID_ARGUMENT";
   } else if (result == act::ResultInvalidPointer) {
      return "INVALID_POINTER";
   } else if (result == act::ResultOutOfRange) {
      return "OUT_OF_RANGE";
   } else if (result == act::ResultInvalidSize) {
      return "INVALID_SIZE";
   } else if (result == act::ResultInvalidFormat) {
      return "INVALID_FORMAT";
   } else if (result == act::ResultInvalidHandle) {
      return "INVALID_HANDLE";
   } else if (result == act::ResultInvalidValue) {
      return "INVALID_VALUE";
   }

   if (result == act::ResultInternalError) {
      return "INTERNAL_ERROR";
   } else if (result == act::ResultEndOfStream) {
      return "END_OF_STREAM";
   } else if (result == act::ResultFileError) {
      return "FILE_ERROR";
   } else if (result == act::ResultFileNotFound) {
      return "FILE_NOT_FOUND";
   } else if (result == act::ResultFileVersionMismatch) {
      return "FILE_VERSION_MISMATCH";
   } else if (result == act::ResultFileIoError) {
      return "FILE_IO_ERROR";
   } else if (result == act::ResultFileTypeMismatch) {
      return "FILE_TYPE_MISMATCH";
   } else if (result == act::ResultOutOfResource) {
      return "OUT_OF_RESOURCE";
   } else if (result == act::ResultShortOfBuffer) {
      return "SHORT_OF_BUFFER";
   } else if (result == act::ResultOutOfMemory) {
      return "OUT_OF_MEMORY";
   } else if (result == act::ResultOutOfGlobalHeap) {
      return "OUT_OF_GLOBAL_HEAP";
   } else if (result == act::ResultOutOfCrossProcessHeap) {
      return "OUT_OF_CROSS_PROCESS_HEAP";
   } else if (result == act::ResultOutOfProcessLocalHeap) {
      return "OUT_OF_PROCESS_LOCAL_HEAP";
   } else if (result == act::ResultOutOfMxmlHeap) {
      return "OUT_OF_MXML_HEAP";
   } else if (result == act::ResultUcError) {
      return "UC_ERROR";
   } else if (result == act::ResultUcReadSysConfigError) {
      return "UC_READ_SYS_CONFIG_ERROR";
   } else if (result == act::ResultMcpError) {
      return "MCP_ERROR";
   } else if (result == act::ResultMcpOpenError) {
      return "MCP_OPEN_ERROR";
   } else if (result == act::ResultMcpGetInfoError) {
      return "MCP_GET_INFO_ERROR";
   } else if (result == act::ResultIsoError) {
      return "ISO_ERROR";
   } else if (result == act::ResultIsoInitFailure) {
      return "ISO_INIT_FAILURE";
   } else if (result == act::ResultIsoGetCountryCodeFailure) {
      return "ISO_GET_COUNTRY_CODE_FAILURE";
   } else if (result == act::ResultIsoGetLanguageCodeFailure) {
      return "ISO_GET_LANGUAGE_CODE_FAILURE";
   } else if (result == act::ResultMxmlError) {
      return "MXML_ERROR";
   } else if (result == act::ResultIosError) {
      return "IOS_ERROR";
   } else if (result == act::ResultIosOpenError) {
      return "IOS_OPEN_ERROR";
   }

   if (result == act::ResultAccountManagementError) {
      return "ACCOUNT_MANAGEMENT_ERROR";
   } else if (result == act::ResultAccountNotFound) {
      return "ACCOUNT_NOT_FOUND";
   } else if (result == act::ResultSlotsFull) {
      return "SLOTS_FULL";
   } else if (result == act::ResultAccountNotLoaded) {
      return "ACCOUNT_NOT_LOADED";
   } else if (result == act::ResultAccountAlreadyLoaded) {
      return "ACCOUNT_ALREADY_LOADED";
   } else if (result == act::ResultAccountLocked) {
      return "ACCOUNT_LOCKED";
   } else if (result == act::ResultNotNetworkAccount) {
      return "NOT_NETWORK_ACCOUNT";
   } else if (result == act::ResultNotLocalAccount) {
      return "NOT_LOCAL_ACCOUNT";
   } else if (result == act::ResultAccountNotCommitted) {
      return "ACCOUNT_NOT_COMMITTED";
   } else if (result == act::ResultNetworkClockInvalid) {
      return "NETWORK_CLOCK_INVALID";
   } else if (result == act::ResultAuthenticationError) {
      return "AUTHENTICATION_ERROR";
   }

   if (result == act::ResultHttpError) {
      return "HTTP_ERROR";
   } else if (result == act::ResultHttpUnsupportedProtocol) {
      return "HTTP_UNSUPPORTED_PROTOCOL";
   } else if (result == act::ResultHttpFailedInit) {
      return "HTTP_FAILED_INIT";
   } else if (result == act::ResultHttpURLMalformat) {
      return "HTTP_URL_MALFORMAT";
   } else if (result == act::ResultHttpNotBuiltIn) {
      return "HTTP_NOT_BUILT_IN";
   } else if (result == act::ResultHttpCouldntResolveProxy) {
      return "HTTP_COULDNT_RESOLVE_PROXY";
   } else if (result == act::ResultHttpCouldntResolveHost) {
      return "HTTP_COULDNT_RESOLVE_HOST";
   } else if (result == act::ResultHttpCouldntConnect) {
      return "HTTP_COULDNT_CONNECT";
   } else if (result == act::ResultHttpFtpWeirdServerReply) {
      return "HTTP_FTP_WEIRD_SERVER_REPLY";
   } else if (result == act::ResultHttpRemoteAccessDenied) {
      return "HTTP_REMOTE_ACCESS_DENIED";
   } else if (result == act::ResultHttpObsolete10) {
      return "HTTP_OBSOLETE10";
   } else if (result == act::ResultHttpFtpWeirdPassReply) {
      return "HTTP_FTP_WEIRD_PASS_REPLY";
   } else if (result == act::ResultHttpObsolete12) {
      return "HTTP_OBSOLETE12";
   } else if (result == act::ResultHttpFtpWeirdPasvReply) {
      return "HTTP_FTP_WEIRD_PASV_REPLY";
   } else if (result == act::ResultHttpFtpWeird227Format) {
      return "HTTP_FTP_WEIRD_227_FORMAT";
   } else if (result == act::ResultHttpFtpCantGetHost) {
      return "HTTP_FTP_CANT_GET_HOST";
   } else if (result == act::ResultHttpObsolete16) {
      return "HTTP_OBSOLETE16";
   } else if (result == act::ResultHttpFtpCouldntSetType) {
      return "HTTP_FTP_COULDNT_SET_TYPE";
   } else if (result == act::ResultHttpPartialFile) {
      return "HTTP_PARTIAL_FILE";
   } else if (result == act::ResultHttpFtpCouldntRetrFile) {
      return "HTTP_FTP_COULDNT_RETR_FILE";
   } else if (result == act::ResultHttpObsolete20) {
      return "HTTP_OBSOLETE20";
   } else if (result == act::ResultHttpQuoteError) {
      return "HTTP_QUOTE_ERROR";
   } else if (result == act::ResultHttpHttpReturnedError) {
      return "HTTP_HTTP_RETURNED_ERROR";
   } else if (result == act::ResultHttpWriteError) {
      return "HTTP_WRITE_ERROR";
   } else if (result == act::ResultHttpObsolete24) {
      return "HTTP_OBSOLETE24";
   } else if (result == act::ResultHttpUploadFailed) {
      return "HTTP_UPLOAD_FAILED";
   } else if (result == act::ResultHttpReadError) {
      return "HTTP_READ_ERROR";
   } else if (result == act::ResultHttpOutOfMemory) {
      return "HTTP_OUT_OF_MEMORY";
   } else if (result == act::ResultHttpOperationTimedout) {
      return "HTTP_OPERATION_TIMEDOUT";
   } else if (result == act::ResultHttpObsolete29) {
      return "HTTP_OBSOLETE29";
   } else if (result == act::ResultHttpFtpPortFailed) {
      return "HTTP_FTP_PORT_FAILED";
   } else if (result == act::ResultHttpFtpCouldntUseRest) {
      return "HTTP_FTP_COULDNT_USE_REST";
   } else if (result == act::ResultHttpObsolete32) {
      return "HTTP_OBSOLETE32";
   } else if (result == act::ResultHttpRangeError) {
      return "HTTP_RANGE_ERROR";
   } else if (result == act::ResultHttpHttpPostError) {
      return "HTTP_HTTP_POST_ERROR";
   } else if (result == act::ResultHttpSslConnectError) {
      return "HTTP_SSL_CONNECT_ERROR";
   } else if (result == act::ResultHttpBadDownloadResume) {
      return "HTTP_BAD_DOWNLOAD_RESUME";
   } else if (result == act::ResultHttpFileCouldntReadFile) {
      return "HTTP_FILE_COULDNT_READ_FILE";
   } else if (result == act::ResultHttpLdapCannotBind) {
      return "HTTP_LDAP_CANNOT_BIND";
   } else if (result == act::ResultHttpLdapSearchFailed) {
      return "HTTP_LDAP_SEARCH_FAILED";
   } else if (result == act::ResultHttpObsolete40) {
      return "HTTP_OBSOLETE40";
   } else if (result == act::ResultHttpFunctionNotFound) {
      return "HTTP_FUNCTION_NOT_FOUND";
   } else if (result == act::ResultHttpAbortedByCallback) {
      return "HTTP_ABORTED_BY_CALLBACK";
   } else if (result == act::ResultHttpBadFunctionArgument) {
      return "HTTP_BAD_FUNCTION_ARGUMENT";
   } else if (result == act::ResultHttpObsolete44) {
      return "HTTP_OBSOLETE44";
   } else if (result == act::ResultHttpInterfaceFailed) {
      return "HTTP_INTERFACE_FAILED";
   } else if (result == act::ResultHttpObsolete46) {
      return "HTTP_OBSOLETE46";
   } else if (result == act::ResultHttpTooManyRedirects) {
      return "HTTP_TOO_MANY_REDIRECTS";
   } else if (result == act::ResultHttpUnknownOption) {
      return "HTTP_UNKNOWN_OPTION";
   } else if (result == act::ResultHttpTelnetOptionSyntax) {
      return "HTTP_TELNET_OPTION_SYNTAX";
   } else if (result == act::ResultHttpObsolete50) {
      return "HTTP_OBSOLETE50";
   } else if (result == act::ResultHttpPeerFailedVerification) {
      return "HTTP_PEER_FAILED_VERIFICATION";
   } else if (result == act::ResultHttpGotNothing) {
      return "HTTP_GOT_NOTHING";
   } else if (result == act::ResultHttpSslEngineNotfound) {
      return "HTTP_SSL_ENGINE_NOTFOUND";
   } else if (result == act::ResultHttpSslEngineSetfailed) {
      return "HTTP_SSL_ENGINE_SETFAILED";
   } else if (result == act::ResultHttpSendError) {
      return "HTTP_SEND_ERROR";
   } else if (result == act::ResultHttpRecvError) {
      return "HTTP_RECV_ERROR";
   } else if (result == act::ResultHttpObsolete57) {
      return "HTTP_OBSOLETE57";
   } else if (result == act::ResultHttpSslCertproblem) {
      return "HTTP_SSL_CERTPROBLEM";
   } else if (result == act::ResultHttpSslCipher) {
      return "HTTP_SSL_CIPHER";
   } else if (result == act::ResultHttpSslCacert) {
      return "HTTP_SSL_CACERT";
   } else if (result == act::ResultHttpBadContentEncoding) {
      return "HTTP_BAD_CONTENT_ENCODING";
   } else if (result == act::ResultHttpLdapInvalidURL) {
      return "HTTP_LDAP_INVALID_URL";
   } else if (result == act::ResultHttpFilesizeExceeded) {
      return "HTTP_FILESIZE_EXCEEDED";
   } else if (result == act::ResultHttpUseSslFailed) {
      return "HTTP_USE_SSL_FAILED";
   } else if (result == act::ResultHttpSendFailRewind) {
      return "HTTP_SEND_FAIL_REWIND";
   } else if (result == act::ResultHttpSslEngineInitfailed) {
      return "HTTP_SSL_ENGINE_INITFAILED";
   } else if (result == act::ResultHttpLoginDenied) {
      return "HTTP_LOGIN_DENIED";
   } else if (result == act::ResultHttpTftpNotfound) {
      return "HTTP_TFTP_NOTFOUND";
   } else if (result == act::ResultHttpTftpPerm) {
      return "HTTP_TFTP_PERM";
   } else if (result == act::ResultHttpRemoteDiskFull) {
      return "HTTP_REMOTE_DISK_FULL";
   } else if (result == act::ResultHttpTftpIllegal) {
      return "HTTP_TFTP_ILLEGAL";
   } else if (result == act::ResultHttpTftpUnknownid) {
      return "HTTP_TFTP_UNKNOWNID";
   } else if (result == act::ResultHttpRemoteFileExists) {
      return "HTTP_REMOTE_FILE_EXISTS";
   } else if (result == act::ResultHttpTftpNosuchuser) {
      return "HTTP_TFTP_NOSUCHUSER";
   } else if (result == act::ResultHttpConvFailed) {
      return "HTTP_CONV_FAILED";
   } else if (result == act::ResultHttpConvReqd) {
      return "HTTP_CONV_REQD";
   } else if (result == act::ResultHttpSslCacertBadfile) {
      return "HTTP_SSL_CACERT_BADFILE";
   } else if (result == act::ResultHttpRemoteFileNotFound) {
      return "HTTP_REMOTE_FILE_NOT_FOUND";
   } else if (result == act::ResultHttpSsh) {
      return "HTTP_SSH";
   } else if (result == act::ResultHttpSslShutdownFailed) {
      return "HTTP_SSL_SHUTDOWN_FAILED";
   } else if (result == act::ResultHttpAgain) {
      return "HTTP_AGAIN";
   } else if (result == act::ResultHttpSslCrlBadfile) {
      return "HTTP_SSL_CRL_BADFILE";
   } else if (result == act::ResultHttpSslIssuerError) {
      return "HTTP_SSL_ISSUER_ERROR";
   } else if (result == act::ResultHttpFtpPretFailed) {
      return "HTTP_FTP_PRET_FAILED";
   } else if (result == act::ResultHttpRtspCseqError) {
      return "HTTP_RTSP_CSEQ_ERROR";
   } else if (result == act::ResultHttpRtspSessionError) {
      return "HTTP_RTSP_SESSION_ERROR";
   } else if (result == act::ResultHttpFtpBadFileList) {
      return "HTTP_FTP_BAD_FILE_LIST";
   } else if (result == act::ResultHttpChunkFailed) {
      return "HTTP_CHUNK_FAILED";
   } else if (result == act::ResultHttpNsslNoCtx) {
      return "HTTP_NSSL_NO_CTX";
   }

   if (result == act::ResultSoError) {
      return "SO_ERROR";
   } else if (result == act::ResultSoSelectError) {
      return "SO_SELECT_ERROR";
   } else if (result == act::ResultRequestError) {
      return "REQUEST_ERROR";
   } else if (result == act::ResultBadFormatParameter) {
      return "BAD_FORMAT_PARAMETER";
   } else if (result == act::ResultBadFormatRequest) {
      return "BAD_FORMAT_REQUEST";
   } else if (result == act::ResultRequestParameterMissing) {
      return "REQUEST_PARAMETER_MISSING";
   } else if (result == act::ResultWrongHttpMethod) {
      return "WRONG_HTTP_METHOD";
   } else if (result == act::ResultResponseError) {
      return "RESPONSE_ERROR";
   } else if (result == act::ResultBadFormatResponse) {
      return "BAD_FORMAT_RESPONSE";
   } else if (result == act::ResultResponseItemMissing) {
      return "RESPONSE_ITEM_MISSING";
   } else if (result == act::ResultResponseTooLarge) {
      return "RESPONSE_TOO_LARGE";
   } else if (result == act::ResultNotModified) {
      return "NOT_MODIFIED";
   } else if (result == act::ResultInvalidCommonParameter) {
      return "INVALID_COMMON_PARAMETER";
   } else if (result == act::ResultInvalidPlatformID) {
      return "INVALID_PLATFORM_ID";
   } else if (result == act::ResultUnauthorizedDevice) {
      return "UNAUTHORIZED_DEVICE";
   } else if (result == act::ResultInvalidSerialID) {
      return "INVALID_SERIAL_ID";
   } else if (result == act::ResultInvalidMacAddress) {
      return "INVALID_MAC_ADDRESS";
   } else if (result == act::ResultInvalidRegion) {
      return "INVALID_REGION";
   } else if (result == act::ResultInvalidCountry) {
      return "INVALID_COUNTRY";
   } else if (result == act::ResultInvalidLanguage) {
      return "INVALID_LANGUAGE";
   } else if (result == act::ResultUnauthorizedClient) {
      return "UNAUTHORIZED_CLIENT";
   } else if (result == act::ResultDeviceIDEmpty) {
      return "DEVICE_ID_EMPTY";
   } else if (result == act::ResultSerialIDEmpty) {
      return "SERIAL_ID_EMPTY";
   } else if (result == act::ResultPlatformIDEmpty) {
      return "PLATFORM_ID_EMPTY";
   } else if (result == act::ResultInvalidUniqueID) {
      return "INVALID_UNIQUE_ID";
   } else if (result == act::ResultInvalidClientID) {
      return "INVALID_CLIENT_ID";
   } else if (result == act::ResultInvalidClientKey) {
      return "INVALID_CLIENT_KEY";
   } else if (result == act::ResultInvalidNexClientID) {
      return "INVALID_NEX_CLIENT_ID";
   } else if (result == act::ResultInvalidGameServerID) {
      return "INVALID_GAME_SERVER_ID";
   } else if (result == act::ResultGameServerIDEnvironmentNotFound) {
      return "GAME_SERVER_ID_ENVIRONMENT_NOT_FOUND";
   } else if (result == act::ResultGameServerIDUniqueIDNotLinked) {
      return "GAME_SERVER_ID_UNIQUE_ID_NOT_LINKED";
   } else if (result == act::ResultClientIDUniqueIDNotLinked) {
      return "CLIENT_ID_UNIQUE_ID_NOT_LINKED";
   } else if (result == act::ResultDeviceMismatch) {
      return "DEVICE_MISMATCH";
   } else if (result == act::ResultCountryMismatch) {
      return "COUNTRY_MISMATCH";
   } else if (result == act::ResultEulaNotAccepted) {
      return "EULA_NOT_ACCEPTED";
   } else if (result == act::ResultUpdateRequired) {
      return "UPDATE_REQUIRED";
   } else if (result == act::ResultSystemUpdateRequired) {
      return "SYSTEM_UPDATE_REQUIRED";
   } else if (result == act::ResultApplicationUpdateRequired) {
      return "APPLICATION_UPDATE_REQUIRED";
   } else if (result == act::ResultUnauthorizedRequest) {
      return "UNAUTHORIZED_REQUEST";
   } else if (result == act::ResultRequestForbidden) {
      return "REQUEST_FORBIDDEN";
   } else if (result == act::ResultResourceNotFound) {
      return "RESOURCE_NOT_FOUND";
   } else if (result == act::ResultPidNotFound) {
      return "PID_NOT_FOUND";
   } else if (result == act::ResultNexAccountNotFound) {
      return "NEX_ACCOUNT_NOT_FOUND";
   } else if (result == act::ResultGenerateTokenFailure) {
      return "GENERATE_TOKEN_FAILURE";
   } else if (result == act::ResultRequestNotFound) {
      return "REQUEST_NOT_FOUND";
   } else if (result == act::ResultMasterPinNotFound) {
      return "MASTER_PIN_NOT_FOUND";
   } else if (result == act::ResultMailTextNotFound) {
      return "MAIL_TEXT_NOT_FOUND";
   } else if (result == act::ResultSendMailFailure) {
      return "SEND_MAIL_FAILURE";
   } else if (result == act::ResultApprovalIDNotFound) {
      return "APPROVAL_ID_NOT_FOUND";
   } else if (result == act::ResultInvalidEulaParameter) {
      return "INVALID_EULA_PARAMETER";
   } else if (result == act::ResultInvalidEulaCountry) {
      return "INVALID_EULA_COUNTRY";
   } else if (result == act::ResultInvalidEulaCountryAndVersion) {
      return "INVALID_EULA_COUNTRY_AND_VERSION";
   } else if (result == act::ResultEulaNotFound) {
      return "EULA_NOT_FOUND";
   } else if (result == act::ResultPhraseNotAcceptable) {
      return "PHRASE_NOT_ACCEPTABLE";
   } else if (result == act::ResultAccountIDAlreadyExists) {
      return "ACCOUNT_ID_ALREADY_EXISTS";
   } else if (result == act::ResultAccountIDNotAcceptable) {
      return "ACCOUNT_ID_NOT_ACCEPTABLE";
   } else if (result == act::ResultAccountPasswordNotAcceptable) {
      return "ACCOUNT_PASSWORD_NOT_ACCEPTABLE";
   } else if (result == act::ResultMiiNameNotAcceptable) {
      return "MII_NAME_NOT_ACCEPTABLE";
   } else if (result == act::ResultMailAddressNotAcceptable) {
      return "MAIL_ADDRESS_NOT_ACCEPTABLE";
   } else if (result == act::ResultAccountIDFormatInvalid) {
      return "ACCOUNT_ID_FORMAT_INVALID";
   } else if (result == act::ResultAccountIDPasswordSame) {
      return "ACCOUNT_ID_PASSWORD_SAME";
   } else if (result == act::ResultAccountIDCharNotAcceptable) {
      return "ACCOUNT_ID_CHAR_NOT_ACCEPTABLE";
   } else if (result == act::ResultAccountIDSuccessiveSymbol) {
      return "ACCOUNT_ID_SUCCESSIVE_SYMBOL";
   } else if (result == act::ResultAccountIDSymbolPositionNotAcceptable) {
      return "ACCOUNT_ID_SYMBOL_POSITION_NOT_ACCEPTABLE";
   } else if (result == act::ResultAccountIDTooManyDigit) {
      return "ACCOUNT_ID_TOO_MANY_DIGIT";
   } else if (result == act::ResultAccountPasswordCharNotAcceptable) {
      return "ACCOUNT_PASSWORD_CHAR_NOT_ACCEPTABLE";
   } else if (result == act::ResultAccountPasswordTooFewCharTypes) {
      return "ACCOUNT_PASSWORD_TOO_FEW_CHAR_TYPES";
   } else if (result == act::ResultAccountPasswordSuccessiveSameChar) {
      return "ACCOUNT_PASSWORD_SUCCESSIVE_SAME_CHAR";
   } else if (result == act::ResultMailAddressDomainNameNotAcceptable) {
      return "MAIL_ADDRESS_DOMAIN_NAME_NOT_ACCEPTABLE";
   } else if (result == act::ResultMailAddressDomainNameNotResolved) {
      return "MAIL_ADDRESS_DOMAIN_NAME_NOT_RESOLVED";
   } else if (result == act::ResultReachedAssociationLimit) {
      return "REACHED_ASSOCIATION_LIMIT";
   } else if (result == act::ResultReachedRegistrationLimit) {
      return "REACHED_REGISTRATION_LIMIT";
   } else if (result == act::ResultCoppaNotAccepted) {
      return "COPPA_NOT_ACCEPTED";
   } else if (result == act::ResultParentalControlsRequired) {
      return "PARENTAL_CONTROLS_REQUIRED";
   } else if (result == act::ResultMiiNotRegistered) {
      return "MII_NOT_REGISTERED";
   } else if (result == act::ResultDeviceEulaCountryMismatch) {
      return "DEVICE_EULA_COUNTRY_MISMATCH";
   } else if (result == act::ResultPendingMigration) {
      return "PENDING_MIGRATION";
   } else if (result == act::ResultWrongUserInput) {
      return "WRONG_USER_INPUT";
   } else if (result == act::ResultWrongAccountPassword) {
      return "WRONG_ACCOUNT_PASSWORD";
   } else if (result == act::ResultWrongMailAddress) {
      return "WRONG_MAIL_ADDRESS";
   } else if (result == act::ResultWrongAccountPasswordOrMailAddress) {
      return "WRONG_ACCOUNT_PASSWORD_OR_MAIL_ADDRESS";
   } else if (result == act::ResultWrongConfirmationCode) {
      return "WRONG_CONFIRMATION_CODE";
   } else if (result == act::ResultWrongBirthDateOrMailAddress) {
      return "WRONG_BIRTH_DATE_OR_MAIL_ADDRESS";
   } else if (result == act::ResultWrongAccountMail) {
      return "WRONG_ACCOUNT_MAIL";
   } else if (result == act::ResultAccountAlreadyDeleted) {
      return "ACCOUNT_ALREADY_DELETED";
   } else if (result == act::ResultAccountIDChanged) {
      return "ACCOUNT_ID_CHANGED";
   } else if (result == act::ResultAuthenticationLocked) {
      return "AUTHENTICATION_LOCKED";
   } else if (result == act::ResultDeviceInactive) {
      return "DEVICE_INACTIVE";
   } else if (result == act::ResultCoppaAgreementCanceled) {
      return "COPPA_AGREEMENT_CANCELED";
   } else if (result == act::ResultDomainAccountAlreadyExists) {
      return "DOMAIN_ACCOUNT_ALREADY_EXISTS";
   } else if (result == act::ResultAccountTokenExpired) {
      return "ACCOUNT_TOKEN_EXPIRED";
   } else if (result == act::ResultInvalidAccountToken) {
      return "INVALID_ACCOUNT_TOKEN";
   } else if (result == act::ResultAuthenticationRequired) {
      return "AUTHENTICATION_REQUIRED";
   } else if (result == act::ResultConfirmationCodeExpired) {
      return "CONFIRMATION_CODE_EXPIRED";
   } else if (result == act::ResultMailAddressNotValidated) {
      return "MAIL_ADDRESS_NOT_VALIDATED";
   } else if (result == act::ResultExcessiveMailSendRequest) {
      return "EXCESSIVE_MAIL_SEND_REQUEST";
   } else if (result == act::ResultCreditCardError) {
      return "CREDIT_CARD_ERROR";
   } else if (result == act::ResultCreditCardGeneralFailure) {
      return "CREDIT_CARD_GENERAL_FAILURE";
   } else if (result == act::ResultCreditCardDeclined) {
      return "CREDIT_CARD_DECLINED";
   } else if (result == act::ResultCreditCardBlacklisted) {
      return "CREDIT_CARD_BLACKLISTED";
   } else if (result == act::ResultInvalidCreditCardNumber) {
      return "INVALID_CREDIT_CARD_NUMBER";
   } else if (result == act::ResultInvalidCreditCardDate) {
      return "INVALID_CREDIT_CARD_DATE";
   } else if (result == act::ResultInvalidCreditCardPin) {
      return "INVALID_CREDIT_CARD_PIN";
   } else if (result == act::ResultInvalidPostalCode) {
      return "INVALID_POSTAL_CODE";
   } else if (result == act::ResultInvalidLocation) {
      return "INVALID_LOCATION";
   } else if (result == act::ResultCreditCardDateExpired) {
      return "CREDIT_CARD_DATE_EXPIRED";
   } else if (result == act::ResultCreditCardNumberWrong) {
      return "CREDIT_CARD_NUMBER_WRONG";
   } else if (result == act::ResultCreditCardPinWrong) {
      return "CREDIT_CARD_PIN_WRONG";
   }

   if (result == act::ResultBanned) {
      return "BANNED";
   } else if (result == act::ResultBannedAccount) {
      return "BANNED_ACCOUNT";
   } else if (result == act::ResultBannedAccountAll) {
      return "BANNED_ACCOUNT_ALL";
   } else if (result == act::ResultBannedAccountInApplication) {
      return "BANNED_ACCOUNT_IN_APPLICATION";
   } else if (result == act::ResultBannedAccountInNexService) {
      return "BANNED_ACCOUNT_IN_NEX_SERVICE";
   } else if (result == act::ResultBannedAccountInIndependentService) {
      return "BANNED_ACCOUNT_IN_INDEPENDENT_SERVICE";
   } else if (result == act::ResultBannedDevice) {
      return "BANNED_DEVICE";
   } else if (result == act::ResultBannedDeviceAll) {
      return "BANNED_DEVICE_ALL";
   } else if (result == act::ResultBannedDeviceInApplication) {
      return "BANNED_DEVICE_IN_APPLICATION";
   } else if (result == act::ResultBannedDeviceInNexService) {
      return "BANNED_DEVICE_IN_NEX_SERVICE";
   } else if (result == act::ResultBannedDeviceInIndependentService) {
      return "BANNED_DEVICE_IN_INDEPENDENT_SERVICE";
   } else if (result == act::ResultBannedAccountTemporarily) {
      return "BANNED_ACCOUNT_TEMPORARILY";
   } else if (result == act::ResultBannedAccountAllTemporarily) {
      return "BANNED_ACCOUNT_ALL_TEMPORARILY";
   } else if (result == act::ResultBannedAccountInApplicationTemporarily) {
      return "BANNED_ACCOUNT_IN_APPLICATION_TEMPORARILY";
   } else if (result == act::ResultBannedAccountInNexServiceTemporarily) {
      return "BANNED_ACCOUNT_IN_NEX_SERVICE_TEMPORARILY";
   } else if (result == act::ResultBannedAccountInIndependentServiceTemporarily) {
      return "BANNED_ACCOUNT_IN_INDEPENDENT_SERVICE_TEMPORARILY";
   } else if (result == act::ResultBannedDeviceTemporarily) {
      return "BANNED_DEVICE_TEMPORARILY";
   } else if (result == act::ResultBannedDeviceAllTemporarily) {
      return "BANNED_DEVICE_ALL_TEMPORARILY";
   } else if (result == act::ResultBannedDeviceInApplicationTemporarily) {
      return "BANNED_DEVICE_IN_APPLICATION_TEMPORARILY";
   } else if (result == act::ResultBannedDeviceInNexServiceTemporarily) {
      return "BANNED_DEVICE_IN_NEX_SERVICE_TEMPORARILY";
   } else if (result == act::ResultBannedDeviceInIndependentServiceTemporarily) {
      return "BANNED_DEVICE_IN_INDEPENDENT_SERVICE_TEMPORARILY";
   }

   if (result == act::ResultServiceNotProvided) {
      return "SERVICE_NOT_PROVIDED";
   } else if (result == act::ResultUnderMaintenance) {
      return "UNDER_MAINTENANCE";
   } else if (result == act::ResultServiceClosed) {
      return "SERVICE_CLOSED";
   } else if (result == act::ResultNintendoNetworkClosed) {
      return "NINTENDO_NETWORK_CLOSED";
   } else if (result == act::ResultNotProvidedCountry) {
      return "NOT_PROVIDED_COUNTRY";
   } else if (result == act::ResultRestrictionError) {
      return "RESTRICTION_ERROR";
   } else if (result == act::ResultRestrictedByAge) {
      return "RESTRICTED_BY_AGE";
   } else if (result == act::ResultRestrictedByParentalControls) {
      return "RESTRICTED_BY_PARENTAL_CONTROLS";
   } else if (result == act::ResultOnGameInternetCommunicationRestricted) {
      return "ON_GAME_INTERNET_COMMUNICATION_RESTRICTED";
   } else if (result == act::ResultInternalServerError) {
      return "INTERNAL_SERVER_ERROR";
   } else if (result == act::ResultUnknownServerError) {
      return "UNKNOWN_SERVER_ERROR";
   } else if (result == act::ResultUnauthenticatedAfterSalvage) {
      return "UNAUTHENTICATED_AFTER_SALVAGE";
   } else if (result == act::ResultAuthenticationFailureUnknown) {
      return "AUTHENTICATION_FAILURE_UNKNOWN";
   }

   return "<unknown>";
}

const char *
GetDescriptionString(nn::Result result)
{
   if (result.isLegacyRepresentation()) {
      return GetLegacyDescriptionString(result);
   }

   switch (result.module()) {
   case nn::Result::MODULE_NN_ACP:
      return GetAcpDescriptionString(result);
   case nn::Result::MODULE_NN_ACT:
      return GetActDescriptionString(result);
   }

   return "<unknown>";
}

} // namespace nn::dbg
