/************************************************************************

        Copyright (c) 2005-2013 by Juphoon System Software, Inc.
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
  File name     : mtc_gs_ginfo.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2013-02-05
  Description   :
      Data structure and function declare required by MTC geolocation share.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_GS_GINFO_H__
#define _MTC_GS_GINFO_H__

/**
 * @file mtc_gs_ginfo.h
 * @brief MTC Geolocation Share Geolocation Information Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC gs status code(error no or terminated code). */
#define MTC_GS_ERR_NO               (MTC_EBASE_GS + 0) /**< @brief no error. */
#define MTC_GS_ERR_FORBIDDEN        (MTC_EBASE_GS + 1) /**< @brief gs forbidden. */
#define MTC_GS_ERR_NOT_FOUND        (MTC_EBASE_GS + 2) /**< @brief gs participant not found. */
#define MTC_GS_ERR_NOT_ACPTED       (MTC_EBASE_GS + 3) /**< @brief gs not accepted. */
#define MTC_GS_ERR_TEMP_UNAVAIL     (MTC_EBASE_GS + 4) /**< @brief gs participant temp unavailable. */
#define MTC_GS_ERR_REQ_TERMED       (MTC_EBASE_GS + 5) /**< @brief gs request terminated. */
#define MTC_GS_ERR_INTERNAL_ERR     (MTC_EBASE_GS + 6) /**< @brief server internal error. */
#define MTC_GS_ERR_SRV_UNAVAIL      (MTC_EBASE_GS + 7) /**< @brief service unavailable. */
#define MTC_GS_ERR_TIMEOUT          (MTC_EBASE_GS + 8) /**< @brief request timeout. */
#define MTC_GS_ERR_OFFLINE          (MTC_EBASE_GS + 9) /**< @brief callee not registered. */
#define MTC_GS_ERR_SURPASS_TRAFFIC  (MTC_EBASE_GS + 10) /**< @brief surpass traffic */
#define MTC_GS_ERR_EMERGENCY_FORBIDDEN (MTC_EBASE_GS + 11) /**< @brief emergency forbidden */
#define MTC_GS_ERR_FILE_EXPIRED     (MTC_EBASE_GS + 12) /**< @brief file expired */
#define MTC_GS_ERR_SEND_TIMEOUT     (MTC_EBASE_GS + 13) /**< @brief file expired */

#define MTC_GS_ERR_OTHER            (MTC_EBASE_GS + 14) /**< @brief other error. */

/**< @brief MTC gs geolocation IMDN type */
#define MTC_GS_GINFO_IMDN_NO             0x00000000 /**< @brief no notification request, regular location */
#define MTC_GS_GINFO_IMDN_UNKNOWN        0x00000001 /**< @brief unknown imdn type */
#define MTC_GS_GINFO_IMDN_DELI_SUCC      0x00000002 /**< @brief location with delivery succeed notification request */
#define MTC_GS_GINFO_IMDN_DELI_FAIL      0x00000004 /**< @brief location with delivery fail notification request */
#define MTC_GS_GINFO_IMDN_DELI_FWD       0x00000008 /**< @brief location with delivery forward notification request */
#define MTC_GS_GINFO_IMDN_DISP           0x00000010 /**< @brief location with display notification request */

/** @brief MTC gs geolocation information type */
typedef enum EN_MTC_GS_GINFO_TYPE
{
    EN_MTC_GS_GINFO_UNKNOWN = 0,                /**< @brief unknown. */
    EN_MTC_GS_GINFO_FREE_TEXT = 1,              /**< @brief free text. */
    EN_MTC_GS_GINFO_2D_CIRCLE = 2,              /**< @brief 2d circle. */
    EN_MTC_GS_GINFO_BOTH = 3,                   /**< @brief both. */
} EN_MTC_GS_GINFO_TYPE;

