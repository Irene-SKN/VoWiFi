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
  File name     : mtc_call.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC call

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CALL_H__
#define _MTC_CALL_H__

/**
 * @file mtc_call.h
 * @brief MTC Call Interface Functions
 *
 * This file includes call interface function. Those function is used to manage calls.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC call record file type */
#define MTC_CALL_REC_FILE_PCM "pcm"  /**< @brief pcm content */
#define MTC_CALL_REC_FILE_WAV "wav"  /**< @brief wav content */

/** @brief MTC call status code(error no or terminated code). */
#define MTC_CALL_ERR_NO               (MTC_EBASE_CALL + 0) /**< @brief no error. */
#define MTC_CALL_ERR_AUTH_FAILED      (MTC_EBASE_CALL + 1) /**< @brief authentication failed, invalid user or password. */
#define MTC_CALL_ERR_SESS_TMR         (MTC_EBASE_CALL + 2) /**< @brief call refresh error. */
#define MTC_CALL_ERR_FORBIDDEN        (MTC_EBASE_CALL + 3) /**< @brief call forbidden. */
#define MTC_CALL_ERR_NOT_FOUND        (MTC_EBASE_CALL + 4) /**< @brief call participant not found. */
#define MTC_CALL_ERR_NOT_ACPTED       (MTC_EBASE_CALL + 5) /**< @brief call not accepted. */
#define MTC_CALL_ERR_TEMP_UNAVAIL     (MTC_EBASE_CALL + 6) /**< @brief call participant temp unavailable. */
#define MTC_CALL_ERR_REQ_TERMED       (MTC_EBASE_CALL + 7) /**< @brief call request terminated. */
#define MTC_CALL_ERR_INTERNAL_ERR     (MTC_EBASE_CALL + 8) /**< @brief server internal error. */
#define MTC_CALL_ERR_SRV_UNAVAIL      (MTC_EBASE_CALL + 9) /**< @brief service unavailable. */
#define MTC_CALL_ERR_NOT_EXIST        (MTC_EBASE_CALL + 10) /**< @brief not exist. */
#define MTC_CALL_ERR_USER_NOTREG      (MTC_EBASE_CALL + 11) /**< @brief call participant not Registered. */
#define MTC_CALL_ERR_NOT_FRIEND       (MTC_EBASE_CALL + 12) /**< @brief call participant is not friend. */
#define MTC_CALL_ERR_IN_BACK_LST      (MTC_EBASE_CALL + 13) /**< @brief call participant is in black list. */
#define MTC_CALL_ERR_TRANS_FAIL       (MTC_EBASE_CALL + 14) /**< @brief call transaction error. */
#define MTC_CALL_ERR_REJECTED         (MTC_EBASE_CALL + 15) /**< @brief Add/RMV video failed beacause of rejected by other participant. */
#define MTC_CALL_ERR_NETWORK          (MTC_EBASE_CALL + 16) /**< @brief Add/RMV video failed  or call termed because of local network disconnected . */
#define MTC_CALL_ERR_TIMEOUT          (MTC_EBASE_CALL + 17) /**< @brief Add/RMV video failed because of timeout for the request. */
#define MTC_CALL_ERR_IN_SERVICE       (MTC_EBASE_CALL + 18) /**< @brief Add/RMV video failed because of last request in service. */
#define MTC_CALL_ERR_BAD_REQ          (MTC_EBASE_CALL + 19) /**< @brief call error by 400 bad request error. */

#define MTC_CALL_TERM_BYE             (MTC_EBASE_CALL + 21) /**< @brief Terminated by bye. */
#define MTC_CALL_TERM_CANCEL          (MTC_EBASE_CALL + 22) /**< @brief Terminated by cancel. */
#define MTC_CALL_TERM_TIMEOUT         (MTC_EBASE_CALL + 23) /**< @brief Terminated by timeout. */
#define MTC_CALL_TERM_BUSY            (MTC_EBASE_CALL + 24) /**< @brief Terminated by busy. */
#define MTC_CALL_TERM_DECLINE         (MTC_EBASE_CALL + 25) /**< @brief Terminated by decline. */
#define MTC_CALL_TERM_TRSFED          (MTC_EBASE_CALL + 26) /**< @brief Terminated by transfered. */
#define MTC_CALL_TERM_REDIRECT        (MTC_EBASE_CALL + 27) /**< @brief Terminated by redirect. */
#define MTC_CALL_TERM_REPLACE         (MTC_EBASE_CALL + 28) /**< @brief Terminated by replace. */
#define MTC_CALL_TERM_COVIB_CANCEL    (MTC_EBASE_CALL + 29) /**< @brief Terminated by co-vibration cancel. */
#define MTC_CALL_TERM_SAMESIDE_TALK   (MTC_EBASE_CALL + 30) /**< @brief Terminated by same side talk . */
#define MTC_CALL_TERM_NO_MEDIA        (MTC_EBASE_CALL + 31) /**< @brief Terminated by no media . */

#define MTC_CALL_ALERT_RING           (MTC_EBASE_CALL + 41) /**< @brief Alerted by 180. */
#define MTC_CALL_ALERT_QUEUED         (MTC_EBASE_CALL + 42) /**< @brief Alerted by 182. */
#define MTC_CALL_ALERT_PROGRESS       (MTC_EBASE_CALL + 43) /**< @brief Alerted by 183. */
#define MTC_CALL_ALERT_OTHER          (MTC_EBASE_CALL + 44) /**< @brief Alerted by other type. */

#define MTC_CALL_ERR_OTHER            (MTC_EBASE_CALL + 200) /**< @brief other error. */

/** @brief MTC call dtmf type */
typedef enum EN_MTC_CALL_DTMF_TYPE
{
    EN_MTC_CALL_DTMF_0,              /**< @brief DTMF signal 0 */
    EN_MTC_CALL_DTMF_1,              /**< @brief DTMF signal 1 */
    EN_MTC_CALL_DTMF_2,              /**< @brief DTMF signal 2 */
    EN_MTC_CALL_DTMF_3,              /**< @brief DTMF signal 3 */
    EN_MTC_CALL_DTMF_4,              /**< @brief DTMF signal 4 */
    EN_MTC_CALL_DTMF_5,              /**< @brief DTMF signal 5 */
    EN_MTC_CALL_DTMF_6,              /**< @brief DTMF signal 6 */
    EN_MTC_CALL_DTMF_7,              /**< @brief DTMF signal 7 */
    EN_MTC_CALL_DTMF_8,              /**< @brief DTMF signal 8 */
    EN_MTC_CALL_DTMF_9,              /**< @brief DTMF signal 9 */
    EN_MTC_CALL_DTMF_STAR,           /**< @brief DTMF signal * */
    EN_MTC_CALL_DTMF_POUND,          /**< @brief DTMF signal # */
    EN_MTC_CALL_DTMF_A,              /**< @brief DTMF signal A */
    EN_MTC_CALL_DTMF_B,              /**< @brief DTMF signal B */
    EN_MTC_CALL_DTMF_C,              /**< @brief DTMF signal C */
    EN_MTC_CALL_DTMF_D,              /**< @brief DTMF signal D */
} EN_MTC_CALL_DTMF_TYPE;

/** @brief MTC call m-type */
typedef enum EN_MTC_CALL_MTYPE
{
    EN_MTC_CALL_MTYPE_DISC_TEXT,          /**< @brief Type for "text". */   
    EN_MTC_CALL_MTYPE_DISC_APP,           /**< @brief Type for "application". */
} EN_MTC_CALL_MTYPE;

/** @brief MTC call m-subtype */
typedef enum EN_MTC_CALL_MSUBTYPE
{
    EN_MTC_CALL_MSUBTYPE_PLAIN,             /**< @brief Type for "plain". */
    EN_MTC_CALL_MSUBTYPE_UD_SIGNAL,         /**< @brief Type for "ud-signal" */
    EN_MTC_CALL_MSUBTYPE_MEMB_CTL_XML,      /**< @brief Type for "memb-ctl+xml" */
    EN_MTC_CALL_MSUBTYPE_MEMB_STATE_XML,    /**< @brief Type for "memb-state+xml" */
    EN_MTC_CALL_MSUBTYPE_PTT_XML,           /**< @brief Type for "ptt+xml" */
    EN_MTC_CALL_MSUBTYPE_PTT_ACK_XML,       /**< @brief Type for "ptt-ack+xml" */
    EN_MTC_CALL_MSUBTYPE_LINK_STATE_XML,    /**< @brief Type for "link-state+xml" */
    EN_MTC_CALL_MSUBTYPE_PARA_INQ_XML,      /**< @brief Type for "para-inq+xml" */
    EN_MTC_CALL_MSUBTYPE_PARA_INQ_ACK_XML,  /**< @brief Type for "para-inq-ack+xml" */
    EN_MTC_CALL_MSUBTYPE_PARA_SET_XML,      /**< @brief Type for "para-set+xml" */
    EN_MTC_CALL_MSUBTYPE_PARA_SET_ACK_XML,  /**< @brief Type for "para-set-ack+xml" */
    EN_MTC_CALL_MSUBTYPE_VOICE_SOURCE_XML,  /**< @brief Type for "voice-source+xml" */
} EN_MTC_CALL_MSUBTYPE;

/** @brief MTC call alert information type */
typedef enum EN_MTC_CALL_ALERT_INFO_TYPE
{
    EN_MTC_CALL_ALERT_INFO_NULL,     /**< @brief no alert info */   
    EN_MTC_CALL_ALERT_INFO_DR0,      /**< @brief bellcore_dr0 */
    EN_MTC_CALL_ALERT_INFO_DR1,      /**< @brief bellcore_dr1 */
    EN_MTC_CALL_ALERT_INFO_DR2,      /**< @brief bellcore_dr2 */
    EN_MTC_CALL_ALERT_INFO_DR3,      /**< @brief bellcore_dr3 */
    EN_MTC_CALL_ALERT_INFO_DR4,      /**< @brief bellcore_dr4 */
    EN_MTC_CALL_ALERT_INFO_DR5       /**< @brief bellcore_dr5 */
} EN_MTC_CALL_ALERT_INFO_TYPE;

