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
  File name     : mtc_cli_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2010-02-06
  Description   :
      Data structure and function declare required by MTC client database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CLI_DB_H__
#define _MTC_CLI_DB_H__

/**
 * @file mtc_cli_db.h
 * @brief MTC Client Database Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC PUSH token type */
#define MTC_PUSH_SERVER_IOS         "0"     /**< @brief push server of IOS */
#define MTC_PUSH_SERVER_IOS_ICSS    "01"    /**< @brief push server of IOS by chinasofti */
#define MTC_PUSH_SERVER_IOS_CMCC    "02"    /**< @brief push server of IOS by cmcc */
#define MTC_PUSH_SERVER_IOS_CMIC    "03"    /**< @brief push server of IOS by cmic */
#define MTC_PUSH_SERVER_IOS_COLLEGE "04"    /**< @brief push server of IOS by college */
#define MTC_PUSH_SERVER_IOS_HK      "05"    /**< @brief push server of IOS by Hong Kong */
#define MTC_PUSH_SERVER_HUAWEI      "1"     /**< @brief push server of HUAWEI */
#define MTC_PUSH_SERVER_XIAOMI      "2"     /**< @brief push server of XIAOMI */
#define MTC_PUSH_SERVER_AOI         "3"     /**< @brief push server of AOI */

/** @brief MTC transport type */
typedef enum EN_MTC_TPT_TYPE
{
    EN_MTC_TPT_UDP,                  /**< @brief UDP transport */
    EN_MTC_TPT_TCP,                  /**< @brief TCP transport */
    EN_MTC_TPT_TLS                   /**< @brief TLS transport */
} EN_MTC_TPT_TYPE;

/** @brief MTC tls method type */
typedef enum EN_MTC_TLS_METHOD_TYPE
{
    EN_MTC_TLS_METHOD_TLS1,          /**< @brief tls TLSv1.0 method */
    EN_MTC_TLS_METHOD_TLS1_1,        /**< @brief tls TLSv1.1 method */
    EN_MTC_TLS_METHOD_TLS1_2,        /**< @brief tls TLSv1.2 method */
} EN_MTC_TLS_METHOD_TYPE;

/** @brief MTC tls verify type */
typedef enum EN_MTC_TLS_VERY_TYPE
{
    EN_MTC_TLS_VERY_NONE,            /**< @brief tls verify none */
    EN_MTC_TLS_VERY_OPTION,          /**< @brief tls verify option */
    EN_MTC_TLS_VERY_OPTION_NO_CA,    /**< @brief tls verify option with no ca */
    EN_MTC_TLS_VERY_REQUIRE          /**< @brief tls verify require */
} EN_MTC_TLS_VERY_TYPE;

/** @brief MTC access network type */
typedef enum EN_MTC_ACC_NET_TYPE
{
    EN_MTC_ACC_NET_UNKNOWN,          /**< @brief unknown */
    EN_MTC_ACC_NET_IEEE_802_11,      /**< @brief IEEE-802.11 */
    EN_MTC_ACC_NET_IEEE_802_11A,     /**< @brief IEEE-802.11a". */
    EN_MTC_ACC_NET_IEEE_802_11B,     /**< @brief IEEE-802.11b". */
    EN_MTC_ACC_NET_IEEE_802_11G,     /**< @brief IEEE-802.11g */
    EN_MTC_ACC_NET_IEEE_802_11N,     /**< @brief IEEE-802.11n */
    EN_MTC_ACC_NET_3GPP_GERAN,       /**< @brief 3GPP-GERAN". */
    EN_MTC_ACC_NET_3GPP_UTRAN_FDD,   /**< @brief 3GPP-UTRAN-FDD". */
    EN_MTC_ACC_NET_3GPP_UTRAN_TDD,   /**< @brief 3GPP-UTRAN-TDD". */
    EN_MTC_ACC_NET_3GPP_E_UTRAN_FDD, /**< @brief 3GPP-E-UTRAN-FDD */
    EN_MTC_ACC_NET_3GPP_E_UTRAN_TDD, /**< @brief 3GPP-E-UTRAN-TDD */
    EN_MTC_ACC_NET_3GPP_UTRAN,       /**< @brief 3GPP-UTRAN */
    EN_MTC_ACC_NET_3GPP_E_UTRAN,     /**< @brief 3GPP-E-UTRAN */
    EN_MTC_ACC_NET_3GPP_WLAN,        /**< @brief 3GPP-WLAN */
    EN_MTC_ACC_NET_3GPP_GAN,         /**< @brief 3GPP-GAN */
    EN_MTC_ACC_NET_3GPP_HSPA,        /**< @brief 3GPP-HSPA */
    EN_MTC_ACC_NET_3GPP_CDMA2000,    /**< @brief 3GPP-CDMA2000". */
    EN_MTC_ACC_NET_3GPP2_1X,         /**< @brief 3GPP2-1X */
    EN_MTC_ACC_NET_3GPP2_1X_FEMTO,   /**< @brief 3GPP2-1X-Femto */
    EN_MTC_ACC_NET_3GPP2_1X_HRPD,    /**< @brief 3GPP2-1X-HRPD */
    EN_MTC_ACC_NET_3GPP2_UMB,        /**< @brief 3GPP2-UMB */
    EN_MTC_ACC_NET_ADSL,             /**< @brief ADSL */
    EN_MTC_ACC_NET_ADSL2,            /**< @brief ADSL2 */
    EN_MTC_ACC_NET_ADSL2X,           /**< @brief ADSL2+ */
    EN_MTC_ACC_NET_RADSL,            /**< @brief RADSL */
    EN_MTC_ACC_NET_SDSL,             /**< @brief SDSL */
    EN_MTC_ACC_NET_HDSL,             /**< @brief HDSL */
    EN_MTC_ACC_NET_HDSL2,            /**< @brief HDSL2 */
    EN_MTC_ACC_NET_G_SHDSL,          /**< @brief G.SHDSL */
    EN_MTC_ACC_NET_VDSL,             /**< @brief VDSL */
    EN_MTC_ACC_NET_IDSL,             /**< @brief IDSL */
    EN_MTC_ACC_NET_IEEE_802_3,       /**< @brief IEEE-802.3 */
    EN_MTC_ACC_NET_IEEE_802_3A,      /**< @brief IEEE-802.3a */
    EN_MTC_ACC_NET_IEEE_802_3E,      /**< @brief IEEE-802.3e */
    EN_MTC_ACC_NET_IEEE_802_3I,      /**< @brief IEEE-802.3i */
    EN_MTC_ACC_NET_IEEE_802_3J,      /**< @brief IEEE-802.3j */
    EN_MTC_ACC_NET_IEEE_802_3U,      /**< @brief IEEE-802.3u */
    EN_MTC_ACC_NET_IEEE_802_3AB,     /**< @brief IEEE-802.3ab */
    EN_MTC_ACC_NET_IEEE_802_3AE,     /**< @brief IEEE-802.3ae */
    EN_MTC_ACC_NET_IEEE_802_3AK,     /**< @brief IEEE-802.3ak */
    EN_MTC_ACC_NET_IEEE_802_3AQ,     /**< @brief IEEE-802.3aq */
    EN_MTC_ACC_NET_IEEE_802_3AN,     /**< @brief IEEE-802.3an */
    EN_MTC_ACC_NET_IEEE_802_3Y,      /**< @brief IEEE-802.3y */
    EN_MTC_ACC_NET_IEEE_802_3Z,      /**< @brief IEEE-802.3z */
    EN_MTC_ACC_NET_GPON,             /**< @brief GPON */
    EN_MTC_ACC_NET_XGPON1,           /**< @brief XGPON1 */
    EN_MTC_ACC_NET_GSTN,             /**< @brief GSTN */
} EN_MTC_ACC_NET_TYPE;

/** @brief MTC shown rcs switch type */
typedef enum EN_MTC_RCSE_SWITCH_TYPE
{
    EN_MTC_RCSE_SWITCH_PERM,         /**< @brief the setting is shown permanently */
    EN_MTC_RCSE_SWITCH_ROAMING,      /**< @brief the setting is only shown during roaming */
    EN_MTC_RCSE_SWITCH_NEVER         /**< @brief RCS Switch is never shown */
} EN_MTC_RCSE_SWITCH_TYPE;

/** @brief MTC ims authentication type */
typedef enum EN_MTC_IMS_AUTH_TYPE
{
    EN_MTC_IMS_AUTH_UNKNOWN,         /**< @brief unknown */
    EN_MTC_IMS_AUTH_EARLY_IMS,       /**< @brief Early IMS */
    EN_MTC_IMS_AUTH_IMS_AKA,         /**< @brief IMS AKA */
    EN_MTC_IMS_AUTH_SIP_DIGEST,      /**< @brief SIP DIGEST (without TLS) */
} EN_MTC_IMS_AUTH_TYPE;

/** @brief MTC register expires type */
typedef enum EN_MTC_REG_EXP_TYPE
{
    EN_MTC_REG_EXP_CONTACT,          /**< @brief expires value in register CONTACT header(default) */
    EN_MTC_REG_EXP_ALONE,            /**< @brief expires value in register EXPIRES header */
    EN_MTC_REG_EXP_BOTH,             /**< @brief expires value both in register  CONTACT & EXPIRES header */
} EN_MTC_REG_EXP_TYPE;

/** @brief MTC xcap authentication type */
typedef enum EN_MTC_XCAP_AUTH_TYPE
{
    EN_MTC_XCAP_AUTH_UNKNOWN,        /**< @brief unknown */
    EN_MTC_XCAP_AUTH_EARLY_IMS,      /**< @brief early ims */
    EN_MTC_XCAP_AUTH_DIGEST          /**< @brief digest */
} EN_MTC_XCAP_AUTH_TYPE;

/* @brief MTC pa authentication type */
typedef enum EN_MTC_PA_AUTH_TYPE
{
    EN_MTC_PA_AUTH_UNKNOW,           /**< @brief unknown */
    EN_MTC_PA_AUTH_DIGEST,           /**< @brief digest */
    EN_MTC_PA_AUTH_UA                /**< @brief unify authentication */
} EN_MTC_PA_AUTH_TYPE;

/* @brief MTC profile authentication type */
typedef enum EN_MTC_PROFILE_AUTH_TYPE
{
    EN_MTC_PROFILE_AUTH_UNKNOW,           /**< @brief unknown */
    EN_MTC_PROFILE_AUTH_DIGEST,           /**< @brief digest */
    EN_MTC_PROFILE_AUTH_UA                /**< @brief unify authentication */
} EN_MTC_PROFILE_AUTH_TYPE;

/* @brief MTC qrcard authentication type */
typedef enum EN_MTC_QRCARD_AUTH_TYPE
{
    EN_MTC_QRCARD_AUTH_UNKNOW,           /**< @brief unknown */
    EN_MTC_QRCARD_AUTH_DIGEST,           /**< @brief digest */
    EN_MTC_QRCARD_AUTH_UA                /**< @brief unify authentication */
} EN_MTC_QRCARD_AUTH_TYPE;

/** @brief MTC uri format type */
typedef enum EN_MTC_URI_FMT_TYPE
{
    EN_MTC_URI_FMT_TEL,              /**< @brief tel uri */
    EN_MTC_URI_FMT_SIP,              /**< @brief sip uri */
} EN_MTC_URI_FMT_TYPE;

/** @brief MTC data bearer type */
typedef enum EN_MTC_DATA_BEARER_TYPE
{
    EN_MTC_DATA_BEARER_UNKNOWN,      /**< @brief unknown */
    EN_MTC_DATA_BEARER_2G,           /**< @brief 2G */
    EN_MTC_DATA_BEARER_EDGE,         /**< @brief EDGE */
    EN_MTC_DATA_BEARER_3G,           /**< @brief 3G */
    EN_MTC_DATA_BEARER_HSPA,         /**< @brief HSPA */
    EN_MTC_DATA_BEARER_LTE,          /**< @brief LTE */
    EN_MTC_DATA_BEARER_WIFI,         /**< @brief WIFI */
} EN_MTC_DATA_BEARER_TYPE;

/** @brief MTC roam type */
typedef enum EN_MTC_ROAM_TYPE
{
    EN_MTC_ROAM_NONE,                /**< @brief none */
    EN_MTC_ROAM_INT,                 /**< @brief international */
    EN_MTC_ROAM_NAT,                 /**< @brief national */
} EN_MTC_ROAM_TYPE;

/** @brief MTC heart beat type */
typedef enum EN_MTC_KEEP_ALIVE_TYPE
{
    EN_MTC_KEEP_ALIVE_DISABLE,       /**< @brief disable */
    EN_MTC_KEEP_ALIVE_SIP,           /**< @brief use SIP keep alive */
    EN_MTC_KEEP_ALIVE_OPTIONS,       /**< @brief use OPTIONS keep alive */
} EN_MTC_KEEP_ALIVE_TYPE;

/** @brief MTC MSRP keep alive type */
typedef enum EN_MTC_MSRP_KEEP_ALIVE_TYPE
{
    EN_MTC_MSRP_KEEP_ALIVE_DISABLE, /**< @brief disable keep alive */
    EN_MTC_MSRP_KEEP_ALIVE_CRLN,    /**< @brief use "\r\n\r\n" */
    EN_MTC_MSRP_KEEP_ALIVE_MSG,     /**< @brief use bodiless message */
} EN_MTC_MSRP_KEEP_ALIVE_TYPE;

/** @brief MTC Nat Traversal Mode type */
typedef enum EN_MTC_NAT_TRAVERSAL_TYPE
{
    EN_MTC_NAT_TRAVERSAL_OFF,        /**< @brief not use Nat Traversal */
    EN_MTC_NAT_TRAVERSAL_STUN,       /**< @brief using STUN */
    EN_MTC_NAT_TRAVERSAL_TURN,       /**< @brief using TURN */
    EN_MTC_NAT_TRAVERSAL_ICE,        /**< @brief using ICE */
} EN_MTC_NAT_TRAVERSAL_TYPE;

/** @brief MTC stg use type */
typedef enum EN_MTC_STG_USETYPE
{
    EN_MTC_STG_USETYPE_CLOSE,       /**< @brief close stg */
    EN_MTC_STG_USETYPE_OPEN,        /**< @brief open stg */
    EN_MTC_STG_USETYPE_PRIORITY_OPEN /**< @brief priority open stg */
} EN_MTC_STG_USETYPE;

/** @brief MTC stg tunnel type */
typedef enum EN_MTC_STG_TRANSPORT
{
    EN_MTC_STG_TRANSPORT_UDP,       /**< @brief udp tunnel */
    EN_MTC_STG_TRANSPORT_TCP,       /**< @brief tcp tunnel */
    EN_MTC_STG_TRANSPORT_TLS,       /**< @brief tls tunnel */
    EN_MTC_STG_TRANSPORT_DTLS       /**< @brief dtls tunnel */
} EN_MTC_STG_TRANSPORT;

/* mtc publich user id policy */
typedef enum EN_MTC_UID_POLICY_TYPE
{
    EN_MTC_UID_POLICY_DFT,           /* use uri for register */
    EN_MTC_UID_POLICY_FIRST,         /* use uri in P-Associated-URI */
    EN_MTC_UID_POLICY_SIP_MSISDN,           /* use sip MSISDN uri in P-Associated-URI */
    EN_MTC_UID_POLICY_SIP_IMSI,           /* use sip IMSI uri in P-Associated-URI */    
    EN_MTC_UID_POLICY_TEL,           /* use tel uri in P-Associated-URI */
    EN_MTC_UID_POLICY_SIZE
} EN_MTC_UID_POLICY_TYPE;

/** @brief MTC address type */
typedef enum EN_MTC_ADDR_TYPE
{
    EN_MTC_ADDR_IPV4,                  /* ipv4 adress */
    EN_MTC_ADDR_IPV6,                  /* ipv6 adress */        
    EN_MTC_ADDR_FQDN,                /* fqdn */
} EN_MTC_ADDR_TYPE;

/* msp http proxy type */
typedef enum EN_MTC_HTTP_PROXY_TYPE
{
    EN_MTC_HTTP_PROXY_OFF,
    EN_MTC_HTTP_PROXY_HTTP,
    EN_MTC_HTTP_PROXY_HTTPS,
} EN_MTC_HTTP_PROXY_TYPE;

/**
 * @brief Apply all data change to all components.
 *
 * @retval ZOK Apply data change successfully.
 * @retval ZFAILED Apply data change failed.
 */
ZFUNC ZINT Mtc_CliDbApplyAll(ZFUNC_VOID);

/**
 * @brief Get data change apply flag.
 *
 * @return Data change apply flag.
 *
 * @see @ref Mtc_CliDbSetApplyChange
 */
ZFUNC ZBOOL Mtc_CliDbGetApplyChange(ZFUNC_VOID);

/**
 * @brief Set data change apply flag realtime.
 * If data change apply flag is ZTRUE, below db set
 * functions(ex @ref Mtc_CliDbSetUserName) will apply change immediately.
 *
 * @retval ZOK Set data change apply flag successfully.
 * @retval ZFAILED Set data change apply flag failed.
 *
 * @see @ref Mtc_CliDbGetApplyChange
 */
ZFUNC ZINT Mtc_CliDbSetApplyChange(ZBOOL bApply);

/**
 * @brief Get local IP from database.
 *
 * @return The string of local IP string.
 *
 * @see @ref Mtc_CliDbSetLocalIp
 */
ZFUNC ZCHAR * Mtc_CliDbGetLocalIp(ZFUNC_VOID);

/**
 * @brief Get local IP from database.
 *
 * @return The local IP value in network byte order.
 *
 * @see @ref Mtc_CliDbSetLocalIp
 */
ZFUNC ZUINT Mtc_CliDbGetLocalIpX(ZFUNC_VOID);

/**
 * @brief Set local IP.
 *
 * @param [in] pcIp The IP value in network string order.
 *
 * @retval ZOK Set local IP successfully.
 * @retval ZFAILED Set local IP failed.
 *
 * @see @ref Mtc_CliDbGetLocalIp
 */
ZFUNC ZINT Mtc_CliDbSetLocalIp(ZCHAR *pcIp);

/**
 * @brief Get local IPv6 from database.
 *
 * @return The string of local IPv6.
 *
 * @see @ref Mtc_CliDbSetLocalIpv6
 */
ZFUNC ZCHAR * Mtc_CliDbGetLocalIpv6();

/**
 * @brief Set local IPv6.
 *
 * @param [in] pcIp The IPv6 value in network string order.
 *
 * @retval ZOK Set local IPv6 successfully.
 * @retval ZFAILED Set local IPv6 failed.
 *
 * @see @ref Mtc_CliDbGetLocalIpv6
 */
ZFUNC ZINT Mtc_CliDbSetLocalIpv6(ZCHAR *pcIp);

/**
 * @brief Get user agent from database.
 *
 * @return The user agent.
 *
 * @see @ref Mtc_CliDbSetUserAgent
 */
ZFUNC ZCHAR * Mtc_CliDbGetUserAgent();

/**
 * @brief Set user agent.
 *
 * @param [in] pcName The user agent.
 *
 * @retval ZOK Set user agent successfully.
 * @retval ZFAILED Set user agent failed.
 *
 * @see @ref Mtc_CliDbGetUserAgent
 */
ZFUNC ZINT Mtc_CliDbSetUserAgent(ZCONST ZCHAR *pcName);

/**
 * @brief Get IP multimedia public identity from database.
 *
 * @return The string of impu.
 *
 * @see @ref Mtc_CliDbSetImpu
 */
ZFUNC ZCHAR * Mtc_CliDbGetImpu(ZFUNC_VOID);

