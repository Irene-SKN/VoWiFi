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
  File name     : mtc_buddy_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by MTC OMA buddy callback.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_BUDDY_CB_H__
#define _MTC_BUDDY_CB_H__

/**
 * @file mtc_buddy_cb.h
 * @brief MTC OMA Buddy Callback Interface Functions
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC buddy set callback for notify load doc ok. */
typedef ZVOID (*PFN_MTCBUDDYSCBLOADOK)(ZFUNC_VOID);

/** @brief Type define of MTC buddy set callback for notify load doc failed. */
typedef ZVOID (*PFN_MTCBUDDYSCBLOADFAILED)(ZUINT iStatCode);

/** @brief Type define of MTC buddy set callback for notify load a group of doc ok. */
typedef ZVOID (*PFN_MTCBUDDYSCBGRPLOADOK)(ZUINT iGrpType);

/** @brief Type define of MTC buddy set callback for notify load a group of doc failed. */
typedef ZVOID (*PFN_MTCBUDDYSCBGRPLOADFAILED)(ZUINT iGrpType, 
                ZUINT iStatCode);

/** @brief Type define of MTC buddy callback for notify rcs group/buddy add ok. */
typedef ZVOID (*PFN_MTCBUDDYCBADDOK)(ZUINT iGrpType, ZUINT iId, 
                ZCHAR *pcIdStr);

/** @brief Type define of MTC buddy callback for notify rcs group/buddy add failed. */
typedef ZVOID (*PFN_MTCBUDDYCBADDFAILED)(ZUINT iGrpType, ZCHAR *pcIdStr, 
                ZUINT iStatCode);

/** @brief Type define of MTC buddy callback for notify rcs group/buddy remove ok. */
typedef ZVOID (*PFN_MTCBUDDYCBRMVOK)(ZUINT iGrpType, ZCHAR *pcIdStr);

/** @brief Type define of MTC buddy callback for notify rcs group/buddy remove failed. */
typedef ZVOID (*PFN_MTCBUDDYCBRMVFAILED)(ZUINT iGrpType, ZUINT iId, 
                ZCHAR *pcIdStr, ZUINT iStatCode);

/** @brief Type define of MTC buddy callback for notify rcs group/buddy modify ok. */
typedef ZVOID (*PFN_MTCBUDDYCBMDFYOK)(ZUINT iGrpType, ZUINT iId, 
                ZCHAR *pcIdStr);

/** @brief Type define of MTC buddy callback for notify rcs group/buddy modify failed. */
typedef ZVOID (*PFN_MTCBUDDYCBMDFYFAILED)(ZUINT iGrpType, ZUINT iId, 
                ZCHAR *pcIdStr, ZUINT iStatCode);

/** @brief Type define of MTC buddy callback for notify rcs group/buddy status changed. */
typedef ZVOID (*PFN_MTCBUDDYSCBTATCHGED)(ZUINT iId, ZCHAR *pcIdStr);

/** @brief Type define of MTC buddy callback for notify load presence icon ok. */
typedef ZVOID (*PFN_MTCBUDDYCBLOADOK)(ZUINT iGrpType, ZUINT iBuddyId, 
                ZCHAR *pcIdStr);

/** @brief Type define of MTC buddy callback for notify load presence icon failed. */
typedef ZVOID (*PFN_MTCBUDDYCBLOADFAILED)(ZUINT iGrpType, 
                ZUINT iBuddyId, ZCHAR *pcIdStr, ZUINT iStatCode);

/** @brief Type define of MTC buddy callback for notify revoke/block group/buddy add ok. */
typedef ZVOID (*PFN_MTCBUDDYCBXADDOK)(ZUINT iId, ZCHAR *pcIdStr);

/** @brief Type define of MTC buddy callback for notify revoke/block group/buddy add failed. */
typedef ZVOID (*PFN_MTCBUDDYCBXADDFAILED)(ZCHAR *pcIdStr, ZUINT iStatCode);

/** @brief Type define of MTC buddy callback for notify revoke/block group/buddy remove ok. */
typedef ZVOID (*PFN_MTCBUDDYCBXRMVOK)(ZCHAR *pcIdStr);

/** @brief Type define of MTC buddy callback for notify revoke/block group/buddy remove failed. */
typedef ZVOID (*PFN_MTCBUDDYCBXRMVFAILED)(ZUINT iId, ZCHAR *pcIdStr, 
                ZUINT iStatCode);

/** @brief Type define of MTC buddy callback for notify revoke/block group/buddy modify ok. */
typedef ZVOID (*PFN_MTCBUDDYCBXMDFYOK)(ZUINT iId, ZCHAR *pcIdStr);

