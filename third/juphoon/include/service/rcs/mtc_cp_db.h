/************************************************************************

        Copyright (c) 2005-2012 by Juphoon System Software, Inc.
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
  File name     : mtc_cp_db.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2012-08-11
  Description   :
      Data structure and function declare required by MTC client provisioning database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CP_DB_H__
#define _MTC_CP_DB_H__

/**
 * @file mtc_cp_db.h
 * @brief MTC Client Provisioning Database Interface Functions.
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get client provisioning database get version.
 *
 * @return The client provisioning version.
*/
ZFUNC ZINT Mtc_CpDbGetVer(ZFUNC_VOID);

/**
 * @brief Get client provisioning database get version timestamp.
 *
 * @return The client provisioning version timestamp.
*/
ZFUNC ZTIME_T Mtc_CpDbGetVerTimestamp(ZFUNC_VOID);

/**
 * @brief Get the token from database.
 *
 * @return The string of token.
*/
ZFUNC ZCHAR * Mtc_CpDbGetToken(ZFUNC_VOID);

/**
 * @brief Get the sip uri from database.
 *
 * @return The string of country code.
 *
 * @see @ref Mtc_CpDbSetCc
*/
ZFUNC ZCHAR * Mtc_CpDbGetCc(ZFUNC_VOID);

/**
 * @brief Get the MSISDN from database.
 *
 * @return The string of MSISDN.
 *
 * @see @ref Mtc_CpDbSetMsisdn
*/
ZFUNC ZCHAR * Mtc_CpDbGetMsisdn(ZFUNC_VOID);

/**
 * @brief Get the sip uri from database.
 *
 * @return The string of sip uri.
 *
 * @see @ref Mtc_CpDbSetSipUri
*/
ZFUNC ZCHAR * Mtc_CpDbGetSipUri(ZFUNC_VOID);

/**
 * @brief Get the IMSI from database.
 *
 * @return The string of IMSI.
 *
 * @see @ref Mtc_CpDbSetImsi
*/
ZFUNC ZCHAR * Mtc_CpDbGetImsi(ZFUNC_VOID);

/**
 * @brief Get the server address from database.
 *
 * @return The string of server address.
 *
 * @see @ref Mtc_CpDbSetSrvAddr
*/
ZFUNC ZCHAR * Mtc_CpDbGetSrvAddr(ZFUNC_VOID);

/**
 * @brief Get the service root from database.
 *
 * @return The string of service root.
 *
 * @see @ref Mtc_CpDbSetSrvRoot
*/
ZFUNC ZCHAR * Mtc_CpDbGetSrvRoot(ZFUNC_VOID);

/**
 * @brief Get the support pgw header completion flag from database.
 *
 * @return The support flag.
 *
 * @see @ref Mtc_CpDbSetSuptHdrCmpl
*/
ZFUNC ZBOOL Mtc_CpDbGetSuptHdrCmpl(ZFUNC_VOID);

/**
 * @brief Get the length of wait cp timer from database.
 *
 * @return The timer wait cp len.
 *
 * @see @ref Mtc_CpDbSetTmrLenWaitCp
*/
ZFUNC ZUINT Mtc_CpDbGetTmrLenWaitCp(ZFUNC_VOID);

/**
 * @brief Get the length of wait prompt timer from database.
 *
 * @return The timer wait prompt len.
 *
 * @see @ref Mtc_CpDbSetTmrLenWaitPt
*/
ZFUNC ZUINT Mtc_CpDbGetTmrLenWaitPt(ZFUNC_VOID);

/**
 * @brief Get validity time from database.
 *
 * @return The validity time.
 *
 * @see @ref Mtc_CpDbSetVerValidTime
*/
ZFUNC ZINT Mtc_CpDbGetVerValidTime(ZFUNC_VOID);

/**
 * @brief Set version.
 *
 * @param [in] iVer Version.
 *
 * @retval ZOK Set version successfully.
 * @retval ZFAILED Set version failed.
 *
 * @see @ref Mtc_CpDbGetVer
 */
ZFUNC ZINT Mtc_CpDbSetVer(ZINT iVer);

/**
 * @brief Set version timestamp.
 *
 * @param [in] iVerTimestamp version timestamp.
 *
 * @retval ZOK Set version timestamp successfully.
 * @retval ZFAILED Set version timestamp failed.
 *
 * @see @ref Mtc_CpDbGetVerTimestamp
 */
ZFUNC ZINT Mtc_CpDbSetVerTimestamp(ZINT iVerTimestamp);

