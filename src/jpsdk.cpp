#include "jpsdk.h"
#include "commFunc.h"
#include "jpAudioMng.h"

#ifndef  TMTC_SLEEP_PING
#define  TMTC_SLEEP_PING   10
#endif

#ifndef  TMTC_PING_RETRY
#define  TMTC_PING_RETRY   3
#endif

#ifndef  TMTC_DOWNLICENSE_NUM
#define  TMTC_DOWNLICENSE_NUM 2
#endif

CJpSdkMng *CJpSdkMng::m_pJpMng = nullptr;
CJpSdkMng::CGarbo CJpSdkMng::m_garbo;

CJpSdkMng::CJpSdkMng()
         : m_iSessCallId(TMTC_INVALID_CALLID)
{
    m_strCallNumber.clear();
#ifdef TMTC_PING_REMOTE
    m_bPingExits = ZFALSE;
#endif
}

CJpSdkMng::~CJpSdkMng()
{
#ifdef TMTC_PING_REMOTE
    StopPingThread();
#endif
    CleanUpSdk();
}

CJpSdkMng *CJpSdkMng::GetInstance()
{
    if (nullptr == m_pJpMng)
    {
        static std::mutex myOSMutex;
        myOSMutex.lock();
        if (nullptr == m_pJpMng)
        {
            m_pJpMng = new CJpSdkMng;

            if (nullptr == m_pJpMng)
            {
                myOSMutex.unlock();
                return nullptr;
            }
            myOSMutex.unlock();
        }
    }

    return m_pJpMng;
}

ZBOOL CJpSdkMng::InitSdk()
{
    ZINT iRet = ZFAILED;

    // set mtc log and mme log file directory
    iRet = Mtc_CliCfgSetLogDir(COVER_TO_CHAR(TMTC_LOGFILE_DIR));
    TMTC_LOG_PRINTE(iRet, "init log Dir Path failed.");

    // set License path
    iRet = Mtc_CliCfgSetLicenseFileName(COVER_TO_CHAR(TMTC_LICENSE_PATH));
    TMTC_LOG_PRINTE(iRet, "init License Path failed.");

    Mtc_CliCfgSetLogPrint(ZFALSE);
    Mtc_CliCfgSetFileEncrypt(ZFALSE);
    Mtc_CliCfgSetLogLevel(EN_MTC_LOG_LEVEL_INFO);
#if(defined TMTC_501_VESION)
    Mtc_CliCfgSetLogFileSize(1024 * 1024);
    Mtc_CliCfgSetLogFileCount(10);
#endif
    SetCallBack();

    iRet = Mtc_ModCom_Register();
    TMTC_LOG_PRINTE(iRet, "com module Register failed.");

    iRet = Mtc_ModCp_Register();
    TMTC_LOG_PRINTE(iRet, "cp module Register failed.");

    iRet = Mtc_ModVoip_Register();
    TMTC_LOG_PRINTE(iRet, "voip module Register failed");

    // start init enviroment
    iRet = InitEnv();
    TMTC_LOG_PRINTE(iRet, "init mtc enviroment failed.");

    // start login account
    iRet = LoginAccout();

    return (ZOK == iRet);
}

ZINT  CJpSdkMng::InitEnv()
{
    static ZINT iDownLicenseNum = 0;
    string strTmp;
    ZINT iRet = Mtc_CliInit(COVER_TO_CHAR(TMTC_INIT_PROFILE));
    if (iRet != ZOK)
    {
       if (MTC_LCS_ERR_NEED_ACT_LICSEN == iRet)
       {
         LOGW << "start DownLicense...";

         strTmp.clear();
         strTmp = "init mtc enviroment failed iRet[" + to_string(iRet)
                 + "] iInitNum[" + to_string(iDownLicenseNum) + "]";
         TMTC_LOG_PRINTE(iRet, strTmp);

         ZBOOL bRet =  CHttpMsg::GetInstance()->DownLoadLicense();

         if (bRet && iDownLicenseNum <= TMTC_DOWNLICENSE_NUM)
         {
             iDownLicenseNum ++;
             return InitEnv();
         }

       }
    }

    return iRet;
}

