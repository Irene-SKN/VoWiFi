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
  File name     : mtc_im_large.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC instant message

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_LARGE_H__
#define _MTC_IM_LARGE_H__

/**
 * @file mtc_im_large.h
 * @brief MTC Instant Message Large Mode Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC IM large message imdn type */
#define MTC_IM_LMSG_IMDN_NO            0x00000000 /**< @brief no notification request, regular message */
#define MTC_IM_LMSG_IMDN_UNKNOWN       0x00000001 /**< @brief unknown imdn type */
#define MTC_IM_LMSG_IMDN_DELI_SUCC     0x00000002 /**< @brief message with delivery succeed notification request */
#define MTC_IM_LMSG_IMDN_DELI_FAIL     0x00000004 /**< @brief message with delivery fail notification request */
#define MTC_IM_LMSG_IMDN_DELI_FWD      0x00000008 /**< @brief message with delivery forward notification request */
#define MTC_IM_LMSG_IMDN_DISP          0x00000010 /**< @brief message with display notification request */
#define MTC_IM_LMSG_IMDN_BURN          0x00000020/**< @brief message with burn after reading notification request */


/** @brief MTC IM large message content type */
typedef enum EN_MTC_IM_LMSG_CONT_TYPE
{
    EN_MTC_IM_LMSG_CONT_UNKNOWN,     /**< @brief unknown content */
    EN_MTC_IM_LMSG_CONT_TXT_PLAIN,   /**< @brief text/plain content */
    EN_MTC_IM_LMSG_CONT_XML,         /**< @brief "message/xml" content */
    EN_MTC_IM_LMSG_CONT_OMAPUSH,         /**< @brief "application/vnd.oma.push" content */   
    EN_MTC_IM_LMSG_CONT_MSG_TXT_PLAIN,/**< @brief content type of "text/plain" wrapt by cpim */
    EN_MTC_IM_LMSG_CONT_MSG_IMAGE_JPEG,/**< @brief content type of "image/jpeg" wrapt by cpim */
    EN_MTC_IM_LMSG_CONT_MSG_IMAGE_BMP, /**< @brief content type of "image/bmp" wrapt by cpim */
    EN_MTC_IM_LMSG_CONT_MSG_IMDN,     /**< @brief content type of "message/imdn+xml" wrapt by cpim */   
    EN_MTC_IM_LMSG_CONT_MSG_XML,      /**< @brief content type of "message/xml" wrapt by cpim */   
    EN_MTC_IM_LMSG_CONT_MSG_VEMOTICON, /**< @brief content type of "message/vemoticon+xml" wrapt by cpim */   
    EN_MTC_IM_LMSG_CONT_MSG_CLOUD_FILE, /**< @brief content type of "message/cloudfile+xml" wrapt by cpim */   
    EN_MTC_IM_LMSG_CONT_MSG_CMRED_BAG, /**< @brief content type of "message/cmredbag+xml" wrapt by cpim */   
    EN_MTC_IM_LMSG_CONT_MSG_CARD, /**< @brief content type of "message/card+xml" wrapt by cpim */
    EN_MTC_IM_LMSG_CONT_MSG_139MAIL_NEW, /**< @brief content type of "application/commonextension+xml" wrapt by cpim */
    EN_MTC_IM_LMSG_CONT_MSG_TXT_SMS,   /**< @brief content type of "text/sms" wrapt by cpim */
    EN_MTC_IM_LMSG_CONT_MSG_COM_TEMP,     /**< @brief content type of "application/commontemplate+xml" wrapt by cpim */
    EN_MTC_IM_LMSG_CONT_MSG_CHRED_BAG, /**< @brief content type of "message/cmredbag+xml" wrapt by cpim */
    EN_MTC_IM_LMSG_CONT_MSG_REVOKE,       /**< @brief content type of "application/vnd.gsma.rcsrevoke+xml" wrapt by cpim */
} EN_MTC_IM_LMSG_CONT_TYPE;

/** @brief MTC IM large message spam type */
typedef enum EN_MTC_IM_LMSG_SPAM_TYPE
{
    EN_MTC_IM_LMSG_SPAM_MIN,
    EN_MTC_IM_LMSG_SPAM_POLITICAL_RUMOR,            /**< @brief political rumor msg */
    EN_MTC_IM_LMSG_SPAM_JURISPRUDENCE,                /**< @brief jurisprudence msg */
    EN_MTC_IM_LMSG_SPAM_FRAUD,                               /**< @brief fraud msg */
    EN_MTC_IM_LMSG_SPAM_MALICIOUS_MARKETING,   /**< @brief malicious marketing msg */
    EN_MTC_IM_LMSG_SPAM_VIOLENCE,                          /**< @brief violence msg */
    EN_MTC_IM_LMSG_SPAM_OTHER = 9,                         /**< @brief other msg */
    EN_MTC_IM_LMSG_SPAM_MAX
} EN_MTC_IM_LMSG_SPAM_TYPE;

