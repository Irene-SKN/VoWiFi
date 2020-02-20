#include "httpmsg.h"
#include "stdio.h"

CHttpMsg *CHttpMsg::m_pHttpMng = nullptr;
CHttpMsg::CGarbo CHttpMsg::m_garbo;

CHttpMsg::CHttpMsg()
        : m_callStartTime(0),
          m_stopUpdate(ZTRUE)
{
    m_iDevValidTime = TMTC_DEVURL_VALID_LEN;
    m_iDmsValidTime = TMTC_DMSURL_VALID_LEN;

    m_strDevMngUrl = strDevURL;
    m_strDmsUrl = strDmsURL;
}

CHttpMsg::~CHttpMsg()
{
    curl_global_cleanup();

    if (m_hUpdateThread.joinable())
        m_hUpdateThread.join();

    if (m_hPeriodThread.joinable())
        m_hPeriodThread.join();
}

CHttpMsg* CHttpMsg::GetInstance()
{
    if (nullptr == m_pHttpMng)
    {
        static std::mutex myOSMutex;
        myOSMutex.lock();
        if (nullptr == m_pHttpMng)
        {
            m_pHttpMng = new CHttpMsg;

            if (nullptr == m_pHttpMng)
            {
                myOSMutex.unlock();
                return nullptr;
            }
            m_pHttpMng->Init();
            myOSMutex.unlock();
        }
    }

    return m_pHttpMng;
}

ZVOID CHttpMsg::Init()
{
      curl_global_init(CURL_GLOBAL_ALL);
}

size_t CHttpMsg::WriteData(void* ptr, size_t size, size_t nmemb, void* stream)
{
    std::string data((const char *)ptr, (size_t)size * nmemb);
    std::string* str = (std::string*)stream;
    str->append(data);
    return size * nmemb;
}

ZBOOL CHttpMsg::PostRequest(const string& strUrl, const string& strBody, ZBOOL bStartCall, ZUCHAR acType)
{
    auto pCurl = curl_easy_init();
    if (nullptr != pCurl)
    {
        string out, strTmp;

        // use post request
        curl_easy_setopt(pCurl, CURLOPT_POST, ZTRUE);
        curl_easy_setopt(pCurl, CURLOPT_CONNECTTIMEOUT, TMTC_TIMEOUT_LEN);
        curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, TMTC_TIMEOUT_LEN);
        curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, CHttpMsg::WriteData);
        curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &out);
        curl_easy_setopt(pCurl, CURLOPT_URL, strUrl.c_str());
        curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1);
#if(defined TMTC_SSL_TRANSPORT)
        curl_easy_setopt(pCurl, CURLOPT_SSLVERSION,1);
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, ZTRUE);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, ZFALSE);
        curl_easy_setopt(pCurl, CURLOPT_CAINFO, CA_CERT_FILE);
#else
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, ZFALSE);
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYHOST, ZFALSE);
#endif
        curl_slist *pHeaderList = curl_slist_append(nullptr, "Content-Type: application/x-www-form-urlencoded");
        curl_slist_append(nullptr, "Accept: */*");

        if (bStartCall)
            curl_slist_append(pHeaderList, "Cookie: SECURITY_CODE=31598a23a087b37a28ad82d449a30206");
#if(defined TMTC_DOMAIN_TEST)
        strTmp = string("HOST:") + string(GetDevMngUrl());
#else
        strTmp = string("HOST:") + TMTC_REMOTE_ADDR;
#endif
        curl_slist_append(pHeaderList, strTmp.c_str());
        curl_slist_append(pHeaderList, "Content-Type: application/x-www-form-urlencoded");
        auto lengthHeader = std::string("Content-Length: ") + std::to_string(strBody.length());
        curl_slist_append(pHeaderList, lengthHeader.c_str());
        curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, pHeaderList);
        curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, strBody.c_str());

        auto res = curl_easy_perform(pCurl);

        if (pHeaderList)
        {
            curl_slist_free_all(pHeaderList);
            pHeaderList = nullptr;
        }

        if (res != CURLE_OK)
        {
            curl_easy_cleanup(pCurl);
            return ZFALSE;
        }
        else
        {
            curl_easy_cleanup(pCurl);
            return  ParseDevMngResult(out, acType);
        }
    }

    return ZTRUE;
}

