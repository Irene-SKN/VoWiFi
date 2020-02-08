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
  File name     : mtc_cp.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2012-08-11
  Description   :
      Data structure and function declare required by MTC client provisoning.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CP_H__
#define _MTC_CP_H__

/**
 * @file mtc_cp.h
 * @brief MTC Client Provisioning Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC cp status code(error no or terminated code). */
#define MTC_CP_STAT_ERR_NO              (MTC_EBASE_CP + 0)  /**< @brief no error */
#define MTC_CP_STAT_ERR_TIMEOUT         (MTC_EBASE_CP + 1)  /**< @brief connect timeout */
#define MTC_CP_STAT_ERR_NETWORK         (MTC_EBASE_CP + 2)  /**< @brief network error */
#define MTC_CP_STAT_ERR_FORBIDDEN       (MTC_EBASE_CP + 3)  /**< @brief request forbidden */
#define MTC_CP_STAT_ERR_INTERNAL_ERR    (MTC_EBASE_CP + 4)  /**< @brief server internal error. */
#define MTC_CP_STAT_ERR_INCORRET_XML    (MTC_EBASE_CP + 5)  /**< @brief incorret configuration xml. */
#define MTC_CP_STAT_ERR_DISABLED_TEMP   (MTC_EBASE_CP + 6)  /**< @brief service disabled temporarily. */
#define MTC_CP_STAT_ERR_DISABLED_PERM   (MTC_EBASE_CP + 7)  /**< @brief service disabled permanently. */
#define MTC_CP_STAT_ERR_DECLINE         (MTC_EBASE_CP + 8)  /**< @brief user decline */
#define MTC_CP_STAT_ERR_INVALID_OTP     (MTC_EBASE_CP + 9)  /**< @brief invalid otp */
#define MTC_CP_STAT_ERR_INVALID_TOKEN   (MTC_EBASE_CP + 10) /**< @brief invalid token */
#define MTC_CP_STAT_ERR_INVALID_NUMBER  (MTC_EBASE_CP + 11) /**< @brief invalid number */
#define MTC_CP_STAT_ERR_RETRY_AFTER     (MTC_EBASE_CP + 12) /**< @brief retry after */
#define MTC_CP_STAT_ERR_BOSS_ERROR      (MTC_EBASE_CP + 13) /**< @brief BOSS error */
#define MTC_CP_STAT_ERR_NO_WHITE_USER   (MTC_EBASE_CP + 14) /**< @brief no white user */
#define MTC_CP_STAT_ERR_BOSS_TIMEOUT    (MTC_EBASE_CP + 15) /**< @brief BOSS timeout */
#define MTC_CP_STAT_ERR_PROMPT_TIMEOUT  (MTC_EBASE_CP + 16) /**< @brief prompt timeout */
#define MTC_CP_STAT_ERR_HAS_BODY        (MTC_EBASE_CP + 17) /**< @brief first HTTP_RSP_200_OK has body */
#define MTC_CP_STAT_ERR_301_EXCEED_LIMIT (MTC_EBASE_CP + 18) /**< @brief receive 301 times exceed the limit */
#define MTC_CP_STAT_ERR_INVALID_VERS    (MTC_EBASE_CP + 19) /**< @brief invalid version */
#define MTC_CP_STAT_ERR_DISA_C_REENABLE (MTC_EBASE_CP + 20) /**< @brief service disabled can reenable */
#define MTC_CP_STAT_ERR_IN_DORMANT      (MTC_EBASE_CP + 21) /**< @brief client in dormant state */
#define MTC_CP_STAT_ERR_OTHER           (MTC_EBASE_CP + 200)/**< @brief other error */

/** @brief MTC Client Provisioning Action Type */
typedef enum EN_MTC_CP_ACT_TYPE
{
    EN_MTC_CP_ACT_ACPT,                 /**< @brief Client provisioning accept action */
    EN_MTC_CP_ACT_DECL,                 /**< @brief Client provisioning decline action */
} EN_MTC_CP_ACT_TYPE;

/** @brief MTC Client Provisioning Network Type */
typedef enum EN_MTC_CP_NET_TYPE
{
    EN_MTC_CP_NET_UNKNOWN,              /**< @brief unknown network */
    EN_MTC_CP_NET_PS,                   /**< @brief PS network */
    EN_MTC_CP_NET_WIFI,                 /**< @brief WIFI network */
} EN_MTC_CP_NET_TYPE;

