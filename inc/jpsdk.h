#pragma once
#include "commdatadef.h"
#include "httpmsg.h"

class CJpSdkMng
{
public:
    static CJpSdkMng *GetInstance();
    ZBOOL  InitSdk();
    ZVOID  CleanUpSdk();
    ZINT   LoginAccout();
    ZINT   StartCall(ZCHAR *pcNumber);
    ZINT   HungUpCall();
    ZINT   PickUpCall();
    ZINT   RejectCall();
    ZBOOL  ReLogin(ZCHAR *pcPrint);
    ZBOOL  LoginOut();
    ZBOOL  GetRegStatus();
    ZBOOL  GetTakingStatus();
    ZINT   SendDtmf(const string &strType);
public:
    ZBOOL IsAutoLoginWay()
    {
        return (m_stConfig.aucLoginWay == EN_LOGIN_AUTO);
    }

private:
    CJpSdkMng();
    ~CJpSdkMng();

    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if (CJpSdkMng::m_pJpMng)
            {
                SAFE_DELETE_PTR(CJpSdkMng::m_pJpMng);
            }
        }
    };

    static CJpSdkMng *m_pJpMng;
    static CGarbo m_garbo;

protected:
    static ZINT  tmtc_MtcCliCbPrint(ZCHAR *pcStr);
    static ZINT  tmtc_MtcCliCbEvnt(ZEVNT zEvntId);
    static ZINT  tmtc_MtcCliCbLoginOk(ZFUNC_VOID);
    static ZINT  tmtc_MtcCliCbSetLoginFailed(ZUINT iStatCode);
    static ZVOID tmtc_MtcCliCbSetRegStatChanged(ZUINT iRegStat, ZUINT iStatCode);
    static ZVOID tmtc_MtcCallCbSetTalking(ZUINT iSessId);
    static ZVOID tmtc_MtcCallCbAlerted(ZUINT iSessId, ZUINT iAlertType);
    static ZVOID tmtc_MtcCallCbIncoming(ZUINT iSessId);
    static ZVOID tmtc_MtcCallCbSetTermed(ZUINT iSessId, ZUINT iStatCode);
    static ZVOID tmtc_MtcCallCbSetOutgoing(ZUINT iSessId);
    static ZVOID tmtc_MtcCallCbSetNetStaChanged(ZUINT iSessId, ZBOOL bVideo, ZBOOL bSend, ZINT iType);
    static ZINT  tmtc_CliCbSetRefreshOk(ZBOOL bActive, ZBOOL bChanged);
    static ZVOID tmtc_MtcCpCbSetCpOk(ZUINT iCpId);
    static ZVOID tmtc_MtcCpCbSetCpFailed(ZUINT iCpId, ZCHAR *pcRspCode, ZUINT iStatCode);
    static ZVOID tmtc_MtcCpCbSetCpExpire(ZUINT iExpireType);
private:
    ZINT   LoginManualCfg();
    ZINT   LoginAutoCfg(ZCHAR *pcReCpImei = nullptr);
    ZVOID  SetCallBack();
    ZUCHAR CoverDtmfType(const string&strType);
#if TMTC_PING_REMOTE
public:
    ZVOID StartPingThread();
protected:
    ZVOID StopPingThread();
    ZVOID PingThreadRun();
#endif

    ZINT  InitEnv();
public:
    ZVOID SetCallNumer(const string &strNumber)
    {
        m_strCallNumber = strNumber;
    }

    ZCHAR *GetCallNumber()
    {
        return COVER_TO_CHAR(m_strCallNumber.c_str());
    }

    ZVOID SetCallId(ZUINT iCallId)
    {
        m_iSessCallId = iCallId;
    }

    ZUINT GetCallId()
    {
        return m_iSessCallId;
    }

private:
    ST_TMTC_LOGIN m_stConfig;
    string  m_strCallNumber;
    ZUINT   m_iSessCallId;

#if TMTC_PING_REMOTE
    ZBOOL   m_bPingExits;
    std::thread m_hPingThread;
#endif
};


