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
  File name     : mtc_cli_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
    Macros and structure definitions required by the mtc client callback.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CLI_CB_H__
#define _MTC_CLI_CB_H__

/**
 * @file mtc_cli_cb.h
 * @brief MTC Client Callback Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC client callback. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLICB)(ZFUNC_VOID);
#else
typedef ZINT (*PFN_MTCCLICB)(ZFUNC_VOID);
#endif

/** 
 * @brief Type define of MTC client callback for post print message.
 * @param pcStr is the print string.
 */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLIPRINT)(ZCHAR *pcStr);
#else
typedef ZINT (*PFN_MTCCLIPRINT)(ZCHAR *pcStr);
#endif

/** 
 * @brief Type define of MTC client callback for post event to MTC user. *
 * @param zEvntId is point to the event.
 */
 #if (ZPLATFORM == ZPLATFORM_WIN32)
 typedef ZINT (__stdcall *PFN_MTCCLIEVNT)(ZEVNT zEvntId);
 #else
typedef ZINT (*PFN_MTCCLIEVNT)(ZEVNT zEvntId);
#endif

/** 
* @brief Type define of MTC GUI callback for notify REGISTER failed.
* @param dwStatCode is register failed status code(see @ref MTC_CLI_ERR_LCL_FAILED).
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLIREGFAILED)(ZUINT iStatCode);
#else
typedef ZINT (*PFN_MTCCLIREGFAILED)(ZUINT iStatCode);
#endif

/** 
* @brief Type define of MTC GUI callback for notify authorization failed.
* @param iAuthType is authorization type(see @ref EN_MTC_IMS_AUTH_TYPE).
* @param pcNonce is used when authorization type is EN_MTC_IMS_AUTH_IMS_AKA.
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLIAUTHIND)(ZUINT iAuthType, ZUINT iRegId,
                ZCHAR *pcNonce);
#else
typedef ZINT (*PFN_MTCCLIAUTHIND)(ZUINT iAuthType, ZUINT iRegId,
                ZCHAR *pcNonce);
#endif

/** @brief Type define of MTC GUI callback for notify server login ok. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLISERVLOGINOK)(ZFUNC_VOID);
#else
typedef ZINT (*PFN_MTCCLISERVLOGINOK)(ZFUNC_VOID);
#endif

/** @brief Type define of MTC GUI callback for notify local login ok. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLILCLLOGINOK)(ZFUNC_VOID);
#else
typedef ZINT (*PFN_MTCCLILCLLOGINOK)(ZFUNC_VOID);
#endif

/** 
* @brief Type define of MTC GUI callback for notify login failed.
* @param iStatCode is login failed status code.
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLILOGINFAILED)(ZUINT iStatCode);
#else
typedef ZINT (*PFN_MTCCLILOGINFAILED)(ZUINT iStatCode);
#endif

/** 
* @brief Type define of MTC GUI callback for notify refresh ok.
* @param bActive indicate if it is a user action results.
* @param bChanged indicate if the registration information changed.
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLIREFRESHOK)(ZBOOL bActive, ZBOOL bChanged);
#else
typedef ZINT (*PFN_MTCCLIREFRESHOK)(ZBOOL bActive, ZBOOL bChanged);
#endif

/** 
* @brief Type define of MTC GUI callback for notify refresh failed.
* @param bActive indicate if it is a user action results.
* @param iStatCode is refresh failed status code.
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLIREFRESHFAILED)(ZBOOL bActive, ZUINT iStatCode);
#else
typedef ZINT (*PFN_MTCCLIREFRESHFAILED)(ZBOOL bActive, ZUINT iStatCode);
#endif

/** @brief Type define of MTC GUI callback for notify local logout. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLILCLLOGOUT)(ZFUNC_VOID);
#else
typedef ZINT (*PFN_MTCCLILCLLOGOUT)(ZFUNC_VOID);
#endif

/** 
* @brief Type define of MTC GUI callback for notify server  logout.
* @param bActive indicate if it is a user action results.
* @param iStatCode is event type which trigger logout(see @ref MTC_CLI_ERR_LCL_FAILED).
* @param iExpires is expire time value if server notify logout later.
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZINT (__stdcall *PFN_MTCCLISERVLOGOUT)(ZBOOL bActive, ZUINT iStatCode,
                ZUINT iExpires);
#else
typedef ZINT (*PFN_MTCCLISERVLOGOUT)(ZBOOL bActive, ZUINT iStatCode,
                ZUINT iExpires);
#endif

/** 
* @brief Type define of MTC GUI callback for notify network changed.
* @param iNetType is access network type(see @ref MTC_ANET_UNAVAILABLE...).
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCLISUBNETCHANGED)(ZUINT iNetType);
#else
typedef ZVOID (*PFN_MTCCLISUBNETCHANGED)(ZUINT iNetType);
#endif

/** 
* @brief Type define of MTC GUI callback for notify register state changed.
* @param iRegStat is register state type(see @ref MTC_REG_STATE_IDLE).
* @param iStatCode is changed reason(see @ref MTC_CLI_ERR_LCL_FAILED).
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCLIREGSTATCHANGED)(ZUINT iRegStat, ZUINT iStatCode);
#else
typedef ZVOID (*PFN_MTCCLIREGSTATCHANGED)(ZUINT iRegStat, ZUINT iStatCode);
#endif

/** 
* @brief Type define of MTC GUI callback for notify before login.
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCLIBEFORELOGIN)(ZFUNC_VOID);
#else
typedef ZVOID (*PFN_MTCCLIBEFORELOGIN)(ZFUNC_VOID);
#endif

/**
 * @brief Set the Zos_Printf string print callback.
 * Zos print and log functions will always call it if callback is not ZNULL.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CliCbSetPrint(PFN_MTCCLIPRINT pfnCb);

/**
 * @brief Set the service event callback to MTC driver owner.
 * If MTC is running multi-thread mode, MTC and service enablers
 * need be drived by MTC user(mostly is GUI), so MTC will call this callback
 * for convey event to MTC user, MTC user should post event to itself.
 * MTC user then call @ref Mtc_CliDrive for run MTC and service enablers.
 * 
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CliCbSetEvnt(PFN_MTCCLIEVNT pfnCb);

/**
 * @brief Set the REGISETER successfully indication callback.
 * The callback will be notified if REGISETER successfully
 * The callback is one of @ref Mtc_CliLogin results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_CliCbSetRegOk(PFN_MTCCLICB pfnCb);   

/**
 * @brief Set the REGISETER failed indication callback.
 * The callback will be notified if REGISETER failed
 * The callback is one of @ref Mtc_CliLogin results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_CliCbSetRegFailed(PFN_MTCCLIREGFAILED pfnCb);   

/**
 * @brief Set the authorizaiton indication callback.
 * The callback will be notified if authorizaiton indication
 * The callback is one of @ref Mtc_CliLogin results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_CliCbSetAuthInd(PFN_MTCCLIAUTHIND pfnCb);

/**
 * @brief Set the login successfully indication callback.
 * The callback will be notified if server login successfully
 * The callback is one of @ref Mtc_CliLogin results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_CliCbSetServLoginOk(PFN_MTCCLISERVLOGINOK pfnCb);   

/**
 * @brief Set the login successfully indication callback.
 * The callback will be notified if local login successfully
 * The callback is one of @ref Mtc_CliLogin results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_CliCbSetLclLoginOk(PFN_MTCCLILCLLOGINOK pfnCb);   

/**
 * @brief Set the login failed indication callback.
 * The callback will be notified if login failed
 * The callback is one of @ref Mtc_CliLogin results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_CliCbSetLoginFailed(PFN_MTCCLILOGINFAILED pfnCb);   

/**
 * @brief Set the refresh successfully indication callback.
 * The callback will be notified if refresh successfully
 * The callback is one of @ref Mtc_CliRefresh results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_CliCbSetRefreshOk(PFN_MTCCLIREFRESHOK pfnCb);   

/**
 * @brief Set the refresh indication callback.
 * The callback will be notified if refresh failed
 * The callback is one of @ref Mtc_CliRefresh results
 *
 * @param [in] pfnCb Callback function.
 *
 */
