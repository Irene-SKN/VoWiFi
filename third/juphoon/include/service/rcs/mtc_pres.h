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
  File name     : mtc_pres.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by MTC OMA Presence.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PRES_H__
#define _MTC_PRES_H__

/**
 * @file mtc_pres.h
 * @brief MTC Presence Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC presence(subscribe/publish) status code. */
#define MTC_PRES_ERR_NO               (MTC_EBASE_PRES + 0) /**< @brief no error. */
#define MTC_PRES_ERR_AUTH_FAILED      (MTC_EBASE_PRES + 1) /**< @brief authentication failed, invalid user or password. */
#define MTC_PRES_ERR_FORBIDDEN        (MTC_EBASE_PRES + 2) /**< @brief subscribe/publish forbidden. */
#define MTC_PRES_ERR_NOT_FOUND        (MTC_EBASE_PRES + 3) /**< @brief presence participant not found. */
#define MTC_PRES_ERR_NOT_ACPTED       (MTC_EBASE_PRES + 4) /**< @brief im not accepted. */
#define MTC_PRES_ERR_TEMP_UNAVAIL     (MTC_EBASE_PRES + 5) /**< @brief im participant temp unavailable. */
#define MTC_PRES_ERR_REQ_TERMED       (MTC_EBASE_PRES + 6) /**< @brief im request terminated. */
#define MTC_PRES_ERR_INTERNAL_ERR     (MTC_EBASE_PRES + 7) /**< @brief server internal error. */
#define MTC_PRES_ERR_SRV_UNAVAIL      (MTC_EBASE_PRES + 8) /**< @brief service unavailable. */
#define MTC_PRES_ERR_OTHER            (MTC_EBASE_PRES + 9) /**< @brief other error. */

/** @brief MTC OMA presence status code. */
#define MTC_PRES_OMA_ERR_NO           (MTC_EBASE_PRES + 20) /**< @brief no error */
#define MTC_PRES_OMA_ERR_AUTH_FAILED  (MTC_EBASE_PRES + 21) /**< @brief authentication failed, invalid user or password */
#define MTC_PRES_OMA_ERR_CONN_FAILED  (MTC_EBASE_PRES + 22) /**< @brief transport connect failed */
#define MTC_PRES_OMA_ERR_SEND_FAILED  (MTC_EBASE_PRES + 23) /**< @brief transport send failed */
#define MTC_PRES_OMA_ERR_SERV_DISCED  (MTC_EBASE_PRES + 24) /**< @brief transport disconnected by server */
#define MTC_PRES_OMA_ERR_SERV_ERR     (MTC_EBASE_PRES + 25) /**< @brief server internal error */
#define MTC_PRES_OMA_ERR_REQ_TIMEOUT  (MTC_EBASE_PRES + 26) /**< @brief request timeout */
#define MTC_PRES_OMA_ERR_BAD_XML_MSG  (MTC_EBASE_PRES + 27) /**< @brief bad xml message */
#define MTC_PRES_OMA_ERR_REPEATED     (MTC_EBASE_PRES + 28) /**< @brief element repeated */
#define MTC_PRES_OMA_ERR_NOT_FOUND    (MTC_EBASE_PRES + 29) /**< @brief not found */

/** @brief MTC presence callback synchronize type */
typedef enum MTC_PRES_CB_SYNC_TYPE
{
    MTC_PRES_CB_SYNC_ADDED,                /**< @brief added */
    MTC_PRES_CB_SYNC_REMOVED,              /**< @brief removed */
    MTC_PRES_CB_SYNC_UPDATED               /**< @brief updated */
} MTC_PRES_CB_SYNC_TYPE;

/** @brief MTC presence status type */
typedef enum EN_MTC_PRES_STAT_TYPE
{
    EN_MTC_PRES_STAT_ONLINE,         /**< @brief online status */
    EN_MTC_PRES_STAT_BUSY,           /**< @brief busy status */
    EN_MTC_PRES_STAT_AWAY,           /**< @brief away status */
    EN_MTC_PRES_STAT_CALLING,        /**< @brief calling(on-the-phone) status */
    EN_MTC_PRES_STAT_OFFLINE         /**< @brief offline status */
} EN_MTC_PRES_STAT_TYPE;