/**
 * @brief Set IP multimedia public identity.
 *
 * @param [in] pcName The string of impu.
 *
 * @retval ZOK Set impu successfully.
 * @retval ZFAILED Set impu failed.
 *
 * @see @ref Mtc_CliDbGetImpu
 */
ZFUNC ZINT Mtc_CliDbSetImpu(ZCHAR *pcImpu);

/**
 * @brief Get IP multimedia public identity of PC client from database.
 *
 * @return The string of PC impu.
 *
 * @see @ref Mtc_CliDbSetPcImpu
 */
ZFUNC ZCHAR * Mtc_CliDbGetPcImpu(ZFUNC_VOID);

/**
 * @brief Set IP multimedia public identity of PC client.
 *
 * @param [in] pcName The string of impu.
 *
 * @retval ZOK Set PC impu successfully.
 * @retval ZFAILED Set PC impu failed.
 *
 * @see @ref Mtc_CliDbGetPcImpu
 */
ZFUNC ZINT Mtc_CliDbSetPcImpu(ZCHAR *pcPcImpu);

/**
 * @brief Set user state.
 *
 * @param [in] iUserState The uint of user state 0 is general and 1 is restricted.
 *
 * @retval ZOK Set user state successfully.
 * @retval ZFAILED Set user state failed.
 *
 * @see @ref Mtc_CliDbGetUserState
 */
ZFUNC ZINT Mtc_CliDbSetUserState(ZUINT iUserState);

/**
 * @brief Get user state.
 *
 * @return the uint of user state  0 is general and 1 is restricted
 *
 * @see @ref Mtc_CliDbGetUserState
 */
ZFUNC ZUINT Mtc_CliDbGetUserState(ZFUNC_VOID);

/**
 * @brief Get user name from database.
 *
 * @return The string of user name.
 *
 * @see @ref Mtc_CliDbSetUserName
 */
ZFUNC ZCHAR * Mtc_CliDbGetUserName(ZFUNC_VOID);

/**
 * @brief Set user name.
 *
 * @param [in] pcName The string of user name.
 *
 * @retval ZOK Set user name successfully.
 * @retval ZFAILED Set user name failed.
 *
 * @see @ref Mtc_CliDbGetUserName
 */
ZFUNC ZINT Mtc_CliDbSetUserName(ZCHAR *pcName);

/**
 * @brief Get nick name from database.
 *
 * @return The string of nick name.
 *
 * @see @ref Mtc_CliDbSetNickName
 */
ZFUNC ZCHAR * Mtc_CliDbGetNickName(ZFUNC_VOID);

/**
 * @brief Set nick name.
 *
 * @param [in] pcName The string of nick name.
 *
 * @retval ZOK Set nick name successfully.
 * @retval ZFAILED Set nick name failed.
 *
 * @see @ref Mtc_CliDbGetNickName
 */
ZFUNC ZINT Mtc_CliDbSetNickName(ZCHAR *pcName);

/**
 * @brief Get authorization name from database.
 *
 * @return The string of authorization name.
 *
 * @see @ref Mtc_CliDbSetAuthName
 */
ZFUNC ZCHAR * Mtc_CliDbGetAuthName(ZFUNC_VOID);

/**
 * @brief Get authorization realm from database.
 *
 * @return The string of authorization realm.
 *
 * @see @ref Mtc_CliDbSetAuthRealm
 */
ZFUNC ZCHAR * Mtc_CliDbGetAuthRealm(ZFUNC_VOID);

/**
 * @brief Set authorization name.
 *
 * @param [in] pcName The string of authorization name.
 *
 * @retval ZOK Set authorization name successfully.
 * @retval ZFAILED Set authorization name failed.
 *
 * @see @ref Mtc_CliDbGetAuthName
 */
ZFUNC ZINT Mtc_CliDbSetAuthName(ZCHAR *pcName);

/**
 * @brief Set authorization realm.
 *
 * @param [in] pcRealm The string of authorization realm.
 *
 * @retval ZOK Set authorization realm successfully.
 * @retval ZFAILED Set authorization realm failed.
 *
 * @see @ref Mtc_CliDbGetAuthRealm
 */
ZFUNC ZINT Mtc_CliDbSetAuthRealm(ZCHAR *pcRealm);

/**
 * @brief Get authorization password from database.
 *
 * @return The string of authorization password.
 *
 * @see @ref Mtc_CliDbSetAuthPass
 */
ZFUNC ZCHAR * Mtc_CliDbGetAuthPass(ZFUNC_VOID);

/**
 * @brief Set authorization password.
 *
 * @param [in] pcPass The string of authorization password.
 *
 * @retval ZOK Set authorization password successfully.
 * @retval ZFAILED Set authorization password failed.
 *
 * @see @ref Mtc_CliDbGetAuthPass
 */
ZFUNC ZINT Mtc_CliDbSetAuthPass(ZCHAR *pcPass);

/**
 * @brief Get Phone Context.
 *
 * @retval The string of phone context.
 *
 * @see @ref Mtc_CliDbSetPhoneContext
 */
ZFUNC ZCHAR * Mtc_CliDbGetPhoneContext();

/**
 * @brief Set Phone Context.
 *
 * @param [in] pcPhoneContext The string of Phone Context.
 *
 * @retval ZOK Set Phone Context successfully.
 * @retval ZFAILED Set Phone Context failed.
 *
 * @see @ref Mtc_CliDbGetPhoneContext
 */
ZFUNC ZINT Mtc_CliDbSetPhoneContext(ZCHAR *pcPhoneContext);

/**
 * @brief Get the type of IMS authentication for the user.
 *
 * @return IMS authentication type, @see @ref EN_MTC_IMS_AUTH_TYPE.
 *
 * @see @ref Mtc_CliDbSetAuthType
 */
ZFUNC ZUINT Mtc_CliDbGetAuthType(ZFUNC_VOID);

/**
 * @brief Set authorization type.
 *
 * @param [in] iType The authentication type, @see @ref EN_MTC_IMS_AUTH_TYPE.
 *
 * @retval ZOK Set authorization type successfully.
 * @retval ZFAILED Set authorization type failed.
 *
 * @see @ref Mtc_CliDbGetAuthType
 */
ZFUNC ZINT Mtc_CliDbSetAuthType(ZUINT iType);

/**
 * @brief Get the roam type for the user.
 *
 * @return The roam type, @see @ref EN_MTC_ROAM_TYPE.
 *
 * @see @ref Mtc_CliDbSetRoamType
 */
ZFUNC ZUINT Mtc_CliDbGetRoamType();

/**
 * @brief Set roam type.
 *
 * @param [in] iType The roam type, @see @ref EN_MTC_ROAM_TYPE.
 *
 * @retval ZOK Set roam type successfully.
 * @retval ZFAILED Set roam type failed.
 *
 * @see @ref Mtc_CliDbGetRoamType
 */
ZFUNC ZINT Mtc_CliDbSetRoamType(ZUINT iType);

/**
 * @brief Get support no digest in new REGISTER.
 *
 * @retval ZTRUE Indicates support no digest.
 * @retval ZFALSE Indicates not support no digest.
 *
 * @see @ref Mtc_CliDbSetRegNoDigest
 */
ZFUNC ZBOOL Mtc_CliDbGetRegNoDigest(ZFUNC_VOID);

/**
 * @brief Set support no digest in new REGISTER.
 *
 * @param [in] bEnable The support flag.
 *
 * @retval ZOK Set support flag successfully.
 * @retval ZFAILED Set support flag failed.
 *
 * @see @ref Mtc_CliDbGetRegNoDigest
 */
ZFUNC ZINT Mtc_CliDbSetRegNoDigest(ZBOOL bEnable);

/**
 * @brief Get keep alive type.
 *
 * @return @ref EN_MTC_KEEP_ALIVE_TYPE.
 *
 * @see @ref Mtc_CliDbSetKeepAliveType
 */
ZFUNC ZUINT Mtc_CliDbGetKeepAliveType();

/**
 * @brief Set keep alive type.
 *
 * @param [in] IType @ref EN_MTC_KEEP_ALIVE_TYPE.
 *
 * @retval ZOK Set keep alive successfully.
 * @retval ZFAILED Set keep alive failed.
 *
 * @see @ref Mtc_CliDbGetKeepAliveType
 */
ZFUNC ZINT Mtc_CliDbSetKeepAliveType(ZUINT IType);

/**
 * @brief Get heart beat timer length on ps, in seconds.
 *
 * @retval The length of heart beat timer on ps, default is 300 seconds.
 *
 * @see @ref Mtc_CliDbSetHeartbeatTmr
 */
ZFUNC ZUINT Mtc_CliDbGetHeartbeatTmr();

/**
 * @brief Set heart beat timer length on ps, in seconds.
 *
 * @param [in] iTmrLen The heart beat timer length on ps.
 *
 * @retval ZOK Set heart beat timer length on ps successfully.
 * @retval ZFAILED Set heart beat timer length on ps failed.
 *
 * @see @ref Mtc_CliDbGetHeartbeatTmr
 */
ZFUNC ZINT Mtc_CliDbSetHeartbeatTmr(ZUINT iTmrLen);

/**
 * @brief Get heart beat timer length on wifi, in seconds.
 *
 * @retval THE length of heart beat timer, default is 150 seconds.
 *
 * @see @ref Mtc_CliDbSetWifiHeartbeatTmr
 */
ZFUNC ZUINT Mtc_CliDbGetWifiHeartbeatTmr();

/**
 * @brief Set heart beat timer length on wifi, in seconds.
 *
 * @param [in] iTmrLen The heart beat timer length on wifi.
 *
 * @retval ZOK Set heart beat timer length on wifi successfully.
 * @retval ZFAILED Set heart beat timer length on wifi failed.
 *
 * @see @ref Mtc_CliDbGetWifiHeartbeatTmr
 */
ZFUNC ZINT Mtc_CliDbSetWifiHeartbeatTmr(ZUINT iTmrLen);

/**
 * @brief Get user register option from database.
 *
 * @retval ZTRUE Register to server.
 * @retval ZFALSE Do not register.
 *
 * @see @ref Mtc_CliDbSetUserReg
 */
ZFUNC ZBOOL Mtc_CliDbGetUserReg(ZFUNC_VOID);

/**
 * @brief Get client proxy option.
 *
 * @retval ZTRUE Support proxy option.
 * @retval ZFALSE Do not Support proxy option.
 *
 * @see @ref Mtc_CliDbSetProxyEnable
 */
ZFUNC ZBOOL Mtc_CliDbGetProxyEnable(ZFUNC_VOID);

/**
 * @brief Set client proxy option.
 *
 * @param [in] bEnable If ZTRUE, client support proxy to server.
 * Otherwise it needn't proxy.
 *
 * @retval ZOK Set client proxy option successfully.
 * @retval ZFAILED Set client proxy option failed.
 *
 * @see @ref Mtc_CliDbGetProxyEnable
 */
ZFUNC ZINT Mtc_CliDbSetProxyEnable(ZBOOL bEnable);

/**
 * @brief Set user register and proxy option.
 *
 * @param [in] bEnable If ZTRUE, register to server.Otherwise it needn't register.
 *
 * @retval ZOK Set user register option successfully.
 * @retval ZFAILED Set user register option failed.
 *
 * @see @ref Mtc_CliDbGetUserReg
 */
ZFUNC ZINT Mtc_CliDbSetUserReg(ZBOOL bEnable);

/**
 * @brief Get user tag converg flag in REGISTER from database.
 *
 * @retval ZTRUE the feature tag in REGISTER will converg.
 * @retval ZFALSE the feature tag in REGISTER will not converg.
 *
 * @see @ref Mtc_CliDbSetRegTagConverg
 */
ZFUNC ZBOOL Mtc_CliDbGetRegTagConverg();

/**
 * @brief Set user flag of tag converging in register.
 *
 * @param [in] bTagConverg If ZTRUE, the feature tag in REGISTER will converg.
 *
 * @retval ZOK Set flag of tag converging in REGISTER successfully.
 * @retval ZFAILED Set flag of tag converging in REGISTER failed.
 *
 * @see @ref Mtc_CliDbGetRegTagConverg
 */
ZFUNC ZINT Mtc_CliDbSetRegTagConverg(ZBOOL bTagConverg);

/**
 * @brief Set user register detect option.
 *
 * @param [in] bEnable If ZTRUE, detect register server.
 *
 * @retval ZOK Set detect option successfully.
 * @retval ZFAILED Set detect option failed.
 *
 * @see @ref Mtc_CliDbGetUserRegDetect
 */
ZFUNC ZINT Mtc_CliDbSetUserRegDetect(ZBOOL bEnable);

/**
 * @brief Get user register detect option from database.
 *
 * @retval ZTRUE Detect register.
 * @retval ZFALSE Do not detect register.
 *
 * @see @ref Mtc_CliDbSetUserRegDetect
 */
ZFUNC ZBOOL Mtc_CliDbGetUserRegDetect(ZFUNC_VOID);

/**
 * @brief Get register IP from database.
 *
 * @return The string of the sip register and proxy IP.
 *
 * @see @ref Mtc_CliDbSetSipRegIp
 */
ZFUNC ZCHAR * Mtc_CliDbGetSipRegIp(ZFUNC_VOID);

/**
 * @brief Set the sip register and proxy IP.
 *
 * @param [in] pcIp The sip register and proxy IP.
 *
 * @retval ZOK Set the sip register IP successfully.
 * @retval ZFAILED Set the sip register IP failed.
 *
 * @see @ref Mtc_CliDbGetSipRegIp
 */
ZFUNC ZINT Mtc_CliDbSetSipRegIp(ZCHAR *pcIp);

/**
 * @brief Get register transport from database.
 *
 * @return The transport of the sip register and proxy.
 *         Transport type @ref EN_MTC_TPT_TYPE includes 
 *         @ref EN_MTC_TPT_UDP, @ref EN_MTC_TPT_TCP and @ref EN_MTC_TPT_TLS. 
 *
 * @see @ref Mtc_CliDbSetSipRegTpt
 */
ZFUNC ZUCHAR Mtc_CliDbGetSipRegTpt(ZFUNC_VOID);

/**
 * @brief Set register proxy transport.
 *
 * @param [in] ucTpt Transport type, @ref EN_MTC_TPT_TYPE includes 
 *             @ref EN_MTC_TPT_UDP, @ref EN_MTC_TPT_TCP and @ref EN_MTC_TPT_TLS. 
 *
 * @retval ZOK Set the sip register transport successfully.
 * @retval ZFAILED Set the sip register transport failed.
 *
 * @see @ref Mtc_CliDbGetSipRegTpt
 */
ZFUNC ZINT Mtc_CliDbSetSipRegTpt(ZUCHAR ucTpt);

/**
 * @brief Get register udp port from database.
 *
 * @return Register port.
 *
 * @see @ref Mtc_CliDbSetSipRegUdpPort
 */
ZFUNC ZUINT Mtc_CliDbGetSipRegUdpPort(ZFUNC_VOID);

/**
 * @brief Set register udp port.
 *
 * @param [in] iPort Register udp port .

 * @retval ZOK Set Register port successfully.
 * @retval ZFAILED Set Register port failed.
 *
 * @see @ref Mtc_CliDbGetSipRegUdpPort
 */
ZFUNC ZINT Mtc_CliDbSetSipRegUdpPort(ZUINT iPort);

/**
 * @brief Get register tcp port from database.
 *
 * @return Register port.
 *
 * @see @ref Mtc_CliDbSetSipRegTcpPort
 */
ZFUNC ZUINT Mtc_CliDbGetSipRegTcpPort(ZFUNC_VOID);

/**
 * @brief Set register port.
 *
 * @param [in] iPort Register tcp port .

 * @retval ZOK Set Register port successfully.
 * @retval ZFAILED Set Register port failed.
 *
 * @see @ref Mtc_CliDbGetSipRegTcpPort
 */
ZFUNC ZINT Mtc_CliDbSetSipRegTcpPort(ZUINT iPort);

/**
 * @brief Get register tls port from database.
 *
 * @return Register port.
 *
 * @see @ref Mtc_CliDbSetSipRegTlsPort
 */
ZFUNC ZUINT Mtc_CliDbGetSipRegTlsPort(ZFUNC_VOID);

/**
 * @brief Set register port.
 *
 * @param [in] iPort Register tls port .

 * @retval ZOK Set Register port successfully.
 * @retval ZFAILED Set Register port failed.
 *
 * @see @ref Mtc_CliDbGetSipRegTlsPort
 */
ZFUNC ZINT Mtc_CliDbSetSipRegTlsPort(ZUINT iPort);

/**
 * @brief Get register stun port from database.
 *
 * @return Register stun port.
 *
 * @see @ref Mtc_CliDbSetSipRegStunPort
 */
ZFUNC ZULONG Mtc_CliDbGetSipRegStunPort(ZFUNC_VOID);

/**
 * @brief Set register port.
 *
 * @param [in] iPort Register stun port .

 * @retval ZOK Set Register port successfully.
 * @retval ZFAILED Set Register port failed.
 *
 * @see @ref Mtc_CliDbGetSipRegStunPort
 */
ZFUNC ZINT Mtc_CliDbSetSipRegStunPort(ZUINT iPort);

/**
 * @brief Get secondary register IP from database.
 *
 * @return The string of the sip register and proxy IP.
 *
 * @see @ref Mtc_CliDbSet2ndSipRegIp
 */
ZFUNC ZCHAR * Mtc_CliDbGet2ndSipRegIp(ZFUNC_VOID);

/**
 * @brief Set the secondary sip register and proxy IP.
 *
 * @param [in] pcIp The sip register and proxy IP.
 *
 * @retval ZOK Set the sip register IP successfully.
 * @retval ZFAILED Set the sip register IP failed.
 *
 * @see @ref Mtc_CliDbGet2ndSipRegIp
 */
ZFUNC ZINT Mtc_CliDbSet2ndSipRegIp(ZCHAR *pcIp);

/**
 * @brief Get secondary register udp port from database.
 *
 * @return Register port.
 *
 * @see @ref Mtc_CliDbSet2ndSipRegUdpPort
 */
ZFUNC ZUINT Mtc_CliDbGet2ndSipRegUdpPort(ZFUNC_VOID);

/**
 * @brief Set secondary register udp port.
 *
 * @param [in] iPort Register udp port .

 * @retval ZOK Set Register port successfully.
 * @retval ZFAILED Set Register port failed.
 *
 * @see @ref Mtc_CliDbGet2ndSipRegUdpPort
 */
ZFUNC ZINT Mtc_CliDbSet2ndSipRegUdpPort(ZUINT iPort);

/**
 * @brief Get secondary register  tcp port from database.
 *
 * @return Register port.
 *
 * @see @ref Mtc_CliDbSet2ndSipRegTcpPort
 */
ZFUNC ZUINT Mtc_CliDbGet2ndSipRegTcpPort(ZFUNC_VOID);

/**
 * @brief Set secondary register port.
 *
 * @param [in] iPort Register tcp port .

 * @retval ZOK Set Register port successfully.
 * @retval ZFAILED Set Register port failed.
 *
 * @see @ref Mtc_CliDbGet2ndSipRegTcpPort
 */
ZFUNC ZINT Mtc_CliDbSet2ndSipRegTcpPort(ZUINT iPort);

/**
 * @brief Get secondary register  tls port from database.
 *
 * @return Register port.
 *
 * @see @ref Mtc_CliDbSet2ndSipRegTlsPort
 */
ZFUNC ZUINT Mtc_CliDbGet2ndSipRegTlsPort(ZFUNC_VOID);