/**
 * @brief MTC Sending Large Instant Message to One Participant.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgSend(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg, ZUINT iMsgType);

/**
 * @brief MTC ReSending Large Instant Message to One Participant
 * Only used to CMCC.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgReSend(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief MTC Sending Burn After Reading Large Instant Message to One Participant
 * Only used to CMCC.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * Gui can get the burn after reading flag when receiving IM(large message)
 * by @ref Mtc_ImLMsgHasBurnInd.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 *
 * @return The large message session id when send burn after reading large message
 *              successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgSendB(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg, ZUINT iMsgType);


/**
 * @brief MTC ReSending Burn After Reading Large Instant Message to One Participant
 * Only used to CMCC.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * Gui can get the burn after reading flag when receiving IM(large message)
 * by @ref Mtc_ImLMsgHasBurnInd.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The large message session id when send burn after reading large message
 *              successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgReSendB(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief MTC Sending multi-media Message to One Participant.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pData The multi-media message body.
 * @param [in] iDataSize The multi-media message size.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgSendM(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZVOID *pData, ZUINT iDataSize, ZUINT iMsgType);


/**
 * @brief MTC ReSending multi-media Message to One Participant
 * Only used to CMCC.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pData The multi-media message body.
 * @param [in] iDataSize The multi-media message size.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgReSendM(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZVOID *pData, ZUINT iDataSize, ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief MTC Reply to specific standalone large message.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcConvId The conversation-id.
 * @param [in] pcContId The contribution-id which reply to.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgReply(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZUINT iMsgType, ZCHAR *pcConvId, ZCHAR *pcContId);

/**
 * @brief MTC Sending Large Instant Message to URI-List.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgSendU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsg, ZUINT iMsgType);


/**
 * @brief MTC ReSending Large Instant Message to URI-List
 * Only used to CMCC.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgReSendU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief MTC Sending Large Instant Message to one participant with spam information.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgLen The message size.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgSendS(ZCOOKIE zCookie, ZCHAR *pcMsg, 
                ZUINT iMsgType, ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);


/**
 * @brief MTC ReSending Large Instant Message to one participant with spam information
 * Only used to CMCC.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgLen The message size.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgReSendS(ZCOOKIE zCookie, ZCHAR *pcMsg, 
                ZUINT iMsgType, ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate,
                ZCHAR *pcReImdnId);

/**
 * @brief MTC Sending Large Instant Message to one participant with spam information.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgLen The message size.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The spam information type.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgSendST(ZCOOKIE zCookie, ZCHAR *pcMsg, 
                ZUINT iMsgType, ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate,
                ZUINT iSpamType);


/**
 * @brief MTC ReSending Large Instant Message to one participant with spam information
 * Only used to CMCC.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgLen The message size.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] pcReImdnId The resend imdn message id.
 * @param [in] iSpamType The spam information type.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgReSendST(ZCOOKIE zCookie, ZCHAR *pcMsg, 
                ZUINT iMsgType, ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate,
                ZCHAR *pcReImdnId, ZUINT iSpamType);

/**
 * @brief MTC Sending Large Instant Message to Public Account.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgSendP(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZUINT iMsgType);


/**
 * @brief MTC ReSending Large Instant Message to Public Account
 * Only used to CMCC.
 *
 * If IM send successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgSendFailed.
 *
 * While receiving IM(large message), GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetLMsgRecvMsg.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see @ref EN_MTC_IM_LMSG_CONT_TYPE.
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgReSendP(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcMsg, 
                ZUINT iMsgType, ZCHAR *pcReImdnId);

/**
 * @brief Sending Large Instant Message with font information to One Participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see EN_MMF_LMSG_CONT_TYPE.
 * @param [in] pcFontInfo The font information of message.
 * @param [in] bBurn The message burn flag.
 * @param [out] piMsgId The id for large message session.
 *
  * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImLMsgSendF(ZCOOKIE zCookie, ZCHAR *pcUri, ZUINT iPartpLstId, 
                    ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcFontInfo, ZBOOL bBurn);

/**
 * @brief ReSending Large Instant Message with font information to One Participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see EN_MMF_LMSG_CONT_TYPE.
 * @param [in] pcFontInfo The font information of message.
 * @param [in] bBurn The message burn flag.
 * @param [in] pcReImdnId The resend imdn message id.
 * @param [out] piMsgId The id for large message session.
 *
  * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZINT Mtc_ImLMsgReSendF(ZCOOKIE zCookie, ZCHAR *pcUri, ZUINT iPartpLstId, 
                    ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcFontInfo, ZBOOL bBurn, 
                    ZCHAR *pcReImdnId);

/**
 * @brief Sending Large Instant Message to One Participant or participant list.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see EN_MMF_LMSG_CONT_TYPE.
 * @param [in] pcFontInfo The font information of message.
 * @param [out] piMsgId The id for large message session.
 *
  * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgUniSend(ZCOOKIE zCookie, ZCHAR *pcUri, ZUINT iPartpLstId, 
                    ZCHAR *pcMsg, ZUINT iMsgType, ZCHAR *pcFontInfo);

/**
 * @brief ReSending Large Instant Message to One Participant or participant list.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcMsg The message body.
 * @param [in] iMsgType The message type, see EN_MMF_LMSG_CONT_TYPE.
 * @param [in] pcFontInfo The font information of message.
 * @param [in] pcReImdnId The resend imdn message id. 
 * @param [out] piMsgId The id for large message session.
 *
  * @return The large message session id when send large message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgUniReSend(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZUINT iPartpLstId, ZCHAR *pcMsg, ZUINT iMsgType, 
                ZCHAR *pcFontInfo, ZCHAR *pcReImdnId);

/**
 * @brief MTC Get user cookie from a large message.
 *
 * @param [in] iMsgId The large message id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImLMsgGetCookie(ZUINT iMsgId);

/**
 * @brief MTC Set user cookie in a large message.
 *
 * @param [in] iMsgId The large message id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImLMsgSetCookie(ZUINT iMsgId, ZCOOKIE zCookie);

/**
 * @brief MTC Get the Imdn type from large message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return Type of large message, see @ref EN_MTC_IM_LMSG_IMDN_TYPE.
 */
