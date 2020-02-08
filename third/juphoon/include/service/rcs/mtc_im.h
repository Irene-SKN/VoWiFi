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
  File name     : mtc_im.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC IM page message

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_H__
#define _MTC_IM_H__

/**
 * @file mtc_im.h
 * @brief MTC Instant Message Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC im status code(error no or terminated code). */
#define MTC_IM_ERR_NO               (MTC_EBASE_IM + 0) /**< @brief no error. */
#define MTC_IM_ERR_AUTH_FAILED      (MTC_EBASE_IM + 1) /**< @brief authentication failed, invalid user or password. */
#define MTC_IM_ERR_SESS_TMR         (MTC_EBASE_IM + 2) /**< @brief im session refresh error. */
#define MTC_IM_ERR_FORBIDDEN        (MTC_EBASE_IM + 3) /**< @brief im forbidden. */
#define MTC_IM_ERR_NOT_FOUND        (MTC_EBASE_IM + 4) /**< @brief im participant not found. */
#define MTC_IM_ERR_NOT_ACPTED       (MTC_EBASE_IM + 5) /**< @brief im not accepted. */
#define MTC_IM_ERR_TEMP_UNAVAIL     (MTC_EBASE_IM + 6) /**< @brief im participant temp unavailable. */
#define MTC_IM_ERR_REQ_TERMED       (MTC_EBASE_IM + 7) /**< @brief im request terminated. */
#define MTC_IM_ERR_INTERNAL_ERR     (MTC_EBASE_IM + 8) /**< @brief server internal error. */
#define MTC_IM_ERR_SRV_UNAVAIL      (MTC_EBASE_IM + 9) /**< @brief service unavailable. */
#define MTC_IM_ERR_TIMEOUT          (MTC_EBASE_IM + 10) /**< @brief request timeout. */
#define MTC_IM_ERR_OFFLINE          (MTC_EBASE_IM + 11) /**< @brief callee not registered. */
#define MTC_IM_ERR_NETWORK          (MTC_EBASE_IM + 12) /**< @brief network error. */
#define MTC_IM_ERR_EXPELLED         (MTC_EBASE_IM + 13) /**< @brief expelled error. */
#define MTC_IM_ERR_GONE             (MTC_EBASE_IM + 14) /**< @brief gone. */
#define MTC_IM_ERR_EXCEED_MAX_PARTP (MTC_EBASE_IM + 15) /**< @brief exceed maximum participant size. */
#define MTC_IM_ERR_EXCEED_MAX_LENGTH (MTC_EBASE_IM + 16) /**< @brief exceed maximum length. */
#define MTC_IM_ERR_CREATED_GRP_FULL (MTC_EBASE_IM + 17) /**< @brief created group is full. */
#define MTC_IM_ERR_JOINED_GRP_FULL  (MTC_EBASE_IM + 18) /**< @brief joined group is full. */
#define MTC_IM_ERR_MANAGED_GRP_FULL (MTC_EBASE_IM + 19) /**< @brief managed group is full. */
#define MTC_IM_ERR_DECLINE          (MTC_EBASE_IM + 20) /**< @brief decline. */
#define MTC_IM_ERR_TOO_FEW_PARTP          (MTC_EBASE_IM + 21) /**< @brief too few participant. */
#define MTC_IM_ERR_NO_PARTPLST            (MTC_EBASE_IM + 22) /**< @brief no participant list. */
#define MTC_IM_ERR_GRPNAME_NOT_ALLOW      (MTC_EBASE_IM + 23) /**< @brief Group name not allowed by monitor plat. */
#define MTC_IM_ERR_RESLST_SYNTAX          (MTC_EBASE_IM + 24) /**< @brief Resource-list syntax error. */
#define MTC_IM_ERR_REFERTO_REQUIRED       (MTC_EBASE_IM + 25) /**< @brief Refer-To field required. */
#define MTC_IM_ERR_ORIGINATOR_NOTIN_GROUP (MTC_EBASE_IM + 26) /**< @brief Originator not in group. */
#define MTC_IM_ERR_ALREADY_IN_GROUP       (MTC_EBASE_IM + 27) /**< @brief Destination already in group. */
#define MTC_IM_ERR_SERVER_NOT_AUTHED      (MTC_EBASE_IM + 28) /**< @brief Service not authorised. */
#define MTC_IM_ERR_PARTP_NOTIN_GROUP      (MTC_EBASE_IM + 29) /**< @brief Destination not in group. */
#define MTC_IM_ERR_PARTP_MISS_GPMAN_CAP   (MTC_EBASE_IM + 30) /**< @brief Destination miss gpmanage capability. */
#define MTC_IM_ERR_CHAGE_ADMIN_LOOPED     (MTC_EBASE_IM + 31) /**< @brief Change admin oper looped. */
#define MTC_IM_ERR_GRP_MEMBER_FULL        (MTC_EBASE_IM + 32) /**< @brief Group chat is full. */
#define MTC_IM_ERR_GPMESSAGE_NOT_AUTH     (MTC_EBASE_IM + 33) /**< @brief Group SMS Message have no authority. */
#define MTC_IM_ERR_GPMESSAGE_OUT_QUOTA    (MTC_EBASE_IM + 34) /**< @brief Group SMS Message out of quota */
#define MTC_IM_ERR_GPMESSAGE_VIP_OUT_QUOTA (MTC_EBASE_IM + 35) /**< @brief Group SMS Message vip out of quota */
#define MTC_IM_ERR_GPMESSAGE_SAFETY_OUT_QUOTA (MTC_EBASE_IM + 36) /**< @brief Group SMS Message safety out of quota */
#define MTC_IM_ERR_SURPASS_TRAFFIC        (MTC_EBASE_IM + 37) /**< @brief surpass traffic */
#define MTC_IM_ERR_EMERGENCY_FORBIDDEN    (MTC_EBASE_IM + 38) /**< @brief emergency forbidden */
#define MTC_IM_ERR_FILE_EXPIRED           (MTC_EBASE_IM + 39) /**< @brief file expired */
#define MTC_IM_ERR_DISMISSED              (MTC_EBASE_IM + 40) /**< @brief group dismissed. */
#define MTC_IM_ERR_LEAVED                 (MTC_EBASE_IM + 41) /**< @brief member leaved. */
#define MTC_IM_ERR_BAD_REQ                (MTC_EBASE_IM + 42) /**< @brief bad request. */
#define MTC_IM_ERR_NOT_IMP                (MTC_EBASE_IM + 43) /**< @brief not implement. */
#define MTC_IM_ERR_SEND_MSG_TIMEOUT       (MTC_EBASE_IM + 44) /**< @brief send msg timeout. */
#define MTC_IM_ERR_HTTP_BAD_RSP           (MTC_EBASE_IM + 45) /**< @brief http bad response. */
#define MTC_IM_ERR_HTTP_BAD_REQ           (MTC_EBASE_IM + 46) /**< @brief http bad request. */
#define MTC_IM_ERR_HTTP_AUTH_FAIL         (MTC_EBASE_IM + 47) /**< @brief http auth fail. */
#define MTC_IM_ERR_HTTP_TOO_MANY_PARTP    (MTC_EBASE_IM + 48) /**< @brief http too many participants. */
#define MTC_IM_ERR_HTTP_SERVER_ERR        (MTC_EBASE_IM + 49) /**< @brief http server error. */
#define MTC_IM_ERR_HTTP_GONE              (MTC_EBASE_IM + 50) /**< @brief http group gone. */
#define MTC_IM_ERR_HTTP_NOT_MDFY          (MTC_EBASE_IM + 51) /**< @brief http not modify. */
#define MTC_IM_ERR_HTTP_NOT_FOUND         (MTC_EBASE_IM + 52) /**< @brief http not found. */
#define MTC_IM_ERR_HTTP_DISPNAME_AUTH_FAIL (MTC_EBASE_IM + 53) /**< @brief http display name auth fail. */
#define MTC_IM_ERR_HTTP_SRV_NOT_AUTHED    (MTC_EBASE_IM + 54) /**< @brief http Service not authorised. */
#define MTC_IM_ERR_HTTP_TIMEOUT           (MTC_EBASE_IM + 55) /**< @brief http timeout. */
#define MTC_IM_ERR_HTTP_CMD_TIMEOUT       (MTC_EBASE_IM + 56) /**< @brief http command timeout. */
#define MTC_IM_ERR_OTHER                  (MTC_EBASE_IM + 200) /**< @brief other error. */

