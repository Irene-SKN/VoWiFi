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
  File name     : mtc_cap_cb.h
  Module        : multimedia talk client
  Author        : logan.huang
  Created on    : 2012-02-20
  Description   :
      Data structure and function declare required by MTC 
      capability query callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CAP_CB_H__
#define _MTC_CAP_CB_H__

/**
 * @file mtc_cap_cb.h
 * @brief MTC Capability Qurey Callback Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC capability ok callback. */
typedef ZINT (*PFN_MTCCAPOKCB)(ZCHAR *pcUri, ZCOOKIE zCookie, 
                ZUINT iCapType);

/** @brief Type define of MTC capability failed callback,
    status code see @ref EN_MTC_CAP_NO_ERR*/
typedef ZINT (*PFN_MTCCAPFAILEDCB)(ZCHAR *pcUri, ZCOOKIE zCookie, 
                ZUINT iStatCode);

/** @brief Type define of MTC capability update callback. */
typedef ZINT (*PFN_MTCCAPUPDATECB)(ZCHAR *pcUri, ZUINT iCapType);

/** @brief Type define of MTC capability option callback. */
typedef ZINT (*PFN_MTCCAPOPTCB)(ZCHAR *pcUri, ZCOOKIE zCookie, 
                ZUINT iCapType, ZUINT iCapOpt);

/** 
 * @brief MTC capability query ok callback.
 * 
 * @param [in] pfnCb The callback will be notify capability query ok.
 * 
 * @retval ZOK successfully.
 * @retval ZFAILED failed.
 */
ZFUNC ZVOID Mtc_CapCbSetCapQOk(PFN_MTCCAPOKCB pfnCb);

/** 
 * @brief MTC capability query failed callback.
 * 
 * @param [in] pfnCb The callback will be notify capability query failed.
 * 
 * @retval ZOK successfully.
 * @retval ZFAILED failed.
 */
ZFUNC ZVOID Mtc_CapCbSetCapQFailed(PFN_MTCCAPFAILEDCB pfnCb);

/** 
 * @brief MTC capability query update callback.
 * 
 * @param [in] pfnCb The callback will be notify capability query ok.
 * 
 * @retval ZOK successfully.
 * @retval ZFAILED failed.
 */
ZFUNC ZVOID Mtc_CapCbSetCapUpdate(PFN_MTCCAPUPDATECB pfnCb);

/** 
 * @brief MTC capability option query callback.
 * 
 * @param [in] pfnCb The callback will be notify capability opton query ok.
 * 
 * @retval ZOK successfully.
 * @retval ZFAILED failed.
 */
ZFUNC ZVOID Mtc_CapCbSetCapOptOk(PFN_MTCCAPOPTCB pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CAP_CB_H__ */