/**
 * @brief Set secondary register port.
 *
 * @param [in] iPort Register tls port .

 * @retval ZOK Set Register port successfully.
 * @retval ZFAILED Set Register port failed.
 *
 * @see @ref Mtc_CliDbGet2ndSipRegTlsPort
 */
ZFUNC ZINT Mtc_CliDbSet2ndSipRegTlsPort(ZUINT iPort);

/**
 * @brief Get secondary register  stun port from database.
 *
 * @return Register stun port.
 *
 * @see @ref Mtc_CliDbSet2ndSipRegStunPort
 */
ZFUNC ZULONG Mtc_CliDbGet2ndSipRegStunPort(ZFUNC_VOID);

/**
 * @brief Set secondary register port.
 *
 * @param [in] iPort Register stun port .

 * @retval ZOK Set Register port successfully.
 * @retval ZFAILED Set Register port failed.
 *
 * @see @ref Mtc_CliDbGet2ndSipRegStunPort
 */
ZFUNC ZINT Mtc_CliDbSet2ndSipRegStunPort(ZUINT iPort);

/**
 * @brief Get register expires time.
 *
 * @return Register expires time.
 *
 * @see @ref Mtc_CliDbGetRegExpire
 */
ZFUNC ZUINT Mtc_CliDbGetRegExpire();

/**
 * @brief Set register expires time.
 *
 * @param [in] iExpires Register expires time.

 * @retval ZOK Set Register expires successfully.
 * @retval ZFAILED Set Register expires failed.
 *
 * @see @ref Mtc_CliDbGetRegExpire
 */
ZFUNC ZINT Mtc_CliDbSetRegExpire(ZUINT iExpires);

/**
 * @brief Get the type of register expires.
 *
 * @return register expires type, @see @ref EN_MTC_REG_EXP_TYPE.
 *
 * @see @ref Mtc_CliDbGetRegExpType
 */
ZFUNC ZUINT Mtc_CliDbGetRegExpireType(ZFUNC_VOID);

/**
 * @brief Set register expires type.
 *
 * @param [in] iType The expires type, @see @ref EN_MTC_REG_EXP_TYPE.
 *
 * @retval ZOK Set expires type successfully.
 * @retval ZFAILED Set expires type failed.
 *
 * @see @ref Mtc_CliDbGetRegExpireType
 */
ZFUNC ZINT Mtc_CliDbSetRegExpireType(ZUINT iType);

/**
 * @brief Get subscribe register expires time.
 *
 * @return subscribe register expires time.
 *
 * @see @ref Mtc_CliDbSetSubsRegExpire
 */
ZFUNC ZUINT Mtc_CliDbGetSubsRegExpire();

/**
 * @brief Set subscribe register expires time.
 *
 * @param [in] iExpires subscribe register expires time.

 * @retval ZOK Set subscribe register expires successfully.
 * @retval ZFAILED Set subscribe register expires failed.
 *
 * @see @ref Mtc_CliDbGetSubsRegExpire
 */
ZFUNC ZINT Mtc_CliDbSetSubsRegExpire(ZUINT iExpires);

/**
 * @brief Get the sip register realm from database.
 *
 * @return The string of sip register realm.
 *
 * @see @ref Mtc_CliDbSetSipRegRealm
 */
ZFUNC ZCHAR * Mtc_CliDbGetSipRegRealm(ZFUNC_VOID);

/**
 * @brief Set the sip register realm.
 *
 * @param [in] pcRealm The sip register realm.
 *
 * @retval ZOK Set the sip register realm successfully.
 * @retval ZFAILED Set the sip register realm failed.
 *
 * @see @ref Mtc_CliDbGetSipRegRealm
 */
ZFUNC ZINT Mtc_CliDbSetSipRegRealm(ZCHAR *pcRealm);

/**
 * @brief Get the msrp keep alive type from database.
 *
 * @return The keep alive type, @see @ref keep EN_MTC_MSRP_KEEP_ALIVE_TYPE.
 *
 * @see @ref Mtc_CliDbSetMsrpKeepAliveType
 */
ZFUNC ZUINT Mtc_CliDbGetMsrpKeepAliveType();

/**
 * @brief Set the msrp keep alive type.
 *
 * @param [in] iKeepAliveType The msrp keep alive type, @see @ref EN_MTC_MSRP_KEEP_ALIVE_TYPE.
 *
 * @retval ZOK Set the msrp keep alive type successfully.
 * @retval ZFAILED Set the msrp keep alive type failed.
 *
 * @see @ref Mtc_CliDbGetMsrpKeepAliveType
 */
ZFUNC ZINT Mtc_CliDbSetMsrpKeepAliveType(ZUINT iKeepAliveType);

/**
 * @brief Get the msrp keep alive interval time in seconds from database.
 *
 * @return The keep alive interval time in seconds.
 *
 * @see @ref Mtc_CliDbSetMsrpKeepAliveIntval
 */
ZFUNC ZUINT Mtc_CliDbGetMsrpKeepAliveIntval();

/**
 * @brief Set the msrp keep alive interval time in seconds.
 *
 * @param [in] iKeepAliveIntval The msrp keep alive interval time in seconds.
 *
 * @retval ZOK Set the msrp keep alive interval time in seconds successfully.
 * @retval ZFAILED Set the msrp keep alive interval time in seconds failed.
 *
 * @see @ref Mtc_CliDbGetMsrpKeepAliveIntval
 */
ZFUNC ZINT Mtc_CliDbSetMsrpKeepAliveIntval(ZUINT iKeepAliveIntval);

/**
 * @brief Get the msrp transport trunk zise in bytes from database.
 *
 * @return msrp transport trunk zise in bytes.
 *
 * @see @ref Mtc_CliDbSetMsrpTptTrunkSize
 */
ZFUNC ZUINT Mtc_CliDbGetMsrpTptTrunkSize();

/**
 * @brief Set the msrp transport trunk zise in bytes.
 *
 * @param [in] iTptTrunkSize The msrp transport trunk zise in bytes.
 *
 * @retval ZOK Set the msrp transport trunk zise in bytes successfully.
 * @retval ZFAILED Set the msrp transport trunk zise in bytes failed.
 *
 * @see @ref Mtc_CliDbGetMsrpTptTrunkSize
 */
ZFUNC ZINT Mtc_CliDbSetMsrpTptTrunkSize(ZUINT iTptTrunkSize);

/**
 * @brief Get the msrp send bodiless flag from database.
 *
 * @return The flag of msrp send bodiless.
 *
 * @see @ref Mtc_CliDbSetMsrpSendBodiless
 */
ZFUNC ZBOOL Mtc_CliDbGetMsrpSendBodiless();

/**
 * @brief Set the msrp send bodiless flag.
 *
 * @param [in] bSendBodiless The msrp send bodiless flag.
 *
 * @retval ZOK Set the msrp send bodiless flag successfully.
 * @retval ZFAILED Set the msrp send bodiless flag failed.
 *
 * @see @ref Mtc_CliDbGetMsrpSendBodiless
 */
ZFUNC ZINT Mtc_CliDbSetMsrpSendBodiless(ZBOOL bSendBodiless);

/**
 * @brief Get the msrp log message print flag from database.
 *
 * @return The flag of msrp log message print.
 *
 * @see @ref Mtc_CliDbSetMsrpLogMsgPrint
 */
ZFUNC ZBOOL Mtc_CliDbGetMsrpLogMsgPrint();

/**
 * @brief Set the msrp log message print flag.
 *
 * @param [in] bLogMsgPrint The msrp log message print flag.
 *
 * @retval ZOK Set the msrp log message print flag successfully.
 * @retval ZFAILED Set the msrp log message print flag failed.
 *
 * @see @ref Mtc_CliDbGetMsrpLogMsgPrint
 */
ZFUNC ZINT Mtc_CliDbSetMsrpLogMsgPrint(ZBOOL bLogMsgPrint);

/**
 * @brief Get the msrp log file information print flag from database.
 *
 * @return The flag of msrp log file information print.
 *
 * @see @ref Mtc_CliDbSetMsrpLogFileInfoPrint
 */
ZFUNC ZBOOL Mtc_CliDbGetMsrpLogFileInfoPrint();

/**
 * @brief Set the msrp log file information print flag.
 *
 * @param [in] bLogFileInfoPrint The msrp log file information print flag.
 *
 * @retval ZOK Set the msrp log file information print flag successfully.
 * @retval ZFAILED Set the msrp log file information print flag failed.
 *
 * @see @ref Mtc_CliDbGetMsrpLogFileInfoPrint
 */
ZFUNC ZINT Mtc_CliDbSetMsrpLogFileInfoPrint(ZBOOL bLogFileInfoPrint);

/**
 * @brief Get DNS local listen port from database.
 *
 * @return The DNS local listen port.
 *
 * @see @ref Mtc_CliDbSetDnsLclPort
 */
ZFUNC ZUINT Mtc_CliDbGetDnsLclPort(ZFUNC_VOID);

/**
 * @brief Set DNS local listen port.
 *
 * @param [in] iPort DNS local listen port.
 *
 * @retval ZOK Set DNS local listen port successfully.
 * @retval ZFAILED Set DNS local listen port failed.
 *
 * @see @ref Mtc_CliDbGetDnsLclPort
 */
ZFUNC ZINT Mtc_CliDbSetDnsLclPort(ZUINT iPort); 

/**
 * @brief Set DNS use cache when dns query.
 *
 * @param [in] bEnCach DNS enable cache.
 *
 * @retval ZOK Set DNS enable cache successfully.
 * @retval ZFAILED Set DNS enable cache failed.
 *
 * @see @ref Mtc_CliDbGetDnsLclPort
 */
ZFUNC ZINT Mtc_CliDbSetDnsEnableCache(ZBOOL bEnCach); 

/**
 * @brief Get DNS primary or secondary server IP from database.
 *
 * @param [in] bPrimary DNS primary option.
 *
 * @return The DNS primary or secondary server IP.
 *
 * @see @ref Mtc_CliDbSetDnsServIp
 */
ZFUNC ZUINT Mtc_CliDbGetDnsServIp(ZBOOL bPrimary);

/**
 * @brief Set DNS primary or secondary server IP.
 *
 * @param [in] bPrimary DNS primary option.
 * @param [in] iServIp DNS primary or secondary server IP.
 *
 * @retval ZOK Set DNS primary or secondary server IP successfully.
 * @retval ZFAILED Set DNS primary or secondary server IP failed.
 *
 * @see @ref Mtc_CliDbGetDnsServIp
 */
ZFUNC ZINT Mtc_CliDbSetDnsServIp(ZBOOL bPrimary, ZUINT iServIp);

/**
 * @brief Get DNS primary or secondary server port from database.
 *
 * @param [in] bPrimary DNS primary option.
 *
 * @return The DNS primary or secondary server port.
 *
 * @see @ref Mtc_CliDbSetDnsServPort
 */
ZFUNC ZUINT Mtc_CliDbGetDnsServPort(ZBOOL bPrimary);

/**
 * @brief Get DNS use cache when dns query.
 *
 *
 * @return The DNS use cache lookup when dns query.
 *
 * @see @ref Mtc_CliDbSetDnsEnableCache
 */
ZFUNC ZBOOL Mtc_CliDbGetDnsEnableCache(ZFUNC_VOID);

/**
 * @brief Set DNS primary or secondary server port.
 *
 * @param [in] bPrimary DNS primary option.
 * @param [in] iPort DNS primary or secondary server port.
 *
 * @retval ZOK Set DNS primary or secondary server port successfully.
 * @retval ZFAILED Set DNS primary or secondary server port failed.
 *
 * @see @ref Mtc_CliDbGetDnsServPort
 */
ZFUNC ZINT Mtc_CliDbSetDnsServPort(ZBOOL bPrimary, ZUINT iPort);

/**
 * @brief Get NAT Traversal Mode.
 *
 * @return The NAT Traversal Mode @ref EN_MTC_NAT_TRAVERSAL_TYPE.
 *
 * @see @ref Mtc_CliDbSetNatTraversalMode
 */
ZFUNC ZUINT Mtc_CliDbGetNatTraversalMode();

/**
 * @brief Set NAT Traversal Mode.
 *
 * @param [in] iType The NAT Traversal Mode @ref EN_MTC_NAT_TRAVERSAL_TYPE.
 *
 * @retval ZOK Set NAT Traversal Mode successfully.
 * @retval ZFAILED Set NAT Traversal Mode failed.
 *
 * @see @ref Mtc_CliDbGetNatTraversalMode
 */
ZFUNC ZINT Mtc_CliDbSetNatTraversalMode(ZUINT iType);

/**
 * @brief Get the stun server name from database.
 *
 * @return The string of the stun server name.
 *
 * @see @ref Mtc_CliDbSetStunServerName
 */
ZFUNC ZCHAR * Mtc_CliDbGetStunServerName(ZFUNC_VOID);

/**
 * @brief Set the stun server name.
 *
 * @param [in] pcName The stun server name.
 *
 * @retval ZOK Set the stun server name successfully.
 * @retval ZFAILED Set the stun server name failed.
 *
 * @see @ref Mtc_CliDbGetStunServerName
 */
ZFUNC ZINT Mtc_CliDbSetStunServerName(ZCHAR *pcName);

/**
 * @brief Get the stun server port from database.
 *
 * @return The string of the stun server port.
 *
 * @see @ref Mtc_CliDbSetStunServerPort
 */
ZFUNC ZUINT Mtc_CliDbGetStunServerPort(ZFUNC_VOID);

/**
 * @brief Set the stun server port.
 *
 * @param [in] iPort The stun server port.
 *
 * @retval ZOK Set the stun server port successfully.
 * @retval ZFAILED Set the stun server port failed.
 *
 * @see @ref Mtc_CliDbGetStunServerPort
 */
ZFUNC ZINT Mtc_CliDbSetStunServerPort(ZUINT iPort);

/**
 * @brief Get the turn server name from database.
 *
 * @return The string of the turn server name.
 *
 * @see @ref Mtc_CliDbSetTurnServerName
 */
ZFUNC ZCHAR * Mtc_CliDbGetTurnServerName(ZFUNC_VOID);

/**
 * @brief Set the turn server name.
 *
 * @param [in] pcName The turn server name.
 *
 * @retval ZOK Set the turn server name successfully.
 * @retval ZFAILED Set the turn server name failed.
 *
 * @see @ref Mtc_CliDbGetTurnServerName
 */
ZFUNC ZINT Mtc_CliDbSetTurnServerName(ZCHAR *pcName);

/**
 * @brief Get the turn server port from database.
 *
 * @return The string of the turn server port.
 *
 * @see @ref Mtc_CliDbSetTurnServerPort
 */
ZFUNC ZUINT Mtc_CliDbGetTurnServerPort(ZFUNC_VOID);

/**
 * @brief Set the turn server port.
 *
 * @param [in] iPort The turn server port.
 *
 * @retval ZOK Set the turn server port successfully.
 * @retval ZFAILED Set the turn server port failed.
 *
 * @see @ref Mtc_CliDbGetTurnServerPort
 */
ZFUNC ZINT Mtc_CliDbSetTurnServerPort(ZUINT iPort);

/**
 * @brief Get SIP local UDP listen port from database.
 *
 * @return The SIP local UDP listen port.
 *
 * @see @ref Mtc_CliDbSetSipLclUdpPort
 */
ZFUNC ZUINT Mtc_CliDbGetSipLclUdpPort(ZFUNC_VOID);

/**
 * @brief Set sip local UDP listen port.
 *
 * @param [in] iPort SIP local UDP listen port.
 *
 * @retval ZOK Set the port successfully.
 * @retval ZFAILED Set the port failed.
 *
 * @see @ref Mtc_CliDbGetSipLclTcpPort
 */
ZFUNC ZINT Mtc_CliDbSetSipLclUdpPort(ZUINT iPort); 

/**
 * @brief Get SIP local TCP listen port from database.
 *
 * @return The SIP local TCP listen port.
 *
 * @see @ref Mtc_CliDbSetSipLclTcpPort
 */
ZFUNC ZUINT Mtc_CliDbGetSipLclTcpPort(ZFUNC_VOID);

/**
 * @brief Set sip local TCP listen port.
 *
 * @param [in] iPort SIP local TCP listen port.
 *
 * @retval ZOK Set the port successfully.
 * @retval ZFAILED Set the port failed.
 *
 * @see @ref Mtc_CliDbGetSipLclTcpPort
 */
ZFUNC ZINT Mtc_CliDbSetSipLclTcpPort(ZUINT iPort); 

/**
 * @brief Get SIP local TLS/SSL listen port from database.
 *
 * @return The SIP local TLS/SSL listen port.
 *
 * @see @ref Mtc_CliDbSetSipLclTcpPort
 */
ZFUNC ZUINT Mtc_CliDbGetSipLclTlsPort(ZFUNC_VOID);

/**
 * @brief Set sip local TLS/SSL listen port.
 *
 * @param [in] iPort SIP local TLS/SSL listen port.
 *
 * @retval ZOK Set the port successfully.
 * @retval ZFAILED Set the port failed.
 *
 * @see @ref Mtc_CliDbGetSipLclTcpPort
 */
ZFUNC ZINT Mtc_CliDbSetSipLclTlsPort(ZUINT iPort); 

/**
 * @brief Get SIP timer 1.
 *
 * @return The SIP timer 1 length.
 *
 * @see @ref Mtc_CliDbSetSipTmr1
 */
ZFUNC ZUINT Mtc_CliDbGetSipTmr1();

/**
 * @brief Set sip timer 1.
 *
 * @param [in] iTimeLen timer 1 length.
 *
 * @retval ZOK Set the timer 1 successfully.
 * @retval ZFAILED Set the timer 1 failed.
 *
 * @see @ref Mtc_CliDbGetSipTmr1
 */
ZFUNC ZINT Mtc_CliDbSetSipTmr1(ZUINT iTimeLen);

/**
 * @brief Get SIP timer 2.
 *
 * @return The SIP timer 2 length.
 *
 * @see @ref Mtc_CliDbSetSipTmr2
 */
ZFUNC ZUINT Mtc_CliDbGetSipTmr2();

/**
 * @brief Set sip timer 2.
 *
 * @param [in] iTimeLen timer 2 length.
 *
 * @retval ZOK Set the timer 2 successfully.
 * @retval ZFAILED Set the timer 2 failed.
 *
 * @see @ref Mtc_CliDbGetSipTmr2
 */
ZFUNC ZINT Mtc_CliDbSetSipTmr2(ZUINT iTimeLen);

/**
 * @brief Get SIP timer 4.
 *
 * @return The SIP timer 4 length.
 *
 * @see @ref Mtc_CliDbSetSipTmr4
 */
ZFUNC ZUINT Mtc_CliDbGetSipTmr4();

/**
 * @brief Set sip timer 4.
 *
 * @param [in] iTimeLen timer 4 length.
 *
 * @retval ZOK Set the timer 4 successfully.
 * @retval ZFAILED Set the timer 4 failed.
 *
 * @see @ref Mtc_CliDbGetSipTmr4
 */
ZFUNC ZINT Mtc_CliDbSetSipTmr4(ZUINT iTimeLen);

/**
 * @brief Get use Ipv4 option from database.
 *
 * @retval ZTRUE Use Ipv4.
 * @retval ZFALSE Do not use Ipv4.
 */
ZFUNC ZBOOL Mtc_CliDbGetUseIpv4(ZFUNC_VOID);

/**
 * @brief Set use ipv4 address option.
 *
 * @param [in] bUseIpv4 Use ipv4 address option.
 *
 * @retval ZOK Set use ipv4 address option successfully.
 * @retval ZFAILED Set use ipv4 address option failed.
 *
 * @see @ref Mtc_CliDbGetUseTelUri
 */

