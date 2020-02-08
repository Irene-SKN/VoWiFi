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
  File name     : mtc_im_sess.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC IM session

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_SESS_H__
#define _MTC_IM_SESS_H__

/**
 * @file mtc_im_sess.h
 * @brief MTC Instant Messaging Session Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief{ */
/* MTC im session function indicate */
#define MTC_IM_SESS_AT_ALL_MEMBER     (ZMAXUINT-1) /**< @brief  Indicate at all member in the group chat */
/** @} */

/** @brief MTC IM session imdn request type */
#define MTC_IM_SESS_IMDN_NO            0x00000000 /**< @brief no notification request, regular message */
#define MTC_IM_SESS_IMDN_UNKNOWN       0x00000001 /**< @brief unknown type */
#define MTC_IM_SESS_IMDN_DELI_SUCC     0x00000002 /**< @brief delivery succeed notification request */
#define MTC_IM_SESS_IMDN_DELI_FAIL     0x00000004 /**< @brief delivery succeed fail request */
#define MTC_IM_SESS_IMDN_DELI_FWD      0x00000008 /**< @brief delivery succeed forward request */
#define MTC_IM_SESS_IMDN_DISP          0x00000010 /**< @brief display notification request */


/** @brief MTC IM session At type */
typedef enum EN_MTC_IM_SESS_AT_TYPE
{
    EN_MTC_IM_SESS_AT_PARTIAL,       /**< @brief user @ some members  in the group */
    EN_MTC_IM_SESS_AT_ALL,               /**< @brief user @ all members in the group */
    EN_MTC_IM_SESS_AT_NONE,         /**< @brief user @ no body in the group */
} EN_MTC_IM_SESS_AT_TYPE;


/** @brief MTC IM session type */
typedef enum EN_MTC_IM_SESS_TYPE
{
    EN_MTC_IM_SESS_ONLINE_CREATE,       /**< @brief online create invitation */
    EN_MTC_IM_SESS_ONLINE_MSG,          /**< @brief online message invitation */
    EN_MTC_IM_SESS_OFFLINE_CREATE,      /**< @brief offline create invitation */
    EN_MTC_IM_SESS_OFFLINE_MSG,         /**< @brief offline message invitation */
} EN_MTC_IM_SESS_TYPE;

/** @brief MTC IM session state */
typedef enum EN_MTC_IM_SESS_STAT_TYPE
{
    EN_MTC_IM_SESS_STAT_UNKNOWN,       /**< @brief unknown state*/
    EN_MTC_IM_SESS_STAT_IDLE,          /**< @brief idle state*/
    EN_MTC_IM_SESS_STAT_PENDING,       /**< @brief pending state */
    EN_MTC_IM_SESS_STAT_ACTIVE,        /**< @brief active state */
    EN_MTC_IM_SESS_STAT_INACTIVE       /**< @brief inactive state */
} EN_MTC_IM_SESS_STAT_TYPE;

/** @brief MTC IM session content type */
typedef enum EN_MTC_IM_SESS_CONT_TYPE
{
    EN_MTC_IM_SESS_CONT_UNKNOWN,     /**< @brief unknown content */
    EN_MTC_IM_SESS_CONT_TXT_PLAIN,   /**< @brief text/plain content */
    EN_MTC_IM_SESS_CONT_LOCATION,    /**< @brief application/vnd.gsma.rcspushlocation+xml content */
    EN_MTC_IM_SESS_CONT_MSG_TXT_PLAIN,/**< @brief content type of "text/plain" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_IMAGE_JPEG,/**< @brief content type of "image/jpeg" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_IMAGE_BMP, /**< @brief content type of "image/bmp" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_IMDN,    /**< @brief content type of "message/imdn+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_FTHTTP,  /**< @brief content type of "application/vnd.gsma.rcs-ft-http+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_LOCATION,  /**< @brief content type of "application/vnd.gsma.rcspushlocation+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_VEMOTICON, /**< @brief content type of "application/vemoticon+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_CLOUD_FILE,   /**< @brief content type of "application/cloudfile+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_CMRED_BAG,   /**< @brief content type of "application/cmredbag+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_CARD,   /**< @brief content type of "application/card+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_COM_TEMP,     /**< @brief content type of "application/commontemplate+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_CHRED_BAG,   /**< @brief content type of "application/chredbag+xml" wrapt by cpim */
    EN_MTC_IM_SESS_CONT_MSG_REVOKE,       /**< @brief content type of "application/vnd.gsma.rcsrevoke+xml" wrapt by cpim */
} EN_MTC_IM_SESS_CONT_TYPE;

