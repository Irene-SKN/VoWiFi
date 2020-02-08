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
  File name     : mtc_buddy.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by mtc oma buddy.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_BUDDY_H__
#define _MTC_BUDDY_H__

/**
 * @file mtc_buddy.h
 * @brief MTC OMA Buddy Interface Functions
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC OMA buddy status code. */
#define MTC_BUDDY_ERR_NO               (MTC_EBASE_BUDDY + 0) /**< @brief no error */
#define MTC_BUDDY_ERR_AUTH_FAILED      (MTC_EBASE_BUDDY + 1) /**< @brief authentication failed, invalid user or password */
#define MTC_BUDDY_ERR_CONN_FAILED      (MTC_EBASE_BUDDY + 2) /**< @brief transport connect failed */
#define MTC_BUDDY_ERR_SEND_FAILED      (MTC_EBASE_BUDDY + 3) /**< @brief transport send failed */
#define MTC_BUDDY_ERR_SERV_DISCED      (MTC_EBASE_BUDDY + 4) /**< @brief transport disconnected by server */
#define MTC_BUDDY_ERR_SERV_ERR         (MTC_EBASE_BUDDY + 5) /**< @brief server internal error */
#define MTC_BUDDY_ERR_REQ_TIMEOUT      (MTC_EBASE_BUDDY + 6) /**< @brief request timeout */
#define MTC_BUDDY_ERR_BAD_XML_MSG      (MTC_EBASE_BUDDY + 7) /**< @brief bad xml message */
#define MTC_BUDDY_ERR_REPEATED         (MTC_EBASE_BUDDY + 8) /**< @brief element repeated */
#define MTC_BUDDY_ERR_NOT_FOUND        (MTC_EBASE_BUDDY + 9) /**< @brief not found */
#define MTC_BUDDY_ERR_OTHER            (MTC_EBASE_BUDDY + 10) /**< @brief other error */

/** @brief MTC buddy group type */
typedef enum EN_MTC_BUDDY_GRP_TYPE
{
    EN_MTC_BUDDY_GRP_UNKNOWN,           /**< @brief unknown group */
    EN_MTC_BUDDY_GRP_RCS,               /**< @brief rcs group */
    EN_MTC_BUDDY_GRP_RCS_SPI_ONLY,      /**< @brief rcs spi only group */
    EN_MTC_BUDDY_GRP_RCS_POLL,          /**< @brief rcs poll group */
    EN_MTC_BUDDY_GRP_RCS_POLL_SPI_ONLY, /**< @brief rcs poll spi only group */
} EN_MTC_BUDDY_GRP_TYPE;

/** @brief MTC buddy status */
typedef enum EN_MTC_BUDDY_STAT_TYPE
{
    EN_MTC_BUDDY_STAT_ONLINE,           /**< @brief online status */
    EN_MTC_BUDDY_STAT_BUSY,             /**< @brief busy status */
    EN_MTC_BUDDY_STAT_AWAY,             /**< @brief away status */
    EN_MTC_BUDDY_STAT_OFFLINE           /**< @brief offline status */
} EN_MTC_BUDDY_STAT_TYPE;

/** @brief MTC buddy callback synchronize type */
typedef enum MTC_BUDDY_CB_SYNC_TYPE
{
    MTC_BUDDY_CB_SYNC_ADDED,                /**< @brief added */
    MTC_BUDDY_CB_SYNC_REMOVED,              /**< @brief removed */
    MTC_BUDDY_CB_SYNC_UPDATED               /**< @brief updated */
} MTC_BUDDY_CB_SYNC_TYPE;

/**
 * @brief Load buddy set from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetAllLoadOk or @ref Mtc_BuddyCbSetAllLoadFailed.
 *
 * @retval ZOK Start loading buddy set successfully.
 * @retval ZFAILED Client loading buddy set failed.
 */
ZFUNC ZINT Mtc_BuddysLoadAll(ZFUNC_VOID);

/**
 * @brief Upload buddy set into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetAllUploadOk or @ref Mtc_BuddyCbSetAllUploadFailed.
 *
 * @retval ZOK Start uploading buddy set successfully.
 * @retval ZFAILED Client upload buddy set failed.
 */
ZFUNC ZINT Mtc_BuddysUploadAll(ZFUNC_VOID);