/** @brief MTC call ealry media direction */
typedef enum EN_MTC_CALL_EM_STATUS_TYPE
{
    EN_MTC_CALL_EM_STATUS_INACTIVE,  /**< @brief inactive */
    EN_MTC_CALL_EM_STATUS_SENDONLY,  /**< @brief sendonly */
    EN_MTC_CALL_EM_STATUS_RECVONLY,  /**< @brief recvonly */
    EN_MTC_CALL_EM_STATUS_SENDRECV,  /**< @brief sendrecv */
} EN_MTC_CALL_EM_STATUS_TYPE;

/** @brief MTC call terminate reason type */
typedef enum EN_MTC_CALL_TERM_REASON_TYPE
{
    EN_MTC_CALL_TERM_REASON_NORMAL,  /**< @brief normal session term, bye or cancel */
    EN_MTC_CALL_TERM_REASON_BUSY,    /**< @brief the session is rejected */
    EN_MTC_CALL_TERM_REASON_DECLINE, /**< @brief decline the session */
    EN_MTC_CALL_TERM_REASON_NOT_AVAILABLE, /**< @brief the user is not available */
    EN_MTC_CALL_TERM_REASON_INTERRUPT /**< @brief active interrupt because of unavailable network */
} EN_MTC_CALL_TERM_REASON_TYPE;

/** @brief MTC call record mode type */
typedef enum EN_MTC_CALL_REC_MODE_TYPE
{
    EN_MTC_CALL_REC_MODE_ALL,        /**< @brief record all data */
    EN_MTC_CALL_REC_MODE_PLAY,       /**< @brief record palying data */
    EN_MTC_CALL_REC_MODE_MIC         /**< @brief record microphone data */
} EN_MTC_CALL_REC_MODE_TYPE;

/** @brief MTC call transmission state type */
typedef enum EN_MTC_CALL_TRANSMISSION_STATE
{
    /** @brief Transmission is normal, 'nrml'. */ 
    EN_MTC_CALL_TRANSMISSION_NORMAL = 0x6E726D6C,
    /** @brief Transmission is paused for camera is off, 'coff'. */
    EN_MTC_CALL_TRANSMISSION_CAMOFF = 0x636F6666,
    /** @brief Transmission is paused, 'pasd'. */
    EN_MTC_CALL_TRANSMISSION_PAUSE  = 0x70617364,
    /** @brief Transmission is pause for QoS reason, 'pqos'. */
    EN_MTC_CALL_TRANSMISSION_PAUSE4QOS = 0x70716F73,
} EN_MTC_CALL_TRANSMISSION_STATE;

/** @brief Device orientation type. */
typedef enum EN_MTC_ORIENTATION_TYPE
{
    EN_MTC_ORIENTATION_PORTRAIT,     /**< @brief Display like a portrait, home
                                         button on the bottom side. */
    EN_MTC_ORIENTATION_LANDSCAPE_RIGHT, /**< @brief Landscape display, home
                                             button on the right side. */
    EN_MTC_ORIENTATION_PORTRAIT_UPSIDEDOWN, /**< @brief Display like a portrait,
                                                 home button on the top side. */
    EN_MTC_ORIENTATION_LANDSCAPE_LEFT, /**< @brief Landscape display, home
                                             button on the left side. */
} EN_MTC_ORIENTATION_TYPE;

/** @brief Type of MTC network status. */
typedef enum EN_MTC_NET_STATUS_TYPE
{
    EN_MTC_NET_STATUS_DISCONNECTED = -3, /**< @brief Disconnected from network. */
    EN_MTC_NET_STATUS_VERY_BAD  = -2, /**< @brief Network status is very bad. */
    EN_MTC_NET_STATUS_BAD       = -1, /**< @brief Network status is bad. */
    EN_MTC_NET_STATUS_NORMAL    = 0,  /**< @brief Network status is normal. */
    EN_MTC_NET_STATUS_GOOD      = 1,  /**< @brief Network status is good. */
    EN_MTC_NET_STATUS_VERY_GOOD = 2,  /**< @brief Network status is very good. */
} EN_MTC_NET_STATUS_TYPE;

/* @brief Type of MTC session state */
typedef enum EN_MTC_SESSION_STATE_TYPE
{
    EN_MTC_SESSION_STATE_IDLE,      /**<@brief Session state is idle. */
    EN_MTC_SESSION_STATE_OUTGOING,  /**<@brief Session state is outgoing. */
    EN_MTC_SESSION_STATE_INCOMING,  /**<@brief Session state is incoming. */
    EN_MTC_SESSION_STATE_ALERTED,   /**<@brief Session state is alerted. */
    EN_MTC_SESSION_STATE_CONNECTING,/**<@brief Session state is connecting. */ 
    EN_MTC_SESSION_STATE_TALKING,   /**<@brief Session state is talking. */
    EN_MTC_SESSION_STATE_ENDED,     /**<@brief Session state is ended. */
    EN_MTC_SESSION_STATE_DIDEND,    /**<@brief Session state is didend. */
} EN_MTC_SESSION_STATE_TYPE;

/* @brief Type of MTC session participant state */
typedef enum EN_MTC_SESS_PARTP_STATE_TYPE
{
    EN_MTC_SESS_PARTP_STATE_PENDING,    /**<@brief Session participant pending. */
    EN_MTC_SESS_PARTP_STATE_DIALINGIN,  /**<@brief Session participant dialing in. */
    EN_MTC_SESS_PARTP_STATE_DIALINGOUT, /**<@brief Session participant dialing out. */
    EN_MTC_SESS_PARTP_STATE_ALERTING,   /**<@brief Session participant alerting. */
    EN_MTC_SESS_PARTP_STATE_CONNED,     /**<@brief Session participant connected. */ 
    EN_MTC_SESS_PARTP_STATE_ONHOLD,     /**<@brief Session participant onhold. */
    EN_MTC_SESS_PARTP_STATE_DISCING,    /**<@brief Session participant disconnecting. */
    EN_MTC_SESS_PARTP_STATE_DISCED,     /**<@brief Session participant disconnected. */
} EN_MTC_SESS_PARTP_STATE_TYPE;

/** @brief MTC session crypto state type */
typedef enum EN_MTC_SESS_CRYPTO_STATE_TYPE
{
    EN_MTC_SESS_NO_CRYPTO,              /**< @brief session no crypto */
    EN_MTC_SESS_FIXED_CRYPTO,           /**< @brief sesssion with fixed crypto */
    EN_MTC_SESS_DTLS_SW_CERT,           /**< @brief sesssion dtls software certificated crypto */
    EN_MTC_SESS_DTLS_HW_CERT_FAILED,    /**< @brief sesssion dtls hardware 
                                            certificated crypto but cert verify failed */
    EN_MTC_SESS_DTLS_HW_CERT_SUCCESS    /**< @brief sesssion dtls hardware 
                                            certificated crypto but cert verify failed */
} EN_MTC_SESS_CRYPTO_STATE_TYPE;

/**  @brief MTC session alert type */
typedef enum EN_MTC_ALERT_TYPE
{
    EN_MTC_ALERT_RING,               /* 180 ring */
    EN_MTC_ALERT_QUEUED,             /* 182 queued */
    EN_MTC_ALERT_PROGRESS            /* 183 session progress */
} EN_MTC_ALERT_TYPE;

/** @brief Type of mtc audio source . */
typedef enum EN_MTC_AUDIO_SOURCE
{
    EN_MTC_AUDIO_SOURCE_NO,         /**< @brief no audio source. */
    EN_MTC_AUDIO_SOURCE_MIC,        /**< @brief mic audio source. */
    EN_MTC_AUDIO_SOURCE_PLAYOUT,    /**< @brief playout source file. */
    EN_MTC_AUDIO_SOURCE_CALL,       /**< @brief send and playout mixed source. */
} EN_MTC_AUDIO_SOURCE;

/** @brief MTC session ST type of ServInfo */
typedef enum EN_MTC_SERV_INFO_TYPE
{
    EN_MTC_SERV_INFO_P2P,               /* for p2p(internal call)*/
    EN_MTC_SERV_INFO_EXCOM,             /* for outside(external call) */
    EN_MTC_SERV_INFO_OTHER              /* for other type */
} EN_MTC_SERV_INFO_TYPE;

/** @brief MTC session Sub-ST type of ServInfo */
typedef enum EN_MTC_SERV_SUB_ST_TYPE
{
    EN_MTC_SERV_SUB_ST_SFCONF,           /**< @brief Type for "Sfconf". */    
    EN_MTC_SERV_SUB_ST_SHCONF,           /**< @brief Type for "Shconf". */
    EN_MTC_SERV_SUB_ST_PFCONF,           /**< @brief Type for "Pfconf". */
    EN_MTC_SERV_SUB_ST_PHCONF,           /**< @brief Type for "Phconf". */
    EN_MTC_SERV_SUB_ST_ALARM,            /**< @brief Type for "Alarm". */
    EN_MTC_SERV_SUB_ST_BROADCAST,        /**< @brief Type for "Broadcast". */
    EN_MTC_SERV_SUB_ST_MULTICAST,        /**< @brief Type for "Multicast". */
    EN_MTC_SERV_SUB_ST_COMMAND,          /**< @brief Type for "Command". */  
    EN_MTC_SERV_SUB_ST_OTHER             /**< @brief Type for "Other". */
} EN_MTC_SERV_SUB_ST_TYPE;

/** @brief MTC session terminal type. */
typedef enum EN_MTC_TERMINAL_TYPE
{
    EN_MTC_TERMINAL_UNKNOWN,                 /* for unknown type */
    EN_MTC_TERMINAL_CAPTAIN,                 /* for captain type */
    EN_MTC_TERMINAL_DIRECTOR,                /* for director type */
    EN_MTC_TERMINAL_ORDINARY,                /* for ordinary type */
    EN_MTC_TERMINAL_ASSISTANT,               /* for assistant type */
} EN_MTC_TERMINAL_TYPE;

/** @brief mtc sesssion media type */
typedef enum EN_MTC_SESS_MEDIA_TYPE
{
    EN_MTC_SESS_MEDIA_AUDIO,
    EN_MTC_SESS_MEDIA_VIDEO
} EN_MTC_SESS_MEDIA_TYPE;