ZFUNC ZUINT Mtc_ImLMsgGetImdnType(ZUINT iMsgId);

/**
 * @brief MTC Get imdn message-id from large message.
 *
 * @param [in] iMsgId The large message id.
 *
 * @return The imdn message-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetImdnMsgId(ZUINT iMsgId);

/**
 * @brief MTC Get device id from large message.
 *
 * @param [in] iMsgId The large message id.
 *
 * @return The device id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetDeviceId(ZUINT iMsgId);

/**
 * @brief MTC Get content type from large message.
 *
 * @param [in] iMsgId The large message id.
 *
 * @return Content type, see @ref EN_MTC_IM_LMSG_CONT_TYPE....
 */
ZFUNC ZUINT Mtc_ImLMsgGetContentType(ZUINT iMsgId);

/**
 * @brief MTC Get content from large message.
 *
 * @param [in] iMsgId The large message id.
 *
 * @return The message content.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetContent(ZUINT iMsgId);

/**
 * @brief MTC Get multi-media content from large message.
 *
 * @param [in] iMsgId The large message id.
 * @param [out] ppData The multi-media message content.
 * @param [out] piDataSize The multi-media message content length.
 *
 * @return The message content.
 * The caller must copy it, then use.
 */
ZFUNC ZINT Mtc_ImLMsgGetMContent(ZUINT iMsgId, ZVOID **ppData, 
                ZUINT *piDataSize);

/**
 * @brief MTC Get participant type from large message.
 *
 * @param [in] iMsgId The large message id.
 *
 * @return Type of large message participant, see @ref EN_MTC_PARTP_LST_TYPE.
 *
 * If type is EN_MTC_PARTP_LST_ONE, participant can be got by @ref Mtc_ImLMsgGetPartp.
 * If type is EN_MTC_PARTP_LST_PREDEF_GRP, participant can be got by @ref Mtc_ImLMsgGetPartp.
 * If type is EN_MTC_PARTP_LST_URI_LST, participant can be got by @ref Mtc_ImLMsgGetPartpLst.
 */
ZFUNC ZUINT Mtc_ImLMsgGetPartpType(ZUINT iMsgId);