ZVOID CJpSdkMng::CleanUpSdk()
{
    Mtc_CliDestroy();
}

ZINT CJpSdkMng::LoginAccout()
{
    ZINT iRet = ZOK;

    if (EN_ACCOUNT_SIP == m_stConfig.u.stManual.iAccountType
        && EN_LOGIN_MANUAL == m_stConfig.aucLoginWay)
        Mtc_CliCfgSetRegSrvType(EN_MTC_REG_SRV_VOIP);
    else
        Mtc_CliCfgSetRegSrvType(EN_MTC_REG_SRV_JOYN_HF);

#if(defined TMTC_SET_MME_LEVEL)
    Mtc_ProvDbSetMmeLogLevel(5);
    Mtc_CliDbApplyAll();
    Mtc_ProfSaveProvision();
#endif

    if(EN_LOGIN_MANUAL == m_stConfig.aucLoginWay)
       iRet = Mtc_CliOpen(COVER_TO_CHAR(m_stConfig.u.stManual.acUserNumber));
    else
       iRet= Mtc_CliOpen(COVER_TO_CHAR(m_stConfig.u.stAuto.uacCuei));

    TMTC_LOG_PRINTE(iRet, "open acount failed.");

    iRet = Mtc_CliStart();
    TMTC_LOG_PRINTE(iRet, "start service failed.");

    Mtc_RingSetDir(COVER_TO_CHAR(TMTC_RING_DIR), strlen(TMTC_RING_DIR));

    Mtc_CallDbSetAecEnable(ZFALSE);
    Mtc_CallDbSetAgcEnable(ZFALSE);
    Mtc_CallDbSetAnrEnable(ZFALSE);

    // set voice activity detection
    Mtc_CallDbSetVadEnable(ZTRUE);
    Mtc_CallDbSetVadMode(EN_MTC_VAD_NORMAL);

    // set user register capability
    Mtc_CliCfgClrRegCap(MTC_REG_CAP_OPT_ALL);
    Mtc_CliCfgClrCmccExtRegCap(MTC_CMCC_EXT_REG_CAP_OPT_ALL);
    Mtc_CliDbSetUserIdPolicy(EN_MTC_UID_POLICY_FIRST);
    Mtc_CallDbSetRtpBreakTime(TMTC_RTPBREAKT_LEN);
    // enable backup server address , 2nd register
#if(defined TMTC_SUPT_BACKUPSEVER)
    Mtc_CliDbSetUseBackupServer(ZTRUE);
#endif
    // set sdk inner params, don't modifty it
    Mtc_ProvDbSetCliVendor(COVER_TO_CHAR("Juphoon"));
    Mtc_ProvDbSetCliVer(COVER_TO_CHAR("1911011"));
    Mtc_ProvDbSetTmnlType(COVER_TO_CHAR("CUEI"));
    Mtc_ProvDbSetTmnlModel(COVER_TO_CHAR("SOUND"));
    Mtc_ProvDbSetTmnlSwVer(COVER_TO_CHAR("v0.1"));

    // default Ipv4 way, if use Ipv6 to register, set ZFALSE
    Mtc_CliDbSetUseIpv4(ZTRUE);

    if (EN_ACCOUNT_SIP == m_stConfig.u.stManual.iAccountType
        && EN_LOGIN_MANUAL == m_stConfig.aucLoginWay)
    {
        Mtc_CliDbSetSubsRegEvnt(ZFALSE);
        Mtc_CliDbSetRegExpire(TMTC_REG_EXPIRE_LEN);
        Mtc_CliDbSetKeepAliveType(EN_MTC_KEEP_ALIVE_DISABLE);
        Mtc_CallDbSetSessTmrInfo(EN_MTC_DB_SESSION_TIME_FORCE, EN_MTC_DB_REFRESHER_UAC, 180, 60);

        for (ZUINT i = 0; i < Mtc_CallDbGetAudioCodecCount(); i++)
        {
              ZCHAR *pcCode = Mtc_CallDbGetAudioCodecByPriority(i);
              Mtc_CallDbSetAudioCodecEnable(pcCode, ZFALSE);
        }

        Mtc_CallDbSetAudioCodecEnable(COVER_TO_CHAR("PCMA"), ZTRUE);
        Mtc_CallDbSetAudioCodecEnable(COVER_TO_CHAR("PCMU"), ZTRUE);
        Mtc_CallDbSetAudioCodecByPriority(COVER_TO_CHAR("PCMA"), 0);
        Mtc_CallDbSetAudioCodecByPriority(COVER_TO_CHAR("PCMU"), 1);
    }
    else
        Mtc_CliDbSetKeepAliveType(EN_MTC_KEEP_ALIVE_OPTIONS);

    if (EN_LOGIN_AUTO == m_stConfig.aucLoginWay)
        iRet = LoginAutoCfg();
    else
        iRet = LoginManualCfg();

    return iRet;
}

