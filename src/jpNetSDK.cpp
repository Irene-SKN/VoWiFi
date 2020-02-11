#include "jpNetSDK.h"

JP_NETSDK_API ZBOOL SDK_Init()
{
    plog::init(plog::debug, "JpLog.txt", (1024*1024), 1);

    CHttpMsg *pHttpMsg = CHttpMsg::GetInstance();
    assert(NULL != pHttpMsg);
#if 1
    pHttpMsg->UploadSDKState();
    pHttpMsg->GetValidServerUrl();
#else
    ZBOOL bRet = pHttpMsg->UploadSDKState();
    if (!bRet) return bRet;

    bRet = pHttpMsg->GetValidServerUrl();
    if(!bRet) return bRet;
#endif
    CJpAudioMng *pAudioMng = CJpAudioMng::GetInstance();
    assert(NULL != pAudioMng);
    pAudioMng->InitAudio();
    pAudioMng->StartAudioAdp(EN_INPUTSDK_OUTPUTSDK_TYPE);

    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);
    return pInitSdkMng->InitSdk();
}

JP_NETSDK_API ZVOID SDK_CleanUp()
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);
    pInitSdkMng->CleanUpSdk();
}

JP_NETSDK_API ZBOOL SDK_Login(ZCHAR *pcPrint)
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    return pInitSdkMng->ReLogin(pcPrint);
}

JP_NETSDK_API ZBOOL SDK_LoginOut()
{
    ZBOOL bRet;
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    bRet = pInitSdkMng->LoginOut();

    CHttpMsg *pHttpMsg = CHttpMsg::GetInstance();
    assert(NULL != pHttpMsg);

    ZBOOL bAutoCfg = CJpSdkMng::GetInstance()->IsAutoLoginWay();
    CHttpMsg::GetInstance()->ReportRegister(ENUM_HTTP_PARSE_UNREGISTER, bAutoCfg);
    return bRet;
}

JP_NETSDK_API ZINT  SDK_StartOneCall(ZCHAR *pcUri)
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    return pInitSdkMng->StartCall(pcUri);
}

JP_NETSDK_API ZINT  SDK_TermOneCall()
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    return pInitSdkMng->HungUpCall();
}

JP_NETSDK_API ZINT  SDK_PickUpOneCall()
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    return pInitSdkMng->PickUpCall();
}

JP_NETSDK_API ZINT  SDK_SendDtmf(ZCHAR* pcNumber)
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    return pInitSdkMng->SendDtmf(pcNumber);
}

JP_NETSDK_API ZBOOL SDK_GetRegState()
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    return pInitSdkMng->GetRegStatus();
}

JP_NETSDK_API ZBOOL SDK_GetTakingState()
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    return pInitSdkMng->GetTakingStatus();
}

JP_NETSDK_API ZVOID SDK_SetCallPhone(ZCHAR *pcNumber)
{
    CJpSdkMng *pInitSdkMng = CJpSdkMng::GetInstance();
    assert(NULL != pInitSdkMng);

    pInitSdkMng->SetCallNumer(pcNumber);
}


