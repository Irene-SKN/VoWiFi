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
  File name     : mtc_im_grp_cb.h
  Module        : multimedia talk client
  Author        : gloria.yang
  Created on    : 2018-11-07
  Description   :
      Data structure and function declare required by MTC instant message callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_GRP_CB_H__
#define _MTC_IM_GRP_CB_H__

/**
 * @file mtc_im_cb.h
 * @brief MTC Instant Message Callback Interface Functions
 *
 * This file includes IM callback interface function. Those function
 * is used to manage IM.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC IM message(page or large) operation ok. */
typedef ZVOID (*PFN_MTCIMCMCCMSGCB)(ZUINT iMsgId);

/** @brief Type define of MTC IM message(page or large) operation failed. */
typedef ZVOID (*PFN_MTCIMCMCCMSGXCB)(ZUINT iMsgId, ZUINT iStatCode);

/** @brief Type define of MTC IM session operation ok. */
typedef ZVOID (*PFN_MTCIMCMCCSESSCB)(ZUINT iSessId);

/** @brief Type define of MTC IM session operation failed. */
typedef ZVOID (*PFN_MTCIMCMCCSESSXCB)(ZUINT iSessId, ZUINT iStatCode);

/** @brief Type define of MTC IM refer operation ok. */
typedef ZVOID (*PFN_MTCIMCMCCRFERCB)(ZUINT iRferId);

/** @brief Type define of MTC IM refer operation failed. */
typedef ZVOID (*PFN_MTCIMCMCCRFERXCB)(ZUINT iRferId, ZUINT iStatCode);

/** @brief Type define of MTC IM receive group infomation callback. */
typedef ZVOID (*PFN_MTCIMCMCCGINFO)(ZUINT iGrpInfoId, ZBOOL bFullNtfy);


/**
 * @brief Set the cmcc group received a new invitation callback.
 * The callback will be notified if user received cmcc group invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpRecvIvt(PFN_MTCIMCMCCSESSCB pfnCb);

/**
 * @brief Set the cmcc group accepted callback.
 * The callback is one of @ref Mtc_ImCmccGrpCreat results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpAcpted(PFN_MTCIMCMCCSESSCB pfnCb);

/**
 * @brief Set the cmcc group rejected callback.
 * The callback is one of @ref Mtc_ImCmccGrpCreat results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpRejected(PFN_MTCIMCMCCSESSXCB pfnCb);

/**
 * @brief Set the cmcc group released callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpReleased(PFN_MTCIMCMCCSESSXCB pfnCb);

/**
 * @brief Set the cmcc group calceled callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpCanceled(PFN_MTCIMCMCCSESSCB pfnCb);

/**
 * @brief Set the cmcc group leave successfully callback.
 * The callback is one of @ref Mtc_ImCmccGrpLeave results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpLeaveOk(PFN_MTCIMCMCCSESSCB pfnCb); 

/**
 * @brief Set the cmcc group leave failed callback.
 * The callback is one of @ref Mtc_ImCmccGrpLeave results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpLeaveFailed(PFN_MTCIMCMCCSESSXCB pfnCb); 

/**
 * @brief Set the cmcc group dissolve successfully callback.
 * The callback is one of @ref Mtc_ImCmccGrpDissolve results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpDissolveOk(PFN_MTCIMCMCCSESSCB pfnCb); 

/**
 * @brief Set the cmcc group dissolve failed callback.
 * The callback is one of @ref Mtc_ImCmccGrpDissolve results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpDissolveFailed(PFN_MTCIMCMCCSESSXCB pfnCb);

/**
 * @brief Set the cmcc group add participant successfully callback.
 * The callback is one of @ref Mtc_ImCmccGrpAddPartp, Mtc_ImCmccGrpAddPartpU results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpPartpAddOk(PFN_MTCIMCMCCRFERCB pfnCb); 

/**
 * @brief Set the cmcc group add participant failed callback.
 * The callback is one of @ref Mtc_ImCmccGrpAddPartp, Mtc_ImCmccGrpAddPartpU results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpPartpAddFailed(PFN_MTCIMCMCCRFERXCB pfnCb); 

/**
 * @brief Set the cmcc group expel participant successfully callback.
 * The callback is one of @ref Mtc_ImCmccGrpEplPartp, Mtc_ImCmccGrpEplPartpU results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpPartpEplOk(PFN_MTCIMCMCCRFERCB pfnCb); 

/**
 * @brief Set the cmcc group expel participant failed callback.
 * The callback is one of @ref Mtc_ImCmccGrpEplPartp, Mtc_ImCmccGrpEplPartpU results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpPartpEplFailed(PFN_MTCIMCMCCRFERXCB pfnCb); 

/**
 * @brief Set the cmcc group chairman modify successfully callback.
 * The callback is one of @ref Mtc_ImCmccGrpMdfyChairMan results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpChairManMdfyOk(PFN_MTCIMCMCCRFERCB pfnCb);

/**
 * @brief Set the cmcc group chairman modify failed callback.
 * The callback is one of @ref Mtc_ImCmccGrpMdfyChairMan results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpChairManMdfyFailed(PFN_MTCIMCMCCRFERXCB pfnCb);

/**
 * @brief Set the cmcc group own display name modify successfully callback.
 * The callback is one of @ref Mtc_ImCmccGrpMdfyDispName results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpDispNameMdfyOk(PFN_MTCIMCMCCRFERCB pfnCb);

/**
 * @brief Set the cmcc group own display name modify failed callback.
 * The callback is one of @ref Mtc_ImCmccGrpMdfyDispName results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpDispNameMdfyFailed(PFN_MTCIMCMCCRFERXCB pfnCb);

/**
 * @brief Set the cmcc group received a group information update callback.
 * The callback will be notified if user received cmcc group information(by pager).
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpInfoUpdate(PFN_MTCIMCMCCGINFO pfnCb);

/**
 * @brief Set the cmcc group received a pager new message callback.
 * The callback will be notified if user received a new message.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpPMsgRecvMsg(PFN_MTCIMCMCCMSGCB pfnCb); 

/**
 * @brief Set the cmcc group send one pager message successfully callback.
 * The callback is one of @ref Mtc_ImCmccGrpPMsgSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpPMsgSendOk(PFN_MTCIMCMCCMSGCB pfnCb); 

/**
 * @brief Set the cmcc group send one pager message failed callback.
 * The callback is one of @ref Mtc_ImCmccGrpPMsgSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetCmccGrpPMsgSendFailed(PFN_MTCIMCMCCMSGXCB pfnCb); 

/**
 * @brief Set group operation via http join face2face group iconwall ok callback.
 * The callback will be notified if join face2face group iconwall ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGhJoinIconWallOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set group operation via http join face2face group iconwall failed callback.
 * The callback will be notified if join face2face group iconwall failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGhJoinIconWallFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

/**
 * @brief Set group operation via http quit face2face group iconwall ok callback.
 * The callback will be notified if quit face2face group iconwall ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGhQuitIconWallOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set group operation via http quit face2face group iconwall failed callback.
 * The callback will be notified if quit face2face group iconwall failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGhQuitIconWallFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

/**
 * @brief Set group operation via http join face2face group ok callback.
 * The callback will be notified if join face2face group ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGhJoinGrpOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set group operation via http join face2face group failed callback.
 * The callback will be notified if join face2face group failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGhJoinGrpFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_GRP_CB_H__ */