/** @brief MTC gs geolocation message spam type */
typedef enum EN_MTC_GS_GINFO_SPAM_TYPE
{
    EN_MTC_GS_GINFO_SPAM_MIN,
    EN_MTC_GS_GINFO_SPAM_POLITICAL_RUMOR,            /**< @brief political rumor msg */
    EN_MTC_GS_GINFO_SPAM_JURISPRUDENCE,                /**< @brief jurisprudence msg */
    EN_MTC_GS_GINFO_SPAM_FRAUD,                               /**< @brief fraud msg */
    EN_MTC_GS_GINFO_SPAM_MALICIOUS_MARKETING,   /**< @brief malicious marketing msg */
    EN_MTC_GS_GINFO_SPAM_VIOLENCE,                          /**< @brief violence msg */
    EN_MTC_GS_GINFO_SPAM_OTHER = 9,                         /**< @brief other msg */
    EN_MTC_GS_GINFO_SPAM_MAX
} EN_MTC_GS_GINFO_SPAM_TYPE;

/**
 * @brief MTC Push free text to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushText(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcUri, ZCHAR *pcLabel);

/**
 * @brief MTC Push free text to public account.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushTextP(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcUri, ZCHAR *pcLabel);

/**
 * @brief MTC Push spam free text to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushTextS(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcLabel, ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);

/**
 * @brief MTC Push spam free text to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The Spam information type.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushTextST(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcLabel, ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, 
                ZUINT iSpamType);

/**
 * @brief MTC Push free text to participant list.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushTextU(ZCOOKIE zCookie, ZCHAR *pcFreeText, 
                ZUINT iPartpLstId, ZCHAR *pcLabel);

/**
 * @brief MTC Push free text to group chat.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushTextX(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcSubject, ZCHAR *pcUri, ZCHAR *pcGrpChatId, 
                ZCHAR *pcLabel);

/**
 * @brief MTC Push coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushCoord(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcUri, 
                ZCHAR *pcLabel);

/**
 * @brief MTC Push coordinate to public account.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushCoordP(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcUri, 
                ZCHAR *pcLabel);

/**
 * @brief MTC Push spam coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushCoordS(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcLabel,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);

/**
 * @brief MTC Push spam coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The spam information type.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushCoordST(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcLabel,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, ZUINT iSpamType);

/**
 * @brief MTC Push coordinate to participant list.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * Note: if radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushCoordU(ZCOOKIE zCookie, ZDOUBLE dLatitude, 
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZUINT iPartpLstId, 
                ZCHAR *pcLabel);

/**
 * @brief MTC Push coordinate to group chat.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushCoordX(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcGrpChatId, ZCHAR *pcLabel);

/**
 * @brief MTC Push both free text and coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushBoth(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcUri, ZCHAR *pcLabel);

/**
 * @brief MTC Push both free text and coordinate to public account.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushBothP(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcUri, ZCHAR *pcLabel);

/**
 * @brief MTC Push both spam free text and spam coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushBothS(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcLabel, ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);

/**
 * @brief MTC Push both spam free text and spam coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The spam information type.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushBothST(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcLabel, ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, 
                ZUINT iSpamType);

/**
 * @brief MTC Push both free text and coordinate to participant list.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * Note: if radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushBothU(ZCOOKIE zCookie, ZCHAR *pcFreeText, 
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZUINT iPartpLstId, ZCHAR *pcLabel);

/**
 * @brief MTC Push both free text and coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPushBothX(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcSubject, ZCHAR *pcUri, ZCHAR *pcGrpChatId,
                ZCHAR *pcLabel);

/**
 * @brief MTC Resend Push free text to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushText(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcUri, ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push free text to public account.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushTextP(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcUri, ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push spam free text to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushTextS(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);

/**
 * @brief MTC Resend Push spam free text to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The spam information type.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushTextST(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, ZUINT iSpamType);


/**
 * @brief MTC Resend Push free text to participant list.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushTextU(ZCOOKIE zCookie, ZCHAR *pcFreeText, 
                ZUINT iPartpLstId, ZCHAR *pcLabel, ZCHAR *pcReTrsfId, 
                ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push free text to group chat.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushTextX(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZCHAR *pcSubject, ZCHAR *pcUri, ZCHAR *pcGrpChatId, 
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushCoord(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcUri, 
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC RePush coordinate to public account.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushCoordP(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcUri, 
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC RePush spam coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushCoordS(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcLabel,
                ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);

/**
 * @brief MTC RePush spam coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The spam information type.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushCoordST(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcLabel,
                ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, ZUINT iSpamType);


/**
 * @brief MTC Resend Push coordinate to participant list.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * Note: if radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushCoordU(ZCOOKIE zCookie, ZDOUBLE dLatitude, 
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZUINT iPartpLstId, 
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push coordinate to group chat.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushCoordX(ZCOOKIE zCookie, ZDOUBLE dLatitude,
                ZDOUBLE dLongitude, ZFLOAT fRadius, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcGrpChatId, ZCHAR *pcLabel, 
                ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push both free text and coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushBoth(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcUri, ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push both free text and coordinate to public account.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushBothP(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcUri, ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push both free text and coordinate to public account.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushBothS(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);

/**
 * @brief MTC Resend Push both free text and coordinate to public account.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position,
 *             else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The spam information type.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushBothST(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId,
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, ZUINT iSpamType);


/**
 * @brief MTC Resend Push both free text and coordinate to participant list.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * Note: if radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushBothU(ZCOOKIE zCookie, ZCHAR *pcFreeText, 
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZUINT iPartpLstId, ZCHAR *pcLabel, ZCHAR *pcReTrsfId, 
                ZCHAR *pcReMsgId);

/**
 * @brief MTC Resend Push both free text and coordinate to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 * @param [in] pcReTrsfId The resend file-transfer-id @ref Mtc_GsGInfoGetTrsfId.
 * @param [in] pcReMsgId  The resend imdn message-id @ref Mtc_GsGInfoGetImdnMsgId.
 *
 * @note If radius value is equal to 0, the coordinate is a point,
 *       if radius value is bigger than 0, the coordinate is a circle.
 *
 * @return Push geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoRePushBothX(ZCOOKIE zCookie, ZCHAR *pcFreeText,
                ZDOUBLE dLatitude, ZDOUBLE dLongitude, ZFLOAT fRadius, 
                ZCHAR *pcSubject, ZCHAR *pcUri, ZCHAR *pcGrpChatId,
                ZCHAR *pcLabel, ZCHAR *pcReTrsfId, ZCHAR *pcReMsgId);

/**
 * @brief MTC Accept the push request from one participant.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZOK Accept successfully.
 * @retval ZFAILED Accept failed.
 */
