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
  File name     : mtc_cli.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
    Marcos and structure definitions required by the mtc.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CLI_H__
#define _MTC_CLI_H__

/**
 * @file mtc_cli.h
 * @brief MTC Client Interface Functions
 *
    @code
    The MTC client startup procedure like below:
    Mtc_CliInit    ---   init system resource
    Mtc_CliOpen    ---   open an user for config provision 
    *** Using Mtc_CliDbSetLocalIp etc db APIs for set provision
    Mtc_CliStart   ---   start client service

    The MTC client halt procedure like below:
    Mtc_CliStop    ---   stop client service
    Mtc_CliClose   ---   close client user 
    Mtc_CliDestroy ---   destroy system resource.

    The MTC client for support multi-user switch procedure like below:
    Mtc_CliStop    ---   stop client service
    Mtc_CliClose   ---   close current user provision 
    Mtc_CliOpen    ---   open another user config provision 
    *** Using Mtc_CliDbSetLocalIp etc db APIs for set provision
    Mtc_CliStart   ---   start client service
    @endcode

    If Zos_CfgGetModDrvMode value is ZTRUE, 
    it means MTC and MSF are running in different threads,
    User should implement callback which was set by @ref Mtc_CliCbSetEvnt 
    and post event to UI thread.
    The UI thread should Mtc_CliDrive explicitly after receive event.

    If Zos_CfgGetModDrvMode value is ZFALSE,
    it means MTC and MSF are running in the same thread,
    MTC will call Mtc_CliDrive implicitly.
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC state of REGISTER. */
#define MTC_REG_STATE_IDLE      0    /**< @brief Register idle state */
#define MTC_REG_STATE_REGING    1    /**< @brief Register registering state */
#define MTC_REG_STATE_REGED     2    /**< @brief Register registered state */
#define MTC_REG_STATE_UNREGING  3    /**< @brief Register unregistering state */
#define MTC_REG_STATE_RETRYING  4    /**< @brief Register retry registering state */

/** @brief MTC error/status code base */
#define MTC_EBASE_CP     	0xE000      /**< @brief CP error base */
#define MTC_EBASE_REG    	0xE100      /**< @brief REG error base */
#define MTC_EBASE_CALL   	0xE200      /**< @brief CALL error base */
#define MTC_EBASE_VSHARE 	0xE300      /**< @brief VSHARE error base */
#define MTC_EBASE_CAP    	0xE400      /**< @brief CAP error base */
#define MTC_EBASE_BUDDY  	0xE500      /**< @brief BUDDY error base */
#define MTC_EBASE_GRP    	0xE600      /**< @brief GRP error base */
#define MTC_EBASE_CONF   	0xE700      /**< @brief CONF error base */
#define MTC_EBASE_GS     	0xE800      /**< @brief GS error base */
#define MTC_EBASE_PRES   	0xE900      /**< @brief PRES error base */
#define MTC_EBASE_IM     	0xEA00      /**< @brief IM error base */
#define MTC_EBASE_LCS       0xEB00   	/**< @brief LCS error base */
#define MTC_EBASE_PA        0xEC00   	/**< @brief PA error base */
#define MTC_EBASE_CPROF     0xED00   	/**< @brief CRPOF error base */
#define MTC_EBASE_GBA       0xEE00   	/**< @brief GBA error base */

