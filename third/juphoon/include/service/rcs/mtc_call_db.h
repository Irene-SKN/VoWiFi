/************************************************************************

        Copyright (c) 2005-2011 by Juphoon System Software, Inc.
                       All rights reserved.

     This software is confidential and proprietary to Juphoon System,
     Inc. No part of this software may be reproduced, stored, transmitted,
     disclosed or used in any form or by any means other than as expressly
     provided by the written license agreement between Juphoon and its
     licensee.

     THIS SOFTWARE IS PROVIDED BY JUPHOON "AS IS" AND ANY EXPRESS OR 
     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
     ARE DISCLAIMED. IN NO EVENT SHALL JUPHOON BE LIABLE FOR ANY DIRECT, 
     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
     OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
     POSSIBILITY OF SUCH DAMAGE. 

                    Juphoon System Software, Inc.
                    Email: support@juphoon.com
                    Web: http://www.juphoon.com

************************************************************************/
/*************************************************
  File name     : mtc_call_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2010-02-06
  Description   :
      Data structure and function declare required by mtc call database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CALL_DB_H__
#define _MTC_CALL_DB_H__

/**
 * @file mtc_call_db.h
 * @brief MTC Call Database Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC privacy flag */
#define MTC_PRIVACY_NONE     0x01    /**< @brief no privacy support */
#define MTC_PRIVACY_ID       0x02    /**< @brief using privacy id */
#define MTC_PRIVACY_HEADER   0x03    /**< @brief using privacy header */
#define MTC_PRIVACY_SESSION  0x04    /**< @brief using privacy session */
#define MTC_PRIVACY_CRITICAL 0x05    /**< @brief using privacy critical */

/** @brief MTC database dtmf type */
typedef enum EN_MTC_DB_DTMF_TYPE
{
    EN_MTC_DB_DTMF_AUTO,             /**< @brief auto select inband and outband */
    EN_MTC_DB_DTMF_INBAND,           /**< @brief inband dtmf */
    EN_MTC_DB_DTMF_OUTBAND,          /**< @brief rfc2833 */
    EN_MTC_DB_DTMF_INFO,             /**< @brief INFO message(CISCO format) */
    EN_MTC_DB_DTMF_INFO_HW           /**< @brief INFO message(Huawei format) */
} EN_MTC_DB_DTMF_TYPE;

/** @brief MTC database encoding type */
typedef enum EN_MTC_DB_ENCODING_TYPE
{
    EN_MTC_ENCODING_H264,            /**< @brief H.264 */
    EN_MTC_ENCODING_VP8,             /**< @brief VP8 */
} EN_MTC_ENCODING_TYPE;

/** @brief MTC database ARS type */
typedef enum EN_MTC_DB_ARS_TYPE
{
    EN_MTC_DB_ARS_LD,                /**< @brief Low Difinition */
    EN_MTC_DB_ARS_SD,                /**< @brief Standard Difinition */
    EN_MTC_DB_ARS_HD                 /**< @brief High Difinition */
} EN_MTC_DB_ARS_TYPE;

/** @brief MTC database net type */
typedef enum EN_MTC_DB_NET_TYPE
{
    EN_MTC_DB_NET_3G,                /**< @brief 3G */
    EN_MTC_DB_NET_LAN,               /**< @brief LAN */
    EN_MTC_DB_NET_WIFI               /**< @brief WIFI */
} EN_MTC_DB_NET_TYPE;

/** @brief MTC database video h264 profile type */
typedef enum EN_MTC_DB_H264_PROFILE_TYPE
{
    EN_MTC_DB_H264_PROFILE_BASELINE,        /**< @brief H264 baseline profile */
    EN_MTC_DB_H264_PROFILE_MAIN,            /**< @brief H264 main profile */
    EN_MTC_DB_H264_PROFILE_HIGH,            /**< @brief H264 high profile */
    EN_MTC_DB_H264_PROFILE_NOT_SUPPORT      /**< @brief H264 profile not support */
} EN_MTC_DB_H264_PROFILE_TYPE;

/** @brief MTC database video h264 profile type */
typedef enum EN_MTC_DB_H264_CONSTRAINT_SETS_TYPE
{
    EN_MTC_DB_H264_CONSTRAINT_SETS0,       /**< @brief H264 constraint sets 0 */
    EN_MTC_DB_H264_CONSTRAINT_SETS1,       /**< @brief H264 constraint sets 1 */
    EN_MTC_DB_H264_CONSTRAINT_SETS2,       /**< @brief H264 constraint sets 2 */
    EN_MTC_DB_H264_CONSTRAINT_SETS3        /**< @brief H264 constraint sets 3 */
} EN_MTC_DB_H264_CONSTRAINT_SETS_TYPE;

/** @brief MTC database video h264 packet mode type */
typedef enum EN_MTC_DB_H264_PACKET_MODE_TYPE
{
    EN_MTC_DB_H264_PACKET_MODE_0,        /**< @brief H264 packet mode 0 */
    EN_MTC_DB_H264_PACKET_MODE_1         /**< @brief H264 packet mode 1 */
} EN_MTC_DB_H264_PACKET_MODE_TYPE;

/** @brief MTC database session timer type */
typedef enum EN_MTC_DB_SESSION_TIME_TYPE
{
    EN_MTC_DB_SESSION_TIME_OFF,      /**< @brief Session timer off*/
    EN_MTC_DB_SESSION_TIME_NEGO,     /**< @brief Session timer negotiation */
    EN_MTC_DB_SESSION_TIME_FORCE     /**< @brief Session timer force on */
} EN_MTC_DB_SESSION_TIME_TYPE;

/** @brief MTC database  session timer refresher type */
typedef enum EN_MTC_DB_REFRESHER_TYPE
{
    EN_MTC_DB_REFRESHER_DEFAULT,        /**< @brief Session timer refresher specified by server
                                                                            (no refresher value) */
    EN_MTC_DB_REFRESHER_UAC,            /**< @brief Session timer refresher is UAC */
    EN_MTC_DB_REFRESHER_UAS             /**< @brief Session timer refresher is UAS */
} EN_MTC_DB_REFRESHER_TYPE;

/** @brief MTC database SRTP crypto type */
typedef enum EN_MTC_DB_SRTP_CRYPTO_TYPE
{
    EN_MTC_DB_SRTP_CRYPTO_OFF,           /**< @brief SRTP off */
    EN_MTC_DB_SRTP_CRYPTO_AES128_HMAC80, /**< @brief SRTP AES-128 HMAC-80 */
    EN_MTC_DB_SRTP_CRYPTO_AES128_HMAC32, /**< @brief SRTP AES-128 HMAC-32 */
    EN_MTC_DB_SRTP_CRYPTO_SRTP_ZUC_EEA3, /**< @brief SRTP ZUC EEA3 */
} EN_MTC_DB_SRTP_CRYPTO_TYPE;

/* mtc call prefix option */
typedef enum EN_MTC_DB_PREFIX_OPT_TYPE
{
    EN_MTC_DB_PREFIX_OPT_NO_USE,     /* do not use call prefix */
    EN_MTC_DB_PREFIX_OPT_CONFIRM,    /* need user to confirm use or not */
    EN_MTC_DB_PREFIX_OPT_FORCE       /* force to use call prefix */
} EN_MTC_DB_PREFIX_OPT_TYPE;

/* mtc P-Asserted-Identity policy */
typedef enum EN_MTC_DB_PAI_POLICY_TYPE
{
    EN_MTC_DB_PAI_POLICY_SIP,           /* sip uri in P-Asserted-Identity */
    EN_MTC_DB_PAI_POLICY_SIPS,          /* sips uri in P-Asserted-Identity */
    EN_MTC_DB_PAI_POLICY_DFT,           /* default(first) in P-Asserted-Identity */
    EN_MTC_DB_PAI_POLICY_TEL            /* tel uri in P-Asserted-Identity */
} EN_MTC_DB_PAI_POLICY_TYPE;

/* mtc call resolution ratio type */
typedef enum EN_MTC_CALL_DB_RES_RATIO_TYPE
{
    EN_MTC_CALL_DB_RES_RATIO_DEFAULT,        /* use default resolution ratio */
    EN_MTC_CALL_DB_RES_RATIO_288P,           /* use 352X288 resolution ratio */
    EN_MTC_CALL_DB_RES_RATIO_480P,           /* use 640X480 resolution ratio */
    EN_MTC_CALL_DB_RES_RATIO_720P,           /* use 1280X720 resolution ratio */
    EN_MTC_CALL_DB_RES_RATIO_1080P           /* use 1920X1080 resolution ratio */
} EN_MTC_CALL_DB_RES_RATIO_TYPE;

/** @brief The profile mode mask */
#define MTC_CALL_DB_MEDIA_MASK 0xFf

/** @brief The profile media mode type. */
typedef enum EN_MTC_CALL_DB_MEDIA_MODE
{
    EN_MTC_CALL_DB_MEDIA_BASE    = 0x00, /**< @brief media base */
    EN_MTC_CALL_DB_MEDIA_ENHANCE = 0x01 /**< @brief media enhance */
} EN_MTC_CALL_DB_MEDIA_MODE;

/* mtc stream direction type */
typedef enum EN_MTC_DB_STRM_DIR_TYPE
{
    EN_MTC_DB_STRM_DIR_NONE,            /* stream direction type none */
    EN_MTC_DB_STRM_DIR_SEND,            /* stream direction type send only */
    EN_MTC_DB_STRM_DIR_RECV,            /* stream direction type receive only */
    EN_MTC_DB_STRM_DIR_SENDRECV,        /* stream direction type send and receive */
} EN_MTC_DB_STRM_DIR_TYPE;

/** @brief MTC database fec type */
typedef enum EN_MTC_DB_FEC_TYPE
{
    EN_MTC_DB_FEC_NONE,                /**< @brief not support fec */
    EN_MTC_DB_FEC_RED,                 /**< @brief use red type for fec */
    EN_MTC_DB_FEC_MULTI_SSRC,          /**< @brief use multi ssrc for fec(rfc5956, rfc5576) */
} EN_MTC_DB_FEC_TYPE;

/** @brief Type of MTC resolution control type. */
typedef enum EN_MTC_RES_CTRL_TYPE
{
    EN_MTC_RES_CTRL_NORMAL = 0,    /**< @brief resolution control mode provided by engine. */    
    EN_MTC_RES_CTRL_SMOOTH = 1,    /**< @brief smooth mode(default, lower resolution, higher framerate). */
} EN_MTC_RES_CTRL_TYPE;

/** @brief Type of MTC video quality mode. */
typedef enum EN_MTC_ARS_TYPE
{
    EN_MTC_ARS_QUALITY_SPATIAL   = 0, /**< @brief Spatial quality first: clear picture. */
    EN_MTC_ARS_QUALITY_TEMPORAL  = 1, /**< @brief Temporal quality first: fluent motion. */
} EN_MTC_ARS_TYPE;

/** @brief Type of MTC echo cancellation. */
typedef enum EN_MTC_EC_TYPE
{
    EN_MTC_EC_AEC = 0,                /**< @brief Default AEC provided by engine. */    
    EN_MTC_EC_OS  = 1,                /**< @brief AEC provided by OS. */
    EN_MTC_EC_AES = 2,                /**< @brief AES provided by engine. */    
    EN_MTC_EC_AEC_FDE = 3,            /**< @brief AEC based on formant delay estimation. */ 
    EN_MTC_EC_AEC_SDE = 4,            /**< @brief AEC based on spectrum delay estimation. */ 
} EN_MTC_EC_TYPE;

/** @brief Type of MTC noise suppression. */
typedef enum EN_MTC_NS_TYPE
{
    EN_MTC_NS_LOW  = 0,               /**< @brief NS with low level. */
    EN_MTC_NS_MID  = 1,               /**< @brief NS with moderate level. */
    EN_MTC_NS_HIGH = 2,               /**< @brief NS with high level. */
    EN_MTC_NS_VERYHIGH = 3,           /**< @brief NS with very high level. */
} EN_MTC_NS_TYPE;

/** @brief Type of MTC gain control. */
typedef enum EN_MTC_GC_TYPE
{
    EN_MTC_GC_ANALOG  = 0,           /**< @brief AGC based on analog volume adjustment. */
    EN_MTC_GC_OS      = 1,           /**< @brief AGC provided by OS */
    EN_MTC_GC_DIGITAL = 2,           /**< @brief AGC based on digital volume adjustment. */
    EN_MTC_GC_FIXED   = 3            /**< @brief AGC based on fixed digital volume adjustment. */
} EN_MTC_GC_TYPE;

