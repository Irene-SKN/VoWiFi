#pragma once
#include "commdatadef.h"

const std::string TMTC_REMOTE_ADDR = "47.103.69.233:8155";
#if(defined TMTC_SSL_TRANSPORT)
const std::string TMTC_HTTP_PRO = "https://";
#else
const std::string TMTC_HTTP_TPT = "http://";
#endif
const std::string TMTC_VALIDSERVAL_URL = TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/getValidServerUrl?functionType=0";
const std::string TMTC_UPLOADSDKSTATE = TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/uploadSDKState?dataType=2";
const std::string TMTC_START_CALL_URL = TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/ss/voiceCall";
const std::string TMTC_STOP_CALL_URL = TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/callEnd";
const std::string TMTC_UPDATE_CALL_URL = TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/updateCallTime";
//const std::string TMTC_REGISTER_URL = "http://101.207.176.139:8099/rest2/client/terminalVail";
const std::string  TMTC_REGISTER_URL = TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/event/";
const std::string TMTC_UPLOADLOG_URL= TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/logUpload";
const std::string TMTC_RINGTIME_URL = TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/ringTime/";
const std::string TMTC_LICENSE_URL = TMTC_HTTP_TPT + TMTC_REMOTE_ADDR + "/rest2/client/license/download?APPKEY=";

//"unicom-32arm-baidu"
const std::string  TMTC_SDK_APPID = "2";

#ifndef TMTC_LOCALPORT_LEN
#define TMTC_LOCALPORT_LEN 80
#endif

#ifndef  TMTC_TIMEOUT_LEN
#define  TMTC_TIMEOUT_LEN 3
#endif

#define  TMTC_DEVURL_VALID_LEN  (24*3600)
#define  TMTC_DMSURL_VALID_LEN  (24*3600)

#define  CA_CERT_FILE "./tmp.crt"
#define  TMTC_DEVMNG_URL "sdt.cuopen.net"

class CHttpMsg
{
public:
    static CHttpMsg* GetInstance();

    ZVOID StartCall(string& calluri, string& calleduri, ZBOOL bAutoCfg);
    ZVOID StopCall();
    ZVOID UpdateCall();
    ZVOID RingCall(ZBOOL bTaking = ZFALSE);
    ZVOID ReportRegister(ZUCHAR aucType, ZBOOL bAutoCfg);
    ZBOOL UploadLogFile(ZCHAR *pcPath);

    ZBOOL GetValidServerUrl();
    ZBOOL UploadSDKState();
    ZBOOL DownLoadLicense();
private:
    ZVOID AddBody(string& strBody, const string& strKey, const string& strValue);
    ZBOOL PostRequest(const string& strUrl, const  string& strBody, ZBOOL bStartCall, ZUCHAR acType);
    ZBOOL GetRequest(const string& strUrl, ZUCHAR acType);

protected:
    static size_t WriteData(void* ptr, size_t size, size_t nmemb, void* stream);
public:
    ZVOID GetDevMngUrl(string &strUri)
    {
        m_periodMutex.lock();
        strUri = m_strDevMngUrl;
        m_periodMutex.unlock();
    }

    ZVOID GetDmsUrl(string &strUri)
    {
        m_periodMutex.lock();
        strUri = m_strDmsUrl;
        m_periodMutex.unlock();
    }
private:
    ZVOID Init();
    /**
     * @brief ParseDevMngResult
     * @param result http return json,
     * @param ucType see@ENUM_HTTP_PARSE_TYPE
     * @return
     */
    ZBOOL ParseDevMngResult(const std::string& result, ZUCHAR ucType);

    ZVOID UrlPeriodRun();
private:
    std::string m_uuid;
    std::string m_cid;
    std::string m_callPhone;
    std::string m_calledPhone;

    std::thread m_hUpdateThread;
    ZINT64 m_callStartTime;
    ZBOOL  m_stopUpdate;

    std::mutex m_mutex;
    std::condition_variable m_cond;

    std::string m_strDevMngUrl;
    ZUINT m_iDevValidTime;
    std::mutex m_periodMutex;
    std::thread m_hPeriodThread;

    std::string m_strDmsUrl;
    ZUINT m_iDmsValidTime;

private:
    CHttpMsg();
    ~CHttpMsg();

    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if (CHttpMsg::m_pHttpMng)
            {
                SAFE_DELETE_PTR(CHttpMsg::m_pHttpMng);
            }
        }
    };

    static CHttpMsg *m_pHttpMng;
    static CGarbo m_garbo;

};