/** @brief MTC Client Provisioning Expire Type */
typedef enum EN_MTC_CP_EXPIRE_TYPE
{
    EN_MTC_CP_EXPIRE_VER,               /**< @brief version expire */
    EN_MTC_CP_EXPIRE_TOKEN              /**< @brief token expire */
} EN_MTC_CP_EXPIRE_TYPE;

/**
 * @brief MTC Cilent provisioning configure by primary device.
 * Sending request mesaage to RCS configuration server.
 * Request will be sent by HTTP and HTTPS MESSAGE method.
 *
 * While client provisioning ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpOk.
 *
 * While client provisioning failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpFailed.
 *
 * While client provisioning receive message only if no working configuration was avaliable before, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpRecvMsg.
 *
 * While client provisioning take place over non-3GPP accsess, 
 * and MSISDN is unavailable or IMSI is not accessible, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpPromptMSISDN.
 *
 * While client provisioning take place over non-3GPP accsess,
 * and client not support SMS UDH procedure, server will send a standard SMS with OTP to client, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpPromptOTP.
 *
 * @param [in] iNetType The network type, @ref EN_MTC_CP_NET_TYPE.
 * @param [in] pcToken The unified authentication token, used when network type is EN_MTC_CP_NET_WIFI.
 *
 * @return The cp id successfully or ZMAXUINT failed, client provisioning will be running.
 */
ZFUNC ZUINT Mtc_Cp(ZUINT iNetType, ZCHAR *pcToken);

/**
 * @brief MTC Cilent provisioning configure by primary device.
 * Sending request mesaage to RCS configuration server.
 * Request will be sent by HTTP and HTTPS MESSAGE method.
 *
 * While client provisioning ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpOk.
 *
 * While client provisioning failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpFailed.
 *
 * While client provisioning receive message only if no working configuration was avaliable before, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpRecvMsg.
 *
 * While client provisioning take place over non-3GPP accsess, 
 * and MSISDN is unavailable or IMSI is not accessible, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpPromptMSISDN.
 *
 * While client provisioning take place over non-3GPP accsess,
 * and client not support SMS UDH procedure, server will send a standard SMS with OTP to client, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpPromptOTP.
 *
 * @param [in] iNetType The network type, @ref EN_MTC_CP_NET_TYPE.
 * @param [in] pcToken The unified authentication token, used when network type is EN_MTC_CP_NET_WIFI.
 * @param [in] iTimes The times of invoking the function.
 *
 * @return The cp id successfully or ZMAXUINT failed, client provisioning will be running.
 */
ZFUNC ZUINT Mtc_CpX(ZUINT iNetType, ZCHAR *pcToken, ZUINT iTimes);

/**
 * @brief MTC Cilent provisioning reconfigure by primary device.
 * Sending request mesaage to RCS configuration server.
 * Request will be sent by HTTP and HTTPS MESSAGE method.
 *
 * While client provisioning ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpOk.
 *
 * While client provisioning failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpFailed.
 *
 * While client provisioning receive message only if no working configuration was avaliable before, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpRecvMsg.
 *
 * While client provisioning take place over non-3GPP accsess, 
 * and MSISDN is unavailable or IMSI is not accessible, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpPromptMSISDN.
 *
 * While client provisioning take place over non-3GPP accsess,
 * and client not support SMS UDH procedure, server will send a standard SMS with OTP to client, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpPromptOTP.
 *
 * @param [in] iNetType The network type, @ref EN_MTC_CP_NET_TYPE.
 *
 * @return The cp id successfully or ZMAXUINT failed, client provisioning will be running.
 */
ZFUNC ZUINT Mtc_CpReCfg(ZUINT iNetType);

/**
 * @brief MTC Cilent provisioning action.
 *
 * @param [in] iCpId The cp id.
 * @param [in] iActType The action type, @ref EN_MTC_CP_ACT_TYPE.
 *    
 * @retval ZOK enabling cilent provisioning successfully. 
 * @retval ZFAILED enabling cilent provisioning failed.
 */
ZFUNC ZINT Mtc_CpAct(ZUINT iCpId, ZUINT iActType);

/**
 * @brief MTC Cilent provisioning validate SMS.
 *
 * @param [in] pcSMS The SMS received from configure server.
 *
 * While validate ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpCfgInd or @ref Mtc_CpCbSetCpReCfgInd,
 * then GUI must logout client if registered, 
 * and invoke @ref Mtc_Cp or @ref Mtc_CpReCfg.
 *    
 * @retval ZOK validate successfully. 
 * @retval ZFAILED validate failed.
 */
