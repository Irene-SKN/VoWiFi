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
  File name     : mtc_im_grphttp.h
  Module        : multimedia talk client
  Author        : gloria.yang
  Created on    : 2018-05-14
  Description   :
      Data structure and function declare required by MTC IM group manage 
      via http.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_GRPMAN_HTTP_H__
#define _MTC_IM_GRPMAN_HTTP_H__

/**
 * @file mtc_im_grphttp.h
 * @brief MTC Instant Message Group Manage Via Http Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

#define MTC_GRPHTTP_SRC_RCS         "RCS"
#define MTC_GRPHTTP_SRC_MEETYOU     "MEETYOU"

/* MTC grphttp request type */
typedef enum EN_MTC_GRPHTTP_VALID_TYPE
{
    EN_MTC_GRPHTTP_VALID_ALL,            /* valid for all */
    EN_MTC_GRPHTTP_VALID_NONE,           /* valid for none  */
    EN_MTC_GRPHTTP_VALID_PERMIT,         /* valid for permit */
} EN_MTC_GRPHTTP_VALID_TYPE;

/**
 * @brief MTC Create group chat via http.
 *
 * If IM create a group successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpCreateOk.
 *
 * If IM create a group failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpCreateFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUserUri The controled user URI.
 * @param [in] pcSubject The subject of group.
 * @param [in] pcToken The auth token.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcSourceData The Source type data. 
 *
 * @return The group manage via http id, send create group invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpGrpCreate(ZCOOKIE zCookie, ZCHAR *pcUserUri, 
                ZCHAR *pcSubject, ZCHAR *pcBulletin, ZCHAR *pcToken,
                ZUINT iPartpLstId, ZCHAR *pcSourceData);

/**
 * @brief MTC Delete group chat via http.
 *
 * If IM delete a group successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpDeleteOk.
 *
 * If IM delete a group failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpDeleteFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpUri The group URI.
 * @param [in] pcUserUri The controled user URI. 
 * @param [in] pcToken The auth token.
 * @param [in] pcSourceData The Source type data. 
 *
 * @return The group manage via http id, send delete group invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpGrpDelete(ZCOOKIE zCookie, ZCHAR *pcGrpUri, 
                ZCHAR *pcUserUri, ZCHAR *pcToken, ZCHAR *pcSourceData);

/**
 * @brief MTC Subs group list via http.
 *
 * If IM subs group list successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpSubsLstOk.
 *
 * If IM subs group list failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpSubsLstFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUserUri The controled user URI. 
 * @param [in] pcToken The auth token.
 * @param [in] iGrpLstVer The group list veriosn, default 0.
 * @param [in] iGrpType The group type, @ref EN_MTC_GROUP_TYPE.
 * @param [in] pcSourceData The Source type data. 
 *
 * @return The group manage via http id, send subs group list invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpSubsGrpLst(ZCOOKIE zCookie, ZCHAR *pcUserUri, 
                ZCHAR *pcToken, ZUINT iGrpLstVer, ZUINT iGrpType, 
                ZCHAR *pcSourceData);

/**
 * @brief MTC Subs group information via http.
 *
 * If IM subs group information successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpSubsInfoOk.
 *
 * If IM subs group information failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpSubsInfoFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpUri The group URI.
 * @param [in] pcUserUri The controled user URI. 
 * @param [in] pcToken The auth token.
 * @param [in] iGrpVer The group version.
 * @param [in] pcSourceData The Source type data. 
 *
 * @return The group manage via http id, send subs group information invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpSubsGrpInfo(ZCOOKIE zCookie, ZCHAR *pcGrpUri, 
                ZCHAR *pcUserUri, ZCHAR *pcToken, ZUINT iGrpVer, 
                ZCHAR *pcSourceData);

/**
 * @brief MTC Modify subject via http.
 *
 * If IM modify subject successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpMdfySubjectOk.
 *
 * If IM modify subject failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpMdfySubjectFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpUri The group URI.
 * @param [in] pcUserUri The controled user URI. 
 * @param [in] pcNewSubject The new subject of group.
 * @param [in] pcToken The auth token.
 * @param [in] pcSourceData The Source type data. 
 *
 * @return The group manage via http id, send modify subject invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpMdfySubject(ZCOOKIE zCookie, ZCHAR *pcGrpUri, 
                ZCHAR *pcUserUri, ZCHAR *pcNewSubject, ZCHAR *pcToken, 
                ZCHAR *pcSourceData);

/**
 * @brief MTC Modify displayname via http.
 *
 * If IM modify displayname successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpMdfyDispNameOk.
 *
 * If IM modify displayname failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpMdfyDispNameFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpUri The group URI.
 * @param [in] pcUserUri The controled user URI.
 * @param [in] pcNewDispName The new displayname of ursr. 
 * @param [in] pcToken The auth token.
 * @param [in] pcSourceData The Source type data. 
 *
 * @return The group manage via http id, send modify displayname invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpMdfyDispName(ZCOOKIE zCookie, ZCHAR *pcGrpUri, 
                ZCHAR *pcUserUri, ZCHAR *pcNewDispName, ZCHAR *pcToken, 
                ZCHAR *pcSourceData);

/**
 * @brief MTC Modify chairman via http.
 *
 * If IM modify chairman successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpMdfyChairManOk.
 *
 * If IM modify chairman failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpMdfyChairManFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpUri The group URI.
 * @param [in] pcUserUri The controled user URI.
 * @param [in] pcNewChairManUri The new chairman URI. 
 * @param [in] pcToken The auth token.
 * @param [in] pcSourceData The Source type data. 
 *
 * @return The group manage via http id, send modify chairman invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpMdfyChairMan(ZCOOKIE zCookie, ZCHAR *pcGrpUri, 
                ZCHAR *pcUserUri, ZCHAR *pcNewChairManUri, ZCHAR *pcToken, 
                ZCHAR *pcSourceData);

/**
 * @brief MTC Add partp via http.
 *
 * If IM add partp successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpAddPartpOk.
 *
 * If IM add partp failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpAddPartpFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpUri The group URI.
 * @param [in] pcUserUri The controled user URI.
 * @param [in] pcToken The auth token.
 * @param [in] iPartpLstId The participant list id. 
 * @param [in] pcSourceData The Source type data. 
 *
 * @return The group manage via http id, send add partp invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpAddPartp(ZCOOKIE zCookie, ZCHAR *pcGrpUri, 
                ZCHAR *pcUserUri, ZCHAR *pcToken, ZUINT iPartpLstId, 
                ZCHAR *pcSourceData);

/**
 * @brief MTC Epl partp via http.
 *
 * If IM epl partp successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpEplPartpOk.
 *
 * If IM epl partp failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGrpHttpEplPartpFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpUri The group URI.
 * @param [in] pcUserUri The controled user URI.
 * @param [in] pcToken The auth token.
 * @param [in] pcPartpUri The partp uri to epl.
 * @param [in] pcSourceData The Source type data.
 *
 * @return The group manage via http id, send epl partp invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpEplPartp(ZCOOKIE zCookie, ZCHAR *pcGrpUri, 
                ZCHAR *pcUserUri, ZCHAR *pcToken, ZCHAR *pcPartpUri, 
                ZCHAR *pcSourceData);

/**
 * @brief MTC Join face to face group icon wall by command.
 *
 * If Join group chat successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGhJoinIconWallOk.
 *
 * If Join group chat failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGhJoinIconWallFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcToken The auth token.
 * @param [in] pcSourceData The Source Data. 
 * @param [in] dLongitude The longitude of user place. 
 * @param [in] dLatitude The latitude of user place. 
 * @param [in] iCmd The command number.
 *
 * @return The group manage via http id, send join face2face group iconwall 
 *             invitation successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpJoinIconWall(ZCOOKIE zCookie, ZCHAR *pcToken, 
                ZCHAR *pcSourceData, ZDOUBLE dLongitude, ZDOUBLE dLatitude, 
                ZUINT iCmd);

/**
 * @brief MTC Quit face to face group icon wall.
 *
 * If Quit group chat successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGhQuitIconWallOk.
 *
 * If Quit group chat failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGhQuitIconWallFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcToken The auth token.
 * @param [in] pcSourceData The Source Data. 
 * @param [in] dLongitude The longitude of user place. 
 * @param [in] dLatitude The latitude of user place. 
 * @param [in] iCmd The command number.
 * @param [in] pcCommandId The command id. 
 *
 * @return The group manage via http id, send quit face2face group iconwall 
 *              invitation successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpQuitIconWall(ZCOOKIE zCookie, ZCHAR *pcToken, 
                ZCHAR *pcSourceData, ZDOUBLE dLongitude, ZDOUBLE dLatitude, 
                ZUINT iCmd, ZCHAR *pcCommandId);

/**
 * @brief MTC Join face to face group.
 *
 * If Quit group chat successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGhJoinGrpOk.
 *
 * If Quit group chat failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetGhJoinGrpFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcToken The auth token.
 * @param [in] pcSourceData The Source Data. 
 * @param [in] dLongitude The longitude of user place. 
 * @param [in] dLatitude The latitude of user place. 
 * @param [in] iCmd The command number.
 * @param [in] pcCommandId The command id.
 *
 * @return The group manage via http id, send join face2face group invitation 
 *              successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImGrpHttpJoinGrp(ZCOOKIE zCookie, ZCHAR *pcToken, 
                ZCHAR *pcSourceData, ZDOUBLE dLongitude, ZDOUBLE dLatitude, 
                ZUINT iCmd, ZCHAR *pcCommandId);

/**
 * @brief MTC Cancel a group manage via http.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Cancel group manage via http successfully.
 * @retval ZFAILED Cancel group manage via http failed.
 */