/** @brief Type of MTC receiving-side gain control. */
typedef enum EN_MTC_RX_GC_TYPE
{
    EN_MTC_RX_GC_FIXED     = 0,       /**< @brief RX-AGC based on fixed digital volume adjustment. */
    EN_MTC_RX_GC_ADAPTIVE  = 1,       /**< @brief RX-AGC based on adaptive digital volume adjustment. */
} EN_MTC_RX_GC_TYPE;

/** @brief Type of MTC voice activity detection. */
typedef enum EN_MTC_VAD_TYPE
{
    EN_MTC_VAD_NORMAL  = 0,           /**< @brief VAD with lowest level. */
    EN_MTC_VAD_LOW     = 1,           /**< @brief VAD with low level. */
    EN_MTC_VAD_MID     = 2,           /**< @brief VAD with moderate level. */
    EN_MTC_VAD_HIGH    = 3,           /**< @brief VAD with high level. */
} EN_MTC_VAD_TYPE;

#define PROV_SETTINGS
/**
 * @brief MTC CALL db restore configuration of current user for speicifc mode.
 *
 * @param [in] iMode The combination of EN_MTC_CALL_DB_MEDIA_MODE 
 *
 * This interface should be invoke after @ref Mtc_CliInit and 
 * @ref Mtc_CliOpen was called.
 *
 * @retval ZOK Restore provision successfully.
 * @retval ZFAILED Restore provision failed.
 */
ZFUNC ZINT Mtc_CallDbRestoreProvision(ZUINT iMode);

#define DTMF_SETTINGS

/**
 * @brief Get the DTMF message type.
 *
 * @return The DTMF message type.
 *         DTMF type MTC EN_MTC_DB_DTMF_TYPE, include 
 *         EN_MTC_DB_DTMF_INBAND, EN_MTC_DB_DTMF_OUTBAND, 
 *         EN_MTC_DB_DTMF_INFO, EN_MTC_DB_DTMF_INFO_HW, 
 *         EN_MTC_DB_DTMF_AUTO.
 *
 * @see @ref Mtc_CallDbSetDtmfType
 */
ZFUNC ZUINT Mtc_CallDbGetDtmfType(ZFUNC_VOID);

/**
 * @brief Set the DTMF message type.
 *
 * @param [in] iType The DTMF message type.
 *         DTMF type EN_MTC_DB_DTMF_TYPE, include 
 *         EN_MTC_DB_DTMF_INBAND, EN_MTC_DB_DTMF_OUTBAND, 
 *         EN_MTC_DB_DTMF_INFO, EN_MTC_DB_DTMF_INFO_HW, 
 *         EN_MTC_DB_DTMF_AUTO.
 *
 * @retval ZOK Set the DTMF message type successfully.
 * @retval ZFAILED Set the DTMF message type failed.
 *
 * @see @ref Mtc_CallDbGetDtmfType
 */
ZFUNC ZINT Mtc_CallDbSetDtmfType(ZUINT iType);

/**
 * @brief Get the DTMF message payload.
 *
 * @return The DTMF message payload.
 *
 * @see @ref Mtc_CallDbSetDtmfPayload
 */
ZFUNC ZUINT Mtc_CallDbGetDtmfPayload(ZFUNC_VOID);

/**
 * @brief Set the DTMF message payload.
 *
 * @param [in] iPayload The DTMF message payload.
 *
 * @retval ZOK Set the DTMF message payload successfully.
 * @retval ZFAILED Set the DTMF message payload failed.
 *
 * @see @ref Mtc_CallDbGetDtmfPayload
 */
ZFUNC ZINT Mtc_CallDbSetDtmfPayload(ZUINT iPayload);

/**
 * @brief Get the watch DTMF flag.
 *
 * @retval ZTRUE It will notify watcher when receive DTMF.
 * @retval ZFALSE Don't notify.
 *
 * @see @ref Mtc_CallDbSetDtmfWatch
 */
ZFUNC ZBOOL Mtc_CallDbGetDtmfWatch(ZFUNC_VOID);

/**
 * @brief Set the watch DTMF flag.
 *
 * @param [in] bWatch If ZTRUE, it will notify watcher when receive DTMF.
 *                    ZFALSE, Don't notify.
 *
 * @retval ZOK Set watch DTMF flag successfully.
 * @retval ZFAILED Set watch DTMF flag failed.
 *
 * @see @ref Mtc_CallDbGetDtmfWatch
 */
ZFUNC ZINT Mtc_CallDbSetDtmfWatch(ZBOOL bWatch);

/**
 * @brief Get audio jitter buffer value in millisecconds.
 *
 * @param [out] piMinDelay minimum jitter buffer delay.
 * @param [out] piMaxPacketSize maximum jitter buffer packet numbers.
 *
 * @retval ZOK Get successfully.
 * @retval ZFAILED Get failed.
 *
 * @see @ref Mtc_CallDbSetAudioJitterParms
 */
ZFUNC ZINT Mtc_CallDbGetAudioJitterParms(ZUINT * piMinDelay,
                ZUINT * piMaxPacketSize);

/**
 * @brief Set audio jitter buffer value in millisecconds.
 *
 * @param [in] iMinDelay minimum jitter buffer delay.
 * @param [in] iMaxPacketSize maximum jitter buffer packet numbers.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetAudioJitterParms
 */
ZFUNC ZINT Mtc_CallDbSetAudioJitterParms(ZUINT iMinDelay,
                ZUINT iMaxPacketSize);

#define AUDIO_QOS_SETTINGS

/**
 * @brief Get audio QOS.
 *
 * @param [out] pbAec Audio echo cancel option.
 * @param [out] pbAnr Audio noise reduction.
 * @param [out] pbAgc Audio gain control option.
 * @param [out] pbVad Audio silence detection.
 *
 * @retval ZOK Get audio QOS successfully.
 * @retval ZFAILED Get audio QOS failed.
 *
 * @see @ref Mtc_CallDbSetAudioQos
 */
ZFUNC ZINT Mtc_CallDbGetAudioQos(ZBOOL *pbAec, ZBOOL *pbAnr, 
                ZBOOL *pbAgc, ZBOOL *pbVad);

/**
 * @brief Set audio QOS.
 *
 * @param [in] bAec Audio echo cancel option.
 * @param [in] bAnr Audio noise reduction.
 * @param [in] bAgc Audio gain control option.
 * @param [in] bVad Audio silence detection.
 *
 * @retval ZOK Set audio QOS successfully.
 * @retval ZFAILED Set audio QOS failed.
 *
 * @see @ref Mtc_CallDbGetAudioQos
 */
ZFUNC ZINT Mtc_CallDbSetAudioQos(ZBOOL bAec, ZBOOL bAnr,
                ZBOOL bAgc, ZBOOL bVad);

/**
 * @brief Set state of AEC.
 *
 * @param [in] bEnable ZTRUE to enable AEC, ZFALSE to disable AEC.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetAecEnable
 */
ZFUNC ZINT Mtc_CallDbSetAecEnable(ZBOOL bEnable);

/**
 * @brief Get state of AEC.
 *
 * @retval ZTRUE indicate AEC is enabled.
 * @retval ZFALSE indicate AEC is disabled.
 *
 * @see Mtc_CallDbSetAecEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetAecEnable(ZFUNC_VOID);

/**
 * @brief Set mode of AEC.
 *
 * @param [in] ucMode Mode of AEC, @ref EN_MTC_EC_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetAecMode
 */
ZFUNC ZINT Mtc_CallDbSetAecMode(ZUCHAR ucMode);

/**
 * @brief Get mode of AEC.
 *
 * @return Current AEC mode, @ref EN_MTC_EC_TYPE.
 *
 * @see Mtc_CallDbSetAecMode
 */
ZFUNC ZUCHAR Mtc_CallDbGetAecMode(ZFUNC_VOID);

/**
 * @brief Set state of VAD.
 *
 * @param [in] bEnable ZTRUE to enable VAD, ZFALSE to disable VAD.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetVadEnable
 */
ZFUNC ZINT Mtc_CallDbSetVadEnable(ZBOOL bEnable);

/**
 * @brief Get state of VAD.
 *
 * @retval ZTRUE indicate VAD is enabled.
 * @retval ZFALSE indicate VAD is disabled.
 *
 * @see Mtc_CallDbSetVadEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetVadEnable(ZFUNC_VOID);

/**
 * @brief Set mode of VAD.
 *
 * @param [in] ucMode Mode of VAD, @ref EN_MTC_VAD_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetVadMode
 */
ZFUNC ZINT Mtc_CallDbSetVadMode(ZUCHAR ucMode);

/**
 * @brief Get mode of VAD.
 *
 * @return Current VAD mode, @ref EN_MTC_VAD_TYPE.
 *
 * @see Mtc_CallDbSetVadMode
 */
ZFUNC ZUCHAR Mtc_CallDbGetVadMode(ZFUNC_VOID);

/**
 * @brief Set state of AGC.
 *
 * @param [in] bEnable ZTRUE to enable AGC, ZFALSE to disable AGC.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetAgcEnable
 */
ZFUNC ZINT Mtc_CallDbSetAgcEnable(ZBOOL bEnable);

/**
 * @brief Get state of AGC.
 *
 * @retval ZTRUE indicate AGC is enabled.
 * @retval ZFALSE indicate AGC is disabled.
 *
 * @see Mtc_CallDbSetAgcEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetAgcEnable(ZFUNC_VOID);

/**
 * @brief Set mode of AGC.
 *
 * @param [in] ucMode Mode of AGC, @ref EN_MTC_GC_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetAgcMode
 */
ZFUNC ZINT Mtc_CallDbSetAgcMode(ZUCHAR ucMode);

/**
 * @brief Get mode of AGC.
 *
 * @return Current AGC mode, @ref EN_MTC_GC_TYPE.
 *
 * @see Mtc_CallDbSetAgcMode
 */
ZFUNC ZUCHAR Mtc_CallDbGetAgcMode(ZFUNC_VOID);

/**
 * @brief Set target dBOV of AGC.
 *
 * @param [in] ucTargetDb Target dBOV of AGC, should be 0 - 30.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetAgcTarget
 */
ZFUNC ZINT Mtc_CallDbSetAgcTarget(ZUCHAR ucTargetDb);

/**
 * @brief Get target dBOV of AGC.
 *
 * @return Current target dBOV of AGC.
 *
 * @see Mtc_CallDbSetAgcTarget
 */
ZFUNC ZUCHAR Mtc_CallDbGetAgcTarget(ZFUNC_VOID);

/**
 * @brief Set state of RxAGC.
 *
 * @param [in] bEnable ZTRUE to enable RxAGC, ZFALSE to disable RxAGC.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetRxAgcEnable
 */
ZFUNC ZINT Mtc_CallDbSetRxAgcEnable(ZBOOL bEnable);

/**
 * @brief Get state of RxAGC.
 *
 * @retval ZTRUE indicate RxAGC is enabled.
 * @retval ZFALSE indicate RxAGC is disabled.
 *
 * @see Mtc_CallDbSetRxAgcEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetRxAgcEnable(ZFUNC_VOID);

/**
 * @brief Set mode of RxAGC.
 *
 * @param [in] ucMode Mode of RxAGC, @ref EN_MTC_RX_GC_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetRxAgcMode
 */
ZFUNC ZINT Mtc_CallDbSetRxAgcMode(ZUCHAR ucMode);

/**
 * @brief Get mode of RxAGC.
 *
 * @return Current RxAGC mode, @ref EN_MTC_RX_GC_TYPE.
 *
 * @see Mtc_CallDbSetRxAgcMode
 */
ZFUNC ZUCHAR Mtc_CallDbGetRxAgcMode(ZFUNC_VOID);

/**
 * @brief Set target dBOV of RxAGC.
 *
 * @param [in] ucTargetDb Target dBOV of RxAGC, should be 0 - 30.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetRxAgcTarget
 */
ZFUNC ZINT Mtc_CallDbSetRxAgcTarget(ZUCHAR ucTargetDb);

/**
 * @brief Get target dBOV of RxAGC.
 *
 * @return Current target dBOV of RxAGC.
 *
 * @see Mtc_CallDbSetRxAgcTarget
 */
ZFUNC ZUCHAR Mtc_CallDbGetRxAgcTarget(ZFUNC_VOID);

/**
 * @brief Set state of ANR.
 *
 * @param [in] bEnable ZTRUE to enable ANR, ZFALSE to disable ANR.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetAnrEnable
 */
ZFUNC ZINT Mtc_CallDbSetAnrEnable(ZBOOL bEnable);

/**
 * @brief Get state of ANR.
 *
 * @retval ZTRUE indicate ANR is enabled.
 * @retval ZFALSE indicate ANR is disabled.
 *
 * @see Mtc_CallDbSetAnrEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetAnrEnable(ZFUNC_VOID);

/**
 * @brief Set mode of ANR.
 *
 * @param [in] ucMode Mode of ANR, @ref EN_MTC_NS_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetAnrMode
 */
