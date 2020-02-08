#pragma once

/* user define header file */
#include "commdatadef.h"

class CJpAudioMng
{
public:
    static CJpAudioMng *GetInstance();
    ZINT  InitAudio();
    ZINT  DecodeIncomingUrl(const string& strUrl);
    ZINT  StartAudioAdp(ZINT iType);

    ZVOID StartZeroAudioInput();
    ZVOID StartUpThread();
    ZVOID StartDownThread();

    ZVOID UpThreadStop();
    ZVOID DownThreadStop();
public:
    ZBOOL GetIsUseControlUp()
    {
       return (m_iAdpType == EN_INPUTUSER_OUATPUTUSER ||
               m_iAdpType == EN_INPUTUSER_OUTPUTSDK_TYPE);
    }

    ZVOID NotifyOne()
    {
        m_cvDown.notify_one();
    }

private:
    ZINT OpenInputDevice(ZUCHAR bAec = ZmfAecOn, ZUCHAR bAgc = ZmfAgcOff);
    ZINT OpenOutputDevice();
    ZINT StopInputDevice();
    ZINT StopOutputDevice();

    ZVOID UpThreadRun();
    ZVOID DownThreadRun();
    ZINT  DownThreadInit();
    ZINT  DownThreadDestory();
private:
    CJpAudioMng();
    ~CJpAudioMng();

    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if (CJpAudioMng::m_pAudioMng)
            {
                SAFE_DELETE_PTR(CJpAudioMng::m_pAudioMng);
            }
        }
    };

    static CJpAudioMng *m_pAudioMng;
    static CGarbo m_garbo;

    std::thread m_hUpAudioThread;
    ZBOOL m_bUpAudioExits;

    std::thread m_hDownAudioThread;
    ZBOOL m_bDownThreadExits;

    /** @biref play thread condition variable */
    std::condition_variable m_cvDown;

    /** @biref play thread  mutex variable */
    std::mutex m_mxDown;
#if((defined TMTC_INTUSER_OUTUSER) ||  (defined TMTC_INTSDK_OUTUSER))
    /** @biref opaque  connection object */
    pa_simple* m_pstPaSim;
    pa_sample_spec m_stPa_spec;

    /** @biref out pcm data */
    ZUCHAR *m_pcOutBuf;
    ZUINT  m_iOutLen;
#endif
    /** @brief whether is initialize or not */
    ZBOOL m_bPlayInit;

    ZINT  m_iAdpType;
};


