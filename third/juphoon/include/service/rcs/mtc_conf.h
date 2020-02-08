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
  File name     : mtc_conf.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC conference

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CONF_H__
#define _MTC_CONF_H__

/**
 * @file mtc_conf.h
 * @brief MTC Conference Interfaces
 *
 * This file includes conference interface function. Those function
 * is used to manage conferences.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC conference status code(error no or terminated code). */
#define MTC_CONF_ERR_NO                 (MTC_EBASE_CONF + 0) /**< @brief no error. */
#define MTC_CONF_ERR_AUTH_FAILED        (MTC_EBASE_CONF + 1) /**< @brief authentication failed, invalid user or password. */
#define MTC_CONF_ERR_SESS_TMR           (MTC_EBASE_CONF + 2) /**< @brief conference refresh error. */
#define MTC_CONF_ERR_FORBIDDEN          (MTC_EBASE_CONF + 3) /**< @brief conference forbidden. */
#define MTC_CONF_ERR_NOT_FOUND          (MTC_EBASE_CONF + 4) /**< @brief conference participant not found. */
#define MTC_CONF_ERR_NOT_ACPTED         (MTC_EBASE_CONF + 5) /**< @brief conference not accepted. */
#define MTC_CONF_ERR_TEMP_UNAVAIL       (MTC_EBASE_CONF + 6) /**< @brief conference participant temp unavailable. */
#define MTC_CONF_ERR_REQ_TERMED         (MTC_EBASE_CONF + 7) /**< @brief conference request terminated. */
#define MTC_CONF_ERR_INTERNAL_ERR       (MTC_EBASE_CONF + 8) /**< @brief server internal error. */
#define MTC_CONF_ERR_SRV_UNAVAIL        (MTC_EBASE_CONF + 9) /**< @brief service unavailable. */
#define MTC_CONF_ERR_COVIB_CANCEL       (MTC_EBASE_CONF + 10) /**< @brief conference terminated co-vibration cancel. */
#define MTC_CONF_ERR_SAMESIDE_TALK      (MTC_EBASE_CONF + 11) /**< @brief conference terminated by same side talk . */
#define MTC_CONF_ERR_SUBS_TERMED        (MTC_EBASE_CONF + 12) /**< @brief conference subscription terminated. */
#define MTC_CONF_TERM_BYE               (MTC_EBASE_CONF + 13) /**< @brief conference terminated by bye . */
#define MTC_CONF_TERM_NETWORK           (MTC_EBASE_CONF + 14) /**< @brief conference terminated by network error . */
#define MTC_CONF_ERR_BAD_REQ            (MTC_EBASE_CONF + 15) /**< @brief conference error by 400 bad request error. */
#define MTC_CONF_ERR_NOT_RCV_RING       (MTC_EBASE_CONF + 16) /**< @brief cmcc conference donot receive 183 error. */
#define MTC_CONF_TERM_CANCEL            (MTC_EBASE_CONF + 17) /**< @brief conference terminated by cancel. */
#define MTC_CONF_ERR_OTHER              (MTC_EBASE_CONF + 200) /**< @brief other error. */

/* @brief Type of MTC conference participant state type */
typedef enum EN_MTC_CONF_PARTP_STATE_TYPE
{
    EN_MTC_CONF_PARTP_STATE_PENDING,    /**<@brief Conference participant pending. */
    EN_MTC_CONF_PARTP_STATE_DIALINGIN,  /**<@brief Conference participant dialing in. */
    EN_MTC_CONF_PARTP_STATE_DIALINGOUT, /**<@brief Conference participant dialing out. */
    EN_MTC_CONF_PARTP_STATE_ALERTING,   /**<@brief Conference participant alerting. */
    EN_MTC_CONF_PARTP_STATE_CONNED,     /**<@brief Conference participant connected. */ 
    EN_MTC_CONF_PARTP_STATE_ONHOLD,     /**<@brief Conference participant onhold. */
    EN_MTC_CONF_PARTP_STATE_DISCING,    /**<@brief Conference participant disconnecting. */
    EN_MTC_CONF_PARTP_STATE_DISCED      /**<@brief Conference participant disconnected. */
} EN_MTC_CONF_PARTP_STATE_TYPE;