ZFUNC ZINT Mtc_CliDbSetUseIpv4(ZBOOL bUseIpv4);

/**
 * @brief Get sip dscp value from database.
 *
 * @retval The sip dscp value;
 *
 * @see @ref Mtc_CliDbSetSipDscpValue
 */
ZFUNC ZUINT Mtc_CliDbGetSipDscpValue();

/**
 * @brief Set sip dscp value.
 *
 * @param [in] iValue The sip dscp value.the value range is 0~63.
 *
 * @retval ZOK Set sip dscp value successfully.
 * @retval ZFAILED Set sip dscp value failed.
 *
 * @see @ref Mtc_CliDbGetSipDscpValue
 */
ZFUNC ZINT Mtc_CliDbSetSipDscpValue(ZUINT iValue);

/**
 * @brief Get use TEL URI option from database.
 *
 * @retval ZTRUE Use TEL URI.
 * @retval ZFALSE Do not use TEL URI.
 *
 * @see @ref Mtc_CliDbSetUseTelUri
 */
ZFUNC ZBOOL Mtc_CliDbGetUseTelUri(ZFUNC_VOID);

/**
 * @brief Get use TEL URI option.
 *
 * @param [in] bIvtTel Use TEL URI option.
 *
 * @retval ZOK Set user TEL URI option successfully.
 * @retval ZFAILED Set user TEL URI option failed.
 *
 * @see @ref Mtc_CliDbGetUseTelUri
 */
ZFUNC ZINT Mtc_CliDbSetUseTelUri(ZBOOL bIvtTel);

/**
 * @brief Get SIP register or proxy server IP from database.
 *
 * @note: It can set different REGISTAR and Proxy compare to @ref Mtc_CliDbGetSipRegIp.
 *
 * @param [in] bProxy SIP proxy option.
 *
 * @return Get SIP register or proxy server IP.
 *
 * @see @ref Mtc_CliDbSetSipServIp
 */
ZFUNC ZCHAR * Mtc_CliDbGetSipServIp(ZBOOL bProxy);

/**
 * @brief Set SIP register or proxy server IP.
 *
 * @note: It can set different REGISTAR and Proxy compare to @ref Mtc_CliDbSetSipRegIp.
 *
 * @param [in] bProxy SIP proxy option.
 * @param [in] pcIp SIP register or proxy server IP.
 *
 * @retval ZOK Set SIP register or proxy server IP successfully.
 * @retval ZFAILED Set SIP register or proxy server IP failed.
 *
 * @see @ref Mtc_CliDbGetSipServIp
 */
ZFUNC ZINT Mtc_CliDbSetSipServIp(ZBOOL bProxy, ZCHAR *pcIp);

/**
 * @brief Get SIP register or proxy server port from database.
 *
 * @note: It can set different REGISTAR and Proxy compare to 
 *        @ref Mtc_CliDbSetSipRegUdpPort and @ref Mtc_CliDbSetSipRegTcpPort.
 *
 * @param [in] bProxy SIP proxy option.
 *
 * @return Get SIP register or proxy server port.
 *
 * @see @ref Mtc_CliDbSetSipServPort
 */
ZFUNC ZUINT Mtc_CliDbGetSipServPort(ZBOOL bProxy);

/**
 * @brief Set SIP register or proxy server port.
 *
 * @note: It can set different REGISTAR and Proxy compare to 
 *        @ref Mtc_CliDbSetSipRegUdpPort and @ref Mtc_CliDbSetSipRegTcpPort.
 *
 * @param [in] bProxy SIP proxy option.
 * @param [in] iPort SIP register or proxy server port.
 *
 * @retval ZOK Set SIP register or proxy server port successfully.
 * @retval ZFAILED Set SIP register or proxy server port failed.
 *
 * @see @ref Mtc_CliDbGetSipServPort
 */
ZFUNC ZINT Mtc_CliDbSetSipServPort(ZBOOL bProxy, ZUINT iPort);

/**
 * @brief Get SIP register or proxy server port from database.
 *
 * @param [in] bProxy SIP proxy option.
 * @param [in] ucTpt SIP register or proxy server transport protocal type.
 *
 * @return Get SIP register or proxy server port.
 *
 * @see @ref Mtc_CliDbGetSipServPort, @ref Mtc_CliDbSetSipServPort, @ref Mtc_CliDbSetSipServPortX
 */
ZFUNC ZUINT Mtc_CliDbGetSipServPortX(ZBOOL bProxy, ZUCHAR ucTpt);

/**
 * @brief Get SIP register or proxy server port.
 *
 * @param [in] bProxy SIP proxy option.
 * @param [in] ucTpt SIP register or proxy server transport protocal type.
 * @param [in] iPort SIP register or proxy server port.
 *
 * @retval ZOK Set SIP register or proxy server port successfully.
 * @retval ZFAILED Set SIP register or proxy server port failed.
 *
 * @see @ref Mtc_CliDbGetSipServPort, @ref Mtc_CliDbSetSipServPort, @ref Mtc_CliDbGetSipServPortX
 */
ZFUNC ZINT Mtc_CliDbSetSipServPortX(ZBOOL bProxy, ZUCHAR ucTpt, ZUINT iPort);

/**
 * @brief Get SIP register or proxy server transport protocol type from database.
 *
 * @note: It can set different REGISTAR and Proxy compare to @ref Mtc_CliDbGetSipRegTpt.
 *
 * @param [in] bProxy SIP proxy option.
 *
 * @return Get SIP register or proxy server transport protocol type.
 *
 * @see @ref Mtc_CliDbSetSipServTpt
 */
ZFUNC ZUCHAR Mtc_CliDbGetSipServTpt(ZBOOL bProxy);

/**
 * @brief Set SIP register or proxy server transport protocal type.
 *
 * @note: It can set different REGISTAR and Proxy compare to @ref Mtc_CliDbSetSipRegTpt.
 *
 * @param [in] bProxy SIP proxy option.
 * @param [in] ucTpt SIP register or proxy server transport protocal type.
 *
 * @retval ZOK Set SIP register or proxy server transport protocal type successfully.
 * @retval ZFAILED Set SIP register or proxy server transport protocal type failed.
 *
 * @see @ref Mtc_CliDbGetSipServTpt
 */
ZFUNC ZINT Mtc_CliDbSetSipServTpt(ZBOOL bProxy, ZUCHAR ucTpt);

/**
 * @brief Get SIP register or proxy server realm from database.
 *
 * @note: It can set different REGISTAR and Proxy compare to @ref Mtc_CliDbGetSipRegRealm.
 *
 * @param [in] bProxy SIP proxy option.
 *
 * @return Get SIP register or proxy server realm.
 *
 * @see @ref Mtc_CliDbSetSipServRealm
 */
ZFUNC ZCHAR * Mtc_CliDbGetSipServRealm(ZBOOL bProxy);

/**
 * @brief Set SIP register or proxy server realm.
 *
 * @note: It can set different REGISTAR and Proxy compare to @ref Mtc_CliDbSetSipRegRealm.
 *
 * @param [in] bProxy SIP proxy option.
 * @param [in] pcRealm SIP register or proxy server realm.
 *
 * @retval ZOK Set SIP register or proxy server realm successfully.
 * @retval ZFAILED Set SIP register or proxy server realm failed.
 *
 * @see @ref Mtc_CliDbGetSipServRealm
 */
ZFUNC ZINT Mtc_CliDbSetSipServRealm(ZBOOL bProxy, ZCHAR *pcRealm);

/**
 * @brief Get register retry count while starting REGISTER.
 *
 * @return Get register retry count.
 *
 * @see @ref Mtc_CliDbSetRegRetryCount
 */
ZFUNC ZUINT Mtc_CliDbGetRegRetryCount(ZFUNC_VOID);

/**
 * @brief Set register retry count while starting REGISTER.
 *
 * @param [in] iCount The register retry count .
 *
 * @retval ZOK Set register retry count successfully.
 * @retval ZFAILED Set register retry count failed.
 *
 * @see @ref Mtc_CliDbGetRegRetryCount
 */
ZFUNC ZINT Mtc_CliDbSetRegRetryCount(ZUINT iCount);

/**
 * @brief Get subscribe register event option after successful REGISTER.
 *
 * @return Get subscribe register event enable option.
 *
 * @see @ref Mtc_CliDbSetSubsRegEvnt
 */
ZFUNC ZBOOL Mtc_CliDbGetSubsRegEvnt(ZFUNC_VOID);

/**
 * @brief Set subscribe register event option after successful REGISTER.
 *
 * @param [in] bSubs Support subscribe register event.
 *
 * @retval ZOK Set subscribe register event option successfully.
 * @retval ZFAILED Set subscribe register event option failed.
 *
 * @see @ref Mtc_CliDbGetSubsRegEvnt
 */
ZFUNC ZINT Mtc_CliDbSetSubsRegEvnt(ZBOOL bSubs);

/**
 * @brief Get access network type.
 *
 * @return Get access network type. Network type @ref EN_MTC_ACC_NET_TYPE.
 *
 * @see @ref Mtc_CliDbSetAccNetType
 */
ZFUNC ZUINT Mtc_CliDbGetAccNetType(ZFUNC_VOID);

/**
 * @brief Set access network type.
 *
 * @param [in] iType The access network type. 
 *             Network type @ref EN_MTC_ACC_NET_TYPE. 
 *
 * @retval ZOK Set access network type successfully.
 * @retval ZFAILED Set access network type failed.
 *
 * @see @ref Mtc_CliDbGetAccNetType
 */
ZFUNC ZINT Mtc_CliDbSetAccNetType(ZUINT iType);

/**
 * @brief Get access network info.
 *
 * @return Get access network info.
 *
 * @see @ref Mtc_CliDbSetAccNetInfo
 */
ZFUNC ZCHAR * Mtc_CliDbGetAccNetInfo(ZFUNC_VOID);

/**
 * @brief Set access network info.
 *
 * @param [in] pcInfo Access network info.
 *             The info should set right value according to 
 *             3GPP TS24.229[7.2A.4.3]
 *
 * @retval ZOK Set access network info successfully.
 * @retval ZFAILED Set access network info failed.
 *
 * @see @ref Mtc_CliDbGetAccNetInfo
 */
ZFUNC ZINT Mtc_CliDbSetAccNetInfo(ZCHAR *pcInfo);

/**
 * @brief Get XCAP root uri from database.
 *
 * @return The string of root uri.
 *
 * @see @ref Mtc_CliDbSetXcapRootUri
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapRootUri(ZFUNC_VOID);

/**
 * @brief Set XCAP root uri.
 *
 * @param [in] pcUri The string of root uri.
 *
 * @retval ZOK Set root uri successfully.
 * @retval ZFAILED Set name failed.
 *
 * @see @ref Mtc_CliDbGetXcapRootUri
 */
ZFUNC ZINT Mtc_CliDbSetXcapRootUri(ZCHAR *pcUri);

/**
 * @brief Get XCAP authorization name from database.
 *
 * @return The string of authorization name.
 *
 * @see @ref Mtc_CliDbSetXcapAuthName
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapAuthName(ZFUNC_VOID);

/**
 * @brief Set XCAP authorization name.
 *
 * @param [in] pcName The string of authorization name.
 *
 * @retval ZOK Set authorization name successfully.
 * @retval ZFAILED Set authorization name failed.
 *
 * @see @ref Mtc_CliDbGetXcapAuthName
 */
ZFUNC ZINT Mtc_CliDbSetXcapAuthName(ZCHAR *pcName);

/**
 * @brief Get XCAP authorization password from database.
 *
 * @return The string of authorization password.
 *
 * @see @ref Mtc_CliDbSetXcapAuthPass
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapAuthPass(ZFUNC_VOID);

/**
 * @brief Set XCAP authorization password.
 *
 * @param [in] pcPass The string of authorization password.
 *
 * @retval ZOK Set authorization password successfully.
 * @retval ZFAILED Set authorization password failed.
 *
 * @see @ref Mtc_CliDbGetXcapAuthPass
 */
ZFUNC ZINT Mtc_CliDbSetXcapAuthPass(ZCHAR *pcPass);

/**
 * @brief Get XCAP authorization token from database.
 *
 * @return The string of authorization token.
 *
 * @see @ref Mtc_CliDbSetXcapAuthToken
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapAuthToken(ZFUNC_VOID);

/**
 * @brief Set XCAP authorization token.
 *
 * @param [in] pcName The string of authorization token.
 *
 * @retval ZOK Set authorization token successfully.
 * @retval ZFAILED Set authorization token failed.
 *
 * @see @ref Mtc_CliDbGetXcapAuthToken
 */
ZFUNC ZINT Mtc_CliDbSetXcapAuthToken(ZCHAR *pcToken);

/**
 * @brief Get XCAP authorization type from database.
 *
 * @return The authorization type, @see @ref EN_MTC_XCAP_AUTH_TYPE.
 *
 * @see @ref Mtc_CliDbSetXcapAuthType
 */
ZFUNC ZUINT Mtc_CliDbGetXcapAuthType(ZFUNC_VOID);

/**
 * @brief Set XCAP authorization type.
 *
 * @param [in] iType The authorization type, @see @ref EN_MTC_XCAP_AUTH_TYPE.
 *
 * @retval ZOK Set authorization type successfully.
 * @retval ZFAILED Set authorization type failed.
 *
 * @see @ref Mtc_CliDbGetXcapAuthType
 */
ZFUNC ZINT Mtc_CliDbSetXcapAuthType(ZUINT iType);

/**
 * @brief Get XCAP server host from database.
 *
 * @return The string of the XCAP server host.
 *
 * @see @ref Mtc_CliDbSetXcapHost
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapHost(ZFUNC_VOID);

/**
 * @brief Set the XCAP server host.
 *
 * @param [in] pcHost The XCAP server host.
 *
 * @retval ZOK Set the server host successfully.
 * @retval ZFAILED Set the server host failed.
 *
 * @see @ref Mtc_CliDbGetXcapHost
 */
ZFUNC ZINT Mtc_CliDbSetXcapHost(ZCHAR *pcHost);

/**
 * @brief Get XCAP the xcap server host port from database.
 *
 * @return The port of the XCAP server host port.
 *
 * @see @ref Mtc_CliDbSetXcapHostPort
 */
ZFUNC ZUSHORT Mtc_CliDbGetXcapHostPort(ZFUNC_VOID);

/**
 * @brief Set the XCAP server host port.
 *
 * @param [in] wPort The XCAP server host port.
 *
 * @retval ZOK Set the server host successfully.
 * @retval ZFAILED Set the server host failed.
 *
 * @see @ref Mtc_CliDbGetXcapHostPort
 */
ZFUNC ZINT Mtc_CliDbSetXcapHostPort(ZUSHORT wPort);

/**
 * @brief Get XCAP root from database.
 *
 * @return The string of the XCAP root.
 *
 * @see @ref Mtc_CliDbSetXcapHost
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapRoot(ZFUNC_VOID);

/**
 * @brief Set the XCAP root.
 *
 * @param [in] pcRoot The XCAP root.
 *
 * @retval ZOK Set the root successfully.
 * @retval ZFAILED Set the root failed.
 *
 * @see @ref Mtc_CliDbGetXcapHost
 */
ZFUNC ZINT Mtc_CliDbSetXcapRoot(ZCHAR *pcRoot);

/**
 * @brief Get XCAP user id from database.
 *
 * @return The string of the XCAP user id.
 *
 * @see @ref Mtc_CliDbSetXcapUserId
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapUserId(ZFUNC_VOID);

/**
 * @brief Set the XCAP user id.
 *
 * @param [in] pcUserId The XCAP user id.
 *
 * @retval ZOK Set the XCAP user id successfully.
 * @retval ZFAILED Set the XCAP user id failed.
 *
 * @see @ref Mtc_CliDbGetXcapUserId
 */
ZFUNC ZINT Mtc_CliDbSetXcapUserId(ZCHAR *pcUserId);

/**
 * @brief Get XCAP aggregation proxy IP from database.
 *
 * @return The string of the XCAP aggregation proxy IP.
 *
 * @see @ref Mtc_CliDbSetXcapAgProxyIp
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapAgProxyIp(ZFUNC_VOID);

/**
 * @brief Set the XCAP aggregation proxy IP.
 *
 * @param [in] pcIp The XCAP aggregation proxy IP.
 *
 * @retval ZOK Set the aggregation proxy IP successfully.
 * @retval ZFAILED Set the aggregation proxy IP failed.
 *
 * @see @ref Mtc_CliDbGetXcapAgProxyIp
 */
ZFUNC ZINT Mtc_CliDbSetXcapAgProxyIp(ZCHAR *pcIp);

/**
 * @brief Get aggregation proxy port from database.
 *
 * @return Aggregation proxy port.
 *
 * @see @ref Mtc_CliDbSetXcapAgProxyPort
 */
ZFUNC ZUINT Mtc_CliDbGetXcapAgProxyPort(ZFUNC_VOID);

/**
 * @brief Set aggregation proxy port.
 *
 * @param [in] iPort Aggregation proxy port .

 * @retval ZOK Set aggregation proxy port successfully.
 * @retval ZFAILED Set aggregation proxy port failed.
 *
 * @see @ref Mtc_CliDbGetXcapAgProxyPort
 */
ZFUNC ZINT Mtc_CliDbSetXcapAgProxyPort(ZUINT iPort);

/**
 * @brief get xcap uri namespace support.
 *
 * @return xcap uri namespace support.
 *
 * @see @ref Mtc_CliDbSetXcapUriNsSupt
 */
ZFUNC ZBOOL Mtc_CliDbGetXcapUriNsSupt(ZFUNC_VOID);

/**
 * @brief set xcap uri namespace support.
 *
 * @param [in] bSupt xcap uri namespace.

 * @retval ZOK Set xcap uri namespace suppor successfully.
 * @retval ZFAILED Set xcap uri namespace suppor failed.
 *
 * @see @ref Mtc_CliDbGetXcapUriNsSupt
 */
ZFUNC ZINT Mtc_CliDbSetXcapUriNsSupt(ZBOOL bSupt);

/**
 * @brief get xcap pre-arranged group uri.
 *
 * @return xcap pre-arranged group uri.
 *
 * @see @ref Mtc_CliDbGetXcapPreArgGrpUri
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapPreArgGrpUri(ZFUNC_VOID);

/**
 * @brief set xcap pre-arranged group uri.
 *
 * @param [in] pcPreArgGrpUri pre-arranged group uri.

 * @retval ZOK  set xcap pre-arranged group uri successfully.
 * @retval ZFAILED set xcap pre-arranged group uri failed.
 *
 * @see @ref Mtc_CliDbGetXcapPreArgGrpUri
 */
ZFUNC ZINT Mtc_CliDbSetXcapPreArgGrpUri(ZCHAR *pcPreArgGrpUri);

/**
 * @brief get xcap chat group uri.
 *
 * @return xcap chat group uri.
 *
 * @see @ref Mtc_CliDbSetXcapChatGrpUri
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapChatGrpUri(ZFUNC_VOID);

/**
 * @brief set xcap chat group uri.
 *
 * @param [in] pcChatGpUri xcap chat group uri.

 * @retval ZOK  set xcap chat group uri successfully.
 * @retval ZFAILED set xcap chat group uri failed.
 *
 * @see @ref Mtc_CliDbGetXcapChatGrpUri
 */
ZFUNC ZINT Mtc_CliDbSetXcapChatGrpUri(ZCHAR *pcChatGpUri);

/**
 * @brief get xcap rls-service uri.
 *
 * @return xcap rls-service uri.
 *
 * @see @ref Mtc_CliDbSetXcapRlsSrvUri.
 */
