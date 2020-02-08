#pragma once

/* system header file */
#include <condition_variable>
#include <functional>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <atomic>
#include <list>
#include <map>
using namespace std;

/* linux define header file */
#include <signal.h>
#include <sys/stat.h>
#include <execinfo.h>

/* upper control pcm data */
#if((defined TMTC_INTUSER_OUTUSER) ||  (defined TMTC_INTSDK_OUTUSER))
#include <alsa/asoundlib.h>
#include <pulse/simple.h>
#include <pulse/error.h>
#include <condition_variable>
#endif

/* sdk header file */
#define  ZPLATFORM ZPLATFORM_LINUX
#include "os/linux/zplin_osenv.h"
#include "zos_osenv.h"
#include "mtc.h"
#include "zmf.h"
#include "zjson.h"
#include "zmd5.h"

/* user define header file */
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "curl/curl.h"
#include "commFunc.h"
#include "plog/Log.h"

/* user define common data length */
#define  TMTC_INVALID_CALLID    ZMAXUINT  /**< @brief Invalid call Id */
#define  TMTC_LOG_HEAD_STR      "Juphoon" /**< @brief Mtc log header flag */
#define  TMTC_DATA_LEN          256       /**< @brief General data length */
#define  TMTC_RTPBREAKT_LEN     30        /**< @brief rtp break time  */
#define  TMTC__IP_LEN           128       /**< @brief remote Ip Address */
#define  TMTC_PWD_LEN           16        /**< @brief password number */
#define  TMTC_USERNUM_LEN       16        /**< @brief userName number */
#define  TMTC_DOMAIN_LEN        32        /**< @brief remote server domain */
#define  TMTC_REG_EXPIRE_LEN    600       /**< @brief register min expire time */
#define  TMTC_CP_VENDOR_LEN     16        /**< @brief terminal vendor name length */
#define  TMTC_RETRYLOGIN_NUM    2         /**< @brief auto retry number */
#define  TMTC_MACADDR_LEN       32        /**< @brief MAC Adder Length */
#define  TMTC_MAX_SIGN_LEN      100       /**< @brief SIGN Length */
#define  TMTC_MAX_MD5_LEN       32        /**< @brief Upper Md5 Length */

/* data formula */
#define  TMTC_RATE_HZ        16000        /**< @brief default Audio rate Hz */
#define  TMTC_MIC_CHANNLES   1            /**< @brief default Audio mic Channels */
#define  TMTC_SPK_CHANNLES   2            /**< @brief default Audio Speaker Channles */
#define  TMTC_SOUND_HZ       3000         /**< @brief default Audio Sound Hz */
#define  TMTC_SLEEP_TIME     10           /**< @brief default Audio Sleep Time */
#define  TMTC_READAUDIO_DATA 2048;        /**< @brief file test Read length */

/* user define configure path */
#ifdef   TMTC_SUPT_ARM_PATH
#define  TMTC_LICENSE_PATH "/home/heyappluase/project/VOIP/testDemo/res/license.sign" /**< @brief set license  path */
#define  TMTC_INIT_PROFILE "/home/heyappluase/project/VOIP/testDemo"            /**< @brief set profile file path */
#define  TMTC_LOGFILE_DIR  "/home/heyappluase/project/VOIP/testDemo/log"        /**< @brief set log file path */
#define  TMTC_RING_DIR     "/home/heyappluase/project/VOIP/testDemo/ring"      /**< @brief set ring file  */
#define  TMTC_TEST_INT     "/home/heyappluase/project/VOIP/testDemo/test.ini"  /**< @brief upper user  config file path */
#else
#define  TMTC_LICENSE_PATH "license.sign" /**< @brief set SDK license  path */
#define  TMTC_INIT_PROFILE "profile"      /**< @brief set SDK profile file path */
#define  TMTC_LOGFILE_DIR  "JuphoonLog"   /**< @brief set SDK log file path */
#define  TMTC_RING_DIR     "ring"         /**< @brief set SDK ring file  */
#define  TMTC_TEST_INT     "test.ini"     /**< @brief upper user test config file path */
#endif