ZFUNC ZINT Mtc_GsGInfoPushAcpt(ZUINT iGInfoId);

/**
 * @brief MTC Deny the push request from one participant.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZOK Denyine successfully.
 * @retval ZFAILED Denyine failed.
 */
ZFUNC ZINT Mtc_GsGInfoPushDeny(ZUINT iGInfoId);

/**
 * @brief MTC Pull geolocation information from one participant via file transfer.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 *
 * @return Pull geolocation information successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GsGInfoPullViaFt(ZCOOKIE zCookie, ZCHAR *pcUri);

/**
 * @brief MTC Accept the pull request from one participant.
 *
 * @param [in] iGInfoId The geolocation information id.
 * @param [in] iGInfoType The geolocation information type, see @ref EN_MTC_GS_GINFO_TYPE.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @retval ZOK Accept successfully.
 * @retval ZFAILED Accept failed.
 */
ZFUNC ZINT Mtc_GsGInfoPullAcpt(ZUINT iGInfoId, ZUINT iGInfoType, 
                ZCHAR *pcFreeText, ZDOUBLE dLatitude, ZDOUBLE dLongitude, 
                ZFLOAT fRadius, ZCHAR *pcLabel);

/**
 * @brief MTC Deny the pull request from one participant.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZOK Denyine successfully.
 * @retval ZFAILED Denyine failed.
 */
ZFUNC ZINT Mtc_GsGInfoPullDeny(ZUINT iGInfoId);

/**
 * @brief MTC Sending geolocation fetch invitation to one participant via msrp.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcTransId The file-transfer-id string.
 *
 * @return The geolocation information id, send geolocation fetch invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GInfoFetchViaMsrp(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcTransId);

/**
 * @brief MTC Sending geolocation fetch invitation to group chat via msrp.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpUri The The group chat Session Identity.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcGrpChatId The group chat id.
 *
 * @return The geolocation information id, send geolocation fetch invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_GInfoFetchViaMsrpX(ZCOOKIE zCookie, ZCHAR *pcGrpUri, 
                ZCHAR *pcTransId, ZCHAR *pcGrpChatId); 
                
/**
 * @brief MTC Cancel the geolocation information transfer.
 *
 * @param [in] iGInfoId The geolocation information id.
 */
