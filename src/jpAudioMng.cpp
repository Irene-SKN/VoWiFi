#include "jpAudioMng.h"
#include "jpsdk.h"

/* init static variable */
CJpAudioMng *CJpAudioMng::m_pAudioMng = nullptr;
CJpAudioMng::CGarbo CJpAudioMng::m_garbo;

CJpAudioMng::CJpAudioMng()
            :m_bUpAudioExits(ZFALSE),
             m_bDownThreadExits(ZFALSE)
{
    m_bPlayInit = ZFALSE;
    m_iAdpType = EN_INPUTSDK_OUTPUTSDK_TYPE;
}

CJpAudioMng::~CJpAudioMng()
{
    switch (m_iAdpType)
    {
        case EN_INPUTSDK_OUTPUTSDK_TYPE:
        {
            StopInputDevice();
            StopOutputDevice();
        }
        break;
        case EN_INPUTUSER_OUATPUTUSER:
        {
             UpThreadStop();
             StopOutputDevice();
        }
        case EN_INPUTUSER_OUTPUTSDK_TYPE:
        {
             UpThreadStop();
             DownThreadStop();
        }
        break;
        default:
            break;
    }
}

CJpAudioMng *CJpAudioMng::GetInstance()
{
    if (nullptr == m_pAudioMng)
    {
        static std::mutex myOSMutex;
        myOSMutex.lock();
        if (nullptr == m_pAudioMng)
        {
            m_pAudioMng = new CJpAudioMng;

            if (nullptr == m_pAudioMng)
            {

                myOSMutex.unlock();
                return NULL ;
            }
            m_pAudioMng->InitAudio();
            myOSMutex.unlock();
        }
    }

    return m_pAudioMng;
}

ZINT CJpAudioMng::InitAudio()
{
    ZINT iRet = ZOK;
    plog::init(plog::debug, "JpLog.txt", (1024*1024), 1);
    iRet = Zmf_AudioInitialize(0);
    return iRet;
}

ZINT CJpAudioMng::StartAudioAdp(ZINT iType)
{
    ZINT iRet = ZOK;
    m_iAdpType = iType;
    switch (m_iAdpType)
    {
        case EN_INPUTSDK_OUTPUTSDK_TYPE:
        {
            iRet |= OpenInputDevice();
            iRet |= OpenOutputDevice();
        }
        break;
        case EN_INPUTUSER_OUATPUTUSER:
        {
            // noting to do
            // if Taking will start Up Thread And Down Thread.
        }
        case EN_INPUTUSER_OUTPUTSDK_TYPE:
        {
            iRet |= OpenOutputDevice();

        }
        break;
        default:
            break;
    }

    return iRet;
}

ZINT CJpAudioMng::OpenInputDevice(ZUCHAR bAec /*= ZmfAecOn*/, ZUCHAR bAgc /*= ZmfAgcOff*/)
{
    ZCHAR cId[TMTC_DATA_LEN * 2], cDeviceName[TMTC_DATA_LEN * 2];
    ZINT  iRet = ZFAILED;
    string strTmp;

    for (ZINT i = 0;i < Zmf_AudioInputGetCount(); i++)
    {
        Zmf_AudioInputGetName(i, cId, cDeviceName);
        strTmp.clear();
        strTmp = string("Input[") + to_string(i) + "]cId[" + string(cId)
                 + string("]cDevName[") + string(cDeviceName) + string("]");

        CCommFunc::PrintInTermiate(EN_PRINT_GREEN, strTmp);
        LOGI << strTmp;

        if (0 == i)
            iRet = Zmf_AudioInputStart(cId, TMTC_RATE_HZ, TMTC_MIC_CHANNLES, (ZmfAecMode)bAec, (ZmfAgcMode)bAgc);
     }

   return iRet;
}

