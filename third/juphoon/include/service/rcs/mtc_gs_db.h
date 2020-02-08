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
  File name     : mtc_gs_db.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2013-03-14
  Description   :
      Data structure and function declare required by MTC geolocation share database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_GS_DB_H__
#define _MTC_GS_DB_H__

/**
 * @file mtc_gs_db.h
 * @brief MTC Geolocation Share Database Interface Functions.
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC geolocation share pull service type */
typedef enum EN_MTC_GS_PULL_TYPE
{
    EN_MTC_GS_PULL_NONE,                /**< @brief disable pull service */
    EN_MTC_GS_PULL_LBS_ONLY,            /**< @brief pull with only LBS technology */
    EN_MTC_GS_PULL_FT_ONLY,             /**< @brief pull with only FT technology */
    EN_MTC_GS_PULL_LBS_PRIORITY,        /**< @brief pull both technologies with priority to LBS */
    EN_MTC_GS_PULL_FT_PRIORITY,         /**< @brief pull both technologies with priority to FT */
} EN_MTC_GS_PULL_TYPE;

/** @brief MTC geolocation share media protocol type */
typedef enum EN_MTC_GS_PROTO_TYPE
{
    EN_MTC_GS_PROTO_MSRP_TCP,           /**< @brief MSRP over TCP */
    EN_MTC_GS_PROTO_MSRP_TLS,           /**< @brief MSRP over TLS */
} EN_MTC_GS_PROTO_TYPE;


/** @brief MTC geolocation share allowed SMS type */
typedef enum EN_MTC_GS_ALLOWED_SMS_TYPE
{
    EN_MTC_GS_ALLOWED_SMS_SERVER,          /* server allowed SMS */    
    EN_MTC_GS_ALLOWED_SMS_YES,             /* terminal allowed SMS */
    EN_MTC_GS_ALLOWED_SMS_NO,              /* terminal not allowed SMS */
} EN_MTC_GS_ALLOWED_SMS_TYPE;

/**
 * @brief Get push service enable.
 *
 * @return The push service enable.
 *
 * @see @ref Mtc_GsDbSetPushEnable
 */
ZFUNC ZBOOL Mtc_GsDbGetPushEnable(ZFUNC_VOID);

/**
 * @brief Get pull service type.
 *
 * @return The pull service type, @see @ref EN_MTC_GS_PULL_TYPE.
 *
 * @see @ref Mtc_GsDbSetPullType
 */
ZFUNC ZUINT Mtc_GsDbGetPullType(ZFUNC_VOID);

/**
 * @brief Get pull pull open flag.
 *
 * @return The pull open flag, 
 *   if ZTRUE indicate PULL service can be used to attempt to obtain non-RCS users' location.
 *
 * @see @ref Mtc_GsDbSetPullOpen
 */
ZFUNC ZBOOL Mtc_GsDbGetPullOpen(ZFUNC_VOID);

/**
 * @brief Get location information max valid time.
 *
 * @return Location information max valid time.
 */
ZFUNC ZUINT Mtc_GsDbGetLocInfoMaxValidTime(ZFUNC_VOID);

/**
 * @brief Get pull block timer length.
 *
 * @return The pull block timer length.
 *
 * @see @ref Mtc_GsDbSetBlockTimer
 */
ZFUNC ZUINT Mtc_GsDbGetBlockTimer(ZFUNC_VOID);

/**
 * @brief Get text max length.
 *
 * @return The text max length.
 */
ZFUNC ZUINT Mtc_GsDbGetTxtMaxLen(ZFUNC_VOID);

/**
 * @brief Get OneAPI host.
 *
 * @return The OneAPI host.
 *
 * @see @ref Mtc_GsDbSetOneApiHost
 */
ZFUNC ZCHAR * Mtc_GsDbGetOneApiHost(ZFUNC_VOID);

/**
 * @brief Get OneAPI host port.
 *
 * @return The OneAPI host port.
 *
 * @see @ref Mtc_GsDbSetOneApiPort
 */
ZFUNC ZSHORT Mtc_GsDbGetOneApiPort(ZFUNC_VOID);

/**
 * @brief Get OneAPI root.
 *
 * @return The OneAPI root.
 *
 * @see @ref Mtc_GsDbSetOneApiRoot
 */
ZFUNC ZCHAR * Mtc_GsDbGetOneApiRoot(ZFUNC_VOID);

/**
 * @brief Get OneAPI version.
 *
 * @return The OneAPI version.
 *
 * @see @ref Mtc_GsDbSetOneApiVers
 */
ZFUNC ZCHAR * Mtc_GsDbGetOneApiVers(ZFUNC_VOID);

/**
 * @brief Get address of the H-SLP.
 *
 * @return The address of the H-SLP.
 */
ZFUNC ZCHAR * Mtc_GsDbGetHslpAddr(ZFUNC_VOID);

/**
 * @brief Get address type of the H-SLP.
 *
 * @return The address type of the H-SLP.
 */