ZFUNC ZINT Mtc_CpValidSMS(ZCHAR *pcSMS);

/**
 * @brief MTC Cilent provisioning prompt for MSISDN by primary device.
 *
 * @param [in] iCpId The cp id.
 * @param [in] pcMsisdn The MSISDN.
 *    
 * @retval ZOK operation successfully. 
 * @retval ZFAILED operation failed.
 */
ZFUNC ZINT Mtc_CpPromptMSISDN(ZUINT iCpId, ZCHAR *pcMsisdn);

/**
 * @brief MTC Cilent provisioning prompt for OTP by primary device.
 *
 * @param [in] iCpId The cp id.
 * @param [in] pcOTP The one-time password.
 *    
 * @retval ZOK operation successfully. 
 * @retval ZFAILED operation failed.
 */
ZFUNC ZINT Mtc_CpPromptOTP(ZUINT iCpId, ZCHAR *pcOTP);

/**
 * @brief MTC Cilent provisioning prompt for token by primary device.
 *
 * @param [in] iCpId The cp id.
 * @param [in] pcToken The unified authentication token.
 *    
 * @retval ZOK operation successfully. 
 * @retval ZFAILED operation failed.
 */
ZFUNC ZINT Mtc_CpPromptToken(ZUINT iCpId, ZCHAR *pcToken);

/**
 * @brief MTC Cilent provisioning end user confirmation request action by primary device.
 *
 * @param [in] iMsgId The msg id.
 * @param [in] iActType @ref EN_MTC_CP_ACT_TYPE.
 * @param [in] pcPIN The personal identification number.
 *    
 * @retval ZOK operation successfully. 
 * @retval ZFAILED operation failed.
 */
ZFUNC ZINT Mtc_CpEUCRAct(ZUINT iMsgId, ZUINT iActType, ZCHAR *pcPIN);

/**
 * @brief MTC Cilent provisioning by additional device.
 * Sending request mesaage to RCS configuration server.
 * Request will be sent by HTTP and HTTPS MESSAGE method.
 *
 * While client provisioning ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpOk.
 *
 * While client provisioning failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpFailed.
 *
 * While client provisioning receive message only if no working configuration was avaliable before, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpRecvMsg.
 *
 * While client provisioning take place and the Service Provider use sending a standard SMS 
 * to primary user to confirm the identity of the user, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpPromptOTPSMS.
 *
 * While client provisioning take place and the Service Provider use the 
 * End User Confirmation Request instead of SMS to confirm the identity of the user 
 * and the primary user have an option to enter a PIN, if entered, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpPromptOTPPIN.
 *
 * @return The cp id successfully or ZMAXUINT failed, client provisioning will be running.
 */
ZFUNC ZUINT Mtc_CpAD(ZFUNC_VOID);

/**
 * @brief MTC Cilent provisioning by additional device with OTP.
 * Sending request mesaage to RCS configuration server.
 * Request will be sent by HTTP and HTTPS MESSAGE method.
 *
 * While client provisioning ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpOk.
 *
 * While client provisioning failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CpCbSetCpFailed.
 *
 * While client provisioning receive message only if no working configuration was avaliable before, 
 * GUI will be notified by callback which was set by @ref Mtc_CpCbSetCpRecvMsg.
 *
 * @return The cp id successfully or ZMAXUINT failed, client provisioning will be running.
 */
ZFUNC ZUINT Mtc_CpADWithOTP(ZCHAR *pcOTP);

/**
 * @brief MTC Cilent provisioning prompt for OTP by additional device.
 *
 * @param [in] iCpId The cp id.
 * @param [in] pcOTP The one-time password.
 *    
 * @retval ZOK prompt successfully. 
 * @retval ZFAILED prompt failed.
 */
ZFUNC ZINT Mtc_CpADPromptOTP(ZUINT iCpId, ZCHAR *pcOTP);

/**
 * @brief MTC Cilent provisioning prompt for PIN by additional device.
 *
 * @param [in] iCpId The cp id.
 * @param [in] pcPIN The personal identification number.
 *    
 * @retval ZOK prompt successfully. 
 * @retval ZFAILED prompt failed.
 */
ZFUNC ZINT Mtc_CpADPromptPIN(ZUINT iCpId, ZCHAR *pcPIN);

/**
 * @brief MTC Cilent provisioning get retry time len.
 *
 * @param [in] iCpId The cp id.
 *    
 * @retval ZOK get retry time len.
 */
ZFUNC ZINT Mtc_CpGetRetryTimeLen(ZUINT iCpId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CP_H__ */

