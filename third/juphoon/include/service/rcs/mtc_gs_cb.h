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
  File name     : mtc_gs_cb.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2013-02-05
  Description   :
      Data structure and function declare required by MTC geolocation share callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_GS_CB_H__
#define _MTC_GS_CB_H__

/**
 * @file mtc_gs_cb.h
 * @brief MTC Geolocation Share Callback Interface Functions
 *
 * This file includes geolocation share callback interface function. Those function
 * is used to manage geolocation information.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC GS geolocation information push operation ok. */
typedef ZVOID (*PFN_MTCGSGINFOPUSHCB)(ZUINT iGInfoId);

/** @brief Type define of MTC GS geolocation information push operation failed. */
typedef ZVOID (*PFN_MTCGSGINFOPUSHXCB)(ZUINT iGInfoId, ZUINT iStatCode);

/**
 * @brief Set the gs push information receive invitation callback.
 * The callback will be notified if user receiving push information invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPushGInfoRecvIvt(PFN_MTCGSGINFOPUSHCB pfnCb);

/**
 * @brief Set the gs push information share ok callback.
 * The callback is one of @ref Mtc_GsGInfoPushText results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPushGInfoShareOk(PFN_MTCGSGINFOPUSHCB pfnCb);

/**
 * @brief Set the gs push information share failed callback.
 * The callback is one of @ref Mtc_GsGInfoPushText results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPushGInfoShareFailed(PFN_MTCGSGINFOPUSHXCB pfnCb);

/**
 * @brief Set the gs push information released callback.
 * The callback is one of @ref Mtc_GsGInfoPushText results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPushGInfoReleased(PFN_MTCGSGINFOPUSHXCB pfnCb);

/**
 * @brief Set the gs push information receive done callback.
 * The callback will be notified if user received a geolocation information.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPushGInfoRecvDone(PFN_MTCGSGINFOPUSHCB pfnCb);

/**
 * @brief Set the gs pull information receive invitation callback.
 * The callback will be notified if user receiving pull information invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPullGInfoRecvIvt(PFN_MTCGSGINFOPUSHCB pfnCb);

/**
 * @brief Set the gs pull information share ok callback.
 * The callback is one of @ref Mtc_GsGInfoPullViaFt results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPullGInfoShareOk(PFN_MTCGSGINFOPUSHCB pfnCb);

/**
 * @brief Set the gs pull information share failed callback.
 * The callback is one of @ref Mtc_GsGInfoPullViaFt results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPullGInfoShareFailed(PFN_MTCGSGINFOPUSHXCB pfnCb);

/**
 * @brief Set the gs pull information share blocked callback.
 * The callback is one of @ref Mtc_GsGInfoPullViaFt results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_GsCbSetPullGInfoShareBlocked(PFN_MTCGSGINFOPUSHCB pfnCb);

/* mtc set the fetch information ok callback. */
ZFUNC ZVOID Mtc_GsCbSetFetchGInfoOk(PFN_MTCGSGINFOPUSHCB pfnCb);

/* mtc set the fetch information failed callback. */
ZFUNC ZVOID Mtc_GsCbSetFetchGInfoFailed(PFN_MTCGSGINFOPUSHXCB pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_GS_CB_H__ */