/**
 * @brief Set token.
 *
 * @param [in] pcToken Token string.
 *
 * @retval ZOK Set token successfully.
 * @retval ZFAILED Set token failed.
 *
 * @see @ref Mtc_CpDbGetToken
 */
ZFUNC ZINT Mtc_CpDbSetToken(ZCHAR *pcToken);

/**
 * @brief Set country code.
 *
 * @param [in] pcCountryCode Country code string.
 *
 * @retval ZOK Set country code successfully.
 * @retval ZFAILED Set country code failed.
 *
 * @see @ref Mtc_CpDbGetCc
 */
ZFUNC ZINT Mtc_CpDbSetCc(ZCHAR *pcCountryCode);

/**
 * @brief Set MSISDN.
 *
 * @param [in] pcMsisdn MSISDN string.
 *
 * @retval ZOK Set MSISDN successfully.
 * @retval ZFAILED Set MSISDN failed.
 *
 * @see @ref Mtc_CpDbGetMsisdn
 */
ZFUNC ZINT Mtc_CpDbSetMsisdn(ZCHAR *pcMsisdn);

/**
 * @brief Set sip uri.
 *
 * @param [in] pcSipUri sip uri string.
 *
 * @retval ZOK Set sip uri successfully.
 * @retval ZFAILED Set sip uri failed.
 *
 * @see @ref Mtc_CpDbGetSipUri
 */
ZFUNC ZINT Mtc_CpDbSetSipUri(ZCHAR *pcSipUri);

/**
 * @brief Set IMSI.
 *
 * @param [in] pcImsi IMSI string.
 *
 * @retval ZOK Set IMSI successfully.
 * @retval ZFAILED Set IMSI failed.
 *
 * @see @ref Mtc_CpDbGetImsi
 */
ZFUNC ZINT Mtc_CpDbSetImsi(ZCHAR *pcImsi);

/**
 * @brief Set server address.
 *
 * @param [in] pcSrvAddr server address string.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CpDbGetSrvAddr
 */
ZFUNC ZINT Mtc_CpDbSetSrvAddr(ZCHAR *pcSrvAddr);

/**
 * @brief Set service root.
 *
 * @param [in] pcSrvRoot service root string.
 *
 * @retval ZOK Set service root successfully.
 * @retval ZFAILED Set service root failed.
 *
 * @see @ref Mtc_CpDbGetSrvRoot
 */
ZFUNC ZINT Mtc_CpDbSetSrvRoot(ZCHAR *pcSrvRoot);

/**
 * @brief Set support pgw header completion flag.
 *
 * @param [in] bFlag support pgw header completion flag.
 *
 * @retval ZOK Set support flag successfully.
 * @retval ZFAILED Set support flag failed.
 *
 * @see @ref Mtc_CpDbGetSuptHdrCmpl
 */
ZFUNC ZINT Mtc_CpDbSetSuptHdrCmpl(ZBOOL bFlag);

/**
 * @brief Set wait cp timer length.
 *
 * @param [in] iTmrLen the timer length.
 *
 * @retval ZOK Set timer length successfully.
 *
 * @see @ref Mtc_CpDbGetTmrLenWaitCp
 */
ZFUNC ZINT Mtc_CpDbSetTmrLenWaitCp(ZUINT iTmrLen);

/**
 * @brief Set wait prompt timer length.
 *
 * @param [in] iTmrLen the timer length.
 *
 * @retval ZOK Set timer length successfully.
 *
 * @see @ref Mtc_CpDbGetTmrLenWaitPt
 */
ZFUNC ZINT Mtc_CpDbSetTmrLenWaitPt(ZUINT iTmrLen);

/**
 * @brief Set validity time.
 *
 * @param [in] iTime the validity time.
 *
 * @retval ZOK Set timer length successfully.
 *
 * @see @ref Mtc_CpDbGetVerValidTime
 */
ZFUNC ZINT Mtc_CpDbSetVerValidTime(ZINT iTime);

/**
 * @brief Get client provisioning database get tls port.
 *
 * @return The client provisioning tls port.
*/
ZFUNC ZUINT Mtc_CliDbGetCpTlsPort(ZFUNC_VOID);

/**
 * @brief Set cp tls port.
 *
 * @param [in] iPort The tls port.
 *
 * @retval ZOK Set tls port successfully.
 * @retval ZFAILED Set tls port failed.
 *
 * @see @ref Mtc_CliDbGetCpTlsPort
 */
ZFUNC ZINT Mtc_CliDbSetCpTlsPort(ZUINT iPort);

#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_CP_DB_H__ */

