/************************************************************************

        Copyright (c) 2005-2014 by Juphoon System Software, Inc.
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
  File name     : mtc_cprof_cb.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2014-09-25
  Description   :
      Function implement required by MTC CMCC profile callback.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CPROF_CB_H__
#define _MTC_CPROF_CB_H__

/**
 * @file mtc_cprof_cb.h
 * @brief MTC CMCC profile Callback Interface Functions
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC cmcc profile callback for notify load ok. */
typedef ZVOID (*PFN_MTCCPROFSCBLOADOK)(ZFUNC_VOID);

/** @brief Type define of MTC cmcc profile callback for notify load failed. */
typedef ZVOID (*PFN_MTCCPROFSCBLOADFAILED)(ZUINT iStatCode);

/** @brief Type define of MTC cmcc profile callback for notify load qr card pcc ok. */
typedef ZVOID (*PFN_MTCCPROFSCBXLOADOK)(ZUINT iObjId);

/** @brief Type define of MTC cmcc profile callback for notify load qr card pcc failed. */
typedef ZVOID (*PFN_MTCCPROFSCBXLOADFAILED)(ZUINT iObjId, ZUINT iStatCode);

/**
 * @brief Set the OMA cmcc profile load all pcc successfully callback.
 * The callback is one of @ref Mtc_CprofPccLoadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccAllLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load all pcc failed callback.
 * The callback is one of @ref Mtc_CprofPccLoadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccAllLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload all pcc successfully callback.
 * The callback is one of @ref Mtc_CprofPccUploadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccAllUploadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload all pcc failed callback.
 * The callback is one of @ref Mtc_CprofPccUploadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccAllUploadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc name successfully callback.
 * The callback is one of @ref Mtc_CprofPccLoadName results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccNameLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc name failed callback.
 * The callback is one of @ref Mtc_CprofPccLoadName results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccNameLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc name successfully callback.
 * The callback is one of @ref Mtc_CprofPccUploadName results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccNameUploadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc name failed callback.
 * The callback is one of @ref Mtc_CprofPccUploadName results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccNameUploadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc address successfully callback.
 * The callback is one of @ref Mtc_CprofPccLoadAddr results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccAddrLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc address failed callback.
 * The callback is one of @ref Mtc_CprofPccLoadAddr results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccAddrLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc address successfully callback.
 * The callback is one of @ref Mtc_CprofPccUploadAddr results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccAddrUploadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc address failed callback.
 * The callback is one of @ref Mtc_CprofPccUploadAddr results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccAddrUploadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc comm-addr successfully callback.
 * The callback is one of @ref Mtc_CprofPccLoadCommAddr results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccCommAddrLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc comm-addr failed callback.
 * The callback is one of @ref Mtc_CprofPccLoadCommAddr results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccCommAddrLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc comm-addr successfully callback.
 * The callback is one of @ref Mtc_CprofPccUploadCommAddr results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccCommAddrUploadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc comm-addr failed callback.
 * The callback is one of @ref Mtc_CprofPccUploadCommAddr results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccCommAddrUploadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc birth successfully callback.
 * The callback is one of @ref Mtc_CprofPccLoadBirth results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccBirthLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc birth failed callback.
 * The callback is one of @ref Mtc_CprofPccLoadBirth results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccBirthLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc birth successfully callback.
 * The callback is one of @ref Mtc_CprofPccUploadBirth results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccBirthUploadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc birth failed callback.
 * The callback is one of @ref Mtc_CprofPccUploadBirth results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccBirthUploadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc career successfully callback.
 * The callback is one of @ref Mtc_CprofPccLoadCareer results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccCareerLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc career failed callback.
 * The callback is one of @ref Mtc_CprofPccLoadCareer results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccCareerLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc career successfully callback.
 * The callback is one of @ref Mtc_CprofPccUploadCareer results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccCareerUploadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc career failed callback.
 * The callback is one of @ref Mtc_CprofPccUploadCareer results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccCareerUploadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc icon successfully callback.
 * The callback is one of @ref Mtc_CprofPccLoadIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccIconLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load pcc icon failed callback.
 * The callback is one of @ref Mtc_CprofPccLoadIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccIconLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc icon successfully callback.
 * The callback is one of @ref Mtc_CprofPccUploadIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccIconUploadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload pcc icon failed callback.
 * The callback is one of @ref Mtc_CprofPccUploadIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetPccIconUploadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load all qr card successfully callback.
 * The callback is one of @ref Mtc_CprofQrCardLoadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardAllLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load all qr card failed callback.
 * The callback is one of @ref Mtc_CprofQrCardLoadAll results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardAllLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load qr card flag successfully callback.
 * The callback is one of @ref Mtc_CprofQrCardLoadFlag results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardFlagLoadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load qr card flag failed callback.
 * The callback is one of @ref Mtc_CprofQrCardLoadFlag results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardFlagLoadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload qr card flag successfully callback.
 * The callback is one of @ref Mtc_CprofQrCardUploadFlag results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardFlagUploadOk(PFN_MTCCPROFSCBLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile set upload qr card flag failed callback.
 * The callback is one of @ref Mtc_CprofQrCardUploadFlag results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardFlagUploadFailed(PFN_MTCCPROFSCBLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load qr card pcc successfully callback.
 * The callback is one of @ref Mtc_CprofQrCardLoadPcc results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardPccLoadOk(PFN_MTCCPROFSCBXLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load qr card pcc failed callback.
 * The callback is one of @ref Mtc_CprofQrCardLoadPcc results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardPccLoadFailed(PFN_MTCCPROFSCBXLOADFAILED pfnCb);

/**
 * @brief Set the OMA cmcc profile load qr card pcc icon successfully callback.
 * The callback is one of @ref Mtc_CprofQrCardLoadPccIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardPccIconLoadOk(PFN_MTCCPROFSCBXLOADOK pfnCb);

/**
 * @brief Set the OMA cmcc profile load qr card pcc icon failed callback.
 * The callback is one of @ref Mtc_CprofQrCardLoadPccIcon results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CprofCbSetQrCardPccIconLoadFailed(PFN_MTCCPROFSCBXLOADFAILED pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CPROF_CB_H__ */

