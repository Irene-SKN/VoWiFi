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
  File name     : mtc_pa_cb.h
  Module        : multimedia talk client
  Author        : nero.fang
  Created on    : 2014-09-30
  Description   :
    Marcos and structure definitions required by the mtc pa callback.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PA_CB_H__
#define _MTC_PA_CB_H__

/**
 * @file mtc_pa_cb.h
 * @brief MTC CMCC Public Account Callback Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC public account operation ok. */
typedef ZVOID (*PFN_MTCPACB)(ZUINT iSessId);

/** @brief Type define of MTC public account operation failed. */
typedef ZVOID (*PFN_MTCPACBX)(ZUINT iSessId, ZUINT iStatCode);

/**
 * @brief Set the public account add subscribe successfully callback.
 * The callback is one of @ref Mtc_PaSessAddSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaAddSubsOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account add subscribe failed callback.
 * The callback is one of @ref Mtc_PaSessAddSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaAddSubsFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account cancel subscribe successfully callback.
 * The callback is one of @ref Mtc_PaSessCancelSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaCancelSubsOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the publia account cancel subscribe failed callback.
 * The callback is one of @ref Mtc_PaSessCancelSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaCancelSubsFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account query user subscribed successfully callback.
 * The callback is one of @ref Mtc_PaSessQryUsrSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaQryUsrSubsOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account query user subscribed failed callback.
 * The callback is one of @ref Mtc_PaSessQryUsrSubs results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaQryUsrSubsFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account get public list successfully callback.
 * The callback is one of @ref Mtc_PaSessGetPubLst results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPubLstOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account get public list failed callback.
 * The callback is one of @ref Mtc_PaSessGetPubLst results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPubLstFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account get public list recommend successfully callback.
 * The callback is one of @ref Mtc_PaSessGetPubLstRecmd results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPubLstRecmdOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account get public list recommend failed callback.
 * The callback is one of @ref Mtc_PaSessGetPubLstRecmd results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPubLstRecmdFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account get public detail successfully callback.
 * The callback is one of @ref Mtc_PaSessGetPubDetail results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPubDetailOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account get public detail failed callback.
 * The callback is one of @ref Mtc_PaSessGetPubDetail results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPubDetailFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account get public menu successfully callback.
 * The callback is one of @ref Mtc_PaSessGetPubMenu results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPubMenuOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account get public menu failed callback.
 * The callback is one of @ref Mtc_PaSessGetPubMenu results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPubMenuFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account get previous message successfully callback.
 * The callback is one of @ref Mtc_PaSessGetPrevMsg results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPrevMsgOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account get previous message failed callback.
 * The callback is one of @ref Mtc_PaSessGetPrevMsg results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaGetPrevMsgFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account complain public successfully callback.
 * The callback is one of @ref Mtc_PaSessComplainPub results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaComplainPubOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account complain public failed callback.
 * The callback is one of @ref Mtc_PaSessComplainPub results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaComplainPubFailed(PFN_MTCPACBX pfnCb);

/**
 * @brief Set the public account set accept status successfully callback.
 * The callback is one of @ref Mtc_PaSessSetAcptStat results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaSetAcptStatOk(PFN_MTCPACB pfnCb);

/**
 * @brief Set the public account set accept status failed callback.
 * The callback is one of @ref Mtc_PaSessSetAcptStat results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_PaCbSetPaSetAcptStatFailed(PFN_MTCPACBX pfnCb);

#ifdef __cplusplus
}
#endif

#endif