ZFUNC ZINT Mtc_CallDbSetAnrMode(ZUCHAR ucMode);

/**
 * @brief Get mode of ANR.
 *
 * @return Current mode of ANR, @ref EN_MTC_NS_TYPE.
 *
 * @see Mtc_CallDbSetAnrMode
 */
ZFUNC ZUCHAR Mtc_CallDbGetAnrMode(ZFUNC_VOID);

/**
 * @brief Get ARS option of audio stream.
 *
 * @retval ZTRUE ARS is enabled for audio stream.
 * @retval ZFALSE ARS is disabled for audio stream.
 *
 * @see @ref Mtc_CallDbSetVideoArs
 */
ZFUNC ZBOOL Mtc_CallDbGetAudioArsEnable(ZFUNC_VOID);

/**
 * @brief Set ARS option of audio stream.
 *
 * @param [in] bEnable ZTRUE to enable ARS, otherwise to disable ARS.
 *
 * @retval ZOK Set the audio ARS option successfully.
 * @retval ZFAILED Set the audio ARS option failed.
 *
 * @see @ref Mtc_CallDbGetVideoArs
 */
ZFUNC ZINT Mtc_CallDbSetAudioArsEnable(ZBOOL bEnable);

/**
 * @brief Set state of RxANR.
 *
 * @param [in] bEnable ZTRUE to enable RxANR, ZFALSE to disable RxANR.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetRxAnrEnable
 */
ZFUNC ZINT Mtc_CallDbSetRxAnrEnable(ZBOOL bEnable);

/**
 * @brief Get state of RxANR.
 *
 * @retval ZTRUE indicate RxANR is enabled.
 * @retval ZFALSE indicate RxANR is disabled.
 *
 * @see Mtc_CallDbSetRxAnrEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetRxAnrEnable(ZFUNC_VOID);

/**
 * @brief Set mode of RxANR.
 *
 * @param [in] ucMode Mode of RxANR, @ref EN_MTC_NS_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetRxAnrMode
 */
ZFUNC ZINT Mtc_CallDbSetRxAnrMode(ZUCHAR ucMode);

/**
 * @brief Get mode of RxANR.
 *
 * @return Current mode of RxANR, @ref EN_MTC_NS_TYPE.
 *
 * @see Mtc_CallDbSetRxAnrMode
 */
ZFUNC ZUCHAR Mtc_CallDbGetRxAnrMode(ZFUNC_VOID);

/**
 * @brief Set state of audio redundant.
 *
 * @param [in] bEnable ZTRUE to enable audio redundant, ZFALSE to disable audio redundant.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetAudioRed
 */
ZFUNC ZINT Mtc_CallDbSetAudioRed(ZBOOL bEnable);

/**
 * @brief Get state of audio redundant.
 *
 * @retval ZTRUE indicate audio redundant is enabled.
 * @retval ZFALSE indicate audio redundant is disabled.
 *
 * @see Mtc_CallDbSetAudioRed
 */
ZFUNC ZBOOL Mtc_CallDbGetAudioRed(ZFUNC_VOID);

/**
 * @brief Get RTX option from database.
 *
 * @retval ZTRUE Start RTX.
 * @retval ZFALSE Do not start RTX.
 *
 * @see @ref Mtc_CallDbSetAudioRtxEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetAudioRtxEnable(ZFUNC_VOID);

/**
 * @brief Set RTX option.
 *
 * @param [in] bEnable RTX option.
 *
 * @retval ZOK Set RTX option successfully.
 * @retval ZFAILED Set RTX option failed.
 *
 * @see @ref Mtc_CallDbGetAudioRtxEnable
 */
ZFUNC ZINT Mtc_CallDbSetAudioRtxEnable(ZBOOL bEnable);

#define AUDIO_CODEC_SETTINGS
/**
 * @brief Set AMR-WB bitrate(bps).
 *
 * @param [in] iBitrate bitrate(bps) of AMR-WB. The value can only be (6600, 8850, 
 *      12650, 14250, 15850, 18250, 19850, 23050, 23850).
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 */
ZFUNC ZUINT Mtc_CallDbSetAmrWbBitrate(ZUINT iBitrate);

/**
 * @brief Get AMR-WB bitrate.
 *
 * @return The bitrate(bps) of AMR-WB .
 */
ZFUNC ZUINT Mtc_CallDbGetAmrWbBitrate(ZFUNC_VOID);

/**
 * @brief Set AMR bitrate(bps).
 *
 * @param [in] iBitrate bitrate(bps) of AMR. The value can only be (4750, 5150, 
 *      5900, 6700, 7400, 7950, 10200, 12200).
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 */
ZFUNC ZUINT Mtc_CallDbSetAmrBitrate(ZUINT iBitrate);

/**
 * @brief Get AMR bitrate.
 *
 * @return The bitrate of AMR .
 */
ZFUNC ZUINT Mtc_CallDbGetAmrBitrate(ZFUNC_VOID);


/**
 * @brief Get supporting audio codec count
 *
 * @return The count of audio codec supported.
 */
ZFUNC ZUINT Mtc_CallDbGetSuptAudioCodecCount(ZFUNC_VOID);

/**
 * @brief Get supporting audio codec from database.
 *
 * @param [in] iIndex Codec index from 0 to (count - 1). Count get by
                       @ref Mtc_CallDbGetSuptAudioCodecCount.
 *
 * @return The string of Codec name successfully or empty string failed.
 *
 * @see @ref Mtc_CallDbGetSuptAudioCodecCount
 */
ZFUNC ZCONST ZCHAR * Mtc_CallDbGetSuptAudioCodec(ZUINT iIndex);

/**
 * @brief Get used audio codec count
 *
 * @return The count of audio codec supported.
 */
ZFUNC ZUINT Mtc_CallDbGetAudioCodecCount(ZFUNC_VOID);

/**
 * @brief Get audio codec from database.
 *
 * @param [in] ucPriority Codec priority.
 *
 * @return The string of Codec name successfully or empty string failed.
 *
 * @see @ref Mtc_CallDbSetAudioCodecByPriority
 */
ZFUNC ZCHAR * Mtc_CallDbGetAudioCodecByPriority(ZUCHAR ucPriority);

/**
 * @brief Set the audio codec enable or disable.
 *
 * @param [in] pcCodec Codec name.
 * @param [in] bEnable ZTRUE for enable, other for disable.
 *
 * @retval ZOK Set the audio codec enable or disable successfully.
 * @retval ZFAILED Set the audio codec enable or disable failed.
 */
ZFUNC ZINT Mtc_CallDbSetAudioCodecEnable(ZCHAR *pcCodec,
                ZBOOL bEnable);

/**
 * @brief Set the audio codec priority.
 *
 * @param [in] pcName Codec name.
 * @param [in] ucPriority Codec priority.
 *
 * @retval ZOK Set the audio codec priority successfully.
 * @retval ZFAILED Set the audio codec priority failed.
 *
 * @see @ref Mtc_CallDbGetAudioCodecByPriority
 */
ZFUNC ZINT Mtc_CallDbSetAudioCodecByPriority(ZCHAR *pcName,
                ZUCHAR ucPriority);

/**
 * @brief Get AMR octet-align enable flag .
 *
 * @retval ZTRUE AMR octet-align enable.
 * @retval ZFALSE AMR octet-align disable.
 *
 * @see @ref Mtc_CallDbSetAmrOctAlign
 */
ZFUNC ZBOOL Mtc_CallDbGetAmrOctAlign(ZFUNC_VOID);

/**
 * @brief Set AMR octet-align enable flag .
 *
 * @param [in] bEnable ZTRUE for enable, other for disable.
 *
 * @retval ZOK Set the AMR octect-align enable successfully.
 * @retval ZFAILED Set the AMR octect-align enable failed.
 *
 * @see @ref Mtc_CallDbGetAmrOctAlign
 */
ZFUNC ZINT Mtc_CallDbSetAmrOctAlign(ZBOOL bEnable);

/**
 * @brief Get AMR-WB octet-align enable flag .
 *
 * @retval ZTRUE AMR-WB octet-align enable.
 * @retval ZFALSE AMR-WB octet-align disable.
 *
 * @see @ref Mtc_CallDbSetAmrWbOctAlign
 */
ZFUNC ZBOOL Mtc_CallDbGetAmrWbOctAlign(ZFUNC_VOID);

/**
 * @brief Set AMR-WB octet-align enable flag .
 *
 * @param [in] bEnable ZTRUE for enable, other for disable.
 *
 * @retval ZOK Set the AMR-WB octet-align enable successfully.
 * @retval ZFAILED Set the AMR-WB octet-align enable failed.
 *
 * @see @ref Mtc_CallDbGetAmrWbOctAlign
 */
ZFUNC ZINT Mtc_CallDbSetAmrWbOctAlign(ZBOOL bEnable);

#define AUDIO_VOLUME_SETTINGS

/**
 * @brief Get default volume value for speaker.
 *
 * @return Default volume value for speaker, from 0-20.
 */
ZFUNC ZUINT Mtc_CallDbGetSpkDftVol(ZFUNC_VOID);

/**
 * @brief Set default volume value for speaker.
 *
 * @param [in] iVol Default volume value for speaker, from 0-20.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 */
ZFUNC ZINT Mtc_CallDbSetSpkDftVol(ZUINT iVol);

#define VIDEO_CODEC_SETTINGS

/**
 * @brief Get supporting video codec count
 *
 * @return The count of video codec supported.
 */
ZFUNC ZUINT Mtc_CallDbGetSuptVideoCodecCount(ZFUNC_VOID);

/**
 * @brief Get supporting video codec from database.
 *
 * @param [in] iIndex Codec index from 0 to (count - 1). Count get by
                       @ref Mtc_CallDbGetSuptVideoCodecCount.
 *
 * @return The string of Codec name successfully or empty string failed.
 *
 * @see @ref Mtc_CallDbGetSuptVideoCodecCount
 */
ZFUNC ZCONST ZCHAR * Mtc_CallDbGetSuptVideoCodec(ZUINT iIndex);

/**
 * @brief Get video codec count.
 *
 * @return Video used codec count.
 */
ZFUNC ZUINT Mtc_CallDbGetVideoCodecCount(ZFUNC_VOID);

/**
 * @brief Get video codec from database.
 *
 * @param [in] ucPriority Codec priority.
 *
 * @return The string of Codec name successfully or empty string failed.
 *
 * @see @ref Mtc_CallDbSetVideoCodecByPriority
 */
ZFUNC ZCHAR * Mtc_CallDbGetVideoCodecByPriority(ZUCHAR ucPriority);

/**
 * @brief Get codec priority auto adjust flag from database.
 *
 * @retval ZTRUE Indicates codec priority will auto adjust.
 * @retval ZFALSE Indicates codec priority will not auto adjust.
 *
 * @see @ref Mtc_CallDbSetCodecPriorityAutoAdjust
 */
ZFUNC ZBOOL Mtc_CallDbGetCodecPriorityAutoAdjust(ZFUNC_VOID);

/**
 * @brief Set the video codec enable or disable.
 *
 * @param [in] pcCodec Codec name.
 * @param [in] bEnable ZTRUE for enable, other for disable.
 *
 * @retval ZOK Set the video codec enable or disable successfully.
 * @retval ZFAILED Set the video codec enable or disable failed.
 */
ZFUNC ZINT Mtc_CallDbSetVideoCodecEnable(ZCHAR *pcCodec,
                ZBOOL bEnable);

/**
 * @brief Set the video codec priority.
 *
 * @param [in] pcCodec Codec name.
 * @param [in] ucPriority Codec priority.
 *
 * @retval ZOK Set the video codec priority successfully.
 * @retval ZFAILED Set the video codec priority failed.
 *
 * @see @ref Mtc_CallDbGetVideoCodecByPriority
 */
ZFUNC ZINT Mtc_CallDbSetVideoCodecByPriority(ZCHAR *pcCodec,
                ZUCHAR ucPriority);

/**
 * @brief Set the codec priority auto adjust flag.
 *
 * @param [in] bAdjust Auto adjust flag.
 *
 * @retval ZOK Set the auto adjust flag successfully.
 * @retval ZFAILED Set the auto adjust flag failed.
 *
 * @see @ref Mtc_CallDbGetCodecPriorityAutoAdjust
 */
ZFUNC ZINT Mtc_CallDbSetCodecPriorityAutoAdjust(ZBOOL bAdjust);

/**
 * @brief Set video h264 profile.
 *
 * @param [in] ucProfile Video h264 profile parameter.
 * @ref  EN_MTC_DB_H264_PROFILE_TYPE.
 *
 * @retval ZOK Set the video h264 profile successfully.
 * @retval ZFAILED Set the video h264 profile failed.
 *
 * @see @ref Mtc_CallDbGetVideoH264Profile
 */