/** @brief Type of MTC conference network status. */
typedef enum EN_MTC_CONF_NET_STATUS_TYPE
{
    EN_MTC_CONF_NET_STATUS_DISCONNECTED = -3, /**< @brief Conference Disconnected from network. */
    EN_MTC_CONF_NET_STATUS_VERY_BAD  = -2, /**< @brief Conference Network status is very bad. */
    EN_MTC_CONF_NET_STATUS_BAD       = -1, /**< @brief Conference Network status is bad. */
    EN_MTC_CONF_NET_STATUS_NORMAL    = 0,  /**< @brief Conference Network status is normal. */
    EN_MTC_CONF_NET_STATUS_GOOD      = 1,  /**< @brief Conference Network status is good. */
    EN_MTC_CONF_NET_STATUS_VERY_GOOD = 2,  /**< @brief Conference Network status is very good. */
} EN_MTC_CONF_NET_STATUS_TYPE;

/** @brief Type of MTC conference video switch mode. */
typedef enum EN_MTC_CONF_VIDEO_SWITCH_MODE
{
    EN_MTC_CONF_VOICE_CONTROL_MODE = 1,    /**< @brief Conference voice control mode. */
    EN_MTC_CONF_CHAIRMAN_CONTROL_MODE = 2, /**< @brief Conference chairman control mode . */
} EN_MTC_CONF_VIDEO_SWITCH_MODE;

/** @brief Type of MTC conference multi-pic mode. */
typedef enum EN_MTC_CONF_MULTI_PIC_MODE
{
    EN_MTC_CONF_MULTI_PIC_ONE_BIG = 0,    /**< @brief One-big picture size mode. */
    EN_MTC_CONF_MULTI_PIC_ALL_SAME = 1, /**< @brief All same picture size mode. */
} EN_MTC_CONF_MULTI_PIC_MODE;

/** @brief mtc conference media type */
typedef enum EN_MTC_CONF_MEDIA_TYPE
{
    EN_MTC_CONF_MEDIA_AUDIO,
    EN_MTC_CONF_MEDIA_VIDEO
} EN_MTC_CONF_MEDIA_TYPE;

/** @brief mtc conference type */
typedef enum EN_MTC_CONF_TYPE
{
    EN_MTC_CONF_CS,                  /**< @brief cs http conference */
    EN_MTC_CONF_MCU,                 /**< @brief MCU sip conference */
    EN_MTC_CONF_MULTI_STREAM_VIDEO,  /**< @brief Multi-stream video http conference */
    EN_MTC_CONF_MULTI_STREAM_VOICE,  /**< @brief Multi-stream voice http conference */
    EN_MTC_CONF_OTHER                /**< @brief Other conference */
} EN_MTC_CONF_TYPE;

/** @brief mtc conference charge type */
typedef enum EN_MTC_CONF_CHARGE_TYPE
{
    EN_MTC_CONF_CHARGE_FREE_TIME = 1, /**< @brief charge free time */
    EN_MTC_CONF_CHARGE_WITH_CASH = 2, /**< @brief charge with cash */
    EN_MTC_CONF_CHARGE_PRESENTED = 3, /**< @brief presented balance */
    EN_MTC_CONF_CHARGE_PACKAGE = 9,   /**< @brief package recharge */
} EN_MTC_CONF_CHARGE_TYPE;

/** @brief mtc conference access type */
typedef enum EN_MTC_CONF_ACCESS_TYPE
{
    EN_MTC_CONF_ACCESS_OCS_WEB = 1,       /**< @brief ocs web access type */
    EN_MTC_CONF_ACCESS_ONLINE_OFFICE = 2, /**< @brief online office access type */
    EN_MTC_CONF_ACCESS_POCKET_OFFICE = 3, /**< @brief packet office access type */
    EN_MTC_CONF_ACCESS_OTHER = 99,        /**< @brief other access type */
} EN_MTC_CONF_ACCESS_TYPE;

/** @brief mtc conference service type */
typedef enum EN_MTC_CONF_SERVICE_TYPE
{
    EN_MTC_CONF_SERVICE_P2P = 1,          /**< @brief charge service p2p */
    EN_MTC_CONF_SERVICE_CONF = 2,         /**< @brief charge service conference(multi-call) */
} EN_MTC_CONF_SERVICE_TYPE;