/** @brief MTC IM page message imdn type */
#define MTC_PMSG_IMDN_NO            0x00000000 /**< @brief no notification request, regular message */
#define MTC_PMSG_IMDN_UNKNOWN       0x00000001 /**< @brief unknown imdn type */
#define MTC_PMSG_IMDN_DELI_SUCC     0x00000002 /**< @brief message with delivery succeed notification request */
#define MTC_PMSG_IMDN_DELI_FAIL     0x00000004 /**< @brief message with delivery fail notification request */
#define MTC_PMSG_IMDN_DELI_FWD      0x00000008 /**< @brief message with delivery forward notification request */
#define MTC_PMSG_IMDN_DISP          0x00000010 /**< @brief message with display notification request */
#define MTC_PMSG_IMDN_BURN          0x00000020 /**< @brief message with burn after reading notification request */


/** @brief MTC IM page message content type */
typedef enum EN_MTC_PMSG_CTYPE
{
    EN_MTC_PMSG_CONT_UNKNOWN,        /**< @brief unknown content */
    EN_MTC_PMSG_CONT_TXT_PLAIN,      /**< @brief text/plain content */
    EN_MTC_PMSG_CONT_APP_SMS,        /**< @brief application/vnd.3gpp.sms content */
    EN_MTC_PMSG_CONT_VEMOTICON,      /**< @brief "application/vemoticon+xml" content */
    EN_MTC_PMSG_CONT_CLOUD_FILE,     /**< @brief "application/cloudfile+xml" content */
    EN_MTC_PMSG_CONT_XML,            /**< @brief "application/xml" content */
    EN_MTC_PMSG_CONT_OMA_PUSH,       /**< @brief "application/vnd.oma.push" content */
    EN_MTC_PMSG_CONT_MSG_TXT_PLAIN,  /**< @brief content type of "text/plain" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_IMAGE_JPEG, /**< @brief content type of "image/jpeg" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_IMAGE_BMP,  /**< @brief content type of "image/bmp" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_IMDN,       /**< @brief content type of "message/imdn+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_VEMOTICON,  /**< @brief content type of "application/vemoticon+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_CLOUD_FILE, /**< @brief content type of "application/cloudfile+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_XML,        /**< @brief content type of "application/xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_CMRED_BAG,  /**< @brief content type of "application/cmredbag+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_CARD,       /**< @brief content type of "application/card+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_139MAIL_NEW,/**< @brief content type of "application/commonextension+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_ABNTFY_XML, /**< @brief content type of "application/ABNotification+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_GRP_JOIN,       /**< @brief "message/group-join" content */
    EN_MTC_PMSG_CONT_GRP_JOIN_NTFY,  /**< @brief "message/group-join-notify" content */
    EN_MTC_PMSG_CONT_MSG_EXVCARD,    /**< @brief content type of "text/ex-vcard" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_XVCARD,     /**< @brief content type of "text/x-vcard" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_TXT_SMS,    /**< @brief content type of "text/sms" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_COM_TEMP,   /**< @brief content type of "application/commontemplate+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_REVOKE,     /**< @brief content type of "application/vnd.gsma.rcsrevoke+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_CHRED_BAG,  /**< @brief content type of "application/chredbag+xml" wrapt by cpim */
    EN_MTC_PMSG_CONT_MSG_OMA_PUSH,   /**< @brief content type of "application/vnd.oma.push" wrapt by cpim */
} EN_MTC_PMSG_CTYPE;