ZINT CJpSdkMng::LoginManualCfg()
{
    string strAuthName, strUsrName;
    ZINT iRet = ZOK;

    CCommFunc::AccountAdp(m_stConfig.u.stManual.iAccountType,
                          COVER_TO_CHAR(m_stConfig.u.stManual.acUserNumber),
                          COVER_TO_CHAR(m_stConfig.u.stManual.acDomainName),
                          strAuthName, strUsrName);

    // start set user params
    Mtc_CliDbSetUserName(COVER_TO_CHAR(strUsrName.c_str()));
    Mtc_CliDbSetAuthName(COVER_TO_CHAR(strAuthName.c_str()));
    Mtc_CliDbSetAuthPass(COVER_TO_CHAR(m_stConfig.u.stManual.acUserPwd));
    Mtc_CliDbSetSipRegRealm(COVER_TO_CHAR(m_stConfig.u.stManual.acDomainName));
    Mtc_CliDbSetSipRegRealm(COVER_TO_CHAR(m_stConfig.u.stManual.acDomainName));
    Mtc_CliDbSetSipRegIp(COVER_TO_CHAR(m_stConfig.u.stManual.acServerIp));
    Mtc_CliDbSetSipRegTpt(m_stConfig.u.stManual.ucTransprotType);

    switch (m_stConfig.u.stManual.ucTransprotType)
    {
       case EN_MTC_TPT_UDP:
            Mtc_CliDbSetSipRegUdpPort(m_stConfig.u.stManual.iServerPort);
           break;
       case EN_MTC_TPT_TCP:
            Mtc_CliDbSetSipRegTcpPort(m_stConfig.u.stManual.iServerPort);
           break;
       case EN_MTC_TPT_TLS:
            Mtc_CliDbSetSipRegTlsPort(m_stConfig.u.stManual.iServerPort);
           break;
       default:
           break;
     }
#if(defined TMTC_SUPT_BACKUPSEVER)
     Mtc_CliDbSet2ndSipRegIp(COVER_TO_CHAR(m_stConfig.u.stManual.acDomainName));
     Mtc_CliDbSet2ndSipRegUdpPort(m_stConfig.u.stManual.iServerPort);
     Mtc_CliDbSet2ndSipRegTcpPort(m_stConfig.u.stManual.iServerPort);
     Mtc_CliDbSet2ndSipRegTlsPort(m_stConfig.u.stManual.iServerPort);
#endif
    iRet |= Mtc_CliDbApplyAll();
    iRet |= Mtc_ProfSaveProvision();

    if (ZOK == iRet)
    {
        ZCHAR *pcLocalIp = Mtc_GetLclIp(0);
        ZUINT iNetType = Mtc_GetAccessNetType();
        iRet = Mtc_CliLogin(iNetType, pcLocalIp);
        TMTC_LOG_PRINTE(iRet, COVER_TO_CHAR("login interface failed."));
    }

    return iRet;
}

