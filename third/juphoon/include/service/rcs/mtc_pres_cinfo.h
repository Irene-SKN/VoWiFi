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
  File name     : mtc_pres_cinfo.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2013-03-12
  Description   :
      Function implement required by MTC OMA presence contact info.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PRES_CINFO_H__
#define _MTC_PRES_CINFO_H__

/**
 * @file mtc_pres_cinfo.h
 * @brief MTC Presence contact info Interface Functions
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Subscribe presence status of one contact info.
 * 
 * @param [in] pcUri The uri of contact.
 *
 * @return Contact info id start to subscribe presence successfully, 
 *    otherwise return ZMAXUINT failed.
 *
 * @see Mtc_PresCInfoUnSubs
 */
ZFUNC ZUINT Mtc_PresCInfoSubs(ZCHAR *pcUri);

/**
 * @brief Resubscribe presence status of one contact info.
 * 
 * @param [in] iCInfoId The id of contact info.
 *
 * @retval ZOK Resubscribe presence successfully.
 * @retval ZFAILED Resubscribe presence failed.
 *
 * @see Mtc_PresCInfoUnSubs
 */
ZFUNC ZINT Mtc_PresCInfoReSubs(ZUINT iCInfoId);

/**
 * @brief Stop subscribe presence status of one contact info.
 *
 * @param [in] iCInfoId The id of contact info.
 *
 * @retval ZOK Start to un-subscribe presence successfully.
 * @retval ZFAILED Stop subscribe presence failed.
 *
 * @see Mtc_PresCInfoSubs
 */
ZFUNC ZINT Mtc_PresCInfoUnSubs(ZUINT iCInfoId);

/**
 * @brief Find the contact info from contact uri.
 *
 * @param [in] pcUri The contact uri.
 *
 * @return Contact info id successfully, otherwise return ZMAXUINT failed. 
 */
ZFUNC ZUINT Mtc_PresCInfoFromUri(ZCHAR *pcUri);

/**
 * @brief Get the contact uri of contact info.
 *
 * @param [in] iCInfoId The id of contact info.
 *
 * @return Contact uri. 
 */
ZFUNC ZCHAR * Mtc_PresCInfoGetUri(ZUINT iCInfoId);

/**
 * @brief Get the presence subscription state of contact info.
 *
 * @param [in] iCInfoId The id of contact info.
 *
 * @return Presence subscription state, see EN_MTC_PRES_SUBS_STATE_TYPE. 
 */
ZFUNC ZUINT Mtc_PresCInfoGetSubState(ZUINT iCInfoId);

/**
 * @brief Get the presence subscription terminated reason of contact info.
 *
 * @param [in] iCInfoId The id of contact info.
 *
 * @return Presence subscription terminated reason, 
 * see @ref EN_MTC_PRES_SUBS_REASON_TYPE. 
 */
ZFUNC ZUINT Mtc_PresCInfoGetSubTermReason(ZUINT iCInfoId);

/**
 * @brief Get the presence status of contact info.
 *
 * @param [in] iCInfoId The id of contact info.
 *
 * @return Presence status, see EN_MTC_PRES_STAT_TYPE. 
 */
ZFUNC ZUINT Mtc_PresCInfoGetStatus(ZUINT iCInfoId);

/**
 * @brief Get the presence status-icon path of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval The icon path.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PresCInfoGetIconPath(ZUINT iCInfoId);

/**
 * @brief Get contact info status icon type.
 * 
 * @return The icon type, see @ref EN_MTC_PRES_ICON_TYPE.
 */
ZFUNC ZUINT Mtc_PresCInfoGetIconType(ZUINT iCInfoId);

/**
 * @brief Get the presence status-icon etag of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence icon etag.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PresCInfoGetIconEtag(ZUINT iCInfoId);

/**
 * @brief Get the presence status-icon data of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence icon path.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PresCInfoGetIconData(ZUINT iCInfoId);

/**
 * @brief Get the presence display name of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence display name.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PresCInfoGetDispName(ZUINT iCInfoId);

/**
 * @brief Get the presence note of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence note.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PresCInfoGetNote(ZUINT iCInfoId);

/**
 * @brief Get the presence home page of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence home page.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PresCInfoGetHomePage(ZUINT iCInfoId);

/**
 * @brief Get the presence geolocation information type of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 * 
 * @retval The presence geolocation information type, see @ref EN_MTC_PRES_GINFO_TYPE.
 *
 * @see Mtc_CInfoSetPresGInfoType
 */