/** @brief MTC presence subscription state */
typedef enum EN_MTC_PRES_SUBS_STATE_TYPE
{
    EN_MTC_PRES_SUBS_STATE_ACTIVE,   /**< @brief active state */
    EN_MTC_PRES_SUBS_STATE_PEND,     /**< @brief pending state */
    EN_MTC_PRES_SUBS_STATE_TERM      /**< @brief terminated state */
} EN_MTC_PRES_SUBS_STATE_TYPE;

/** @brief MTC presence subscription reason type */
typedef enum EN_MTC_PRES_SUBS_REASON_TYPE
{
    EN_MTC_PRES_SUBS_REASON_DEACTIVE, /**< @brief deactivated status */
    EN_MTC_PRES_SUBS_REASON_PROBATION, /**< @brief probation status */
    EN_MTC_PRES_SUBS_REASON_REJECT,  /**< @brief rejected status */
    EN_MTC_PRES_SUBS_REASON_TIMEOUT, /**< @brief timeout status */
    EN_MTC_PRES_SUBS_REASON_GIVEUP,  /**< @brief giveup status */
    EN_MTC_PRES_SUBS_REASON_NORES    /**< @brief noresource status */
} EN_MTC_PRES_SUBS_REASON_TYPE;

/** @brief MTC geolocation information type */
typedef enum EN_MTC_PRES_GINFO_TYPE
{
    EN_MTC_PRES_GINFO_NONE = 0,/**< @brief geolocation information none */
    EN_MTC_PRES_GINFO_FREE_TEXT = 1,/**< @brief geolocation information free text */
    EN_MTC_PRES_GINFO_2D_CIRCLE = 2,/**< @brief geolocation information circle */
    EN_MTC_PRES_GINFO_BOTH = 3,/**< @brief geolocation information both */
} EN_MTC_PRES_GINFO_TYPE;

/**
 * @brief Publish presence status.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetPubStatusOk or @ref Mtc_PresCbSetPubStatusFailed.
 *
 * Note: Before publish presence status, user MUST load presence permanent state
 * successfully(@ref Mtc_PresPermLoad), if no permanent document, 
 * please set permanent information before upload it(@ref Mtc_PresPermUpload).
 *
 * User MUST load presence status icon document successfully(@ref Mtc_PresPermLoadIcon),
 * if no icon document, set icon data and upload it(@ref Mtc_PresPermUploadIcon).
 *
 * GUI should set information @ref Mtc_PresSetStatus, @ref Mtc_PresSetSrvImSess,
 * @ref Mtc_PresSetSrvFileTrsf, @ref Mtc_PresSetSrvImgShare 
 * before publish status.
 *
 * @retval ZOK Start to publish presence status successfully.
 * @retval ZFAILED Publish presence status failed.
 *
 * @see @ref Mtc_PresUnPubStatus
 */
ZFUNC ZINT Mtc_PresPubStatus(ZFUNC_VOID);

/**
 * @brief Stop publish presence status.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetUnPubStatusOk or @ref Mtc_PresCbSetUnPubStatusFailed.
 *
 * @retval ZOK Start to un-publish presence successfully.
 * @retval ZFAILED Stop publish presence failed.
 *
 * @see @ref Mtc_PresPubStatus
 */
ZFUNC ZINT Mtc_PresUnPubStatus(ZFUNC_VOID);

/**
 * @brief Publish poc-settings.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetPubPocSetsOk or @ref Mtc_PresCbSetPubPocSetsFailed.
 *
 * @retval ZOK Start to publish poc-settings successfully.
 * @retval ZFAILED Publish poc-settings failed.
 *
 * @see @ref Mtc_PresUnPubPocSets
 */
ZFUNC ZINT Mtc_PresPubPocSets(ZFUNC_VOID);

/**
 * @brief Stop publish poc-settings.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetUnPubPocSetsOk or @ref Mtc_PresCbSetUnPubPocSetsFailed.
 *
 * @retval ZOK Start to un-publish poc-settings successfully.
 * @retval ZFAILED Stop publish poc-settings failed.
 *
 * @see @ref Mtc_PresPubPocSets
 */
ZFUNC ZINT Mtc_PresUnPubPocSets(ZFUNC_VOID);