/**
 * @brief Load buddy set of group from OMA XDMS.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * 
 * @retval ZOK Start loading buddy set successfully.
 * @retval ZFAILED Client Load buddy set failed.
 */
ZFUNC ZINT Mtc_BuddysLoad(ZUINT iGrpType);

/**
 * @brief Upload buddy set into OMA XDMS.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * 
 * @retval ZOK Start loading buddy set successfully.
 * @retval ZFAILED Client Load buddy set failed.
 */
ZFUNC ZINT Mtc_BuddysUpload(ZUINT iGrpType);

/**
 * @brief Get OMA buddy child group size.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 *
 * @return Buddy set size.
 *
 * @see @ref Mtc_BuddysGetGrp
 */
ZFUNC ZUINT Mtc_BuddysGetGrpSize(ZUINT iGrpType);

/**
 * @brief Get One buddy child group by index.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * @param [in] iIndex The index of buddy child group.
 *
 * @return The id of buddy.
 *
 * @see @ref Mtc_BuddysGetGrpSize
 */
ZFUNC ZUINT Mtc_BuddysGetGrp(ZUINT iGrpType, ZINT iIndex);

/**
 * @brief Add One buddy child group and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetGrpAddOk or @ref Mtc_BuddyCbSetGrpAddFailed.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * @param [in] zCookie The user cookie.
 * @param [in] pcName The child group name.
 * @param [in] pcDispName The group display name.
 *
 * @return The id of group when add group successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_BuddysRmvGrp
 */
ZFUNC ZUINT Mtc_BuddysAddGrp(ZUINT iGrpType, ZCOOKIE zCookie, 
                ZCHAR *pcName, ZCHAR *pcDispName); 

/**
 * @brief Rmove One buddy child group and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetGrpRmvOk or @ref Mtc_BuddyCbSetGrpRmvFailed.
 *
 * @param [in] iGrpId The group id.
 *
 * @retval ZOK Remove one group successfully.
 * @retval ZFAILED Remove one group failed.
 *
 * @see @ref Mtc_BuddysAddGrp
 */
ZFUNC ZINT Mtc_BuddysRmvGrp(ZUINT iGrpId); 

/**
 * @brief Rmove One buddy child group and in local cache.
 *
 * @param [in] iGrpId The group id.
 *
 * @retval ZOK Remove one group successfully.
 * @retval ZFAILED Remove one group failed.
 *
 * @see @ref Mtc_BuddysAddGrp
 */
ZFUNC ZINT Mtc_BuddysRmvGrpL(ZUINT iGrpId); 

/**
 * @brief Find One child group by name.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * @param [in] pcName The group name.
 *
 * @return One group Id.
 *
 * @see @ref Mtc_BuddysRmvGrpL
 */
ZFUNC ZUINT Mtc_BuddysFindGrp(ZUINT iGrpType, ZCHAR *pcName);

/**
 * @brief Get OMA buddy set size.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 *
 * @return Buddy set size.
 *
 * @see @ref Mtc_BuddysGetBuddy
 */
ZFUNC ZUINT Mtc_BuddysGetBuddySize(ZUINT iGrpType);

/**
 * @brief Get One buddy by index.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * @param [in] iIndex The index of buddy.
 *
 * @return One buddy Id.
 *
 * @see @ref Mtc_BuddysGetBuddySize
 */
ZFUNC ZUINT Mtc_BuddysGetBuddy(ZUINT iGrpType, ZINT iIndex);

/**
 * @brief Add one buddy by URI into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBuddyAddOk or @ref Mtc_BuddyCbSetBuddyAddFailed.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The display name of buddy.
 * @param [in] pcUri The URI of buddy.
 *
 * @return The id of buddy when add one buddy successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_BuddysRmvBuddy
 */
ZFUNC ZUINT Mtc_BuddysAddBuddy(ZUINT iGrpType, ZCOOKIE zCookie, 
                ZCHAR *pcDispName, ZCHAR *pcUri);

/**
 * @brief Add one buddy by URI in local cache.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The display name of buddy.
 * @param [in] pcUri The URI of buddy.
 *
 * @return The id of buddy when add one buddy successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_BuddysRmvBuddyL
 */
ZFUNC ZUINT Mtc_BuddysAddBuddyL(ZUINT iGrpType, ZCOOKIE zCookie, 
                ZCHAR *pcDispName, ZCHAR *pcUri);

