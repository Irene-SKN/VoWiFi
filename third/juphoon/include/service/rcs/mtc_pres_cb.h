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
  File name     : mtc_pres_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by MTC presence callback.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PRES_CB_H__
#define _MTC_PRES_CB_H__

/**
 * @file mtc_pres_cb.h
 * @brief MTC Presence Callback Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC presence callback for notify ok. */
typedef ZVOID (*PFN_MTCPRESCBOK)(ZFUNC_VOID);

/** @brief Type define of MTC presence callback for notify failed. */
typedef ZVOID (*PFN_MTCPRESCBFAILED)(ZUINT iStatCode);

/** @brief Type define of MTC presence callback for notify update. */
typedef ZVOID (*PFN_MTCPRESCBUPDATE)(ZFUNC_VOID);

/** @brief Type define of MTC presence callback for notify contact info subs/unsubs/update ok. */
typedef ZVOID (*PFN_MTCPRESCBCINFOOK)(ZUINT iCInfoId);

/** @brief Type define of MTC presence callback for notify contact info subs/unsubs failed. */
typedef ZVOID (*PFN_MTCPRESCBCINFOFAILED)(ZUINT iCInfoId, ZUINT iStatCode);

/** @brief Type define of MTC presence callback for notify buddy add ok. */
typedef ZVOID (*PFN_MTCPRESCBADDOK)(ZUINT iCInfoId);

/** @brief Type define of MTC presence callback for notify buddy add failed. */
typedef ZVOID (*PFN_MTCPRESCBADDFAILED)(ZUINT iCInfoId, ZUINT iStatCode);

/** @brief Type define of MTC presence callback for notify buddy remove ok. */
typedef ZVOID (*PFN_MTCPRESCBRMVOK)(ZUINT iCInfoId);

/** @brief Type define of MTC presence callback for notify buddy remove failed. */
typedef ZVOID (*PFN_MTCPRESCBRMVFAILED)(ZUINT iCInfoId, ZUINT iStatCode);

/** @brief Type define of MTC presence callback for notify document changes subs/unsubs ok. */
typedef ZVOID (*PFN_MTCPRESCBDOCCHGSOK)(ZUINT iSubsId);

/** @brief Type define of MTC presence callback for notify document changes subs/unsubs failed. */
typedef ZVOID (*PFN_MTCPRESCBDOCCHGSFAILED)(ZUINT iSubsId, ZUINT iStatCode);

/** 
* @brief Type define of MTC presence set callback for synchronize document indication of presence permanent.
* @param iSyncType is the type need to synchronize document(see @ref MTC_PRES_CB_SYNC_TYPE).
*/
typedef ZVOID (*PFN_MTCPRESCBDOCSYNCIND)(ZUINT iSyncType);