/** @brief MTC IM session reject reason type */
typedef enum EN_MTC_IM_SESS_REJECT_REASON_TYPE
{
    EN_MTC_IM_SESS_REJECT_REASON_BUSY, /**< @brief busy response */
    EN_MTC_IM_SESS_REJECT_REASON_DECLINE, /**< @brief decline the session */
} EN_MTC_IM_SESS_REJECT_REASON_TYPE;

/**
 * @brief Establishing message session with one participant.
 *
 * If IM establishing successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessAcpted or @ref Mtc_ImCbSetSessRejected.
 *
 * While receiving message session invitation, GUI will be notified by callback 
 * which was set by @ref Mtc_ImCbSetSessRecvIvt.
 *
 * While session participant has updated, GUI will be notified by callback 
 * which was set by @ref Mtc_ImCbSetSessPartpUpted.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 *
 * @return The message session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessEstab(ZCOOKIE zCookie, ZCHAR *pcSubject,
                ZCHAR *pcUri);

/**
 * @brief Establishing message session with one participant with the frist message in invite.
 *
 * If IM establishing successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessAcpted or @ref Mtc_ImCbSetSessRejected.
 *
 * While receiving message session invitation, GUI will be notified by callback 
 * which was set by @ref Mtc_ImCbSetSessRecvIvtM.
 *
 * While session participant has updated, GUI will be notified by callback 
 * which was set by @ref Mtc_ImCbSetSessPartpUpted.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcMsg The user frist message.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] pcUri The participant URI.
 * @param [in,out] piMsgId The session message id.
 *
 * @return The message session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessEstabM(ZCOOKIE zCookie, ZCHAR *pcSubject,
               ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcUri, ZUINT *piMsgId);

/**
 * @brief Establishing message session with one participant with the frist muti-media message in invite.
 *
 * If IM establishing successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessAcpted or @ref Mtc_ImCbSetSessRejected.
 *
 * While receiving message session invitation, GUI will be notified by callback 
 * which was set by @ref Mtc_ImCbSetSessRecvIvtM.
 *
 * While session participant has updated, GUI will be notified by callback 
 * which was set by @ref Mtc_ImCbSetSessPartpUpted.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pData The user frist message.
 * @param [in] iDataSize The message lenth.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] pcUri The participant URI.
 * @param [in,out] piMsgId The session message id.
 *
 * @return The message session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessEstabMM(ZCOOKIE zCookie, ZCHAR *pcSubject,
               ZVOID *pData, ZUINT iDataSize, ZUINT iMsgType, 
               ZCHAR *pcUri, ZUINT *piMsgId);

/**
 * @brief Establishing message session(ad-hoc) with URI-List.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcDispName The own display name in the ad-hoc.
 * @param [in] iPartpLstId The participant list id.
 *
 * @return The (ad-hoc) session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessEstabU(ZCOOKIE zCookie, ZCHAR *pcSubject,
                ZCHAR *pcDispName, ZUINT iPartpLstId);

/**
 * @brief Establishing message session with pre-defined group.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcGrpUri The pre-defined group uri.
 *
 * @return The pre-defined group session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessEstabP(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcGrpUri);

/**
 * @brief Extending session from one-to-one to one-to-many.
 *
 * If IM establishing successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessAcpted or @ref Mtc_ImCbSetSessRejected.
 *
 * While receiving message session invitation, GUI will be notified by callback 
 * which was set by @ref Mtc_ImCbSetSessRecvIvt, and replace session id by
 * Mtc_ImSessGetRplSessId is not 0.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iOne2OneSessId The session id.
 * @param [in] iPartpLstId The participant list id.
 *
 * @return The ad-hoc session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessExtend(ZCOOKIE zCookie, ZUINT iOne2OneSessId, 
                ZUINT iPartpLstId);

/**
 * @brief Rejoin a group message session.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcDispName The own display name in group chat.
 * @param [in] pcGroupChatId The group chat id(Contribution-ID or Conversation-ID).
 * @param [in] pcSessIdentity The focus Session Identity.
 * @param [in] iVersionId The group chat version.
 *
 * @return The rejoin group session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessReJoinG(ZCOOKIE zCookie, ZCHAR *pcSubject,
                ZCHAR *pcDispName, ZCHAR *pcGroupChatId, ZCHAR *pcSessIdentity, 
                ZUINT iVersionId);

/**
 * @brief Rejoin a enterprise group message session.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcDispName The own display name in group chat.
 * @param [in] pcGroupChatId The group chat id(Contribution-ID or Conversation-ID).
 * @param [in] pcSessIdentity The focus Session Identity.
 * @param [in] iVersionId The group chat version.
 *
 * @return The rejoin group session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessReJoinGEP(ZCOOKIE zCookie, ZCHAR *pcSubject,
                ZCHAR *pcDispName, ZCHAR *pcGroupChatId, ZCHAR *pcSessIdentity, 
                ZUINT iVersionId);

/**
 * @brief Rejoin a party group message session.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcDispName The own display name in group chat.
 * @param [in] pcGroupChatId The group chat id(Contribution-ID or Conversation-ID).
 * @param [in] pcSessIdentity The focus Session Identity.
 * @param [in] iVersionId The group chat version.
 *
 * @return The rejoin group session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessReJoinGP(ZCOOKIE zCookie, ZCHAR *pcSubject,
                ZCHAR *pcDispName, ZCHAR *pcGroupChatId, ZCHAR *pcSessIdentity, 
                ZUINT iVersionId);

/**
 * @brief restart a group message session.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcGroupChatId The group chat id(Contribution-ID or Conversation-ID).
 * @param [in] iPartpLstId The participant list id.
 *
 * @return The rejoin group session id when send message session invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessReStartG(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcGroupChatId, ZUINT iPartpLstId);

/**
 * @brief Adding one user to an IM conference session.
 *
 * If IM add successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessPartpAddOk.
 *
 * If IM add failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessPartpAddFailed.
 *
 * @param [in] iSessId The session id.
 * @param [in] pcUri The participant URI.
 *
 * @retval ZOK Adding one participant successfully.
 * @retval ZFAILED Adding one participant failed.
 */