/** @brief mtc conference account type */
typedef enum EN_MTC_CONF_ACCOUNT_TYPE
{
    EN_MTC_CONF_ACCOUNT_MAIN = 0,          /**< @brief main account */
    EN_MTC_CONF_ACCOUNT_CHILD = 1,         /**< @brief child acccount */
    EN_MTC_CONF_ACCOUNT_ENTERPRISE = 2,    /**< @brief enterprise acccount */
} EN_MTC_CONF_ACCOUNT_TYPE;

/** 
 * @brief MTC conference create.
 *
 * @param [in] iType The conference type, @ref EN_MTC_CONF_TYPE.
 *
 * @return The id of this new created conference on succeed, otherwise return ZMAXUINT.
 *
 * Different with the method of session creation, this function only malloc
 * the resource of conference. If you want to setup or join a conference, you need
 * step ahead by calling other functions.
 *
 * @see @ref Mtc_ConfSetup, @ref Mtc_ConfJoin
 */
ZFUNC ZUINT Mtc_ConfCreate(ZUINT iType);

/** 
 * @brief MTC setup a new conference as the creator.
 *
 * If setup a new conference as the creator, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCbSetOutgoing, @ref Mtc_ConfCbSetAlerted, @ref Mtc_ConfCbSetConned
 *
 * While receiving conference invitation, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCbSetIncoming.
 *
 * @param [in] iConfId The id of conference which you want to setup.
 * @param [in] zCookie Used to correspond conference with UI resource.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfCreate, @ref Mtc_ConfJoin
 */
ZFUNC ZINT Mtc_ConfSetup(ZUINT iConfId, ZCOOKIE zCookie);

/** 
 * @brief MTC join an already existed conference.
 *
 * If join a conference, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCbSetOutgoing, @ref Mtc_ConfCbSetAlerted, @ref Mtc_ConfCbSetConned
 *
 * @param [in] iConfId The id of conference which you want to join.
 * @param [in] zCookie Used to correspond conference with UI resource.
 * @param [in] pcUri The URI of existed conference.
 * @param [in] bVideo The video conference flag.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfCreate, @ref Mtc_ConfSetup
 */
ZFUNC ZINT Mtc_ConfJoin(ZUINT iConfId, ZCOOKIE zCookie, ZCHAR *pcUri, ZBOOL bVideo);

/** 
 * @brief MTC alert an incoming conference invite which is notified by
 *        callback function which was set by @ref Mtc_ConfCbSetIncoming.
 *
 * @param [in] iConfId The id of conference which you want to join.
 * @param [in] zCookie Used to correspond conference with UI resource.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * This function is used to tell the conference initiator that you have received
 * the invitation and give user an indication in UI layer. User should make a
 * decision whether accept the conference invitation.
 *
 * @see @ref Mtc_ConfCbSetIncoming, @ref Mtc_ConfAcpt
 */
ZFUNC ZINT Mtc_ConfAlert(ZUINT iConfId, ZCOOKIE zCookie);

/** 
 * @brief MTC accept an incoming conference invite which is notified by
 *        callback function which was set by @ref Mtc_ConfCbSetIncoming.
 *
 * If accept a conference invite, GUI will be notified by callback which
 * was set by @ref Mtc_ConfCbSetConned
 *
 * @param [in] iConfId The id of conference which you want to accept.
 * @param [in] zCookie Used to correspond conference with UI resource.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfCbSetIncoming, @ref Mtc_ConfAlert
 */
ZFUNC ZINT Mtc_ConfAcpt(ZUINT iConfId, ZCOOKIE zCookie);

/** 
 * @brief MTC conference hold.
 *
 * If hold the conference successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCbSetHoldOk
 *
 * If unhold the conference successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCbSetUnHoldOk
 *
 * If hold the conference failed, GUI will be notified by callback which
 * was set by @ref Mtc_ConfCbSetHoldFailed
 *
 * If unhold the conference failed, GUI will be notified by callback which
 * was set by @ref Mtc_ConfCbSetUnHoldFailed
 *
 * while receiving hold conference, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCbSetHeld
 * 
 * while receiving unhold conference, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCbSetUnHeld
 *
 * @param [in] iConfId The id of conference which you want to hold or unhold.
 * @param [in] bHold Indicate the willingness of hold or unhold.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfSetup
 */