ZINT CJpSdkMng::LoginAutoCfg(ZCHAR *pcReCpImei /*= nullptr*/)
{
    ZINT iRet = ZOK;

    if (!TCHECK_ISEMPTY_STR(pcReCpImei))
        Mtc_ProvDbSetImei(pcReCpImei);
    else
        Mtc_ProvDbSetImei(m_stConfig.u.stAuto.uacCuei);

    Mtc_ProvDbSetTmnlType(COVER_TO_CHAR("CUEI"));
    Mtc_ProvDbSetTmnlVendor(m_stConfig.u.stAuto.uacTmnlVendor);
#if(defined TMTC_DOMAIN_TEST)
    CHttpMsg *pTmpHttpMsg = CHttpMsg::GetInstance();
    Mtc_CpDbSetSrvAddr(pTmpHttpMsg->GetDmsUrl());
#else
   Mtc_CpDbSetSrvAddr(m_stConfig.u.stAuto.uacDmsIp);
#endif
    Mtc_CpDbSetSrvRoot(COVER_TO_CHAR("/dms/getConf"));

    iRet |= Mtc_CliDbApplyAll();
    iRet |= Mtc_ProfSaveProvision();

    if (ZOK == iRet)
    {
        ZUINT iCpId = Mtc_Cp(EN_MTC_CP_NET_WIFI, COVER_TO_CHAR(""));
        LOGD <<"Mtc_Cp iCpId:[" << to_string(iCpId) << "]";
    }

    return iRet;
}

ZINT CJpSdkMng::tmtc_MtcCliCbPrint(ZCHAR *pcStr)
{
    CCommFunc::PrintInTermiate(EN_PRINT_WHITE, pcStr);
    return ZOK;
}

ZINT CJpSdkMng::tmtc_MtcCliCbEvnt(ZEVNT zEvntId)
{
    Mtc_CliDrive(zEvntId);
    return ZOK;
}

ZINT CJpSdkMng::tmtc_MtcCliCbLoginOk(ZFUNC_VOID)
{
    ZCHAR *pcCallNumber = CJpSdkMng::GetInstance()->GetCallNumber();

    if (!TCHECK_ISEMPTY_STR(pcCallNumber))
    {
        CJpSdkMng::GetInstance()->StartCall(pcCallNumber);
        CJpSdkMng::GetInstance()->SetCallNumer(string(""));
    }

    CCommFunc::PrintInTermiate(EN_PRINT_GREEN, "Login Success.");
    LOGI << "Login Success.";

    ZBOOL bAutoCfg = CJpSdkMng::GetInstance()->IsAutoLoginWay();
    CHttpMsg::GetInstance()->ReportRegister(ENUM_HTTP_PARSE_REGISTER, bAutoCfg);

    return ZOK;
}

ZINT CJpSdkMng::tmtc_MtcCliCbSetLoginFailed(ZUINT iStatCode)
{
    string strTmp;
    strTmp += "Login Failed Code[";
    strTmp += to_string(iStatCode);
    strTmp += "]";

    CCommFunc::PrintInTermiate(EN_PRINT_RED, strTmp.c_str());
    LOGE << strTmp;
    return ZOK;
}

ZVOID CJpSdkMng::tmtc_MtcCliCbSetRegStatChanged(ZUINT iRegStat, ZUINT iStatCode)
{
    static ZINT iReLoginNum = 0;

    string strTmp;
    strTmp += "RegStatChanged iRegStat[";
    strTmp += to_string(iRegStat);
    strTmp += "]iStatCode[";
    strTmp += to_string(iStatCode);
    strTmp += "]";

    CCommFunc::PrintInTermiate(EN_PRINT_WHITE, strTmp);
    LOGD << strTmp;

    switch (iStatCode)
    {
        case MTC_CLI_REG_ERR_TIMEOUT:
        case MTC_CLI_REG_ERR_SERV_NOT_REACH:
        case MTC_CLI_REG_ERR_SERV_BUSY:
        case MTC_CLI_REG_ERR_SRV_UNAVAIL:
        case MTC_CLI_REG_ERR_DNS_QRY:
        case MTC_CLI_REG_ERR_DEACTED:
        case MTC_CLI_REG_ERR_INTERNAL:
        case MTC_CLI_REG_ERR_NO_RESOURCE:
        case MTC_CLI_REG_ERR_SIP_SESS:
        case MTC_CLI_REG_ERR_UNREG:
        case MTC_CLI_REG_ERR_WAIT_PWD:
             {
                if (iReLoginNum >= (TMTC_RETRYLOGIN_NUM * 100))
                            return;
                /* retry login */
                if (0 == iReLoginNum % TMTC_RETRYLOGIN_NUM)
                {
                   /* "127.0.0.1" local ip address to connetct server */
                   Mtc_CliLogin(Mtc_GetAccessNetType(), Mtc_GetLclIp(0));
                }

                iReLoginNum ++ ;
             }
             break;
        default:
            break;
    }
}