ZBOOL CHttpMsg::PostRequest2(const string& strUrl, const  string& strPath, ZUCHAR acType)
{
    auto pCurl = curl_easy_init();
    if (nullptr != pCurl)
    {
        string out, strTmp;

        // use post request
        curl_easy_setopt(pCurl, CURLOPT_POST, ZTRUE);
        curl_easy_setopt(pCurl, CURLOPT_CONNECTTIMEOUT, TMTC_TIMEOUT_LEN);
        curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, TMTC_TIMEOUT_LEN);
        curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, CHttpMsg::WriteData);
        curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &out);
        curl_easy_setopt(pCurl, CURLOPT_URL, strUrl.c_str());
        curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1);
        curl_easy_setopt(pCurl, CURLOPT_USERAGENT, "PostmanRuntime/7.22.0");

#if(defined TMTC_SSL_TRANSPORT)
        curl_easy_setopt(pCurl, CURLOPT_SSLVERSION,1);
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, ZTRUE);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, ZFALSE);
        curl_easy_setopt(pCurl, CURLOPT_CAINFO, CA_CERT_FILE);
#else
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, ZFALSE);
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYHOST, ZFALSE);
#endif
        curl_slist *pHeaderList = curl_slist_append(nullptr, "Content-Type: multipart/form-data; boundary=--------------------------851916056824645127042149");
        curl_slist_append(nullptr, "Accept: */*");
        curl_slist_append(pHeaderList, "cache-control: no-cache");

#if(defined TMTC_DOMAIN_TEST)
        strTmp = string("HOST:") + string(GetDevMngUrl());
#else
        strTmp = string("HOST:") + TMTC_REMOTE_ADDR;
#endif
        curl_slist_append(pHeaderList, strTmp.c_str());
        curl_slist_append(pHeaderList, "Content-Type: multipart/form-data; boundary=--------------------------851916056824645127042149");
        curl_slist_append(pHeaderList, "Accept-Encoding: gzip, deflate, br");
        curl_slist_append(pHeaderList, "Connection: Keep-Alive");

        curl_httppost* pFormPost = nullptr;
        curl_httppost* pLastElem = nullptr;
        curl_formadd(&pFormPost,  &pLastElem,
                     CURLFORM_COPYNAME, "accountInfo",
                     CURLFORM_COPYCONTENTS, "",
                     CURLFORM_END);

        curl_formadd(&pFormPost, &pLastElem,
                     CURLFORM_COPYNAME, "deviceInfo",
                     CURLFORM_COPYCONTENTS, "linux",
                     CURLFORM_END);

        curl_formadd(&pFormPost, &pLastElem,
                     CURLFORM_COPYNAME, "reason",
                     CURLFORM_COPYCONTENTS, "1",
                     CURLFORM_END);

        curl_formadd(&pFormPost, &pLastElem,
                     CURLFORM_COPYNAME, "appKey",
                     CURLFORM_COPYCONTENTS, "9714fb198263857cf2241cb108fc7da5",
                     CURLFORM_END);
        curl_formadd(&pFormPost, &pLastElem,
                    CURLFORM_CONTENTTYPE, "multipart/form-data",
                    CURLFORM_END);

        curl_formadd(&pFormPost, &pLastElem, CURLFORM_COPYNAME, "file", CURLFORM_FILE, strPath.c_str(), CURLFORM_CONTENTTYPE, "text/plain", CURLFORM_END);
        curl_formadd(&pFormPost, &pLastElem, CURLFORM_COPYNAME, "end", CURLFORM_COPYCONTENTS, "end", CURLFORM_END);
        curl_easy_setopt(pCurl, CURLOPT_HTTPPOST, pFormPost);
        curl_easy_setopt(pCurl, CURLOPT_URL, strUrl.c_str());

        auto res = curl_easy_perform(pCurl);

        if (res != CURLE_OK)
        {
            curl_easy_cleanup(pCurl);
            return ZFALSE;
        }
        else
        {
            curl_easy_cleanup(pCurl);
            return  ParseDevMngResult(out, acType);
        }
    }

    return ZTRUE;
}