ZFUNC ZINT Mtc_ImGrpHttpCancel(ZCOOKIE zCookie, ZUINT iGrpHttpId);

/**
 * @brief MTC Http group list get group list version.
 *
 * @param [in] iGrpHttpId The group manage via http id. 
 *
 * @return group list version.
 */
ZFUNC ZUINT Mtc_ImGrpHttpLstGetGrpLstVer(ZUINT iGrpHttpId);

/**
 * @brief MTC Http group list group size of list.
 *
 * @param [in] iGrpHttpId The group manage via http id. 
 *
 * @return group size of list.
 */
ZFUNC ZINT Mtc_ImGrpHttpLstGetGrpSize(ZUINT iGrpHttpId);

/**
 * @brief MTC Http group list get group id by index.
 *
 * @param [in] iGrpHttpId The group manage via http id. 
 * @param [in] iIndex The group index.
 *
 * @return group id successfully or ZMAXUINT failed.
 */
ZFUNC ZUINT Mtc_ImGrpHttpLstGetGrpId(ZUINT iGrpHttpId, ZUINT iIndex);

/**
 * @brief MTC Http group list get group URI.
 *
 * @param [in] iGrpId The group id.
 *
 * @return group URI.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpLstGetGrpUri(ZUINT iGrpId);

/**
 * @brief MTC Http group list get conversation id.
 *
 * @param [in] iGrpId The group id.
 *
 * @return conversation id.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpLstGetGrpConvId(ZUINT iGrpId);

/**
 * @brief MTC Http group list get subject.
 *
 * @param [in] iGrpId The group id.
 *
 * @return subject.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpLstGetGrpSubject(ZUINT iGrpId);

/**
 * @brief MTC Http group list get group type.
 *
 * @param [in] iGrpId The group id.
 *
 * @return group type @ref EN_MTC_GROUP_TYPE.
 */