/**
 * @brief Subscribe presence status for each buddy in buddy list.
 *  
 * @param [in] iBuddyId The buddy id.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetSubsBuddyOk or @ref Mtc_PresCbSetSubsBuddyFailed.
 *
 * Note: Before subscribe presence, user MUST load buddy successfully(@ref Mtc_BuddysLoad),
 * and MUST load RLS-Service document successfully(@ref Mtc_PresSrvsLoad),
 * and MUST load Pres-Rules document successfully(@ref Mtc_PresRulesLoad).
 *
 * @retval ZOK Start to subscribe presence successfully.
 * @retval ZFAILED Subscribe presence failed.
 *
 * @see @ref Mtc_PresUnSubsBuddy
 */
ZFUNC ZINT Mtc_PresSubsBuddy(ZUINT iBuddyId);

/**
 * @brief Stop subscribe presence status for each buddy in buddy list.
 *  
 * @param [in] iBuddyId The buddy id.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetUnSubsBuddyOk or @ref Mtc_PresCbSetUnSubsBuddyFailed.
 *
 * @retval ZOK Start to subscribe presence successfully.
 * @retval ZFAILED Subscribe presence failed.
 *
 * @see @ref Mtc_PresSubsBuddy
 */
ZFUNC ZINT Mtc_PresUnSubsBuddy(ZUINT iBuddyId);

/**
 * @brief Subscribe presence status of buddy list.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetSubsBuddyLstOk or @ref Mtc_PresCbSetSubsBuddyLstFailed.
 *
 * Note: Before subscribe presence, user MUST load buddy successfully(@ref Mtc_BuddysLoad),
 * and MUST load RLS-Service document successfully(@ref Mtc_PresSrvsLoad),
 * and MUST load Pres-Rules document successfully(@ref Mtc_PresRulesLoad).
 *
 * @retval ZOK Start to subscribe presence successfully.
 * @retval ZFAILED Subscribe presence failed.
 *
 * @see @ref Mtc_PresUnSubsBuddyLst
 */
ZFUNC ZINT Mtc_PresSubsBuddyLst(ZFUNC_VOID);

/**
 * @brief Stop subscribe presence status of buddy list.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetUnSubsBuddyLstOk or @ref Mtc_PresCbSetUnSubsBuddyLstFailed.
 *
 * @retval ZOK Start to un-subscribe presence successfully.
 * @retval ZFAILED Stop subscribe presence failed.
 *
 * @see @ref Mtc_PresSubsBuddyLst
 */
ZFUNC ZINT Mtc_PresUnSubsBuddyLst(ZFUNC_VOID);

/**
 * @brief Get presence status.
 * 
 * @return The presence status, see @ref EN_MTC_PRES_STAT_TYPE.
 *
 * @see @ref Mtc_PresSetStatus
 */
ZFUNC ZUINT Mtc_PresGetStatus(ZFUNC_VOID);

/**
 * @brief Set presence status.
 * 
 * @param [in] iStatType The presence status, see @ref EN_MTC_PRES_STAT_TYPE.
 *
 * @retval ZOK Set presence status successfully.
 * @retval ZFAILED Set presence status failed.
 *
 * @see @ref Mtc_PresGetStatus
 */
ZFUNC ZINT Mtc_PresSetStatus(ZUINT iStatType);

/**
 * @brief Get presence geolocation information type.
 * 
 * @retval The presence geolocation information type, see @ref EN_MTC_PRES_GINFO_TYPE.
 *
 * @see Mtc_PresSetGInfoType
 */
ZFUNC ZUINT Mtc_PresGetGInfoType(ZFUNC_VOID);

/**
 * @brief Set presence geolocation information type.
 * 
 * @param [in] iGInfoType The presence geolocation information type, 
 *                  see @ref EN_MTC_PRES_GINFO_TYPE.
 *
 * @retval ZOK Set geolocation information type successfully.
 * @retval ZFAILED Set geolocation information type failed.
 *
 * @see Mtc_PresGetGInfoType
 */
ZFUNC ZINT Mtc_PresSetGInfoType(ZUINT iGInfoType);

/**
 * @brief Get free text from presence geolocation information.
 *
 * @retval The free text.
 *
 * @see Mtc_PresSetGInfoFreeText
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PresGetGInfoFreeText(ZFUNC_VOID);

/**
 * @brief Set free text into presence geolocation information.
 *
 * @param [in] pcFreeText The geolocation information free text.
 *
 * @retval ZOK Set free text successfully.
 * @retval ZFAILED Set free text failed.
 *
 * @see Mtc_PresGetGInfoFreeText
 */