/**
 * @brief Remove one buddy from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBuddyRmvOk or @ref Mtc_BuddyCbSetBuddyRmvFailed.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @retval ZOK Start to remove one buddy successfully.
 * @retval ZFAILED Start to remove one buddy failed.
 *
 * @see @ref Mtc_BuddysAddBuddy
 */
ZFUNC ZINT Mtc_BuddysRmvBuddy(ZUINT iBuddyId);

/**
 * @brief Remove one buddy in local cache.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @retval ZOK Start to remove one buddy successfully.
 * @retval ZFAILED Start to remove one buddy failed.
 *
 * @see @ref Mtc_BuddysAddBuddyL
 */
ZFUNC ZINT Mtc_BuddysRmvBuddyL(ZUINT iBuddyId);

/**
 * @brief Find One buddy by URI from root group.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * @param [in] pcUri The buddy URI.
 *
 * @return One buddy Id.
 *
 * @see @ref Mtc_BuddysSearchBuddy
 */
ZFUNC ZUINT Mtc_BuddysFindBuddy(ZUINT iGrpType, ZCHAR *pcUri);

/**
 * @brief Find One buddy by URI from root and children groups.
 *
 * @param [in] iGrpType The type of group, @see @ref EN_MTC_BUDDY_GRP_TYPE.
 * @param [in] pcUri The buddy URI.
 *
 * @return One buddy Id.
 *
 * @see @ref Mtc_BuddysFindBuddy
 */
ZFUNC ZUINT Mtc_BuddysSearchBuddy(ZUINT iGrpType, ZCHAR *pcUri);

/**
 * @brief Get OMA sub-group size from one group.
 *
 * @param [in] iGrpId The group id.
 *
 * @return Sub-group size.
 *
 * @see @ref Mtc_BuddyGrpGetGrp
 */
ZFUNC ZUINT Mtc_BuddyGrpGetGrpSize(ZUINT iGrpId);

/**
 * @brief Get One sub-group by index.
 *
 * @param [in] iGrpId The group id.
 * @param [in] iIndex The index of group.
 *
 * @return One Buddy group Id.
 *
 * @see @ref Mtc_BuddyGrpGetGrpSize
 */
ZFUNC ZUINT Mtc_BuddyGrpGetGrp(ZUINT iGrpId, ZINT iIndex);

/**
 * @brief Get One parent-group by index.
 *
 * @param [in] iGrpId The group id.
 *
 * @return One parent group Id.
 *
 * @see @ref Mtc_BuddyGrpGetGrp
 */
ZFUNC ZUINT Mtc_BuddyGrpGetPGrp(ZUINT iGrpId);

/**
 * @brief Add One sub-group and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetGrpAddOk or @ref Mtc_BuddyCbSetGrpAddFailed.
 *
 * @param [in] iGrpId The group id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcName The group name.
 * @param [in] pcDispName The group display name.
 *
 * @return The id of new added group when add group successfully, 
 *              otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_BuddyGrpAddGrpL
 */
ZFUNC ZUINT Mtc_BuddyGrpAddGrp(ZUINT iGrpId, ZCOOKIE zCookie, 
                ZCHAR *pcName, ZCHAR *pcDispName); 

/**
 * @brief Add One sub-group into a group and in local cache.
 *
 * @param [in] iGrpId The group id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcName The group name.
 * @param [in] pcDispName The group display name.
 *
 * @return The id of new added group when add one sub-group successfully, 
 *              otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_BuddyGrpAddGrp
 */
ZFUNC ZUINT Mtc_BuddyGrpAddGrpL(ZUINT iGrpId, ZCOOKIE zCookie, 
                ZCHAR *pcName, ZCHAR *pcDispName); 

/**
 * @brief Find One group from group by name.
 *
 * @param [in] iGrpId The group id.
 * @param [in] pcName The group name.
 *
 * @return One group Id.
 *
 * @see @ref Mtc_BuddyGrpAddGrpL
 */
ZFUNC ZUINT Mtc_BuddyGrpFindGrp(ZUINT iGrpId, ZCHAR *pcName);

/**
 * @brief Get OMA buddy from one group.
 *
 * @param [in] iGrpId The group id.
 *
 * @return Buddy set size.
 *
 * @see @ref Mtc_BuddyGrpGetBuddy
 */
ZFUNC ZUINT Mtc_BuddyGrpGetBuddySize(ZUINT iGrpId);