/** @brief MTC status code of REGISTER. */
#define MTC_CLI_ERR_NO                     (MTC_EBASE_REG + 0) /**< @brief No error. */
#define MTC_CLI_ERR_LCL_FAILED             (MTC_EBASE_REG + 1) /**< @brief Local request error. */
#define MTC_CLI_REG_ERR_SEND_MSG           (MTC_EBASE_REG + 2) /**< @brief Send message error. */
#define MTC_CLI_REG_ERR_AUTH_FAILED        (MTC_EBASE_REG + 3) /**< @brief Register authentication failed, invalid user or password. */
#define MTC_CLI_REG_ERR_INVALID_USER       (MTC_EBASE_REG + 4) /**< @brief Register using invalid user. */
#define MTC_CLI_REG_ERR_TIMEOUT            (MTC_EBASE_REG + 5) /**< @brief Register timeout. */
#define MTC_CLI_REG_ERR_SERV_BUSY          (MTC_EBASE_REG + 6) /**< @brief Register server busy. */
#define MTC_CLI_REG_ERR_SERV_NOT_REACH     (MTC_EBASE_REG + 7) /**< @brief Register server not reached. */
#define MTC_CLI_REG_ERR_SRV_FORBIDDEN      (MTC_EBASE_REG + 8) /**< @brief Register forbidden. */
#define MTC_CLI_REG_ERR_SRV_UNAVAIL        (MTC_EBASE_REG + 9) /**< @brief Register unavailable. */
#define MTC_CLI_REG_ERR_DNS_QRY            (MTC_EBASE_REG + 10) /**< @brief Register dns query error. */
#define MTC_CLI_REG_ERR_NETWORK            (MTC_EBASE_REG + 11) /**< @brief Register network error. */
#define MTC_CLI_REG_ERR_DEACTED            (MTC_EBASE_REG + 12) /**< @brief Register deactived. */
#define MTC_CLI_REG_ERR_PROBATION          (MTC_EBASE_REG + 13) /**< @brief Register probation */
#define MTC_CLI_REG_ERR_INTERNAL           (MTC_EBASE_REG + 14) /**< @brief Register internal error. */
#define MTC_CLI_REG_ERR_NO_RESOURCE        (MTC_EBASE_REG + 15) /**< @brief Register no resource. */
#define MTC_CLI_REG_ERR_REJECTED           (MTC_EBASE_REG + 16) /**< @brief Register be rejected. */
#define MTC_CLI_REG_ERR_SIP_SESS           (MTC_EBASE_REG + 17) /**< @brief Register sip session error. */
#define MTC_CLI_REG_ERR_UNREG              (MTC_EBASE_REG + 18) /**< @brief Register stop or unregsiter error. */
#define MTC_CLI_REG_ERR_INVALID_ADDR       (MTC_EBASE_REG + 19) /**< @brief Register using invalid ip addr. */
#define MTC_CLI_REG_ERR_WAIT_PWD           (MTC_EBASE_REG + 20) /**< @brief Register wait prompt password timeout. */
#define MTC_CLI_REG_ERR_NOT_FOUND          (MTC_EBASE_REG + 21) /**< @brief Register not found user. */
#define MTC_CLI_REG_ERR_AUTH_REJECT        (MTC_EBASE_REG + 22) /**< @brief Register authentication rejected, rorbidden to user register in hss. */
#define MTC_CLI_REG_ERR_ID_NOT_MATCH       (MTC_EBASE_REG + 23) /**< @brief Register identities don't match, the pvi of user not inconformity. */
#define MTC_CLI_REG_ERR_USER_NOT_EXIST     (MTC_EBASE_REG + 24) /**< @brief Register user not exist. */
#define MTC_CLI_REG_ERR_COM_NOT_MATCH      (MTC_EBASE_REG + 25) /**< @brief Register company don't match. */
#define MTC_CLI_REG_ERR_BAD_REQUEST        (MTC_EBASE_REG + 26) /**< @brief Register company don't match. */
#define MTC_CLI_REG_ERR_OTHER              (MTC_EBASE_REG + 200) /**< @brief Other register error. */

/** @brief MTC client open the last profile. */
#define MTC_CLI_OPEN_LAST(_ret) do { \
    /* get current profile user */ \
    ZCHAR *pcCurUser = Mtc_ProvDbGetCurProfUser(); \
    /* check the profile is exist, then open client if it is exist*/ \
    if (!ZOS_ISEMPTY_STR(pcCurUser) && Mtc_ProfExistUser(pcCurUser)) \
        _ret = Mtc_CliOpen(pcCurUser); \
    else \
        _ret = ZFAILED; \
} while (0)