ZFUNC ZINT Mtc_ConfHold(ZUINT iConfId, ZBOOL bHold);

/** 
 * @brief MTC invite new participant to conference. 
 *
 * @param [in] iConfId The id of conference to which you want invite new
 *                      participant.
 * @param [in] pcUri The uri of destination participant.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfKickUser, @ref Mtc_ConfIvtSess
 */
ZFUNC ZINT Mtc_ConfIvtUser(ZUINT iConfId, ZCHAR *pcUri);

/** 
 * @brief MTC invite new participant list to a new conference, this interface 
 *        will setup a new conference automatically.
 *
 * @param [in] iConfId The id of conference to which you want invite new
 *                      participant list.
 * @param [in] zCookie Used to correspond conference with UI resource.
 * @param [in] iPartpLstId The participant list id, UI shall use 
 *                      @ref Mtc_PartpLstCreate, @ref Mtc_PartpLstAddPartp 
 *                      to create the id.
 * @param [in] bVideo The video conference flag.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfKickUser
 */
ZFUNC ZINT Mtc_ConfIvtUserLst(ZUINT iConfId, ZCOOKIE zCookie, 
                ZUINT iPartpLstId, ZBOOL bVideo);
                
/** 
 * @brief MTC kick participant from conference. 
 *
 * @param [in] iConfId The id of conference to which you want kick participant.
 * @param [in] pcUri The uri of destination participant.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfIvtUser, @ref Mtc_ConfIvtSess
 */
ZFUNC ZINT Mtc_ConfKickUser(ZUINT iConfId, ZCHAR *pcUri);

/** 
 * @brief MTC invite new participant, which you already have a session with,
 *        to conference. 
 *
 * @param [in] iConfId The id of conference to which you want to invite new participant.
 * @param [in] iSessId The id of the session which you have with the
                        want-invited participant.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfKickUser
 *
 */
ZFUNC ZINT Mtc_ConfIvtSess(ZUINT iConfId, ZUINT iSessId);

/** 
 * @brief MTC invite new participant list, which you already have a session with,
 *        to conference, this interface will setup a new conference automatically.
 *
 * @param [in] iConfId The id of conference to which you want invite new
 *                      participant.
 * @param [in] zCookie Used to correspond conference with UI resource.
 * @param [in] iSessLstId The session list id which you have with the
 *                      want-invited participant, UI shall use 
 *                      @ref Mtc_PartpLstCreate, @ref Mtc_PartpLstAddPartp, 
 *                      @ref Mtc_PartpSetSessId to create the id.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfKickUser
 */
ZFUNC ZINT Mtc_ConfIvtSessLst(ZUINT iConfId, ZCOOKIE zCookie, 
                ZUINT iSessLstId);

/** 
 * @brief MTC conference terminate.
 *
 * @param [in] iConfId The id of conference which you want to terminate.
 * @param [in] iReason Indicate the terminate reason which may trigger some
                        service in S-CSCF.
 * @param [in] bTermConf the terminate conf flag. If ZTRUE, terminate the conferece
 *                     (which means the other participants will receive BYE to terminate the conference);
 *                     If ZFALSE, only leave the conference.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * Actually Mtc_ConfTerm does not free all resource allocated for this
 * conference. It only starts a terminating procedure. All resource will be
 * freed automatically when the procedure ends.
 *
 * @see @ref Mtc_ConfSetup, @ref Mtc_ConfJoin, @ref EN_MTC_CALL_TERM_REASON_TYPE
 */
ZFUNC ZINT Mtc_ConfTerm(ZUINT iConfId, ZUINT iReason, ZBOOL bTermConf);