ZFUNC ZINT Mtc_GsGInfoCancel(ZUINT iGInfoId);

/**
 * @brlef MTC Release the geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 */
ZFUNC ZVOID Mtc_GsGInfoRelease(ZUINT iGInfoId);

/**
 * @brief MTC Get user cookie in a geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval User cookie.
 */
ZFUNC ZCOOKIE Mtc_GsGInfoGetCookie(ZUINT iGInfoId);

/**
 * @brief MTC Set user cookie in a geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_GsGInfoSetCookie(ZUINT iGInfoId, ZCOOKIE zCookie);

/**
 * @brief MTC Get geolocation information type.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval Type of geolocation information, see @ref EN_MTC_GS_GINFO_TYPE.
 */
ZFUNC ZUINT Mtc_GsGInfoGetType(ZUINT iGInfoId);

/**
 * @brief MTC Get free text from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The free text.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetFreeText(ZUINT iGInfoId);

/**
 * @brief MTC Get latitude of user place from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The latitude of user place.
 */
ZFUNC ZDOUBLE Mtc_GsGInfoGetLatitude(ZUINT iGInfoId);

/**
 * @brief MTC Get longitude of user place from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The longitude of user place.
 */
ZFUNC ZDOUBLE Mtc_GsGInfoGetLongitude(ZUINT iGInfoId);

/**
 * @brief MTC Get radius of user place from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The radius of user place.
 */
ZFUNC ZFLOAT Mtc_GsGInfoGetRadius(ZUINT iGInfoId);

/**
 * @brief MTC Get participant type from the geolocation share.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval Type of im participant, see @ref EN_MTC_PARTP_LST_TYPE.
 *
 * If type is @ref EN_MTC_PARTP_LST_ONE, participant can be got by @ref Mtc_GsGInfoGetPartp.
 * If type is @ref EN_MTC_PARTP_LST_PREDEF_GRP, participant can be got by @ref Mtc_GsGInfoGetPartp.
 * If type is @ref EN_MTC_PARTP_LST_URI_LST, participant can be got by @ref Mtc_GsGInfoGetPartpLstId.
 */
ZFUNC ZUINT Mtc_GsGInfoGetPartpType(ZUINT iGInfoId);

/**
 * @brief MTC Get participant from the geolocation share.
 * Get receiver information from feion carbon copy geolocation share.
 *
 * @param [in] iGInfoId The geolocation information id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant uri.
 * The caller must copy them, then use.
 *
 * @retval ZOK Get paticipant information successfully.
 * @retval ZFAILED Get paticipant information failed.
 */