ZFUNC ZUINT Mtc_PresCInfoGetGInfoType(ZUINT iCInfoId);

/**
 * @brief Get the free text from presence geolocation information of contact info.
 * 
 * @param [in] iCInfoId The contact info id.
 *
 * @retval The free text.
 *
 * @see Mtc_CInfoSetPresGInfoFreeText
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PresCInfoGetGInfoFreeText(ZUINT iCInfoId);

/**
 * @brief Get the latitude of user place from presence geolocation information of contact info.
 * 
 * @param [in] iCInfoId The contact info id.
 *
 * @retval The latitude of user place.
 *
 * @see Mtc_CInfoSetPresGInfoLatitude
 */
ZFUNC ZDOUBLE Mtc_PresCInfoGetGInfoLatitude(ZUINT iCInfoId);

/**
 * @brief Get the longitude of user place from presence geolocation information of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval The longitude of user place.
 *
 * @see Mtc_CInfoSetPresGInfoLongitude
 */
ZFUNC ZDOUBLE Mtc_PresCInfoGetGInfoLongitude(ZUINT iCInfoId);

/**
 * @brief Get the radius of user place from presence geolocation information of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval The radius of user place.
 *
 * @see Mtc_CInfoSetPresGInfoRadius
 */
ZFUNC ZFLOAT Mtc_PresCInfoGetGInfoRadius(ZUINT iCInfoId);

/**
 * @brief Get the timestamp from presence geolocation information of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval The timestamp.
 *
 * @see Mtc_CInfoSetPresGInfoTimestamp
 */
ZFUNC ZTIME_T Mtc_PresCInfoGetGInfoTimestamp(ZUINT iCInfoId);

/**
 * @brief Get the until time from presence geolocation information of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval The until time.
 *
 * @see Mtc_CInfoSetPresGInfoUntilTime
 */
ZFUNC ZTIME_T Mtc_PresCInfoGetGInfoUntilTime(ZUINT iCInfoId);

/**
 * @brief Get the the presence standalone message service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence standalone message support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvStandalMsg(ZUINT iCInfoId);

/**
 * @brief Get the the presence session mode messaging service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence session mode messaging support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvImSess(ZUINT iCInfoId);

/**
 * @brief Get the the presence full store and forward group chat service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence full store and forward group chat support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvStFwdGrpChat(ZUINT iCInfoId);

/**
 * @brief Get the the presence file transfer service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence file transfer support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvFileTrsf(ZUINT iCInfoId);

/**
 * @brief Get the the presence file transfer thumbnail service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence file transfer thumbnail support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvFtThumb(ZUINT iCInfoId);

/**
 * @brief Get the the presence file transfer store and forward service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence file transfer store and forward support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvFtStFwd(ZUINT iCInfoId);

/**
 * @brief Get the the presence file transfer via http service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence file transfer via http support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvFtViaHttp(ZUINT iCInfoId);

/**
 * @brief Get the the presence image share service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence image share support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvImgShare(ZUINT iCInfoId);

/**
 * @brief Get the the presence video share during a call service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence video share during a call support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvVsDuringCall(ZUINT iCInfoId);

/**
 * @brief Get the the presence video share outside of a voice call service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence video share outside of a voice call support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvVsOutCall(ZUINT iCInfoId);

/**
 * @brief Get the the presence social presence information service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence social presence information support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvSpi(ZUINT iCInfoId);

/**
 * @brief Get the the presence capability discovery via presence service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence capability discovery via presence support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvCapViaPres(ZUINT iCInfoId);

/**
 * @brief Get the the presence session mode voice call service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence session mode voice call support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvVoiceCall(ZUINT iCInfoId);

/**
 * @brief Get the the presence session mode video call service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence session mode video call support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvVideoCall(ZUINT iCInfoId);

/**
 * @brief Get the the presence geolocation pull service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence geolocation pull support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvGeoPull(ZUINT iCInfoId);

/**
 * @brief Get the the presence geolocation pull via file transfer service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence geolocation pull via file transfer support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvGeoPullViaFt(ZUINT iCInfoId);

/**
 * @brief Get the the presence geolocation push service of contact info.
 *
 * @param [in] iCInfoId The contact info id.
 *
 * @retval Contact info presence geolocation push support.
 */
ZFUNC ZBOOL Mtc_PresCInfoGetSrvGeoPush(ZUINT iCInfoId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PRES_CINFO_H__ */