ZFUNC ZVOID Mtc_CliCbSetRefreshFailed(PFN_MTCCLIREFRESHFAILED pfnCb);   

/**
 * @brief Set the local logout indication callback.
 * The callback will be notified if client is not in register with server.
 * If @ref Mtc_CliDbGetUserReg is ZTRUE, this callback will not be called.
 * 
 * The callback is one of @ref Mtc_CliLogout results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CliCbSetLclLogout(PFN_MTCCLILCLLOGOUT pfnCb);   

/**
 * @brief Set the server logout indication callback.
 * The callback will be notified if client has un-register from server.
 * If @ref Mtc_CliDbGetUserReg is ZFALSE, this callback will not be called.
 * 
 * The callback is one of @ref Mtc_CliLogout results
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CliCbSetServLogout(PFN_MTCCLISERVLOGOUT pfnCb);   

/**
 * @brief Set subscribe network changed indication callback.
 * The callback will be notified if network has changed
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CliCbSetSubNetChanged(PFN_MTCCLISUBNETCHANGED pfnCb);

/**
 * @brief Set register state changed indication callback.
 * The callback will be notified if register state has changed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CliCbSetRegStatChanged(PFN_MTCCLIREGSTATCHANGED pfnCb);

/**
 * @brief Set before login indication callback.
 * The callback will be notified before login
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CliCbSetBeforeLogin (PFN_MTCCLIBEFORELOGIN pfnCb);


#ifdef __cplusplus
}
#endif

#endif /* _MTC_CLI_CB_H__ */