ZFUNC ZCHAR * Mtc_CliDbGetXcapRlsSrvUri(ZFUNC_VOID);

/**
 * @brief set xcap rls-service uri.
 *
 * @param [in] pcRlsSrvUri xcap rls-service uri.

 * @retval ZOK  set xcap rls-service uri successfully.
 * @retval ZFAILED set xcap rls-service uri failed.
 *
 * @see @ref Mtc_CliDbGetXcapChatGrpUri
 */
ZFUNC ZINT Mtc_CliDbSetXcapRlsSrvUri(ZCHAR *pcRlsSrvUri);

/**
 * @brief get xcapc listen tcp port.
 *
 * @return xcapc listen tcp port.
 *
 * @see @ref Mtc_CliDbSetXcapcTcpListenPort
 */
ZFUNC ZUSHORT Mtc_CliDbGetXcapcTcpListenPort(ZFUNC_VOID);

/**
 * @brief set xcapc listen tcp port.
 *
 * @param [in] wPort xcapc listen tcp port.

 * @retval ZOK  set xcapc listen tcp port successfully.
 * @retval ZFAILED set xcapc listen tcp port failed.
 *
 * @see @ref Mtc_CliDbGetXcapcTcpListenPort
 */
ZFUNC ZINT Mtc_CliDbSetXcapcTcpListenPort(ZUSHORT wPort);

/**
 * @brief Get revoke timer length.
 *
 * @return revoke timer length in seconds.
 */
ZFUNC ZUINT Mtc_CliDbGetRvkTmrLen(ZFUNC_VOID);

/**
 * @brief Get pnb management enable.
 *
 * @return pnb management enable.
 *
 * @see @ref Mtc_CliDbSetPnbEnable
 */
ZFUNC ZBOOL Mtc_CliDbGetPnbEnable(ZFUNC_VOID);

/**
 * @brief Set pnb management enable.
 *
 * @param [in] bEnable pnb management enable .
 *
 * @retval ZOK Set pnb management enable successfully.
 * @retval ZFAILED Set pnb management enable failed.
 *
 * @see @ref Mtc_CliDbGetPnbEnable
 */
ZFUNC ZINT Mtc_CliDbSetPnbEnable(ZBOOL bEnable);

/**
 * @brief Get xdm document subscribe enable.
 *
 * @return xdm document subscribe enable.
 *
 * @see @ref Mtc_CliDbSetXdmChgSubsEnable
 */
ZFUNC ZBOOL Mtc_CliDbGetXdmChgSubsEnable(ZFUNC_VOID);

/**
 * @brief Set xdm document changes subscription enable.
 *
 * @param [in] bEnable xdm document changes subscription enable .

 * @retval ZOK Set subscription enable successfully.
 * @retval ZFAILED Set subscription enable failed.
 *
 * @see @ref Mtc_CliDbGetXdmChgSubsEnable
 */
ZFUNC ZINT Mtc_CliDbSetXdmChgSubsEnable(ZBOOL bEnable);

/**
 * @brief Get the format (SIP URI or tel URI) to be used when the callee 
 *  numbering is dialled in national format.
 *
 * @return Uri format type, @see @ref EN_MTC_URI_FMT_TYPE.
 */
ZFUNC ZUINT Mtc_CliDbGetNatUriFmt(ZFUNC_VOID);

/**
 * @brief Get the format (SIP URI or tel URI) to be used when the callee 
 *  numbering is dialled in international format.
 *
 * @return Uri format type, @see @ref EN_MTC_URI_FMT_TYPE.
 */
ZFUNC ZUINT Mtc_CliDbGetIntUriFmt(ZFUNC_VOID);

/**
 * @brief Get a sip.instance enable flag.
 * A sip.instance which is required for the sip.instance multidevice approach.
 *
 * @return sip instance enable.
 *
 * @see @ref Mtc_CliDbSetSipInstanceEnable
 *
 */
ZFUNC ZBOOL Mtc_CliDbGetSipInstanceEnable(ZFUNC_VOID);

/**
 * @brief Set a sip.instance enable flag. 
 * A sip.instance which is required for the sip.instance multidevice approach.
 *
 * @param [in] bSipInstanceEnable sip instance enable.
 *
 * @return sip instance enable.
 *
 * @retval ZOK Set sip instance enable successfully.
 * @retval ZFAILED Set sip instance enable failed.
 *
 * @see @ref Mtc_CliDbGetSipInstanceEnable
 *
 */
ZFUNC ZUINT Mtc_CliDbSetSipInstanceEnable(ZBOOL bSipInstanceEnable);

/**
 * @brief Get the Q-value to be put in the Contact header of the Register method.
 *
 * @return Q-value, including '0.1', '0.2', '0.3', '0.4', '0.5', '0.6', '0.7', '0.8', '0.9', '1.0'.
 */
ZFUNC ZCHAR * Mtc_CliDbGetQValue(ZFUNC_VOID);

/**
 * @brief Get whether or not to show the RCS enabled/disabled switch permanently.
 *
 * @return switch type, @see @ref EN_MTC_RCSE_SWITCH_TYPE.
 * 
 * @see @ref Mtc_CliDbSetRcseSwitchType
 */
ZFUNC ZUCHAR Mtc_CliDbGetRcseSwitchType(ZFUNC_VOID);

/**
 * @brief Get the APN to be used as the RCS roaming APN.
 *
 * @return APN name string.
 * 
 * @see @ref Mtc_CliDbSetRcseOnlyApn
 */
ZFUNC ZCHAR * Mtc_CliDbGetRcseOnlyApn(ZFUNC_VOID);

/**
 * @brief Get the use ims apn mode when available.
 *
 * @retval -1 Indications the device shall never use the IMS APN for RCS.
 * @retval 0  Indications The device shall use the IMS APN for RCS when the 
 *            device's internet access is using cellular coverage.
 * @retval 1  Indications the device shall always use the IMS APN for RCS whenever 
 *            it is in cellular coverage, even if non-cellular access is available.
 * 
 * @see @ref Mtc_CliDbSetAlwaysUseImsApn
 */
ZFUNC ZINT Mtc_CliDbGetAlwaysUseImsApn();

/**
 * @brief Set whether or not to show the RCS enabled/disabled switch permanently.
 *
 * @param [in] ucRcseSwitch switch type @see @ref EN_MTC_RCSE_SWITCH_TYPE
 *
 * @retval ZOK Set switch type successfully.
 * @retval ZFAILED Set switch type failed.
 * 
 * @see @ref Mtc_CliDbGetRcseSwitchType
 */
ZFUNC ZINT Mtc_CliDbSetRcseSwitchType(ZUCHAR ucRcseSwitch);

/**
 * @brief Set the APN to be used as the RCS roaming APN.
 *
 * @param [in] pcApn The APN name.
 *
 * @retval ZOK Set APN name successfully.
 * @retval ZFAILED Set APN name failed.
 * 
 * @see @ref Mtc_CliDbGetRcseOnlyApn
 */
ZFUNC ZINT Mtc_CliDbSetRcseOnlyApn(ZCHAR *pcApn);

/**
 * @brief Set the always use ims apn mode.
 *
 * @param [in] iAlwaysUseImsApn The use ims apn mode.
 *
 * @retval ZOK Set use ims apn mode successfully.
 * @retval ZFAILED Set use ims apn mode failed.
 * 
 * @see @ref Mtc_CliDbGetAlwaysUseImsApn
 */
ZFUNC ZINT Mtc_CliDbSetAlwaysUseImsApn(ZINT iAlwaysUseImsApn);

/**
 * @brief Get data bearer type.
 * 
 * @return Data bearer type, @see @ref EN_MTC_DATA_BEARER_TYPE.
 *
 * @see @ref Mtc_CliDbSetDataBearerType
 */
ZFUNC ZUINT Mtc_CliDbGetDataBearerType(ZFUNC_VOID);

/**
 * @brief Set data bearer type.
 *
 * @param [in] iBearerType The data bearer type, @see @ref EN_MTC_DATA_BEARER_TYPE
 * 
 * @retval ZOK Set data bearer type successfully.
 * @retval ZFAILED Set data bearer type failed.
 *
 * @see @ref Mtc_CliDbSetDataBearerType
 */
ZFUNC ZINT Mtc_CliDbSetDataBearerType(ZUINT iBearerType);

/**
 * @brief Get tls client method type.
 *
 * @return tls client method type, @see @ref EN_MTC_TLS_METHOD_TYPE.
 *
 * @see @ref Mtc_CliDbSetTlsCliMethod
 */
ZFUNC ZUINT Mtc_CliDbGetTlsCliMethod(ZFUNC_VOID);

/**
 * @brief Get tls client verify type.
 *
 * @return tls client verify type, @see @ref EN_MTC_TLS_VERY_TYPE.
 *
 * @see @ref Mtc_CliDbSetTlsCliVeryType
 */
ZFUNC ZUINT Mtc_CliDbGetTlsCliVeryType(ZFUNC_VOID);

/**
 * @brief Get tls client trusted ca path.
 *
 * @return tls client trusted ca path.
 *
 * @see @ref Mtc_CliDbSetTlsCliTrustCaPath
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsCliTrustCaPath(ZFUNC_VOID);

/**
 * @brief Get tls client trusted ca file.
 *
 * @return tls client trusted ca file, including path.
 *
 * @see @ref Mtc_CliDbSetTlsCliTrustCaFile
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsCliTrustCaFile(ZFUNC_VOID);

/**
 * @brief Get tls client certificate file.
 *
 * @return tls client certificate file, including path.
 *
 * @see @ref Mtc_CliDbSetTlsCliCertFile
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsCliCertFile(ZFUNC_VOID);

/**
 * @brief Get tls client private key file.
 *
 * @return tls client private key file, including path.
 *
 * @see @ref Mtc_CliDbSetTlsCliPrvKeyFile
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsCliPrvKeyFile(ZFUNC_VOID);

/**
 * @brief Get tls client private key password.
 *
 * @return tls client private key password, max length is 64 bytes.
 *
 * @see @ref Mtc_CliDbSetTlsCliPrvKeyPass
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsCliPrvKeyPass(ZFUNC_VOID);

/**
 * @brief Get tls server method type.
 *
 * @return tls server method type, @see @ref EN_MTC_TLS_METHOD_TYPE.
 *
 * @see @ref Mtc_CliDbSetTlsServMethod
 */
ZFUNC ZUINT Mtc_CliDbGetTlsServMethod(ZFUNC_VOID);

/**
 * @brief Get tls server verify type.
 *
 * @return tls server verify type, @see @ref EN_MTC_TLS_VERY_TYPE.
 *
 * @see @ref Mtc_CliDbSetTlsServVeryType
 */
ZFUNC ZUINT Mtc_CliDbGetTlsServVeryType(ZFUNC_VOID);

/**
 * @brief Get tls server trusted ca file.
 *
 * @return tls server trusted ca file, including path.
 *
 * @see @ref Mtc_CliDbSetTlsServTrustCaFile
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsServTrustCaFile(ZFUNC_VOID);

/**
 * @brief Get tls server certificate file.
 *
 * @return tls server certificate file, including path.
 *
 * @see @ref Mtc_CliDbSetTlsServCertFile
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsServCertFile(ZFUNC_VOID);

/**
 * @brief Get tls server private key file.
 *
 * @return tls server private key file, including path.
 *
 * @see @ref Mtc_CliDbSetTlsServPrvKeyFile
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsServPrvKeyFile(ZFUNC_VOID);

/**
 * @brief Get tls server private key password.
 *
 * @return tls server private key password, max length is 64 bytes.
 *
 * @see @ref Mtc_CliDbSetTlsServPrvKeyPass
 */
ZFUNC ZCHAR * Mtc_CliDbGetTlsServPrvKeyPass(ZFUNC_VOID);

/**
 * @brief Set tls client method.
 *
 * @param [in] dwMethod The client method, @see @ref EN_MTC_TLS_METHOD_TYPE.
 *
 * @retval ZOK Set tls client method successfully.
 * @retval ZFAILED tls client method failed.
 *
 * @see @ref Mtc_CliDbGetTlsCliMethod
 */
ZFUNC ZINT Mtc_CliDbSetTlsCliMethod(ZUINT dwMethod);

/**
 * @brief Set tls client verify type.
 *
 * @param [in] iVeryType The client verify type, @see @ref EN_MTC_TLS_VERY_TYPE.

 * @retval ZOK Set tls client verify type successfully.
 * @retval ZFAILED tls client verify type failed.
 *
 * @see @ref Mtc_CliDbGetTlsCliVeryType
 */
ZFUNC ZINT Mtc_CliDbSetTlsCliVeryType(ZUINT iVeryType);

/**
 * @brief Set tls client trusted ca path.
 *
 * @param [in] pcPath The client trusted ca path. 
 *
 * @retval ZOK Set tls client verify type successfully.
 * @retval ZFAILED tls client verify type failed.
 *
 * @see @ref Mtc_CliDbGetTlsCliTrustCaPath
 */
ZFUNC ZINT Mtc_CliDbSetTlsCliTrustCaPath(ZCHAR *pcPath);

/**
 * @brief Set tls client trusted ca file.
 *
 * @param [in] pcFile The client trusted ca file, including path. 
 *
 * @retval ZOK Set tls client verify type successfully.
 * @retval ZFAILED tls client verify type failed.
 *
 * @see @ref Mtc_CliDbGetTlsCliTrustCaFile
 */
ZFUNC ZINT Mtc_CliDbSetTlsCliTrustCaFile(ZCHAR *pcFile);

/**
 * @brief Set tls client certificate file.
 *
 * @param [in] pcFile The client certificate file, including path. 
 *
 * @retval ZOK Set tls client certificate file successfully.
 * @retval ZFAILED tls client certificate file failed.
 *
 * @see @ref Mtc_CliDbGetTlsCliCertFile
 */
ZFUNC ZINT Mtc_CliDbSetTlsCliCertFile(ZCHAR *pcFile);

/**
 * @brief Set tls client private key file.
 *
 * @param [in] pcFile The client private key file, including path.
 *
 * @retval ZOK Set tls client private key file successfully.
 * @retval ZFAILED tls client private key file failed.
 *
 * @see @ref Mtc_CliDbGetTlsCliPrvKeyFile
 */
ZFUNC ZINT Mtc_CliDbSetTlsCliPrvKeyFile(ZCHAR *pcFile);

/**
 * @brief Set tls client private key password.
 *
 * @param [in] pcPasswd The client private key password, max length is 64 bytes.
 *
 * @retval ZOK Set tls client private key password successfully.
 * @retval ZFAILED tls client private key password failed.
 *
 * @see @ref Mtc_CliDbGetTlsCliPrvKeyPass
 */
ZFUNC ZINT Mtc_CliDbSetTlsCliPrvKeyPass(ZCHAR *pcPasswd);

/**
 * @brief Set tls server method.
 *
 * @param [in] dwMethod The server method, @see @ref EN_MTC_TLS_METHOD_TYPE.
 *
 * @retval ZOK Set tls server method successfully.
 * @retval ZFAILED tls server method failed.
 *
 * @see @ref Mtc_CliDbGetTlsServMethod
 */
ZFUNC ZINT Mtc_CliDbSetTlsServMethod(ZUINT dwMethod);

/**
 * @brief Set tls server verify type.
 *
 * @param [in] iVeryType The server verify type, @see @ref EN_MTC_TLS_VERY_TYPE.
 *
 * @retval ZOK Set tls server verify type successfully.
 * @retval ZFAILED tls server verify type failed.
 *
 * @see @ref Mtc_CliDbGetTlsServVeryType
 */
ZFUNC ZINT Mtc_CliDbSetTlsServVeryType(ZUINT iVeryType);

/**
 * @brief Set tls server trusted ca file.
 *
 * @param [in] pcFile The server trusted ca file, including path.
 *
 * @retval ZOK Set tls server verify type successfully.
 * @retval ZFAILED tls server verify type failed.
 *
 * @see @ref Mtc_CliDbGetTlsServTrustCaFile
 */
ZFUNC ZINT Mtc_CliDbSetTlsServTrustCaFile(ZCHAR *pcFile);

/**
 * @brief Set tls server certificate file.
 *
 * @param [in] pcFile The server certificate file, including path.
 *
 * @retval ZOK Set tls server certificate file successfully.
 * @retval ZFAILED tls server certificate file failed.
 *
 * @see @ref Mtc_CliDbGetTlsServCertFile
 */
ZFUNC ZINT Mtc_CliDbSetTlsServCertFile(ZCHAR *pcFile);

/**
 * @brief Set tls server private key file.
 *
 * @param [in] pcFile The server private key file, including path.
 *
 * @retval ZOK Set tls server private key file successfully.
 * @retval ZFAILED tls server private key file failed.
 *
 * @see @ref Mtc_CliDbGetTlsServPrvKeyFile
 */
ZFUNC ZINT Mtc_CliDbSetTlsServPrvKeyFile(ZCHAR *pcFile);

/**
 * @brief Set tls server private key password.
 *
 * @param [in] pcPasswd The server private key password, max length is 64 bytes.
 *
 * @retval ZOK Set tls server private key password successfully.
 * @retval ZFAILED tls server private key password failed.
 *
 * @see @ref Mtc_CliDbGetTlsServPrvKeyPass
 */
ZFUNC ZINT Mtc_CliDbSetTlsServPrvKeyPass(ZCHAR *pcPasswd);

/**
 * @brief Set dtls client ca file.
 *
 * @param [in] pcFile The client trusted ca file, including path. 
 *
 * @retval ZOK Set dtls CA file successfully.
 * @retval ZFAILED set dtls CA file failed.
 *
 * @see @ref Mtc_CliDbGetDtlsCaFile
 */
ZFUNC ZINT Mtc_CliDbSetDtlsCaFile(ZCHAR *pcFile);

/**
 * @brief Get dtls client ca file.
 *
 * @return dtls client trusted ca file, including path.
 *
 * @see @ref Mtc_CliDbSetDtlsCaFile
 */
ZFUNC ZCHAR * Mtc_CliDbGetDtlsCaFile(ZFUNC_VOID);

/**
 * @brief Get ux messaging UX.
 *
 * @return ux messaging UX .
 *
 * @see @ref Mtc_CliDbSetUxMessagingUX
 */
ZFUNC ZBOOL Mtc_CliDbGetUxMessagingUX();

/**
 * @brief Set ux messaging UX.
 *
 * @param [in] bMessagingUX The UX messaging style, false for converged inbox,
 * true for integrated messaging.
 *
 * @retval ZOK Set ux messaging UX successfully.
 * @retval ZFAILED ux messaging UX failed.
 *
 * @see @ref Mtc_CliDbGetUxMessagingUX
 */
ZFUNC ZINT Mtc_CliDbSetUxMessagingUX(ZBOOL bMessagingUX);

/**
 * @brief Set archive server address.
 *
 * @param [in] pcAcvServAddr The archive server address.
 *
 * @retval ZOK Set archive server address successfully.
 * @retval ZFAILED Set archive server address failed.
 *
 */
ZFUNC ZINT Mtc_CliDbSetAcvServAddr(ZCHAR *pcAcvServAddr);

/**
 * @brief Set archive url.
 *
 * @param [in] pcAcvUrl The archive url.
 *
 * @retval ZOK Set archive url successfully.
 * @retval ZFAILED Set archive url failed.
 *
 */
ZFUNC ZINT Mtc_CliDbSetAcvUrl(ZCHAR *pcAcvUrl);

/**
 * @brief Set archive server prot.
 *
 * @param [in] wPort The archive server prot.
 *
 * @retval ZOK Set archive prot successfully.
 * @retval ZFAILED Set archive prot failed.
 *
 */
