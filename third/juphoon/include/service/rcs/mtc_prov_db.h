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
  File name     : mtc_prov_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC provision database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PROV_DB_H__
#define _MTC_PROV_DB_H__

/**
 * @file mtc_prov_db.h
 * @brief MTC Provision Database Interface Functions.
 *
 * Provision Database contain client global configuration
 * beside account profile. For example, auto run client when PC startup.
 */
#ifdef __cplusplus
extern "C" {
#endif

#define MTC_PROV_TMNL_APP    "APP"
#define MTC_PROV_TMNL_PC     "PC"
#define MTC_PROV_TMNL_MAC    "MAC"
#define MTC_PROV_TMNL_PAD    "PAD"
#define MTC_PROV_TMNL_WEB    "WEB"
#define MTC_PROV_TMNL_NATIVE "NATIVE"

/** @brief mtc provision rcs version type */
typedef enum EN_MTC_PROV_RCS_VER_TYPE
{
    EN_MTC_PROV_RCS_VER_UNKNOWN,             /**< @brief unknown */
    EN_MTC_PROV_RCS_VER_5_1,                 /**< @brief rcs5.1_v1.0(5.1) */
    EN_MTC_PROV_RCS_VER_5_1_B,               /**< @brief rcs5.1_v2.0(5.1B) */
} EN_MTC_PROV_RCS_VER_TYPE;

/** @brief mtc provision rcs profile type */
typedef enum EN_MTC_PROV_RCS_PROF_TYPE
{
    EN_MTC_PROV_RCS_PROF_UNKNOWN,             /**< @brief unknown */
    EN_MTC_PROV_RCS_PROF_JOYN_BLACKBIRD,      /**< @brief joyn blackbird */
    EN_MTC_PROV_RCS_PROF_JOYN_HOTFIXES,       /**< @brief joyn hotfixes */
} EN_MTC_PROV_RCS_PROF_TYPE;

/** @brief mtc provision device type */
typedef enum EN_MTC_PROV_DEVICE_TYPE
{
    EN_MTC_PROV_DEVICE_TABLET,               /**< @brief tablet device type */
    EN_MTC_PROV_DEVICE_PC,                   /**< @brief pc device type */
    EN_MTC_PROV_DEVICE_OTHER,                /**< @brief other device type */
} EN_MTC_PROV_DEVICE_TYPE;

/** @brief mtc provision server template type */
typedef enum EN_MTC_PROV_SRV_TMPL_TYPE
{
    EN_MTC_PROV_SRV_TMPL_UNKNOWN,            /**< @brief unknown */
    EN_MTC_PROV_SRV_TMPL_LOCAL,              /**< @brief config.rcs.mncXXX.mccXXX.pub.3gppnetwork.org */
    EN_MTC_PROV_SRV_TMPL_GLOBAL,             /**< @brief global.config.rcs.mncXXX.mccXXX.pub.3gppnetwork.org */
    EN_MTC_PROV_SRV_TMPL_OTHER,              /**< @brief other */
} EN_MTC_PROV_SRV_TMPL_TYPE;

/**
 * @brief Flush provision into database.
 *
 * @retval ZOK Set the flush successfully.
 * @retval ZFAILED Set the flush failed.
 */
ZFUNC ZINT Mtc_ProvDbFlush(ZFUNC_VOID);

/**
 * @brief Get the automatically start on PC option from database.
 *
 * @return Automatically start on PC option.
 */
ZFUNC ZBOOL Mtc_ProvDbGetLoginOnPC(ZFUNC_VOID);

/**
 * @brief Get the using manual local IP option from database.
 *
 * @return Automatically start on PC option.
 */
ZFUNC ZBOOL Mtc_ProvDbGetManualIp(ZFUNC_VOID);

/**
 * @brief Get the GUI show debug window option from database.
 *
 * @return Show debug window option.
 */
ZFUNC ZBOOL Mtc_ProvDbGetGuiShowDbg(ZFUNC_VOID);

/**
 * @brief Get the MME dump debug option from database.
 *
 * @return MME dump debug option.
 */
ZFUNC ZBOOL Mtc_ProvDbGetMmeDumpDbg(ZFUNC_VOID);

/**
 * @brief Get the MME log level from database.
 *
 * @return MME log level number.
 */
ZFUNC ZUCHAR Mtc_ProvDbGetMmeLogLevel(ZFUNC_VOID);

/**
 * @brief Get the mvc record voice option from database.
 *
 * @return mvc record debug option.
 */
ZFUNC ZBOOL Mtc_ProvDbGetMvcRecVoice(ZFUNC_VOID);

/**
 * @brief Get the mvd record video option from database.
 *
 * @return mvd record debug option.
 */
ZFUNC ZBOOL Mtc_ProvDbGetMvdRecVideo(ZFUNC_VOID);

/**
 * @brief Get the mvd sync audio option from database.
 *
 * @return mvc record debug option.
 */
ZFUNC ZBOOL Mtc_ProvDbGetMvdSyncAudio(ZFUNC_VOID);

/**
 * @brief Get the current profile user from database.
 *
 * @return Current profile user.
 */
ZFUNC ZCHAR * Mtc_ProvDbGetCurProfUser(ZFUNC_VOID);

/**
 * @brief Get emergency server realm.
 *
 * The general emergency call flow is like below:
 * -# No any account has logined
 * -# initialize the client
 * -# Mtc_CliInit(profile director);
 * -# initialize callback functions
 * -# Mtc_CliCbSetPrint(print callback);
 * -# Mtc_CallCbSetAlerted(alerted callback);
 * -# Mtc_CallCbSetTalking(talking callback);
 * -# Mtc_CallCbSetTermed(terminated callback);
 * -# Mtc_CallCbSetError(error callback);
 * -# Open an null account Mtc_CliOpen(ZNULL)
 * -# Start client service Mtc_CliStart()
 * -# Get Emergency server info by @ref Mtc_ProvDbGetEmgAddr
 * -# Set local and server parameters:
 * @code
   Mtc_CliDbSetSipLclTcpPort(5060);
   Mtc_CliDbSetSipLclTcpPort(5060);
   Mtc_CliDbSetSipRegIp(pcProxyAddr);
   Mtc_CliDbSetSipRegPort(5060);
   Mtc_CliDbSetSipRegRealm(pcProxyRealm);
   Mtc_CliDbSetSipRegTpt(EN_MSP_TPT_UDP);
   Mtc_CliDbSetUserReg(ZTRUE);
   Mtc_CliDbSetAuthName("unknown");
   Mtc_CliDbSetAuthPass("unknown");
 * @endcode
 *
 * @return Default emergency server realm.
 */
ZFUNC ZCHAR * Mtc_ProvDbGetEmgRealm(ZFUNC_VOID);

/**
 * @brief Get the emergency server address from database.
 *
 * @return Default emergency server address.
 */
ZFUNC ZCHAR * Mtc_ProvDbGetEmgAddr(ZFUNC_VOID);

/**
 * @brief Get the default register realm from database.
 *
 * @return Default register realm.
 */
ZFUNC ZCHAR * Mtc_ProvDbGetDftRegRealm(ZFUNC_VOID);

/**
 * @brief Get the default proxy address from database.
 *
 * @return Default proxy address.
 */
ZFUNC ZCHAR * Mtc_ProvDbGetDftProxyAddr(ZFUNC_VOID);

/**
 * @brief Get the default authentication name in register realm from database.
 *
 * @return Default authentication name in realm.
 */
ZFUNC ZBOOL Mtc_ProvDbGetDftAuthNameInRealm(ZFUNC_VOID);

/**
 * @brief Get the default subscribe register event from database.
 *
 * @return Default subscribe register event.
 */
ZFUNC ZBOOL Mtc_ProvDbGetDftSubRegEvnt(ZFUNC_VOID);

/**
 * @brief Get the default DTMF type from database.
 *
 * @return Default DTMF type, see @ref EN_MTC_DB_DTMF_TYPE.
 */
ZFUNC ZUINT Mtc_ProvDbGetDftDtmfType(ZFUNC_VOID);

/**
 * @brief Get the default ring directory.
 *
 * @return Default ring directory.
 */
ZFUNC ZCHAR * Mtc_ProvDbGetDftRingDir(ZFUNC_VOID);

/**
 * @brief Get ring mute option.
 *
 * @retval ZTRUE Mute ring.
 * @retval ZFALSE Not to mute ring.
 *
 * @see Mtc_ProvDbSetRingMute
 */
ZFUNC ZBOOL Mtc_ProvDbGetRingMute(ZFUNC_VOID);

/**
 * @brief Set automatically start on PC option.
 *
 * @param [in] bEnable The boolean value.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option failed.
 *
 * @see @ref Mtc_ProvDbGetLoginOnPC
 */
ZFUNC ZINT Mtc_ProvDbSetLoginOnPC(ZBOOL bEnable);

/**
 * @brief Set using manual local IP option.
 *
 * @param [in] bEnable The boolean value.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option failed.
 *
 * @see @ref Mtc_ProvDbGetManualIp
 */
ZFUNC ZINT Mtc_ProvDbSetManualIp(ZBOOL bEnable);

/**
 * @brief Set MME dump information to file option.
 *
 * @param [in] bEnable The boolean value.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option failed.
 *
 * @see @ref Mtc_ProvDbGetMmeDumpDbg
 */
ZFUNC ZINT Mtc_ProvDbSetMmeDumpDbg(ZBOOL bEnable);

/**
 * @brief Set MME log level.
 *
 * @param [in] ucLevel Log level number, 0 is no log, bigger number for more log.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option failed.
 *
 * @see @ref Mtc_ProvDbGetMmeDumpDbg
 */
ZFUNC ZINT Mtc_ProvDbSetMmeLogLevel(ZUCHAR ucLevel);

/**
 * @brief Set current profile user.
 *
 * @param [in] pcUser The profile user name.
 *
 * @retval ZOK Set the profile user successfully.
 * @retval ZFAILED Set the profile user failed.
 *
 * @see @ref Mtc_ProvDbGetCurProfUser
 */
ZFUNC ZINT Mtc_ProvDbSetCurProfUser(ZCHAR *pcUser);

/**
 * @brief Set default ring directory.
 *
 * @param [in] pcDir The default ring directory.
 *
 * @retval ZOK Set the default ring directory successfully.
 * @retval ZFAILED Set the default ring directory failed.
 *
 * @see @ref Mtc_ProvDbGetDftRingDir
 */
ZFUNC ZINT Mtc_ProvDbSetDftRingDir(ZCHAR *pcDir);

/**
 * @brief Set ring mute option.
 *
 * @param [in] bMute ZTRUE to mute ring.
 *
 * @retval ZOK Set ring mute option successfully.
 * @retval ZFAILED Set ring mute option failed.
 *
 * @see @ref Mtc_ProvDbGetRingMute
 */
ZFUNC ZINT Mtc_ProvDbSetRingMute(ZBOOL bMute);

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
 * @see @ref Mtc_ProvDbSetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbGetExtnParm(ZCHAR *pcName, ZCHAR **ppcParm);

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
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbGetExtnParmBool(ZCHAR *pcName, ZBOOL *pbParm);

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
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbGetExtnParmInt(ZCHAR *pcName, ZINT *piParm);

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
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbGetExtnParmUint(ZCHAR *pcName, ZUINT *piParm);

/**
 * @brief Get extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] iIndex The parameter index.
 *
 * @return The parameter value when get extension parameter successfully, 
 *              otherwise return empty string.
 *
 * @see @ref Mtc_ProvDbSetExtnParm
 */
ZFUNC ZCHAR * Mtc_ProvDbGetExtnParmX(ZCHAR *pcName, ZINT iIndex);

/**
 * @brief Get extension parameter.
 *
 * @param [in] pcName The parameter name.
 *
 * @retval ZOK Get the parameter count successfully.
 * @retval ZFAILED Get the parameter count failed.
 *
 * @see @ref Mtc_ProvDbSetExtnParm
 */
ZFUNC ZUINT Mtc_ProvDbGetExtnParmCount(ZCHAR *pcName);

/**
 * @brief Set extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] pcVal The parameter value.
 *
 * @retval ZOK Set the parameter successfully.
 * @retval ZFAILED Set the parameter failed.
 *
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbSetExtnParm(ZCHAR *pcName, ZCHAR *pcVal);

/**
 * @brief Set extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] bVal The parameter value.
 *
 * @retval ZOK Set the parameter successfully.
 * @retval ZFAILED Set the parameter failed.
 *
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbSetExtnParmBool(ZCHAR *pcName, ZBOOL bVal);

/**
 * @brief Set extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] iVal The parameter value.
 *
 * @retval ZOK Set the parameter successfully.
 * @retval ZFAILED Set the parameter failed.
 *
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbSetExtnParmInt(ZCHAR *pcName, ZINT iVal);

/**
 * @brief Set extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] iVal The parameter value.
 *
 * @retval ZOK Set the parameter successfully.
 * @retval ZFAILED Set the parameter failed.
 *
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbSetExtnParmUint(ZCHAR *pcName, ZUINT iVal);

/**
 * @brief Add extension parameter.
 *
 * @param [in] pcName The parameter name.
 * @param [in] pcVal The parameter value.
 *
 * @retval ZOK Add the parameter successfully.
 * @retval ZFAILED Add the parameter failed.
 *
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbAddExtnParm(ZCHAR *pcName, ZCHAR *pcVal);

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
 * @see @ref Mtc_ProvDbGetExtnParm
 */
ZFUNC ZINT Mtc_ProvDbAddExtnParmN(ZCHAR *pcName, ZUSHORT wNameLen,
                ZCHAR *pcVal, ZUSHORT wValLen);

/**
 * @brief Get the RCS version from database.
 *   It is only mandatory from RCS 5.1 onwards.
 *
 * @return The type of RCS version, @see @ref EN_MTC_PROV_RCS_VER_TYPE.
 *
 * @see @ref Mtc_ProvDbSetRcsVer
*/
ZFUNC ZUINT  Mtc_ProvDbGetRcsVer(ZFUNC_VOID);

/**
 * @brief Get the RCS profile from database.
 *
 * @return The type of RCS profile, @see @ref EN_MTC_PROV_RCS_PROF_TYPE.
 *
 * @see @ref Mtc_ProvDbSetRcsProfile
*/
ZFUNC ZUINT Mtc_ProvDbGetRcsProfile(ZFUNC_VOID);

/**
 * @brief Get the device type from database.
 *
 * @return The device type, @see @ref EN_MTC_PROV_DEVICE_TYPE.
 *
 * @see @ref Mtc_ProvDbSetDeviceType
*/
ZFUNC ZUSHORT Mtc_ProvDbGetDeviceType(ZFUNC_VOID);

/**
 * @brief Get the SMS port from database.
 *
 * @return The SMS port.
 *
 * @see @ref Mtc_ProvDbSetSmsPort
*/
ZFUNC ZUSHORT Mtc_ProvDbGetSmsPort(ZFUNC_VOID);

/**
 * @brief Get the client vendor from database.
 *
 * @return The string of client vendor.
 *
 * @see @ref Mtc_ProvDbSetCliVendor
*/
ZFUNC ZCHAR * Mtc_ProvDbGetCliVendor(ZFUNC_VOID);

/**
 * @brief Get the client version from database.
 *
 * @return The string of client version.
 *
 * @see @ref Mtc_ProvDbSetCliVer
*/
ZFUNC ZCHAR * Mtc_ProvDbGetCliVer(ZFUNC_VOID);

/**
 * @brief Get the terminal vendor from database.
 *
 * @return The string of terminal vendor.
 *
 * @see @ref Mtc_ProvDbSetTmnlVendor
*/
ZFUNC ZCHAR * Mtc_ProvDbGetTmnlVendor(ZFUNC_VOID);

/**
 * @brief Get the terminal model from database.
 *
 * @return The string of terminal model.
 *
 * @see @ref Mtc_ProvDbSetTmnlModel
*/
ZFUNC ZCHAR * Mtc_ProvDbGetTmnlModel(ZFUNC_VOID);

/**
 * @brief Get the terminal software version from database.
 *
 * @return The string of terminal software version.
 *
 * @see @ref Mtc_ProvDbSetTmnlSwVer
*/
ZFUNC ZCHAR * Mtc_ProvDbGetTmnlSwVer(ZFUNC_VOID);

/**
 * @brief Get the terminal type from database.
 *
 * @return The terminal type
 *
 * @see @ref Mtc_ProvDbSetTmnlType
*/
ZFUNC ZCHAR *  Mtc_ProvDbGetTmnlType(ZFUNC_VOID);

/**
 * @brief Get the channel id from database.
 *
 * @return The string of channel id.
 *
 * @see @ref Mtc_ProvDbSetChnnlId
*/
ZFUNC ZCHAR * Mtc_ProvDbGetChnnlId(ZFUNC_VOID);

/**
 * @brief Get the server template from database.
 *
 * @return The type of server template, @see @ref EN_MTC_PROV_SRV_TMPL_TYPE.
 *
 * @see @ref Mtc_ProvDbSetSrvTmpl
*/
ZFUNC ZUINT Mtc_ProvDbGetSrvTmpl(ZFUNC_VOID);

/**
 * @brief Get the server template from database.
 *
 * @return The string of server template.
 *
 * @see @ref Mtc_ProvDbSetSrvTmplX
*/
ZFUNC ZCHAR * Mtc_ProvDbGetSrvTmplX(ZFUNC_VOID);

/**
 * @brief Get the mobile country code from database.
 *
 * @return The string of mobile country code.
 *
 * @see @ref Mtc_ProvDbSetMcc
*/
ZFUNC ZCHAR * Mtc_ProvDbGetMcc(ZFUNC_VOID);

/**
 * @brief Get the mobile network code from database.
 *
 * @return The string of mobile network code.
 *
 * @see @ref Mtc_ProvDbSetMnc
*/
ZFUNC ZCHAR * Mtc_ProvDbGetMnc(ZFUNC_VOID);

/**
 * @brief Get the IMEI from database.
 *
 * @return The string of IMEI.
 *
 * @see @ref Mtc_ProvDbSetImei
*/
ZFUNC ZCHAR * Mtc_ProvDbGetImei(ZFUNC_VOID);

/**
 * @brief Get the service type from database.
 *
 * @return The string of service type.
 *
 * @see @ref Mtc_ProvDbSetSrvType
*/
ZFUNC ZCHAR * Mtc_ProvDbGetSrvType(ZFUNC_VOID);

/**
 * @brief Set RCS version.
 *   It is only mandatory from RCS 5.1 onwards.
 *
 * @param [in] iRcsVer RCS version type, @see @ref EN_MTC_PROV_RCS_VER_TYPE.
 *
 * @retval ZOK Set RCS version successfully.
 * @retval ZFAILED Set RCS version failed.
 *
 * @see @ref Mtc_ProvDbGetRcsVer
 */
ZFUNC ZINT Mtc_ProvDbSetRcsVer(ZUINT iRcsVer);

/**
 * @brief Set RCS profile.
 *
 * @param [in] iRcsProfile RCS profile type, @see @ref EN_MTC_PROV_RCS_PROF_TYPE.
 *
 * @retval ZOK Set RCS profile successfully.
 * @retval ZFAILED Set RCS profile failed.
 *
 * @see @ref Mtc_ProvDbGetRcsProfile
 */
ZFUNC ZINT Mtc_ProvDbSetRcsProfile(ZUINT iRcsProfile);

/**
 * @brief Set device type.
 *
 * @param [in] wDeviceType device type, @see @ref EN_MTC_PROV_DEVICE_TYPE.
 *
 * @retval ZOK Set device type successfully.
 * @retval ZFAILED Set device type failed.
 *
 * @see @ref Mtc_ProvDbGetDeviceType
 */
ZFUNC ZINT Mtc_ProvDbSetDeviceType(ZUSHORT wDeviceType);

/**
 * @brief Set SMS port.
 *
 * @param [in] wPort SMS port.
 *
 * @retval ZOK Set SMS port successfully.
 * @retval ZFAILED Set SMS port failed.
 *
 * @see @ref Mtc_ProvDbGetSmsPort
 */
ZFUNC ZINT Mtc_ProvDbSetSmsPort(ZUSHORT wPort);

/**
 * @brief Set client vendor.
 *
 * @param [in] pcVendor Client vendor string.
 *
 * @retval ZOK Set client vendor successfully.
 * @retval ZFAILED Set client vendor failed.
 *
 * @see @ref Mtc_ProvDbGetCliVendor
 */
ZFUNC ZINT Mtc_ProvDbSetCliVendor(ZCHAR *pcVendor);

/**
 * @brief Set client version.
 *
 * @param [in] pcVer client version string.
 *
 * @retval ZOK Set client version successfully.
 * @retval ZFAILED Set client version failed.
 *
 * @see @ref Mtc_ProvDbGetCliVer
 */
ZFUNC ZINT Mtc_ProvDbSetCliVer(ZCHAR *pcVer);

/**
 * @brief Set terminal vendor.
 *
 * @param [in] pcVendor terminal vendor string.
 *
 * @retval ZOK Set terminal vendor successfully.
 * @retval ZFAILED Set terminal vendor failed.
 *
 * @see @ref Mtc_ProvDbGetTmnlVendor
 */
ZFUNC ZINT Mtc_ProvDbSetTmnlVendor(ZCHAR *pcVendor);

/**
 * @brief Set terminal model.
 *
 * @param [in] pcModel terminal model string.
 *
 * @retval ZOK Set terminal model successfully.
 * @retval ZFAILED Set terminal model failed.
 *
 * @see @ref Mtc_ProvDbGetTmnlModel
 */
ZFUNC ZINT Mtc_ProvDbSetTmnlModel(ZCHAR *pcModel);

/**
 * @brief Set terminal software version.
 *
 * @param [in] pcVer terminal software version string.
 *
 * @retval ZOK Set terminal software version successfully.
 * @retval ZFAILED Set terminal software version failed.
 *
 * @see @ref Mtc_ProvDbGetTmnlSwVer
 */
ZFUNC ZINT Mtc_ProvDbSetTmnlSwVer(ZCHAR *pcVer);

/**
 * @brief Set terminal type.
 *
 * @param [in] pcTmnlType terminal type
 *
 * @retval ZOK Set terminal type successfully.
 * @retval ZFAILED Set terminal type failed.
 *
 * @see @ref Mtc_ProvDbGetTmnlType
 */
ZFUNC ZINT Mtc_ProvDbSetTmnlType(ZCHAR * pcTmnlType);

/**
 * @brief Set channel id.
 *
 * @param [in] pcChnnlId channel id string.
 *
 * @retval ZOK Set channel id successfully.
 * @retval ZFAILED Set channel id failed.
 *
 * @see @ref Mtc_ProvDbGetChnnlId
 */
ZFUNC ZINT Mtc_ProvDbSetChnnlId(ZCHAR *pcChnnlId);

/**
 * @brief Set server template.
 *
 * @param [in] iSrvTmpl server template, @see @ref EN_MTC_PROV_SRV_TMPL_TYPE.
 *
 * @retval ZOK Set server template successfully.
 * @retval ZFAILED Set server template failed.
 *
 * @see @ref Mtc_ProvDbGetSrvTmpl
 */
ZFUNC ZINT Mtc_ProvDbSetSrvTmpl(ZUINT iSrvTmpl);

/**
 * @brief Set server template.
 *
 * @param [in] pcSrvTmpl server template.
 *
 * @retval ZOK Set server template successfully.
 * @retval ZFAILED Set server template failed.
 *
 * @see @ref Mtc_ProvDbGetSrvTmplX
 */
ZFUNC ZINT Mtc_ProvDbSetSrvTmplX(ZCHAR *pcSrvTmpl);

/**
 * @brief Set mobile country code.
 *
 * @param [in] pcMcc mobile country code string.
 *
 * @retval ZOK Set mobile country code successfully.
 * @retval ZFAILED Set mobile country code failed.
 *
 * @see @ref Mtc_ProvDbGetMcc
 */
 ZFUNC ZINT Mtc_ProvDbSetMcc(ZCHAR *pcMcc);

/**
 * @brief Set mobile network code.
 *
 * @param [in] pcMnc mobile network code string.
 *
 * @retval ZOK Set mobile network code successfully.
 * @retval ZFAILED Set mobile network code failed.
 *
 * @see @ref Mtc_ProvDbGetMnc
 */
ZFUNC ZINT Mtc_ProvDbSetMnc(ZCHAR *pcMnc);

/**
 * @brief Set IMEI.
 *
 * @param [in] pcImei IMEI string.
 *
 * @retval ZOK Set IMEI successfully.
 * @retval ZFAILED Set IMEI failed.
 *
 * @see @ref Mtc_ProvDbGetImei
 */
ZFUNC ZINT Mtc_ProvDbSetImei(ZCHAR *pcImei);

/**
 * @brief Set service type.
 *
 * @param [in] pcSrvType service type string.
 *
 * @retval ZOK Set service type successfully.
 * @retval ZFAILED Set tservice type failed.
 *
 * @see @ref Mtc_ProvDbGetSrvType
 */
ZFUNC ZINT Mtc_ProvDbSetSrvType(ZCHAR *pcSrvType);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PROV_DB_H__ */