ZBOOL CHttpMsg::GetRequest(const string& strUrl, ZUCHAR acType)
{
    CURL *pCurl = curl_easy_init();

    if (pCurl != nullptr)
    {
        std::string out;
        curl_easy_setopt(pCurl, CURLOPT_URL, strUrl.c_str());
#if(defined TMTC_SSL_TRANSPORT)
        curl_easy_setopt(pCurl,CURLOPT_SSLVERSION, 1);
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, ZTRUE);
        curl_easy_setopt(pCurl, CURLOPT_CAINFO, CA_CERT_FILE);
#else
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, ZFALSE);
        curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYHOST, ZFALSE);
#endif
        curl_easy_setopt(pCurl, CURLOPT_CONNECTTIMEOUT, TMTC_TIMEOUT_LEN);
        curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, TMTC_TIMEOUT_LEN);
        curl_easy_setopt(pCurl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, CHttpMsg::WriteData);
        curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &out);
        curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1);
        auto res = curl_easy_perform(pCurl);

        if (res != CURLE_OK)
        {
            curl_easy_cleanup(pCurl);
            return ZFALSE;
        }
        else
        {
            curl_easy_cleanup(pCurl);
            return ParseDevMngResult(out, acType);
        }
    }

    return ZFALSE;
}

ZVOID CHttpMsg::StartCall(string& calluri, string& calleduri, ZBOOL bAutoCfg)
{
    ZUINT iPort;
    m_callPhone = calluri;
    m_calledPhone = calleduri;
    m_callStartTime = CCommFunc::getCurrentUnixTime();

    string strBody, strTmp;
    CCommFunc::ObtainCurTime(time(0), strTmp);

    AddBody(strBody, "clientVendor", Mtc_ProvDbGetCliVendor());
    AddBody(strBody, "clientVersion", Mtc_ProvDbGetCliVer());
    AddBody(strBody, "terminalModel", Mtc_ProvDbGetTmnlModel());
    AddBody(strBody, "terminalSwVersion", Mtc_ProvDbGetTmnlSwVer());

    if (bAutoCfg)
        AddBody(strBody, "terminalVendor",  Mtc_ProvDbGetTmnlVendor());
    else
        AddBody(strBody, "terminalVendor",  "baidu");

    AddBody(strBody, "startTime", strTmp);
    AddBody(strBody, "callType", "voiceCall");
    AddBody(strBody, "callDomain", std::string(Mtc_CliDbGetSipRegIp()));
    // upper modifty Actual Vendor Name,
    switch (Mtc_CliDbGetSipRegTpt())
    {
       case EN_MTC_TPT_UDP:
           iPort = Mtc_CliDbGetSipRegUdpPort();
           break;
       case EN_MTC_TPT_TCP:
           iPort = Mtc_CliDbGetSipRegTcpPort();
           break;
       case EN_MTC_TPT_TLS:
           iPort = Mtc_CliDbGetSipRegTlsPort();
           break;
       default:
           break;
     }
    AddBody(strBody, "callDomainPort", std::to_string(iPort));
    AddBody(strBody, "callPhone", m_callPhone);
    AddBody(strBody, "calledPhone", m_calledPhone);

    LOGI << "StartCall:" << strBody;
    PostRequest(TMTC_START_CALL_URL, strBody, ZTRUE, ENUM_HTTP_PARSE_STARTCALL);

    if (m_hUpdateThread.joinable())
        m_hUpdateThread.join();

    m_stopUpdate = ZFALSE;
    m_hUpdateThread = std::thread(std::bind(&CHttpMsg::UpdateCall, this));
}