ZFUNC ZINT Mtc_ImSessAddPartp(ZUINT iSessId, ZCHAR *pcUri);

/**
 * @brief Adding multi-users to an IM conference session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iPartpLstId The participant list id.
 *
 * @retval ZOK Adding multi-users successfully.
 * @retval ZFAILED Adding multi-users failed.
 */
ZFUNC ZINT Mtc_ImSessAddPartpU(ZUINT iSessId, ZUINT iPartpLstId);

/**
 * @brief Expelling one user from an IM conference session.
 *
 * If IM expel successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessPartpEplOk.
 *
 * If IM expel failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessPartpEplFailed.
 *
 * @param [in] iSessId The session id.
 * @param [in] pcUri The participant URI.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessAcpted or @ref Mtc_ImCbSetSessRejected.
 *
 * @retval ZOK Expelling one user successfully.
 * @retval ZFAILED Expelling one user failed.
 */
ZFUNC ZINT Mtc_ImSessEplPartp(ZUINT iSessId, ZCHAR *pcUri);

/**
 * @brief Expelling muti-user from an IM conference session.
 *
 * If IM expel successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessPartpEplOk.
 *
 * If IM expel failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessPartpEplFailed.
 *
 * @param [in] iSessId The session id.
 * @param [in] iPartpLstId The participant list id.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessAcpted or @ref Mtc_ImCbSetSessRejected.
 *
 * @retval ZOK Expelling one user successfully.
 * @retval ZFAILED Expelling one user failed.
 */
ZFUNC ZINT Mtc_ImSessEplPartpU(ZUINT iSessId, ZUINT iPartpLstId);

/**
 * @brief Accept a message session invitation.
 *
 * @param [in] iSessId The session id.
 * @param [in] pcDispName The own display name in the group chat.
 *
 * @retval ZOK Accept message session successfully.
 * @retval ZFAILED Accept message session failed.
 */
ZFUNC ZINT Mtc_ImSessAccept(ZUINT iSessId, ZCHAR *pcDispName);

/**
 * @brief Reject a message session invitation.
 *
 * @param [in] iSessId The session id.
 * @param [in] iReason Indicate the reject reason which may trigger some
 *                   service in S-CSCF, see @ref EN_MTC_IM_SESS_REJECT_REASON_TYPE.
 *
 * @retval ZOK Reject message session successfully.
 * @retval ZFAILED Reject message session failed.
 */
ZFUNC ZINT Mtc_ImSessReject(ZUINT iSessId, ZUINT iReason);