ZFUNC ZINT Mtc_GsGInfoGetPartp(ZUINT iGInfoId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get participant list id from the geolocation share.
 *
 * The participant list id is all remote clients who shared geolocation.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The participant list id.
 * The caller is responsible for freeing it by Mtc_PartpLstDelete
 */
ZFUNC ZUINT Mtc_GsGInfoGetPartpLstId(ZUINT iGInfoId);

/**
 * @brief MTC Get original participant which is the owner of geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant uri.
 * The caller must copy them, then use.
 *
 * @retval ZOK Get paticipant information successfully.
 * @retval ZFAILED Get paticipant information failed.
 */
ZFUNC ZINT Mtc_GsGInfoGetOrigPartp(ZUINT iGInfoId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get participant uri which is the owner of geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant uri.
 * The caller must copy them, then use.
 *
 * @retval ZOK Get paticipant information successfully.
 * @retval ZFAILED Get paticipant information failed.
 */
ZFUNC ZINT Mtc_GsGInfoGetOwnerPartp(ZUINT iGInfoId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get date time from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @return The date time(milliseconds).
 */
ZFUNC ZMTIME_T Mtc_GsGInfoGetDateTime(ZUINT iGInfoId);

/**
 * @brief MTC Get timestamp from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The timestamp.
 */
ZFUNC ZTIME_T Mtc_GsGInfoGetTimestamp(ZUINT iGInfoId);

/**
 * @brief MTC Get until time from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The until time.
 */
ZFUNC ZTIME_T Mtc_GsGInfoGetUntilTime(ZUINT iGInfoId);

/**
 * @brief MTC Get label flag from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZTRUE if it is a permanent location, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_GsGInfoHasLabel(ZUINT iGInfoId);

/**
 * @brief MTC Get label string from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The label string.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetLabel(ZUINT iGInfoId);

/**
 * @brief MTC Get file-transfer-id string from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval The file-transfer-id string.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetTrsfId(ZUINT iGInfoId);

/**
 * @brief MTC Get IsFocus flag from geolocation information id.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval return ZTRUE geolocation in group chat
 * @retval return ZFALSE geolocation in 1-1 chat.
 */
ZFUNC ZBOOL Mtc_GsGInfoGetIsFocus(ZUINT iGInfoId);

/**
 * @brief MTC  Get subject from geolocation information id.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval Geolocation Subject.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetSubject(ZUINT iGInfoId);

/**
 * @brief MTC Get group chat id from geolocation information id.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval Geolocation group chat id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetGrpChatId(ZUINT iGInfoId);

/**
 * @brief MTC Get the Imdn type from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information Id.
 *
 * @return Type of geolocation information, see @ref EN_MTC_GS_GINFO_IMDN_TYPE.
 */
ZFUNC ZUINT Mtc_GsGInfoGetImdnType(ZUINT iGInfoId);

/**
 * @brief MTC Get imdn message-id from geolocation information id.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval Geolocation imdn message-id.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetImdnMsgId(ZUINT iGInfoId);

/**
 * @brlef MTC Get device id from geolocation information session.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @return The device id.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetDeviceId(ZUINT iGInfoId);

/**
 * @brief MTC Get public message indication flag from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZTRUE if it has public message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_GsGInfoHasPubInd(ZUINT iGInfoId);

/**
 * @brief MTC Get spam indication flag from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZTRUE if it has spam message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_GsGInfoHasSpamInd(ZUINT iGInfoId);

/**
 * @brief MTC Get directional message indication flag from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZTRUE if it has directional message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_GsGInfoHasDirectInd(ZUINT iGInfoId);

/**
 * @brief MTC Get carbon copy message indication flag from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZTRUE if it has carbon copy message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_GsGInfoHasCcInd(ZUINT iGInfoId);

/**
 * @brief MTC Get silence message indication flag from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZTRUE if it has silence message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_GsGInfoHasSilenceInd(ZUINT iGInfoId);

/**
 * @brief MTC Get offline message indication flag from geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @retval ZTRUE if it has offline message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_GsGInfoHasOffInd(ZUINT iGInfoId);

/**
 * @brief MTC Get conversation-id of geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @return The conversation-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetConvId(ZUINT iGInfoId);

/**
 * @brief MTC Get contribution-id of geolocation information.
 *
 * @param [in] iGInfoId The geolocation information id.
 *
 * @return The contribution-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoGetContId(ZUINT iGInfoId);

/**
 * @brief RLE Save geolocation information data.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iGInfoType The geolocation information type, @see EN_MTC_GS_GINFO_TYPE.
 * @param [in] pcFreeText The free text.
 * @param [in] dLatitude The latitude of user place.
 * @param [in] dLongitude The longitude of user place.
 * @param [in] fRadius The radius of user place.
 * @param [in] pcUri The participant URI.
 * @param [in] pcLabel The label string, if ZNULL indicate user's own position, else other position.
 *
 * @return geolocation information data string.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_GsGInfoSaveData(ZCOOKIE zCookie, ZUINT iGInfoType, 
                ZCHAR *pcFreeText, ZDOUBLE dLatitude, ZDOUBLE dLongitude, 
                ZFLOAT fRadius, ZCHAR *pcUri, ZCHAR *pcLabel);

/**
 * @brief MGF Load geolocation information data.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcData The geolocation information data.
 *
 * @return geolocation information id successfully, otherwise return ZMAXUINT.
 *  When used completely, caller must release geolocation information, @see @ref Mtc_GsGInfoRelease.
 */
ZFUNC ZUINT Mtc_GsGInfoLoadData(ZCOOKIE zCookie, ZCHAR *pcUri, ZCHAR *pcData);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_GS_GINFO_H__ */