/**
 * @brief Set the publish presence status successfully callback.
 * The callback is one of @ref Mtc_PresPubStatus results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPubStatusOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the publish presence status failed callback.
 * The callback is one of @ref Mtc_PresPubStatus results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPubStatusFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the un-publish presence status successfully callback.
 * The callback is one of @ref Mtc_PresUnPubStatus results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnPubStatusOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the un-publish presence status failed callback.
 * The callback is one of @ref Mtc_PresUnPubStatus results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnPubStatusFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the publish poc-settings successfully callback.
 * The callback is one of @ref Mtc_PresPubPocSets results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPubPocSetsOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the publish poc-settings failed callback.
 * The callback is one of @ref Mtc_PresPubPocSets results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPubPocSetsFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the un-publish poc-settings successfully callback.
 * The callback is one of @ref Mtc_PresUnPubPocSets results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnPubPocSetsOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the un-publish poc-settings failed callback.
 * The callback is one of @ref Mtc_PresUnPubPocSets results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnPubPocSetsFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the subscribe one buddy presence status successfully callback.
 * The callback is one of @ref Mtc_PresSubsBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSubsBuddyOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the subscribe one buddy presence status failed callback.
 * The callback is one of @ref Mtc_PresSubsBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSubsBuddyFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the un-subscribe one buddy presence status successfully callback.
 * The callback is one of @ref Mtc_PresUnSubsBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnSubsBuddyOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the un-subscribe one buddy presence status failed callback.
 * The callback is one of @ref Mtc_PresUnSubsBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnSubsBuddyFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the subscribe presence status successfully callback.
 * The callback is one of @ref Mtc_PresSubsBuddyLst results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSubsBuddyLstOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the subscribe presence status failed callback.
 * The callback is one of @ref Mtc_PresSubsBuddyLst results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSubsBuddyLstFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the un-subscribe presence status successfully callback.
 * The callback is one of @ref Mtc_PresUnSubsBuddyLst results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnSubsBuddyLstOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the un-subscribe presence status failed callback.
 * The callback is one of @ref Mtc_PresUnSubsBuddyLst results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnSubsBuddyLstFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the subscribe one contact info presence status successfully callback.
 * The callback is one of @ref Mtc_PresCInfoSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSubsCInfoOk(PFN_MTCPRESCBCINFOOK pfnCb);

/**
 * @brief Set the subscribe one contact info presence status failed callback.
 * The callback is one of @ref Mtc_PresCInfoSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSubsCInfoFailed(PFN_MTCPRESCBCINFOFAILED pfnCb);

/**
 * @brief Set the un-subscribe one contact info presence status successfully callback.
 * The callback is one of @ref Mtc_PresCInfoUnSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnSubsCInfoOk(PFN_MTCPRESCBCINFOOK pfnCb);

/**
 * @brief Set the un-subscribe one contact info presence status failed callback.
 * The callback is one of @ref Mtc_PresCInfoUnSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnSubsCInfoFailed(PFN_MTCPRESCBCINFOFAILED pfnCb);

/**
 * @brief Set the contact info has updated callback.
 * The callback will be notified if user subscribe contact info
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetCInfoUpdated(PFN_MTCPRESCBCINFOOK pfnCb);

/**
 * @brief Set the subscribe watch info successfully callback.
 * The callback is one of @ref Mtc_PresWinfoSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSubsWinfoOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the subscribe watch info failed callback.
 * The callback is one of @ref Mtc_PresWinfoSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSubsWinfoFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the un-subscribe watch info successfully callback.
 * The callback is one of @ref Mtc_PresWinfoUnSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnSubsWinfoOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the un-subscribe watch info failed callback.
 * The callback is one of @ref Mtc_PresWinfoUnSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetUnSubsWinfoFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the watch info has updated callback.
 * The callback will be notified if user subscribe watch info
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetWinfoUpdated(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the load presence rule successfully callback.
 * The callback is one of @ref Mtc_PresRulesLoad results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetRuleLoadOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the load presence rule failed callback.
 * The callback is one of @ref Mtc_PresRulesLoad results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetRuleLoadFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the load presence service successfully callback.
 * The callback is one of @ref Mtc_PresSrvsLoad results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSrvLoadOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the load presence service failed callback.
 * The callback is one of @ref Mtc_PresSrvsLoad results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSrvLoadFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the upload presence service successfully callback.
 * The callback is one of @ref Mtc_PresSrvsUpload results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSrvUploadOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the upload presence service failed callback.
 * The callback is one of @ref Mtc_PresSrvsUpload results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSrvUploadFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the add a buddy in presence service successfully callback.
 * The callback is one of @ref Mtc_PresSrvAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSrvAddBuddyOk(PFN_MTCPRESCBADDOK pfnCb);

/**
 * @brief Set the add a buddy in presence service failed callback.
 * The callback is one of @ref Mtc_PresSrvAddBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSrvAddBuddyFailed(PFN_MTCPRESCBADDFAILED pfnCb);

/**
 * @brief Set the remove a buddy in presence service successfully callback.
 * The callback is one of @ref Mtc_PresSrvRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSrvRmvBuddyOk(PFN_MTCPRESCBRMVOK pfnCb);

/**
 * @brief Set the remove a buddy in presence service failed callback.
 * The callback is one of @ref Mtc_PresSrvRmvBuddy results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetSrvRmvBuddyFailed(PFN_MTCPRESCBRMVFAILED pfnCb);

/**
 * @brief Set the load presence permanent successfully callback.
 * The callback is one of @ref Mtc_PresPermLoad results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsLoadOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the load presence permanent failed callback.
 * The callback is one of @ref Mtc_PresPermLoad results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsLoadFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the upload presence permanent successfully callback.
 * The callback is one of @ref Mtc_PresPermUpload results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsUploadOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the upload presence permanent failed callback.
 * The callback is one of @ref Mtc_PresPermUpload results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsUploadFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the subscribe presence permanent document changes successfully callback.
 * The callback is one of @ref Mtc_PresPermSubsDocChgs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsSubsDocChgsOk(PFN_MTCPRESCBDOCCHGSOK pfnCb);

/**
 * @brief Set the subscribe presence permanent document changes failed callback.
 * The callback is one of @ref Mtc_PresPermSubsDocChgs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsSubsDocChgsFailed(PFN_MTCPRESCBDOCCHGSFAILED pfnCb);

/**
 * @brief Set the un-subscribe presence permanent document changes successfully callback.
 * The callback is one of @ref Mtc_PresPermUnSubsDocChgs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsUnSubsDocChgsOk(PFN_MTCPRESCBDOCCHGSOK pfnCb);

/**
 * @brief Set the un-subscribe presence permanent document changes failed callback.
 * The callback is one of @ref Mtc_PresPermUnSubsDocChgs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsUnSubsDocChgsFailed(PFN_MTCPRESCBDOCCHGSFAILED pfnCb);

/**
 * @brief Set the presence permanent document synchronize indication callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetPermsDocSyncInd(PFN_MTCPRESCBDOCSYNCIND pfnCb);

/**
 * @brief Set the load presence status icon successfully callback.
 * The callback is one of @ref Mtc_PresPermLoadIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetStatIconLoadOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the load presence status icon failed callback.
 * The callback is one of @ref Mtc_PresPermLoadIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetStatIconLoadFailed(PFN_MTCPRESCBFAILED pfnCb);

/**
 * @brief Set the upload presence status icon successfully callback.
 * The callback is one of @ref Mtc_PresPermUploadIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetStatIconUploadOk(PFN_MTCPRESCBOK pfnCb);

/**
 * @brief Set the upload presence status icon failed callback.
 * The callback is one of @ref Mtc_PresPermUploadIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PresCbSetStatIconUploadFailed(PFN_MTCPRESCBFAILED pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PRES_CB_H__ */