/**
 * @brief Cancel a message session.
 *
 * If IM cancel successfully, Remote GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessCanceled.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Canceling message session successfully.
 * @retval ZFAILED Canceling message session failed.
 */
ZFUNC ZINT Mtc_ImSessCancel(ZUINT iSessId);

/**
 * @brief Leaving a message session.
 *
 * If IM cancel successfully, Remote GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessReleased.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Leaving message session successfully.
 * @retval ZFAILED Leaving message session failed.
 */
ZFUNC ZINT Mtc_ImSessLeave(ZUINT iSessId);

/**
 * @brief Dissolve a group chat message session.
 *
 * If IM dissolve successfully, Remote GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessReleased.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Dissolve group chat message session successfully.
 * @retval ZFAILED Dissolve group chat message session failed.
 */
ZFUNC ZINT Mtc_ImSessDissolve(ZUINT iSessId);

/**
 * @brief Modify a message session subject.
 *
 * @param [in] iSessId The session id.
 * @param [in] pcSubject The session subject.
 *
 * @retval ZOK Modify subject successfully.
 * @retval ZFAILED Modify subject failed.
 */
ZFUNC ZINT Mtc_ImSessMdfySubject(ZUINT iSessId, ZCHAR *pcSubject);

/**
 * @brief Modify a group chat message session chairman.
 *
 * @param [in] iSessId The session id.
 * @param [in] pcUri The Uri of new chairman, if the value is null, 
 *                     server will randomly assign a chairman.
 *
 * @retval ZOK Modify chairman successfully.
 * @retval ZFAILED Modify chairman failed.
 */
ZFUNC ZINT Mtc_ImSessMdfyChairMan(ZUINT iSessId, ZCHAR *pcUri);

/**
 * @brief Accept modify a group chat message session chairman.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Accept successfully.
 * @retval ZFAILED Accept failed.
 */
ZFUNC ZINT Mtc_ImSessAcptMdfyChairMan(ZUINT iSessId);

/**
 * @brief Reject modify a group chat message session chairman.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Reject successfully.
 * @retval ZFAILED Reject failed.
 */
ZFUNC ZINT Mtc_ImSessRjctMdfyChairMan(ZUINT iSessId);

/**
 * @brief Modify own display name in a group chat message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] pcDispName The own new display name in group chat.
 *
 * @retval ZOK Modify display name successfully.
 * @retval ZFAILED Modify display name failed.
 */
ZFUNC ZINT Mtc_ImSessMdfyDispName(ZUINT iSessId, ZCHAR *pcDispName);

/**
 * @brief Get user cookie from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImSessGetCookie(ZUINT iSessId);

/**
 * @brief Set user cookie in a message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie of message session.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImSessSetCookie(ZUINT iSessId, ZCOOKIE zCookie);

/**
 * @brief Get session state from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return Session state, @see @ref EN_MTC_IM_SESS_STAT_TYPE.
 */
ZFUNC ZUINT Mtc_ImSessGetState(ZUINT iSessId);

/**
 * @brief Get user subject from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return User subject.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetSubject(ZUINT iSessId);

/**
 * @brief Get user display name from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return User display name.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetDispName(ZUINT iSessId);

/**
 * @brief MTC Get participant type from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return Type of IM message session participant, see @ref EN_MTC_PARTP_LST_TYPE.
 *
 * If type is @ref EN_MTC_PARTP_LST_ONE, participant can be got by @ref Mtc_ImSessGetPartp.
 * If type is @ref EN_MTC_PARTP_LST_PREDEF_GRP, participant can be got by @ref Mtc_ImSessGetPartp.
 * If type is @ref EN_MTC_PARTP_LST_URI_LST, participant can be got by @ref Mtc_ImSessGetPartpLstId.
 */
ZFUNC ZUINT Mtc_ImSessGetPartpType(ZUINT iSessId);

/**
 * @brief MTC Get participant information from message session.
 *
 * The participant is the remote client who is joining session.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImSessGetPartp(ZUINT iSessId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief Get participant list id from message session.
 *
 * The participant list id is all remote clients who are joining session.
 *
 * @param [in] iSessId The session id.
 *
 * @return The participant list id on succeed or 0 on failed.
 *
 *  The caller is responsible for freeing it by @ref Mtc_PartpLstDelete.
 */
ZFUNC ZUINT Mtc_ImSessGetPartpLstId(ZUINT iSessId);