/** 
 * @brief MTC Call, establishing session call with video or audio.
 *
 * If send a new call and the callee answered, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTalking
 *
 * If send a new call and the callee redirected, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetOutgoing, @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTalking
 *
 * If send a new call and the callee do not answered(timeout, busy now, etc.), GUI will be 
 * notified by callback which was set by @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTermed
 *
 * While receiving call invitation, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetIncoming.
 *
 * While receiving call invitation and session is exist, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetReplaced.
 *
 * @param [in] pcUri The destination URI to which you want to make a session call.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by @ref Mtc_SessGetCookie or reset by
 *                      @ref Mtc_SessSetCookie at any time of session's life.
 * @param [in] bAudio Indicate whether this call has a voice stream.
 * @param [in] bVideo Indicate whether this call has a video stream.
 *
 * @return The id of this new created session on succeed, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_SessAnswer, @ref Mtc_SessGetCookie, @ref Mtc_SessSetCookie
 */
ZFUNC ZUINT Mtc_SessCall(ZCHAR *pcUri, ZCOOKIE zCookie, ZBOOL bAudio,
                ZBOOL bVideo);

/** 
 * @brief MTC Call, establishing session call with video or audio.
 *
 * If send a new call and the callee answered, GUI will be notified by 
 * callback which was set by @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTalking
 *
 * If send a new call and the callee redirected, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetOutgoing, @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTalking
 *
 * If send a new call and the callee do not answered(timeout, busy now, etc.), GUI will be 
 * notified by callback which was set by @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTermed
 *
 * While receiving call invitation, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetIncoming.
 *
 * While receiving call invitation and session is exist, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetReplaced.
 *
 * @param [in] pcUri The destination URI to which you want to make a session call.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by @ref Mtc_SessGetCookie or reset by
 *                      @ref Mtc_SessSetCookie at any time of session's life.
 * @param [in] bAudio Indicate whether this call has a voice stream.
 * @param [in] bVideo Indicate whether this call has a video stream.
 * @param [in] bSend Indicate whether this call start to send after established.
 * @param [in] bRecv Indicate whether this call start to receive after established.
 *
 * @return The id of this new created session on succeed, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_SessAnswer, @ref Mtc_SessGetCookie, @ref Mtc_SessSetCookie
 */
ZFUNC ZUINT Mtc_SessCallX(ZCHAR *pcUri, ZCOOKIE zCookie, ZBOOL bAudio,
                ZBOOL bVideo, ZBOOL bSend, ZBOOL bRecv);

/** 
 * @brief MTC Call, establishing session call with video or audio.
 *
 * If send a new call and the callee answered, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTalking
 *
 * If send a new call and the callee redirected, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetOutgoing, @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTalking
 *
 * If send a new call and the callee do not answered(timeout, busy now, etc.), GUI will be 
 * notified by callback which was set by @ref Mtc_CallCbSetAlerted, @ref Mtc_CallCbSetTermed
 *
 * While receiving call invitation, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetIncoming.
 *
 * While receiving call invitation and session is exist, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetReplaced.
 *
 * @param [in] pcUri The destination URI to which you want to make a session call.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by @ref Mtc_SessGetCookie or reset by
 *                      @ref Mtc_SessSetCookie at any time of session's life.
 * @param [in] bAudio Indicate whether this call has a voice stream.
 * @param [in] bVideo Indicate whether this call has a video stream.
 * @param [in] iServInfoType Indicate type of server info, @ref EN_MTC_SERV_INFO_TYPE.
 * @param [in] iTermType Indicate type of the seat terminal, @ref EN_MTC_TERMINAL_TYPE.
 *
 * @return The id of this new created session on succeed, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_SessAnswer, @ref Mtc_SessGetCookie, @ref Mtc_SessSetCookie
 */
ZFUNC ZUINT Mtc_SessRadioCall(ZCHAR *pcUri, ZCOOKIE zCookie, ZBOOL bAudio,
                ZBOOL bVideo, ZUINT iServInfoType, ZUINT iTermType);

/** 
 * @brief MTC session get  ST type, which should be called in the incoming callbacks.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval The ST type in ServInfo, @ref EN_MTC_SERV_INFO_TYPE.
 *
 */
ZFUNC ZUINT Mtc_SessGetServInfoType(ZUINT iSessId);

/** 
 * @brief MTC session get  Sub-ST type, which should be called in the incoming callbacks 
 * when  @ref Mtc_SessGetServInfoType returns @ref EN_MTC_SERV_INFO_EXCOM.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval The Sub-ST type in ServInfo, @ref EN_MTC_SERV_SUB_ST_TYPE.
 *
 */
ZFUNC ZUINT Mtc_SessGetSubServInfoType(ZUINT iSessId);

/** 
 * @brief MTC session get peer terminal type, which should be called in the incoming callbacks.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval The peer type, @ref EN_MTC_TERMINAL_TYPE.
 *
 */
ZFUNC ZUINT Mtc_SessGetPeerType(ZUINT iSessId);

/** 
 * @brief MTC Call Continue, continue the last session call with video or audio within short time.
 *
 * @param [in] pcUri The destination URI to which you want to make a session call.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by @ref Mtc_SessGetCookie or reset by
 *                      @ref Mtc_SessSetCookie at any time of session's life.
 * @param [in] bAudio Indicate whether this call has a voice stream.
 * @param [in] bVideo Indicate whether this call has a video stream.
 * @param [in] bSend Indicate whether this call start to send after established.
 * @param [in] bRecv Indicate whether this call start to receive after established.
 * @param [in] pcCallId The callid of last call session.
 * @param [in] pcLocalTag The local tag of last call session.  
 *
 * @return The id of this new created session on succeed, otherwise return ZMAXUINT.
 *
 * @see @ref @ref Mtc_SessGetCookie, @ref Mtc_SessSetCookie, @Mtc_SessGetCallId, @Mtc_SessGetLocalTag
 */
ZFUNC ZUINT Mtc_SessContinue(ZCHAR *pcUri, ZCOOKIE zCookie, ZBOOL bAudio,
                ZBOOL bVideo, ZCHAR *pcCallId, ZCHAR *pcLocalTag);

/** 
 * @brief MTC session alert an incoming session.
 *
 * @param [in] iSessId The id of incoming session which you want answer.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by Rse_SessGetCookie or reset by
 *                      Rse_SessSetCookie at any time of session's life.
 * @param [in] iType Alert type, EN_MTC_ALERT_TYPE.
 * @param [in] bReliable If ZTRUE, message will be sending as reliable
 *                      provisional response.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessCall, @ref Mtc_SessGetCookie, @ref Mtc_SessSetCookie
 */
ZFUNC ZINT Mtc_SessAlert(ZUINT iSessId, ZCOOKIE zCookie, ZUINT iType,
                ZBOOL bReliable);

/** 
 * @brief MTC session answer an incoming session call which is notified by
 *        callback function which was set by @ref Mtc_CallCbSetIncoming.
 *
 * @param [in] iSessId The id of incoming session which you want to answer.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by @ref Mtc_SessGetCookie or reset by
 *                      @ref Mtc_SessSetCookie at any time of session's life.
 * @param [in] bAudio Indicate whether this call has a voice stream.
 * @param [in] bVideo Indicate whether this call has a video stream.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessCall, @ref Mtc_CallCbSetIncoming, @ref Mtc_SessGetCookie, @ref Mtc_SessSetCookie
 */
ZFUNC ZINT Mtc_SessAnswer(ZUINT iSessId, ZCOOKIE zCookie, ZBOOL bAudio,
                ZBOOL bVideo);

/** 
 * @brief MTC session terminate.
 *
 * @param [in] iSessId The ID of session which you want to terminate.
 * @param [in] iReason Indicate the terminate reason which may trigger some
 *                   service in S-CSCF, see @ref EN_MTC_CALL_TERM_REASON_TYPE.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * Actually Mtc_SessTerm does not free all resource allocated for this
 * session. It only starts a terminating procedure. All resource will be
 * freed automatically when the procedure ends.
 *
 * @see @ref Mtc_SessCall, @ref Mtc_SessAnswer...
 */
ZFUNC ZINT Mtc_SessTerm(ZUINT iSessId, ZUINT iReason);

/** 
 * @brief MTC session hold.
 *
 * If sending session hold successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetHoldOk
 *
 * If sending session hold failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetHoldFailed
 *
 * While receiving session held, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetHeld.
 *
 * @param [in] iSessId The ID of session which you want to hold.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessUnhold
 */
ZFUNC ZINT Mtc_SessHold(ZUINT iSessId);

/** 
 * @brief MTC session unhold.
 *
 * If sending session unhold successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetUnHoldOk
 *
 * If sending session hold failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetUnHoldFailed
 *
 * While receiving session unheld, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetUnHeld.
 *
 * @param [in] iSessId The ID of session which you want to unhold.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessUnhold
 */
ZFUNC ZINT Mtc_SessUnhold(ZUINT iSessId);

/** 
 * @brief MTC session unattended transfer.
 *
 * If unattended transfer successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetTrsfAcpt
 *
 * If unattended transfer failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetTrsfFailed, @ref Mtc_CallCbSetTrsfTerm
 *
 * while receiving unattended transfer, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetRefered
 *
 * @param [in] iSessId The ID of session which you want to make unattended transfer.
 * @param [in] pcUri The destination URI to which you want to transfer this session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * After this operation, the session will be terminated by server.
 *
 * @see @ref Mtc_SessATrsf
 */
ZFUNC ZINT Mtc_SessUTrsf(ZUINT iSessId, ZCHAR *pcUri);

/** 
 * @brief MTC session attended transfer.
 *
 * If attended transfer successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetTrsfAcpt
 *
 * If attended transfer failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetTrsfFailed, @ref Mtc_CallCbSetTrsfTerm
 *
 * while receiving attended transfer, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetRefered
 *
 * @param [in] iSessId The ID of session which you want to make attended transfer.
 * @param [in] iTrsfSess The destination session to which you want to transfer
 *                          this session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * If you have a session with user A(indicated by iSessId) and a session with
 * user B(indicated by iTrsfSessId), the result of attended transfer is A will
 * have a session with B and all sessions you had with A and B will be terminated.
 *
 * @see @ref Mtc_SessUTrsf
 */
