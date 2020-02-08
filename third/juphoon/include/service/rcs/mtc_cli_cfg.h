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
  File name     : mtc_cli_cfg.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-04
  Description   :
      Data structure and function declare required by MTC client config

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CLI_CFG_H__
#define _MTC_CLI_CFG_H__

/**
 * @file mtc_cli_cfg.h
 * @brief MTC Client Config Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Application context type definition */
typedef ZVOID * ZAPPCONTEXT;

/** @brief{ */
/* MTC client REGISTER capability options */
#define MTC_REG_CAP_OPT_NULL       0 /**< @brief no capability. */
#define MTC_REG_CAP_OPT_QVAL       1 /**< @brief qvalue */
#define MTC_REG_CAP_OPT_CS_VOICE   2 /**< @brief 3GPP cs voice */
#define MTC_REG_CAP_OPT_MMTEL      3 /**< @brief IMS MMTel */
#define MTC_REG_CAP_OPT_ISHARE     4 /**< @brief IMS Image Share */
#define MTC_REG_CAP_OPT_IM         5 /**< @brief OMA IM */
#define MTC_REG_CAP_OPT_IM_LMSG    6 /**< @brief OMA Large Message  */
#define MTC_REG_CAP_OPT_RCS_CS     7 /**< @brief RCS cs telephony */
#define MTC_REG_CAP_OPT_RCS_GEO    8 /**< @brief RCS geopush */
#define MTC_REG_CAP_OPT_RCSE_IM    9 /**< @brief RCSE file transfer */
#define MTC_REG_CAP_OPT_RCSE_FT    10 /**< @brief RCSE file transfer */
#define MTC_REG_CAP_OPT_AUDIO      11 /**< @brief audio */
#define MTC_REG_CAP_OPT_VIDEO      12 /**< @brief video */
#define MTC_REG_CAP_OPT_CPM        13 /**< @brief CPM message */
#define MTC_REG_CAP_OPT_CPM_LMSG   14 /**< @brief CPM large message */
#define MTC_REG_CAP_OPT_CPM_FT     15 /**< @brief CPM file transfer */
#define MTC_REG_CAP_OPT_CPM_SESS   16 /**< @brief CPM session */
#define MTC_REG_CAP_OPT_SMS_IP     17 /**< @brief 3GPP SMS over IP */
#define MTC_REG_CAP_OPT_CMCC_GROUP 18 /**< @brief CMCC group chat */

#define MTC_REG_CAP_OPT_ALL        ZMAXUINT /**< @brief all capabilties. */
/** @} */

/** @brief{ */
/* MTC client REGISTER extern capability options */
#define MTC_CMCC_EXT_REG_CAP_OPT_NULL       0 /**< @brief no capability. */
#define MTC_CMCC_EXT_REG_CAP_OPT_BURN       1 /**< @brief burn after read */
#define MTC_CMCC_EXT_REG_CAP_OPT_GRP_MAN    2 /**< @brief group manage */
#define MTC_CMCC_EXT_REG_CAP_OPT_CLOUD_FILE 3 /**< @brief cloud file */
#define MTC_CMCC_EXT_REG_CAP_OPT_VEM        4 /**< @brief vemoticon */
#define MTC_CMCC_EXT_REG_CAP_OPT_CMRED_BAG  5 /**< @brief cmcc redbag */
#define MTC_CMCC_EXT_REG_CAP_OPT_CARD_MSG   6 /**< @brief cmcc cardmsg */
#define MTC_CMCC_EXT_REG_CAP_OPT_OFF_MSG    7 /**< @brief 3GPP offline msg */
#define MTC_CMCC_EXT_REG_CAP_OPT_139MAIL_NEW 8 /**< @brief cmcc 139 new mail notify msg */
#define MTC_CMCC_EXT_REG_CAP_OPT_GRP_QRCODE 9 /**< @brief group qrcode  */
#define MTC_CMCC_EXT_REG_CAP_OPT_EXVCARD_MSG 10 /**< @brief x-vcard msg */
#define MTC_CMCC_EXT_REG_CAP_OPT_OMAPUSH    11  /**< @brief app push msg */
#define MTC_CMCC_EXT_REG_CAP_OPT_COM_TEMPLATE    12  /**< @brief app common template */
#define MTC_CMCC_EXT_REG_CAP_OPT_CALLCOM     13  /**< @brief app callcomposer msg */
#define MTC_CMCC_EXT_REG_CAP_OPT_MSG_REVOKE  14  /**< @brief app message revoke */
#define MTC_CMCC_EXT_REG_CAP_OPT_CHRED_BAG       15 /**< @brief cmcc cash redbag */
#define MTC_CMCC_EXT_REG_CAP_OPT_PUB_MSG  16 /**< @brief cmcc pub msg */
#define MTC_CMCC_EXT_REG_CAP_OPT_ALL        ZMAXUINT /**< @brief all capabilties. */
/** @} */

