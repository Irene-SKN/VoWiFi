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
  File name     : mtc_prof_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC profile DB

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PROF_DB_H__
#define _MTC_PROF_DB_H__

/**
 * @file mtc_prof_db.h
 * @brief MTC Profile Database Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get application version from database.
 *
 * @return Application version.
 *
 * @see @ref Mtc_ProfDbSetAppVer
 */
ZFUNC ZCHAR * Mtc_ProfDbGetAppVer(ZFUNC_VOID);

/**
 * @brief Set application version from database.
 *
 * @param [in] pcAppVer The application version.
 *
 * @retval ZOK Set application version successfully.
 * @retval ZFAILED Set application version failed.
 *
 * @see @ref Mtc_ProfDbGetAppVer
 */
ZFUNC ZINT Mtc_ProfDbSetAppVer(ZCONST ZCHAR *pcAppVer);

/**
 * @brief Get remember password option from database.
 *
 * @retval ZTRUE Remember password.
 * @retval ZFALSE Do not remember password.
 *
 * @see @ref Mtc_ProfDbSetRemPwd
 */
ZFUNC ZBOOL Mtc_ProfDbGetRemPwd(ZFUNC_VOID);

/**
 * @brief Set remember password option.
 *
 * @param [in] bRember The option of remembering password.
 *
 * @retval ZOK Set remember password option successfully.
 * @retval ZFAILED Set remember password option failed.
 *
 * @see @ref Mtc_ProfDbGetRemPwd
 */
ZFUNC ZINT Mtc_ProfDbSetRemPwd(ZBOOL bRember);

/**
 * @brief Get the user automatically login option from database.
 *
 * @retval ZTRUE User will automatically login.
 * @retval ZFALSE User will not automatically login.
 *
 * @see @ref Mtc_ProfDbSetAutoLogin
*/
ZFUNC ZBOOL Mtc_ProfDbGetAutoLogin(ZFUNC_VOID);

/**
 * @brief Set the user automatically login option.
 *
 * @param [in] bAuto User automatically login option.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option option failed.
 *
 * @see @ref Mtc_ProfDbGetAutoLogin
 */
ZFUNC ZINT Mtc_ProfDbSetAutoLogin(ZBOOL bAuto);

/**
 * @brief Get avatar file name.
 *
 * @return The string of avatar file name.
 *
 * @see @ref Mtc_ProfDbSetAvatarFile
 */
ZFUNC ZCHAR * Mtc_ProfDbGetAvatarFile(ZFUNC_VOID);

/**
 * @brief Set avatar file name.
 *
 * @param [in] pcFileName Avatar file name.
 *
 * @retval ZOK Set avatar file name successfully.
 * @retval ZFAILED Set avatar file name failed.
 *
 * @see @ref Mtc_ProfDbGetAvatarFile
 */
ZFUNC ZINT Mtc_ProfDbSetAvatarFile(ZCHAR *pcFileName);

/**
 * @brief Get country code.
 *
 * @return The string of country code.
 *
 * @see @ref Mtc_ProfDbSetCountryCode
 */
ZFUNC ZCHAR * Mtc_ProfDbGetCountryCode(ZFUNC_VOID);

/**
 * @brief Set country code.
 *
 * @param [in] pcCountryCode Country code.
 *
 * @retval ZOK Set country code successfully.
 * @retval ZFAILED Set country code failed.
 *
 * @see @ref Mtc_ProfDbGetCountryCode
 */
ZFUNC ZINT Mtc_ProfDbSetCountryCode(ZCHAR *pcCountryCode);

/**
 * @brief Get area code.
 *
 * @return The string of area code.
 *
 * @see @ref Mtc_ProfDbSetAreaCode
 */
ZFUNC ZCHAR * Mtc_ProfDbGetAreaCode(ZFUNC_VOID);

/**
 * @brief Set area code.
 *
 * @param [in] pcAreaCode Country code.
 *
 * @retval ZOK Set area code successfully.
 * @retval ZFAILED Set area code failed.
 *
 * @see @ref Mtc_ProfDbGetAreaCode
 */
ZFUNC ZINT Mtc_ProfDbSetAreaCode(ZCHAR *pcAreaCode);

/**
 * @brief Get the client provisioning enable from database.
 *
 * @retval ZTRUE Start client provisioning.
 * @retval ZFALSE Do not start client provisioning.
 *
 * @see @ref Mtc_ProfDbSetCpEnable
*/
ZFUNC ZBOOL Mtc_ProfDbGetCpEnable();