ZFUNC ZINT Mtc_SessATrsf(ZUINT iSessId, ZUINT iTrsfSess);

/** 
 * @brief MTC session diverse an incoming session call which is notified by
 *        callback function which was set by @ref Mtc_CallCbSetIncoming.
 *
 * While receiving forwarded, GUI will be notified by callback which 
 * was set by @ref Mtc_CallCbSetRedirected.
 *
 * @param [in] iSessId The ID of session which you want to diverse.
 * @param [in] pcUri The URI of diverse destination.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_CallCbSetIncoming
 */
ZFUNC ZINT Mtc_SessDiv(ZUINT iSessId, ZCHAR *pcUri);

/** 
 * @brief MTC session send a media update request to peer. The update in this
 *        function means open a new media stream or close an already exist
 *        media stream.
 *
 * If sending update successfully, GUI will be notified by callback which  was set by 
 * @ref Mtc_CallCbSetAddAudioOk, @ref Mtc_CallCbSetRmvAudioOk, @ref Mtc_CallCbSetAddVideoOk,
 * @ref Mtc_CallCbSetRmvVideoOk
 *
 * If sending update failed, GUI will be notified by callback which was set by 
 * @ref Mtc_CallCbSetAddAudioFailed, @ref Mtc_CallCbSetRmvAudioFailed, @ref Mtc_CallCbSetAddVideoFailed,
 * @ref Mtc_CallCbSetRmvVideoFailed
 *
 * While receiving update, GUI will be notified by callback which  was set by 
 * @ref Mtc_CallCbSetAddAudioReq, @ref Mtc_CallCbSetAddVideoReq.
 *
 * @param [in] iSessId The ID of session which you want to update its media.
 * @param [in] bAudio Indicate whether you want to have a audio stream after
 *                    update.
 * @param [in] bVideo Indicate whether you want to have a video stream after
 *                    update.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * If the update request is accepted by peer, an indication will arise
 * through the callback function which was set by @ref Mtc_CallCbSetMdfyAcpt.
 *
 * @see @ref Mtc_SessUpdateRsp, @ref Mtc_CallCbSetMdfyAcpt
 */
ZFUNC ZINT Mtc_SessUpdate(ZUINT iSessId, ZBOOL bAudio, ZBOOL bVideo);

/** 
 * @brief MTC session response a media update request from peer. The update
 *        in this function means open a new media stream or close an already
 *        exist media stream.
 *
 * If sending negotiate successfully, GUI will be notified by callback which  was set by 
 * @ref Mtc_CallCbSetMdfyed
 *
 * @param [in] iSessId The ID of session which you want to accept the update
 *                      of its media.
 * @param [in] bAudio Indicate whether you want to have a audio stream after
 *                    update.
 * @param [in] bVideo Indicate whether you want to have a video stream after
 *                    update.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessUpdate, @ref Mtc_CallCbSetMdfyReq
 */
ZFUNC ZINT Mtc_SessUpdateRsp(ZUINT iSessId, ZBOOL bAudio, ZBOOL bVideo);

/** 
 * @brief MTC PickUp, establishing session call with video or audio 
          by replacing specific call.
 *
 * If the new session call was accept by callee, GUI will be notified by 
   callback which was set by @ref Mtc_CallCbSetTalking.
 *
 * If the new session call was reject by callee or no answer, GUI will be 
   notified by callback which was set by @ref Mtc_CallCbSetTermed.
 *
 * @param [in] pcUri The destination URI to which you want to make a session call.
 * @param [in] pcReplaceInfo The replace information used to locate replaced call.
                     The format must comply with RFC3891, 
                     like '425928@phone.example.org;to-tag=7743;from-tag=6472'.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by @ref Mtc_SessGetCookie or reset by
 *                      @ref Mtc_SessSetCookie at any time of session's life.
 * @param [in] bAudio Indicate whether this call has a voice stream.
 * @param [in] bVideo Indicate whether this call has a video stream.
 *
 * @return The id of this new created session on succeed, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_SessPickUpX
 */
ZFUNC ZUINT Mtc_SessPickUp(ZCHAR *pcUri, ZCHAR *pcReplaceInfo,
                ZCOOKIE zCookie, ZBOOL bAudio, ZBOOL bVideo);

/** 
 * @brief MTC session PickUp, establishing session call with video or audio 
          by replacing specific call.
 *
 * @param [in] iSessId The session ID indication which session to be pick up.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessPickUp
 */
ZFUNC ZINT Mtc_SessPickUpX(ZUINT iSessId);

/** 
 * @brief MTC session send DTMF info.
 *
 * @param [in] iSessId The ID of session which you want to send DTMF info.
 * @param [in] iDtmfType DTMF type which will be sent, see @ref EN_MTC_CALL_DTMF_TYPE.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessDtmf(ZUINT iSessId, ZUINT iDtmfType);

/** 
 * @brief MTC session send INFO with text.
 *
 * @param [in] iSessId The ID of session which you want to send INFO.
 * @param [in] pcInfo Text string carried by INFO.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessInfo(ZUINT iSessId, ZCHAR *pcInfo);

/** 
 * @brief MTC session send INFO by type.
 *
 * @param [in] iSessId The ID of session which you want to send INFO.
 * @param [in] pcInfo Text string carried by INFO.
 * @param [in] ucMType INFO m-type @ref EN_MTC_CALL_MTYPE. 
 * @param [in] ucMSubType INFO m-sub type @ref EN_MTC_CALL_MSUBTYPE. 
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessInfoByType(ZUINT iSessId, ZCHAR *pcInfo, 
                ZUCHAR ucMType, ZUCHAR ucMSubType);

/** 
 * @brief MTC session send out of dialog INFO by type.
 *
 * @param [in] pcUri The Uri of the user who the INFO will be send to.
 * @param [in] pcInfo Text string carried by INFO.
 * @param [in] ucMType INFO m-type @ref EN_MTC_CALL_MTYPE. 
 * @param [in] ucMSubType INFO m-sub type @ref EN_MTC_CALL_MSUBTYPE. 
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessInfoX(ZCHAR *pcUri, ZCHAR *pcInfo, 
                ZUCHAR ucMType, ZUCHAR ucMSubType);

/** 
 * @brief MTC session send out of dialog INFO by type.
 *
 * @param [in] pcUri The Uri of the user who the INFO will be send to.
 * @param [in] pcInfo Text string carried by INFO.
 * @param [in] pcMTypeExt INFO m-type externsion string. 
 * @param [in] pcMSubTypeExt INFO m-sub type externsion string. 
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessInfoXExt(ZCHAR *pcUri, ZCHAR *pcInfo, 
                ZCHAR *pcMTypeExt, ZCHAR *pcMSubTypeExt);

/** 
 * @brief MTC session attach camera.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] pcName The name string of camera.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessCameraAttach(ZUINT iSessId, ZCONST ZCHAR *pcName);

/** 
 * @brief MTC session detach camera.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessCameraDetach(ZUINT iSessId);

/**
 * @brief MTC get session name.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return The Render name string when found, otherwise "".
 */
ZFUNC ZCONST ZCHAR * Mtc_SessGetName(ZUINT iSessId);

/**
 * @brief MTC get session from render name.
 *
 * @param pcName Render name string.
 *
 * @return The ID of session when found, otherwise ZMAXUINT.
 */
ZFUNC ZUINT Mtc_SessFromName(ZCONST ZCHAR *pcName);

/** 
 * @brief MTC session start video transmission.
 *
 * @param [in] iSessId The ID of session which you want to start video transmission.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessVideoStart(ZUINT iSessId);

/** 
 * @brief MTC session stop video transmission.
 *
 * @param [in] iSessId The ID of session which you want to stop video transmission.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessVideoStop(ZUINT iSessId);

/** 
 * @brief MTC session pause sending video.
 *
 * @param [in] iSessId The ID of session which you want to stop video transmission.
 * @param [in] iState Transport state type, @ref EN_MTC_CALL_TRANSMISSION_STATE.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessVideoSetSend(ZUINT iSessId, ZUINT iState);

/** 
 * @brief Get MTC session video sending state.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Transport state type, @ref EN_MTC_CALL_TRANSMISSION_STATE.
 */
ZFUNC ZUINT Mtc_SessVideoGetSend(ZUINT iSessId);

/** 
 * @brief Get if the network status is suitable for sending video.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE It is suitable for sending video.
 * @retval ZFALSE It is not suitable for sending video.
 */
ZFUNC ZBOOL Mtc_SessVideoGetSendAdvice(ZUINT iSessId);

/** 
 * @brief Get MTC session video received state.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Transport state type, @ref EN_MTC_CALL_TRANSMISSION_STATE.
 */
ZFUNC ZUINT Mtc_SessVideoGetRecv(ZUINT iSessId);

/** 
 * @brief MTC session get video size.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] piWidth Video width in pixel of specific session.
 * @param [out] piHeight Video height in pixel of specific session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessGetVideoSize(ZUINT iSessId, ZUINT *piWidth,
                ZUINT *piHeight);

/** 
 * @brief MTC session get remote video size.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] piWidth Video width in pixel of specific session.
 * @param [out] piHeight Video height in pixel of specific session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessGetVideoRemoteSize(ZUINT iSessId, ZUINT *piWidth,
                ZUINT *piHeight);

/** 
 * @brief MTC session get local video size.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] piWidth Video width in pixel of specific session.
 * @param [out] piHeight Video height in pixel of specific session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessGetVideoLocalSize(ZUINT iSessId, ZUINT *piWidth,
                ZUINT *piHeight);

/**
 * @brief MTC session get network status of video stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Network status @ref EN_MTC_NET_STATUS_TYPE.
 */
ZFUNC ZINT Mtc_SessGetVideoNetSta(ZUINT iSessId);

/**
 * @brief MTC session get network status of audio stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Network status @ref EN_MTC_NET_STATUS_TYPE.
 */
ZFUNC ZINT Mtc_SessGetAudioNetSta(ZUINT iSessId);

/**
 * @brief MTC session get session state.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Session state @ref EN_MTC_SESSION_STATE_TYPE.
 */