ZFUNC ZUINT Mtc_ImGrpHttpLstGetGrpType(ZUINT iGrpId);

/* mtc group manage get user cookie. */

/**
 * @brief Get user cookie from grphttp.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImGrpHttpGetCookie(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get group version.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return group version.
 */
ZFUNC ZUINT Mtc_ImGrpHttpGetGrpVersion(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get subject.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return subject.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpGetSubject(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get group URI.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return group URI.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpGetGrpUri(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get max user count.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return max user count.
 */
ZFUNC ZUINT Mtc_ImGrpHttpGetMaxUsrCnt(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get bulletin.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return bulletin.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpGetBulletin(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get validtype.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return validtype @ref EN_MTC_GRPHTTP_VALID_TYPE.
 */
ZFUNC ZUINT Mtc_ImGrpHttpGetValidType(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get display name.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return display name.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpGetDispname(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get participant list id.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return participant list id.
 */
ZFUNC ZUINT Mtc_ImGrpHttpGetPartpLstId(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get creator URI.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return creator URI.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpGetCreatorUri(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get identifier.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return identifier.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpGetIdentifier(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get Timestamp(ms).
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return Timestamp.
 */
ZFUNC ZTIME_T Mtc_ImGrpHttpGetTimestamp(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get need permit.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return need permit.
 */
ZFUNC ZBOOL Mtc_ImGrpHttpGetNeedPermit(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get group type.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return group type @ref EN_MTC_GROUP_TYPE.
 */
ZFUNC ZUINT Mtc_ImGrpHttpGetGrpType(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get conversation Id.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return conversation Id.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpGetConvId(ZUINT iGrpHttpId);

/**
 * @brief MTC Get latitude of user place.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @retval The latitude of user place.
 */
ZFUNC ZDOUBLE Mtc_ImGrpHttpGetLatitude(ZUINT iGrpHttpId);

/**
 * @brief MTC Get longitude of user place.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @retval The longitude of user place.
 */
ZFUNC ZDOUBLE Mtc_ImGrpHttpGetLongitude(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get command.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return command.
 */
ZFUNC ZUINT Mtc_ImGrpHttpGetCommand(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get command Id.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return command Id.
 */
ZFUNC ZCHAR * Mtc_ImGrpHttpGetCommandId(ZUINT iGrpHttpId);

/**
 * @brief MTC Group manage get validate-time of command.
 *
 * @param [in] iGrpHttpId The group manage via http id.
 *
 * @return validate-time of command.
 */
ZFUNC ZTIME_T Mtc_ImGrpHttpGetValidTime(ZUINT iGrpHttpId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_GRPMAN_HTTP_H__ */