/** @brief{ */
/* MTC log level */
#define MTC_LOG_LEVEL_NULL    0x00000000 /**< @brief null to be logged */
#define MTC_LOG_LEVEL_FATAL   0x00000001 /**< @brief fatal message to be logged */
#define MTC_LOG_LEVEL_ERROR   0x00000002 /**< @brief error message to be logged */
#define MTC_LOG_LEVEL_WARN    0x00000004 /**< @brief warning message to be logged */
#define MTC_LOG_LEVEL_INFO    0x00000008 /**< @brief info message to be logged */
#define MTC_LOG_LEVEL_DBG     0x00000010 /**< @brief debug message to be logged */
#define MTC_LOG_LEVEL_FUNC    0x00000100 /**< @brief function trace to be logged */
#define MTC_LOG_LEVEL_ALL     0x000001FF /**< @brief all message to be logged */
/** @} */

/** @brief MTC service type */
typedef enum EN_MTC_REG_SRV_TYPE
{
    EN_MTC_REG_SRV_VOIP,             /**< @brief voip service */
    EN_MTC_REG_SRV_MMTEL,            /**< @brief 3GPP IMS service */
    EN_MTC_REG_SRV_VOLTE,            /**< @brief 3GPP VoLTE service */
    EN_MTC_REG_SRV_RCS5,             /**< @brief GSMA RCS5 service */
    EN_MTC_REG_SRV_JOYN_HF,          /**< @brief GSMA joyn hotfixes service */
    EN_MTC_REG_SRV_JOYN_BB,          /**< @brief GSMA joyn blackbird service */
    EN_MTC_REG_SRV_CMCC_RCS,         /**< @brief CMCC RCS service */
} EN_MTC_REG_SRV_TYPE;

/** @brief MTC log level. */
typedef enum EN_MTC_LOG_LEVEL_TYPE
{
    EN_MTC_LOG_LEVEL_DISABLE = 0,    /** @brief Disable log output. */
    EN_MTC_LOG_LEVEL_ERROR,          /** @brief Only error message. */
    EN_MTC_LOG_LEVEL_INFO,           /** @brief Include error, info message. */
    EN_MTC_LOG_LEVEL_DEBUG,          /** @brief Inlcude error, info 
                                                and debug message. */
    EN_MTC_LOG_LEVEL_FUNCTION,       /** @brief Include error, info,
                                                debug and function message. */
} EN_MTC_LOG_LEVEL_TYPE;

/**
 * @brief Set log level.
 *
 * @param [in] iLevel Log level, 0 for no log, larger value for more log, 
 *  type see @ref EN_MTC_LOG_LEVEL_TYPE.
 */
ZFUNC ZVOID Mtc_CliCfgSetLogLevel(ZUINT iLevel);

/**
 * @brief Set log level.
 *
 * @param [in] iLevel Log level, MTC_LOG_LEVEL_NULL for no log, 
 *  larger value (e.g. MTC_LOG_LEVEL_ERROR & MTC_LOG_LEVEL_INFO) for more log, 
 *  type see @ref MTC_LOG_LEVEL_NULL...
 */
ZFUNC ZVOID Mtc_CliCfgSetLogLevelX(ZUINT iLevel);

/**
 * @brief Set log print.
 *
 * @param [in] bPrint log print.
 *
 * @retval ZOK Set operation successfully.
 * @retval ZFAILED Set operation failed.
 */
ZFUNC ZINT Mtc_CliCfgSetLogPrint(ZBOOL bPrint);

/**
 * @brief Get using detect local IP when client start and login.
 *
 * @retval ZTRUE Detect local IP.
 * @retval ZFALSE Not detect local IP.
 *
 * @see @ref Mtc_CliCfgSetUseDetLclIp
 */
ZFUNC ZBOOL Mtc_CliCfgGetUseDetLclIp(ZFUNC_VOID);