/**
 * @brief Get original participant URI from message session.
 *
 * The participant is the session initiator who initialized this message session.
 * It will return local URI if local client is the session initiator.
 * It will return From uri from session invitation information.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImSessGetOrigPartp(ZUINT iSessId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief Get original identity of participant URI from message session.
 *
 * The participant is the session initiator who initialized this message session.
 * It will return local URI if local client is the session initiator.
 * It will return identity uri if session invitation has P-Asserted-Identity information.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImSessGetOrigIdPartp(ZUINT iSessId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief Get group URI from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return Group URI when get group successfully, otherwise return empty string.
 *
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetGrpUri(ZUINT iSessId);

/**
 * @brief Get group Identity from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return Group Identity when get group successfully, otherwise return empty string.
 *
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetGrpIdent(ZUINT iSessId);

/**
 * @brief MTC Get conversation-id from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return The conversation-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetConvId(ZUINT iSessId);

/**
 * @brief MTC Get contribution-id from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return The contribution-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetContId(ZUINT iSessId);

/**
 * @brief MTC Get group chat id from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return The group chat id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetGrpChatId(ZUINT iSessId);

/**
 * @brief Get replaced session(one to one session) id from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return The replaced session id.
 */
ZFUNC ZUINT Mtc_ImSessGetRplSessId(ZUINT iSessId);

/**
 * @brief MTC Get date time from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time failed.
 */