ZFUNC ZINT Mtc_CallDbSetVideoH264Profile(ZUCHAR ucProfile);

/**
 * @brief Get video h264 profile.
 *
 * @return Video h264 profile, @ref  EN_MTC_DB_H264_PROFILE_TYPE.
 *
 * @see @ref Mtc_CallDbSetVideoH264Profile
 */
ZFUNC ZUCHAR Mtc_CallDbGetVideoH264Profile();

/**
 * @brief Set video h264 consraint sets, which should be set according to profile(see h264 rfc for details).
 *
 * @param [in] ucProfile Video h264 consraint sets parameter.
 * @ref  EN_MTC_DB_H264_CONSTRAINT_SETS_TYPE.
 *
 * @retval ZOK Set the video h264 consraint sets successfully.
 * @retval ZFAILED Set the video h264 consraint sets failed.
 *
 * @see @ref Mtc_CallDbGetVideoH264Constraint
 */
ZFUNC ZINT Mtc_CallDbSetVideoH264Constraint(ZUCHAR ucConstraint);

/**
 * @brief Get video h264 consraint sets.
 *
 * @return Video h264 consraint sets, @ref  EN_MTC_DB_H264_CONSTRAINT_SETS_TYPE.
 *
 * @see @ref Mtc_CallDbSetVideoH264Constraint
 */
ZFUNC ZUCHAR Mtc_CallDbGetVideoH264Constraint();

/**
 * @brief Set video h264 packet mode.
 *
 * @param [in] ucMode Video h264 packet mode parameter.
 *
 * @retval ZOK Set the video h264 packet mode successfully.
 * @retval ZFAILED Set the video h264 packet mode  failed.
 *
 * @see @ref Mtc_CallDbGetVideoH264Packetmode
 */
ZFUNC ZINT Mtc_CallDbSetVideoH264Packetmode(ZUCHAR ucMode);

/**
 * @brief Get video h264 packet mode.
 *
 * @return Video h264 packet mode, @ref  EN_MTC_DB_H264_PACKET_MODE_TYPE.
 *
 * @see @ref Mtc_CallDbSetVideoH264Packetmode
 */
ZFUNC ZUCHAR Mtc_CallDbGetVideoH264Packetmode();

/**
 * @brief Set video image attribute enable.
 *
 * @param [in] bEnable ZTRUE to enable image attribute, ZFALSE to disable.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_CallDbGetVideoImgAttrEnable
 */
ZFUNC ZINT Mtc_CallDbSetVideoImgAttrEnable(ZBOOL bEnable);

/**
 * @brief Get video image attribute enable.
 *
 * @retval ZTRUE indicate image attribute is enabled.
 * @retval ZFALSE indicate image attribute is disabled.
 *
 * @see @ref Mtc_CallDbSetVideoImgAttrEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetVideoImgAttrEnable();

/**
 * @brief Set video cvo attribute enable.
 *
 * @param [in] bEnable ZTRUE to enable cvo attribute, ZFALSE to disable.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_CallDbGetVideoCvoEnable
 */
ZFUNC ZINT Mtc_CallDbSetVideoCvoEnable(ZBOOL bEnable);

/**
 * @brief Get video cvo attribute enable.
 *
 * @retval ZTRUE indicate video cvo attribute is enabled.
 * @retval ZFALSE indicate video cvo attribute is disabled.
 *
 * @see @ref Mtc_CallDbSetVideoCvoEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetVideoCvoEnable();

/**
 * @brief Get video nack RTT in millisecconds.
 *
 * @param [out] piMinRtt minimum video nack rtt(ms).
 * @param [out] piMaxRtt maximum video nack rtt(ms).
 *
 * @retval ZOK Get successfully.
 * @retval ZFAILED Get failed.
 *
 * @see @ref Mtc_CallDbSetVideoNackRttParms
 */
ZFUNC ZINT Mtc_CallDbGetVideoNackRttParms(ZUINT * piMinRtt,
                ZUINT * piMaxRtt);

/**
 * @brief Set video nack RTT in millisecconds.
 *
 * @param [in] iMinRtt minimum video nack RTT(ms).
 * @param [in] iMaxRtt maximum video nack RTT(ms).
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetVideoNackRttParms
 */
ZFUNC ZINT Mtc_CallDbSetVideoNackRttParms(ZUINT iMinRtt,
                ZUINT iMaxRtt);

#define VIDEO_PARAMETER_SETTINGS

/**
 * @brief Get video bitrate.
 *
 * @retval Video bitrate parameter in bps.
 *
 * @see @ref Mtc_CallDbSetVideoBitrate
 */
ZFUNC ZUINT Mtc_CallDbGetVideoBitrate();

/**
 * @brief Set video bitrate.
 *
 * @param [in] iBitRate Video bitrate parameter in bps.
 *
 * @retval ZOK Set the video bitrate successfully.
 * @retval ZFAILED Set the video bitrate failed.
 *
 * @see @ref Mtc_CallDbGetVideoBitrate
 */
ZFUNC ZINT Mtc_CallDbSetVideoBitrate(ZUINT iBitRate);

/**
 * @brief Get video frame rate.
 *
 * @retval Video frame rate parameter in fps.
 *
 * @see @ref Mtc_CallDbSetVideoFramerate
 */
ZFUNC ZUINT Mtc_CallDbGetVideoFramerate();

/**
 * @brief Set video frame rate.
 *
 * @param [in] iFrameRate Video frame rate parameter in fps.
 *
 * @retval ZOK Set the video frame rate successfully.
 * @retval ZFAILED Set the video frame rate failed.
 *
 * @see @ref Mtc_CallDbGetVideoFramerate
 */
ZFUNC ZINT Mtc_CallDbSetVideoFramerate(ZUINT iFrameRate);

/**
 * @brief Get video resolution.
 *
 * @param [out] piWidth Pixel value in horizontal direction.
 * @param [out] piHeight Pixel value in vertical direction.
 *
 * @retval ZOK Get the video resolution successfully.
 * @retval ZFAILED Get the video resolution failed.
 *
 * @see @ref Mtc_CallDbSetVideoResolution
 */
ZFUNC ZINT Mtc_CallDbGetVideoResolution(ZUINT *piWidth, ZUINT *piHeight);

/**
 * @brief Set video resolution.
 *
 * @param [in] iWidth Pixel value in horizontal direction.
 * @param [in] iHeight Pixel value in vertical direction.
 *
 * @retval ZOK Set the video resolution successfully.
 * @retval ZFAILED Set the video resolution failed.
 *
 * @see @ref Mtc_CallDbGetVideoResolution
 */
ZFUNC ZINT Mtc_CallDbSetVideoResolution(ZUINT iWidth, ZUINT iHeight);

/**
 * @brief Get video resolution.
 *
 * @return The string of video resolution name or "UNKNOWN" failed.
 *
 * @see @ref Mtc_CallDbSetVideoResolutionX
 */
ZFUNC ZCHAR * Mtc_CallDbGetVideoResolutionX();

/**
 * @brief Set video resolution.
 *
 * @param [in] pcName Video resolution name string.
 *
 * @retval ZOK Set the video resolution successfully.
 * @retval ZFAILED Set the video resolution failed.
 *
 * @see @ref Mtc_CallDbGetVideoResolutionX
 */
ZFUNC ZINT Mtc_CallDbSetVideoResolutionX(ZCHAR *pcName);

/**
 * @brief Get send video resolution.
 *
 * @param [out] piWidth Pixel value in horizontal direction.
 * @param [out] piHeight Pixel value in vertical direction.
 *
 * @retval ZOK Get the send video resolution successfully.
 * @retval ZFAILED Get the send video resolution failed.
 *
 * @see @ref Mtc_CallDbSetVideoResolution, Mtc_CallDbSetSendVideoRes
 */
ZFUNC ZINT Mtc_CallDbGetSendVideoRes(ZUINT *piWidth, ZUINT *piHeight);

/**
 * @brief Set send video resolution.
 *       When mdm@ref Mtc_CallDbSetMdmEnable open, 
 *       the function used to set send video resolution.
 *
 * @param [in] iWidth Pixel value in horizontal direction.
 * @param [in] iHeight Pixel value in vertical direction.
 *
 * @retval ZOK Set the send video resolution successfully.
 * @retval ZFAILED Set send the video resolution failed.
 *
 * @see @ref Mtc_CallDbGetVideoResolution, Mtc_CallDbGetSendVideoRes
 */
ZFUNC ZINT Mtc_CallDbSetSendVideoRes(ZUINT iWidth, ZUINT iHeight);

#define VIDEO_QOS_SETTINGS

/**
 * @brief Get media device manager option.
 *
 * @retval ZTRUE Enable media device manager.
 * @retval ZFALSE Disable media device manager.
 *
 * @see @ref Mtc_CallDbSetMdmEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetMdmEnable(ZFUNC_VOID);

/**
 * @brief Set media device manager option.
 *
 * @param [in] bEnable ZTRUE to enable media device manager, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetMdmEnable
 */
ZFUNC ZINT Mtc_CallDbSetMdmEnable(ZBOOL bEnable);

/**
 * @brief Get resolution control of video stream.
 *
 * @retval ZTRUE Resolution control is enabled for video stream.
 * @retval ZFALSE Resolution control is disabled for video stream.
 *
 * @see @ref Mtc_CallDbSetResolutionControl
 */
ZFUNC ZBOOL Mtc_CallDbGetResolutionControl(ZFUNC_VOID);

/**
 * @brief Set resolution control of video stream.
 *
 * @param [in] bEnable ZTRUE to enable resolution control, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetResolutionControl
 */
ZFUNC ZINT Mtc_CallDbSetResolutionControl(ZBOOL bEnable);

/**
 * @brief Set video resolution control mode.
 *
 * @param [in] ucMode Mode of video resolution control, @ref EN_MTC_RES_CTRL_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetVideoResCtrlMode
 */
ZFUNC ZINT Mtc_CallDbSetVideoResCtrlMode(ZUCHAR ucMode);

/**
 * @brief Get video resolution control mode.
 *
 * @return Current video resolution control mode, @ref EN_MTC_RES_CTRL_TYPE.
 *
 * @see Mtc_CallDbSetVideoResCtrlMode
 */
ZFUNC ZUCHAR Mtc_CallDbGetVideoResCtrlMode(ZFUNC_VOID);

/**
 * @brief Get framerate control of video stream.
 *
 * @retval ZTRUE Framerate control is enabled for video stream.
 * @retval ZFALSE Framerate control is disabled for video stream.
 *
 * @see @ref Mtc_CallDbSetFramerateControl
 */
ZFUNC ZBOOL Mtc_CallDbGetFramerateControl(ZFUNC_VOID);

/**
 * @brief Set framerate control of video stream.
 *
 * @param [in] bEnable ZTRUE to enable framerate control, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetFramerateControl
 */
ZFUNC ZINT Mtc_CallDbSetFramerateControl(ZBOOL bEnable);

/**
 * @brief Get CPU load control of video stream.
 *
 * @retval ZTRUE CPU load control is enabled for video stream.
 * @retval ZFALSE CPU load control is disabled for video stream.
 *
 * @see @ref Mtc_CallDbSetCpuLoadControl
 */
ZFUNC ZBOOL Mtc_CallDbGetCpuLoadControl(ZFUNC_VOID);

/**
 * @brief Set CPU load control of video stream.
 *
 * @param [in] bEnable ZTRUE to enable CPU load control, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetCpuLoadControl
 */
ZFUNC ZINT Mtc_CallDbSetCpuLoadControl(ZBOOL bEnable);

/**
 * @brief Get CPU load control of video stream.
 *
 * @return CPU load control target, from 0 to 100.
 *
 * @see @ref Mtc_CallDbSetCpuLoadTarget
 */
ZFUNC ZUINT Mtc_CallDbGetCpuLoadTarget(ZFUNC_VOID);

/**
 * @brief Set CPU load control of video stream.
 *
 * @param [in] iTarget CPU load control target, from 0 to 100.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetCpuLoadTarget
 */
ZFUNC ZINT Mtc_CallDbSetCpuLoadTarget(ZUINT iTarget);

/**
 * @brief Get FIR of video stream.
 *
 * @retval ZTRUE FIR is enabled for video stream.
 * @retval ZFALSE FIR is disabled for video stream.
 *
 * @see @ref Mtc_CallDbSetFir
 */
ZFUNC ZBOOL Mtc_CallDbGetFir(ZFUNC_VOID);

/**
 * @brief Set FIR of video stream.
 *
 * @param [in] bEnable ZTRUE to enable FIR, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetFir
 */
ZFUNC ZINT Mtc_CallDbSetFir(ZBOOL bEnable);