/** @brief MTC IM page message SMS info type */
typedef enum EN_MTC_PMSG_SMS_TYPE
{
    EN_MTC_PMSG_SMS_BUSY,            /**< @brief busy */
    EN_MTC_PMSG_SMS_NO_ANSWER,       /**< @brief noanswer */
    EN_MTC_PMSG_SMS_NOT_REARCH,      /**< @brief notreachable */
    EN_MTC_PMSG_SMS_NOT_REG          /**< @brief notregistered */
} EN_MTC_PMSG_SMS_TYPE;

/** @brief MTC IM page message group join notify option type */
typedef enum EN_MTC_PMSG_GROUP_JOIN_NTFY_OPTION_TYPE
{
    EN_MTC_PMSG_GROUP_JOIN_NTFY_OPTION_404,     /* sip uri not exists */
    EN_MTC_PMSG_GROUP_JOIN_NTFY_OPTION_YES,     /* allow */
    EN_MTC_PMSG_GROUP_JOIN_NTFY_OPTION_NO,      /* forbidden */
    EN_MTC_PMSG_GROUP_JOIN_NTFY_OPTION_TIMEOUT, /* timeout */

    EN_MTC_PMSG_GROUP_JOIN_NTFY_OPTION_UNKOWN   /* unkown option */
} EN_MTC_PMSG_GROUP_JOIN_NTFY_OPTION_TYPE;