/**
 * @brief Set using detect local IP when client start and login.
 *
 * @param [in] bDetect Use default profile management.
 *
 * @retval ZOK Set detect option successfully.
 * @retval ZFAILED Set detect option failed.
 *
 * @see @ref Mtc_CliCfgGetUseDetLclIp
 */
ZFUNC ZINT Mtc_CliCfgSetUseDetLclIp(ZBOOL bDetect);

/**
 * @brief Get support ability of network detection when client has logined.
 *
 * @retval ZTRUE Detect network available.
 * @retval ZFALSE Not detect available.
 *
 * @see @ref Mtc_CliCfgSetSuptNetDetect
 */
ZFUNC ZBOOL Mtc_CliCfgGetSuptNetDetect(ZFUNC_VOID);

/**
 * @brief Set support ability of network detection when client has logined.
 *
 * @param [in] bSupt Support network detection.
 *
 * @retval ZOK Set network detection successfully.
 * @retval ZFAILED Set network detection failed.
 *
 * @see @ref Mtc_CliCfgGetSuptNetDetect
 */
ZFUNC ZINT Mtc_CliCfgSetSuptNetDetect(ZBOOL bSupt);

/**
 * @brief Get support ability of encrypt password.
 *
 * @retval ZTRUE Password saved in crypto.
 * @retval ZFALSE Password save in plain text.
 *
 * @see @ref Mtc_CliCfgSetSuptEncPwd
 */
ZFUNC ZBOOL Mtc_CliCfgGetSuptEncPwd();

/**
 * @brief Set support ability of encrypt password.
 *
 * @param [in] bSupt Support encrypt password.
 *
 * @retval ZOK Set encrypt password successfully.
 * @retval ZFAILED Set encrypt password failed.
 *
 * @see @ref Mtc_CliCfgGetSuptEncPwd
 */
ZFUNC ZINT Mtc_CliCfgSetSuptEncPwd(ZBOOL bSupt);

/**
 * @brief Get REGISTER capability flag.
 *
 * @return REGISTER capability, see @ref MTC_REG_CAP_OPT_IM etc.
 *
 * @see @ref Mtc_CliCfgSetRegCap
 */
ZFUNC ZUINT Mtc_CliCfgGetRegCap(ZFUNC_VOID);

/**
 * @brief Set REGISTER capability flag.
 *
 * @param [in] iCapOpt REGISTER capability flag, see @ref MTC_REG_CAP_OPT_IM etc.
 *
 * @retval ZOK Set capability option successfully.
 * @retval ZFAILED Set capability option failed.
 *
 * @see @ref Mtc_CliCfgGetRegCap
 */
ZFUNC ZINT Mtc_CliCfgSetRegCap(ZUINT iCapOpt);

/**
 * @brief Clear REGISTER capability flag.
 *
 * @param [in] iCapOpt REGISTER capability flag, see @ref MTC_REG_CAP_OPT_IM etc.
 *
 * @retval ZOK Clear capability option successfully.
 * @retval ZFAILED Clear capability option failed.
 *
 * @see @ref Mtc_CliCfgGetRegCap
 */
ZFUNC ZINT Mtc_CliCfgClrRegCap(ZUINT iCapOpt);

/**
 * @brief Get CmccExtRegister extern capability flag.
 *
 * @return CmccExtRegister extern capability, see @ref MTC_EXT_REG_CAP_OPT_CMRED_BAG etc.
 *
 * @see @ref Mtc_CliCfgSetCmccExtRegCap
 */
ZFUNC ZUINT Mtc_CliCfgGetCmccExtRegCap(ZFUNC_VOID);

/**
 * @brief Set CmccExtRegister extern capability flag.
 *
 * @param [in] iCapOpt CmccExtRegister extern capability flag, see @ref MTC_EXT_REG_CAP_OPT_CMRED_BAG etc.
 *
 * @retval ZOK Set extern capability option successfully.
 * @retval ZFAILED Set extern capability option failed.
 *
 * @see @ref Mtc_CliCfgGetCmccExtRegCap
 */
ZFUNC ZINT Mtc_CliCfgSetCmccExtRegCap(ZUINT iCapOpt);