ZFUNC ZINT Mtc_PresSetGInfoFreeText(ZCHAR *pcFreeText);

/**
 * @brief  Get latitude of user place from presence geolocation information.
 *
 * @retval The latitude of user place.
 *
 * @see Mtc_PresSetGInfoLatitude
 */
ZFUNC ZDOUBLE Mtc_PresGetGInfoLatitude(ZFUNC_VOID);

/**
 * @brief Set latitude of user place into presence geolocation information.
 *
 * @param [in] dLatitude The geolocation information latitude.
 *
 * @retval ZOK Set latitude successfully.
 * @retval ZFAILED Set latitude failed.
 *
 * @see Mtc_PresGetGInfoLatitude
 */
ZFUNC ZINT Mtc_PresSetGInfoLatitude(ZDOUBLE dLatitude);

/**
 * @brief Get longitude of user place from presence geolocation information.
 *
 * @retval The longitude of user place.
 *
 * @see Mtc_PresSetGInfoLongitude
 */
ZFUNC ZDOUBLE Mtc_PresGetGInfoLongitude(ZFUNC_VOID);

/**
 * @brief Set longitude of user place into presence geolocation information.
 *
 * @param [in] dLongitude The geolocation information longitude.
 *
 * @retval ZOK Set longitude successfully.
 * @retval ZFAILED Set longitude failed.
 *
 * @see Mtc_PresGetGInfoLongitude
 */
ZFUNC ZINT Mtc_PresSetGInfoLongitude(ZDOUBLE dLongitude);

/**
 * @brief Get radius of user place from presence geolocation information.
 *
 * @retval The radius of user place.
 *
 * @see Mtc_PresSetGInfoRadius
 */
ZFUNC ZFLOAT Mtc_PresGetGInfoRadius(ZFUNC_VOID);

/**
 * @brief Set radius of user place into presence geolocation information.
 *
 * @param [in] fRadius The geolocation information radius.
 *
 * @retval ZOK Set radius successfully.
 * @retval ZFAILED Set radius failed.
 *
 * @see Mtc_PresGetGInfoRadius
 */
ZFUNC ZINT Mtc_PresSetGInfoRadius(ZFLOAT fRadius);

/**
 * @brief Get timestamp from presence geolocation information.
 *
 * @retval The timestamp.
 *
 * @see Mtc_PresSetGInfoTimestamp
 */
ZFUNC ZTIME_T Mtc_PresGetGInfoTimestamp(ZFUNC_VOID);

/**
 * @brief Set timestamp into presence geolocation information.
 *
 * @param [in] zTimestamp The geolocation information timestamp.
 *
 * @retval ZOK Set timestamp successfully.
 * @retval ZFAILED Set timestamp failed.
 *
 * @see Mtc_PresGetGInfoTimestamp
 */
ZFUNC ZINT Mtc_PresSetGInfoTimestamp(ZTIME_T zTimestamp);

/**
 * @brief Get until time from presence geolocation information.
 *
 * @retval The until time.
 *
 * @see Mtc_PresSetGInfoUntilTime
 */
ZFUNC ZTIME_T Mtc_PresGetGInfoUntilTime(ZFUNC_VOID);

/**
 * @brief Set until time into presence geolocation information.
 *
 * @param [in] zUntilTime The geolocation information until time.
 *
 * @retval ZOK Set until time successfully.
 * @retval ZFAILED Set until time failed.
 *
 * @see Mtc_PresGetGInfoUntilTime
 */
ZFUNC ZINT Mtc_PresSetGInfoUntilTime(ZTIME_T zUntilTime);