ZVOID CJpSdkMng::tmtc_MtcCallCbSetTalking(ZUINT iSessId)
{
    string strTmp;
    strTmp = "Taking iSessId:" + to_string(iSessId);
    CCommFunc::PrintInTermiate(EN_PRINT_WHITE, strTmp);
    LOGI << "Current Taking....";
    CHttpMsg::GetInstance()->RingCall(ZTRUE);
}

ZVOID CJpSdkMng::tmtc_MtcCallCbAlerted(ZUINT iSessId, ZUINT iAlertType)
{
    string strTmp;
    CJpSdkMng::GetInstance()->SetCallId(iSessId);

    strTmp += "SessId[";
    strTmp += to_string(iSessId);
    strTmp += "]iAleryType[";
    strTmp += to_string(iAlertType);
    strTmp += "]";

    CCommFunc::PrintInTermiate(EN_PRINT_WHITE, strTmp);
    LOGI << strTmp;

    CHttpMsg::GetInstance()->RingCall(ZFALSE);
}

ZVOID CJpSdkMng::tmtc_MtcCallCbIncoming(ZUINT iSessId)
{
    string strTmp;
    if (TMTC_INVALID_CALLID == CJpSdkMng::GetInstance()->GetCallId())
    {
        CJpSdkMng::GetInstance()->SetCallId(iSessId);

        ZCHAR *pcDispName = nullptr;
        ZCHAR *pcUri = nullptr;
        Mtc_SessGetPeerId(iSessId, &pcDispName, &pcUri);

        strTmp.clear();
        strTmp = "Recv DispName[" + string(pcDispName) + "]pcUri[" + string(pcUri) +"]" ;
        CCommFunc::PrintInTermiate(EN_PRINT_WHITE, strTmp);
        LOGI << strTmp;

        if(!TCHECK_ISEMPTY_STR(pcUri))
            CJpAudioMng::GetInstance()->DecodeIncomingUrl(Mtc_UriGetUserPart(pcUri));

#if((defined TMTC_INTUSER_OUTUSER) || (defined TMTC_INTSDK_OUTUSER))
        CJpAudioMng::GetInstance()->NotifyOne();
#endif
    }
    else
    {
        strTmp.clear();
        strTmp = "Current Exits Calling, So Reject Incoming Call.";
        CCommFunc::PrintInTermiate(EN_PRINT_RED, strTmp);
        LOGW << strTmp;

        Mtc_SessTerm(iSessId, EN_MTC_CALL_TERM_REASON_BUSY);
    }
}

ZVOID CJpSdkMng::tmtc_MtcCallCbSetTermed(ZUINT iSessId, ZUINT iStatCode)
{
    string strTmp = "SessId[" + to_string(iSessId) + "]iStatCode[" + to_string(iStatCode) + "]";
    CCommFunc::PrintInTermiate(EN_PRINT_GREEN, strTmp);
    LOGI << strTmp;

    if(CJpSdkMng::GetInstance()->GetCallId() == iSessId)
    {
       CJpSdkMng::GetInstance()->SetCallId(TMTC_INVALID_CALLID);
       CHttpMsg::GetInstance()->StopCall();
    }
    else
    {
        strTmp.clear();
        strTmp = "Recv Term But Is Is not Calling Session Id.";
        CCommFunc::PrintInTermiate(EN_PRINT_RED, strTmp);
        LOGW << strTmp;
    }
}