/** @brief MTC client check if registered. */
#define MTC_CLI_CHK_REGED(_ret) do { \
    ZUINT iState = Mtc_CliGetRegState(); \
    if (iState != MTC_REG_STATE_REGED) \
    { \
        MSF_LOG_WARN(MTC_LOGID, "MTC_CLI_CHK_REGED not registed %d.", iState); \
        return _ret; \
    } \
} while (0)

/** @defgroup group_def_access_net_type Type define of access network type */
/** @{ */
#define MTC_ANET_UNAVAILABLE        0xFFFFFFFE
#define MTC_ANET_UNKNOWN            0xFFFFFFFF
#define MTC_ANET_MOBILE             0x0000
#define MTC_ANET_MOBILE_GPRS        0x0001
#define MTC_ANET_MOBILE_EDGE        0x0002
#define MTC_ANET_MOBILE_UMTS        0x0003
#define MTC_ANET_MOBILE_CDMA        0x0004
#define MTC_ANET_MOBILE_EVDO_0      0x0005
#define MTC_ANET_MOBILE_EVDO_A      0x0006
#define MTC_ANET_MOBILE_1XRTT       0x0007
#define MTC_ANET_MOBILE_HSDPA       0x0008
#define MTC_ANET_MOBILE_HSUPA       0x0009
#define MTC_ANET_MOBILE_HSPA        0x000A
#define MTC_ANET_MOBILE_IDEN        0x000B
#define MTC_ANET_MOBILE_EVDO_B      0x000C
#define MTC_ANET_MOBILE_LTE         0x000D
#define MTC_ANET_MOBILE_EHRPD       0x000E
#define MTC_ANET_MOBILE_HSPAP       0x000F
#define MTC_ANET_WIFI               0x0100
#define MTC_ANET_WIMAX              0x0600
#define MTC_ANET_BLUETOOTH          0x0700
#define MTC_ANET_ETHERNET           0x0900
#define MTC_ANET_MASK_CATEGORY      0xFF00
/** @} */

/** @brief MTC http sync status code. */
typedef enum tagMTC_SYNC_ERR_TYPE
{
    MTC_SYNC_NOT_START = 0, /**< @brief http sync not start */
    MTC_SYNC_SUCCESS,       /**< @brief http sync success */
    MTC_SYNC_AUTH_FAILED,   /**< @brief authentication failed, invalid user or password */
    MTC_SYNC_CONN_FAILED,   /**< @brief transport connect failed */
    MTC_SYNC_SEND_FAILED,   /**< @brief transport send failed */
    MTC_SYNC_RECV_FAILED,   /**< @brief transport received failed */
    MTC_SYNC_ERV_DISCED,    /**< @brief transport disconnected by server */
    MTC_SYNC_SERV_ERR,      /**< @brief server internal error */
    MTC_SYNC_REQ_TIMEOUT,   /**< @brief request timeout */
    MTC_SYNC_FORBIDDEN,     /**< @brief forbidden */
    MTC_SYNC_FAIL,          /**< @brief http sync number failed */
    MTC_SYNC_ERR_OTHER,     /**< @brief other */
}MTC_SYNC_ERR_TYPE;

/** @brief MTC use server type */
typedef enum EN_MTC_USE_SERV_TYPE
{
    EN_MTC_USE_SERV_1ST_SBC,          /* primary sbc server */
    EN_MTC_USE_SERV_2ND_SBC,          /* secondary sbc server */
    EN_MTC_USE_SERV_1ST_STG,          /* primary stg server */
    EN_MTC_USE_SERV_2ND_STG,          /* secondary stg server */
} EN_MTC_USE_SERV_TYPE;

/** @brief MTC get device ID type only for android devices */
typedef enum EN_MTC_DEVICE_ID_TYPE
{
    EN_MTC_DEVICE_ID_SERIAL = 0,          /* device serial number */
    EN_MTC_DEVICE_ID_IMEI,            /* device imei */
    EN_MTC_DEVICE_ID_MACADDR,         /* device mac address  */
    EN_MTC_DEVICE_ID_ANDROID_ID,      /* device android id */
} EN_MTC_DEVICE_ID_TYPE;

