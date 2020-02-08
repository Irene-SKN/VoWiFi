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
  File name     : mtc_buddy_pnb.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2013-02-21
  Description   :
      Data structure and function declare required by mtc pnb buddy set 

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_BUDDY_PNB_H__
#define _MTC_BUDDY_PNB_H__

/**
 * @file mtc_buddy_pnb.h
 * @brief MTC OMA Buddy Personal Network Blacklists Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC buddy pnb type */
typedef enum EN_MTC_BUDDY_PNB_TYPE
{
    EN_MTC_BUDDY_PNB_CHAT,          /**< @brief rcs pnb chat block */
    EN_MTC_BUDDY_PNB_FT,            /**< @brief rcs pnb ft block */
    EN_MTC_BUDDY_PNB_SA,            /**< @brief rcs pnb standalone block */
    EN_MTC_BUDDY_PNB_OUT_CHAT,      /**< @brief rcs pnb outchat block */
    EN_MTC_BUDDY_PNB_OUT_FT,        /**< @brief rcs pnb outft block */
    EN_MTC_BUDDY_PNB_OUT_SA,        /**< @brief rcs pnb outstandalone block */
} EN_MTC_BUDDY_PNB_TYPE;

/**
 * @brief Load buddy set from OMA XDMS.
 *
 * @param [in] iPnbType The buddy pnb type, @see @ref EN_MTC_BUDDY_PNB_TYPE.
 * 
 * @retval ZOK Start loading buddy set successfully.
 * @retval ZFAILED Client Load buddy set failed.
 */
ZFUNC ZINT Mtc_PnbBuddysLoad(ZUINT iPnbType);

/**
 * @brief Upload buddy set into OMA XDMS.
 *
 * @param [in] iPnbType The buddy pnb type, @see @ref EN_MTC_BUDDY_PNB_TYPE.
 * 
 * @retval ZOK Start loading buddy set successfully.
 * @retval ZFAILED Client Load buddy set failed.
 */
ZFUNC ZINT Mtc_PnbBuddysUpload(ZUINT iPnbType);

/**
 * @brief Get OMA buddy size in root group.
 *
 * @param [in] iPnbType The buddy pnb type, @see @ref EN_MTC_BUDDY_PNB_TYPE.
 *
 * @return Buddy set size.
 *
 * @see Mtc_PnbBuddysGetBuddy
 */
ZFUNC ZUINT Mtc_PnbBuddysGetBuddySize(ZUINT iPnbType);

/**
 * @brief Get One buddy from root group by index.
 *
 * @param [in] iPnbType The buddy pnb type, @see @ref EN_MTC_BUDDY_PNB_TYPE.
 * @param [in] iIndex The index of buddy.
 *
 * @return One buddy Id.
 *
 * @see Mtc_PnbBuddysGetBuddySize
 */
ZFUNC ZUINT Mtc_PnbBuddysGetBuddy(ZUINT iPnbType, ZUINT iIndex);

/**
 * @brief Add One buddy into root group and update change to xdms.
 *
 * @param [in] iPnbType The buddy pnb type, @see @ref EN_MTC_BUDDY_PNB_TYPE.
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The buddy display name.
 * @param [in] pcUri The buddy uri.
 *
 * @return The id of buddy when add one buddy successfully, otherwise return ZMAXUINT.
 *
 * @see Mtc_PnbBuddysRmvBuddy
 */
ZFUNC ZUINT Mtc_PnbBuddysAddBuddy(ZUINT iPnbType, ZCOOKIE zCookie, 
                ZCHAR *pcDispName, ZCHAR *pcUri);

/**
 * @brief Rmove One buddy and update change to xdms.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval ZOK Remove one buddy successfully.
 * @retval ZFAILED Remove one buddy failed.
 *
 * @see Mtc_PnbBuddysAddBuddy
 */
ZFUNC ZINT Mtc_PnbBuddysRmvBuddy(ZUINT iBuddyId);

/**
 * @brief Rmove One buddy in local cache.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval ZOK Remove one buddy successfully.
 * @retval ZFAILED Remove one buddy failed.
 *
 * @see Mtc_PnbBuddysAddBuddy
 */
ZFUNC ZINT Mtc_PnbBuddysRmvBuddyL(ZUINT iBuddyId);

/**
 * @brief Find One buddy from buddy URI.
 *
 * @param [in] iPnbType The buddy pnb type, @see @ref EN_MTC_BUDDY_PNB_TYPE.
 * @param [in] pcUri The buddy uri.
 *
 * @retval One buddy Id.
 *
 * @see Mtc_PnbBuddysRmvBuddy
 */
ZFUNC ZUINT Mtc_PnbBuddysFindBuddy(ZUINT iPnbType, ZCHAR *pcUri);

/**
 * @brief Get the display name of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy display name.
 *  The caller must copy it, then use.
 *
 * @see Mtc_PnbBuddySetDispName
 */
ZFUNC ZCHAR * Mtc_PnbBuddyGetDispName(ZUINT iBuddyId);

/**
 * @brief Set the display name of buddy and update change to xdms.
 *
 * @param [in] iBuddyId The buddy id.
 * @param [in] pcDispName The buddy display name.
 *
 * @retval ZOK Set buddy display name successfully.
 * @retval ZFAILED Set buddy display name failed.
 *
 * @see Mtc_PnbBuddyGetDispName
 */
ZFUNC ZINT Mtc_PnbBuddySetDispName(ZUINT iBuddyId, ZCHAR *pcDispName);

/**
 * @brief Get the URI of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy URI.
 *  The caller must copy it, then use.
 *
 * @see Mtc_PnbBuddyGetDispName
 */
ZFUNC ZCHAR * Mtc_PnbBuddyGetUri(ZUINT iBuddyId);

/**
 * @brief Get user cookie of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 *
 * @retval Buddy user cookie.
 *
 * @see Mtc_PnbBuddySetCookie
 */
ZFUNC ZCOOKIE Mtc_PnbBuddyGetCookie(ZUINT iBuddyId);

/**
 * @brief Set user cookie of buddy.
 *
 * @param [in] iBuddyId The buddy id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set buddy cookie successfully.
 * @retval ZFAILED Set buddy cookie failed.
 *
 * @see Mtc_PnbBuddyGetCookie
 */
ZFUNC ZINT Mtc_PnbBuddySetCookie(ZUINT iBuddyId, ZCOOKIE zCookie);


#ifdef __cplusplus
}
#endif

#endif /* _MTC_BUDDY_PNB_H__ */

