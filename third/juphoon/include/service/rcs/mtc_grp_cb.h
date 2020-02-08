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
  File name     : mtc_grp_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by MTC OMA pre-arranged group callback.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_GRP_CB_H__
#define _MTC_GRP_CB_H__

/**
 * @file mtc_grp_cb.h
 * @brief MTC OMA Pre-Arranged GRP Callback Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC group set callback for notify load all group ok. */
typedef ZINT (*PFN_MTCGRPSCBLOADALLOK)(ZFUNC_VOID);

/** @brief Type define of MTC group set callback for notify load all group failed. */
typedef ZINT (*PFN_MTCGRPSCBLOADALLFAILED)(ZUINT iStatCode);

/** @brief Type define of MTC group callback for notify load all group ok. */
typedef ZINT (*PFN_MTCGRPSCBLOADOK)(ZUINT iId, ZCHAR *pcIdStr);

/** @brief Type define of MTC group callback for notify load all group failed. */
typedef ZINT (*PFN_MTCGRPSCBLOADFAILED)(ZCHAR *pcIdStr, ZUINT iStatCode);

/** @brief Type define of MTC group callback for notify group add ok. */
typedef ZINT (*PFN_MTCGRPSCBADDOK)(ZUINT iId, ZCHAR *pcIdStr);

/** @brief Type define of MTC group callback for notify group add failed. */
typedef ZINT (*PFN_MTCGRPSCBADDFAILED)(ZCHAR *pcIdStr, ZUINT iStatCode);

/** @brief Type define of MTC group callback for notify group remove ok. */
typedef ZINT (*PFN_MTCGRPSCBRMVOK)(ZCHAR *pcIdStr);

/** @brief Type define of MTC group callback for notify group remove failed. */
typedef ZINT (*PFN_MTCGRPSCBRMVFAILED)(ZUINT iId, ZCHAR *pcIdStr, 
                ZUINT iStatCode);

/** @brief Type define of MTC group callback for notify group entry add ok. */
typedef ZINT (*PFN_MTCGRPENTRYCBADDOK)(ZUINT iEntryId, ZUINT iGrpId, 
                ZCHAR *pcIdStr);

/** @brief Type define of MTC group callback for notify group entry add failed. */
typedef ZINT (*PFN_MTCGRPENTRYCBADDFAILED)(ZCHAR *pcIdStr, ZUINT iGrpId, 
                ZUINT iStatCode);

/** @brief Type define of MTC group callback for notify group remove ok. */
typedef ZINT (*PFN_MTCGRPENTRYCBRMVOK)(ZCHAR *pcIdStr, ZUINT iGrpId);

/** @brief Type define of MTC group callback for notify group remove failed. */
typedef ZINT (*PFN_MTCGRPENTRYCBRMVFAILED)(ZUINT iEntryId, ZUINT iGrpId, 
                ZCHAR *pcIdStr, ZUINT iStatCode);

/**
 * @brief Set the OMA pre-arranged group set load all groups successfully callback.
 * The callback is one of @ref Mtc_GrpsLoadAllGrp results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetLoadAllOk(PFN_MTCGRPSCBLOADALLOK pfnCb);

/**
 * @brief Set the OMA pre-arranged group set load failed callback.
 * The callback is one of @ref Mtc_GrpsLoadAllGrp results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetLoadAllFailed(PFN_MTCGRPSCBLOADALLFAILED pfnCb);

/**
 * @brief Set the OMA pre-arranged group load successfully callback.
 * The callback is one of @ref Mtc_GrpsLoadGrpU results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetLoadOk(PFN_MTCGRPSCBLOADOK pfnCb);

/**
 * @brief Set the OMA pre-arranged group load failed callback.
 * The callback is one of @ref Mtc_GrpsLoadGrpU results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetLoadFailed(PFN_MTCGRPSCBLOADFAILED pfnCb);

/**
 * @brief Set the pre-arranged group added successfully callback.
 * The callback is one of @ref Mtc_GrpsAddGrp results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetGrpAddOk(PFN_MTCGRPSCBADDOK pfnCb);

/**
 * @brief Set the pre-arranged group added failed callback.
 * The callback is one of @ref Mtc_GrpsAddGrp results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetGrpAddFailed(PFN_MTCGRPSCBADDFAILED pfnCb);

/**
 * @brief Set the pre-arranged group removed successfully callback.
 * The callback is one of @ref Mtc_GrpsRmvGrp results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetGrpRmvOk(PFN_MTCGRPSCBRMVOK pfnCb);

/**
 * @brief Set the pre-arranged group removed failed callback.
 * The callback is one of @ref Mtc_GrpsRmvGrp results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetGrpRmvFailed(PFN_MTCGRPSCBRMVFAILED pfnCb);

/**
 * @brief Set the pre-arranged group entry added successfully callback.
 * The callback is one of @ref Mtc_GrpAddEntry results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetEntryAddOk(PFN_MTCGRPENTRYCBADDOK pfnCb);

/**
 * @brief Set the pre-arranged group entry added failed callback.
 * The callback is one of @ref Mtc_GrpAddEntry results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetEntryAddFailed(PFN_MTCGRPENTRYCBADDFAILED pfnCb);

/**
 * @brief Set the pre-arranged group entry removed successfully callback.
 * The callback is one of @ref Mtc_GrpRmvEntry results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetEntryRmvOk(PFN_MTCGRPENTRYCBRMVOK pfnCb);

/**
 * @brief Set the pre-arranged group entry removed failed callback.
 * The callback is one of @ref Mtc_GrpRmvEntry results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GrpCbSetEntryRmvFailed(PFN_MTCGRPENTRYCBRMVFAILED pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_GRP_CB_H__ */

