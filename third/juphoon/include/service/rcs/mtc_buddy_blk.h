/************************************************************************

        Copyright (c) 2005-2007 by Juphoon System Software, Inc.
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
  File name     : mtc_buddy_blk.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-02-20
  Description   :
      Data structure and function declare required by mtc block buddy set 

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_BUDDY_BLK_H__
#define _MTC_BUDDY_BLK_H__

/**
 * @file mtc_buddy_blk.h
 * @brief MTC OMA Block Buddy Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Load buddy set from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBlkAllLoadOk or @ref Mtc_BuddyCbSetBlkAllLoadFailed.
 *
 * @retval ZOK Start loading buddy set successfully.
 * @retval ZFAILED Client Load buddy set failed.
 */
ZFUNC ZINT Mtc_BlkBuddysLoad(ZFUNC_VOID);

/**
 * @brief Upload buddy set into OMA XDMS.
 * 
 * @retval ZOK Start loading buddy set successfully.
 * @retval ZFAILED Client Load buddy set failed.
 */
ZFUNC ZINT Mtc_BlkBuddysUpload(ZFUNC_VOID);

/**
 * @brief Get OMA buddy size in root group.
 *
 * @return Buddy set size.
 *
 * @see @ref Mtc_BlkBuddysGetBuddy
 */
ZFUNC ZUINT Mtc_BlkBuddysGetBuddySize(ZFUNC_VOID);

/**
 * @brief Get One buddy from root group by index.
 *
 * @param [in] iIndex The index of buddy.
 *
 * @return One buddy Id.
 *
 * @see @ref Mtc_BlkBuddysGetBuddySize
 */
ZFUNC ZUINT Mtc_BlkBuddysGetBuddy(ZUINT iIndex);

/**
 * @brief Add One buddy into root group and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBlkBuddyAddOk or @ref Mtc_BuddyCbSetBlkBuddyAddFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The buddy display name.
 * @param [in] pcUri The buddy URI.
 *
 * @return The id of buddy when add one buddy successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_BlkBuddysRmvBuddy
 */
ZFUNC ZUINT Mtc_BlkBuddysAddBuddy(ZCOOKIE zCookie, ZCHAR *pcDispName, 
                ZCHAR *pcUri);

/**
 * @brief Remove One buddy and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBlkBuddyRmvOk or @ref Mtc_BuddyCbSetBlkBuddyRmvFailed.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval ZOK Remove one buddy successfully.
 * @retval ZFAILED Remove one buddy failed.
 *
 * @see @ref Mtc_BlkBuddysAddBuddy
 */
ZFUNC ZINT Mtc_BlkBuddysRmvBuddy(ZUINT iBuddyId);

/**
 * @brief Remove One buddy in local cache.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval ZOK Remove one buddy successfully.
 * @retval ZFAILED Remove one buddy failed.
 *
 * @see @ref Mtc_BlkBuddysAddBuddy
 */
ZFUNC ZINT Mtc_BlkBuddysRmvBuddyL(ZUINT iBuddyId);

/**
 * @brief Find One buddy from buddy URI.
 *
 * @param [in] pcUri The buddy URI.
 *
 * @return One buddy Id.
 *
 * @see @ref Mtc_BlkBuddysRmvBuddy
 */
ZFUNC ZUINT Mtc_BlkBuddysFindBuddy(ZCHAR *pcUri);

/**
 * @brief Get the display name of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy display name.
 *  The caller must copy it, then use.
 *
 * @see @ref Mtc_BlkBuddySetDispName
 */
ZFUNC ZCHAR * Mtc_BlkBuddyGetDispName(ZUINT iBuddyId);

/**
 * @brief Set the display name of buddy and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_BuddyCbSetBlkBuddyMdfyOk or @ref Mtc_BuddyCbSetBlkBuddyMdfyFailed.
 *
 * @param [in] iBuddyId The buddy id.
 * @param [in] pcDispName The buddy display name.
 *
 * @retval ZOK Set buddy display name successfully.
 * @retval ZFAILED Set buddy display name failed.
 *
 * @see @ref Mtc_BlkBuddyGetDispName
 */
ZFUNC ZINT Mtc_BlkBuddySetDispName(ZUINT iBuddyId, ZCHAR *pcDispName);

/**
 * @brief Get the URI of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy URI.
 *  The caller must copy it, then use.
 *
 * @see @ref Mtc_BlkBuddyGetDispName
 */
ZFUNC ZCHAR * Mtc_BlkBuddyGetUri(ZUINT iBuddyId);

/**
 * @brief Get user cookie of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @return Buddy user cookie.
 *
 * @see @ref Mtc_BlkBuddySetCookie
 */
ZFUNC ZCOOKIE Mtc_BlkBuddyGetCookie(ZUINT iBuddyId);

/**
 * @brief Set user cookie of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set buddy cookie successfully.
 * @retval ZFAILED Set buddy cookie failed.
 *
 * @see @ref Mtc_BlkBuddyGetCookie
 */
ZFUNC ZINT Mtc_BlkBuddySetCookie(ZUINT iBuddyId, ZCOOKIE zCookie);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_BUDDY_BLK_H__ */