/** 
 * @brief MTC conference get conference state.
 *  As for CS conference, UI should call @ref Mtc_ConfSetSeverConfId to save conference id  
 *  while receiving common template sip MESSAGE
 *
 * @param [in] iConfId The id of conference which you want to get the conference state.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfGetState(ZUINT iConfId);

/** 
 * @brief MTC select one participant as remote image.
 *
 * @param [in] iConfId The id of conference to which you want select one
 *                      participant as remote image.
 * @param [in] pcUri The uri of the selected participant.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfVideoSelectUsr(ZUINT iConfId, ZCHAR *pcUri);

/** 
 * @brief MTC remove one participant from conference.
 *      If one participant kicked out from the conference, its video image window still exist.
 *      Chairman should use this function to remove its video image window.
 *      The participants would receive callbacks set by @ref Mtc_ConfCbSetVideoStrmPtptUpdt.
 *
 * @param [in] iConfId The id of conference to which you want to remove.
 * @param [in] pcNum The phone number(e.g. +8613800000000) of the removed participant 
 *                with country code, neither TEL uri nor SIP URI.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfRmvUser(ZUINT iConfId, ZCONST ZCHAR *pcNum);

/** 
 * @brief MTC remove some participants from conference.
 *      If one participant kicked out from the conference, its video image window still exist.
 *      Chairman should use this function to remove its video image window.
 *      The participants would receive callbacks set by @ref Mtc_ConfCbSetVideoStrmPtptUpdt.
 *
 * @param [in] iConfId The id of conference to which you want to remove.
 * @param [in] iPartpLstId The participant list id, UI shall use 
 *                      @ref Mtc_PartpLstCreate, @ref Mtc_PartpLstAddPartp 
 *                      to create the id.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfRmvUserX(ZUINT iConfId, ZUINT iPartpLstId);

/** 
 * @brief MTC clear the data of remove user before .
 *      If one participant kicked out from the conference, when chairman want to invite him.
 *      into the conference again, chairman should use this function to clear the data
 *      of remove the user before first.
 *
 * @param [in] iConfId The id of conference 
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfRmvUserClearData(ZUINT iConfId);

/** 
 * @brief MTC conference get cookie value.
 *
 * @param [in] iConfId The id of conference which you want to get cookie of.
 *
 * @return The cookie of conference.
 *
 * The cookie value could be set by @ref Mtc_ConfSetup, @ref Mtc_ConfJoin or
 * Mtc_ConfAcpt previously.
 *
 * @see @ref Mtc_ConfSetup, @ref Mtc_ConfJoin, @ref Mtc_ConfAcpt
 */
ZFUNC ZCOOKIE Mtc_ConfGetCookie(ZUINT iConfId);

/** 
 * @brief MTC conference get peer URI and display name.
 *
 * @param [in] iConfId The id of conference which you want to get.
 * @param [out] ppcDispName The display name of conference.
 * @param [out] ppcUri The URI of conference.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfGetConfUri, @ref Mtc_ConfGetInitiatorUri
 */
ZFUNC ZINT Mtc_ConfGetPeerUri(ZUINT iConfId, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri);

/** 
 * @brief MTC conference get conference URI and display name.
 *
 * @param [in] iConfId The id of conference which you want to get.
 * @param [out] ppcDispName The display name of conference.
 * @param [out] ppcUri The URI of conference.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfGetPeerUri, @ref Mtc_ConfGetInitiatorUri
 */
ZFUNC ZINT Mtc_ConfGetConfUri(ZUINT iConfId, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri);

/** 
 * @brief MTC conference get initiator URI and display name.
 *
 * @param [in] iConfId The id of conference which you want to get.
 * @param [out] ppcDispName The display name of conference.
 * @param [out] ppcUri The URI of conference.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfGetPeerUri, @ref Mtc_ConfGetConfUri
 */
ZFUNC ZINT Mtc_ConfGetInitiatorUri(ZUINT iConfId, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri);

/** 
 * @brief MTC conference get paticipant size.
 *
 * @param [in] iConfId The id of conference which you want get.
 *
 * @return The paticipant size.
 *
 * @see Mtc_ConfGetPartpUri, Mtc_ConfGetPartpStat
 */
ZFUNC ZINT Mtc_ConfGetPartpSize(ZUINT iConfId);

/** 
 * @brief MTC conference get paticipant uri and display name.
 *
 * @param [in] iConfId The id of conference which you want get.
 * @param [in] iIndex The paticipant index.
 * @param [out] ppcDispName The display name of paticipant.
 * @param [out] ppcUri The uri of paticipant.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfGetPartpSize, @ref Mtc_ConfGetPartpStat
 */
ZFUNC ZINT Mtc_ConfGetPartpUri(ZUINT iConfId, ZINT iIndex, 
                ZCHAR **ppcDispName, ZCHAR **ppcUri);