ZVOID CJpSdkMng::tmtc_MtcCallCbSetOutgoing(ZUINT iSessId)
{
    string strTmp = "Start Call Out.";
    CCommFunc::PrintInTermiate(EN_PRINT_WHITE, strTmp);
    CJpSdkMng::GetInstance()->SetCallId(iSessId);
    LOGI << strTmp;

#if((defined TMTC_INTUSER_OUTUSER) || (defined TMTC_INTSDK_OUTUSER))
    CJpAudioMng::GetInstance()->NotifyOne();
#endif

}

ZVOID CJpSdkMng::tmtc_MtcCallCbSetNetStaChanged(ZUINT iSessId,
                ZBOOL bVideo, ZBOOL bSend, ZINT iType)
{
     string strTmp;
     strTmp = "iSessId[" + to_string(iSessId) + "]bSend[" + to_string(bSend)
              +"]iType[" + to_string(iType) +"]" + "bVideo[" + to_string(bVideo) +"]";

     CCommFunc::PrintInTermiate(EN_PRINT_WHITE, strTmp);
     LOGI << strTmp;

     // rtp break callback
     if (EN_MTC_NET_STATUS_DISCONNECTED == iType
         && iSessId == CJpSdkMng::GetInstance()->GetCallId())
     {
         strTmp.clear();
         strTmp = "Current Device Network UnReachable.";
         CCommFunc::PrintInTermiate(EN_PRINT_RED, strTmp);
         LOGE << strTmp;

         Mtc_CliNetUnavailable();
         tmtc_MtcCallCbSetTermed(iSessId, 0);
     }
}

ZINT CJpSdkMng::tmtc_CliCbSetRefreshOk(ZBOOL bActive, ZBOOL bChanged)
{
   string strTmp;
   ZUINT iRegState = Mtc_CliGetRegState();

   strTmp = "iRegState[" + to_string(iRegState) + "]bActive[" + to_string(bActive)
            +"]bChanged[" + to_string(bChanged) + "]" ;

   CCommFunc::PrintInTermiate(EN_PRINT_GREEN, strTmp);
   LOGD << strTmp;

   return ZOK;
}

ZVOID CJpSdkMng::tmtc_MtcCpCbSetCpOk(ZUINT iCpId)
{
   string strTmp = "Auto Cp Success iCpId[" + to_string(iCpId) + "]";
   CCommFunc::PrintInTermiate(EN_PRINT_GREEN, strTmp);
   LOGI << strTmp;

   Mtc_CliLogin(Mtc_GetAccessNetType(), Mtc_GetLclIp(0));
}

// upper  must write statCode  and RspCode to your log file
ZVOID CJpSdkMng::tmtc_MtcCpCbSetCpFailed(ZUINT iCpId, ZCHAR *pcRspCode, ZUINT iStatCode)
{
    string strTmp = "Cp Failed CpId[" + to_string(iCpId)
                    + "]pcRspCode[" + string(pcRspCode)
                    +"]iStatCode[" + to_string(iStatCode) + "]";
    LOGE << strTmp;
}

ZVOID CJpSdkMng::tmtc_MtcCpCbSetCpExpire(ZUINT iExpireType)
{
    string strTmp;
    ZUINT iValidTime = Mtc_CpDbGetVerValidTime();
    strTmp = "Cp ValidTime[" + to_string(iValidTime) + "]"
             + "ExprieType[" + to_string(iExpireType) + "]";

    LOGI << strTmp;
    CJpSdkMng::GetInstance()->LoginAutoCfg(nullptr);
}

ZVOID CJpSdkMng::SetCallBack()
{
    Mtc_CliCbSetPrint(tmtc_MtcCliCbPrint);
    Mtc_CliCbSetEvnt(tmtc_MtcCliCbEvnt);

    Mtc_CliCbSetServLoginOk(tmtc_MtcCliCbLoginOk);
    Mtc_CliCbSetLoginFailed(tmtc_MtcCliCbSetLoginFailed);
    Mtc_CliCbSetRegStatChanged(tmtc_MtcCliCbSetRegStatChanged);
    Mtc_CliCbSetRefreshOk(tmtc_CliCbSetRefreshOk);

    Mtc_CallCbSetTalking(tmtc_MtcCallCbSetTalking);
    Mtc_CallCbSetAlerted(tmtc_MtcCallCbAlerted);
    Mtc_CallCbSetIncoming(tmtc_MtcCallCbIncoming);
    Mtc_CallCbSetTermed(tmtc_MtcCallCbSetTermed);
    Mtc_CallCbSetOutgoing(tmtc_MtcCallCbSetOutgoing);
    Mtc_CallCbSetNetStaChanged(tmtc_MtcCallCbSetNetStaChanged);

    Mtc_CpCbSetCpOk(tmtc_MtcCpCbSetCpOk);
    Mtc_CpCbSetCpFailed(tmtc_MtcCpCbSetCpFailed);
    Mtc_CpCbSetCpExpire(tmtc_MtcCpCbSetCpExpire);
}