/**
 * @brief Get a buddy from one group by index.
 *
 * @param [in] iGrpId The group id.
 * @param [in] iIndex The index of buddy.
 *
 * @return One buddy Id.
 *
 * @see @ref Mtc_BuddyGrpGetBuddySize
 */
ZFUNC ZUINT Mtc_BuddyGrpGetBuddy(ZUINT iGrpId, ZINT iIndex);

/**
 * @brief Add a buddy into one group and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBuddyAddOk or @ref Mtc_BuddyCbSetBuddyAddFailed.
 *
 * @param [in] iGrpId The group id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The buddy display name.
 * @param [in] pcUri The buddy URI.
 *
 * @return The id of buddy when add one buddy successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_BuddyGrpGetBuddySize
 */
ZFUNC ZUINT Mtc_BuddyGrpAddBuddy(ZUINT iGrpId, ZCOOKIE zCookie, 
                ZCHAR *pcDispName, ZCHAR *pcUri); 

/**
 * @brief Find One buddy from group by URI.
 *
 * @param [in] iGrpId The group id.
 * @param [in] pcUri The buddy URI.
 *
 * @return One buddy Id.
 *
 * @see @ref Mtc_BuddyGrpAddBuddy
 */
ZFUNC ZUINT Mtc_BuddyGrpFindBuddy(ZUINT iGrpId, ZCHAR *pcUri);

/**
 * @brief Get a buddy group name.
 *
 * @param [in] iGrpId The group id.
 *
 * @return Buddy group name.
 *  The caller must copy it, then use.
 *
 * @see @ref Mtc_BuddyGrpGetDispName
 */
ZFUNC ZCHAR * Mtc_BuddyGrpGetName(ZUINT iGrpId);

/**
 * @brief Get a buddy group display name.
 *
 * @param [in] iGrpId The group id.
 *
 * @return Buddy group name.
 *  The caller must copy it, then use.
 *
 * @see @ref Mtc_BuddyGrpSetDispName
 */
ZCHAR * Mtc_BuddyGrpGetDispName(ZUINT iGrpId);

/**
 * @brief Set a buddy group name and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetGrpMdfyOk or @ref Mtc_BuddyCbSetGrpMdfyFailed.
 *
 * @param [in] iGrpId The group id.
 * @param [in] pcName The group Name.
 *
 * @retval ZOK Set group name successfully.
 * @retval ZFAILED Set group name failed.
 *
 * @see @ref Mtc_BuddyGrpGetDispName
 */
ZINT Mtc_BuddyGrpSetDispName(ZUINT iGrpId, ZCHAR *pcName);

/**
 * @brief Get buddy display name.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @return Buddy display name. 
 *  The caller must copy it, then use.
 *
 * @see @ref Mtc_BuddySetDispName
 */
ZFUNC ZCHAR * Mtc_BuddyGetDispName(ZUINT iBuddyId);

/**
 * @brief Set buddy display name and update it to OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBuddyMdfyOk or @ref Mtc_BuddyCbSetBuddyMdfyFailed.
 *
 * @param [in] iBuddyId The id of buddy.
 * @param [in] pcDispName The display name of buddy.
 *
 * @retval ZOK Set buddy display name successfully.
 * @retval ZFAILED Set buddy display name failed.
 *
 * @see @ref Mtc_BuddyGetDispName
 */
ZFUNC ZINT Mtc_BuddySetDispName(ZUINT iBuddyId, ZCHAR *pcDispName);

/**
 * @brief Get buddy URI.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @return Buddy URI. 
 *  The caller must copy it, then use.
 *
 * @see @ref Mtc_BuddyGetDispName
 */
ZFUNC ZCHAR * Mtc_BuddyGetUri(ZUINT iBuddyId);

/**
 * @brief Get buddy cookie id.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @return Buddy cookie id. 
 *
 * @see @ref Mtc_BuddySetCookie
 */
ZFUNC ZCOOKIE Mtc_BuddyGetCookie(ZUINT iBuddyId);

/**
 * @brief Set buddy cookie id.
 *
 * @param [in] iBuddyId The id of buddy.
 * @param [in] zCookie The cookie id of buddy.
 *
 * @retval ZOK Set buddy cookie id successfully.
 * @retval ZFAILED Set buddy cookie id failed.
 *
 * @see @ref Mtc_BuddySetCookie
 */