/** 
 * @brief MTC conference get paticipant state.
 *
 * @param [in] iConfId The id of conference which you want get.
 * @param [in] iIndex The paticipant index.
 *
 * @retrun The paticipant state, @see @ref EN_MTC_CONF_PARTP_STATE_TYPE.
 *
 * @see @ref Mtc_ConfGetPartpSize, @ref Mtc_ConfGetPartpUri
 */
ZFUNC ZUINT Mtc_ConfGetPartpStat(ZUINT iConfId, ZINT iIndex);

/** 
 * @brief MTC conference get the mute status of microphone.
 *
 * @param [in] iConfId The ID of conference which you want to get.
 *
 * @retval ZTRUE on muted.
 * @retval ZFALSE on not muted.
 *
 * @see @ref Mtc_ConfSetMicMute
 */
ZFUNC ZBOOL Mtc_ConfGetMicMute(ZUINT iConfId);

/** 
 * @brief MTC conference set the mute status of microphone.
 *
 * @param [in] iConfId The ID of conference which you want to set.
 * @param [in] bMute Indicate whether to mute the microphone.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfGetMicMute
 */
ZFUNC ZINT Mtc_ConfSetMicMute(ZUINT iConfId, ZBOOL bMute);

/** 
 * @brief MTC conference get the mute status of speaker.
 *
 * @param [in] iConfId The ID of conference which you want to get.
 *
 * @retval ZTRUE on muted.
 * @retval ZFALSE on not muted.
 *
 * @see @ref Mtc_ConfSetSpkMute
 */
ZFUNC ZBOOL Mtc_ConfGetSpkMute(ZUINT iConfId);

/** 
 * @brief MTC conference set the mute status of speaker.
 *
 * @param [in] iConfId The ID of conference which you want to set.
 * @param [in] bMute Indicate whether to mute the speaker.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfGetSpkMute
 */
ZFUNC ZINT Mtc_ConfSetSpkMute(ZUINT iConfId, ZBOOL bMute);

/** 
 * @brief MTC conference send DTMF info.
 *
 * @param [in] iConfId The ID of conference which you want to send DTMF info.
 * @param [in] iDtmfType DTMF type which will be sent, see @ref EN_MTC_CALL_DTMF_TYPE.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_ConfDtmf(ZUINT iConfId, ZUINT iDtmfType);

/** 
 * @brief MTC conference attach camera.
 *
 * @param [in] iConfId The ID of conference.
 * @param [in] pcName The name string of camera.
 * @param [in] iStrmId The ID of video stream.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_ConfCameraAttach(ZUINT iConfId, ZUINT iStrmId, ZCONST ZCHAR *pcName);

/** 
 * @brief MTC conference detach camera.
 *
 * @param [in] iConfId The ID of conference.
 * @param [in] iStrmId The ID of video stream.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_ConfCameraDetach(ZUINT iConfId, ZUINT iStrmId);

/**
 * @brief MTC get conference session name.
 *
 * @param [in] iConfId The ID of conference.
 * @param [in] iStrmId The ID of video stream.
 *
 * @return The Render name string when found, otherwise "".
 */
ZFUNC ZCONST ZCHAR * Mtc_ConfGetStrmName(ZUINT iConfId, ZUINT iStrmId);

/**
 * @brief MTC get conference stream ID from stream render name.
 *
 * @param pcName Render name string of the video stream.
 *
 * @return The ID of conference video stream ID when found, otherwise ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ConfStrmIdFromStrmName(ZUINT iConfId, ZCONST ZCHAR *pcName);


/**
 * @brief MTC get conference video stream count.
 *
 * @param [in] iConfId The ID of conference.
 *
 * @return The count of conference video stream.
 */
ZFUNC ZUINT Mtc_ConfGetVideoStrmCount(ZUINT iConfId);

/**
 * @brief MTC get conference  video stream id by index.
 *
 * @param [in] iConfId The ID of conference.
 *
 * @return The ID of conference video stream when found, otherwise ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ConfGetVideoStrmIdByIndex(ZUINT iConfId, ZUINT iIndex);

/**
 * @brief MTC get conference  video stream by stream id statistics.
 *
 * @param [in] iConfId The ID of conference.
 * @param [in] iStrmId The ID of video stream.  One conference may contains
 *                                one more video stream.
 *
 * @retval String of video statistics.
 */