/**
 * @brief Initialize Client Resource.
 *
 * @param [in] pcProfDir Profile directory
 *
 * @retval ZOK Initialize client resource successfully.
 * @retval MTC_LCS_ERR_NEED_ACT_LICSEN, Initialize client resource failed, 
 * you should call Mtc_lcsActivate activate licenser .
 * &retval ZFAILED, Initialize client resource failed.
 * @see @ref Mtc_CliDestroy
 * Mtc_CliCfgSetLicenseFileName first
 */
ZFUNC ZINT Mtc_CliInit(ZCHAR *pcProfDir);

/**
 * @brief Destroy Client Resource.
 *
 * @see @ref Mtc_CliInit
 */
ZFUNC ZVOID Mtc_CliDestroy(ZFUNC_VOID);

/**
 * @brief Open a account.
 *
 * @param [in] pcUserName The account name.
 * If account name is ZNULL, it will load default profile information.
 * For change parameter, call @ref Mtc_CliDbSetLocalIp etc functions.
 *
 * @retval ZOK Open a account successfully.
 * @retval ZFAILED Initialize a account failed.
 *
 * @see @ref Mtc_CliClose
 */
ZFUNC ZINT Mtc_CliOpen(ZCHAR *pcUserName);

/**
 * @brief Close current account.
 *
 * @see @ref Mtc_CliOpen
 */
ZFUNC ZVOID Mtc_CliClose(ZFUNC_VOID);

/**
 * @brief Start Client Service.
 *
 * @retval ZOK Start client service successfully.
 * @retval ZFAILED Start client service failed.
 *
 * @see @ref Mtc_CliStop
 */
ZFUNC ZINT Mtc_CliStart(ZFUNC_VOID);

/**
 * @brief Stop Client Service.
 *
 * @see @ref Mtc_CliStart
 */
ZFUNC ZVOID Mtc_CliStop(ZFUNC_VOID);

/**
 * @brief Start to Login Client.
 * 
 * @param [in] iAccNetType The access network type from Mtc_GetAccessNetType
 * @param [in] pcAccNetIp The access network IP string.
 * If @ref Mtc_CliDbGetUserReg returns ZTRUE, Login result notified by callbacks 
 * which were set by @ref Mtc_CliCbSetRegOk, @ref Mtc_CliCbSetRegFailed, 
 * @ref Mtc_CliCbSetServLoginOk or @ref Mtc_CliCbSetLclLoginOk
 * or @ref Mtc_CliCbSetLoginFailed or Mtc_CliCbSetAuthInd. 
 * Otherwise, it means client needn't login to remote server,
 * and will return immediately without any GUI callback.
 *
 * @retval ZOK Client is logining.
 * @retval ZFAILED Client login failed.
 *
 * @see @ref Mtc_CliLogout
 */
ZFUNC ZINT Mtc_CliLogin(ZUINT iAccNetType, ZCONST ZCHAR *pcAccNetIp);

/**
 * @brief Start to Re-Login Client.
 * 
 * @param [in] iAccNetType The access network type from Mtc_GetAccessNetType
 * @param [in] pcAccNetIp The access network IP string.
 * If @ref Mtc_CliDbGetUserReg returns ZTRUE, Login result notified by callbacks 
 * which were set by @ref Mtc_CliCbSetRegOk, @ref Mtc_CliCbSetRegFailed, 
 * @ref Mtc_CliCbSetServLoginOk or @ref Mtc_CliCbSetLclLoginOk
 * or @ref Mtc_CliCbSetLoginFailed or Mtc_CliCbSetAuthInd. 
 * Otherwise, it means client needn't login to remote server,
 * and will return immediately without any GUI callback.
 *
 * @retval ZOK Client is logining.
 * @retval ZFAILED Client login failed.
 *
 * @see @ref Mtc_CliLogout
 */
ZFUNC ZINT Mtc_CliRelogin(ZUINT iAccNetType, ZCONST ZCHAR *pcAccNetIp);