ZINT CJpAudioMng::OpenOutputDevice()
{
    ZCHAR cId[TMTC_DATA_LEN * 2], cDeviceName[TMTC_DATA_LEN * 2];
    ZINT  iRet = ZFAILED;
    string strTmp;

    for (ZINT i = 0; i < Zmf_AudioOutputGetCount(); i++)
    {
        Zmf_AudioOutputGetName(i, cId, cDeviceName);
        strTmp.clear();
        strTmp = string("Output[") + to_string(i) + "]cId[" + string(cId)
                 + string("]cDevName[") + string(cDeviceName) + string("]");

        CCommFunc::PrintInTermiate(EN_PRINT_GREEN, strTmp);
        LOGI << strTmp;

        if (0 == i)
        {
            iRet = Zmf_AudioOutputStart(cId, TMTC_RATE_HZ, TMTC_MIC_CHANNLES);
        }
    }

    return iRet;
}

ZINT CJpAudioMng::StopInputDevice()
{
    return Zmf_AudioInputStopAll();
}


ZINT CJpAudioMng::StopOutputDevice()
{
    return Zmf_AudioOutputStopAll();
}

ZINT  CJpAudioMng::DecodeIncomingUrl(const string& strUrl)
{
    if (!strUrl.length())
        return ZFAILED;

    string strTmp;
    // upper report this number
    cout << "incoming phone[ " << strUrl.c_str() << "]" << endl;

    strTmp += "incoming phone[";
    strTmp += strUrl;
    strTmp += "]";

    CCommFunc::PrintInTermiate(EN_PRINT_WHITE, strTmp);
    LOGI << strTmp;

    return ZOK;
}

ZVOID CJpAudioMng::StartZeroAudioInput()
{
      ZUCHAR ucTmpChr[2] = {0};
      Zmf_OnAudioInput("?", TMTC_RATE_HZ, TMTC_MIC_CHANNLES, ucTmpChr, 2, 0, 0, 0, 0);
}

ZVOID CJpAudioMng::StartUpThread()
{
    if (m_hUpAudioThread.joinable()) m_hUpAudioThread.join();

    m_bUpAudioExits = ZFALSE;
    m_hUpAudioThread = std::thread(std::bind(&CJpAudioMng::UpThreadRun, this));
}

ZVOID CJpAudioMng::UpThreadRun()
{
   FILE* fp = fopen("./test_eng_female.pcm", "r");
   ZINT iMaxSampleBufSize = TMTC_RATE_HZ * TMTC_SLEEP_TIME / 1000 * 2 * 10;
   ZUINT iLastAudioSampleTime = CCommFunc::getCurrentUnixTime();

   ZCHAR *pcBuffer = new char[iMaxSampleBufSize];
   while(!m_bUpAudioExits)
   {
       ZUINT iNowAudioSample = CCommFunc::getCurrentUnixTime();
       ZUINT iTimeInterval = iNowAudioSample - iLastAudioSampleTime;
       ZINT iCount = TMTC_RATE_HZ * iTimeInterval /1000 * 2;

       if (iCount > iMaxSampleBufSize) iCount = iMaxSampleBufSize;

       if (CJpSdkMng::GetInstance()->GetTakingStatus())
       {
            if (fp)
            {
                fread(pcBuffer, iMaxSampleBufSize, 1, fp);
                Zmf_OnAudioInput("?", TMTC_RATE_HZ, TMTC_SPK_CHANNLES, (unsigned char *)pcBuffer, iMaxSampleBufSize, 0, 0, 0, 0);
            }
       }

       usleep(TMTC_SLEEP_TIME * 1000);
    }

    if (fp) fclose(fp);
    delete[] pcBuffer;
}

ZVOID CJpAudioMng::UpThreadStop()
{
   m_bUpAudioExits = ZTRUE;

   if (m_hUpAudioThread.joinable()) m_hUpAudioThread.join();
}

ZVOID CJpAudioMng::StartDownThread()
{
    if (m_hDownAudioThread.joinable()) m_hDownAudioThread.join();

    m_hDownAudioThread = std::thread(std::bind(&CJpAudioMng::DownThreadRun, this));
}