ZINT  CJpSdkMng::StartCall(ZCHAR *pcNumber)
{
  string strCallPhone;

  if (TCHECK_ISEMPTY_STR(pcNumber))
  {
      LOGE << "Call PhoneNum Is Empty.";
      return ZFAILED;
  }

  if (EN_ACCOUNT_SIP == m_stConfig.u.stManual.iAccountType && EN_LOGIN_MANUAL == m_stConfig.aucLoginWay)
      CCommFunc::CoverToUri(m_stConfig.u.stManual.acServerIp, pcNumber, strCallPhone);
  else
      CCommFunc::CoverToUri(nullptr, pcNumber, strCallPhone);

   m_iSessCallId = Mtc_SessCall(COVER_TO_CHAR(strCallPhone.c_str()), 0, ZTRUE, ZFALSE);

#if((defined TMTC_INTUSER_OUTSDK) || (defined TMTC_INTUSER_OUTUSER))
    /** to tranmit sdp to server ,for example 183 session */
    CJpAudioMng::GetInstance()->StartZeroAudioInput();
#endif

    std::string strCallUri = Mtc_CliDbGetUserName();
    std::string calledUri = pcNumber;
    std::string callUri = (strCallUri.find("+86") == std::string::npos) ? strCallUri : strCallUri.substr(3);

    ZBOOL bAutoCfg = CJpSdkMng::GetInstance()->IsAutoLoginWay();
    CHttpMsg::GetInstance()->StartCall(callUri, calledUri, bAutoCfg);
    return m_iSessCallId;
}

ZINT CJpSdkMng::HungUpCall()
{
    ZINT iRet = ZFAILED;

    if (TMTC_INVALID_CALLID == m_iSessCallId)
        return iRet;

    iRet = Mtc_SessTerm(m_iSessCallId, EN_MTC_CALL_TERM_REASON_DECLINE);
    CHttpMsg::GetInstance()->StopCall();

    if (ZOK == iRet)
        m_iSessCallId = TMTC_INVALID_CALLID;

    return iRet;
}

ZINT CJpSdkMng::PickUpCall()
{
    if (m_iSessCallId != TMTC_INVALID_CALLID)
        return Mtc_SessAnswer(m_iSessCallId, 0, ZTRUE, ZFALSE);

    return ZFAILED;
}

ZINT CJpSdkMng::RejectCall()
{
    ZINT iRet = ZFAILED;

    if (TMTC_INVALID_CALLID == m_iSessCallId)
        return iRet;

    iRet = Mtc_SessTerm(m_iSessCallId, EN_MTC_CALL_TERM_REASON_BUSY);

    if (ZOK == iRet)
       m_iSessCallId = TMTC_INVALID_CALLID;

    CHttpMsg::GetInstance()->StopCall();
    return iRet;
}

ZBOOL CJpSdkMng::GetRegStatus()
{
    return (MTC_REG_STATE_REGED == Mtc_CliGetRegState());
}

ZBOOL CJpSdkMng::GetTakingStatus()
{
    if (m_iSessCallId != TMTC_INVALID_CALLID)
        return Mtc_SessHasTalk(m_iSessCallId);

    return ZFALSE;
}