ZFUNC ZCHAR * Mtc_GsDbGetHslpAddrType(ZFUNC_VOID);

/**
 * @brief Get media protocal type, @see @ref EN_MTC_GS_PROTO_TYPE.
 *
 * @return The media protocal type.
 *
 * @see @ref Mtc_GsDbSetMediaProtoType
 */
ZFUNC ZUINT Mtc_GsDbGetMediaProtoType(ZFUNC_VOID);

/**
 * @brief Set push service enable.
 *
 * @param [in] bEnable The push service enable.
 *
 * @retval ZOK Set push service enable successfully.
 * @retval ZFAILED Set push service enable failed.
 *
 * @see @ref Mtc_GsDbGetPushEnable
 */
ZFUNC ZINT Mtc_GsDbSetPushEnable(ZBOOL bEnable);

/**
 * @brief Set pull service type.
 *
 * @param [in] iType The pull service type, @see @ref EN_MTC_GS_PULL_TYPE.
 *
 * @retval ZOK Set pull service type successfully.
 * @retval ZFAILED Set pull service type failed.
 *
 * @see @ref Mtc_GsDbGetPullType
 */
ZFUNC ZINT Mtc_GsDbSetPullType(ZUINT iType);

/**
 * @brief Set pull open flag.
 *
 * @param [in] bOpen The pull open flag.
 *
 * @retval ZOK Set pull open flag successfully.
 * @retval ZFAILED Set pull open flag failed.
 *
 * @see @ref Mtc_GsDbGetPullOpen
 */
ZFUNC ZINT Mtc_GsDbSetPullOpen(ZBOOL bOpen);

/**
 * @brief Set pull block timer length.
 *
 * @param [in] iBlockTimerLen The pull block timer length.
 *
 * @retval ZOK Set pull block timer length successfully.
 * @retval ZFAILED Set pull block timer length failed.
 *
 * @see @ref Mtc_GsDbGetBlockTimer
 */
ZFUNC ZINT Mtc_GsDbSetBlockTimer(ZUINT iBlockTimerLen);

/**
 * @brief Set OneAPI host.
 *
 * @param [in] pcHost The OneAPI host.
 *
 * @retval ZOK Set OneAPI host successfully.
 * @retval ZFAILED Set OneAPI host failed.
 *
 * @see @ref Mtc_GsDbGetOneApiHost
 */
ZFUNC ZINT Mtc_GsDbSetOneApiHost(ZCHAR *pcHost);

/**
 * @brief Set OneAPI host port.
 *
 * @param [in] wPort The OneAPI host port.
 *
 * @retval ZOK Set OneAPI host port successfully.
 * @retval ZFAILED Set OneAPI host port failed.
 *
 * @see @ref Mtc_GsDbGetOneApiPort
 */
ZFUNC ZINT Mtc_GsDbSetOneApiPort(ZSHORT wPort);

/**
 * @brief Set OneAPI root.
 *
 * @param [in] pcRoot The OneAPI root.
 *
 * @retval ZOK Set OneAPI root successfully.
 * @retval ZFAILED Set OneAPI root failed.
 *
 * @see @ref Mtc_GsDbGetOneApiRoot
 */
ZFUNC ZINT Mtc_GsDbSetOneApiRoot(ZCHAR *pcRoot);

/**
 * @brief Set OneAPI version.
 *
 * @param [in] pcVer The OneAPI version.
 *
 * @retval ZOK Set OneAPI version successfully.
 * @retval ZFAILED Set OneAPI version failed.
 *
 * @see @ref Mtc_GsDbGetOneApiVers
 */
ZFUNC ZINT Mtc_GsDbSetOneApiVers(ZCHAR *pcVer);

/**
 * @brief Set media protocol type.
 *
 * @param [in] iType The media protocol type, @see @ref EN_MTC_GS_PROTO_TYPE.
 *
 * @retval ZOK Set media protocol type successfully.
 * @retval ZFAILED Set media protocol type failed.
 *
 * @see @ref Mtc_GsDbGetMediaProtoType
 */
ZFUNC ZINT Mtc_GsDbSetMediaProtoType(ZUINT iType);

/**
 * @brief Set allowed sms type.
 *
 * @param [in] iAllowedSmsType the allowed sms type, @see @ref EN_MTC_GS_ALLOWED_SMS_TYPE.
 *
 * @retval ZOK Set allowed sms type successfully.
 * @retval ZFAILED Set allowed sms type failed.
 *
 * @see @ref Mtc_GsDbGetAllowedSmsType.
 */
ZFUNC ZINT Mtc_GsDbSetAllowedSmsType(ZUINT iAllowedSmsType);

/**
 * @brief Get allowed sms type.
 *
 * @return allowed sms type.
 *
 * @see @ref Mtc_GsDbSetAllowedSmsType.
 */
ZFUNC ZUINT Mtc_GsDbGetAllowedSmsType();

#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_GS_DB_H__ */