/** @brief File permissions type */
#define ZFILE_URD         0x0001     /**< @brief User can read */
#define ZFILE_UWR         0x0002     /**< @brief User can write */
#define ZFILE_UEXE        0x0004     /**< @brief User can execute */
#define ZFILE_GRD         0x0010     /**< @brief Group can read */
#define ZFILE_GWR         0x0020     /**< @brief Group can write */
#define ZFILE_GEXE        0x0040     /**< @brief Group can execute */
#define ZFILE_ORD         0x0100     /**< @brief Others can read */
#define ZFILE_OWR         0x0200     /**< @brief Others can write */
#define ZFILE_OEXE        0x0400     /**< @brief Others can execute */

#define TMTC_DIR_FLAG (ZFILE_URD | ZFILE_UWR | ZFILE_UEXE \
                      | ZFILE_GRD | ZFILE_GEXE | ZFILE_ORD | ZFILE_OEXE)

#define TMTC_LOG_PRINTE(_ret, _info) do { \
    if (_ret != ZOK) \
    { \
        LOGE << _info; \
        return ZFAILED; \
    } \
} while (0)

#define TMTC_LOG_PRINTD(_ret, _info) do { \
    if (_ret == ZOK) \
    { \
        LOGD << _info; \
        return ZFAILED; \
    } \
} while (0)

#define TMTC_LOG_PRINTI(_ret, _info) do { \
    if (_ret == ZOK) \
    { \
        LOGI << _info \
        return ZFAILED; \
    } \
} while (0)

/* safe  delete ptr */
#define SAFE_DELETE_PTR(p)  if(p) { delete (p); (p) = NULL; }

/* check string invalid */
#define TCHECK_ISEMPTY_STR(_str) (!_str || *_str == '\0')

/* solve Compile waring */
#define COVER_TO_CHAR(_str)  const_cast<ZCHAR *>(_str)

/** @brief TMTC login server way */
typedef enum EN_LOGIN_WAY
{
    EN_LOGIN_MANUAL, /**< @brief  manual login way */
    EN_LOGIN_AUTO,   /**< @brief  auto configure way */

    EN_LOGIN_NUM
}EN_LOGIN_WAY;

/** @brief TMTC  account type */
typedef enum EN_ACCOUNT_TYPE
{
    EN_ACCOUNT_FIXSNUMBER,/** @brief<  voice box use fixs number */
    EN_ACCOUNT_SIP,       /** @brief<  voip user sips acccount */
    EN_ACCOUNT_PHONE,     /** @brief<  volte use phone account */

    EN_ACCOUNT_NUM
}EN_ACCOUNT_TYPE;

/** @brief TMTC  audio control type */
typedef enum EN_AUDIOCONTROL_TYPE
{
    EN_INPUTSDK_OUTPUTSDK_TYPE, /** @brief<  input pcm data and output pcm data by sdk control */
    EN_INPUTUSER_OUTPUTSDK_TYPE,/** @brief<  input pcm data by user control, output pcm data by sdk control */
    EN_INPUTUSER_OUATPUTUSER,   /** @brief<  input pcm data by user control output pcm data by user control */

    EN_AUDIOCONTROL_NUM

}EN_AUDIOCONTROL_TYPE;

typedef enum ENUM_HTTP_PARSE_TYPE
{
    ENUM_HTTP_PARSE_SDK_STATE, /** @brief get request, report current SDK state */
    ENUM_HTTP_PARSE_VALIDURL,  /** @brief get request, obtain latest URL */
    ENUM_HTTP_PARSE_REGISTER,  /** @brief post request, report current register capability */
    ENUM_HTTP_PARSE_UNREGISTER,/** @brief post request, report unregister capability */
    ENUM_HTTP_PARSE_CALL,      /** @brief post request, report current call capability */
    ENUM_HTTP_UPLOAD_LOG       /** @brief post request, report log file */
}ENUM_HTTP_PARSE_TYPE;

