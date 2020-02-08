#pragma once
#include "jpAudioMng.h"
#include "jpsdk.h"
#ifndef	__cplusplus
extern "C" {
#endif

#ifdef  JP_SUPT_EXPORT
#define JP_NETSDK_API  __attribute__((visibility("default")))
#else
#define JP_NETSDK_API
JP_NETSDK_API ZBOOL SDK_Init();
JP_NETSDK_API ZVOID SDK_CleanUp();
JP_NETSDK_API ZBOOL SDK_Login(ZCHAR *pcPrint);
JP_NETSDK_API ZBOOL SDK_LoginOut();
JP_NETSDK_API ZINT  SDK_StartOneCall(ZCHAR *pcUri);
JP_NETSDK_API ZINT  SDK_TermOneCall();
JP_NETSDK_API ZINT  SDK_PickUpOneCall();
JP_NETSDK_API ZINT  SDK_SendDtmf(ZCHAR* pcNumber);
JP_NETSDK_API ZBOOL SDK_GetRegState();
JP_NETSDK_API ZBOOL SDK_GetTakingState();
JP_NETSDK_API ZVOID SDK_SetCallPhone(ZCHAR *pcNumber);
#endif

#ifndef __cplusplus
}
#endif