ZFUNC ZINT Mtc_CliDbSetAcvServPort(ZUSHORT wPort);

/**
 * @brief Get public account server address.
 *
 * @return public account server address.
 *
 * @see @ref Mtc_CliDbSetPaServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaServAddr();

/**
 * @brief Set public account server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetPaServAddr
 */
ZFUNC ZINT Mtc_CliDbSetPaServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get public account server address type.
 *
 * @return public account server address type.
 *
 * @see @ref Mtc_CliDbSetPaServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaServAddrType();

/**
 * @brief Set public account server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetPaServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetPaServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get public account server root.
 *
 * @return public account server root.
 *
 * @see @ref Mtc_CliDbSetPaServRoot
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaServRoot();

/**
 * @brief Set public account server root.
 *
 * @param [in] pcServRoot The server root.
 *
 * @retval ZOK Set server root successfully.
 * @retval ZFAILED Set server root failed.
 *
 * @see @ref Mtc_CliDbGetPaServRoot
 */
ZFUNC ZINT Mtc_CliDbSetPaServRoot(ZCHAR *pcServRoot);

/**
 * @brief Get public account server port.
 *
 * @return public account server port.
 *
 * @see @ref Mtc_CliDbSetPaServPort
 */
ZFUNC ZUSHORT Mtc_CliDbGetPaServPort();

/**
 * @brief Set public account server port.
 *
 * @param [in] wPort The server port.
 *
 * @retval ZOK Set server port successfully.
 * @retval ZFAILED Set server port failed.
 *
 * @see @ref Mtc_CliDbGetPaServPort
 */
ZFUNC ZINT Mtc_CliDbSetPaServPort(ZUSHORT wPort);

/**
 * @brief Get public account http userid.
 *
 * @return public account http userid.
 *
 * @see @ref Mtc_CliDbSetPaHttpUserId
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaHttpUserId();

/**
 * @brief Set public account http userid.
 *
 * @param [in] pcHttpUserId The http userid.
 *
 * @retval ZOK Set http userid successfully.
 * @retval ZFAILED Set http userid failed.
 *
 * @see @ref Mtc_CliDbGetPaHttpUserId
 */
ZFUNC ZINT Mtc_CliDbSetPaHttpUserId(ZCHAR *pcHttpUserId);

/**
 * @brief Get public account version.
 *
 * @return public account version.
 *
 * @see @ref Mtc_CliDbSetPaVers
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaVers();

/**
 * @brief Set public account version.
 *
 * @param [in] pcVers The version.
 *
 * @retval ZOK Set version successfully.
 * @retval ZFAILED Set version failed.
 *
 * @see @ref Mtc_CliDbGetPaVers
 */
ZFUNC ZINT Mtc_CliDbSetPaVers(ZCHAR *pcVers);

/**
 * @brief Get public account authorization name.
 *
 * @return public account authorization name.
 *
 * @see @ref Mtc_CliDbSetPaAuthName
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaAuthName();

/**
 * @brief Set public account authorization name.
 *
 * @param [in] pcAuthName The authorization name.
 *
 * @retval ZOK Set authorization name successfully.
 * @retval ZFAILED Set authorization name failed.
 *
 * @see @ref Mtc_CliDbGetPaAuthName
 */
ZFUNC ZINT Mtc_CliDbSetPaAuthName(ZCHAR *pcAuthName);

/**
 * @brief Get public account authorization password.
 *
 * @return public account authorization password.
 *
 * @see @ref Mtc_CliDbSetPaAuthPass
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaAuthPass();

/**
 * @brief Set public account authorization password.
 *
 * @param [in] pcAuthPass The authorization password.
 *
 * @retval ZOK Set authorization password successfully.
 * @retval ZFAILED Set authorization password failed.
 *
 * @see @ref Mtc_CliDbGetPaAuthPass
 */
ZFUNC ZINT Mtc_CliDbSetPaAuthPass(ZCHAR *pcAuthPass);

/**
 * @brief Get public account authorization token.
 *
 * @return public account authorization token.
 *
 * @see @ref Mtc_CliDbSetPaAuthToken
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaAuthToken();

/**
 * @brief Set public account authorization token.
 *
 * @param [in] pcAuthToken The authorization token.
 *
 * @retval ZOK Set authorization token successfully.
 * @retval ZFAILED Set authorization token failed.
 *
 * @see @ref Mtc_CliDbGetPaAuthToken
 */
ZFUNC ZINT Mtc_CliDbSetPaAuthToken(ZCHAR *pcAuthToken);

/**
 * @brief Get public account authorization type.
 *
 * @return public account authorization type, @see @ref EN_MTC_PA_AUTH_TYPE.
 *
 * @see @ref Mtc_CliDbSetPaAuthType
 */
ZFUNC ZUINT Mtc_CliDbGetPaAuthType();

/**
 * @brief Set public account authorization type.
 *
 * @param [in] pcAuthType The authorization type, @see @ref EN_MTC_PA_AUTH_TYPE.
 *
 * @retval ZOK Set authorization type successfully.
 * @retval ZFAILED Set authorization type failed.
 *
 * @see @ref Mtc_CliDbGetPaAuthType
 */
ZFUNC ZINT Mtc_CliDbSetPaAuthType(ZUINT iAuthType);

/**
 * @brief Set public account user agent.
 *
 * @param [in] pcUserAgent The user agent.
 *
 * @retval ZOK Set user agent successfully.
 * @retval ZFAILED Set user agent failed.
 *
 * @see @ref Mtc_CliDbGetPaUserAgent
 */
ZFUNC ZINT Mtc_CliDbSetPaUserAgent(ZCHAR *pcUserAgent);

/**
 * @brief Get public account user agent.
 *
 * @return public account user agent.
 *
 * @see @ref Mtc_CliDbSetPaUserAgent
 */
ZFUNC ZCHAR * Mtc_CliDbGetPaUserAgent();

/**
 * @brief Get profile server address.
 *
 * @return profile server address.
 *
 * @see @ref Mtc_CliDbSetProfileServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetProfileServAddr();

/**
 * @brief Set profile server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetProfileServAddr
 */
ZFUNC ZINT Mtc_CliDbSetProfileServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get profile server address type.
 *
 * @return profile server address type.
 *
 * @see @ref Mtc_CliDbSetProfileServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetProfileServAddrType();

/**
 * @brief Set profile server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetProfileServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetProfileServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get pc as server address.
 *
 * @return pc as server address.
 *
 * @see @ref Mtc_CliDbSetPcAsServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetPcAsServAddr();

/**
 * @brief Set pc as server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetPcAsServAddr
 */
ZFUNC ZINT Mtc_CliDbSetPcAsServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get pc as server port.
 *
 * @return pc as server port.
 *
 * @see @ref Mtc_CliDbSetpcAsServPort
 */
ZFUNC ZUSHORT Mtc_CliDbGetPcAsServPort();

/**
 * @brief Set pc as server port.
 *
 * @param [in] wPort The server port.
 *
 * @retval ZOK Set server port successfully.
 * @retval ZFAILED Set server port failed.
 *
 * @see @ref Mtc_CliDbGetPcAsServPort
 */
ZFUNC ZINT Mtc_CliDbSetpcAsServPort(ZUSHORT wPort);


/**
 * @brief Get pc as server address type.
 *
 * @return pc as server address type.
 *
 * @see @ref Mtc_CliDbSetPcAsServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetPcAsServAddrType();

/**
 * @brief Set pc as server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetPcAsServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetPcAsServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get profile server root.
 *
 * @return profile server root.
 *
 * @see @ref Mtc_CliDbSetProfileServRoot
 */
ZFUNC ZCHAR * Mtc_CliDbGetProfileServRoot();

/**
 * @brief Set profile server root.
 *
 * @param [in] pcServRoot The server root.
 *
 * @retval ZOK Set server root successfully.
 * @retval ZFAILED Set server root failed.
 *
 * @see @ref Mtc_CliDbGetProfileServRoot
 */
ZFUNC ZINT Mtc_CliDbSetProfileServRoot(ZCHAR *pcServRoot);

/**
 * @brief Get profile server port.
 *
 * @return profile server port.
 *
 * @see @ref Mtc_CliDbSetProfileServPort
 */
ZFUNC ZUSHORT Mtc_CliDbGetProfileServPort();

/**
 * @brief Set profile server port.
 *
 * @param [in] wPort The server port.
 *
 * @retval ZOK Set server port successfully.
 * @retval ZFAILED Set server port failed.
 *
 * @see @ref Mtc_CliDbGetProfileServPort
 */
ZFUNC ZINT Mtc_CliDbSetProfileServPort(ZUSHORT wPort);

/**
 * @brief Get profile authorization name.
 *
 * @return profile authorization name.
 *
 * @see @ref Mtc_CliDbSetProfileAuthName
 */
ZFUNC ZCHAR * Mtc_CliDbGetProfileAuthName();

/**
 * @brief Set profile authorization name.
 *
 * @param [in] pcAuthName The authorization name.
 *
 * @retval ZOK Set authorization name successfully.
 * @retval ZFAILED Set authorization name failed.
 *
 * @see @ref Mtc_CliDbGetProfileAuthName
 */
ZFUNC ZINT Mtc_CliDbSetProfileAuthName(ZCHAR *pcAuthName);

/**
 * @brief Get profile authorization password.
 *
 * @return profile authorization password.
 *
 * @see @ref Mtc_CliDbSetProfileAuthPass
 */
ZFUNC ZCHAR * Mtc_CliDbGetProfileAuthPass();

/**
 * @brief Set profile authorization password.
 *
 * @param [in] pcAuthPass The authorization password.
 *
 * @retval ZOK Set authorization password successfully.
 * @retval ZFAILED Set authorization password failed.
 *
 * @see @ref Mtc_CliDbGetProfileAuthPass
 */
ZFUNC ZINT Mtc_CliDbSetProfileAuthPass(ZCHAR *pcAuthPass);

/**
 * @brief Get profile authorization token.
 *
 * @return profile authorization token.
 *
 * @see @ref Mtc_CliDbSetProfileAuthToken
 */
ZFUNC ZCHAR * Mtc_CliDbGetProfileAuthToken();

/**
 * @brief Set profile authorization token.
 *
 * @param [in] pcAuthToken The authorization token.
 *
 * @retval ZOK Set authorization token successfully.
 * @retval ZFAILED Set authorization token failed.
 *
 * @see @ref Mtc_CliDbGetProfileAuthToken
 */
ZFUNC ZINT Mtc_CliDbSetProfileAuthToken(ZCHAR *pcAuthToken);

/**
 * @brief Get profile authorization type.
 *
 * @return profile authorization type, @see @ref EN_MTC_PROFILE_AUTH_TYPE.
 *
 * @see @ref Mtc_CliDbSetProfileAuthType
 */
ZFUNC ZUINT Mtc_CliDbGetProfileAuthType();

/**
 * @brief Set profile authorization type.
 *
 * @param [in] pcAuthType The authorization type, @see @ref EN_MTC_PROFILE_AUTH_TYPE.
 *
 * @retval ZOK Set authorization type successfully.
 * @retval ZFAILED Set authorization type failed.
 *
 * @see @ref Mtc_CliDbGetProfileAuthType
 */
ZFUNC ZINT Mtc_CliDbSetProfileAuthType(ZUINT iAuthType);

/**
 * @brief Get qrcard server address.
 *
 * @return qrcard server address.
 *
 * @see @ref Mtc_CliDbSetQrcardServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetQrcardServAddr();

/**
 * @brief Set qrcard server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetQrcardServAddr
 */
ZFUNC ZINT Mtc_CliDbSetQrcardServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get qrcard server address type.
 *
 * @return qrcard server address type.
 *
 * @see @ref Mtc_CliDbSetQrcardServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetQrcardServAddrType();

/**
 * @brief Set qrcard server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetQrcardServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetQrcardServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get qrcard server root.
 *
 * @return qrcard server root.
 *
 * @see @ref Mtc_CliDbSetQrcardServRoot
 */
ZFUNC ZCHAR * Mtc_CliDbGetQrcardServRoot();

/**
 * @brief Set qrcard server root.
 *
 * @param [in] pcServRoot The server root.
 *
 * @retval ZOK Set server root successfully.
 * @retval ZFAILED Set server root failed.
 *
 * @see @ref Mtc_CliDbGetQrcardServRoot
 */
ZFUNC ZINT Mtc_CliDbSetQrcardServRoot(ZCHAR *pcServRoot);

/**
 * @brief Get qrcard server port.
 *
 * @return qrcard server port.
 *
 * @see @ref Mtc_CliDbSetQrcardServPort
 */
ZFUNC ZUSHORT Mtc_CliDbGetQrcardServPort();

/**
 * @brief Set qrcard server port.
 *
 * @param [in] wPort The server port.
 *
 * @retval ZOK Set server port successfully.
 * @retval ZFAILED Set server port failed.
 *
 * @see @ref Mtc_CliDbGetQrcardServPort
 */
ZFUNC ZINT Mtc_CliDbSetQrcardServPort(ZUSHORT wPort);

/**
 * @brief Get qrcard authorization name.
 *
 * @return qrcard authorization name.
 *
 * @see @ref Mtc_CliDbSetQrcardAuthName
 */
ZFUNC ZCHAR * Mtc_CliDbGetQrcardAuthName();

/**
 * @brief Set qrcard authorization name.
 *
 * @param [in] pcAuthName The authorization name.
 *
 * @retval ZOK Set authorization name successfully.
 * @retval ZFAILED Set authorization name failed.
 *
 * @see @ref Mtc_CliDbGetQrcardAuthName
 */
ZFUNC ZINT Mtc_CliDbSetQrcardAuthName(ZCHAR *pcAuthName);

/**
 * @brief Get qrcard authorization password.
 *
 * @return qrcard authorization password.
 *
 * @see @ref Mtc_CliDbSetQrcardAuthPass
 */
ZFUNC ZCHAR * Mtc_CliDbGetQrcardAuthPass();

/**
 * @brief Set qrcard authorization password.
 *
 * @param [in] pcAuthPass The authorization password.
 *
 * @retval ZOK Set authorization password successfully.
 * @retval ZFAILED Set authorization password failed.
 *
 * @see @ref Mtc_CliDbGetQrcardAuthPass
 */
ZFUNC ZINT Mtc_CliDbSetQrcardAuthPass(ZCHAR *pcAuthPass);

/**
 * @brief Get qrcard authorization token.
 *
 * @return qrcard authorization token.
 *
 * @see @ref Mtc_CliDbSetQrcardAuthToken
 */
ZFUNC ZCHAR * Mtc_CliDbGetQrcardAuthToken();

/**
 * @brief Set qrcard authorization token.
 *
 * @param [in] pcAuthToken The authorization token.
 *
 * @retval ZOK Set authorization token successfully.
 * @retval ZFAILED Set authorization token failed.
 *
 * @see @ref Mtc_CliDbGetQrcardAuthToken
 */
ZFUNC ZINT Mtc_CliDbSetQrcardAuthToken(ZCHAR *pcAuthToken);

/**
 * @brief Get qrcard authorization type.
 *
 * @return qrcard authorization type, @see @ref EN_MTC_QRCARD_AUTH_TYPE.
 *
 * @see @ref Mtc_CliDbSetQrcardAuthType
 */
ZFUNC ZUINT Mtc_CliDbGetQrcardAuthType();

/**
 * @brief Set qrcard authorization type.
 *
 * @param [in] pcAuthType The authorization type, @see @ref EN_MTC_QRCARD_AUTH_TYPE.
 *
 * @retval ZOK Set authorization type successfully.
 * @retval ZFAILED Set authorization type failed.
 *
 * @see @ref Mtc_CliDbGetQrcardAuthType
 */
ZFUNC ZINT Mtc_CliDbSetQrcardAuthType(ZUINT iAuthType);

/**
 * @brief Get network address book server address.
 *
 * @return network address book server address.
 *
 * @see @ref Mtc_CliDbSetNabServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetNabServAddr();

/**
 * @brief Set network address book server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetNabServAddr
 */
ZFUNC ZINT Mtc_CliDbSetNabServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get network address book server address type.
 *
 * @return network address book server address type.
 *
 * @see @ref Mtc_CliDbSetNabServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetNabServAddrType();

/**
 * @brief Set network address book server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetNabServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetNabServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get single sign-on server address.
 *
 * @return single sign-on server address.
 *
 * @see @ref Mtc_CliDbSetSsoServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetSsoServAddr();

/**
 * @brief Set single sign-on server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetSsoServAddr
 */
ZFUNC ZINT Mtc_CliDbSetSsoServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get single sign-on server address type.
 *
 * @return single sign-on server address type.
 *
 * @see @ref Mtc_CliDbSetSsoServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetSsoServAddrType();

/**
 * @brief Set single sign-on server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetSsoServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetSsoServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get enriched call as content management system server address.
 *
 * @return enriched call as content management system server address.
 *
 * @see @ref Mtc_CliDbSetEcscmsServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetEcscmsServAddr();

/**
 * @brief Set enriched call as content management system server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetEcscmsServAddr
 */
ZFUNC ZINT Mtc_CliDbSetEcscmsServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get enriched call as content management system server address type.
 *
 * @return enriched call as content management system server address type.
 *
 * @see @ref Mtc_CliDbSetEcscmsServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetEcscmsServAddrType();

/**
 * @brief Set enriched call as content management system server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetEcscmsServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetEcscmsServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get enriched call as content management system number prefixes.
 *
 * @return enriched call as content management system number prefixes.
 *
 * @see @ref Mtc_CliDbSetEcscmsNumberPrefixes
 */
ZFUNC ZCHAR * Mtc_CliDbGetEcscmsNumberPrefixes();

/**
 * @brief Set enriched call as content management system number prefixes.
 *
 * @param [in] pcNumberPrefixes The number prefixes.
 *
 * @retval ZOK Set number prefixes successfully.
 * @retval ZFAILED Set number prefixes failed.
 *
 * @see @ref Mtc_CliDbGetEcscmsNumberPrefixes
 */
ZFUNC ZINT Mtc_CliDbSetEcscmsNumberPrefixes(ZCHAR *pcNumberPrefixes);

/**
 * @brief Get user manger server address.
 *
 * @return user manger server address.
 *
 * @see @ref Mtc_CliDbSetUserMangerServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetUserMangerServAddr();

/**
 * @brief Set user manger server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetUserMangerServAddr
 */
ZFUNC ZINT Mtc_CliDbSetUserMangerServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get user manger server address type.
 *
 * @return user manger server address type.
 *
 * @see @ref Mtc_CliDbSetUserMangerServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetUserMangerServAddrType();

/**
 * @brief Set user manger server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetUserMangerServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetUserMangerServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get iap server address.
 *
 * @return user manger server address.
 *
 * @see @ref Mtc_CliDbSetIapServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetIapServAddr();

/**
 * @brief Set iap server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetIapServAddr
 */
ZFUNC ZINT Mtc_CliDbSetIapServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get iap server address type.
 *
 * @return user manger server address type.
 *
 * @see @ref Mtc_CliDbSetIapServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetIapServAddrType();

/**
 * @brief Set iap server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetIapServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetIapServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get profile authorization flag.
 *
 * @retval ZTRUE Indications profile is authorized.
 * @retval ZFALSE Indications profile is not authorized.
 *
 * @see @ref Mtc_CliDbSetProfileAuth
 */
ZFUNC ZBOOL Mtc_CliDbGetProfileAuth();