/**
 * @brief Get the presence standalone message service.
 *
 * @retval Client presence standalone message support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvStandalMsg(ZFUNC_VOID);

/**
 * @brief Set the presence standalone message service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvStandalMsg(ZBOOL bSupt);

/**
 * @brief Get the presence session mode messaging service.
 *
 * @retval Client presence session mode messaging support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvImSess(ZFUNC_VOID);

/**
 * @brief Set the presence session mode messaging service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvImSess(ZBOOL bSupt);

/**
 * @brief Get the presence full store and forward group chat service.
 *
 * @retval Client presence full store and forward group chat support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvStFwdGrpChat(ZFUNC_VOID);

/**
 * @brief Set the presence full store and forward group chat service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvStFwdGrpChat(ZBOOL bSupt);

/**
 * @brief Get the presence file transfer service.
 *
 * @retval Client presence file transfer support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvFileTrsf(ZFUNC_VOID);

/**
 * @brief Set the presence file transfer service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvFileTrsf(ZBOOL bSupt);

/**
 * @brief Get the presence file transfer thumbnail service.
 *
 * @retval Client presence file transfer thumbnail support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvFtThumb(ZFUNC_VOID);

/**
 * @brief Set the presence file transfer thumbnail service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvFtThumb(ZBOOL bSupt);

/**
 * @brief Get the presence file transfer store and forward service.
 *
 * @retval Client presence file transfer store and forward support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvFtStFwd(ZFUNC_VOID);

/**
 * @brief Set the presence file transfer store and forward service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvFtStFwd(ZBOOL bSupt);

/**
 * @brief Get the presence file transfer via http service.
 *
 * @retval Client presence file transfer via http support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvFtViaHttp(ZFUNC_VOID);

/**
 * @brief Set the presence file transfer via http service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvFtViaHttp(ZBOOL bSupt);

/**
 * @brief Get the presence image share service.
 *
 * @retval Client presence image share support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvImgShare(ZFUNC_VOID);

/**
 * @brief Set the presence image share service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvImgShare(ZBOOL bSupt);

/**
 * @brief Get the presence video share during a call service.
 *
 * @retval Client presence video share during a call support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvVsDuringCall(ZFUNC_VOID);

/**
 * @brief Set the presence video share during a call service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvVsDuringCall(ZBOOL bSupt);

/**
 * @brief Get the presence video share outside of a voice call service.
 *
 * @retval Client presence video share outside of a voice call support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvVsOutCall(ZFUNC_VOID);

/**
 * @brief Set the presence video share outside of a voice call service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvVsOutCall(ZBOOL bSupt);

/**
 * @brief Get the presence social presence information service.
 *
 * @retval Client presence social presence information support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvSpi(ZFUNC_VOID);

/**
 * @brief Set the presence social presence information service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvSpi(ZBOOL bSupt);

/**
 * @brief Get the presence capability discovery via presence service.
 *
 * @retval Client presence capability discovery via presence support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvCapViaPres(ZFUNC_VOID);

/**
 * @brief Set the presence capability discovery via presence service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvCapViaPres(ZBOOL bSupt);

/**
 * @brief Get the presence session mode voice call service.
 *
 * @retval Client presence session mode voice call support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvVoiceCall(ZFUNC_VOID);

/**
 * @brief Set the presence session mode voice call service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvVoiceCall(ZBOOL bSupt);

/**
 * @brief Get the presence session mode video call service.
 *
 * @retval Client presence session mode video call support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvVideoCall(ZFUNC_VOID);

/**
 * @brief Set the presence session mode video call service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvVideoCall(ZBOOL bSupt);

/**
 * @brief Get the presence geolocation pull service.
 *
 * @retval Client presence geolocation pull support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvGeoPull(ZFUNC_VOID);

/**
 * @brief Set the presence geolocation pull service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvGeoPull(ZBOOL bSupt);

/**
 * @brief Get the presence geolocation pull via file tranfer service.
 *
 * @retval Client presence geolocation pull via file tranfer support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvGeoPullViaFt(ZFUNC_VOID);

/**
 * @brief Set the presence geolocation pull via file tranfer service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvGeoPullViaFt(ZBOOL bSupt);

/**
 * @brief Get the presence geolocation push service.
 *
 * @retval Client presence geolocation push support.
 */
ZFUNC ZBOOL Mtc_PresGetSrvGeoPush(ZFUNC_VOID);

/**
 * @brief Set the presence geolocation push service.
 *
 * @param [in] bSupt The service support flag.
 *
 * @retval ZOK Set service support flag successfully.
 * @retval ZFAILED Set service support flag failed.
 */
ZFUNC ZINT Mtc_PresSetSrvGeoPush(ZBOOL bSupt);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PRES_H__ */