ZVOID CHttpMsg::StopCall()
{
    string strBody, strTmp;
    m_stopUpdate = ZTRUE;
    m_cond.notify_one();
    ZINT64 stopTime = CCommFunc::getCurrentUnixTime();

    CCommFunc::ObtainCurTime(time(0), strTmp);
    AddBody(strBody, "endTime", strTmp);
    AddBody(strBody, "uuid", m_uuid);
    AddBody(strBody, "cId", m_cid);
    AddBody(strBody, "callStatus", "1");
    AddBody(strBody, "callDuration", std::to_string((long)difftime(stopTime, m_callStartTime)));
    AddBody(strBody, "callPhone", m_callPhone);
    AddBody(strBody, "calledPhone", m_calledPhone);

    PostRequest(TMTC_STOP_CALL_URL, strBody, ZFALSE, ENUM_HTTP_PARSE_STARTCALL);
}

ZVOID CHttpMsg::UpdateCall()
{
    while (!m_stopUpdate)
    {
        ZINT64 updateTime = CCommFunc::getCurrentUnixTime();
        std::string body;
        AddBody(body, "callPhone", m_callPhone);
        AddBody(body, "calledPhone", m_calledPhone);
        AddBody(body, "callDuration", std::to_string((long) difftime(updateTime, m_callStartTime)));
        AddBody(body, "cId", m_cid);

        PostRequest(TMTC_UPDATE_CALL_URL, body, ZFALSE, ENUM_HTTP_PARSE_STARTCALL);

        std::unique_lock<std::mutex> lock(m_mutex);
        m_cond.wait_for(lock, std::chrono::seconds{60});
    }
}

ZVOID CHttpMsg::ReportRegister(ZUCHAR aucType, ZBOOL bAutoCfg)
{
#if 0
    string strMac, strSign, strTmp;
    string strBody;

    CCommFunc::GetLocalMac(strMac);

    AddBody(strBody, "RPCMethod", "IntelDevSyn");
    AddBody(strBody, "VER", "01");
    AddBody(strBody, "CUEI", pcCuei);
    // upper Device=>Actual Router MAC Address,if not ,set empty ""
    AddBody(strBody, "MAC", strMac);
    AddBody(strBody, "IP", Mtc_GetLclIp(0));
    // 1=> NetWork access via  wolink   2 => Not through wolink
    AddBody(strBody, "LINK", "1");
    // report current fireware version number
    AddBody(strBody, "FWVER", "11.2.5(15D55)");
    CCommFunc::ObtainCurTime(time(0), strTmp);
    AddBody(strBody, "DATE", strTmp);

    CCommFunc::GetInitSign(pcCuei, strMac, Mtc_GetLclIp(0), strSign);
    AddBody(strBody, "SIGN", strSign);
    AddBody(strBody, "UPLINKMAC", "");

    PostRequest(TMTC_REGISTER_URL, strBody, ZFALSE, ENUM_HTTP_PARSE_REGISTER);
#endif

    string strTmp, strBody;
    // dataTye = 0; =>register/unregister type
    AddBody(strBody, "dataType", "0");
    // UserType = 0 ; =>voice box;
    if (ENUM_HTTP_PARSE_REGISTER == aucType)
       strTmp = "1";
    else
       strTmp = "0";

    AddBody(strBody, "userType", "0");
    AddBody(strBody, "ip", Mtc_GetLclIp(0));
    AddBody(strBody, "operationType", strTmp);
    if (bAutoCfg)
        AddBody(strBody, "device", Mtc_ProvDbGetImei());
    else
        AddBody(strBody, "device", "200012040000045");

    strTmp.clear();
    CCommFunc::ObtainCurTime(time(0), strTmp);
    AddBody(strBody, "time", strTmp);

    // Post(TMTC_REGISTER_URL, strBody, aucType);
    LOGI << "ReportRegister:" << strBody;
    PostRequest(TMTC_REGISTER_URL, strBody, ZFALSE, aucType);
}