ZFUNC ZINT Mtc_SessGetState(ZUINT iSessId);

/** 
 * @brief MTC session check if has a active video stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on yes.
 * @retval ZFALSE on no.
 *
 * @see @ref Mtc_SessVideoStart, @ref Mtc_SessVideoStop, @ref Mtc_SessHasAudio
 */
ZFUNC ZBOOL Mtc_SessHasVideo(ZUINT iSessId);

/** 
 * @brief MTC session check if has a active audio stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on yes.
 * @retval ZFALSE on no.
 *
 * @see @ref Mtc_SessHasVideo
 */
ZFUNC ZBOOL Mtc_SessHasAudio(ZUINT iSessId);

/** 
 * @brief MTC check session has entered in talking state.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on talking state.
 * @retval ZFALSE on talking state.
 *
 * @see @ref Mtc_SessCall, @ref Mtc_SessAnswer
 */
ZFUNC ZBOOL Mtc_SessHasTalk(ZUINT iSessId);

/** 
 * @brief MTC session get crypto state.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bVideo The video flag .
 *
 * @retval The crypto state for the session.
 *
 */
ZFUNC ZUINT Mtc_SessGetCryptoState(ZUINT iSessId, ZBOOL bVideo);

/** 
 * @brief MTC check session has entered in hold state.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on hold state.
 * @retval ZFALSE on hold state.
 *
 * @see @ref Mtc_SessHasHeld
 */
ZFUNC ZBOOL Mtc_SessHasHold(ZUINT iSessId);

/** 
 * @brief MTC check session has entered in held state.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on held state.
 * @retval ZFALSE on held  state.
 *
 * @see @ref Mtc_SessHasHold
 */
ZFUNC ZBOOL Mtc_SessHasHeld(ZUINT iSessId);

/** 
 * @brief MTC get the lost ratio in percentage of audio stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Lost ratio in percentage(0-1000).
 *
 * @see @ref Mtc_SessVideoLostRatio
 */
ZFUNC ZUINT Mtc_SessAudioLostRatio(ZUINT iSessId);

/** 
 * @brief MTC get the lost ratio in percentage of video stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Lost ratio in percentage(0-1000).
 *
 * @see @ref Mtc_SessAudioLostRatio
 */
ZFUNC ZUINT Mtc_SessVideoLostRatio(ZUINT iSessId);

/** 
 * @brief MTC get the lost count of audio stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Total lost count.
 *
 * @see @ref Mtc_SessVideoLostRatio
 */
ZFUNC ZUINT Mtc_SessAudioLostCount(ZUINT iSessId);

/** 
 * @brief MTC get the lost count of video stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Total lost count.
 *
 * @see @ref Mtc_SessAudioLostCount
 */
ZFUNC ZUINT Mtc_SessVideoLostCount(ZUINT iSessId);

/** 
 * @brief MTC get the round trip time of audio stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Round trip time in milliseconds.
 *
 * @see @ref Mtc_SessVideoRtt
 */
ZFUNC ZUINT Mtc_SessAudioRtt(ZUINT iSessId);

/** 
 * @brief MTC get the round trip time of video stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Round trip time in milliseconds.
 *
 * @see @ref Mtc_SessAudioRtt
 */
ZFUNC ZUINT Mtc_SessVideoRtt(ZUINT iSessId);

/** 
 * @brief MTC get the jitter of audio stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Jitter in milliseconds.
 *
 * @see @ref Mtc_SessVideoJitter
 */
ZFUNC ZUINT Mtc_SessAudioJitter(ZUINT iSessId);

/** 
 * @brief MTC get the jitter of video stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return Jitter in milliseconds.
 *
 * @see @ref Mtc_SessAudioJitter
 */
ZFUNC ZUINT Mtc_SessVideoJitter(ZUINT iSessId);

/** 
 * @brief MTC get audio stream traffic data for following:
 * send bitrate, receive bitrate, send bytes, receive bytes
 *
 * @param [in] iSessId The ID of session.
 * @param [out] piSentBps The sent traffic in bps.
 * @param [out] piRecvBps The received traffic in bps.
 * @param [out] piRecvBytes The received bytes.
 * @param [out] piSendBytes The send bytes.
 *
 * @retval ZOK Get successfully.
 * @retval ZFAILED Get failed.
 *
 * @see @ref Mtc_SessVideoTrafficData
 */
ZFUNC ZINT Mtc_SessAudioTrafficData(ZUINT iSessId,
                ZUINT *piSentBps,   ZUINT *piRecvBps, 
                ZUINT *piSentBytes, ZUINT *piRecvBytes);

/** 
 * @brief MTC get video stream traffic data for following:
 * send bitrate, receive bitrate, send bytes, receive bytes
 *
 * @param [in] iSessId The ID of session.
 * @param [out] piSentBps The sent traffic in bps.
 * @param [out] piRecvBps The received traffic in bps.
 * @param [out] piRecvBytes The received bytes.
 * @param [out] piSendBytes The send bytes.
 *
 * @retval ZOK Get successfully.
 * @retval ZFAILED Get failed.
 *
 * @see @ref Mtc_SessAudioTrafficData
 */
ZFUNC ZINT Mtc_SessVideoTrafficData(ZUINT iSessId,
                ZUINT *piSentBps,   ZUINT *piRecvBps, 
                ZUINT *piSentBytes, ZUINT *piRecvBytes);

/** 
 * @brief MTC session check if peer offer a video stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on yes.
 * @retval ZFALSE on no.
 *
 * @see @ref Mtc_SessVideoStart, @ref Mtc_SessVideoStop, @ref Mtc_SessPeerOfferAudio
 */
ZFUNC ZBOOL Mtc_SessPeerOfferVideo(ZUINT iSessId);

/** 
 * @brief MTC session check if peer offer a audio stream.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on yes.
 * @retval ZFALSE on no.
 *
 * @see @ref Mtc_SessPeerOfferVideo
 */
ZFUNC ZBOOL Mtc_SessPeerOfferAudio(ZUINT iSessId);

/** 
 * @brief MTC session get the mute status of microphone.
 *
 * @param [in] iSessId The ID of session which you want to get.
 *
 * @retval ZTRUE on muted.
 * @retval ZFALSE on not muted.
 *
 * @see @ref Mtc_SessSetMicMute
 */
ZFUNC ZBOOL Mtc_SessGetMicMute(ZUINT iSessId);

/** 
 * @brief MTC session set the mute status of microphone.
 *
 * @param [in] iSessId The ID of session which you want to set.
 * @param [in] bMute Indicate whether to mute the microphone.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessGetMicMute @ref Mtc_SessSetMicMuteAll
 */
ZFUNC ZINT Mtc_SessSetMicMute(ZUINT iSessId, ZBOOL bMute);

/** 
 * @brief MTC session set the mute status of microphone, which not related to the call session.
 *
 * @param [in] bMute Indicate whether to mute the microphone.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessSetMicMute
 */
ZFUNC ZINT Mtc_SessSetMicMuteAll(ZBOOL bMute);

/** 
 * @brief MTC session get scale of microphone.
 *
 * @param [in] iSessId The ID of session which you want get.
 *
 * @return Scale value, from 0.0 to 10.0, 1.0 for no scaling.
 *
 * @see @ref Mtc_SessSetMicScale
 */
ZFUNC ZFLOAT Mtc_SessGetMicScale(ZUINT iSessId);

/** 
 * @brief MTC session set scale of microphone.
 *
 * @param [in] iSessId The ID of session which you want set.
 * @param [in] fScale Scale value, from 0.0 to 10.0, 1.0 for no scaling.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessGetMicScale
 */
ZFUNC ZINT Mtc_SessSetMicScale(ZUINT iSessId, ZFLOAT fScale);

/** 
 * @brief MTC session get the mute status of speaker.
 *
 * @param [in] iSessId The ID of session which you want to get.
 *
 * @retval ZTRUE on muted.
 * @retval ZFALSE on not muted.
 *
 * @see @ref Mtc_SessSetSpkMute
 */
ZFUNC ZBOOL Mtc_SessGetSpkMute(ZUINT iSessId);

/** 
 * @brief MTC session set the mute status of speaker.
 *
 * @param [in] iSessId The ID of session which you want to set.
 * @param [in] bMute Indicate whether to mute the speaker.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessGetSpkMute
 */
ZFUNC ZINT Mtc_SessSetSpkMute(ZUINT iSessId, ZBOOL bMute);

/** 
 * @brief MTC session get scale of speaker.
 *
 * @param [in] iSessId The ID of session which you want get.
 *
 * @return Scale value, from 0.0 to 10.0, 1.0 for no scaling.
 *
 * @see @ref Mtc_SessSetSpkScale
 */
ZFUNC ZFLOAT Mtc_SessGetSpkScale(ZUINT iSessId);

/** 
 * @brief MTC session set scale of speaker.
 *
 * @param [in] iSessId The ID of session which you want set.
 * @param [in] fScale Scale value, from 0.0 to 10.0, 1.0 for no scaling.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessGetSpkScale
 */
ZFUNC ZINT Mtc_SessSetSpkScale(ZUINT iSessId, ZFLOAT fScale);

/** 
 * @brief MTC session get volume of speaker.
 *
 * @param [in] iSessId The ID of session which you want get.
 *
 * @return Volume value, from 0 to 20.
 *
 * @see @ref Mtc_SessSetSpkVol
 */
ZFUNC ZUINT Mtc_SessGetSpkVol(ZUINT iSessId);

/** 
 * @brief MTC session set volume of speaker.
 *
 * @param [in] iSessId The ID of session which you want set.
 * @param [in] iVol Volume value, from 0 to 20.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessGetSpkVol
 */
ZFUNC ZINT Mtc_SessSetSpkVol(ZUINT iSessId, ZUINT iVol);

/** 
 * @brief MTC session get mix voice status.
 *
 * @param [in] iSessId The ID of session which you want to set.
 *
 * @return mix voice status.
 */
ZFUNC ZBOOL Mtc_SessGetMixVoice(ZUINT iSessId);