ZFUNC ZCONST ZCHAR * Mtc_ConfGetVideoStat(ZUINT iConfId, ZUINT iStrmId);

/**
 * @brief MTC get conference  audio statistics.
 *
 * @param [in] iConfId The ID of conference.
 *
 * @retval String of video statistics.
 */
ZFUNC ZCONST ZCHAR * Mtc_ConfGetAudioStat(ZUINT iConfId);

/**
 * @brief MTC get conference get max image number.
 *
 * @param [in] iConfId The ID of conference.
 *
 * @retval max image number of video conference.
 */
ZFUNC ZUINT Mtc_ConfGetMaxImageNum(ZUINT iConfId);

/**
 * @brief MTC get conference get video switch mode.
 *
 * @param [in] iConfId The ID of conference.
 *
 * @retval video switch mode of video conference, @ref EN_MTC_CONF_VIDEO_SWITCH_MODE. 
 */
ZFUNC ZUINT Mtc_ConfGetVideoSwithMode(ZUINT iConfId);

/**
 * @brief MTC get conference get multi-picture mode.
 *
 * @param [in] iConfId The ID of conference.
 *
 * @retval video multi-picture mode of video conference, @ref EN_MTC_CONF_MULTI_PIC_MODE.
 */
ZFUNC ZUINT Mtc_ConfGetMultiPicMode(ZUINT iConfId);

/**
 * @brief MTC conference enable/disable dynamic reset encoder to change video image aspect.
 *            The function should be called before @ref Mtc_ConfCameraAttach.
 *
 * @param [in] iConfId The ID of conference.
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
ZFUNC ZINT Mtc_ConfEnableAdaptiveAspect(ZUINT iConfId, ZBOOL bEnable,
                ZFLOAT fFixedAspect);

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
 * @see @ref Mtc_ConfRecMicStop
 */
ZFUNC ZINT Mtc_ConfRecMicStart(ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType);

/**
 * @brief Reccord Audio stop.
 *
 * @see @ref Mtc_ConfRecMicStart
 */
ZFUNC ZINT Mtc_ConfRecMicStop(ZFUNC_VOID);

/** 
 * @brief MTC session record playout.
 *
 * @param [in] iConfId The ID of conference which you want to record, 
 *                      if iConfId is invalid, record the mix playout.
 * @param [in] pcFileName The reccord file name.
 * @param [in] ucFileType The reccord file type, @ref EN_MTC_MFILE_TYPE
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_ConfRecPlayoutStart(ZUINT iConfId, ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType);

/** 
 * @brief MTC session stop record playout.
 *
 * @param [in] iConfId The ID of conference which you want to stop record, 
 *                      if iConfId is invalid, stop record the mix playout.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_ConfRecPlayoutStop(ZUINT iConfId);

/** 
 * @brief MTC conference start send sound from file.
 *
 * @param [in] iConfId The ID of conference which you want to start send sound from file.
 * @param [in] pcFileName The reccord file name.
 * @param [in] ucFileType The reccord file type, @ref EN_MTC_MFILE_TYPE
 * @param [in] bLoop ZFALSE if play once.
 * @param [in] bMix If false, microphone sound is replaced by file sound;
 *                  if true, microphone sound is mixed with file sound
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_ConfSndStartSend(ZUINT iConfId, ZCONST ZCHAR *pcFileName, 
                ZUCHAR ucFileType, ZBOOL bLoop, ZBOOL bMix);

/** 
 * @brief MTC conference stop send sound.
 *
 * @param [in] iConfId The ID of conference which you want to stop send sound from file.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_ConfSndStopSend(ZUINT iConfId);

/**
 * @brief MTC conference play file as camera.
 *
 * @param [in] pcFileName Video file name.
 * @param [in] iAudioStrmId Audio stream id, @see Mtc_ConfGetStrmId.
 * @param [in] iCycle 0 to play once, otherwise to loop play .
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_ConfFilePlayStop
 */
ZFUNC ZINT Mtc_ConfFilePlayAsCamera(ZCONST ZCHAR *pcFileName, 
                ZUINT iAudioStrmId, ZUINT iCycle);