ZVOID CJpAudioMng::DownThreadRun()
{
#if((defined TMTC_INTUSER_OUTUSER) ||  (defined TMTC_INTSDK_OUTUSER))
    string strTmp;
    ZINT ierror;
    while (!m_bDownThreadExits)
    {
        std::unique_lock<std::mutex> lck(m_mxDown);
        m_cvDown.wait(lck);

        while (CJpSdkMng::GetInstance()->GetTakingStatus())
        {
            if (!TCHECK_ISEMPTY_STR(m_pcOutBuf))
                Zmf_OnAudioOutput("?", TMTC_RATE_HZ, TMTC_SPK_CHANNLES, m_pcOutBuf, m_iOutLen);

            if (m_pstPaSim)
            {
                if (pa_simple_write(m_pstPaSim, m_pcOutBuf, m_iOutLen, &ierror) < 0)
                {
                    // print error to your log file

                    strTmp.clear();
                    strTmp = "pa_simple_write failed errcoe[" + string(pa_strerror(ierror)) + "]iLen["
                            + to_string(m_iOutLen) + "]";
                    LOGE << strTmp;
                }
                else
                {
                    strTmp.clear();
                    strTmp = "Get Pcm Data Len[" + to_string(m_iOutLen) + "]";
                }
            }

            usleep(TMTC_SLEEP_TIME * 1000);
        }
    }
#endif
}


ZINT CJpAudioMng::DownThreadInit()
{
#if((defined TMTC_INTUSER_OUTUSER) ||  (defined TMTC_INTSDK_OUTUSER))
   string strTmp;
   if(m_bPlayInit)
      return ZFAILED;

    m_bPlayInit = ZTRUE;

    if (m_pstPaSim)
    {
        pa_simple_free(m_pstPaSim);
        m_pstPaSim = nullptr;
    }

    ZINT ierror;
    m_stPa_spec.format = PA_SAMPLE_S16LE;
    m_stPa_spec.rate = TMTC_RATE_HZ;
    m_stPa_spec.channels = TMTC_SPK_CHANNLES;

    m_pstPaSim = pa_simple_new(NULL, "ttsplayer", PA_STREAM_PLAYBACK, NULL,
                      "tts", &m_stPa_spec, NULL, NULL, &ierror);

    if (!m_pstPaSim)
    {
        strTmp.clear();
        strTmp = "pa_simple_new errcoe[" + string(pa_strerror(ierror)) + "]";
        LOGE << strTmp;
        return ZFAILED;
    }


    m_iOutLen = TMTC_RATE_HZ * TMTC_SLEEP_TIME/1000  * TMTC_SPK_CHANNLES * 2;

    if(!m_pcOutBuf)
        m_pcOutBuf = new unsigned char[m_iOutLen];
#endif
    return ZOK;

}

ZINT CJpAudioMng::DownThreadDestory()
{
#if((defined TMTC_INTUSER_OUTUSER) ||  (defined TMTC_INTSDK_OUTUSER))
    ZINT ierror;
    string strTmp;
    if (m_pstPaSim != ZNULL)
    {
      pa_simple_flush(m_pstPaSim, &ierror);
      ierror = 0;
      // Make sure that every single sample was played
      if (pa_simple_drain(m_pstPaSim, &ierror) < 0)
      {
          strTmp.clear();
          strTmp = "pa_simple_drain errcoe[" + string(pa_strerror(ierror)) + "]";
          LOGE << strTmp;
      }

      pa_simple_free(m_pstPaSim);
      m_pstPaSim = ZNULL;
    }

    if (m_pcOutBuf)
    {
        delete []m_pcOutBuf;
        m_pcOutBuf = ZNULL;
    }
    m_bPlayInit = ZFALSE;
    m_iOutLen = 0;

#endif
   return ZOK;
}

ZVOID CJpAudioMng::DownThreadStop()
{
    m_bDownThreadExits = ZTRUE;

    if (m_hDownAudioThread.joinable()) m_hDownAudioThread.join();
}