/**
 * @brief MTC Get participant information from large message.
 * Get receiver information from fetion carbon copy large message.
 *
 * The participant is the remote client who sent large message.
 *
 * @param [in] iMsgId The large message id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImLMsgGetPartp(ZUINT iMsgId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get participant list id from large message.
 *
 * The participant list id is all remote clients who sent large message.
 *
 * @param [in] iMsgId The large message id.
 *
 * @return Participant list id.
 *   The caller is responsible for freeing it by @ref Mtc_PartpLstDelete.
 */
ZFUNC ZUINT Mtc_ImLMsgGetPartpLst(ZUINT iMsgId);

/**
 * @brief MTC Get original participant from large message.
 *
 * The participant is the session initiator who initialized this large message.
 * It will return local URI if local client is the large message initiator.
 * It will return From uri from large message invitation information.
 *
 * @param [in] iMsgId The large message id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImLMsgGetOrigPartp(ZUINT iMsgId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief MTC Get original identity of participant from large message.
 *
 * The participant is the session initiator who initialized large message session.
 * It will return local URI if local client is the session initiator.
 * It will return identity uri if session invitation has P-Asserted-Identity information.
 *
 * @param [in] iMsgId The large message id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImLMsgGetOrigIdPartp(ZUINT iMsgId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief MTC Get date time from large message.
 *
 * @param [in] iMsgId The message Id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time failed.
 */
ZFUNC ZINT Mtc_ImLMsgGetSysDateTime(ZUINT iMsgId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from large message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return large message date time(milliseconds), otherwise return 0.
 */
ZFUNC ZMTIME_T Mtc_ImLMsgGetDateTime(ZUINT iMsgId);

/**
 * @brief MTC Get the font information from large message.
 *
 * @param [in] iMsgId The large message id.
 *
 * @retval Font information of message, otherwise NULL.
 */
ZFUNC ZCHAR* Mtc_ImLMsgGetFontInfo(ZUINT iMsgId);

/**
 * @brief MTC Get conversation-id from large message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The conversation-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetConvId(ZUINT iMsgId);

/**
 * @brief MTC Get contribution-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The contribution-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetContId(ZUINT iMsgId);

/**
 * @brief MTC Get inreplyto-contribution-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The inreplyto-contribution-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetIrtContId(ZUINT iMsgId);

/**
 * @brief MTC Get public messgae indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has public messgae indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImLMsgHasPubInd(ZUINT iMsgId);

/**
 * @brief MTC Get burn after reading messgae indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has burn after reading messgae indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImLMsgHasBurnInd(ZUINT iMsgId);

/**
 * @brief MTC Get burn after reading time length from large message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return burn after reading time length.
 */
ZFUNC ZUINT Mtc_ImLMsgGetBurnTimeLen(ZUINT iMsgId);

/**
 * @brief MTC Get spam messgae indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has spam messgae indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImLMsgHasSpamInd(ZUINT iMsgId);

/**
 * @brief MTC Get directional messgae indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has directional messgae indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImLMsgHasDirectInd(ZUINT iMsgId);

/**
 * @brief MTC Get carbon copy messgae indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has carbon copy messgae indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImLMsgHasCcInd(ZUINT iMsgId);

/**
 * @brief MTC Get silence messgae indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has silence messgae indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImLMsgHasSilenceInd(ZUINT iMsgId);

/**
 * @brief MTC Get offline messgae indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has offline messgae indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImLMsgHasOffInd(ZUINT iMsgId);

/**
 * @brief MTC Get app push type from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval app push type if it is a oma push message, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImLMsgGetAppPushType(ZUINT iMsgId);

/**
 * @brief MTC Get revoke message indication flag from large message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has revoke message indication, otherwise return ZFALSE.
 */
 ZFUNC  ZBOOL Mtc_ImLMsgHasRevokeMsgInd(ZUINT iMsgId);

/**
 * @brief MTC Get revoke message-id from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke message-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetRevokeMsgId(ZUINT iMsgId);

/**
 * @brief MTC Get revoke result from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke result.
 */
ZFUNC ZUCHAR Mtc_ImLMsgGetRevokeResult(ZUINT iMsgId);

/**
 * @brief MTC Get revoke from addr from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke from addr.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetRevokeFromAddr(ZUINT iMsgId);

/**
 * @brief MTC Get revoke to addr from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke to addr.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImLMsgGetRevokeToAddr(ZUINT iMsgId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_LARGE_H__ */