/** @brief Type define of MTC buddy callback for notify revoke/block group/buddy modify failed. */
typedef ZVOID (*PFN_MTCBUDDYCBXMDFYFAILED)(ZUINT iId, ZCHAR *pcIdStr, 
                ZUINT iStatCode);

/** @brief Type define of MTC buddy callback for notify document changes subs/unsubs ok. */
typedef ZVOID (*PFN_MTCBUDDYCBDOCCHGSOK)(ZUINT iSubsId);

/** @brief Type define of MTC buddy callback for notify document changes subs/unsubs failed. */
typedef ZVOID (*PFN_MTCBUDDYCBDOCCHGSFAILED)(ZUINT iSubsId, 
                ZUINT iStatCode);

/** 
* @brief Type define of MTC buddy set callback for document synchronize indication.
* @param iSyncType is the type need to synchronize document(see @ref MTC_BUDDY_CB_SYNC_TYPE).
*/
typedef ZVOID (*PFN_MTCBUDDYCBDOCSYNCIND)(ZUINT iSyncType);

/**
 * @brief Set the OMA buddy set load all buddies successfully callback.
 * The callback is one of @ref Mtc_BuddysLoadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetAllLoadOk(PFN_MTCBUDDYSCBLOADOK pfnCb);

/**
 * @brief Set the OMA buddy set load failed callback.
 * The callback is one of @ref Mtc_BuddysLoadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetAllLoadFailed(PFN_MTCBUDDYSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA buddy set upload all buddies successfully callback.
 * The callback is one of @ref Mtc_BuddysUploadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetAllUploadOk(PFN_MTCBUDDYSCBLOADOK pfnCb);

/**
 * @brief Set the OMA buddy set upload failed callback.
 * The callback is one of @ref Mtc_BuddysUploadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetAllUploadFailed(PFN_MTCBUDDYSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA buddy set load a group buddies successfully callback.
 * The callback is one of @ref Mtc_BuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetRcsAllLoadOk(PFN_MTCBUDDYSCBGRPLOADOK pfnCb);

/**
 * @brief Set the OMA buddy set load a group buddies failed callback.
 * The callback is one of @ref Mtc_BuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetRcsAllLoadFailed(PFN_MTCBUDDYSCBGRPLOADFAILED pfnCb);

/**
 * @brief Set the OMA buddy set upload a group buddies successfully callback.
 * The callback is one of @ref Mtc_BuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetRcsAllUploadOk(PFN_MTCBUDDYSCBGRPLOADOK pfnCb);

/**
 * @brief Set the OMA buddy set upload a group buddies failed callback.
 * The callback is one of @ref Mtc_BuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetRcsAllUploadFailed(PFN_MTCBUDDYSCBGRPLOADFAILED pfnCb);

/**
 * @brief Set the group added successfully callback.
 * The callback is one of @ref Mtc_BuddysAddGrp results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetGrpAddOk(PFN_MTCBUDDYCBADDOK pfnCb);

/**
 * @brief Set the group added failed callback.
 * The callback is one of @ref Mtc_BuddysAddGrp results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetGrpAddFailed(PFN_MTCBUDDYCBADDFAILED pfnCb);

/**
 * @brief Set the group removed successfully callback.
 * The callback is one of @ref Mtc_BuddysRmvGrp results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetGrpRmvOk(PFN_MTCBUDDYCBRMVOK pfnCb);

/**
 * @brief Set the group removed failed callback.
 * The callback is one of @ref Mtc_BuddysRmvGrp results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetGrpRmvFailed(PFN_MTCBUDDYCBRMVFAILED pfnCb);

/**
 * @brief Set the group modified successfully callback.
 * The callback is one of @ref Mtc_BuddyGrpSetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetGrpMdfyOk(PFN_MTCBUDDYCBMDFYOK pfnCb);

/**
 * @brief Set the group modified failed callback.
 * The callback is one of @ref Mtc_BuddyGrpSetDispName results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetGrpMdfyFailed(PFN_MTCBUDDYCBMDFYFAILED pfnCb);

/**
 * @brief Set the buddy group state change callback.
 * The callback will be notified if user subscribe buddy's presence status in one group.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetGrpStaChged(PFN_MTCBUDDYSCBTATCHGED pfnCb);

/**
 * @brief Set the buddy added successfully callback.
 * The callback is one of @ref Mtc_BuddysAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyAddOk(PFN_MTCBUDDYCBADDOK pfnCb);

/**
 * @brief Set the buddy added failed callback.
 * The callback is one of @ref Mtc_BuddysAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyAddFailed(PFN_MTCBUDDYCBADDFAILED pfnCb);

/**
 * @brief Set the buddy removed successfully callback.
 * The callback is one of @ref Mtc_BuddysRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyRmvOk(PFN_MTCBUDDYCBRMVOK pfnCb);

/**
 * @brief Set the buddy removed failed callback.
 * The callback is one of @ref Mtc_BuddysRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyRmvFailed(PFN_MTCBUDDYCBRMVFAILED pfnCb);

/**
 * @brief Set the buddy modified successfully callback.
 * The callback is one of @ref Mtc_BuddySetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyMdfyOk(PFN_MTCBUDDYCBMDFYOK pfnCb);

/**
 * @brief Set the buddy modified failed callback.
 * The callback is one of @ref Mtc_BuddySetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyMdfyFailed(PFN_MTCBUDDYCBMDFYFAILED pfnCb);

/**
 * @brief Set the buddy icon load successfully callback.
 * The callback is one of @ref Mtc_BuddyLoadPresIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyIconLoadOk(PFN_MTCBUDDYCBLOADOK pfnCb);

/**
 * @brief Set the buddy icon load failed callback.
 * The callback is one of @ref Mtc_BuddyLoadPresIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyIconLoadFailed(PFN_MTCBUDDYCBLOADFAILED pfnCb);

/**
 * @brief Set the buddy state change callback.
 * The callback will be notified if user subscribe buddy's presence status
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBuddyStatChged(PFN_MTCBUDDYSCBTATCHGED pfnCb);

/**
 * @brief Set the OMA blocked buddy set load all buddies successfully callback.
 * The callback is one of @ref Mtc_BlkBuddysLoad results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkAllLoadOk(PFN_MTCBUDDYSCBLOADOK pfnCb);

/**
 * @brief Set the OMA blocked buddy set load failed callback.
 * The callback is one of @ref Mtc_BlkBuddysLoad results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkAllLoadFailed(PFN_MTCBUDDYSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA blocked buddy set upload all buddies successfully callback.
 * The callback is one of @ref Mtc_BlkBuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkAllUploadOk(PFN_MTCBUDDYSCBLOADOK pfnCb);

/**
 * @brief Set the OMA blocked buddy set upload failed callback.
 * The callback is one of @ref Mtc_BlkBuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkAllUploadFailed(PFN_MTCBUDDYSCBLOADFAILED pfnCb);

/**
 * @brief Set the buddy added successfully callback.
 * The callback is one of @ref Mtc_BlkBuddysAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkBuddyAddOk(PFN_MTCBUDDYCBXADDOK pfnCb);

/**
 * @brief Set the buddy added failed callback.
 * The callback is one of @ref Mtc_BlkBuddysAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkBuddyAddFailed(PFN_MTCBUDDYCBXADDFAILED pfnCb);

/**
 * @brief Set the buddy removed successfully callback.
 * The callback is one of @ref Mtc_BlkBuddysRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkBuddyRmvOk(PFN_MTCBUDDYCBXRMVOK pfnCb);

/**
 * @brief Set the buddy removed failed callback.
 * The callback is one of @ref Mtc_BlkBuddysRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkBuddyRmvFailed(PFN_MTCBUDDYCBXRMVFAILED pfnCb);

/**
 * @brief Set the buddy modified successfully callback.
 * The callback is one of @ref Mtc_BlkBuddySetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkBuddyMdfyOk(PFN_MTCBUDDYCBXMDFYOK pfnCb);

/**
 * @brief Set the buddy modified failed callback.
 * The callback is one of @ref Mtc_BlkBuddySetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetBlkBuddyMdfyFailed(PFN_MTCBUDDYCBXMDFYFAILED pfnCb);

/**
 * @brief Set the OMA revoked buddy set load all buddies successfully callback.
 * The callback is one of @ref Mtc_RvkBuddysLoad results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkAllLoadOk(PFN_MTCBUDDYSCBLOADOK pfnCb);

/**
 * @brief Set the OMA revoked buddy set load failed callback.
 * The callback is one of @ref Mtc_RvkBuddysLoad results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkAllLoadFailed(PFN_MTCBUDDYSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA revoked buddy set upload all buddies successfully callback.
 * The callback is one of @ref Mtc_RvkBuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkAllUploadOk(PFN_MTCBUDDYSCBLOADOK pfnCb);

/**
 * @brief Set the OMA revoked buddy set upload failed callback.
 * The callback is one of @ref Mtc_RvkBuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkAllUploadFailed(PFN_MTCBUDDYSCBLOADFAILED pfnCb);

/**
 * @brief Set the buddy added successfully callback.
 * The callback is one of @ref Mtc_RvkBuddysAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkBuddyAddOk(PFN_MTCBUDDYCBXADDOK pfnCb);

/**
 * @brief Set the buddy added failed callback.
 * The callback is one of @ref Mtc_RvkBuddysAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkBuddyAddFailed(PFN_MTCBUDDYCBXADDFAILED pfnCb);

/**
 * @brief Set the buddy removed successfully callback.
 * The callback is one of @ref Mtc_RvkBuddysRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkBuddyRmvOk(PFN_MTCBUDDYCBXRMVOK pfnCb);

/**
 * @brief Set the buddy removed failed callback.
 * The callback is one of @ref Mtc_RvkBuddysRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkBuddyRmvFailed(PFN_MTCBUDDYCBXRMVFAILED pfnCb);

/**
 * @brief Set the buddy modified successfully callback.
 * The callback is one of @ref Mtc_RvkBuddySetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkBuddyMdfyOk(PFN_MTCBUDDYCBXMDFYOK pfnCb);

/**
 * @brief Set the buddy modified failed callback.
 * The callback is one of @ref Mtc_RvkBuddySetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetRvkBuddyMdfyFailed(PFN_MTCBUDDYCBXMDFYFAILED pfnCb);

/**
 * @brief Set the OMA pnb buddy set load all buddies successfully callback.
 * The callback is one of @ref Mtc_PnbBuddysLoad results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbAllLoadOk(PFN_MTCBUDDYSCBGRPLOADOK pfnCb);

/**
 * @brief Set the OMA pnb buddy set load failed callback.
 * The callback is one of @ref Mtc_PnbBuddysLoad results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbAllLoadFailed(PFN_MTCBUDDYSCBGRPLOADFAILED pfnCb);

/**
 * @brief Set the OMA pnb buddy set upload all buddies successfully callback.
 * The callback is one of @ref Mtc_PnbBuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbAllUploadOk(PFN_MTCBUDDYSCBGRPLOADOK pfnCb);

/**
 * @brief Set the OMA pnb buddy set upload failed callback.
 * The callback is one of @ref Mtc_PnbBuddysUpload results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbAllUploadFailed(PFN_MTCBUDDYSCBGRPLOADFAILED pfnCb);

/**
 * @brief Set the buddy added successfully callback.
 * The callback is one of @ref Mtc_PnbBuddysAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbBuddyAddOk(PFN_MTCBUDDYCBADDOK pfnCb);

/**
 * @brief Set the buddy added failed callback.
 * The callback is one of @ref Mtc_PnbBuddysAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbBuddyAddFailed(PFN_MTCBUDDYCBADDFAILED pfnCb);

/**
 * @brief Set the buddy removed successfully callback.
 * The callback is one of @ref Mtc_PnbBuddysRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbBuddyRmvOk(PFN_MTCBUDDYCBRMVOK pfnCb);

/**
 * @brief Set the buddy removed failed callback.
 * The callback is one of @ref Mtc_PnbBuddysRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbBuddyRmvFailed(PFN_MTCBUDDYCBRMVFAILED pfnCb);

/**
 * @brief Set the buddy modified successfully callback.
 * The callback is one of @ref Mtc_PnbBuddySetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbBuddyMdfyOk(PFN_MTCBUDDYCBMDFYOK pfnCb);

/**
 * @brief Set the buddy modified failed callback.
 * The callback is one of @ref Mtc_PnbBuddySetDispName results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_BuddyCbSetPnbBuddyMdfyFailed(PFN_MTCBUDDYCBMDFYFAILED pfnCb);

/**
 * @brief Set the subscribe document changes successfully callback.
 * The callback is one of @ref Mtc_BuddySubsDocChgs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetSubsDocChgsOk(PFN_MTCBUDDYCBDOCCHGSOK pfnCb);

/**
 * @brief Set the subscribe document changes failed callback.
 * The callback is one of @ref Mtc_BuddySubsDocChgs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetSubsDocChgsFailed(PFN_MTCBUDDYCBDOCCHGSFAILED pfnCb);

/**
 * @brief Set the un-subscribe document changes successfully callback.
 * The callback is one of @ref Mtc_BuddyUnSubsDocChgs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetUnSubsDocChgsOk(PFN_MTCBUDDYCBDOCCHGSOK pfnCb);

/**
 * @brief Set the un-subscribe document changes failed callback.
 * The callback is one of @ref Mtc_BuddyUnSubsDocChgs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetUnSubsDocChgsFailed(PFN_MTCBUDDYCBDOCCHGSFAILED pfnCb);

/**
 * @brief Set the OMA buddy set document synchronize indication callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_BuddyCbSetDocSyncInd(PFN_MTCBUDDYCBDOCSYNCIND pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_BUDDY_CB_H__ */