/**
 * @brief Set profile authorization flag.
 *
 * @param [in] bAuth The authorization flag.
 *
 * @retval ZOK Set authorization flag successfully.
 * @retval ZFAILED Set authorization flag failed.
 *
 * @see @ref Mtc_CliDbGetProfileAuth
 */
ZFUNC ZINT Mtc_CliDbSetProfileAuth(ZBOOL bAuth);

/**
 * @brief Get nab authorization flag.
 *
 * @retval ZTRUE Indications nab is authorized.
 * @retval ZFALSE Indications nab is not authorized.
 *
 * @see @ref Mtc_CliDbSetNabAuth
 */
ZFUNC ZBOOL Mtc_CliDbGetNabAuth();

/**
 * @brief Set nab authorization flag.
 *
 * @param [in] bAuth The authorization flag.
 *
 * @retval ZOK Set authorization flag successfully.
 * @retval ZFAILED Set authorization flag failed.
 *
 * @see @ref Mtc_CliDbGetNabAuth
 */
ZFUNC ZINT Mtc_CliDbSetNabAuth(ZBOOL bAuth);

/**
 * @brief Get public account authorization flag.
 *
 * @retval ZTRUE Indications public account is authorized.
 * @retval ZFALSE Indications public account is not authorized.
 *
 * @see @ref Mtc_CliDbSetPaAuth
 */
ZFUNC ZBOOL Mtc_CliDbGetPaAuth();

/**
 * @brief Set public account authorization flag.
 *
 * @param [in] bAuth The authorization flag.
 *
 * @retval ZOK Set authorization flag successfully.
 * @retval ZFAILED Set authorization flag failed.
 *
 * @see @ref Mtc_CliDbGetPaAuth
 */
ZFUNC ZINT Mtc_CliDbSetPaAuth(ZBOOL bAuth);

/**
 * @brief Get sso authorization flag.
 *
 * @retval ZTRUE Indications sso is authorized.
 * @retval ZFALSE Indications sso is not authorized.
 *
 * @see @ref Mtc_CliDbSetSsoAuth
 */
ZFUNC ZBOOL Mtc_CliDbGetSsoAuth();

/**
 * @brief Set sso authorization flag.
 *
 * @param [in] bAuth The authorization flag.
 *
 * @retval ZOK Set authorization flag successfully.
 * @retval ZFAILED Set authorization flag failed.
 *
 * @see @ref Mtc_CliDbGetSsoAuth
 */
ZFUNC ZINT Mtc_CliDbSetSsoAuth(ZBOOL bAuth);

/**
 * @brief Get ECSCMS authorization flag.
 *
 * @retval ZTRUE Indications sso is authorized.
 * @retval ZFALSE Indications sso is not authorized.
 *
 * @see @ref Mtc_CliDbSetEcscmsAuth
 */
ZFUNC ZBOOL Mtc_CliDbGetEcscmsAuth();

/**
 * @brief Set ECSCMS authorization flag.
 *
 * @param [in] bAuth The authorization flag.
 *
 * @retval ZOK Set authorization flag successfully.
 * @retval ZFAILED Set authorization flag failed.
 *
 * @see @ref Mtc_CliDbGetEcscmsAuth
 */
ZFUNC ZINT Mtc_CliDbSetEcscmsAuth(ZBOOL bAuth);

/**
 * @brief Get UserManger authorization flag.
 *
 * @retval ZTRUE Indications sso is authorized.
 * @retval ZFALSE Indications sso is not authorized.
 *
 * @see @ref Mtc_CliDbSetUserMangerAuth
 */
ZFUNC ZBOOL Mtc_CliDbGetUserMangerAuth();

/**
 * @brief Set UserManger authorization flag.
 *
 * @param [in] bAuth The authorization flag.
 *
 * @retval ZOK Set authorization flag successfully.
 * @retval ZFAILED Set authorization flag failed.
 *
 * @see @ref Mtc_CliDbGetUserMangerAuth
 */
ZFUNC ZINT Mtc_CliDbSetUserMangerAuth(ZBOOL bAuth);

/**
 * @brief Get Iap authorization flag.
 *
 * @retval ZTRUE Indications sso is authorized.
 * @retval ZFALSE Indications sso is not authorized.
 *
 * @see @ref Mtc_CliDbSetIapAuth
 */
ZFUNC ZBOOL Mtc_CliDbGetIapAuth();

/**
 * @brief Set Iap authorization flag.
 *
 * @param [in] bAuth The authorization flag.
 *
 * @retval ZOK Set authorization flag successfully.
 * @retval ZFAILED Set authorization flag failed.
 *
 * @see @ref Mtc_CliDbGetIapAuth
 */
ZFUNC ZINT Mtc_CliDbSetIapAuth(ZBOOL bAuth);

/**
 * @brief get stg use type.
 *
 * @return stg use type, @see @ref EN_MTC_STG_USETYPE.
 *
 * @see Mtc_CliDbSetStgUseType
 */
ZFUNC ZINT Mtc_CliDbGetStgUseType(ZFUNC_VOID);

/**
 * @brief set stg use type.
 *
 * @param [in] iStgUseType stg use type, @see @ref EN_MTC_STG_USETYPE.
 *
 * @retval ZOK Set stg use type successfully.
 * @retval ZFAILED Set stg use type failed.
 *
 * @see Mtc_CliDbGetStgUseType
 */
ZFUNC ZINT Mtc_CliDbSetStgUseType(ZINT iStgUseType);

/**
 * @brief get stg tunnel type.
 *
 * @return stg tunnel type, @see @ref EN_MTC_STG_TRANSPORT.
 *
 * @see Mtc_CliDbSetStgTunnelType
 */
ZFUNC ZINT Mtc_CliDbGetStgTunnelType(ZFUNC_VOID);

/**
 * @brief set stg tunnel type.
 *
 * @param [in] iStgTunnelType stg tunnel type, @see @ref EN_MTC_STG_TRANSPORT.
 *
 * @retval ZOK Set stg tunnel type successfully.
 * @retval ZFAILED Set stg tunnel type failed.
 *
 * @see Mtc_CliDbGetStgTunnelType
 */
ZFUNC ZINT Mtc_CliDbSetStgTunnelType(ZINT iStgTunnelType);

/**
 * @brief get stg tunnel ip.
 *
 * @return stg tunnel ip.
 *
 * @see Mtc_CliDbSetStgTunnelIp
 */
ZFUNC ZCHAR* Mtc_CliDbGetStgTunnelIp(ZFUNC_VOID);

/**
 * @brief set stg tunnel ip.
 *
 * @param [in] pcIp stg tunnel ip.
 *
 * @retval ZOK Set stg tunnel ip successfully.
 * @retval ZFAILED Set stg tunnel ip failed.
 *
 * @see Mtc_CliDbGetStgTunnelIp
 */
ZFUNC ZINT Mtc_CliDbSetStgTunnelIp(ZCHAR* pcIp);

/**
 * @brief get stg tunnel port.
 *
 * @return stg tunnel port.
 *
 * @see Mtc_CliDbSetStgTunnelIp
 */
ZFUNC ZUSHORT Mtc_CliDbGetStgTunnelPort(ZFUNC_VOID);

/**
 * @brief set stg tunnel port.
 *
 * @param [in] wPort stg tunnel port.
 *
 * @retval ZOK Set stg tunnel port successfully.
 * @retval ZFAILED Set stg tunnel port failed.
 *
 * @see Mtc_CliDbGetStgTunnelPort
 */
ZFUNC ZINT Mtc_CliDbSetStgTunnelPort(ZUSHORT wPort);

/**
 * @brief get stg tunnel proxy enable.
 *
 * @return stg tunnel proxy enable.
 *
 * @see Mtc_CliDbSetStgTunnelProxyEnable
 */
ZFUNC ZBOOL Mtc_CliDbGetStgTunnelProxyEnable(ZFUNC_VOID);

/*
* @brief set stg tunnel proxy enable.
*
* @param [in] bProxy stg tunnel proxy enable.
*
* @retval ZOK Set stg tunnel enable successfully.
* @retval ZFAILED Set stg tunnel enable failed.
*
* @see Mtc_CliDbGetStgTunnelProxyEnable
*/
ZFUNC ZINT Mtc_CliDbSetStgTunnelProxyEnable(ZBOOL bProxy);

/* 
 * @brief get stg tunnel proxy server address.
 *
 * @return stg tunnel proxy server address.
 *
 * @see Mtc_CliDbSetStgTunnelProxySrvAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetStgTunnelProxySrvAddr(ZFUNC_VOID);

/*
* @brief set tunnel proxy server address.
*
* @param [in] pcSrvAddr stg tunnel proxy server address.
*
* @retval ZOK Set stg tunnel server address successfully.
* @retval ZFAILED Set stg tunnel server address failed.
*
* @see Mtc_CliDbGetStgTunnelProxySrvAddr
*/
ZFUNC ZINT Mtc_CliDbSetStgTunnelProxySrvAddr(ZCHAR *pcSrvAddr);

/* 
 * @brief get stg tunnel proxy server port.
 *
 * @return stg tunnel proxy server port.
 *
 * @see Mtc_CliDbSetStgTunnelProxySrvPort
 */
ZFUNC ZSHORT Mtc_CliDbGetStgTunnelProxySrvPort(ZFUNC_VOID);

/*
* @brief set tunnel proxy server port.
*
* @param [in] wProxyPort stg tunnel proxy server port.
*
* @retval ZOK Set stg tunnel server port successfully.
* @retval ZFAILED Set stg tunnel server port failed.
*
* @see Mtc_CliDbGetStgTunnelProxySrvPort
*/
ZFUNC ZINT Mtc_CliDbSetStgTunnelProxySrvPort(ZUSHORT wProxyPort);

/* 
 * @brief get stg tunnel proxy server username.
 *
 * @return stg tunnel proxy server username.
 *
 * @see Mtc_CliDbSetStgTunnelProxySrvUsername
 */
ZFUNC ZCHAR * Mtc_CliDbGetStgTunnelProxySrvUsername(ZFUNC_VOID);

/*
* @brief set tunnel proxy server username.
*
* @param [in] pcProxyUsername stg tunnel proxy server username.
*
* @retval ZOK Set stg tunnel server username successfully.
* @retval ZFAILED Set stg tunnel server username failed.
*
* @see Mtc_CliDbGetStgTunnelProxySrvUsername
*/
ZFUNC ZINT Mtc_CliDbSetStgTunnelProxySrvUsername(ZCHAR *pcProxyUsername);

/* 
 * @brief get stg tunnel proxy server password.
 *
 * @return stg tunnel proxy server password.
 *
 * @see Mtc_CliDbSetStgTunnelProxySrvPwd
 */
ZFUNC ZCHAR * Mtc_CliDbGetStgTunnelProxySrvPwd(ZFUNC_VOID);

/*
* @brief set tunnel proxy server password.
*
* @param [in] pcProxyPwd stg tunnel proxy server password.
*
* @retval ZOK Set stg tunnel server password successfully.
* @retval ZFAILED Set stg tunnel server password failed.
*
* @see Mtc_CliDbGetStgTunnelProxySrvPwd
*/
ZFUNC ZINT Mtc_CliDbSetStgTunnelProxySrvPwd(ZCHAR *pcProxyPwd);

/**
 * @brief Get use backup server from database.
 *
 * @retval ZTRUE Use backup server.
 * @retval ZFALSE Do not use backup server.
 *
 * @see @ref Mtc_CliDbSetUseBackupServer
 */
ZFUNC ZBOOL Mtc_CliDbGetUseBackupServer(ZFUNC_VOID);

/**
 * @brief Get use backup server.
 *
 * @param [in] bUse Use flag.
 *
 * @retval ZOK Set use backup server successfully.
 * @retval ZFAILED Set use backup server failed.
 *
 * @see @ref Mtc_CliDbGetUseBackupServer
 */
ZFUNC ZINT Mtc_CliDbSetUseBackupServer(ZBOOL bUse);

/**
 * @brief Get bsf server address.
 *
 * @return bsf server address.
 *
 * @see @ref Mtc_CliDbSetBsfServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetBsfServAddr();

/**
 * @brief Set bsf server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetBsfServAddr
 */
ZFUNC ZINT Mtc_CliDbSetBsfServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get bsf server address type.
 *
 * @return bsf server address type.
 *
 * @see @ref Mtc_CliDbSetBsfServAddrType
 */
ZFUNC ZCHAR * Mtc_CliDbGetBsfServAddrType();

/**
 * @brief Set bsf server address type.
 *
 * @param [in] pcServAddrType The server address type.
 *
 * @retval ZOK Set server address type successfully.
 * @retval ZFAILED Set server address type failed.
 *
 * @see @ref Mtc_CliDbGetBsfServAddrType
 */
ZFUNC ZINT Mtc_CliDbSetBsfServAddrType(ZCHAR *pcServAddrType);

/**
 * @brief Get bsf server port.
 *
 * @return bsf server port.
 *
 * @see @ref Mtc_CliDbSetBsfServPort
 */
ZFUNC ZUSHORT Mtc_CliDbGetBsfServPort();

/**
 * @brief Set bsf server port.
 *
 * @param [in] wPort The server port.
 *
 * @retval ZOK Set server port successfully.
 * @retval ZFAILED Set server port failed.
 *
 * @see @ref Mtc_CliDbGetBsfServPort
 */
ZFUNC ZINT Mtc_CliDbSetBsfServPort(ZUSHORT wPort);

/**
 * @brief Get bsf realm.
 *
 * @return bsf realm.
 *
 * @see @ref Mtc_CliDbSetBsfRealm
 */
ZFUNC ZCHAR * Mtc_CliDbGetBsfRealm();

/**
 * @brief Set bsf realm.
 *
 * @param [in] wPort The realm.
 *
 * @retval ZOK Set realm successfully.
 * @retval ZFAILED Set realm failed.
 *
 * @see @ref Mtc_CliDbGetBsfRealm
 */
ZFUNC ZINT Mtc_CliDbSetBsfRealm(ZCHAR *pcRealm);

/**
 * @brief Get device token.
 *
 * @return device token.
 *
 * @see @ref Mtc_CliDbSetPushToken
 */
ZFUNC ZCHAR * Mtc_CliDbGetDevToken();

/**
 * @brief Get Voip token.
 *
 * @return device token.
 *
 * @see @ref Mtc_CliDbSetPushToken
 */
ZFUNC ZCHAR * Mtc_CliDbGetVoipToken();

/**
 * @brief Get TokenType.
 *
 * @return TokenType.
 *
 * @see @ref Mtc_CliDbSetPushToken
 */
ZFUNC ZCHAR * Mtc_CliDbGetTokenType();

/**
 * @brief Set device token.
 *
 * @param [in] pcDevToken The device token.
 * @param [in] pcVoipToken The Voip token.
 * @param [in] pcTokenType The TokenType,see @ref MTC_PUSH_SERVER_IOS etc.
 *
 * @retval ZOK Set device token successfully.
 * @retval ZFAILED Set device token failed.
 *
 */
ZFUNC ZINT Mtc_CliDbSetPushToken(ZCHAR *pcDevToken, ZCHAR *pcVoipToken, 
            ZCHAR *pcTokenType) ;

/**
 * @brief Get calibrate time option from database.
 *
 * @retval ZTRUE Calibrate Time.
 * @retval ZFALSE Do not calibrate time.
 */
ZFUNC ZBOOL Mtc_CliDbGetCalibrateTime(ZFUNC_VOID);

/**
 * @brief Set calibrate time option.
 *
 * @param [in] bCalibrateTime calibrate time option.
 *
 * @retval ZOK Set calibrate time option successfully.
 * @retval ZFAILED Set calibrate time option failed.
 *
 * @see @ref Mtc_CliDbGetCalibrateTime
 */
ZFUNC ZINT Mtc_CliDbSetCalibrateTime(ZBOOL bCalibrateTime);

/**
 * @brief mtc set user id policy.
 *
 * @param [in] iPolicy user policy @ref EN_MTC_UID_POLICY_TYPE.
 *
 * @retval ZOK Set user policy option successfully.
 * @retval ZFAILED Set user policy option failed.
 *
 */
ZFUNC ZINT Mtc_CliDbSetUserIdPolicy(ZUINT iPolicy);

/**
 * @brief mtc set user impi.
 *
 * @param [in] pcImpi user impi.
 *
 * @retval ZOK Set user impi option successfully.
 * @retval ZFAILED Set user impi option failed.
 *
 */
ZFUNC ZINT Mtc_CliDbSetImpi(ZCHAR *pcImpi);

/**
 * @brief mtc get user impi.
 *
 */
ZFUNC ZCHAR * Mtc_CliDbGetImpi();

/**
 * @brief Get register address type.
 *
 * @return The register address type.
 *
 * @see @ref Mtc_CliDbSetRegAddrType
 */
ZFUNC ZUINT Mtc_CliDbGetRegAddrType(ZFUNC_VOID);

/**
 * @brief Set register address type.
 *
 * @param [in] iAddrType The register address type.
 *
 * @retval ZOK Set the register address type successfully.
 * @retval ZFAILED Set the register address type failed.
 *
 * @see @ref Mtc_CliDbGetRegAddrType
 */
ZFUNC ZINT Mtc_CliDbSetRegAddrType(ZUINT iAddrType);

/**
 * @brief Get secondary register address type.
 *
 * @return The secondary register address type.
 *
 * @see @ref Mtc_CliDbSet2ndRegAddrType
 */
ZFUNC ZUINT Mtc_CliDbGet2ndRegAddrType(ZFUNC_VOID);

/**
 * @brief Set secondary register address type.
 *
 * @param [in] iAddrType The secondary register address type.
 *
 * @retval ZOK Set the secondary register address type successfully.
 * @retval ZFAILED Set the secondary register address type failed.
 *
 * @see @ref Mtc_CliDbGet2ndRegAddrType
 */
ZFUNC ZINT Mtc_CliDbSet2ndRegAddrType(ZUINT iAddrType);

/*
 * @brief mtc get cnpc sync and verify http server address.
 */
ZFUNC ZCHAR * Mtc_CliDbGetCnpcHttpServAddr(ZFUNC_VOID);

/**
 * @brief mtc set cnpc sync and verify server address.
 *
 * @param [in] pcServAddr server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 */
ZFUNC ZINT Mtc_CliDbSetCnpcHttpServAddr(ZCHAR *pcServAddr);

/**
 * @brief mtc get cnpc sync and verify http server port.
 */
ZFUNC ZUSHORT Mtc_CliDbGetCnpcHttpServPort(ZFUNC_VOID);

/**
 * @brief mtc set cnpc sync and verify server port.
 *
 * @param [in] wPort server port.
 *
 * @retval ZOK Set server port successfully.
 * @retval ZFAILED Set server port failed.
 */
ZFUNC ZINT Mtc_CliDbSetCnpcHttpServPort(ZUSHORT wPort);

/**
 * @brief mtc get cnpc sync server root.
 */
ZFUNC ZCHAR * Mtc_CliDbGetCnpcSyncServRoot(ZFUNC_VOID);

/**
 * @brief mtc set cnpc sync server root.
 *
 * @param [in] pcSyncRoot server root uri.
 *
 * @retval ZOK Set server root successfully.
 * @retval ZFAILED Set server root failed.
 */
ZFUNC ZINT Mtc_CliDbSetCnpcSyncServRoot(ZCHAR *pcSyncRoot);

/**
 * @brief mtc get cnpc verify server root.
 */
ZFUNC ZCHAR * Mtc_CliDbGetCnpcVerifyServRoot(ZFUNC_VOID);

/**
 * @brief mtc set cnpc verify server root.
 *
 * @param [in] pcVerifyRoot server root uri.
 *
 * @retval ZOK Set server root successfully.
 * @retval ZFAILED Set server root failed.
 */