/** @brief TMTC obtain call direction */
typedef enum  EN_CALL_DIRECTION
{
    EN_CALL_DIR_OUT, /** @brief< call direction, user auto call to outside */
    EN_CALL_DIR_IN,  /** @brief< call direction, incoming call */

    EN_CALL_DIR_NUM
}EN_CALL_DIRECTION;

/** @brief TMTC print type */
typedef enum  EN_PRINT_TYPE
{
    EN_PRINT_WHITE,
    EN_PRINT_RED,
    EN_PRINT_GREEN,
    EN_PRINT_RESET,
    EN_PRINT_NUM
}EN_PRINT_TYPE;

/** @brief TMTC Manual Way */
typedef struct tagTMTC_MANUALCFG_WAY
{
    ZUCHAR  iAccountType;   /**< @brief  account type see@ EN_ACCOUNT_TYPE */
    ZUCHAR  ucTransprotType;/**< @brief  login transport type EN_MTC_TPT_TYPE */
    ZUCHAR  uacUpdate;      /**< @brief  Is update account data */
    ZCHAR   aucSpare[1];     /**< @brief  for 32 bits alignment */
    ZCHAR   acUserNumber[TMTC_USERNUM_LEN ];   /**<  @brief  login user name */
    ZCHAR   acUserPwd[TMTC_PWD_LEN];            /**<  @brief  login user password */
    ZCHAR   acServerIp[TMTC__IP_LEN];           /**<  @brief  login IMS server ip  */
    ZCHAR   acDomainName[TMTC_DOMAIN_LEN];      /**<  @brief  login server real name*/
    ZINT    iServerPort;                       /**<  @brief  login server port */

}ST_TMTC_MANUAL_WAY;

/** @biref TMTC auto login way */
typedef struct tagTMTC_AUTOCFG_WAY
{
    ZCHAR uacTmnlVendor[TMTC_CP_VENDOR_LEN]; /**<  @brief terminal vendor name */
    ZCHAR uacDmsIp[TMTC__IP_LEN];            /**<  @brief  login DMS server ip  */
}ST_TMTC_AUTOCFG_WAY;

/** @brief register structure */
typedef struct tagTMTC_LOGIN
{
  ZCHAR  acCuei[TMTC_DATA_LEN];   /** @brief terminiate device serival number */
  ZUCHAR aucLoginWay;                    /**< @brief  login way see@ EN_LOGIN_WAY */
  ZUCHAR aucSpare[3];                    /**< @brief for 32 bits alignment */
  union
  {
     ST_TMTC_AUTOCFG_WAY stAuto;   /**< @brief auto login way */
     ST_TMTC_MANUAL_WAY stManual;  /**< @brief manual login way */
  }u;

  /* set defalut value */
  tagTMTC_LOGIN()
  {
       strcpy(acCuei, "200012040000045");
       aucLoginWay  = EN_LOGIN_MANUAL;

     if (EN_LOGIN_MANUAL == aucLoginWay)
     {
        u.stManual.iAccountType = EN_ACCOUNT_FIXSNUMBER;
        strcpy(u.stManual.acUserNumber, "861060967054");
        strcpy(u.stManual.acUserPwd, "unicom0225");
        strcpy(u.stManual.acServerIp, "119.4.202.1");
        strcpy(u.stManual.acDomainName, "ngv.ims.chinaunicom.cn");
        u.stManual.iServerPort = 5070;
        u.stManual.ucTransprotType = EN_MTC_TPT_TCP;
     }
     else
     {
        strcpy(u.stAuto.uacDmsIp, "101.207.176.140");
        strcpy(u.stAuto.uacTmnlVendor, "baidu");
     }
  }

}ST_TMTC_LOGIN;