/**
 * @brief Get FIR using INFO method of video stream.
 *
 * @retval ZTRUE FIR using INFO method is enabled for video stream.
 * @retval ZFALSE FIR using INFO method is disabled for video stream.
 *
 * @see @ref Mtc_CallDbSetFirByInfo
 */
ZFUNC ZBOOL Mtc_CallDbGetFirByInfo(ZFUNC_VOID);

/**
 * @brief Set FIR using INFO method of video stream.
 *
 * @param [in] bEnable ZTRUE to enable FIR by INFO method, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetFirByInfo
 */
ZFUNC ZINT Mtc_CallDbSetFirByInfo(ZBOOL bEnable);

/**
 * @brief Get key frame period of video stream.
 *
 * @return Key frame period in milliseconds for video stream.
 *
 * @see @ref Mtc_CallDbSetFramerateControl
 */
ZFUNC ZUINT Mtc_CallDbGetKeyPeriod(ZFUNC_VOID);

/**
 * @brief Set framerate control of video stream.
 *
 * @param [in] iTimeLen Key frame period in milliseconds.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetKeyPeriod
 */
ZFUNC ZINT Mtc_CallDbSetKeyPeriod(ZUINT iTimeLen);

/**
 * @brief Get video key frame repeat count at start.
 *
 * @return Key frame repeat count at start.
 *
 * @see @ref Mtc_CallDbSetKeyRepeat
 */
ZFUNC ZUINT Mtc_CallDbGetKeyRepeat(ZFUNC_VOID);

/**
 * @brief Set video key frame repeat count at start.
 *
 * @param [in] iCount Key frame repeat count at start.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetKeyRepeat
 */
ZFUNC ZINT Mtc_CallDbSetKeyRepeat(ZUINT iCount);

/**
 * @brief Get bandwidth efficiency mode of video stream.
 *
 * @retval ZTRUE BEM is enabled for video stream.
 * @retval ZFALSE BEM is disabled for video stream.
 *
 * @see @ref Mtc_CallDbSetVideoBem
 */
ZFUNC ZBOOL Mtc_CallDbGetVideoBem(ZFUNC_VOID);

/**
 * @brief Set bandwidth efficiency mode of video stream.
 *
 * @param [in] bEnable ZTRUE to enable BEM, otherwise to disable BEM.
 *
 * @retval ZOK Set the video BEM option successfully.
 * @retval ZFAILED Set the video BEM option failed.
 *
 * @see @ref Mtc_CallDbGetVideoBem
 */
ZFUNC ZINT Mtc_CallDbSetVideoBem(ZBOOL bEnable);

/**
 * @brief Get bandwidth for video stream.
 * 
 * @param  [out] piDownBps Downstream bandwidth in bps.
 * @param  [out] piUpBps   Upstream bandwidth in bps.
 * 
 * @retval ZOK Set the video bandwidth option successfully.
 * @retval ZFAILED Set the video bandwidth option failed.
 */
ZFUNC ZINT Mtc_CallDbGetVideoBandwidth(ZUINT *piDownBps, ZUINT *piUpBps);

/**
 * @brief Set bandwidth for video stream.
 *
 * @param  [in] iDownBps Downstream bandwidth in bps.
 * @param  [in] iUpBps   Upstream bandwidth in bps.
 *
 * @retval ZOK Set the video bandwidth option successfully.
 * @retval ZFAILED Set the video bandwidth option failed.
 */
ZFUNC ZINT Mtc_CallDbSetVideoBandwidth(ZUINT iDownBps, ZUINT iUpBps);

/**
 * @brief Get coordination of video orientation is enabled or not for send.
 *
 * @retval ZTRUE Coordination of video orientation is enabled for send.
 * @retval ZFALSE Coordination of video orientation is disabled for send.
 *
 * @see @ref Mtc_CallDbSetVideoOrientSend
 */
ZFUNC ZBOOL Mtc_CallDbGetVideoOrientSend(ZFUNC_VOID);

/**
 * @brief Set coordination of video orientation is enabled or not for send.
 *
 * @param [in] bEnable ZTRUE enable coordination of video orientation for send.
 *
 * @retval ZOK Set option successfully.
 * @retval ZFAILED Set option failed.
 *
 * @see @ref Mtc_CallDbGetVideoOrientSend
 */
ZFUNC ZINT Mtc_CallDbSetVideoOrientSend(ZBOOL bEnable);

/**
 * @brief Get coordination of video orientation is enabled or not for receive.
 *
 * @retval ZTRUE Coordination of video orientation is enabled for receive.
 * @retval ZFALSE Coordination of video orientation is disabled for receive.
 *
 * @see @ref Mtc_CallDbSetVideoOrientRecv
 */
ZFUNC ZBOOL Mtc_CallDbGetVideoOrientRecv(ZFUNC_VOID);

/**
 * @brief Set coordination of video orientation is enabled or not for receive.
 *
 * @param [in] bEnable ZTRUE enable coordination of video orientation for receive.
 *
 * @retval ZOK Set option successfully.
 * @retval ZFAILED Set option failed.
 *
 * @see @ref Mtc_CallDbGetVideoOrientRecv
 */
ZFUNC ZINT Mtc_CallDbSetVideoOrientRecv(ZBOOL bEnable);

/**
 * @brief Get RTP extension ID for coordination of video orientation.
 *
 * @return RTP extension ID.
 *
 * @see @ref Mtc_CallDbSetVideoOrientId
 */
ZFUNC ZUINT Mtc_CallDbGetVideoOrientId(ZFUNC_VOID);

/**
 * @brief Set RTP extension ID for coordination of video orientation.
 *
 * @param [in] iId RTP extension ID.
 *
 * @retval ZOK Set option successfully.
 * @retval ZFAILED Set option failed.
 *
 * @see @ref Mtc_CallDbGetVideoOrientId
 */
ZFUNC ZINT Mtc_CallDbSetVideoOrientId(ZUINT iId);

/**
 * @brief Get ARS option of video stream.
 *
 * @retval ZTRUE ARS is enabled for video stream.
 * @retval ZFALSE ARS is disabled for video stream.
 *
 * @see @ref Mtc_CallDbSetVideoArs
 */
ZFUNC ZBOOL Mtc_CallDbGetVideoArs(ZFUNC_VOID);

/**
 * @brief Set ARS option of video stream.
 *
 * @param [in] bEnable ZTRUE to enable ARS, otherwise to disable ARS.
 *
 * @retval ZOK Set the video ARS option successfully.
 * @retval ZFAILED Set the video ARS option failed.
 *
 * @see @ref Mtc_CallDbGetVideoArs
 */
ZFUNC ZINT Mtc_CallDbSetVideoArs(ZBOOL bEnable);

/**
 * @brief Set mode of ARS.
 *
 * @param [in] ucMode Mode of ARS, @ref EN_MTC_ARS_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_CallDbGetArsMode
 */
ZFUNC ZINT Mtc_CallDbSetArsMode(ZUCHAR ucMode);

/**
 * @brief Get mode of ARS.
 *
 * @return Current ARS mode, @ref EN_MTC_ARS_TYPE.
 *
 * @see Mtc_CallDbSetArsMode
 */
ZFUNC ZUCHAR Mtc_CallDbGetArsMode(ZFUNC_VOID);

/**
 * @brief Get ARS parameter from database.
 *
 * @param [out] piBrHi Highest bitrate.
 * @param [out] piBrLo Lowest bitrate.
 * @param [out] piFrHi Highest framerate.
 * @param [out] piFrLo Lowest framerate.

 * @retval ZOK Get successfully.
 * @retval ZFAILED Get failed.
 *
 * @see @ref Mtc_CallDbSetVideoArsParm
 */
ZFUNC ZINT Mtc_CallDbGetVideoArsParm(ZUINT * piBrHi, ZUINT * piBrLo,
                ZUINT * piFrHi, ZUINT * piFrLo);

/**
 * @brief Set ARS parameter.
 *
 * @param [in] iBrHi Highest bitrate.
 * @param [in] iBrLo Lowest bitrate.
 * @param [in] iFrHi Highest framerate.
 * @param [in] iFrLo Lowest framerate.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetVideoArsParm
 */
ZFUNC ZINT Mtc_CallDbSetVideoArsParm(ZUINT iBrHi, ZUINT iBrLo,
                ZUINT iFrHi, ZUINT iFrLo);

/**
 * @brief Set ARS parameter.
 *
 * @param [in] bNetWorkType the network type.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_CallDbGetVideoArsParm
 */
ZFUNC ZINT Mtc_CallDbSetVideoArsParmX(ZBOOL bNetWorkType);

/**
 * @brief Get the video FEC type.
 *
 * @return The video FEC type @ref MTC EN_MTC_DB_FEC_TYPE.
 *
 * @see @ref Mtc_CallDbSetVideoFecType
 */
ZFUNC ZUINT Mtc_CallDbGetVideoFecType(ZFUNC_VOID);

/**
 * @brief Set the video FEC type.
 *
 * @param [in] iType The video FEC type.  FEC type @ref EN_MTC_DB_FEC_TYPE.
 *
 * @retval ZOK Set the video FEC type successfully.
 * @retval ZFAILED Set the video FEC type failed.
 *
 * @see @ref Mtc_CallDbGetVideoFecType
 */
ZFUNC ZINT Mtc_CallDbSetVideoFecType(ZUINT iType);

#define RTP_RTCP_SETTINGS

/**
 * @brief Get RTCP option from database.
 *
 * @retval ZTRUE Start RTCP.
 * @retval ZFALSE Do not start RTCP.
 *
 * @see @ref Mtc_CallDbSetRtcpEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetRtcpEnable(ZFUNC_VOID);

/**
 * @brief Set RTCP option.
 *
 * @param [in] bEnable RTCP option.
 *
 * @retval ZOK Set RTCP option successfully.
 * @retval ZFAILED Set RTCP option failed.
 *
 * @see @ref Mtc_CallDbGetRtcpEnable
 */
ZFUNC ZINT Mtc_CallDbSetRtcpEnable(ZBOOL bEnable);

/**
 * @brief Get RTP port from database.
 *
 * @param [out] pwAMinPort RTP audio min port.
 * @param [out] pwAMaxPort RTP audio max port.
 * @param [out] pwVMinPort RTP video min port.
 * @param [out] pwVMaxPort RTP video max port.

 * @retval ZOK Get RTP port successfully.
 * @retval ZFAILED Get RTP port failed.
 *
 * @see @ref Mtc_CallDbSetRtpPort
 */
ZFUNC ZINT Mtc_CallDbGetRtpPort(ZUSHORT *pwAMinPort, ZUSHORT *pwAMaxPort, 
                ZUSHORT *pwVMinPort, ZUSHORT *pwVMaxPort);

/**
 * @brief Set RTP port.
 *
 * @param [in] wAMinPort RTP audio min port.
 * @param [in] wAMaxPort RTP audio max port.
 * @param [in] wVMinPort RTP video min port.
 * @param [in] wVMaxPort RTP video max port.
 *
 * @retval ZOK Set RTP port successfully.
 * @retval ZFAILED Set RTP port failed.
 *
 * @see @ref Mtc_CallDbGetRtpPort
 */
ZFUNC ZINT Mtc_CallDbSetRtpPort(ZUSHORT wAMinPort, ZUSHORT wAMaxPort, 
                ZUSHORT wVMinPort, ZUSHORT wVMaxPort);

/**
 * @brief Get RTP break detection time length in seconds from database.
 *
 * @return RTP break detection time length.
 *
 * @see Mtc_CallDbSetRtpBreakTime
 */
ZFUNC ZUINT Mtc_CallDbGetRtpBreakTime(ZFUNC_VOID);

/**
 * @brief Set RTP break detection time length in seconds.
 *
 * @param [in] iTimeLen RTP break detection time length in seconds.
 *
 * @retval ZOK Set RTP break detection time length successfully.
 * @retval ZFAILED Set RTP break detection time length failed.
 *
 * @see Mtc_CallDbGetRtpBreakTime
 */
ZFUNC ZINT Mtc_CallDbSetRtpBreakTime(ZUINT iTimeLen);

#define SRTP_SETTINGS

/**
 * @brief Get SRTP crypto type from database.
 *
 * @return SRTP crypto type, @ref EN_MTC_DB_SRTP_CRYPTO_TYPE.
 *
 * @see Mtc_CallDbSetSrtpCryptoType
 */
ZFUNC ZUINT Mtc_CallDbGetSrtpCryptoType(ZFUNC_VOID);

/**
 * @brief Set SRTP crypto type.
 *
 * @param [in] iType SRTP crypto type, @ref EN_MTC_DB_SRTP_CRYPTO_TYPE.
 *
 * @retval ZOK Set SRTP crypto type successfully.
 * @retval ZFAILED Set SRTP crypto type failed.
 *
 * @see Mtc_CallDbGetSrtpCryptoType
 */