/**
 * @brief Enter aka response to Login Client again.
 * 
 * If @ref Mtc_CliDbGetAuthType returns EN_MTC_IMS_AUTH_IMS_AKA, 
 * Login result will be notified by callback which was set by
 * @ref Mtc_CliCbSetAuthInd, then client must enter aka response to login again.
 *
 * @retval ZOK Client is logining.
 * @retval ZFAILED Client login failed.
 *
 * @see @ref Mtc_CliLogout
 */
ZFUNC ZINT Mtc_CliEnterAkaRsp(ZUINT iRegId, ZCHAR *pcRsp, ZCHAR *pcCk,
                ZCHAR *pcIk, ZCHAR *pcAuts);

/**
 * @brief Enter digest password to Login Client again.
 * 
 * If @ref Mtc_CliDbGetAuthType returns EN_MTC_IMS_AUTH_SIP_DIGEST, 
 * Login result will be notified by callback which was set by 
 * @ref Mtc_CliCbSetAuthInd if no password was avaliable before, 
 * then client must enter digest password to login again.
 *
 * @retval ZOK Client is logining.
 * @retval ZFAILED Client login failed.
 *
 * @see @ref Mtc_CliLogout
 */
ZFUNC ZINT Mtc_CliEnterDgstPwd(ZUINT iRegId, ZCHAR *pcPwd);

/**
 * @brief Refresh the registration.
 * 
 * This interface is try to send re-REGISTRE message to refresh the
 * registration information on the server. Although the SDK will send 
 * re-REGISTER automatically accroding to the expire time length, there still
 * be in some condition which the client wants to send re-REGISTER to keep
 * registration information valid. Like on mobile phone platfrom, the 
 * SDK may not be able to send re-REGISTER on time during background mode.
 * In these cases, the application should invoke this interface to send
 * re-REGISTER manually to discover errors maybe occured during background mode.
 * This interface must only be invoked after client has logined,
 * @ref Mtc_CliCbSetLclLoginOk.
 *
 * @retval ZOK Client send re-REGISTER ok.
 * @retval ZFAILED Client send re-REGISTER failed.
 *
 * @see @ref Mtc_CliLogin @ref Mtc_CliLogout
 */
ZFUNC ZINT Mtc_CliRefresh(ZFUNC_VOID);

/* mtc client keep alive */
ZFUNC ZINT Mtc_CliKeepAlive(ZFUNC_VOID);

/**
 * @brief Start to Logout Client.
 *
 * If Mtc_DbGetUserReg returns ZTRUE, Logout result will be notified by 
 * callbacks which were set by @ref Mtc_CliCbSetLclLogout and @ref Mtc_CliCbSetServLogout. 
 *
 * @retval ZOK Client is logouting.
 * @retval ZFAILED Client logout failed.
 *
 * @see @ref Mtc_CliLogin
 */
ZFUNC ZINT Mtc_CliLogout(ZFUNC_VOID);

/**
 * @brief Send INFO message.
 *
 * @param [in] pcType Body type string, ZNULL for "plain".
 * @param [in] pcInfo INFO message body string.
 *
 * @retval ZOK Send info ok.
 * @retval ZFAILED Send info failed.
 */
ZFUNC ZINT Mtc_CliInfo(ZCHAR *pcType, ZCHAR *pcInfo);

/**
 * @brief Get User Register State.
 *
 * @return Register State. State see @ref MTC_REG_STATE_IDLE...
 */
ZFUNC ZUINT Mtc_CliGetRegState(ZFUNC_VOID);

/**
 * @brief Get User Register Server Type.
 *
 * @return Register Server Type. State see @ref MTC_USE_SERV_TYPE...
 */
ZFUNC ZUINT Mtc_CliGetRegServType(ZFUNC_VOID);

/**
 * @brief Get User Register Date.
 *
 * @return Register Date. 
 */
ZFUNC ZTIME_T Mtc_CliGetRegDate(ZFUNC_VOID);

/**
 * @brief Get User did register flag.
 *
 * @return did register flag. 
 */