/**
 * @brief Clear CmccExtRegister extern capability flag.
 *
 * @param [in] iCapOpt CmccExtRegister extern capability flag, see @ref MTC_EXT_REG_CAP_OPT_CMRED_BAG etc.
 *
 * @retval ZOK Clear extern capability option successfully.
 * @retval ZFAILED Clear extern capability option failed.
 *
 * @see @ref Mtc_CliCfgGetCmccExtRegCap
 */
ZFUNC ZINT Mtc_CliCfgClrCmccExtRegCap(ZUINT iCapOpt);

/**
 * @brief Set Log file directory.
 *
 * @param [in] pcDir The log file directory.
 *
 * @retval ZOK Set directory successfully.
 * @retval ZFAILED Set directory failed.
 */
ZFUNC ZINT Mtc_CliCfgSetLogDir(ZCHAR * pcDir);

/**
 * @brief Get Log file directory.
 *
 * @return The log file directory, default "".
 */
ZFUNC ZCONST ZCHAR * Mtc_CliCfgGetLogDir(ZFUNC_VOID);

/**
 * @brief Get log file size from configuration.
 *
 * @return The log file size in byte(default 5MB).
 *
 * @see @ref Mtc_CliCfgSetLogFileSize
 */
ZFUNC ZUINT Mtc_CliCfgGetLogFileSize(ZFUNC_VOID);

/**
 * @brief Set log file size.
 *
 * @param [in] iLogFileSize The log file size in byte(default 5MB)..
 *
 * @retval ZOK Set log file size successfully.
 * @retval ZFAILED Set log file size failed.
 *
 * @see @ref Mtc_CliCfgGetLogFileSize
 */
ZFUNC ZINT Mtc_CliCfgSetLogFileSize(ZUINT iLogFileSize);

/**
 * @brief Get log file count from configuration.
 *
 * @return The log file count(default 10 log files).
 *
 * @see @ref Mtc_CliCfgSetLogFileCount
 */
ZFUNC ZUINT Mtc_CliCfgGetLogFileCount(ZFUNC_VOID);

/**
 * @brief Set log file count.
 *
 * @param [in] iLogFileCount The log file count(default 10 log files).
 *
 * @retval ZOK Set log file size successfully.
 * @retval ZFAILED Set log file size failed.
 *
 * @see @ref Mtc_CliCfgGetLogFileCount
 */
ZFUNC ZINT Mtc_CliCfgSetLogFileCount(ZUINT iLogFileCount);

/**
 * @brief Set login log print to file flag.
 *
 * @param [in] bPrint login log print flag.
 *
 * @retval ZOK Set operation successfully.
 * @retval ZFAILED Set operation failed.
 */
ZFUNC ZINT Mtc_CliCfgSetLoginLogPrint(ZBOOL bPrint);

/**
 * @brief Set Login log file directory.
 *
 * @param [in] pcDir The login log file directory.
 *
 * @retval ZOK Set directory successfully.
 * @retval ZFAILED Set directory failed.
 */
ZFUNC ZINT Mtc_CliCfgSetLoginLogDir(ZCHAR * pcDir);

/**
 * @brief Get Login log file directory.
 *
 * @return The login log file directory, default "".
 */
ZFUNC ZCONST ZCHAR * Mtc_CliCfgGetLoginLogDir(ZFUNC_VOID);

/**
 * @brief Get login log file size from database.
 *
 * @return The login log file size in byte(default 100KB).
 *
 * @see @ref Mtc_CliCfgSetLoginLogFileSize
 */
ZFUNC ZUINT Mtc_CliCfgGetLoginLogFileSize(ZFUNC_VOID);

/**
 * @brief Set login log file size.
 *
 * @param [in] iLogFileSize The login log file size in byte(default 100KB).
 *
 * @retval ZOK Set login log file size successfully.
 * @retval ZFAILED Set login log file size failed.
 *
 * @see @ref Mtc_CliCfgGetLoginLogFileCount
 */
ZFUNC ZINT Mtc_CliCfgSetLoginLogFileSize(ZUINT iLogFileSize);

/**
 * @brief Get login log file count from database.
 *
 * @return The login log file count(default 5 log files).
 *
 * @see @ref Mtc_CliCfgSetLoginLogFileCount
 */
ZFUNC ZUINT Mtc_CliCfgGetLoginLogFileCount(ZFUNC_VOID);