ZBOOL CJpSdkMng::ReLogin(ZCHAR *pcPrint)
{
    ZCHAR *pcLocalIp = Mtc_GetLclIp(0);
    ZUINT iNetType = Mtc_GetAccessNetType();

    if (!TCHECK_ISEMPTY_STR(pcPrint))
       CCommFunc::PrintInTermiate(EN_PRINT_RED, pcPrint);

    return (ZOK == Mtc_CliLogin(iNetType, pcLocalIp));
}

ZBOOL CJpSdkMng::LoginOut()
{
    if (GetTakingStatus())
        HungUpCall();

    return (ZOK == Mtc_CliLogout());
}

ZINT CJpSdkMng::SendDtmf(const string &strType)
{
    ZINT iRet = ZFAILED;
    ZUINT iType;

    if (TMTC_INVALID_CALLID == m_iSessCallId)
        return ZFAILED;

    iType = CoverDtmfType(strType);
    iRet = Mtc_SessDtmf(m_iSessCallId, iType);

    return iRet;
}

ZUCHAR CJpSdkMng::CoverDtmfType(const string&strType)
{
    ZUCHAR iType = EN_MTC_CALL_DTMF_0;

    std::map <std::string,EN_MTC_CALL_DTMF_TYPE> tDtmfMap =
    {
     {"0", EN_MTC_CALL_DTMF_0}, {"1", EN_MTC_CALL_DTMF_1}, {"2", EN_MTC_CALL_DTMF_2}, {"3", EN_MTC_CALL_DTMF_3},
     {"4", EN_MTC_CALL_DTMF_4}, {"5", EN_MTC_CALL_DTMF_5}, {"6", EN_MTC_CALL_DTMF_6}, {"7", EN_MTC_CALL_DTMF_7},
     {"8", EN_MTC_CALL_DTMF_8}, {"9", EN_MTC_CALL_DTMF_9}, {"*", EN_MTC_CALL_DTMF_STAR}, {"#", EN_MTC_CALL_DTMF_POUND},
     {"A", EN_MTC_CALL_DTMF_A}, {"B", EN_MTC_CALL_DTMF_B}, {"C", EN_MTC_CALL_DTMF_C}, {"D", EN_MTC_CALL_DTMF_D}
    };

    iType = tDtmfMap.at(strType);

    return (ZUCHAR)iType;
}

#ifdef TMTC_PING_REMOTE
// SOCK_RAW need root authority
ZVOID CJpSdkMng::StartPingThread()
{
    if (m_hPingThread.joinable())
        m_hPingThread.join();

    m_bPingExits = ZFALSE;
    m_hPingThread= std::thread(std::bind(&CJpSdkMng::PingThreadRun, this));
}

ZVOID CJpSdkMng::StopPingThread()
{
    m_bPingExits = ZTRUE ;

    if (m_hPingThread.joinable())
        m_hPingThread.join();
}

ZVOID CJpSdkMng::PingThreadRun()
{
    ZBOOL bReLogin = ZFALSE;
    string strTmp, strIp;
    ZINT iCount = 0;

    strIp = Mtc_CliDbGetSipRegIp();

    while(!m_bPingExits)
    {
        ZBOOL bRet= CCommFunc::UpingRemoteIp(strIp.c_str());
        if (bRet)
        {
            iCount = 0;
            if (bReLogin)
            {
                ReLogin(COVER_TO_CHAR("Ping Thread ReLogin."));
                bReLogin = ZFALSE;
            }

            strTmp = "Ping Remote Ip[" + string(strIp) + "]Success period["
                     + to_string(TMTC_SLEEP_PING) + "s]";
            CCommFunc::PrintInTermiate(EN_PRINT_WHITE, strTmp);
            LOGI << strTmp;
            continue;
        }

        iCount ++ ;
        if (iCount > 0 && 0 == iCount % TMTC_PING_RETRY)
        {
            iCount = 0;
            CCommFunc::PrintInTermiate(EN_PRINT_RED, string("Ping Remote Ip, Current Device Network UnReachable."));
            LOGE << "Ping Remote Ip, Current Device Network UnReachable.";
            Mtc_CliLogout();
            tmtc_MtcCallCbSetTermed(m_iSessCallId, 0);
            bReLogin = ZTRUE;
        }

        sleep(TMTC_SLEEP_PING);
    }
}
#endif