/** 
 * @brief MTC session set mix voice status.
 *
 * @param [in] iSessId The ID of session which you want to set.
 * @param [in] bEnable Indicate whether to mix voice. If ZTRUE, it will mix
 *                     corresponding session's voice.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessSetMixVoice(ZUINT iSessId, ZBOOL bEnable);

/** 
 * @brief MTC session get cookie value.
 *
 * @param [in] iSessId The ID of session which you want to get cookie of.
 *
 * @return The cookie of session.
 *
 * The cookie value could be set by @ref Mtc_SessCall, @ref Mtc_SessAnswer or
 * @ref Mtc_SessSetCookie previously.
 *
 * @see @ref Mtc_SessCall, @ref Mtc_SessAnswer, @ref Mtc_SessSetCookie
 */
ZFUNC ZCOOKIE Mtc_SessGetCookie(ZUINT iSessId);

/** 
 * @brief MTC session set cookie value.
 *
 * @param [in] iSessId The ID of session which you want to set cookie.
 * @param [in] zCookie The cookie which you want to set.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessCall, @ref Mtc_SessAnswer, @ref Mtc_SessGetCookie
 */
ZFUNC ZINT Mtc_SessSetCookie(ZUINT iSessId, ZCOOKIE zCookie);

/** 
 * @brief MTC session get local tag string.
 *
 * @param [in] iSessId The ID of session which you want to get.
 * @param [out] ppcLocalTag The string of local tag.
 *
 *   The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessGetLocalTag(ZUINT iSessId, ZCHAR **ppcLocalTag);

/** 
 * @brief MTC session get Call-ID string.
 *
 * @param [in] iSessId The ID of session which you want to get.
 * @param [out] ppcCallId The string of Call-ID.
 *
 *   The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessGetCallId(ZUINT iSessId, ZCHAR **ppcCallId);

/** 
 * @brief MTC session get peer URI and display name.
 *
 * @param [in] iSessId The ID of session which you want to get.
 * @param [out] ppcDispName The display name of peer user.
 * @param [out] ppcUri The URI of peer user.
 *
 *   The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * The peer information get by this function is actually from FROM/TO header in
 * SIP message. So the true identity of peer user is not asserted by server.
 *
 * @see @ref Mtc_SessGetPeerId
 */
ZFUNC ZINT Mtc_SessGetPeerUri(ZUINT iSessId, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri);

/** 
 * @brief MTC session get peer id, based on polices.
 *
 * @param [in] iSessId The ID of session which you want to get.
 * @param [out] ppcDispName The display name of peer user which you have this session with.
 * @param [out] ppcUri The URI of peer user which you have this session with.
 *
 *   The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * Note the result of this function may be different with Mtc_SessGetPeerUri
 * because the apply of polices. For example, OIP, OIR, TIP, TIR, and privacy.
 *
 * @see @ref Mtc_SessGetPeerUri
 */
ZFUNC ZINT Mtc_SessGetPeerId(ZUINT iSessId, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri);

/** 
 * @brief MTC session check if the peer is contains isfocus parameter.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on peer is focus.
 * @retval ZFALSE on peer no focus.
 */
ZFUNC ZBOOL Mtc_SessPeerIsFocus(ZUINT iSessId);

/** 
 * @brief MTC session get paticipant size.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return The paticipant size.
 *
 * @see Mtc_SessGetPartpUri, Mtc_SessGetPartpStat
 */
ZFUNC ZINT Mtc_SessGetPartpSize(ZUINT iSessId);

/** 
 * @brief MTC session get paticipant uri and display name.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] iIndex The paticipant index.
 * @param [out] ppcDispName The display name of paticipant.
 * @param [out] ppcUri The uri of paticipant.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessGetPartpSize, @ref Mtc_SessGetPartpStat
 */
ZFUNC ZINT Mtc_SessGetPartpUri(ZUINT iSessId, ZINT iIndex, 
                ZCHAR **ppcDispName, ZCHAR **ppcUri);

/** 
 * @brief MTC session get paticipant state.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] iIndex The paticipant index.
 * @param [out] ppcDispName The display name of paticipant.
 * @param [out] ppcUri The uri of paticipant.
 *
 * @retrun The paticipant state, @see @ref EN_MTC_SESS_PARTP_STATE_TYPE
 *
 * @see @ref Mtc_SessGetPartpSize, @ref Mtc_SessGetPartpUri
 */
ZFUNC ZUINT Mtc_SessGetPartpStat(ZUINT iSessId, ZINT iIndex);

/** 
 * @brief MTC session check if the offer/answer exchange is completed.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on offer has answer.
 * @retval ZFALSE on offer has not answer.
 *
 * @see @ref Mtc_SessGetEarlyMediaStatus
 */
ZFUNC ZBOOL Mtc_SessHasOfferAnswer(ZUINT iSessId);

/** 
 * @brief MTC session get alert information type.
 *
 * @param [in] iSessId The ID of session which you want to get.
 *
 * @retval @ref EN_MTC_CALL_ALERT_INFO_TYPE.
 *
 * The information get by this function is actually from Alert-Info header 
 * in SIP message.
 */
ZFUNC ZUINT Mtc_SessGetAlertInfo(ZUINT iSessId);

/** 
 * @brief MTC session get the early media status.
 *
 * @param [in] iSessId The ID of session which you want to get its early media
 *                      status.
 * @param [in] bVideo If ZTRUE, get video status, otherwise get audio status.
 *
 * @retval @ref EN_MTC_CALL_EM_STATUS_TYPE.
 *
 * @see @ref Mtc_SessHasOfferAnswer
 */
ZFUNC ZUINT Mtc_SessGetEarlyMediaStatus(ZUINT iSessId, 
                ZBOOL bVideo);

/**
 * @brief Reccord mic start.
 *
 * It will reccord from mic to file.
 *
 * @param [in] pcFileName The reccord file name.
 * @param [in] ucFileType The reccord file type, @ref EN_MTC_MFILE_TYPE
 *
 * @retval ZOK Audio Reccord  successfully.
 * @retval ZFAILED Audio Reccord failed.
 *
 * @see @ref Mtc_SessRecMicStop
 */
ZFUNC ZINT Mtc_SessRecMicStart(ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType);

/**
 * @brief Reccord Audio stop.
 *
 * @see @ref Mtc_SessRecMicStart
 */
ZFUNC ZINT Mtc_SessRecMicStop(ZFUNC_VOID);

/** 
 * @brief MTC session record playout.
 *
 * @param [in] iSessId The ID of session which you want to record, 
 *                      if iSessId is invalid, record the mix playout.
 * @param [in] pcFileName The reccord file name.
 * @param [in] ucFileType The reccord file type, @ref EN_MTC_MFILE_TYPE
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessRecPlayStart(ZUINT iSessId, ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType);

/** 
 * @brief MTC session stop record playout.
 *
 * @param [in] iSessId The ID of session which you want to stop record, 
 *                      if iSessId is invalid, stop record the mix playout.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessRecPlayStop(ZUINT iSessId);

/** 
 * @brief MTC session start send sound from file.
 *
 * @param [in] iSessId The ID of session which you want to send sound from file. 
 * @param [in] pcFileName The reccord file name.
 * @param [in] ucFileType The reccord file type, @ref EN_MTC_MFILE_TYPE
 * @param [in] bLoop ZFALSE if play once.
 * @param [in] bMix If false, microphone sound is replaced by file sound;
 *                  if true, microphone sound is mixed with file sound
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessSndStartSend(ZUINT iSessId, ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType, ZBOOL bLoop, ZBOOL bMix);

/** 
 * @brief MTC session stop send sound.
 *
 * @param [in] iSessId The ID of session which you want to stop sound from file. 
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessSndStopSend(ZUINT iSessId);

/** 
 * @brief MTC session start play sound from file.
 *
 * @param [in] pcFileName The reccord file name.
 * @param [in] ucFileType The reccord file type, @ref EN_MTC_MFILE_TYPE
 * @param [in] bOnce ZTRUE if play once, ZFALSE if play loop.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessSndStartPlay(ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType, ZBOOL bOnce);

/** 
 * @brief MTC session stop play sound.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessSndStopPlay(ZFUNC_VOID);

/** 
 * @brief MTC session start send bgm from file.
 *
 * @param [in] iSessId The ID of session which you want to record, 
 *                      if iSessId is invalid, record the mix playout.
 * @param [in] pcFileName The reccord file name.
 * @param [in] ucFileType The reccord file type, @ref EN_MTC_MFILE_TYPE
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessSndStartBgm(ZUINT iSessId, ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType);

/** 
 * @brief MTC session stop send bgm.
 *
 * @param [in] iSessId The ID of session which you want to send sound, 
 *                      if iSessId is invalid, stop send sound.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessSndStopBgm(ZUINT iSessId);

/**
 * @brief Reccord call start.
 *
 * It will reccord from call to file.
 *
 * @param [in] pcFileName The reccord file name.
 * @param [in] ucFileType The reccord file type, @ref EN_MTC_MFILE_TYPE
 *
 * @retval ZOK Audio Reccord  successfully.
 * @retval ZFAILED Audio Reccord failed.
 *
 * @see @ref Mtc_SessRecCallStop
 */
ZFUNC ZINT Mtc_SessRecCallStart(ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType);

/**
 * @brief Reccord Audio stop.
 *
 * @see @ref Mtc_SessRecCallStart
 */
ZFUNC ZINT Mtc_SessRecCallStop(ZFUNC_VOID);

/** 
 * @brief Mtc session start recording sound.
 *
 * @param [in] iSessId The ID of session whose sound you want to record.
 * @param [in] pcFileName The recording file name.
 * @param [in] ucFileType The recording file type, @ref EN_MTC_MFILE_TYPE.
 * @param [in] iRecMode The recording mode. @ref EN_MTC_CALL_REC_MODE_TYPE.
 *
 * @see @ref Mtc_SessRecSndStop
 */
ZFUNC ZINT Mtc_SessRecSndStart(ZUINT iSessId, ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType, ZUINT iRecMode);

/** 
 * @brief Mtc session stop recording sound.
 *
 * @param [in] iSessId The ID of session.
 *
 * @see @ref Mtc_SessRecSndStart
 */
ZFUNC ZINT Mtc_SessRecSndStop(ZUINT iSessId);