ZVOID CHttpMsg::AddBody(string& strBody, const string& strKey, const string& strValue)
{
    if (!strBody.empty())
        strBody += "&";

    strBody = strBody + strKey + "=" + strValue;
}

ZBOOL CHttpMsg::ParseDevMngResult(const std::string& result, ZUCHAR ucType)
{
    rapidjson::Document document;
    string strTmp;
    ZBOOL bRet = ZFALSE;
    cout << "ParseDeMngResult result:" << result << endl;
    LOGI <<"ParseDeMngResult result:" << result;

    document.Parse<0>(result.c_str());
    if (document.HasParseError())
        return ZFALSE;

    switch(ucType)
    {
        case ENUM_HTTP_PARSE_SDK_STATE:
        {
            if (document.HasMember("result") && document.HasMember("message"))
            {
                ZINT iRetCode = document["result"].GetInt();
                string strCode = document["message"].GetString();
                if (0 == iRetCode && 0 == strCode.compare("success"))
                {
                     LOGI << "Get SDK State return Success" ;
                     bRet = ZTRUE;
                }
            }
        }
        break;

        case ENUM_HTTP_PARSE_VALIDURL:
        {
            if (document.HasMember("result"))
            {
                if (0 == document["result"].GetInt())
                {
                   bRet = ZFALSE;
                   break;
                }

                if (document.HasMember("data"))
                {
                    m_periodMutex.lock();
                    string strDevMngUrl =  document["data"]["sdkPlatformServerUrl"].GetString();
                    if ( 0 != strDevMngUrl.compare(m_strDevMngUrl))
                        m_strDevMngUrl = strDevMngUrl;

                    m_iDevValidTime = document["data"]["sdkPlatformServerUrlValidDate"].GetInt();

                    string strDmsUrl= document["data"]["dmsServerUrl"].GetString();
                    if ( 0 != strDmsUrl.compare(m_strDmsUrl))
                        m_strDmsUrl  = strDmsUrl;

                    m_iDmsValidTime = document["data"]["dmsServerUrlValidDate"].GetInt();
                    m_periodMutex.unlock();

                    if (m_hPeriodThread.joinable())
                    {
                        bRet = ZFALSE;
                        m_hPeriodThread.join();
                    }

                    m_hPeriodThread = std::thread(std::bind(&CHttpMsg::UrlPeriodRun, this));
                }

                bRet = ZTRUE;
            }
        }
        break;

        case ENUM_HTTP_PARSE_REGISTER:
        case ENUM_HTTP_PARSE_UNREGISTER:
        {
            if (document.HasMember("result"))
            {
                strTmp.clear();
                strTmp = document["result"].GetString();
                if (0 == strTmp.compare("ok"))
                    bRet = ZTRUE;
            }
        }
        break;

        case ENUM_HTTP_PARSE_STARTCALL:
        {
            if (document.HasMember("value"))
            {
                if (document["value"].HasMember("uuid") && document["value"].HasMember("cid"))
                {
                    m_uuid = document["value"]["uuid"].GetString();
                    m_cid = document["value"]["cid"].GetString();
                    bRet = ZTRUE;
                }
            }
        }
        break;

        case ENUM_HTTP_UPLOAD_LOG:
        {
            if (document.HasMember("ret") && document.HasMember("msg") && document.HasMember("data"))
            {
                strTmp.clear();
                strTmp = document["msg"].GetString();
                if ( 0 == document["ret"].GetInt() && 0 == strTmp.compare("ok"))
                {
                    // nothing todo
                }

            }
        }
        break;

        case ENUM_HTTP_RING_CALL:
        {
            if (document.HasMember("result") && document.HasMember("value"))
            {
               strTmp.clear();
               strTmp = document["result"].GetString();
               if (0 == strTmp.compare("ok"))
               {
                   // nothing todo
               }

            }

        }
        break;

       case ENUM_HTTP_RING_UPDATECALL:
       {
            if (document.HasMember("result") && document.HasMember("value"))
            {
               strTmp.clear();
               strTmp = document["result"].GetString();
               if (0 == strTmp.compare("ok"))
               {
                   // nothing todo
               }

            }
       }
       break;

       case ENUM_HTTP_RING_CALL_STOPCALL:
       {
            if (document.HasMember("result") && document.HasMember("value"))
            {
               strTmp.clear();
               strTmp = document["result"].GetString();
               if (0 == strTmp.compare("ok"))
               {
                   // nothing todo
               }

            }
       }
       break;

       case ENUM_HTTP_DOWNLICENSE:
       {
            if (document.HasMember("result"))
            {
                // nothing todo
               strTmp.clear();
               strTmp = document["result"].GetString();
               if (0 == strTmp.compare("ok"))
               {
                   bRet = ZTRUE;
               }
            }
       }
       break;
    }

    return bRet;
}