/**
 * @brief Set login log file count.
 *
 * @param [in] iLogFileCount The login log file count(default 5 log files).
 *
 * @retval ZOK Set login log file size successfully.
 * @retval ZFAILED Set login log file size failed.
 *
 * @see @ref Mtc_CliCfgGetLoginLogFileCount
 */
ZFUNC ZINT Mtc_CliCfgSetLoginLogFileCount(ZUINT iLogFileCount);

/**
 * @brief Set license file name.
 *
 * @param [in] pcFileName The license file name.
 *
 * @retval ZOK Set file name successfully.
 * @retval ZFAILED Set file name failed.
 */
ZFUNC ZINT Mtc_CliCfgSetLicenseFileName(ZCONST ZCHAR *pcFileName);

/**
 * @brief Set aes key.
 *
 * @param [in] pcAesKey The aes key.
 *
 * @retval ZOK Set aes key successfully.
 * @retval ZFAILED Set aes key failed.
 */
ZFUNC ZINT Mtc_CliCfgSetAesKey(ZCONST ZCHAR *pcAesKey);

/**
 * @brief Set license context.
 *
 * @param [in] zContext The application context, only avaliable on Android.
 *
 * @retval ZOK Set file name successfully.
 * @retval ZFAILED Set file name failed.
 */
ZFUNC ZINT Mtc_CliCfgSetContext(ZAPPCONTEXT zContext);

/**
 * @brief Get file encryption from database.
 *
 * @return The file encryption.
 *
 * @see @ref Mtc_CliCfgSetFileEncrypt
 */
ZFUNC ZBOOL Mtc_CliCfgGetFileEncrypt(ZFUNC_VOID);

/**
 * @brief Set file encryption.
 *
 * @param [in] bFileEncrypt The file encryption.
 *
 * @retval ZOK Set file encryption successfully.
 * @retval ZFAILED Set file encryption failed.
 *
 * @see @ref Mtc_CliCfgGetFileEncrypt
 */
ZFUNC ZINT Mtc_CliCfgSetFileEncrypt(ZBOOL bFileEncrypt);

/**
 * @brief Get register service type.
 *
 * @return register service type, see @ref EN_MTC_REG_SRV_TYPE etc.
 *
 * @see @ref Mtc_CliCfgSetRegSrvType
 */
ZFUNC ZUINT Mtc_CliCfgGetRegSrvType(ZFUNC_VOID);

/**
 * @brief Set register service type.
 *
 * @param [in] iSrvType register service type, see @ref EN_MTC_REG_SRV_TYPE etc.
 *
 * @retval ZOK Set register service type successfully.
 * @retval ZFAILED Set register service type failed.
 *
 * @see @ref Mtc_CliCfgGetRegSrvType
 */
ZFUNC ZINT Mtc_CliCfgSetRegSrvType(ZUINT iSrvType);

/**
 * @brief Get wait register timer length.
 *
 * @return wait register timer length.
 *
 * @see @ref Mtc_CliCfgSetTmrLenWaitReg
 */
ZFUNC ZUINT Mtc_CliCfgGetTmrLenWaitReg();

/**
 * @brief Set wait register timer length.
 *
 * @param [in] iTmrLen wait register timer length.
 *
 * @retval ZOK Set wait register timer length successfully.
 * @retval ZFAILED wait register timer length failed.
 *
 * @see @ref Mtc_CliCfgGetTmrLenWaitReg
 */
ZFUNC ZINT Mtc_CliCfgSetTmrLenWaitReg(ZUINT iTmrLen);

/**
 * @brief Get support refresh before expire.
 *
 * @retval ZTRUE refresh before expire.
 * @retval ZFALSE refresh when expire.
 *
 * @see @ref Mtc_CliCfgSetSuptRefreshBefExpr
 */
ZFUNC ZBOOL Mtc_CliCfgGetSuptRefreshBefExpr();

/**
 * @brief Set support refresh before expire.
 *
 * @param [in] bSupt Support refresh before expire.
 *
 * @retval ZOK Set refresh before expire successfully.
 * @retval ZFAILED Set refresh before expire failed.
 *
 * @see @ref Mtc_CliCfgGetSuptRefreshBefExpr
 */
ZFUNC ZINT Mtc_CliCfgSetSuptRefreshBefExpr(ZBOOL bSupt);

/**
 * @brief Set check device ID type.
 *
 * @param [in] iType The device ID type @ref EN_MTC_DEVICE_ID_TYPE.
 *
 * @retval ZOK Set check device ID type successfully.
 * @retval ZFAILED Set check device ID type failed.
 *
 */