/** 
 * @brief Mtc session get audio statistics.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval String of audio statistics.
 */
ZFUNC ZCONST ZCHAR * Mtc_SessGetAudioStat(ZUINT iSessId);

/** 
 * @brief Mtc session get video statistics.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval String of video statistics.
 */
ZFUNC ZCONST ZCHAR * Mtc_SessGetVideoStat(ZUINT iSessId);

/**
 * @brief MTC session set state of receiving-side AGC.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bEnable ZTRUE to enable Rx-AGC, ZFALSE to disable Rx-AGC.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessGetRxAgcEnable
 */
ZFUNC ZINT Mtc_SessSetRxAgcEnable(ZUINT iSessId, ZBOOL bEnable);

/**
 * @brief MTC session get state of receiving-side AGC.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pbEnable Current state of Rx-AGC.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessSetRxAgcEnable
 */
ZFUNC ZINT Mtc_SessGetRxAgcEnable(ZUINT iSessId, ZBOOL *pbEnable);

/**
 * @brief MTC session set mode of receiving-side AGC.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] ucMode Mode of Rx-AGC, @ref EN_MTC_RX_GC_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessGetRxAgcMode
 */
ZFUNC ZINT Mtc_SessSetRxAgcMode(ZUINT iSessId, ZUCHAR ucMode);

/**
 * @brief MTC session get mode of receiving-side AGC.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pucMode Mode of Rx-AGC, @ref EN_MTC_RX_GC_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessSetRxAgcMode
 */
ZFUNC ZINT Mtc_SessGetRxAgcMode(ZUINT iSessId, ZUCHAR *pucMode);

/**
 * @brief MTC session set traget dBOV of receiving-side AGC.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] wTargetDb Traget dBOV of Rx-AGC.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessGetRxAgcTarget
 */
ZFUNC ZINT Mtc_SessSetRxAgcTarget(ZUINT iSessId, ZUSHORT wTargetDb);

/**
 * @brief MTC session get traget dBOV of receiving-side AGC.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pwTargetDb Traget dBOV of Rx-AGC.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessSetRxAgcTarget
 */
ZFUNC ZINT Mtc_SessGetRxAgcTarget(ZUINT iSessId, ZUSHORT *pwTargetDb);

/**
 * @brief MTC session set state of receiving-side ANR.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bEnable ZTRUE to enable Rx-ANR, ZFALSE to disable Rx-ANR.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessGetRxAnrEnable
 */
ZFUNC ZINT Mtc_SessSetRxAnrEnable(ZUINT iSessId, ZBOOL bEnable);

/**
 * @brief MTC session get state of receiving-side ANR.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pbEnable Current state of Rx-ANR.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessSetRxAnrEnable
 */
ZFUNC ZINT Mtc_SessGetRxAnrEnable(ZUINT iSessId, ZBOOL *pbEnable);

/**
 * @brief MTC session set mode of receiving-side ANR.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] ucMode Mode of Rx-ANR, @ref EN_MTC_NS_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessGetRxAnrMode
 */
ZFUNC ZINT Mtc_SessSetRxAnrMode(ZUINT iSessId, ZUCHAR ucMode);

/**
 * @brief MTC session get mode of receiving-side ANR.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pucMode Mode of Rx-ANR, @ref EN_MTC_NS_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessSetRxAnrMode
 */
ZFUNC ZINT Mtc_SessGetRxAnrMode(ZUINT iSessId, ZUCHAR *pucMode);

/**
 * @brief MTC session set state of VAD.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bEnable ZTRUE to enable VAD, ZFALSE to disable VAD.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessGetVadEnable
 */
ZFUNC ZINT Mtc_SessSetVadEnable(ZUINT iSessId, ZBOOL bEnable);

/**
 * @brief MTC session get state of VAD.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pbEnable Current state of VAD.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessSetVadEnable
 */
ZFUNC ZINT Mtc_SessGetVadEnable(ZUINT iSessId, ZBOOL *pbEnable);

/**
 * @brief MTC session set mode of VAD.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] ucMode Mode of VAD, @ref EN_MTC_VAD_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessGetVadMode
 */
ZFUNC ZINT Mtc_SessSetVadMode(ZUINT iSessId, ZUCHAR ucMode);

/**
 * @brief MTC session get mode of VAD.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pucMode Mode of VAD, @ref EN_MTC_VAD_TYPE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessSetVadMode
 */
ZFUNC ZINT Mtc_SessGetVadMode(ZUINT iSessId, ZUCHAR *pucMode);

/**
 * @brief MTC session set send sound from file loop option.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bLoop The loop option.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_SessGetSndSendLoopOption
 */
ZFUNC ZINT Mtc_SessSetSndSendLoopOption(ZUINT iSessId, ZBOOL bLoop);

/**
 * @brief MTC session get send sound from file loop option.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pbLoop Current loop option of  sending sound from file.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_SessSetSndSendLoopOption
 */
ZFUNC ZINT Mtc_SessGetSndSendLoopOption(ZUINT iSessId, ZBOOL *pbLoop);

/**
 * @brief MTC session enable/disable color enhancement.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bEnable ZTRUE to enable color enhancement, 
 *                     ZFALSE to disable color enhancement.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
ZFUNC ZINT Mtc_SessEnhanceColor(ZUINT iSessId, ZBOOL bEnable);

/**
 * @brief MTC session enable/disable CPU load control.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bEnable ZTRUE to enable CPU load control, 
 *                     ZFALSE to disable CPU load control.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
ZFUNC ZINT Mtc_SessArsEnableCpuCtrl(ZUINT iSessId, ZBOOL bEnable);

/**
 * @brief MTC session set target usage percent of CPU load control.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] iLoad Target usage percent of CPU load control, should be 0-100.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
ZFUNC ZINT Mtc_SessArsSetCupCtrlTgt(ZUINT iSessId, ZUINT iLoad);

/**
 * @brief MTC session enable/disable bandwidth efficient mode.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bEnable ZTRUE to enable bandwidth efficient mode, 
 *                     ZFALSE to disable bandwidth efficient mode.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
ZFUNC ZINT Mtc_SessArsEnableBem(ZUINT iSessId, ZBOOL bEnable);

/**
 * @brief MTC session ARS get video bitrate in bps.
 * @param  [in] iSessId  The ID of session.
 * @param  [out] piBitrate Current max bitrate of ARS in bps.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
ZFUNC ZINT Mtc_SessArsGetVideoBitrate(ZUINT iSessId, ZUINT *piBitrate);

/**
 * @brief MTC session ARS set video bitrate in bps.
 * @param  [in] iSessId  The ID of session.
 * @param  [in] iBitrate Max bitrate of ARS in bps.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
ZFUNC ZINT Mtc_SessArsSetVideoBitrate(ZUINT iSessId, ZUINT iBitrate);

/**
 * @brief MTC session start recoding incoming video.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] pcFileName Name of the file which to store the recording data.
 * @param [in] ucFileType File type, @ref EN_MTC_MFILE_TYPE.
 * @param [in] iWidth Video width in pixel of recoding data.
 * @param [in] iHeight Video height in pixel of recoding data.
 * @param [in] bWithAudio ZTRUE to recording audio data.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessRecRecvVideoStop
 */
ZFUNC ZINT Mtc_SessRecRecvVideoStart(ZUINT iSessId, 
                ZCONST ZCHAR *pcFileName, ZUCHAR ucFileType, ZUINT iWidth, 
                ZUINT iHeight, ZBOOL bWithAudio);

/**
 * @brief MTC session start recoding incoming video and two-way audio.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] pcFileName Name of the file which to store the recording data.
 * @param [in] ucFileType File type, @ref EN_MTC_MFILE_TYPE.
 * @param [in] iWidth Video width in pixel of recoding data.
 * @param [in] iHeight Video height in pixel of recoding data.
 * @param [in] bWithAudio ZTRUE to recording audio data.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessRecRecvVideoStop
 */
ZFUNC ZINT Mtc_SessRecRecvVideoStartX(ZUINT iSessId, 
                ZCONST ZCHAR *pcFileName, ZUCHAR ucFileType, ZUINT iWidth, 
                ZUINT iHeight, ZBOOL bWithAudio);

/**
 * @brief MTC session stop recoding incoming video.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessRecRecvVideoStart
 */
ZFUNC ZINT Mtc_SessRecRecvVideoStop(ZUINT iSessId);

/**
 * @brief MTC session start recoding sending video.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] pcFileName Name of the file which to store the recording data.
 * @param [in] ucFileType File type, @ref EN_MTC_MFILE_TYPE.
 * @param [in] iWidth Video width in pixel of recoding data.
 * @param [in] iHeight Video height in pixel of recoding data.
 * @param [in] bWithAudio ZTRUE to recording audio data.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessRecSendVideoStop
 */
ZFUNC ZINT Mtc_SessRecSendVideoStart(ZUINT iSessId, 
                ZCONST ZCHAR *pcFileName, ZUCHAR ucFileType, 
                ZUINT iWidth, ZUINT iHeight, ZBOOL bWithAudio);

/**
 * @brief MTC session stop recoding sending video.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see @ref Mtc_SessRecSendVideoStart
 */
ZFUNC ZINT Mtc_SessRecSendVideoStop(ZUINT iSessId);

/**
 * @brief Take a snapshot of display render.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] pcFileName Name of the file which to store the picture.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_SessCaptureSnapshot
 */
ZFUNC ZINT Mtc_SessRenderSnapshot(ZUINT iSessId, ZCONST ZCHAR *pcFileName);

/**
 * @brief Take a snapshot of capture.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] pcFileName Name of the file which to store the picture.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_SessRenderSnapshot
 */
ZFUNC ZINT Mtc_SessCaptureSnapshot(ZUINT iSessId, ZCONST ZCHAR *pcFileName);

/**
 * @brief MTC session play file as camera.
 *
 * @param [in] pcFileName Video file name.
 * @param [in] iAudioStrmId Audio stream id, @see Mtc_SessGetStrmId.
 * @param [in] iCycle 0 to play once, otherwise to loop play .
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_SessFilePlayStop
 */