ZFUNC ZINT Mtc_ImSessGetSysDateTime(ZUINT iSessId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return message session date time(milliseconds), otherwise return 0.
 */
ZFUNC ZMTIME_T Mtc_ImSessGetDateTime(ZUINT iSessId);

/**
 * @brief Get outgoing.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZTRUE outgoing.
 * @retval ZFALSE incoming.
 */
ZFUNC ZBOOL Mtc_ImSessGetOutgoing(ZUINT iSessId);

/**
 * @brief Start composing function.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Start composing successfully.
 * @retval ZFAILED Start composing failed.
 */
ZFUNC ZINT Mtc_ImSessStartCompsing(ZUINT iSessId);

/**
 * @brief Stop composing function.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Stop composing successfully.
 * @retval ZFAILED Stop composing failed.
 */
ZFUNC ZINT Mtc_ImSessStopCompsing(ZUINT iSessId);

/**
 * @brief MTC get if message session support imdn.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZTRUE support imdn.
 * @retval ZFALSE do not support imdn.
 */
ZFUNC ZBOOL Mtc_ImSessGetImdnSupport(ZUINT iSessId);

/**
 * @brief MTC get if message session support FTHTTP.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZTRUE support FTHTTP.
 * @retval ZFALSE do not support FTHTTP.
 */
ZFUNC ZBOOL Mtc_ImSessGetFtHttpSupport(ZUINT iSessId);

/**
 * @brief MTC get establishing message session with first message.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZTRUE establishing session with first message.
 * @retval ZFALSE establishing session with none.
 */
ZFUNC ZBOOL Mtc_ImSessHasFirstMsg(ZUINT iSessId);

/**
 * @brief MTC get message session session isfous.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZTRUE message session is group chat or pre-defined group.
 * @retval ZFALSE message session is 1-1 chat.
 */
ZFUNC ZBOOL Mtc_ImSessGetIsFocus(ZUINT iSessId);

/**
 * @brief MTC get message session local is chairman.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZTRUE Indicates local is chairman.
 * @retval ZFALSE Indicates local is not chairman.
 */
ZFUNC ZBOOL Mtc_ImSessGetIsChairman(ZUINT iSessId);

/**
 * @brief MTC Get message session get max user count.
 *
 * @param [in] iSessId The session id.
 *
 * @return session max user count.
 */
ZFUNC ZUINT Mtc_ImSessGetMaxUsrCnt(ZUINT iSessId);

/**
 * @brief MTC Get message session get group type.
 *
 * @param [in] iSessId The session id.
 *
 * @return session group type, see @ref EN_MTC_GROUP_TYPE.
 */
ZFUNC ZUINT Mtc_ImSessGetGroupType(ZUINT iSessId);

/**
 * @brief MTC Get message session get user count.
 *
 * @param [in] iSessId The session id.
 *
 * @return session user count.
 */
ZFUNC ZUINT Mtc_ImSessGetUsrCnt(ZUINT iSessId);

/**
 * @brief MTC message session get active flag.
 *
 * @param [in] iSessId The session id.
 *
 * @return session active flag.
 */
ZFUNC ZBOOL Mtc_ImSessGetActive(ZUINT iSessId);

/**
 * @brief MTC message session get locked flag.
 *
 * @param [in] iSessId The session id.
 *
 * @return session locked flag.
 */
ZFUNC ZBOOL Mtc_ImSessGetLocked(ZUINT iSessId);

/**
 * @brief MTC message session get offline flag.
 *
 * @param [in] iSessId The session id.
 *
 * @return session offline flag.
 */
ZFUNC ZBOOL Mtc_ImSessGetOffline(ZUINT iSessId);

/**
 * @brief MTC message session get offline invitation flag.
 *
 * @param [in] iSessId The session id.
 *
 * @return session offline invitation flag.
 */
ZFUNC ZBOOL Mtc_ImSessGetOfflineIvt(ZUINT iSessId);

/**
 * @brief MTC message session get offline message flag.
 *
 * @param [in] iSessId The session id.
 *
 * @return session offline message flag.
 */
ZFUNC ZBOOL Mtc_ImSessGetOfflineMsg(ZUINT iSessId);

/**
 * @brief MTC message session get session type.
 *
 * @param [in] iSessId The session id.
 *
 * @return session type, @see @ref EN_MTC_IM_SESS_TYPE.
 */
ZFUNC ZUINT Mtc_ImSessGetSessType(ZUINT iSessId);

/**
 * @brief MTC message session get group chat version.
 *
 * @param [in] iSessId The session id.
 *
 * @return group chat version.
 */
ZFUNC ZUINT Mtc_ImSessGetVersionId(ZUINT iSessId);

/**
 * @brief MTC message session set group chat version.
 *
 * @param [in] iSessId The session id.
 * @param [in] iVer The group chat version.
 *
 * @retval ZOK Set version successfully.
 * @retval ZFAILED Set version failed.
 */
ZFUNC ZINT Mtc_ImSessSetVersionId(ZUINT iSessId, ZUINT iVer);

/**
 * @brief MTC Sending a message through message session.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgSend(ZUINT iSessId, ZCOOKIE zCookie,
                ZCHAR *pcMsg, ZUINT iMsgType);

/**
 * @brief MTC Sending a message through message session.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] iAtPartpLstId The participant list id which be mentioned.
 * @param [in] iAtType The at function type, see @ref EN_MTC_IM_SESS_AT_TYPE.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgSendAt(ZUINT iSessId, ZCOOKIE zCookie,
                ZCHAR *pcMsg, ZUINT iMsgType, ZUINT iAtPartpLstId, ZUINT iAtType);

/**
 * @brief MTC Sending a message to one participant through message session.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcPeerUri The peer uri.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgSendO(ZUINT iSessId, ZCOOKIE zCookie,
                ZCHAR *pcPeerUri, ZCHAR *pcMsg, ZUINT iMsgType);

/**
 * @brief MTC Sending a multi-media message through message session.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pData The multi-media message body.
 * @param [in] iDataSize The multi-media message size.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgSendM(ZUINT iSessId, ZCOOKIE zCookie,
                ZVOID *pData, ZUINT iDataSize, ZUINT iMsgType);

/**
 * @brief MTC Sending a message through with font information message session.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] pcFontInfo The font information.
 * @param [in] iAtPartpLstId The participant list id which be mentioned.
 * @param [in] iAtType The at function type, see @ref EN_MTC_IM_SESS_AT_TYPE.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgSendF(ZUINT iSessId, ZCOOKIE zCookie,
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcFontInfo, ZUINT iAtPartpLstId, 
                ZUINT iAtType);

/**
 * @brief mtcf MTC Send geolocation free text through session.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] bCpim The CPIM message format flag.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImSessMsgSendGeoText(ZUINT iSessId, ZCOOKIE zCookie, 
                ZCHAR *pcFreeText, ZCHAR *pcLabel, ZBOOL bCpim);

/**
 * @brief mtcf MTC Send geolocation coordinate through session.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] bCpim The CPIM message format flag.
 *
 * Note: if radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImSessMsgSendGeoCoord(ZUINT iSessId, ZCOOKIE zCookie, 
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcLabel, ZBOOL bCpim);

/**
 * @brief mtcf MTC Send geolocation both free text and coordinate through session.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] bCpim The CPIM message format flag.
 *
 * Note: if radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImSessMsgSendGeoBoth(ZUINT iSessId, ZCOOKIE zCookie, 
                ZCHAR *pcFreeText, ZDOUBLE dLatitude, ZDOUBLE dLongitude, 
                ZFLOAT fRadius, ZCHAR *pcLabel, ZBOOL bCpim);

/**
 * @brief MTC ReSending a message through message session
 * Only used to CMCC.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgReSend(ZUINT iSessId, ZCOOKIE zCookie,
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief MTC ReSending a message through message session
 * Only used to CMCC.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] iAtPartpLstId The participant list id which be mentioned.
 * @param [in] pcReImdnId The resend imdn message id.
 * @param [in] iAtType The at function type, see @ref EN_MTC_IM_SESS_AT_TYPE.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgReSendAt(ZUINT iSessId, ZCOOKIE zCookie,
                ZCHAR *pcMsg, ZUINT iMsgType, ZUINT iAtPartpLstId,  ZUINT iAtType,
                ZCHAR *pcReImdnId);

/**
 * @brief MTC ReSending a message with font information through message session
 * Only used to CMCC.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] pcFontInfo The font information.
 * @param [in] iAtPartpLstId The participant list id which be mentioned.
 * @param [in] pcReImdnId The resend imdn message id.
 * @param [in] iAtType The at function type, see @ref EN_MTC_IM_SESS_AT_TYPE.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgReSendF(ZUINT iSessId, ZCOOKIE zCookie,
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcFontInfo, ZUINT iAtPartpLstId,  
                ZUINT iAtType, ZCHAR *pcReImdnId);

/**
 * @brief MTC ReSending a message to one participant through message session
 * Only used to CMCC.
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcPeerUri The peer uri.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] iAtPartpLstId The participant list id which be mentioned.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgReSendO(ZUINT iSessId, ZCOOKIE zCookie,
                ZCHAR *pcPeerUri, ZCHAR *pcMsg, ZUINT iMsgType,  
                ZCHAR *pcReImdnId);

/**
 * @brief MTC ReSending a multi-media message through message session
 * Only used to CMCC
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pData The multi-media message body.
 * @param [in] iDataSize The multi-media message size.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImSessMsgReSendM(ZUINT iSessId, ZCOOKIE zCookie,
                ZVOID *pData, ZUINT iDataSize, ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief MTC ReSend geolocation free text through session
 * Only used to CMCC
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] bCpim The CPIM message format flag.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImSessMsgReSendGeoText(ZUINT iSessId, ZCOOKIE zCookie, 
                ZCHAR *pcFreeText, ZCHAR *pcLabel, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief MTC ReSend geolocation coordinate through session
 * Only used to CMCC
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] bCpim The CPIM message format flag.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * Note: if radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImSessMsgReSendGeoCoord(ZUINT iSessId, ZCOOKIE zCookie, 
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcLabel, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief MTC ReSend geolocation both free text and coordinate through session
 * Only used to CMCC
 *
 * If IM sent message successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendOk.
 *
 * If IM sent message failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgSendFailed.
 *
 * While receiving message, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetSessMsgRecvMsg.
 *
 * @param [in] iSessId The session id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] bCpim The CPIM message format flag.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * Note: if radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return The session message id when send a message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImSessMsgReSendGeoBoth(ZUINT iSessId, ZCOOKIE zCookie, 
                ZCHAR *pcFreeText, ZDOUBLE dLatitude, ZDOUBLE dLongitude, 
                ZFLOAT fRadius, ZCHAR *pcLabel, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief MTC Get the Imdn type from message of message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return Type of message, @ref EN_MTC_IM_SESS_REQ_ITYPE.
 */
ZFUNC ZUINT Mtc_ImSessMsgGetImdnType(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get imdn message-id from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The imdn message-id.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessMsgGetImdnMsgId(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get device id from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The device id.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessMsgGetDeviceId(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get message content type from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return Type of IM message, see @ref EN_MTC_IM_SESS_CONT_TYPE.
 */
ZFUNC ZUINT Mtc_ImSessMsgGetContentType(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get message content length from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The message content length.
 */
ZFUNC ZUINT Mtc_ImSessMsgGetContentLen(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get message content from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The message content.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessMsgGetContent(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get multi-media message content from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 * @param [out] ppData The multi-media message content.
 * @param [out] piDataSize The multi-media message content length.
 *
 * @retval ZOK Get message content successfully.
 * @retval ZFAILED Get message content failed.
 *   The caller must copy it, then use.
 */
ZFUNC ZINT Mtc_ImSessMsgGetMContent(ZUINT iSessId, 
                ZUINT iMsgId, ZVOID **ppData, ZUINT *piDataSize);

/**
 * @brief MTC Get participant information from message session.
 *
 * The participant is the remote client who has sent message.
 * It will return ZNULL if message was sent by local client.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImSessMsgGetPartp(ZUINT iSessId, ZUINT iMsgId, 
                ZCHAR **ppcName, ZCHAR **ppcUri);

/**
 * @brief MTC Get message date time from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time failed.
 */
ZFUNC ZINT Mtc_ImSessMsgGetSysDateTime(ZUINT iSessId, ZUINT iMsgId,
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get message date time from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return message date time(milliseconds), otherwise return 0.
 */
ZFUNC ZMTIME_T Mtc_ImSessMsgGetDateTime(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get font information of IM message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The session message id.
 *
 * @return The font information.
 * The caller is responsible for freeing it by Zos_SysStrFree
 */
ZFUNC ZCHAR * Mtc_ImSessMsgGetFontInfo(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief Get user cookie from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImSessMsgGetCookie(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief Set user cookie in a message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 * @param [in] zCookie The user cookie of message session.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImSessMsgSetCookie(ZUINT iSessId, ZUINT iMsgId,
                ZCOOKIE zCookie);

/**
 * @brief Set file transfer via http id in a session message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 * @param [in] iFtHttpId The FtHttp id.
 *
 * @retval ZOK Set FtHttpId successfully.
 * @retval ZFAILED Set FtHttpId failed.
 */
ZFUNC ZINT Mtc_ImSessMsgSetFtHttpId(ZUINT iSessId, ZUINT iMsgId,
                ZUINT iFtHttpId);
/**
 * @brief mtcf MTC Get geolocation information id of IM message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The session message id.
 *
 * @return The geolocation information id.
 */
ZFUNC ZUINT Mtc_ImSessMsgGetGInfoId(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief mtcf MTC Get silence indication flag of IM message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The session message id.
 *
 * @return The silence indication.
 */
ZFUNC ZBOOL Mtc_ImSessMsgHasSilenceInd(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief mtcf MTC Get at indication flag of IM message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The session message id.
 *
 * @return The at indication.
 */
ZFUNC ZBOOL Mtc_ImSessMsgHasAtInd(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief mtcf MTC Get at all indication flag of IM message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The session message id.
 *
 * @return The at all indication.
 */
ZFUNC ZBOOL Mtc_ImSessMsgHasAtAllInd(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief mtcf MTC Get carbon copy indication flag of IM message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The session message id.
 *
 * @return The carbon copy indication.
 */
ZFUNC ZBOOL Mtc_ImSessMsgHasCcInd(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief mtcf MTC Get offline indication flag of IM message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The session message id.
 *
 * @return The offline indication.
 */
ZFUNC ZBOOL Mtc_ImSessMsgHasOffInd(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC get enterprise group indication from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return enterprise group indication.
 */
ZFUNC ZBOOL Mtc_ImSessGetEnterPriseGrpInd(ZUINT iSessId);

/**
 * @brief MTC get party group indication from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return party group indication.
 */
ZFUNC ZBOOL Mtc_ImSessGetPartyGrpInd(ZUINT iSessId);

/**
 * @brief MTC get revoke message indication from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return revoke message indication.
 */
ZFUNC ZBOOL Mtc_ImSessHasRevokeMsgInd(ZUINT iSessId, ZUINT iMsgId);

/**
 * @brief MTC Get revoke message-id from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke message-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetRevokeMsgId(ZUINT iSessId, ZUINT iMsgId);

/**
 * @brief MTC Get revoke result from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id. 
 *
 * @return The revoke result.
 */
ZFUNC ZUCHAR Mtc_ImSessGetRevokeResult(ZUINT iSessId, ZUINT iMsgId);

/**
 * @brief MTC Get revoke from addr from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke from addr.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetRevokeFromAddr(ZUINT iSessId, ZUINT iMsgId);

/**
 * @brief MTC Get revoke to addr from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke to addr.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImSessGetRevokeToAddr(ZUINT iSessId, ZUINT iMsgId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_SESS_H__ */