/**
 * @brief MTC conference stop play file.
 *
 * @param [in] pcFileName Video file name.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_ConfFilePlayAsCamera
 */
ZFUNC ZINT Mtc_ConfFilePlayStop(ZCONST ZCHAR *pcFileName);

/**
 * @brief Get stream ID of the conference.
 *
 * @param [in] iConfId The ID of conference.
 * @param [in] ucStrmType The stream type of conference, @ref EN_MTC_CONF_MEDIA_TYPE.
 *
 * @return The stream id of the conference on succeed, otherwise return ZMAXUINT.
 *
 */
ZFUNC ZUINT Mtc_ConfGetStrmId(ZUINT iConfId, ZUCHAR ucStrmType);

/**
 * @brief MTC conference get media server ip address string.
 * 
 * @param [in] iConfId The ID of conference.
 *
 * @return Media server ip address string, like "192.168.0.1".
 *
 */
ZFUNC ZCHAR * Mtc_ConfGetMediaServerIpAddr(ZUINT iConfId);

/**
 * @brief MTC conference get conference type.
 * 
 * @param [in] iConfId The ID of conference.
 *
 * @return Conference type @ref EN_MTC_CONF_TYPE.
 *
 */
ZFUNC ZUCHAR Mtc_ConfGetConfType(ZUINT iConfId);

/** 
 * @brief MTC conference set server conference id. 
 *              UI should set server conference id 
 *              which in common-template MESSAGE.
 *
 * @param [in] iConfId The ID of conference.
 * @param [in] pcServConfId conference id in common-template message.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfSetSeverConfId(ZUINT iConfId, ZCHAR *pcServConfId);

/**
 * @brief MTC conference get available conference id.
 *              UI should use the ID to get conference state.
 *
 * @return The ID of exist conference.
 *
 *@ref Mtc_ConfGetState, Mtc_ConfCreateX
 */
ZFUNC ZUINT Mtc_ConfGetAvailableConfId(ZFUNC_VOID);

/** 
 * @brief MTC conference create account.
 *
 * @param [in] pcAppId The APP ID of the application.
 * @param [in] pcPwd The password of the application.
 * @param [in] pcToken The token from CMCC unified authentication.
 * @param [in] pcPkgId The package id.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfCreateAccount(ZCHAR *pcAppId, ZCHAR *pcPwd,
                ZCHAR *pcToken, ZCHAR *pcPkgId);

/** 
 * @brief MTC conference delete account.
 *
 * @param [in] pcAppId The APP ID of the application.
 * @param [in] pcPwd The password of the application.
 * @param [in] pcToken The token from CMCC unified authentication.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfDelAccount(ZCHAR *pcAppId, ZCHAR *pcPwd, ZCHAR *pcToken);

/** 
 * @brief MTC conference charge account.
 *
 * @param [in] pcAppId The APP ID of the application.
 * @param [in] pcPwd The password of the application.
 * @param [in] pcToken The token from CMCC unified authentication.
 
 * @param [in] iBalance The charge balance in minutes. User can only make domestic calls.
 * @param [in] ucType The charging type, @ref EN_MTC_CONF_CHARGE_TYPE.
 * @param [in] ucAccessType The access type, @ref EN_MTC_CONF_ACCESS_TYPE.
 * @param [in] ucSrvType Service type, @ref EN_MTC_CONF_SERVICE_TYPE.
 * @param [in] pcExireDate The charge balance expire date, like YYYYMMDD.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfChargeAccount(ZCHAR *pcAppId, ZCHAR *pcPwd, ZCHAR *pcToken, 
                ZUINT iBalance, ZUCHAR ucType, ZUCHAR ucAccessType,
                ZUCHAR ucSrvType, ZCHAR *pcExireDate);

/** 
 * @brief MTC conference query account.
 *
 * @param [in] pcAppId The APP ID of the application.
 * @param [in] pcPwd The password of the application.
 * @param [in] pcToken The token from CMCC unified authentication.
 * @param [in] iAccType The account type @ref EN_MTC_CONF_ACCOUNT_TYPE(default 
 *                                  @ref EN_MTC_CONF_ACCOUNT_MAIN).
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfQueryAccount(ZCHAR *pcAppId, ZCHAR *pcPwd,
                ZCHAR *pcToken, ZUINT iAccType);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CONF_H__ */