ZFUNC ZINT Mtc_SessFilePlayAsCamera(ZCONST ZCHAR *pcFileName, 
                ZUINT iAudioStrmId, ZUINT iCycle);

/**
 * @brief MTC session stop play file.
 *
 * @param [in] pcFileName Video file name.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_SessFilePlayAsCamera
 */
ZFUNC ZINT Mtc_SessFilePlayStop(ZCONST ZCHAR *pcFileName);

/**
 * @brief Get stream ID of the call session.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] ucStrmType The stream type of session, @ref EN_MTC_SESS_MEDIA_TYPE.
 *
 * @return The stream id of the call session on succeed, otherwise return ZMAXUINT.
 *
 */
ZFUNC ZUINT Mtc_SessGetStrmId(ZUINT iSessId, ZUCHAR ucStrmType);

/**
 * @brief MTC session set record video quality; 
 *        Need to be called before Start record.
 *
 * @param [in] iFps Record video framerate.
 * @param [in] ucQuality Record video quality, @ref EN_MTC_REC_QUALITY.
 * @param [in] ucFileType File type, @ref EN_MTC_MFILE_TYPE.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessRecSetQuality(ZUINT iFps, ZUCHAR ucQuality, ZUCHAR ucFileType);

/**
 * @brief MTC session get terminate reason description.
 *
 * @param [in] iStatCode The status code.
 *
 * @return The status code description successfully, otherwise return "UNKNOWN".
 */
ZFUNC ZCHAR * Mtc_SessGetStatDesc(ZUINT iStatCode);

/** 
 * @brief MTC session get history info size.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return The history info size.
 */
ZFUNC ZINT Mtc_SessGetHisInfoSize(ZUINT iSessId);

/** 
 * @brief MTC session get history info diverting uri.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] iIndex The index of history info.
 * @param [out] ppcName The display name.
 * @param [out] ppcUri The diverting uri.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessGetHisInfoDivUri(ZUINT iSessId, ZUINT iIndex, 
                ZCHAR **ppcName, ZCHAR **ppcUri);

/** 
 * @brief MTC session get history info diverting uri gruu.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] iIndex The index of history info.
 *
 * @return The history info diverting uri gruu.
 */
ZFUNC ZCHAR * Mtc_SessGetHisInfoGruu(ZUINT iSessId, ZUINT iIndex);

/** 
 * @brief MTC session get history info index string.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] iIndex The index of history info.
 *
 * @return The history info index string.
 */
ZFUNC ZCHAR * Mtc_SessGetHisInfoIndex(ZUINT iSessId, ZUINT iIndex);

/** 
 * @brief MTC session get history info cause.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] iIndex The index of history info.
 *
 * @return The history info cause.
 */
ZFUNC ZUINT Mtc_SessGetHisInfoCause(ZUINT iSessId, ZUINT iIndex);

/** 
 * @brief MTC session receive rtp data .
 *
 * @param [in] iStrmId The ID of stream.
 * @param [in] bVideo The video or audio flag, ZTRUE for video, ZFALSE for audio.
 * @param [in] pData The rtp data packet.
 * @param [in] iDataSize The rtp data length.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessRecvRtpData(ZUINT iStrmId, ZBOOL bVideo, 
                ZVOID *pData, ZUINT iDataSize);

/** 
 * @brief MTC session send rtp data .
 *
 * @param [in] iTptId The ID of transport id.
 * @param [in] pcRmtAddr The remote address.
 * @param [in] pData The rtp data packet.
 * @param [in] iDataSize The rtp data length.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_SessSendRtpData(ZUINT iTptId, ZCHAR *pcRmtAddr,
                ZVOID *pData, ZUINT iDataSize);

/** 
 * @brief MTC session get replaces info string.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return The replaces info string of the curretn call session, 
 *      which includes call dialog infos (call-id, from-tag, to-tag).
 */
ZFUNC ZCHAR * Mtc_SessGetReplaceInfo(ZUINT iSessId);

/**
 * @brief MTC session get Gain dBOV of receiving-side AGC(Automatic Gain Control).
 *
 * @param [in] iSessId The ID of session.
 * @param [out] *pwGainDb Return the Gain dBOV of receiving-side AGC.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_SessSetRxAgcGain
 */
ZFUNC ZINT Mtc_SessGetRxAgcGain(ZUINT iSessId, ZUSHORT *pwGainDb);

/**
 * @brief MTC session set the Gain dBOV of receiving-side AGC(Automatic Gain Control).
 *
 * @param [in] iSessId The ID of session.
 * @param [in] wGainDb The Gain dBOV of receiving-side AGC.
 *                     Range from 0-90, Recommend 0-32.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_SessGetRxAgcGain
 */
ZFUNC ZINT Mtc_SessSetRxAgcGain(ZUINT iSessId, ZUSHORT wGainDb);

/**
 * @brief MTC session et the gain dBOV of AGC(Automatic Gain Control).
 *
 * @param [out] *pwGainDb Return the Gain dBOV of AGC.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_SessSetAgcGain
 */
ZFUNC ZINT Mtc_SessGetAgcGain(ZUSHORT *pwGainDb);

/**
 * @brief MTC session set the gain dBOV of AGC(Automatic Gain Control).
 *
 * @param [in] wGainDb The Gain dBOV of AGC;
 *                     Range from 0-90, Recommend 0-32.
 *                     Default 9
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_SessGetAgcGain
 */
ZFUNC ZINT Mtc_SessSetAgcGain(ZUSHORT wGainDb);

/**
 * @brief  MTC session get current microphone mic level(0-100).
 *
 * @return microphone mic level.
 *
 * @see
 */
ZFUNC ZUINT Mtc_SessGetMicLv(ZFUNC_VOID);

/**
 * @brief MTC session get  speaker(playout) speech level(0-100).
 *
 * @param [in] iSessId The ID of session.
 *
 * @return speaker speech level.
 *
 * @see
 */
ZFUNC ZUINT Mtc_SessGetSpkLv(ZUINT iSessId);

/**
 * @brief MTC session get X-ZTE-Cause string.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return X-ZTE-Cause string.
 *
 * @see
 */
ZFUNC ZCHAR * Mtc_SessGetZTECause(ZUINT iSessId);

/**
 * @brief MTC session get media server ip address string.
 * 
 * @param [in] iSessId The ID of session.
 *
 * @return Media server ip address string, like "192.168.0.1".
 *
 */
ZFUNC ZCHAR * Mtc_SessGetMediaServerIpAddr(ZUINT iSessId);

/** 
 * @brief MTC session send subscription.
 *
 * @param [in] pcUri The destination URI to which you want to send subscription.
 * @param [in] pcBody The body string of Subscribe.
 *
 * @return The id of this subscription, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_SessUnSubs
 *
 */
ZFUNC ZUINT Mtc_SessSubs(ZCHAR *pcUri, ZCHAR *pcBody);

/** 
 * @brief MTC session un-subscribe.
 *
 * @param [in] iSubsId The ID of subscription which you want to send un subscribe.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_SessSubs
 */
ZFUNC ZINT Mtc_SessUnSubs(ZUINT iSubsId);

/** 
 * @brief MTC session get media stream direction.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bVideo The video stream flag.
 *
 * @retval the media stream direction, @ref EN_MTC_DB_STRM_DIR_TYPE.
 *
 */
ZFUNC ZUCHAR Mtc_SessGetStrmDirect(ZUINT iSessId, ZBOOL bVideo);

/**
 * @brief MTC session enable/disable dynamic reset encoder to change video image aspect.
 *            The function should be called before @ref Mtc_SessCameraAttach.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] bEnable ZTRUE to enable dynamic reset encoder, ZFALSE to disable it
 * @param [in] fFixedAspect,
 *             if < 0 the outgoing video image will be adaptive the capture (camera, always 4:3) aspect, 
 *             if =0 it will use codec  settings(always 16:9, to be adaptive with the devices), 
 *             if >0 will be with the setting fixed aspect(like 1.33, 1.77).
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 */
ZFUNC ZINT Mtc_SessEnableAdaptiveAspect(ZUINT iSessId, ZBOOL bEnable,
                ZFLOAT fFixedAspect);

/*
 * @brief Set MVD engine start record capturing video.
 *
 * @param [in] pcCaptureId capture device Id
 * @param [in] pcFileName Video file name.
 * @param [in] ucFileType Video file type, @ref EN_MTC_MFILE_TYPE.
 * @param [in] iWidth Video width.
 * @param [in] iHeight Video height.
 * @param [in] ucAudioSource Audio Source, @ref EN_MTC_AUDIO_SOURCE
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_SessRecCaptStop
 */
ZFUNC ZINT Mtc_SessFileRecCaptStart(ZCONST ZCHAR* pcCaptureId, ZCONST ZCHAR *pcFileName,
                           ZUCHAR ucFileType, ZUINT iWidth, ZUINT iHeight,
                           ZUCHAR ucAudioSource);

/**
 * @brief Set MVD engine stop record capturing video.
 *
 * @param [in] pcCaptureId capture device Id
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_SessFileRecCaptStart
 */
ZFUNC ZINT Mtc_SessRecCaptStop(ZCONST ZCHAR* pcCaptureId);

/**
 * @brief Get the recv StatusCode when it's at calling status.
 *
 * @param [in] the session id.
 *
 * @retval the string StatusCode received when it's at calling status.
 *
 * @see @ref Mtc_SessGetStatusCode
 */
ZFUNC ZCHAR *Mtc_SessGetStatusCode(ZUINT iSessId);

/**
 * @brief Get the unique call id sting to locate one call session.
 *
 * @param [in] the session id.
 *
 * @retval the unique call id stin string.
 *
 */
ZFUNC ZCHAR * Mtc_SessGetUniqueCallId(ZUINT iSessId);

/**
 * @brief obtain server transmit sdp flags.
 *
 * @param [in] iSessId the ID of session.
 *        [in] iAlertType @see EN_MTC_ALERT_TYPE
 * @retval ZTRUE on succeed.
 * @retval ZFALSE on failure.
 *
 * @see Mtc_SessHasServerAlert
 */
 ZFUNC ZBOOL Mtc_SessHasServerAlert(ZUINT iSessId, ZUINT iAlertType);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CALL_H__ */