ZFUNC ZINT Mtc_CliCfgSetChkDevIdType(ZUINT iType);

/**
 * @brief Get timer self drive enable.
 *
 * @retval ZTRUE enable timer self drive.
 * @retval ZFALSE disable timer self drive.
 *
 * @see Mtc_CliCfgSetTimerSelfDrvEnable
 */
ZFUNC ZBOOL Mtc_CliCfgGetTimerSelfDrvEnable();

/**
 * @brief Set timer self drive enable.
 *
 * @param [in] bEnable Enable timer self drive.
 *
 * @retval ZOK Set timer self drive enable successfully.
 * @retval ZFAILED Set timer self drive enable failed.
 *
 * @see Mtc_CliCfgGetTimerSelfDrvEnable
 */
ZFUNC ZINT Mtc_CliCfgSetTimerSelfDrvEnable(ZBOOL bEnable);

/**
 * @brief Get logcat print flag.
 *
 * @retval ZTRUE logcat print.
 * @retval ZFALSE logcat not print.
 *
 * @see @ref Mtc_CliCfgSetLogcatPrint
 */
ZFUNC ZBOOL Mtc_CliCfgGetLogcatPrint(ZFUNC_VOID);

/**
 * @brief Set logcat print flag.
 *
 * @param [in] bPrint logcat print.
 *
 * @retval ZOK Set logcat print flag successfully.
 * @retval ZFAILED Set logcat print flag failed.
 *
 * @see @ref Mtc_CliCfgGetLogcatPrint
 */
ZFUNC ZINT Mtc_CliCfgSetLogcatPrint(ZBOOL bPrint);

/**
 * @brief Get socket reuse address enable.
 *
 * @retval ZTRUE enable socket reuse address.
 * @retval ZFALSE disable socket reuse address.
 *
 * @see Mtc_CliCfgSetSocketReuseEnable
 */
ZFUNC ZBOOL Mtc_CliCfgGetSocketReuseEnable(ZFUNC_VOID);
    
/**
 * @brief Set socket reuse address enable.
 *
 * @param [in] bEnable Enable socket reuse address.
 *
 * @retval ZOK Set socket reuse address enable successfully.
 * @retval ZFAILED Set socket reuse address enable failed.
 *
 * @see Mtc_CliCfgGetSocketReuseEnable
 */
ZFUNC ZINT Mtc_CliCfgSetSocketReuseEnable(ZBOOL bEnable);

/**
 * @brief Get udp socket connect enable.
 *
 * @retval ZTRUE enable udp socket connect.
 * @retval ZFALSE disable udp socket connect.
 *
 * @see Mtc_CliCfgSetUdpConnectEnable
 */
ZFUNC ZBOOL Mtc_CliCfgGetUdpConnectEnable();
    
/**
 * @brief Set udp socket connect enable.
 *
 * @param [in] bEnable Enable udp socket connect.
 *
 * @retval ZOK Set udp socket connect enable successfully.
 * @retval ZFAILED Set udp socket connect enable failed.
 *
 * @see Mtc_CliCfgGetUdpConnectEnable
 */
ZFUNC ZINT Mtc_CliCfgSetUdpConnectEnable(ZBOOL bEnable);

/**
 * @brief Get client buried data point enable option(default ZFALSE).
 *
 * @retval ZTRUE Support buried data point enable option.
 * @retval ZFALSE Do not Support buried data point enable option.
 *
 * @see @ref Mtc_CliCfgSetBuriedDataPointEnable
 */
ZFUNC ZBOOL Mtc_CliCfgGetBuriedDataPointEnable(ZFUNC_VOID);

/**
 * @brief Set client buried data point enable option(default ZFALSE).
 *
 * @param [in] bEnable If ZTRUE, client support uploading buried data point  to server.
 * Otherwise it needn't buried data point.
 *
 * @retval ZOK Set client buried data point enable option successfully.
 * @retval ZFAILED Set client buried data point enable option failed.
 *
 * @see @ref Mtc_CliCfgGetBuriedDataPointEnable
 */
ZFUNC ZINT Mtc_CliCfgSetBuriedDataPointEnable(ZBOOL bEnable);

/**
 * @brief Get buried data point server address with port(e.g. 192.168.1.4:9000).
 *
 * @return buried data point server address.
 *
 * @see @ref Mtc_CliCfgSetBuriedDataPointServerAddr
 */