ZFUNC ZINT Mtc_CallDbSetSrtpCryptoType(ZUINT iType);

/**
 * @brief Get authenticated SRTP option from database.
 *
 * @retval ZTRUE Enable authenticated SRTP.
 * @retval ZFALSE Disable authenticated SRTP.
 *
 * @see @ref Mtc_CallDbSetSrtpAuthRtp
 */
ZFUNC ZBOOL Mtc_CallDbGetSrtpAuthRtp(ZFUNC_VOID);

/**
 * @brief Set authenticated SRTP option.
 *
 * @param [in] bEnable ZTRUE to enable authenticated SRTP, ZFALSE to disable.
 *
 * @retval ZOK Set authenticated SRTP option successfully.
 * @retval ZFAILED Set authenticated SRTP option failed.
 *
 * @see @ref Mtc_CallDbGetSrtpAuthRtp
 */
ZFUNC ZINT Mtc_CallDbSetSrtpAuthRtp(ZBOOL bEnable);

/**
 * @brief Get encrypted SRTP option from database.
 *
 * @retval ZTRUE Enable encrypted SRTP.
 * @retval ZFALSE Disable encrypted SRTP.
 *
 * @see @ref Mtc_CallDbSetSrtpEncryptRtp
 */
ZFUNC ZBOOL Mtc_CallDbGetSrtpEncryptRtp(ZFUNC_VOID);

/**
 * @brief Set encrypted SRTP option.
 *
 * @param [in] bEnable ZTRUE to enable encrypted SRTP, ZFALSE to disable.
 *
 * @retval ZOK Set encrypted SRTP option successfully.
 * @retval ZFAILED Set encrypted SRTP option failed.
 *
 * @see @ref Mtc_CallDbGetSrtpEncryptRtp
 */
ZFUNC ZINT Mtc_CallDbSetSrtpEncryptRtp(ZBOOL bEnable);

/**
 * @brief Get encrypted SRTCP option from database.
 *
 * @retval ZTRUE Enable encrypted SRTCP.
 * @retval ZFALSE Disable encrypted SRTCP.
 *
 * @see @ref Mtc_CallDbSetSrtpEncryptRtcp
 */
ZFUNC ZBOOL Mtc_CallDbGetSrtpEncryptRtcp(ZFUNC_VOID);

/**
 * @brief Set encrypted SRTCP option.
 *
 * @param [in] bEnable ZTRUE to enable encrypted SRTCP, ZFALSE to disable.
 *
 * @retval ZOK Set encrypted SRTCP option successfully.
 * @retval ZFAILED Set encrypted SRTCP option failed.
 *
 * @see @ref Mtc_CallDbGetSrtpEncryptRtcp
 */
ZFUNC ZINT Mtc_CallDbSetSrtpEncryptRtcp(ZBOOL bEnable);

#define TRANSPORT_PARAMETER_SETTINGS

/**
 * @brief Get NACK option from database.
 *
 * @retval ZTRUE Start NACK.
 * @retval ZFALSE Do not start NACK.
 *
 * @see @ref Mtc_CallDbSetNackEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetNackEnable(ZFUNC_VOID);

/**
 * @brief Set NACK option.
 *
 * @param [in] bEnable NACK option.
 *
 * @retval ZOK Set NACK option successfully.
 * @retval ZFAILED Set NACK option failed.
 *
 * @see @ref Mtc_CallDbGetNackEnable
 */
ZFUNC ZINT Mtc_CallDbSetNackEnable(ZBOOL bEnable);

/**
 * @brief Get RTX option from database.
 *
 * @retval ZTRUE Start RTX.
 * @retval ZFALSE Do not start RTX.
 *
 * @see @ref Mtc_CallDbSetRtxEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetRtxEnable(ZFUNC_VOID);

/**
 * @brief Set RTX option.
 *
 * @param [in] bEnable RTX option.
 *
 * @retval ZOK Set RTX option successfully.
 * @retval ZFAILED Set RTX option failed.
 *
 * @see @ref Mtc_CallDbGetRtxEnable
 */
ZFUNC ZINT Mtc_CallDbSetRtxEnable(ZBOOL bEnable);

/**
 * @brief Get TMMBR option from database.
 *
 * @retval ZTRUE Start TMMBR.
 * @retval ZFALSE Do not start TMMBR.
 *
 * @see @ref Mtc_CallDbSetTmmbrEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetTmmbrEnable(ZFUNC_VOID);

/**
 * @brief Set TMMBR option.
 *
 * @param [in] bEnable TMMBR option.
 *
 * @retval ZOK Set TMMBR option successfully.
 * @retval ZFAILED Set TMMBR option failed.
 *
 * @see @ref Mtc_CallDbGetTmmbrEnable
 */
ZFUNC ZINT Mtc_CallDbSetTmmbrEnable(ZBOOL bEnable);

/**
 * @brief Get audio rtcp-mux option from database.
 *
 * @retval ZTRUE Start audio rtcp-mux.
 * @retval ZFALSE Do not start audio rtcp-mux.
 *
 * @see @ref Mtc_CallDbSetAudioRtcpMuxEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetAudioRtcpMuxEnable(ZFUNC_VOID);

/**
 * @brief Set audio rtcp-mux option.
 *
 * @param [in] bEnable audio rtcp-mux option.
 *
 * @retval ZOK Set audio rtcp-mux option successfully.
 * @retval ZFAILED Set audio rtcp-mux option failed.
 *
 * @see @ref Mtc_CallDbGetAudioRtcpMuxEnable
 */
ZFUNC ZINT Mtc_CallDbSetAudioRtcpMuxEnable(ZBOOL bEnable);

/**
 * @brief Get video rtcp-mux option from database.
 *
 * @retval ZTRUE Start video rtcp-mux.
 * @retval ZFALSE Do not start video rtcp-mux.
 *
 * @see @ref Mtc_CallDbSetVideoRtcpMuxEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetVideoRtcpMuxEnable(ZFUNC_VOID);

/**
 * @brief Set video rtcp-mux option.
 *
 * @param [in] bEnable video rtcp-mux option.
 *
 * @retval ZOK Set video rtcp-mux option successfully.
 * @retval ZFAILED Set video rtcp-mux option failed.
 *
 * @see @ref Mtc_CallDbGetVideoRtcpMuxEnable
 */
ZFUNC ZINT Mtc_CallDbSetVideoRtcpMuxEnable(ZBOOL bEnable);

/**
 * @brief Get RPSI option from database.
 *
 * @retval ZTRUE Start RPSI.
 * @retval ZFALSE Do not start RPSI.
 *
 * @see @ref Mtc_CallDbSetRpsiEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetRpsiEnable(ZFUNC_VOID);

/**
 * @brief Set RPSI option.
 *
 * @param [in] bEnable RPSI option.
 *
 * @retval ZOK Set RPSI option successfully.
 * @retval ZFAILED Set RPSI option failed.
 *
 * @see @ref Mtc_CallDbGetRpsiEnable
 */
ZFUNC ZINT Mtc_CallDbSetRpsiEnable(ZBOOL bEnable);

/**
 * @brief Get small NALU option from database.
 *
 * @retval ZTRUE Enable small NALU.
 * @retval ZFALSE Disable small NALU.
 *
 * @see @ref Mtc_CallDbSetSmallNaluEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetSmallNaluEnable(ZFUNC_VOID);

/**
 * @brief Set small NALU option.
 *
 * @param [in] bEnable Small NALU option.
 *
 * @retval ZOK Set small NALU option successfully.
 * @retval ZFAILED Set small NALU option failed.
 *
 * @see @ref Mtc_CallDbGetSmallNaluEnable
 */
ZFUNC ZINT Mtc_CallDbSetSmallNaluEnable(ZBOOL bEnable);

/**
 * @brief Get packet time length from database.
 *
 * @return Packet time length.
 *
 * @see Mtc_CallDbSetPtime
 */
ZFUNC ZUINT Mtc_CallDbGetPtime(ZFUNC_VOID);

/**
 * @brief Set packet time length.
 *
 * @param [in] iTimeLen Max packet time length.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see Mtc_CallDbGetPtime
 */
ZFUNC ZINT Mtc_CallDbSetPtime(ZUINT iTimeLen);

/**
 * @brief Get max packet time length from database.
 *
 * @return Max packet time length.
 *
 * @see Mtc_CallDbSetMaxPtime
 */
ZFUNC ZUINT Mtc_CallDbGetMaxPtime(ZFUNC_VOID);

/**
 * @brief Set max packet time length.
 *
 * @param [in] iTimeLen Max packet time length.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see Mtc_CallDbGetMaxPtime
 */
ZFUNC ZINT Mtc_CallDbSetMaxPtime(ZUINT iTimeLen);

 /**
 * @brief Get max packet time enable flag from database.
 *
 * @retval ZTRUE Enable max packet time.
 * @retval ZFALSE Do not enable max packet time.
 *
 * @see @ref Mtc_CallDbSetMaxPtimeEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetMaxPtimeEnable(ZFUNC_VOID);

/**
 * @brief Set max packet time enable.
 *
 * @param [in] bEnable Max packet time enable.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option failed.
 *
 * @see @ref Mtc_CallDbGetMaxPtimeEnable
 */
ZFUNC ZINT Mtc_CallDbSetMaxPtimeEnable(ZBOOL bEnable);

#define SERVICE_SETTINGS

/**
 * @brief Get the automatically accepted call option from database.
 *
 * @retval ZTRUE Accept call automatically.
 * @retval ZFALSE Do not accept call automatically.
 *
 * @see @ref Mtc_CallDbSetAutoAcptCall
 */
ZFUNC ZBOOL Mtc_CallDbGetAutoAcptCall(ZFUNC_VOID);

/**
 * @brief Set the automatically accepted call option.
 *
 * @param [in] bEnable Automatically accepted call option.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option failed.
 *
 * @see @ref Mtc_CallDbGetAutoAcptCall
 */
ZFUNC ZINT Mtc_CallDbSetAutoAcptCall(ZBOOL bEnable);

/**
 * @brief Get the callin while calling option from database.
 *
 * @retval ZTRUE Enable callin while calling.
 * @retval ZFALSE Disable callin while calling.
 *
 * @see @ref Mtc_CallDbSetCwc
 */
ZFUNC ZBOOL Mtc_CallDbGetCwc(ZFUNC_VOID);

/**
 * @brief Set the callin while calling option.
 *
 * @param [in] bEnable Enable callin while calling.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option failed.
 *
 * @see @ref Mtc_CallDbGetCwc
 */
ZFUNC ZINT Mtc_CallDbSetCwc(ZBOOL bEnable);

/**
 * @brief Get the do not disturb option from database.
 *
 * @retval ZTRUE Do not disturb.
 * @retval ZFALSE Normal.
 *
 * @see @ref Mtc_CallDbSetDoNotDisturb
 */
ZFUNC ZBOOL Mtc_CallDbGetDoNotDisturb(ZFUNC_VOID);

/**
 * @brief Set the do not disturb option.
 *
 * @param [in] bEnable The do not disturb option.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option failed.
 *
 * @see @ref Mtc_CallDbGetDoNotDisturb
 */
ZFUNC ZINT Mtc_CallDbSetDoNotDisturb(ZBOOL bEnable);

/**
 * @brief Get the call forward unconditional information.
 *
 * @param [out] ppcUri Unconditional call forward uri.
 *
 * @retval ZTRUE Call forword on uncoditional enabled.
 * @retval ZFALSE Call forword on uncoditional disabled.
 *
 * @see @ref Mtc_CallDbSetCfuInfo
 */
ZFUNC ZBOOL Mtc_CallDbGetCfuInfo(ZCHAR **ppcUri);

/**
 * @brief Set the call forward unconditional information.
 *
 * @param [in] bEnable Unconditional call forward option.
 * @param [in] pcUri Unconditional call forward URI.
 *
 * @retval ZOK Set call forward unconditional information successfully.
 * @retval ZFAILED Set call forward unconditional information failed.
 *
 * @see @ref Mtc_CallDbGetCfuInfo
 */
ZFUNC ZINT Mtc_CallDbSetCfuInfo(ZBOOL bEnable, ZCHAR *pcUri);

/**
 * @brief Get the call forward on busy information.
 *
 * @param [out] ppcUri On busy call forward uri.
 *
 * @retval ZTRUE Call forword on busy enabled.
 * @retval ZFALSE Call forword on busy disabled.
 *
 * @see @ref Mtc_CallDbSetCfbInfo
 */
ZFUNC ZBOOL Mtc_CallDbGetCfbInfo(ZCHAR **ppcUri);

/**
 * @brief Set the call forward on busy information.
 *
 * @param [in] bEnable On busy call forward option.
 * @param [in] pcUri On busy call forward URI.
 *
 * @retval ZOK Set call forward on busy information successfully.
 * @retval ZFAILED Set call forward on busy information failed.
 *
 * @see @ref Mtc_CallDbGetCfbInfo
 */