ZFUNC ZINT Mtc_BuddySetCookie(ZUINT iBuddyId, ZCOOKIE zCookie);

/**
 * @brief Get buddy group id.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @return Buddy group id. 
 */
ZFUNC ZUINT Mtc_BuddyGetGrpId(ZUINT iBuddyId);

/**
 * @brief Get the presence subscription state of buddy.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @return Presence subscription state, see @ref EN_MTC_PRES_SUBS_STATE_TYPE. 
 */
ZFUNC ZUINT Mtc_BuddyGetPresSubState(ZUINT iBuddyId);

/**
 * @brief Get the presence subscription terminated reason of buddy.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @return Presence subscription terminated reason, 
 * see @ref EN_MTC_PRES_SUBS_REASON_TYPE. 
 */
ZFUNC ZUINT Mtc_BuddyGetPresSubTermReason(ZUINT iBuddyId);

/**
 * @brief Get the presence status of buddy.
 *
 * @param [in] iBuddyId The id of buddy.
 *
 * @return Presence status, see @ref EN_MTC_PRES_STAT_TYPE. 
 */
ZFUNC ZUINT Mtc_BuddyGetPresStatus(ZUINT iBuddyId);

/**
 * @brief Get the presence status-icon path of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy presence icon path.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_BuddyGetPresIconPath(ZUINT iBuddyId);

/**
 * @brief Get buddy status icon type.
 * 
 * @return The icon type, see @ref EN_MTC_PRES_ICON_TYPE.
 */
ZFUNC ZUINT Mtc_BuddyGetPresIconType(ZUINT iBuddyId);

/**
 * @brief Get the presence status-icon etag of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy presence icon etag.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_BuddyGetPresIconEtag(ZUINT iBuddyId);

/**
 * @brief Get the presence status-icon data of buddy.
 *
 * GUI would better clear icon data @ref Mtc_BuddyClrPresIconData after used icon file.
 * The reason is icon file will occupy big memory(less than or equal 200KB).
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy presence icon data.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_BuddyGetPresIconData(ZUINT iBuddyId);

/**
 * @brief Clear the presence status-icon data of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval ZOK Clear icon data successfully.
 * @retval ZFAILED Clear icon data failed.
 */
ZFUNC ZINT Mtc_BuddyClrPresIconData(ZUINT iBuddyId);

/**
 * @brief Get the presence display name of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy presence display name.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_BuddyGetPresDispName(ZUINT iBuddyId);

/**
 * @brief Get the presence note of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy presence note.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_BuddyGetPresNote(ZUINT iBuddyId);

/**
 * @brief Get the presence home page of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy presence home page.
 *  The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_BuddyGetPresHomePage(ZUINT iBuddyId);

/**
 * @brief Get the presence geolocation information type of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 * 
 * @retval The presence geolocation information type, see @ref EN_MTC_PRES_GINFO_TYPE.
 *
 * @see Mtc_BuddySetPresGInfoType
 */
ZFUNC ZUINT Mtc_BuddyGetPresGInfoType(ZUINT iBuddyId);

/**
 * @brief Get the free text from presence geolocation information of buddy.
 * 
 * @param [in] iBuddyId The buddy id.
 *
 * @retval The free text.
 *
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_BuddyGetPresGInfoFreeText(ZUINT iBuddyId);

/**
 * @brief Get the latitude of user place from presence geolocation information of buddy.
 * 
 * @param [in] iBuddyId The buddy id.
 *
 * @retval The latitude of user place.
 *
 */
ZFUNC ZDOUBLE Mtc_BuddyGetPresGInfoLatitude(ZUINT iBuddyId);

/**
 * @brief Get the longitude of user place from presence geolocation information of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval The longitude of user place.
 *
 */
ZFUNC ZDOUBLE Mtc_BuddyGetPresGInfoLongitude(ZUINT iBuddyId);

/**
 * @brief Get the radius of user place from presence geolocation information of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval The radius of user place.
 *
 */
ZFUNC ZFLOAT Mtc_BuddyGetPresGInfoRadius(ZUINT iBuddyId);

/**
 * @brief Get the timestamp from presence geolocation information of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval The timestamp.
 *
 */
ZFUNC ZTIME_T Mtc_BuddyGetPresGInfoTimestamp(ZUINT iBuddyId);

/**
 * @brief Get the until time from presence geolocation information of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval The until time.
 *
 */
