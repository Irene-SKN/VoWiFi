/************************************************************************

        Copyright (c) 2005-2015 by Juphoon System Software, Inc.
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
  File name     : mtc_gba_cb.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2015-04-29
  Description   :
    Macros and structure definitions required by the mtc gba callback.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_GBA_CB_H__
#define _MTC_GBA_CB_H__

/**
 * @file mtc_gba_cb.h
 * @brief MTC GBA Callback Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC GUI callback for notify GBA bootstrapping ok. */
typedef ZVOID (*PFN_MTCGBABOOTCB)(ZUINT iBootId, ZUINT iCookie);

/** @brief Type define of MTC GUI callback for notify GBA bootstrapping failed. */
typedef ZVOID (*PFN_MTCGBABOOTCBX)(ZUINT iBootId, ZUINT iCookie, ZUINT iStatCode);

/** @brief Type define of MTC GUI callback for notify authorization indication. */
typedef ZVOID (*PFN_MTCGBAAUTHIND)(ZUINT iCookie, ZCHAR *pcNonce);

/** @brief Type define of MTC GUI callback for notify GBA btid expired. */
typedef ZVOID (*PFN_MTCGBABTIDEXPIREDCB)(ZFUNC_VOID);

/**
 * @brief Set the gba bootstrapping successfully callback.
 * The callback is one of @ref Mtc_GbaBootStart results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GbaCbSetBootOk(PFN_MTCGBABOOTCB pfnCb);

/**
 * @brief Set the gba bootstrapping failed callback.
 * The callback is one of @ref Mtc_GbaBootStart results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GbaCbSetBootFailed(PFN_MTCGBABOOTCBX pfnCb);

/**
 * @brief Set the authorizaiton indication callback.
 * The callback will be notified if authorizaiton indication
 * The callback is one of @ref Mtc_GbaBootStart results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GbaCbSetAuthInd(PFN_MTCGBAAUTHIND pfnCb);

/**
 * @brief Set the btid expired callback.
 * The callback will be notified if btid expired
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GbaCbSetBtidExpired(PFN_MTCGBABTIDEXPIREDCB pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_GBA_CB_H__ */