ZFUNC ZINT Mtc_CallDbSetCfbInfo(ZBOOL bEnable, ZCHAR *pcUri);

/**
 * @brief Get call forward on no answer information.
 *
 * @param [out] ppcUri No answer call forward uri.
 * @param [out] piWaitLen No answer call forward wait time length.
 *
 * @retval ZTRUE Call forword on no answer enabled.
 * @retval ZFALSE Call forword on no answer disabled.
 *
 * @see @ref Mtc_CallDbSetCfnaInfo
 */
ZFUNC ZBOOL Mtc_CallDbGetCfnaInfo(ZCHAR **ppcUri, ZUINT *piWaitLen);

/**
 * @brief Set call forward no answer information.
 *
 * @param [in] bEnable No answer call forward option.
 * @param [in] pcUri No answer call forward URI.
 * @param [in] iWaitLen No answer call forward wait time length.
 *
 * @retval ZOK Set call forward no answer information successfully.
 * @retval ZFAILED Set call forward no answer information failed.
 *
 * @see @ref Mtc_CallDbGetCfnaInfo
 */
ZFUNC ZINT Mtc_CallDbSetCfnaInfo(ZBOOL bEnable, ZCHAR *pcUri,
                ZUINT iWaitLen);

/**
 * @brief Get privacy option from database.
 *
 * @param [in] ucOpt Privacy option type, it can be one of MTC_PRIVACY_NONE,
 *                   MTC_PRIVACY_ID, MTC_PRIVACY_HEADER, MTC_PRIVACY_SESSION
 *                   and MTC_PRIVACY_CRITICAL.
 *
 * @retval ZTRUE Corresponding privacy option is enable.
 * @retval ZFALSE Corresponding privacy option is disable.
 *
 * @see @ref Mtc_CallDbSetPrivacyOpt
 */
ZFUNC ZBOOL Mtc_CallDbGetPrivacyOpt(ZUCHAR ucOpt);

/**
 * @brief Set privacy option from database.
 *
 * @param [in] ucOpt Privacy option type, it can be one of MTC_PRIVACY_NONE,
 *                   MTC_PRIVACY_ID, MTC_PRIVACY_HEADER, MTC_PRIVACY_SESSION
 *                   and MTC_PRIVACY_CRITICAL.
 * @param [in] bEnable ZTRUE to enable corresponding privacy option.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option option failed.
 *
 * @see @ref Mtc_CallDbGetPrivacyOpt
 */
ZFUNC ZINT Mtc_CallDbSetPrivacyOpt(ZUCHAR ucOpt, ZBOOL bEnable);

/**
 * @brief Get symmetrical negotiation from database.
 *
 * @retval ZTRUE Symmetrical negotiation is enable.
 * @retval ZFALSE Symmetrical negotiation is disable.
 *
 * @see @ref Mtc_CallDbSetSymNego
 */
ZFUNC ZBOOL Mtc_CallDbGetSymNego();

/**
 * @brief Set symmetrical negotiation.
 *
 * @param [in] bEnable ZTRUE to enable symmetrical negotiation.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option option failed.
 *
 * @see @ref Mtc_CallDbGetSymNego
 */
ZFUNC ZINT Mtc_CallDbSetSymNego(ZBOOL bEnable);

/**
 * @brief Get session timer information.
 *
 * @param [out] piType Session timer type, @ref EN_MTC_DB_SESSION_TIME_TYPE.
 * @param [out] piRefresherType Session timer refresher type, @ref EN_MTC_DB_REFRESHER_TYPE.
 * @param [out] piTmrLen Session timer length.
 * @param [out] piMinTmrLen Min session timer length.
 *
 * @retval ZTRUE Get session timer information successfully.
 * @retval ZFALSE Get session timer information failed.
 *
 * @see @ref Mtc_CallDbSetSessTmrInfo
 */
ZFUNC ZINT Mtc_CallDbGetSessTmrInfo(ZUINT *piType, ZUINT *piRefresherType,
                ZUINT *piTmrLen, ZUINT *piMinTmrLen);

/**
 * @brief Set session timer information.
 *
 * @param [in] iType Session timer type, @ref EN_MTC_DB_SESSION_TIME_TYPE.
 * @param [in] iRefresherType Session timer refresher type, @ref EN_MTC_DB_REFRESHER_TYPE.
 * @param [in] iTmrLen Session timer length.
 * @param [in] iMinTmrLen Min session timer length.
 *
 * @retval ZOK Set the session timer successfully.
 * @retval ZFAILED Set the session timer failed.
 *
 * @see @ref Mtc_CallDbGetSymNego
 */
ZFUNC ZINT Mtc_CallDbSetSessTmrInfo(ZUINT iType, ZUINT iRefresherType,
                ZUINT iTmrLen, ZUINT iMinTmrLen);

/**
 * @brief Get the Dscp Value of Voice Call service.
 *
 * @retval The Dscp Value of Voice Call service.
 * 
 * @see @ref Mtc_CallDbSetVoiceDscpValue
 */
ZFUNC ZUINT Mtc_CallDbGetVoiceDscpValue();

/**
 * @brief Get the Dscp Value of Video Call service.
 *
 * @retval The Dscp Value of Video Call service.
 * 
 * @see @ref Mtc_CallDbSetVideoDscpValue
 */
ZFUNC ZUINT Mtc_CallDbGetVideoDscpValue();

/**
 * @brief Get the authorization for user to use best effort IP Voice Call service.
 *
 * @retval 0 Indicates that best effort IP Voice Call service is disabled.
 * @retval 1 Indicates that best effort IP Voice Call service is enabled for 
 *   non-3GPP/non-3GPP2 access only (e.g. Wi-Fi, xDSL).
 * @retval 2 Indicates that best effort IP Voice Call service is enabled for  
 *   non-3GPP/non-3GPP2 access (e.g. Wi-Fi, xDSL) and for LTE access.
 * @retval 3 Indicates that best effort IP Voice Call service is enabled for  
 *   non-3GPP/non-3GPP2 access (e.g. Wi-Fi, xDSL) and for LTE/HSPA access.
 * @retval 4 Indicates that best effort IP Voice Call service is enabled for ANY 
 *   access except 2G access.
 *
 * @see @ref Mtc_CallDbSetRcsIpVoiceCallAuth
 */
ZFUNC ZUINT Mtc_CallDbGetRcsIpVoiceCallAuth(ZFUNC_VOID);

/**
 * @brief Get the authorization for user to use best effort IP Video Call service.
 *
 * @retval 0 Indicates that best effort IP Video Call service is disabled.
 * @retval 1 Indicates that best effort IP Video Call service is enabled for 
 *   non-3GPP/non-3GPP2 access only (e.g. Wi-Fi, xDSL).
 * @retval 2 Indicates that best effort IP Video Call service is enabled for  
 *   non-3GPP/non-3GPP2 access (e.g. Wi-Fi, xDSL) and for LTE access.
 * @retval 3 Indicates that best effort IP Video Call service is enabled for  
 *   non-3GPP/non-3GPP2 access (e.g. Wi-Fi, xDSL) and for LTE/HSPA access.
 * @retval 4 Indicates that best effort IP Video Call service is enabled for ANY 
 *   access except 2G access.
 *
 * @see @ref Mtc_CallDbSetRcsIpVideoCallAuth
 */
ZFUNC ZUINT Mtc_CallDbGetRcsIpVideoCallAuth(ZFUNC_VOID);

/**
 * @brief Get a device in RCS-AA mode whether it can initiate Voice calls even if the 
 *   recipient user does not show service capability for voice calls.
 *   It is required in devices that can function in RCS-AA mode.
 *   It will not be instantiated if the service provider does not support the best effort IP 
 *   Voice Call service.
 *
 * @retval ZTRUE Indicates an IP Voice Call cannot be initiated if an error (480/404) 
 *   is returned to a request for the recipient user's service capabilities or service capabilities 
 *   do not indicate the support of IP Voice Call.
 * @retval ZFALSE Indicates an IP Voice Call to be initiated even if an error (480/404) 
 *   is returned to a request for the recipient user?s service capabilities or service capabilities 
 *   do not indicate the support of IP Voice Call.
 *
 * @see @ref Mtc_CallDbSetIpCallBreakOut
 */
ZFUNC ZBOOL Mtc_CallDbGetIpCallBreakOut(ZFUNC_VOID);

/**
 * @brief Get a device in RCS-CS mode whether it can initiate Voice calls even if the 
 *   recipient user does not show service capability for voice calls.
 *   It is required in devices that can function in RCS-CS mode.
 *   It will not be instantiated if the service provider does not support the best effort IP 
 *   Voice Call service.
 *
 * @retval ZTRUE Indicates an IP Voice Call cannot be initiated if an error (480/404) 
 *   is returned to a request for the recipient user's service capabilities or service capabilities 
 *   do not indicate the support of IP Voice Call.
 * @retval ZFALSE Indicates an IP Voice Call to be initiated even if an error (480/404) 
 *   is returned to a request for the recipient user's service capabilities or service capabilities 
 *   do not indicate the support of IP Voice Call.
 *
 * @see @ref Mtc_CallDbSetIpCallBreakOutCs
 */
ZFUNC ZBOOL Mtc_CallDbGetIpCallBreakOutCs(ZFUNC_VOID);

/**
 * @brief Get a device in RCS-CS mode whether it can offer to upgrade a CS call to 
 *   an IP Video Call.
 *   It is required in devices that can function in RCS-CS mode.
 *   It is will not be instantiated if the service provider does not support the IP Video Call service.
 *
 * @retval ZTRUE Indicates allow upgrade of CS Voice call to best effort IP Video Call.
 * @retval ZFALSE does not allow upgrade of CS Voice call to best effort IP Video Call.
 *
 * @see @ref Mtc_CallDbSetVCallUpgFromCs
 */
ZFUNC ZBOOL Mtc_CallDbGetVCallUpgFromCs(ZFUNC_VOID);

/**
 * @brief Get an RCS-CS device whether it can initiate a best effort IP Video Call 
 *   upgrade without first tearing down the CS voice call.
 *   It is required in devices that can function in RCS-CS mode.
 *   It is will not be instantiated if the service provider does not support the IP Video Call service.
 *
 * @retval ZTRUE Indicates a best effort IP Video Call can be initiated even before the CS voice 
 *    call is torn down.
 * @retval ZFALSE Indicates a best effort IP Video Call can only be initiated once the CS voice 
 *   call has been torn down.
 *
 * @see @ref Mtc_CallDbSetVCallUpgAttemptEarly
 */
ZFUNC ZBOOL Mtc_CallDbGetVCallUpgAttemptEarly(ZFUNC_VOID);

/**
 * @brief Get an RCS-AA or RCS-CS device whether it can initiate a best effort IP 
 *   Video Call upgrade even if service capability exchange fails with 480 Temporarily 
 *   Unavailable or 408 Timeout.
 *   It is required in devices that can function in RCS-AA mode or in RCS-CS mode.
 *   It is will not be instantiated if the service provider does not support the IP Video Call service.
 *
 * @retval ZTRUE Indicates a best effort IP Video Call can be initiated even if 
 *   480/408 error is returned.
 * @retval ZFALSE Indicates a best effort IP Video Call can only be initiated if the capability is 
 *   returned from the request for the recipient user's service capabilities.
 *
 * @see @ref Mtc_CallDbSetVCallUpgOnCapError
 */
ZFUNC ZBOOL Mtc_CallDbGetVCallUpgOnCapError(ZFUNC_VOID);

/**
 * @brief Set the Dscp Value of Voice Call service.
 *
 * @param [in] iVoiceDscpValue The Dscp Value of Voice Call service.the value range is 0~63.
 *
 * @retval ZOK Set Dscp Value of Voice Call service successfully.
 * @retval ZFAILED Set Dscp Value of Voice Call service failed.
 *
 * @see @ref Mtc_CallDbGetVoiceDscpValue
 */
ZFUNC ZINT Mtc_CallDbSetVoiceDscpValue(ZUINT iVoiceDscpValue);

/**
 * @brief Set the Dscp Value of Video Call service.
 *
 * @param [in] iVoiceDscpValue The Dscp Value of Video Call service.the value range is 0~63.
 *
 * @retval ZOK Set Dscp Value of Video Call service successfully.
 * @retval ZFAILED Set Dscp Value of Video Call service failed.
 *
 * @see @ref Mtc_CallDbGetVideoDscpValue
 */
ZFUNC ZINT Mtc_CallDbSetVideoDscpValue(ZUINT iVideoDscpValue);