/**
 * @brief Set client provisioning enable.
 *
 * @param [in] bCpEnable The client provisioning option.
 *
 * @retval ZOK Set the client provisioning option successfully.
 * @retval ZFAILED Set the client provisioning option failed.
 *
 * @see @ref Mtc_ProfDbGetCpEnable
 */
ZFUNC ZINT Mtc_ProfDbSetCpEnable(ZBOOL bCpEnable);

/**
 * @brief Get extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [out] ppcParm The parameter value.
 *
 * @retval ZOK get extension parameter successfully.
 * @retval ZFAILED get extension parameter failed, 
 *                 the extension parameter is not exist.
 *
 * @see @ref Mtc_ProfDbSetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbGetExtnParm(ZCHAR *pcName, ZCHAR **ppcParm);

/**
 * @brief Get extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [out] pbParm The parameter value.
 *
 * @retval ZOK get extension parameter successfully.
 * @retval ZFAILED get extension parameter failed, 
 *                 the extension parameter is not exist.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbGetExtnParmBool(ZCHAR *pcName, ZBOOL *pbParm);

/**
 * @brief Get extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [out] piParm The parameter value.
 *
 * @retval ZOK get extension parameter successfully.
 * @retval ZFAILED get extension parameter failed, 
 *                 the extension parameter is not exist.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbGetExtnParmInt(ZCHAR *pcName, ZINT *piParm);

/**
 * @brief Get extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [out] piParm The parameter value.
 *
 * @retval ZOK get extension parameter successfully.
 * @retval ZFAILED get extension parameter failed, 
 *                 the extension parameter is not exist.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbGetExtnParmUint(ZCHAR *pcName, ZUINT *piParm);

/**
 * @brief Get extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] iIndex The parameter index.
 *
 * @return The parameter value when get extension parameter successfully, 
 *              otherwise return empty string.
 *
 * @see @ref Mtc_ProfDbSetExtnParm
 */
ZFUNC ZCHAR * Mtc_ProfDbGetExtnParmX(ZCHAR *pcName, ZINT iIndex);

/**
 * @brief Get extension parameter.
 *
 * @param [in] pcName The parameter name.
 *
 * @retval ZOK Get the parameter count successfully.
 * @retval ZFAILED Get the parameter count failed.
 *
 * @see @ref Mtc_ProfDbSetExtnParm
 */
ZFUNC ZUINT Mtc_ProfDbGetExtnParmCount(ZCHAR *pcName);

/**
 * @brief Set extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] pcVal The parameter value.
 *
 * @retval ZOK Set the parameter successfully.
 * @retval ZFAILED Set the parameter failed.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbSetExtnParm(ZCHAR *pcName, ZCHAR *pcVal);

/**
 * @brief Set extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] bVal The parameter value.
 *
 * @retval ZOK Set the parameter successfully.
 * @retval ZFAILED Set the parameter failed.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbSetExtnParmBool(ZCHAR *pcName, ZBOOL bVal);

/**
 * @brief Set extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] iVal The parameter value.
 *
 * @retval ZOK Set the parameter successfully.
 * @retval ZFAILED Set the parameter failed.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbSetExtnParmInt(ZCHAR *pcName, ZINT iVal);

/**
 * @brief Set extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] iVal The parameter value.
 *
 * @retval ZOK Set the parameter successfully.
 * @retval ZFAILED Set the parameter failed.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbSetExtnParmUint(ZCHAR *pcName, ZUINT iVal);

/**
 * @brief Add extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] pcVal The parameter value.
 *
 * @retval ZOK Add the parameter successfully.
 * @retval ZFAILED Add the parameter failed.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbAddExtnParm(ZCHAR *pcName, ZCHAR *pcVal);

/**
 * @brief Add extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] wNameLen The parameter name length.
 * @param [in] pcVal The parameter value.
 * @param [in] wValLen The parameter value length.
 *
 * @retval ZOK Add the parameter successfully.
 * @retval ZFAILED Add the parameter failed.
 *
 * @see @ref Mtc_ProfDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProfDbAddExtnParmN(ZCHAR *pcName, ZUSHORT wNameLen,
                ZCHAR *pcVal, ZUSHORT wValLen);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PROF_DB_H__ */