ZFUNC ZTIME_T Mtc_BuddyGetPresGInfoUntilTime(ZUINT iBuddyId);

/**
 * @brief Get the the presence standalone message service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence standalone message service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvStandalMsg(ZUINT iBuddyId);

/**
 * @brief Get the the presence session mode messaging service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence session mode messaging service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvImSess(ZUINT iBuddyId);

/**
 * @brief Get the the presence full store and forward group chat service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence full store and forward group chat service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvStFwdGrpChat(ZUINT iBuddyId);

/**
 * @brief Get the the presence file transfer service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence file transfer service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvFileTrsf(ZUINT iBuddyId);

/**
 * @brief Get the the presence file transfer thumbnail service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence file transfer thumbnail service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvFtThumb(ZUINT iBuddyId);

/**
 * @brief Get the the presence file transfer store and forward service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence file transfer store and forward service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvFtStFwd(ZUINT iBuddyId);

/**
 * @brief Get the the presence file transfer via http service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence file transfer via http service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvFtViaHttp(ZUINT iBuddyId);

/**
 * @brief Get the the presence image share service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence image share service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvImgShare(ZUINT iBuddyId);

/**
 * @brief Get the the presence video share during a call service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence video share during a call service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvVsDuringCall(ZUINT iBuddyId);

/**
 * @brief Get the the presence video share outside of a voice call service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence video share outside of a voice call service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvVsOutCall(ZUINT iBuddyId);

/**
 * @brief Get the the presence social presence information service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence social presence information service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvSpi(ZUINT iBuddyId);

/**
 * @brief Get the the presence capability discovery via presence service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence capability discovery via presence service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvCapViaPres(ZUINT iBuddyId);

/**
 * @brief Get the the presence session mode voice call service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence session mode voice call service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvVoiceCall(ZUINT iBuddyId);

/**
 * @brief Get the the presence session mode video call service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence session mode video call service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvVideoCall(ZUINT iBuddyId);

/**
 * @brief Get the the presence geolocation pull service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence geolocation pull service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvGeoPull(ZUINT iBuddyId);

/**
 * @brief Get the the presence geolocation pull via file transfer service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence geolocation pull via file transfer service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvGeoPullViaFt(ZUINT iBuddyId);

/**
 * @brief Get the the presence geolocation push service availability of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy presence geolocation push service availability.
 */
ZFUNC ZBOOL Mtc_BuddyGetPresSrvGeoPush(ZUINT iBuddyId);

/**
 * @brief Load the presence status-icon of buddy.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBuddyIconLoadOk or @ref Mtc_BuddyCbSetBuddyIconLoadFailed.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval ZOK Load the presence status-icon of buddy is successfully.
 * @retval ZFAILED Load the presence status-icon of buddy is failed.
 */
ZFUNC ZINT Mtc_BuddyLoadPresIcon(ZUINT iBuddyId);

/**
 * @brief Export buddy presence status icon data into file.
 * 
 * GUI would better clear icon data @ref Mtc_PresPermClrIconData after exported icon file.
 * The reason is icon file will occupy big memory(less than or equal 200KB).
 *
 * @param [in] iBuddyId The buddy id.
 * @param [in] pcFileName The icon file name.
 *
 * @retval ZOK Export icon file successfully.
 * @retval ZFAILED Export icon file failed.
 */
ZFUNC ZINT Mtc_BuddyExportPresIcon(ZUINT iBuddyId, 
                ZCHAR *pcFileName);

/**
 * @brief Subscribe document changes of buddy.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetSubsDocChgsOk or @ref Mtc_BuddyCbSetSubsDocChgsFailed.
 *
 * @return Subscription id on succeed or ZMAXUINT on failed.
 */
ZFUNC ZUINT Mtc_BuddySubsDocChgs(ZFUNC_VOID);

/**
 * @brief Un-subscribe document changes of buddy.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetUnSubsDocChgsOk or @ref Mtc_BuddyCbSetUnSubsDocChgsFailed.
 *
 * @param [in] iSubsId The subscription id.
 *
 * @retval ZOK Un-subscribe successfully
 * @retval ZFAILED Un-subscribe failed.
 */
ZFUNC ZUINT Mtc_BuddyUnSubsDocChgs(ZUINT iSubsId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_BUDDY_H__ */