/**
 * @brief Set the authorization for user to use best effort IP Voice Call service.
 *
 * @param [in] iRcsIpVoiceCallAuth The best effort IP Voice Call service type.
 *
 * @retval ZOK Set IP Voice Call service type successfully.
 * @retval ZFAILED Set IP Voice Call service type failed.
 *
 * @see @ref Mtc_CallDbGetRcsIpVoiceCallAuth
 */
ZFUNC ZINT Mtc_CallDbSetRcsIpVoiceCallAuth(ZUINT iRcsIpVoiceCallAuth);

/**
 * @brief Set the authorization for user to use best effort IP Video Call service.
 *
 * @param [in] iRcsIpVideoCallAuth The best effort IP Video Call service type.
 *
 * @retval ZOK Set IP Video Call service type successfully.
 * @retval ZFAILED Set IP Video Call service type failed.
 *
 * @see @ref Mtc_CallDbGetRcsIpVideoCallAuth
 */
ZFUNC ZINT Mtc_CallDbSetRcsIpVideoCallAuth(ZUINT iRcsIpVideoCallAuth);

/**
 * @brief Set a device in RCS-AA mode whether it can initiate Voice calls even if the 
 *   recipient user does not show service capability for voice calls.
 *   It is required in devices that can function in RCS-AA mode.
 *   It will not be instantiated if the service provider does not support the best effort IP 
 *   Voice Call service.
 *
 * @param [in] bIpCallBreakOut The initiate Voice calls enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_CallDbGetIpCallBreakOut
 */
ZFUNC ZINT Mtc_CallDbSetIpCallBreakOut(ZBOOL bIpCallBreakOut);

/**
 * @brief Set a device in RCS-CS mode whether it can initiate Voice calls even if the 
 *   recipient user does not show service capability for voice calls.
 *   It is required in devices that can function in RCS-CS mode.
 *   It will not be instantiated if the service provider does not support the best effort IP 
 *   Voice Call service.
 *
 * @param [in] bIpCallBreakOutCs The initiate Voice calls enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_CallDbGetIpCallBreakOutCs
 */
ZFUNC ZINT Mtc_CallDbSetIpCallBreakOutCs(ZBOOL bIpCallBreakOutCs);

/**
 * @brief Set a device in RCS-CS mode whether it can offer to upgrade a CS call to 
 *   an IP Video Call.
 *   It is required in devices that can function in RCS-CS mode.
 *   It is will not be instantiated if the service provider does not support the IP Video Call service.
 *
 * @param [in] bVCallUpgFromCs The upgrade enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_CallDbGetVCallUpgFromCs
 */
ZFUNC ZINT Mtc_CallDbSetVCallUpgFromCs(ZBOOL bVCallUpgFromCs);

/**
 * @brief Set an RCS-CS device whether it can initiate a best effort IP Video Call 
 *   upgrade without first tearing down the CS voice call.
 *   It is required in devices that can function in RCS-CS mode.
 *   It is will not be instantiated if the service provider does not support the IP Video Call service.
 *
 * @param [in] bVCallUpgAttemptEarly The upgrade enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_CallDbGetVCallUpgAttemptEarly
 */
ZFUNC ZINT Mtc_CallDbSetVCallUpgAttemptEarly(ZBOOL bVCallUpgAttemptEarly);

/**
 * @brief Set an RCS-AA or RCS-CS device whether it can initiate a best effort IP 
 *   Video Call upgrade even if service capability exchange fails with 480 Temporarily 
 *   Unavailable or 408 Timeout.
 *   It is required in devices that can function in RCS-AA mode or in RCS-CS mode.
 *   It is will not be instantiated if the service provider does not support the IP Video Call service.
 *
 * @param [in] bVCallUpgOnCapError The upgrade enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_CallDbGetVCallUpgOnCapError
 */
ZFUNC ZINT Mtc_CallDbSetVCallUpgOnCapError(ZBOOL bVCallUpgOnCapError);

/**
 * @brief Get call prefix content.
 *
 * @return The string of call prefix content.
 *
 * @see @ref Mtc_CallDbSetPrefixCont
 */
ZFUNC ZCHAR * Mtc_CallDbGetPrefixCont(ZFUNC_VOID);

/**
 * @brief Set call prefix content.
 *
 * @param [in] pcPrefixCont Call prefix content.
 *
 * @retval ZOK Set the call prefix content successfull.
 * @retval ZFAILED Set the call prefix content failed.
 *
 * @see @ref Mtc_CallDbGetPrefixCont
 */
ZFUNC ZINT Mtc_CallDbSetPrefixCont(ZCHAR *pcPrefixCont);

/**
 * @brief Get call prefix option.
 *
 * @return The call prefix option, @ref EN_MTC_DB_PREFIX_OPT_TYPE.
 *
 * @see @ref Mtc_CallDbGetPrefixOption
 */
ZFUNC ZUINT Mtc_CallDbGetPrefixOption(ZFUNC_VOID);

/**
 * @brief Set call prefix option.
 *
 * @param [in] iPrefixOpt Call prefix option, @ref EN_MTC_DB_PREFIX_OPT_TYPE.
 *
 * @retval ZOK Set the call prefix option successfull.
 * @retval ZFAILED Set the call prefix option failed.
 *
 * @see @ref Mtc_CallDbGetPrefixOption
 */
ZFUNC ZINT Mtc_CallDbSetPrefixOption(ZUINT iPrefixOpt);

/**
 * @brief Get the p-asserted-identity policy.
 *
 * @return The call p-asserted-identity policy, @ref EN_MTC_DB_PAI_POLICY_TYPE.
 *
 * @see @ref Mtc_CallDbSetPAIPolicy
 */
ZFUNC ZUINT Mtc_CallDbGetPAIPolicy(ZFUNC_VOID);

/**
 * @brief Set the p-asserted-identity policy.
 *
 * @param [in] iPAIPolicy p-asserted-identity policy, @ref EN_MTC_DB_PAI_POLICY_TYPE.
 *
 * @retval ZOK Set the p-asserted-identity policy successfull.
 * @retval ZFAILED Set the p-asserted-identity policy failed.
 *
 * @see @ref Mtc_CallDbGetPAIPolicy
 */
ZFUNC ZINT Mtc_CallDbSetPAIPolicy(ZUINT iPAIPolicy);

/**
 * @brief Set RTP packet report option.
 *
 * @param [in] bEnable RTP packet report option.
 * @param [in] bAudio  Audio flag.
 * @param [in] bVideo Video flag.
 *
 * @retval ZOK Set RTP packet report option successfully.
 * @retval ZFAILED Set RTP packet report option failed.
 *
 * @see @ref Mtc_CallDbGetRtpReportEnable
 */
ZFUNC ZINT Mtc_CallDbSetRtpReportEnable(ZBOOL bEnable, 
                ZBOOL bAudio, ZBOOL bVideo);

/**
 * @brief Get RTP packet report option from database.
 *
 * @param [in] bVideo Video flag(ZTRUE for video, ZFALSE for audio).
 *
 * @retval ZTRUE Start RTP packet  report.
 * @retval ZFALSE Do not start RTP packet report.
 *
 * @see @ref Mtc_CallDbSetRtpReportEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetRtpReportEnable(ZBOOL bVideo);

/**
 * @brief Get the H264 payload.
 *
 * @return The H264 payload(118-127 recommended).
 *
 * @see @ref Mtc_CallDbSetH264Payload
 */
ZFUNC ZUINT Mtc_CallDbGetH264Payload(ZFUNC_VOID);

/**
 * @brief Set the H264  payload.
 *
 * @param [in] iPayload The H264 payload(118-127 recommended).
 *
 * @retval ZOK Set the H264 payload successfully.
 * @retval ZFAILED Set the H264 payload failed.
 *
 * @see @ref Mtc_CallDbGetH264Payload
 */
ZFUNC ZINT Mtc_CallDbSetH264Payload(ZUINT iPayload);

/**
 * @brief Set SDK auto ring(send 18x) enable.
 *
 * @param [in] bEnable SDK auto ring(send 18x) enable option.
 *
 * @retval ZOK Set SDK auto ring(send 18x) enable option successfully.
 * @retval ZFAILED Set SDK auto ring(send 18x) enable option failed.
 *
 * @see @ref Mtc_CallDbGetAutoRingEnable
 */
ZFUNC ZINT Mtc_CallDbSetAutoRingEnable(ZBOOL bEnable);

/**
 * @brief Get SDK auto ring(send 18x) enable option from database.
 *
 * @retval ZTRUE SDK auto ring(send 18x) enable.
 * @retval ZFALSE SDK auto ring(send 18x) disable.
 *
 * @see @ref Mtc_CallDbSetAutoRingEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetAutoRingEnable(ZFUNC_VOID);

/**
 * @brief Set the audio stream direction type..
 *
 * @param [in] iType The audio stream direction type. @ref EN_MTC_DB_STRM_DIR_TYPE.
 *
 * @retval ZOK Set the audio stream direction type successfully.
 * @retval ZFAILED Set tthe audio stream direction type failed.
 *
 * @see @ref Mtc_CallDbGetAstrmDirectionType
 */
ZFUNC ZINT Mtc_CallDbSetAstrmDirectionType(ZUINT iType);

/**
 * @brief Get the audio stream direction type.
 *
 * @return The audio stream direction  type. @ref EN_MTC_DB_STRM_DIR_TYPE.
 *
 * @see @ref Mtc_CallDbSetAstrmDirectionType
 */
ZFUNC ZUINT Mtc_CallDbGetAstrmDirectionType(ZFUNC_VOID);

/**
 * @brief Set 182 enable.
 *
 * @param [in] bEnable If ZTRUE(default value),  UE will return 182 response if receiving an incoming 
 *                      call when it's in call; if ZFALSE, UE will return 180 response if receiving
 *                      an incoming call when it's in call.
 *
 * @retval ZOK Set 182 enable flag successfully.
 * @retval ZFAILED Set 182 enable flag failed.
 *
 * @see @ref Mtc_CallDbGet182Enable
 */
ZFUNC ZINT Mtc_CallDbSet182Enable(ZBOOL bEnable);

/**
 * @brief Get 182 enable state.
 *
 * @retval ZTRUE(default value) UE will return 182 response if receiving an incoming call when it's in call.
 * @retval ZFALSE UE will return 180 response if receiving an incoming call when it's in call.
 *
 * @see @ref Mtc_CallDbSet182Enable
 */
ZFUNC ZBOOL Mtc_CallDbGet182Enable();

/**
 * @brief Set support p-early-media enable.
 *
 * @param [in] bEnable If ZTRUE(default value),  UE will add p-early-media header.
 *
 * @retval ZOK Set support p-early-media enable successfully.
 * @retval ZFAILED Set support p-early-media enable failed.
 *
 * @see @ref Mtc_CallDbGetSuptEarlyMediaEnable
 */
ZFUNC ZINT Mtc_CallDbSetSuptEarlyMediaEnable(ZBOOL bEnable);

/**
 * @brief Get support p-early-media enable.
 *
 * @retval ZTRUE(default value) SDK add p-early-media header.
 * @retval ZFALSE SDK not add p-early-media support header.
 *
 * @see @ref Mtc_CallDbSetSuptEarlyMediaEnable
 */
ZFUNC ZBOOL Mtc_CallDbGetSuptEarlyMediaEnable();

/**
 * @brief Get session subscribe user query event expires.
 *
 * @param [out] piExpire Expires timer length.
 *
 * @retval ZTRUE Get subscribe user query event expires successfully.
 * @retval ZFALSE Get subscribe user query event expires failed.
 *
 * @see @ref Mtc_CallDbSetSubsUserQueryExpire
 */
ZFUNC ZINT Mtc_CallDbGetSubsUserQueryExpire(ZUINT *piExpire);

/**
 * @brief Set subscribe user query event expires.
 *
 * @param [in] iExpire user query event expire timer length.
 *
 * @retval ZOK Set subscribe user query event expires successfully.
 * @retval ZFAILED Set subscribe user query event expires failed.
 *
 * @see @ref Mtc_CallDbGetSubsUserQueryExpire
 */
ZFUNC ZINT Mtc_CallDbSetSubsUserQueryExpire(ZUINT iExpire);

/**
 * @brief Set resolution ratio type.
 *
 * @param [in] iType the type of resolution ratio.
 *
 * @retval ZOK Set resolution ratio type successfully.
 * @retval ZFAILED Set resolution ratio type failed.
 *
 * @see @ref Mtc_CallDbSetResRatioType
 */
ZFUNC ZINT Mtc_CallDbSetResRatioType(ZUINT iType);

/**
 * @brief Get resolution ratio type.
 *
 * @retval the conn video resolution ratio type.
 *
 * @see @ref Mtc_CallDbGetResRatioType
 */
ZFUNC ZUINT Mtc_CallDbGetResRatioType();

#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_CALL_DB_H__ */