/** @brief MTC IM page message spam type */
typedef enum EN_MTC_PMSG_SPAM_TYPE
{
    EN_MTC_PMSG_SPAM_MIN,
    EN_MTC_PMSG_SPAM_POLITICAL_RUMOR,            /**< @brief political rumor msg */
    EN_MTC_PMSG_SPAM_JURISPRUDENCE,                /**< @brief jurisprudence msg */
    EN_MTC_PMSG_SPAM_FRAUD,                               /**< @brief fraud msg */
    EN_MTC_PMSG_SPAM_MALICIOUS_MARKETING,   /**< @brief malicious marketing msg */
    EN_MTC_PMSG_SPAM_VIOLENCE,                          /**< @brief violence msg */
    EN_MTC_PMSG_SPAM_OTHER = 9,                         /**< @brief other msg */
    EN_MTC_PMSG_SPAM_MAX
} EN_MTC_PMSG_SPAM_TYPE;

/** @brief MTC IM session group type */
typedef enum EN_MTC_GROUP_TYPE
{
    EN_MTC_GROUP_TYPE_ALL,               /**< @brief all groups */
    EN_MTC_GROUP_TYPE_GENERAL,           /**< @brief general group */
    EN_MTC_GROUP_TYPE_ENTERPRISE,        /**< @brief enterprise group */
    EN_MTC_GROUP_TYPE_PARTY,             /**< @brief party group */
    EN_MTC_GROUP_TYPE_END, 
} EN_MTC_GROUP_TYPE;

/**
 * @brief Sending Instant Message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] bOmaIm The message will set a flag with +g.oma.sip-im.
 * @param [in] bCpim The message body format, text plain or CPIM.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSendU
 */
ZFUNC ZUINT Mtc_ImPMsgSend(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZBOOL bOmaIm, ZBOOL bCpim);

/**
 * @brief ReSending Instant Message to one participant only used for cmcc.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] bOmaIm The message will set a flag with +g.oma.sip-im.
 * @param [in] bCpim The message body format, text plain or CPIM.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSendU
 */
ZFUNC ZUINT Mtc_ImPMsgReSend(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZBOOL bOmaIm, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief Sending Burn After Reading Instant Message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * Gui can get the burn after reading flag when receiving IM by @ref Mtc_ImPMsgHasBurnInd.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 *
 * @return The message id when send burn after reading message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendB(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg);

/**
 * @brief ReSending Burn After Reading Instant Message to one participant.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * Gui can get the burn after reading flag when receiving IM by @ref Mtc_ImPMsgHasBurnInd.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send burn after reading message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendB(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg, ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message to participant list.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] bOmaIm The message will set a flag with +g.oma.sip-im.
 * @param [in] bCpim The message body format, text plain or CPIM.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSend
 */
ZFUNC ZUINT Mtc_ImPMsgSendU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsg, ZBOOL bOmaIm, ZBOOL bCpim);

/**
 * @brief ReSending Instant Message to participant list.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] bOmaIm The message will set a flag with +g.oma.sip-im.
 * @param [in] bCpim The message body format, text plain or CPIM.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSend
 */
ZFUNC ZUINT Mtc_ImPMsgReSendU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsg, ZBOOL bOmaIm, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief Sending Public Message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS
 */
ZFUNC ZUINT Mtc_ImPMsgSendP(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZBOOL bCpim);

/**
 * @brief ReSending Public Message to one participant.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS
 */