ZFUNC ZCHAR * Mtc_CliCfgGetBuriedDataPointServerAddr();

/**
 * @brief Set buried data point server address.
 *
 * @param [in] pcServAddr The server address with port(e.g. 192.168.1.4:9000).
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliCfgGetBuriedDataPointServerAddr
 */
ZFUNC ZINT Mtc_CliCfgSetBuriedDataPointServerAddr(ZCHAR *pcServAddr);

/**
 * @brief Get client uploading buried data log file enable option(default ZFALSE).
 *
 * @retval ZTRUE Support uploading buried data log file enable option.
 * @retval ZFALSE Do not Support uploading buried data log file enable option.
 *
 * @see @ref Mtc_CliCfgSetUploadLogFileEnable
 */
ZFUNC ZBOOL Mtc_CliCfgGetUploadLogFileEnable(ZFUNC_VOID);

/**
 * @brief Set client uploading buried data log file enable option(default ZFALSE).
 *
 * @param [in] bEnable If ZTRUE, client support uploading buried data point log file to server.
 * Otherwise it needn't upload buried data point log file.
 *
 * @retval ZOK Set client uploading buried data point log file enable option successfully.
 * @retval ZFAILED Set client uploading buried data point log file enable option failed.
 *
 * @see @ref Mtc_CliCfgGetUploadLogFileEnable
 */
ZFUNC ZINT Mtc_CliCfgSetUploadLogFileEnable(ZBOOL bEnable);

/**
 * @brief Get client uploading buried data point by https option(default ZTRUE).
 *
 * @retval ZTRUE Support uploading buried data point by https option.
 * @retval ZFALSE Do not Support uploading buried data point by https option.
 *
 * @see @ref Mtc_CliCfgSetStsHttpsEnable
 */
ZFUNC ZBOOL Mtc_CliCfgGetStsHttpsEnable(ZFUNC_VOID);

/**
 * @brief Set client uploading buried data point by https enable option(default ZTRUE).
 *
 * @param [in] bEnable If ZTRUE, client support uploading buried data point by https.
 * Otherwise it needn't upload buried data point by http.
 *
 * @retval ZOK Set client uploading buried data point by https option successfully.
 * @retval ZFAILED Set client uploading buried data point by https option failed.
 *
 * @see @ref Mtc_CliCfgGetStsHttpsEnable
 */
ZFUNC ZINT Mtc_CliCfgSetStsHttpsEnable(ZBOOL bEnable);

/**
 * @brief Get log file desensitization  on-off.
 * @retval ZOK Get  log file on-off flag successfully.
 * @retval ZFAILED  Get log file on-off flag failed.
 *
 * @see Mtc_CliCfgGetLogPhoneVage
 */
ZFUNC ZBOOL Mtc_CliCfgGetLogPhoneVage();

/**
 * @brief Set log file desensitization  on-off.
 *
 * @param [in]  set open log densensitization flag.
 *
 * @retval ZOK Set  log file on-off flag successfully.
 * @retval ZFAILED log file on-off flag failed.
 *
 * @see Mtc_CliCfgSetPhoneVague
 */
 
ZFUNC ZINT Mtc_CliCfgSetPhoneVague(ZBOOL bOpen);

/**
 * @brief Set  License package name 
 * @param [in] pcAppName package name
 *
 * @retval ZOK Set  License AppName successfully.
 * @retval ZFAILED License AppName failed.
 *
 * @see Mtc_CliCfgSetLcsAppName
 */
 
ZFUNC ZINT Mtc_CliCfgSetLcsAppName(ZCHAR *pcAppName);

/**
 * @brief Set Mtc Log  file Print Flags.
 *
 * @param [in] bPrint Support mtc log print info.
 *
 * @retval ZOK Set operation successfully.
 * @retval ZFAILED Set operation failed.
 */

ZFUNC ZINT Mtc_CliCfgSetMtcLogPrint(ZBOOL bPrint);

/**
 * @brief Get Mtc Log  file Print Flags.
 *
 * @retval ZTRUE Supprot Mtc log file print info.
 * @retval ZFALSE not Supprot Mtc log file Print info .
 */
 
ZFUNC ZBOOL Mtc_CliCfgGetMtcLogPrint();

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CLI_CFG_H__ */