ZFUNC ZBOOL Mtc_CliGetDidReg(ZFUNC_VOID);

/**
 * @brief Client Drive Service.
 *
 * MTC service was implemented by MSF, for multi-thread mode,
 * MSF is running in independent thread, GUI is another one generally.
 * MTC implmented service login in GUI, so it is running in GUI.
 * When MSF need notify status to GUI, the event should transfered in 
 * two threads. For thread safety, service event was posted by 
 * GUI callback @ref Mtc_CliCbSetEvnt from MSF to GUI. 
 * Then GUI drive MTC by this service event.
 *
 * @param [in] zEvntId Service Event from RSD.
 *
 * @retval ZOK Drive Service successfully.
 * @retval ZFAILED Drive Service failed.
 *
 */
ZFUNC ZINT Mtc_CliDrive(ZEVNT zEvntId);

/**
 * @brief Detect available local IP address.
 *   It is available in register mode.
 *
 *   If user open it by @ref Mtc_CliCfgSetUseDetLclIp, Client will automatic
 *   call it before start services and login.
 * 
 * @return Available local IP detected.
 */
ZFUNC ZUINT Mtc_CliDetLclIp(ZFUNC_VOID);

/**
 * @brief Detect available local IPv6 address.
 *   It is available in register mode.
 *
 *   If user open it by @ref Mtc_CliCfgSetUseDetLclIp, Client will automatic
 *   call it before start services and login.
 * 
 * @param [out] pucIpv6 available local IP detected.
 *
 * @retval ZOK successfully.
 */
ZFUNC ZINT Mtc_CliDetLclIpv6(ZUCHAR* pucIpv6);

/**
 * @brief Detect and set the use ip address type.
 *
 * @retval ZOK detect and set the use ip address type successfully.
 */
ZFUNC ZINT Mtc_CliSetLclIpAddrType(ZFUNC_VOID);

/**
 * @brief Get Device Id string.
 *
 * @return Device Id string.
 */
ZFUNC ZCONST ZCHAR * Mtc_CliGetDevId(ZFUNC_VOID);

/**
 * @brief Get Device Id with type .
 *
 * @param [in] iType The device id  type EN_MTC_DEVICE_ID_TYPE.
 *
 * @return Device Id string.
 */
ZFUNC ZCONST ZCHAR * Mtc_CliGetDevIdX(ZUINT iType);

/**
 * @brief Network unavailable.
 *
 * @retval ZOK Network unavailable successfully.
 * @retval ZFAILED Network unavailable failed.
 */
ZFUNC ZINT Mtc_CliNetUnavailable(ZFUNC_VOID);

/**
 * @brief Check App.
 *
 * @retval ZOK Check App successfully.
 * @retval ZFAILED Check App failed.
 */
ZFUNC ZINT Mtc_CliChkApp(ZFUNC_VOID);

/**
 * @brief Force disconnect register connection.
 *        GUI no need to call this function, only for fixing UDP fake register.
 */
ZFUNC ZINT Mtc_CliRegDisc();

/**
 * @brief Get http sync result.
 *
 * @return Register State. State see @ref MTC_SYNC_ERR_TYPE...
 */
ZFUNC ZUINT Mtc_CliGetSyncResult();

/**
 * @brief UI call cb net changed, for android.
 * 
 * @param [in] iNetType The new network type EN_MTC_DEVICE_ID_TYPE.
 *
 */
ZFUNC ZINT Mtc_CliCallCbNetChanged(ZUINT iNetType);

/**
 * @brief Get User time diff with local.
 *
 * @return time diff with local. 
 */
ZFUNC ZINT Mtc_CliGetTimeDiff(ZFUNC_VOID);

/* mtc init heartbeat */

/**
 * @brief Init heartbeat detect.
 *
 * @param [in] iNetType The access network type from Mtc_GetAccessNetType 
 *
 * @return ZOK Init heartbeat detect successfully. 
 */
ZFUNC ZINT Mtc_CliInitHeartbeatDetect(ZUINT iNetType);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CLI_H__ */