ZFUNC ZUINT Mtc_ImPMsgReSendP(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief Sending vemoticon message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The vemoticon xml message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendV(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsgXml, ZBOOL bCpim);

/**
 * @brief ReSending vemoticon message to one participant.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The vemoticon xml message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendV(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsgXml, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief Sending vemoticon message to participant list.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list.
 * @param [in] pcMsgXml The vemoticon xml message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendVU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsgXml, ZBOOL bCpim);

/**
 * @brief ReSending vemoticon message to participant list.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list.
 * @param [in] pcMsgXml The vemoticon xml message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendVU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsgXml, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message with cloud file to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The cloud file xml message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
*/
ZFUNC ZUINT Mtc_ImPMsgSendC(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsgXml, ZBOOL bCpim);

/**
 * @brief ReSending Instant Message with cloud file to one participant.
 * IM will be sent by SIP MESSAGE method only used by CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The cloud file xml message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
*/
ZFUNC ZUINT Mtc_ImPMsgReSendC(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsgXml, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message with cloud file to participant list.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsgXml The cloud file xml message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
*/
ZFUNC ZUINT Mtc_ImPMsgSendCU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsgXml, ZBOOL bCpim);

/**
 * @brief ReSending Instant Message with cloud file to participant list.
 * IM will be sent by SIP MESSAGE method only by CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsgXml The cloud file xml message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
*/
ZFUNC ZUINT Mtc_ImPMsgReSendCU(ZCOOKIE zCookie, ZUINT iPartpLstId,
                ZCHAR *pcMsgXml, ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief Sending red bag message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The red bag xml message body.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendR(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsgXml);

/**
 * @brief ReSending red bag message to one participant.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The red bag xml message body.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendR(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsgXml, ZCHAR *pcReImdnId);

/**
 * @brief Sending card message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The card xml message body.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendD(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsgXml);

/**
 * @brief ReSending card message to one participant.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The card xml message body.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendD(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsgXml, ZCHAR *pcReImdnId);

/**
 * @brief Sending card message to to one participant to participant list.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The card xml message body.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendDU(ZCOOKIE zCookie, ZUINT iPartpLstId,
                ZCHAR *pcMsgXml);

/**
 * @brief ReSending card message to participant list.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsgXml The card xml message body.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendDU(ZCOOKIE zCookie, ZUINT iPartpLstId,
                ZCHAR *pcMsgXml, ZCHAR *pcReImdnId);

/**
 * @brief Sending multi-media Message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pData The multi-media message body.
 * @param [in] iDataSize The multi-media message size.
 * @param [in] iMsgType The message type.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS
 */
ZFUNC ZUINT Mtc_ImPMsgSendM(ZCOOKIE zCookie, ZCHAR *pcUri, ZVOID *pData, 
                ZUINT iDataSize, ZUINT iMsgType);

/**
 * @brief ReSending multi-media Message to one participant.
 * IM will be sent by SIP MESSAGE method only used by CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pData The multi-media message body.
 * @param [in] iDataSize The multi-media message size.
 * @param [in] iMsgType The message type.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS
 */
ZFUNC ZUINT Mtc_ImPMsgReSendM(ZCOOKIE zCookie, ZCHAR *pcUri, ZVOID *pData, 
                ZUINT iDataSize, ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief MTC Sending Instant Message to one participant with SMS.
 * IM will send by SIP MESSAGE method. 
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message content type.
 * @param [in] pcFontInfo The font information of message.
 * @param [in] bBurn The burn message flag.
 * @param [out] piMsgId The message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImPMsgSendF(ZCOOKIE zCookie, ZCHAR *pcUri, ZUINT iPartpLstId,
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcFontInfo, ZBOOL bBurn);

/**
 * @brief MTC ReSending Instant Message to one participant.
 * IM will send by SIP MESSAGE method. 
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message content type.
 * @param [in] pcFontInfo The font information of message.
 * @param [in] bBurn The burn message flag.
 * @param [in] pcReImdnId The resend imdn message id.
 * @param [out] piMsgId The message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImPMsgReSendF(ZCOOKIE zCookie, ZCHAR *pcUri, ZUINT iPartpLstId,
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcFontInfo, ZBOOL bBurn, 
                ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message to one participant with SMS.
 * IM will send by SIP MESSAGE method. 
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] bOmaIm The OMA IM flag, add "+g.oma.sip-im" paramter.
 * @param [in] bOmaRcs The OMA RCS flag, add "sms" behind bOmaIm.
 * @param [in] bSmsInd The OMA RCS flag, add "sms;operation=submit" 
                                    in "P-Message-Type-Indicator".
 * @param [in] bCpim The CPIM message format flag.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendX(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZBOOL bOmaIm, ZBOOL bOmaRcs, ZBOOL bSmsInd, ZBOOL bCpim);

/**
 * @brief ReSending Instant Message to one participant with SMS.
 * IM will send by SIP MESSAGE method only used by CMCC. 
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] bOmaIm The OMA IM flag, add "+g.oma.sip-im" paramter.
 * @param [in] bOmaRcs The OMA RCS flag, add "sms" behind bOmaIm.
 * @param [in] bSmsInd The OMA RCS flag, add "sms;operation=submit" 
                                    in "P-Message-Type-Indicator".
 * @param [in] bCpim The CPIM message format flag.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendX(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZBOOL bOmaIm, ZBOOL bOmaRcs, ZBOOL bSmsInd, ZBOOL bCpim, 
                ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message to one participant with RCS SMS.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSend
 */
ZFUNC ZUINT Mtc_ImPMsgSendRS(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg);

/**
 * @brief Sending Instant Message to one participant with spam information.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_PMSG_CTYPE.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendS(ZCOOKIE zCookie, ZCHAR *pcMsg, ZUINT iMsgType,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);

/**
 * @brief ReSending Instant Message to one participant with spam information.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_PMSG_CTYPE.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendS(ZCOOKIE zCookie, ZCHAR *pcMsg, ZUINT iMsgType,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message to one participant with spam information.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_PMSG_CTYPE.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The spam information type.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendST(ZCOOKIE zCookie, ZCHAR *pcMsg, ZUINT iMsgType,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, ZUINT iSpamType);

/**
 * @brief ReSending Instant Message to one participant with spam information.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_PMSG_CTYPE.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] pcReImdnId The resend imdn message id.
 * @param [in] iSpamType The spam information type.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendST(ZCOOKIE zCookie, ZCHAR *pcMsg, ZUINT iMsgType,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, ZCHAR *pcReImdnId,
                ZUINT iSpamType);

/**
 * @brief Sending Instant Message to group chat participant.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendG(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZBOOL bCpim);

/**
 * @brief ReSending Instant Message to group chat participant.
 * IM will send by SIP MESSAGE method only used by CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] bCpim The message body format, text plain or CPIM.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgReSendG(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZBOOL bCpim, ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message to one participant with SMS.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body, formated by SMS.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendSms(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg);

/**
 * @brief Sending ex-vcard message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The ex-vcard message body.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendExvcard(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg);

/**
 * @brief Sending x-vcard message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The x-vcard message body.
 * @param [in] pcConvId The conversation id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendXvcard(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg, ZCHAR* pcConvId);

/**
 * @brief Sending bgm mix message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The xml message body.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgSendBgmMix(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg);

/**
 * @brief Sending Instant Message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message content type.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSendU
 */
ZFUNC ZUINT Mtc_ImPMsgSendN(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                  ZUINT iMsgType);

/**
 * @brief ReSending Instant Message to one participant only used for cmcc.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message content type.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSendU
 */
ZFUNC ZUINT Mtc_ImPMsgReSendN(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
              ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message to participant list.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message content type.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSend
 */
ZFUNC ZUINT Mtc_ImPMsgSendUN(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsg, ZUINT iMsgType);

/**
 * @brief ReSending Instant Message to participant list.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message content type.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSend
 */
ZFUNC ZUINT Mtc_ImPMsgReSendUN(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief Sending callcomposer Message to one participant.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS
 */
ZFUNC ZUINT Mtc_ImPMsgSendE(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg);

/**
 * @brief ReSending callcomposer Message to one participant.
 * IM will be sent by SIP MESSAGE method Only used for CMCC.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS
 */
ZFUNC ZUINT Mtc_ImPMsgReSendE(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
              ZCHAR *pcReImdnId);

/**
 * @brief Sending Instant Message to one participant or participant list.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] iPartpLstId The participant list id. 
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message content type.
 * @param [in] pcConvId The conversation id. 
 * @param [in] pcFontInfo The font information of message. 
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSendU
 */
ZFUNC ZUINT Mtc_ImPMsgUniSend(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZUINT iPartpLstId, ZCHAR *pcMsg, ZUINT iMsgType, 
                ZCHAR* pcConvId, ZCHAR *pcFontInfo);

/**
 * @brief Sending Instant Message to one participant or participant list.
 * IM will be sent by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * While receiving IM, GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetPMsgRecvMsg or @ref Mtc_ImCbSetPMsgRecvSmsInfo.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] iPartpLstId The participant list id. 
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message content type.
 * @param [in] pcConvId The conversation id. 
 * @param [in] pcFontInfo The font information of message. 
 * @param [in] pcReImdnId The resend imdn message id. 
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_ImPMsgSendRS, @ref Mtc_ImPMsgSendU
 */
ZFUNC ZUINT Mtc_ImPMsgUniReSend(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZUINT iPartpLstId, ZCHAR *pcMsg, ZUINT iMsgType, 
                ZCHAR* pcConvId, ZCHAR *pcFontInfo, ZCHAR *pcReImdnId);

/**
 * @brief Reply to specific standalone page mode message.
 * CPM message will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetPMsgSendOk or @ref Mtc_ImCbSetPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgLen The message size.
 * @param [in] iMsgType The message type, @see @ref EN_MTC_PMSG_CTYPE.
 * @param [in] pcConvId The conversation-id.
 * @param [in] pcContId The contribution-id reply to.
 *
 * @retval ZOK Send message successfully.
 * @retval ZFAILED Send message failed.
 */
ZFUNC ZUINT Mtc_ImPMsgReply(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZUINT iMsgLen, ZUINT iMsgType, ZCHAR *pcConvId, 
                ZCHAR *pcContId);

/**
 * @brief MTC Get user cookie from page message.
 *
 * @param [in] iMsgId The message id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImPMsgGetCookie(ZUINT iMsgId);

/**
 * @brief MTC Set user cookie in a page message.
 *
 * @param [in] iMsgId The message id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImPMsgSetCookie(ZUINT iMsgId, ZCOOKIE zCookie);

/**
 * @brief MTC Get the Imdn type from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return Type of page message, @ref EN_MTC_PMSG_IMDN_TYPE.
 */
ZFUNC ZUINT Mtc_ImPMsgGetImdnType(ZUINT iMsgId);

/**
 * @brief MTC Get the imdn message-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The page message imdn message-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetImdnMsgId(ZUINT iMsgId);

/**
 * @brief MTC Get device id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The page message device id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetDeviceId(ZUINT iMsgId);

/**
 * @brief MTC Get the content type from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return Type of page message, @ref EN_MTC_PMSG_CTYPE.
 *
 * @see @ref Mtc_ImPMsgGetContentTypeX
 */
ZFUNC ZUINT Mtc_ImPMsgGetContentType(ZUINT iMsgId);

/**
 * @brief MTC Get the content length from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The message content length.
 */
ZFUNC ZUINT Mtc_ImPMsgGetContentLen(ZUINT iMsgId);

/**
 * @brief MTC Get the content from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The page message content.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetContent(ZUINT iMsgId);

/**
 * @brief MTC Get the multi-media content from page message.
 *
 * @param [in] iMsgId The message Id.
 * @param [out] ppData The multi-media message content.
 * @param [out] piDataSize The multi-media message content length.
 *
 * @return The page message content.
 * The caller must copy it, then use.
 */
ZFUNC ZINT Mtc_ImPMsgGetMContent(ZUINT iMsgId, ZVOID **ppData, 
                ZUINT *piDataSize);
/**
 * @brief MMF Get participant type from page message.
 *
 * @param [in] iMsgId The message id.
 *
 * @retval Type of page message participant type, @see @ref EN_MTC_PARTP_LST_TYPE.
 *
 * If type is EN_MTC_PARTP_LST_ONE, participant can be got by Mtc_ImPMsgGetPartp.
 * If type is EN_MTC_PARTP_LST_PREDEF_GRP, participant can be got by Mtc_ImPMsgGetPartp.
 * If type is EN_MTC_PARTP_LST_URI_LST, participant can be got by Mtc_ImPMsgGetPartpLstId.
 */
ZFUNC ZUINT Mtc_ImPMsgGetPartpType(ZUINT iMsgId);

/**
 * @brief MTC Get participant information from page message.
 * Get receiver information from feion carbon copy page message.
 *
 * The participant is the remote client who sent message.
 *
 * @param [in] iMsgId The message Id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * ppcName and ppcUri must copy it, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImPMsgGetPartp(ZUINT iMsgId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get participant list id from im message.
 *
 * The participant list id is all remote clients who are received message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval The participant list id.
 * The caller is responsible for freeing it by Mtc_PartpLstDelete
 */
ZFUNC ZUINT Mtc_ImPMsgGetPartpLstId(ZUINT iMsgId);

/**
 * @brief MTC Get date time from page message.
 *
 * @param [in] iMsgId The message Id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time failed.
 */
ZFUNC ZINT Mtc_ImPMsgGetSysDateTime(ZUINT iMsgId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The page message date time(milliseconds), otherwise return 0.
 */
ZFUNC ZMTIME_T Mtc_ImPMsgGetDateTime(ZUINT iMsgId);

/**
 * @brief MTC Get font information from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval The font information.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetFontInfo(ZUINT iMsgId);

/**
 * @brief MTC Get OMA IM flag from page message.
 * OMA IM flag exist in accept header +g.oma.sip-im.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a OMA page message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasOmaIm(ZUINT iMsgId); 

/**
 * @brief MTC Get OMA IM flag from IM system message.
 * OMA IM system message flag exist in accept header +g.oma.sip-im.system-message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a OMA IM system message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasOmaImSys(ZUINT iMsgId); 

/**
 * @brief MTC Get RCS SMS flag from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a RCS SMS message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasRcsSms(ZUINT iMsgId); 

/**
 * @brief MTC Get sms indication flag from page message.
 * It has "sms;operation=submit" in "P-Message-Type-Indicator".
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a RCS SMS message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasSmsInd(ZUINT iMsgId); 

/**
 * @brief MTC Get conversation-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The conversation-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetConvId(ZUINT iMsgId);

/**
 * @brief MTC Get contribution-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The contribution-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetContId(ZUINT iMsgId);

/**
 * @brief MTC Get inreplyto-contribution-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The inreplyto-contribution-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetIrtContId(ZUINT iMsgId);

/**
 * @brief MTC Get status code from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZOK Get status code successfully.
 * @retval ZFAILED Get status code failed.
 */
ZFUNC ZUINT Mtc_ImPMsgGetStatCode(ZUINT iMsgId);

/**
 * @brief MTC Get public message indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has public message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasPubInd(ZUINT iMsgId);

/**
 * @brief MTC Get group manage message indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has group manage message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasGrpMInd(ZUINT iMsgId);

/**
 * @brief MTC Get callcomposer message indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has callcomposer message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasCallComposerInd(ZUINT iMsgId);

/**
 * @brief MTC Get revoke message indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has revoke message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasRevokeMsgInd(ZUINT iMsgId);

/**
 * @brief MTC Get burn after reading indication flag from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a burn after reading message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasBurnInd(ZUINT iMsgId);

/**
 * @brief MTC Get burn after reading time length from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return burn after reading time length.
 */
ZFUNC ZUINT Mtc_ImPMsgGetBurnTimeLen(ZUINT iMsgId);

/**
 * @brief MTC Get spam indication flag from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a spam message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasSpamInd(ZUINT iMsgId);

/**
 * @brief MTC Get directional indication flag from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a directional message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasDirectInd(ZUINT iMsgId);

/**
 * @brief MTC Get carbon copy indication flag from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a carbon copy message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasCcInd(ZUINT iMsgId);

/**
 * @brief MTC Get silence indication flag from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a silence message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasSilenceInd(ZUINT iMsgId);

/**
 * @brief MTC Get offline indication flag from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a offline message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImPMsgHasOffInd(ZUINT iMsgId);

/**
 * @brief MTC Get revoke message-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke message-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetRevokeMsgId(ZUINT iMsgId);

/**
 * @brief MTC Get revoke result from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke result.
 */
ZFUNC ZUCHAR Mtc_ImPMsgGetRevokeResult(ZUINT iMsgId);

/**
 * @brief MTC Get revoke from addr from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke from addr.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetRevokeFromAddr(ZUINT iMsgId);

/**
 * @brief MTC Get revoke to addr from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke to addr.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetRevokeToAddr(ZUINT iMsgId);

/**
 * @brief MTC Get the qrcode group-name from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The page message content.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetQrcodeGrpName(ZUINT iMsgId);

/**
 * @brief MTC Get the qrcode group-Uri from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The page message content.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetQrcodeGrpUri(ZUINT iMsgId);

/**
 * @brief MTC Get the qrcode group-proposer from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The page message content.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetQrcodeGrpProposer(ZUINT iMsgId);

/**
 * @brief MTC Get the qrcode reason from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The page message content.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgGetQrcodeReason(ZUINT iMsgId);

/**
 * @brief MTC Get the qrcode option type from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return Type of page message, @ref EN_MTC_PMSG_GROUP_JOIN_NTFY_OPTION_TYPE.
 */
ZFUNC ZUINT Mtc_ImPMsgGetQrcodeOptionType(ZUINT iMsgId);

/**
 * @brief MTC Get app push type from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return app push type if it is a oma push message, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImPMsgGetAppPushType(ZUINT iMsgId);

/* mtc create revoke xml. */
/**
 * @brief MTC create revoke xml content.
 *
 * @param [in] pcMsgId The revoke message-id.
 * @param [in] pcRevokeResult message revoke result.
 * @param [in] pcFromAddr message revoke from addr.
 * @param [in] pcToAddr message revoke to addr. 
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImPMsgCreateRevokeXml(ZCHAR *pcMsgId, ZCHAR *pcRevokeResult,
                ZCHAR *pcFromAddr, ZCHAR *pcToAddr);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_H__ */