ZBOOL CHttpMsg::GetValidServerUrl()
{
   string strUrl, strTmp;
   strTmp = Mtc_GetVersion();
   ZINT iPos = strTmp.find("(");
   ZINT iPos2 = strTmp.find_last_of(")");

   string strTmp2 = strTmp.substr(iPos + 1, iPos2 - iPos - 1);
  // strUrl = TMTC_VALIDSERVAL_URL + "&&sdkVersion=" + strTmp2;
   strUrl = TMTC_VALIDSERVAL_URL + "&&sdkVersion=" + string("1.0.0");
   LOGI << "GetValidServerUrl:" << strUrl;
   return GetRequest(strUrl, ENUM_HTTP_PARSE_VALIDURL);
}

ZBOOL CHttpMsg::UploadSDKState()
{
    string strUrl, strTmp;
    strTmp = Mtc_GetVersion();
    ZINT iPos = strTmp.find("(");
    ZINT iPos2 = strTmp.find_last_of(")");

    string strTmp2 = strTmp.substr(iPos + 1, iPos2 - iPos - 1);
//    strUrl = TMTC_UPLOADSDKSTATE + string("&&bundleId=") + TMTC_SDK_APPID
//             + "&&version=" + strTmp2;

    strUrl = TMTC_UPLOADSDKSTATE + string("&&bundleId=") + TMTC_SDK_APPID
             + "&&version=" + string("1.0.0");

    cout << "UplaodSDKStatae:" << endl;
    cout << strUrl << endl;
    LOGI << "UploadSDKState:" << strUrl;
    return GetRequest(strUrl, ENUM_HTTP_PARSE_SDK_STATE);
}

ZVOID CHttpMsg::UrlPeriodRun()
{
    while(ZTRUE)
    {
        ZUINT iSleepTime = (m_iDevValidTime >= m_iDmsValidTime) ? m_iDmsValidTime : m_iDevValidTime;
        std::this_thread::sleep_for(chrono::seconds(iSleepTime * 3600));
        GetValidServerUrl();
    }
}

ZBOOL CHttpMsg::UploadLogFile(ZCHAR *pcPath)
{
   return PostRequest2(TMTC_UPLOADLOG_URL, pcPath, ENUM_HTTP_UPLOAD_LOG);
}

ZVOID CHttpMsg::RingCall(ZBOOL bTaking /*= ZFALSE */)
{
    string strBody, strTmp;
    AddBody(strBody, "uuid", m_uuid);
    AddBody(strBody, "type", bTaking ? "1" :"0");
    CCommFunc::ObtainCurTime(time(0), strTmp);
    AddBody(strBody, "startTime", strTmp);
    PostRequest(TMTC_RINGTIME_URL, strBody, ZFALSE, ENUM_HTTP_RING_CALL);
}

ZBOOL CHttpMsg::DownLoadLicense()
{
    // string strUrl = TMTC_LICENSE_URL + "31598a23a087b37a28ad82d449a30206" + "&device="  + TMTC_SDK_APPID;
    string strUrl = TMTC_LICENSE_URL + "31598a23a087b37a28ad82d449a30206" + "&device="  + "unicom-32arm-baidu";
    return GetRequest(strUrl, ENUM_HTTP_DOWNLICENSE);
}