ZFUNC ZINT Mtc_CliDbSetCnpcVerifyServRoot(ZCHAR *pcVerifyRoot);

/**
 * @brief Get a deactived enable flag.
 *
 * @return deactived enable.
 *
 * @see @ref Mtc_CliDbSetDeactedEnable
 *
 */
ZFUNC ZBOOL Mtc_CliDbGetDeactedEnable(ZFUNC_VOID);

/**
 * @brief Set a deactived enable flag. 
 *
 * @param [in] bEnable deactived enable.
 *
 * @return deactived enable.
 *
 * @retval ZOK Set deactived enable successfully.
 * @retval ZFAILED Set deactived enable failed.
 *
 * @see @ref Mtc_CliDbGetDeactedEnable
 *
 */
ZFUNC ZUINT Mtc_CliDbSetDeactedEnable(ZBOOL bEnable);

/**
 * @brief Get access network info of country.
 *
 * @return access network info of country.
 *
 * @see @ref Mtc_CliDbSetAccNetInfoCountry
 *
 */
ZFUNC ZCHAR * Mtc_CliDbGetAccNetInfoCountry(ZFUNC_VOID);

/**
 * @brief Set access network info of country. 
 *
 * @param [in] access network info of country.
 *
 * @retval ZOK Set AccNetInfoCountry successfully.
 * @retval ZFAILED Set AccNetInfoCountry failed.
 *
 * @see @ref Mtc_CliDbGetAccNetInfoCountry
 *
 */
ZFUNC ZINT Mtc_CliDbSetAccNetInfoCountry(ZCHAR *pcInfoCountry);

/**
 * @brief Get access network info of city.
 *
 * @return access network info of city.
 *
 * @see @ref Mtc_CliDbSetAccNetInfoCity
 *
 */
ZFUNC ZCHAR * Mtc_CliDbGetAccNetInfoCity(ZFUNC_VOID);

/**
 * @brief Set access network info of city. 
 *
 * @param [in] access network info of city.
 *
 * @retval ZOK Set AccNetInfoCity successfully.
 * @retval ZFAILED Set AccNetInfoCity failed.
 *
 * @see @ref Mtc_CliDbGetAccNetInfoCity
 *
 */
ZFUNC ZINT Mtc_CliDbSetAccNetInfoCity(ZCHAR *pcInfoCity);

/**
 * @brief Get SSO login white address.
 *
 * @param [in] iIndex the index of address in address list.
 *
 * @return SSO login white address.
 *
 * @see @ref Mtc_CliDbSetSSOWhiteAddr
 *
 */
ZFUNC ZCHAR * Mtc_CliDbGetSSOWhiteAddr(ZUINT iIndex);

/* mtc db set SSO login white address */
/**
 * @brief Set SSO login white address. 
 *
 * @param [in] pcServAddr SSO login white address.
 * @param [in] iIndex the index of address in address list.
 *
 * @retval ZOK Set white address successfully.
 * @retval ZFAILED Set white address failed.
 *
 * @see @ref Mtc_CliDbGetSSOWhiteAddr
 *
 */
ZFUNC ZINT Mtc_CliDbSetSSOWhiteAddr(ZCHAR *pcServAddr, ZUINT iIndex);

/**
 * @brief Get SSO login white address type.
 *
 * @param [in] iIndex the index of addr type in addr type list.
 *
 * @return SSO login white address type.
 *
 * @see @ref Mtc_CliDbSetSSOWhiteAddrType
 *
 */
ZFUNC ZCHAR * Mtc_CliDbGetSSOWhiteAddrType(ZUINT iIndex);

/* mtc db set SSO login white address type */
/**
 * @brief Set SSO login white address type. 
 *
 * @param [in] pcServAddrType SSO login white address type.
 * @param [in] iIndex the index of addr type in addr type list.
 *
 * @retval ZOK Set white address type successfully.
 * @retval ZFAILED Set white address type failed.
 *
 * @see @ref Mtc_CliDbGetSSOWhiteAddrType
 *
 */
ZFUNC ZINT Mtc_CliDbSetSSOWhiteAddrType(ZCHAR *pcServAddrType, ZUINT iIndex);

/**
 * @brief Get SSO white address list size.
 *
 * @retval The size of SSO white address list, default is 0,max is 10.
 *
 * @see @ref Mtc_CliDbSetSSOWhiteAddrLstSize
 */
ZFUNC ZUINT Mtc_CliDbGetSSOWhiteAddrLstSize();

/**
 * @brief Set SSO white address list size.
 *
 * @param [in] iLstSize The SSO white address list size.
 *
 * @retval ZOK Set SSO white address list size successfully.
 * @retval ZFAILED Set SSO white address list size failed.
 *
 * @see @ref Mtc_CliDbGetSSOWhiteAddrLstSize
 */
ZFUNC ZINT Mtc_CliDbSetSSOWhiteAddrLstSize(ZUINT iLstSize);

/**
 * @brief Get a auto reg enable flag.
 *
 * @return auto reg enable.
 *
 * @see @ref Mtc_CliDbSetAutoRegEnable
 *
 */
ZFUNC ZBOOL Mtc_CliDbGetAutoRegEnable(ZFUNC_VOID);

/**
 * @brief Set a auto reg enable flag. 
 *
 * @param [in] bEnable auto reg enable.
 *
 * @retval ZOK Set auto reg enable successfully.
 * @retval ZFAILED Set auto reg enable failed.
 *
 * @see @ref Mtc_CliDbGetAutoRegEnable
 *
 */
ZFUNC ZINT Mtc_CliDbSetAutoRegEnable(ZBOOL bEnable);

/**
 * @brief Get IMEI.
 *
 * @return IMEI.
 *
 * @see @ref Mtc_CliDbSetIMEI
 */
ZFUNC ZCHAR * Mtc_CliDbGetIMEI();

/**
 * @brief mtc set IMEI.
 *
 * @param [in] pcIMEI IMEI.
 *
 * @retval ZOK Set IMEI successfully.
 * @retval ZFAILED Set IMEI failed.
 *
 * @see @ref Mtc_CliDbGetIMEI
 *
 */
ZFUNC ZINT Mtc_CliDbSetIMEI(ZCHAR *pcIMEI);

/**
 * @brief Get CellId.
 *
 * @return CellId.
 *
 * @see @ref Mtc_CliDbSetCellId
 */
ZFUNC ZCHAR * Mtc_CliDbGetCellId();

/**
 * @brief mtc set CellId.
 *
 * @param [in] pcCellId CellId.
 *
 * @retval ZOK Set CellId successfully.
 * @retval ZFAILED Set CellId failed.
 *
 * @see @ref Mtc_CliDbGetCellId
 *
 */
ZFUNC ZINT Mtc_CliDbSetCellId(ZCHAR *pcCellId);

/**
 * @brief Get Company.
 *
 * @return Company.
 *
 * @see @ref Mtc_CliDbSetCompany
 *
 */
ZFUNC ZCHAR * Mtc_CliDbGetCompany(ZFUNC_VOID);

/**
 * @brief Set Company. 
 *
 * @param [in] Company.
 *
 * @retval ZOK Set Company successfully.
 * @retval ZFAILED Set Company failed.
 *
 * @see @ref Mtc_CliDbGetCompany
 *
 */
ZFUNC ZINT Mtc_CliDbSetCompany(ZCHAR *pcCompany);

/**
 * @brief Get cmcc group support flag.
 *
 * @retval ZTRUE cmcc group is supported.
 * @retval ZFALSE cmcc group is not supported.
 *
 * @see @ref Mtc_CliDbSetCmccGrpSupt
 */
ZFUNC ZBOOL Mtc_CliDbGetCmccGrpSupt();

/**
 * @brief Set cmcc group support flag.
 *
 * @param [in] bSupt The support flag.
 *
 * @retval ZOK Set cmcc group support flag successfully.
 * @retval ZFAILED Set cmcc group support flag failed.
 *
 * @see @ref Mtc_CliDbGetCmccGrpSupt
 */
ZFUNC ZINT Mtc_CliDbSetCmccGrpSupt(ZBOOL bSupt);

/* mtc db get register timer 1 */
ZFUNC ZUINT Mtc_CliDbGetRegTmr1(ZFUNC_VOID);

/* mtc db set register timer 1 */
ZFUNC ZINT Mtc_CliDbSetRegTmr1(ZUINT iTimeLen);

/* mtc db get register timer 2 */
ZFUNC ZUINT Mtc_CliDbGetRegTmr2(ZFUNC_VOID);

/* mtc db set register timer 2 */
ZFUNC ZINT Mtc_CliDbSetRegTmr2(ZUINT iTimeLen);

/**
 * @brief Get reg use local ip enable flag(default ZTRUE).
 *
 * @return reg use local ip enable.
 *
 * @see @ref Mtc_CliDbSetRegUseLclIp
 *
 */
ZFUNC ZBOOL Mtc_CliDbGetRegUseLclIp();

/**
 * @brief Set  reg use local ip enable flag. 
 *
 * @param [in] bEnable reg use local ip enable.
 *
 *
 * @retval ZOK Set reg use local ip enablesuccessfully.
 * @retval ZFAILED Set reg use local ip enable failed.
 *
 * @see @ref Mtc_CliDbGetRegUseLclIp
 *
 */
ZFUNC ZINT Mtc_CliDbSetRegUseLclIp(ZBOOL bEnable);

/**
 * @brief get http proxy type.
 *
 * @return http proxy type, @see @ref EN_MTC_HTTP_PROXY_TYPE.
 *
 * @see Mtc_CliDbSetHttpProxyType
 */
ZFUNC ZUINT Mtc_CliDbGetHttpProxyType(ZFUNC_VOID);

/*
* @brief set http proxy type.
*
* @param [in] iProxyType http proxy type, @see @ref EN_MTC_HTTP_PROXY_TYPE.
*
* @retval ZOK Set http proxy type successfully.
* @retval ZFAILED Set http proxy type failed.
*
* @see Mtc_CliDbGetHttpProxyType
*/
ZFUNC ZINT Mtc_CliDbSetHttpProxyType(ZUINT iProxyType);

/* 
 * @brief get http proxy server address.
 *
 * @return http proxy server address.
 *
 * @see Mtc_CliDbSetHttpProxySrvAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetHttpProxySrvAddr(ZFUNC_VOID);

/*
* @brief set http proxy server address.
*
* @param [in] pcSrvAddr http proxy server address.
*
* @retval ZOK Set http proxy server address successfully.
* @retval ZFAILED Set http proxy server address failed.
*
* @see Mtc_CliDbGetHttpProxySrvAddr
*/
ZFUNC ZINT Mtc_CliDbSetHttpProxySrvAddr(ZCHAR *pcSrvAddr);

/* 
 * @brief get http proxy server port.
 *
 * @return http proxy server port.
 *
 * @see Mtc_CliDbSetHttpProxySrvPort
 */
ZFUNC ZSHORT Mtc_CliDbGetHttpProxySrvPort(ZFUNC_VOID);

/*
* @brief set http proxy server port.
*
* @param [in] wProxyPort http proxy server port.
*
* @retval ZOK Set http proxy server port successfully.
* @retval ZFAILED Set http proxy server port failed.
*
* @see Mtc_CliDbGetHttpProxySrvPort
*/
ZFUNC ZINT Mtc_CliDbSetHttpProxySrvPort(ZUSHORT wProxyPort);

/**
 * @brief Get group manage http server address.
 *
 * @return group manage http server address.
 *
 * @see @ref Mtc_CliDbSetGrpHttpServAddr
 */
ZFUNC ZCHAR * Mtc_CliDbGetGrpHttpServAddr(ZFUNC_VOID);

/**
 * @brief Set group manage http server address.
 *
 * @param [in] pcServAddr The server address.
 *
 * @retval ZOK Set server address successfully.
 * @retval ZFAILED Set server address failed.
 *
 * @see @ref Mtc_CliDbGetGrpHttpServAddr
 */
ZFUNC ZINT Mtc_CliDbSetGrpHttpServAddr(ZCHAR *pcServAddr);

/**
 * @brief Get group manage http server port.
 *
 * @return group manage http server port.
 *
 * @see @ref Mtc_CliDbSetGrpHttpServPort
 */
ZFUNC ZUSHORT Mtc_CliDbGetGrpHttpServPort(ZFUNC_VOID);

/**
 * @brief Set group manage http server port.
 *
 * @param [in] wPort The server port.
 *
 * @retval ZOK Set server port successfully.
 * @retval ZFAILED Set server port failed.
 *
 * @see @ref Mtc_CliDbGetGrpHttpServPort
 */
ZFUNC ZINT Mtc_CliDbSetGrpHttpServPort(ZUSHORT wPort);

/**
 * @brief Get group manage http authorization name.
 *
 * @return group manage http authorization name.
 *
 * @see @ref Mtc_CliDbSetGrpHttpAuthName
 */
ZFUNC ZCHAR * Mtc_CliDbGetGrpHttpAuthName(ZFUNC_VOID);

/**
 * @brief Set group manage htt authorization name.
 *
 * @param [in] pcAuthName The authorization name.
 *
 * @retval ZOK Set authorization name successfully.
 * @retval ZFAILED Set authorization name failed.
 *
 * @see @ref Mtc_CliDbGetGrpHttpAuthName
 */
ZFUNC ZINT Mtc_CliDbSetGrpHttpAuthName(ZCHAR *pcAuthName);

/**
 * @brief Get use sip pwd from dm flag.
 *
 * @return use sip pwd from dm.
 *
 */
ZFUNC ZBOOL Mtc_CliDbGetUseDmPwd(ZFUNC_VOID);

/**
 * @brief set use sip pwd from dm flag.
 *
 * @return use sip pwd from dm.
 *
 */
ZFUNC ZUINT Mtc_CliDbSetUseDmPwd(ZBOOL bUse);

/**
 * @brief Get min heart beat timer length on ps, in seconds.
 *
 * @retval The min length of heart beat timer on ps, default is 30 seconds.
 *
 * @see @ref Mtc_CliDbSetMinHeartbeatTime
 */
ZFUNC ZUINT Mtc_CliDbGetMinHeartbeatTime();

/**
 * @brief Set min heart beat timer length on ps, in seconds.
 *
 * @param [in] iTmrLen The min heart beat timer length on ps.
 *
 * @retval ZOK Set min heart beat timer length on ps successfully.
 * @retval ZFAILED Set min heart beat timer length on ps failed.
 *
 * @see @ref Mtc_CliDbGetMinHeartbeatTime
 */
ZFUNC ZINT Mtc_CliDbSetMinHeartbeatTime(ZUINT iTmrLen);

/**
 * @brief Get min heart beat timer length on wifi, in seconds.
 *
 * @retval The min length of heart beat timer on wifi, default is 30 seconds.
 *
 * @see @ref Mtc_CliDbSetWifiMinHeartbeatTime
 */
ZFUNC ZUINT Mtc_CliDbGetWifiMinHeartbeatTime();

/**
 * @brief Set min heart beat timer length on wifi, in seconds.
 *
 * @param [in] iTmrLen The min heart beat timer length on wifi.
 *
 * @retval ZOK Set min heart beat timer length on wifi successfully.
 * @retval ZFAILED Set min heart beat timer length on wifi failed.
 *
 * @see @ref Mtc_CliDbGetWifiMinHeartbeatTime
 */
ZFUNC ZINT Mtc_CliDbSetWifiMinHeartbeatTime(ZUINT iTmrLen);

/**
 * @brief Get max heart beat timer length on ps, in seconds.
 *
 * @retval The max length of heart beat timer on ps, default is 30 seconds.
 *
 * @see @ref Mtc_CliDbSetMaxHeartbeatTime
 */
ZFUNC ZUINT Mtc_CliDbGetMaxHeartbeatTime();

/**
 * @brief Set max heart beat timer length on ps, in seconds.
 *
 * @param [in] iTmrLen The max heart beat timer length on ps.
 *
 * @retval ZOK Set max heart beat timer length on ps successfully.
 * @retval ZFAILED Set max heart beat timer length on ps failed.
 *
 * @see @ref Mtc_CliDbGetMaxHeartbeatTime
 */
ZFUNC ZINT Mtc_CliDbSetMaxHeartbeatTime(ZUINT iTmrLen);

/**
 * @brief Get max heart beat timer length on wifi, in seconds.
 *
 * @retval The max length of heart beat timer on wifi, default is 30 seconds.
 *
 * @see @ref Mtc_CliDbSetWifiMaxHeartbeatTime
 */
ZFUNC ZUINT Mtc_CliDbGetWifiMaxHeartbeatTime();

/**
 * @brief Set max heart beat timer length on wifi, in seconds.
 *
 * @param [in] iTmrLen The max heart beat timer length on wifi.
 *
 * @retval ZOK Set max heart beat timer length on wifi successfully.
 * @retval ZFAILED Set max heart beat timer length on wifi failed.
 *
 * @see @ref Mtc_CliDbGetWifiMaxHeartbeatTime
 */
ZFUNC ZINT Mtc_CliDbSetWifiMaxHeartbeatTime(ZUINT iTmrLen);

/**
 * @brief Get heart beat time step length on ps, in seconds.
 *
 * @retval The length of heart beat time step on ps, default is 300 seconds.
 *
 * @see @ref Mtc_CliDbSetHeartbeatStepLen
 */
ZFUNC ZUINT Mtc_CliDbGetHeartbeatStepLen();

/**
 * @brief Set heart beat time step length on ps, in seconds.
 *
 * @param [in] iTmrLen The heart beat time step length on ps.
 *
 * @retval ZOK Set heart beat time step length on ps successfully.
 * @retval ZFAILED Set heart beat time step length on ps failed.
 *
 * @see @ref Mtc_CliDbGetHeartbeatStepLen
 */
ZFUNC ZINT Mtc_CliDbSetHeartbeatStepLen(ZUINT iTmrLen);

/**
 * @brief Get contact address update option.
 *
 * @retval ZTRUE Update contact address by VIA header.
 * @retval ZFALSE Do not update contact address by VIA header.
 *
 * @see @ref Mtc_CliDbSetContactAddrUpdt
 */
ZFUNC ZBOOL Mtc_CliDbGetContactAddrUpdt(ZFUNC_VOID);

/**
 * @brief Set contact address update option.
 *
 * @param [in] bEnable If ZTRUE, update contact address by VIA header.
 * Otherwise not update.
 *
 * @retval ZOK Set update contact address by VIA header option successfully.
 * @retval ZFAILED Set update contact address by VIA header option failed.
 *
 * @see @ref Mtc_CliDbGetContactAddrUpdt
 */
ZFUNC ZINT Mtc_CliDbSetContactAddrUpdt(ZBOOL bEnable);

/**
 * @brief Get contact uri ob parameter option.
 *
 * @retval ZTRUE Add contact uri ob parameter.
 * @retval ZFALSE Do not add contact uri ob parameter.
 *
 * @see @ref Mtc_CliDbSetContactUriObParm
 */
ZFUNC ZBOOL Mtc_CliDbGetContactUriObParm(ZFUNC_VOID);

/**
 * @brief Set contact uri ob parameter option.
 *
 * @param [in] bEnable If ZTRUE, add contact uri ob parameter.
 * Otherwise not add.
 *
 * @retval ZOK Set add contact uri ob parameter option successfully.
 * @retval ZFAILED Set add contact uri ob parameter optio failed.
 *
 * @see @ref Mtc_CliDbGetContactUriObParm
 */
ZFUNC ZINT Mtc_CliDbSetContactUriObParm(ZBOOL bEnable);

#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_CLI_DB_H__ */

