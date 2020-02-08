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
  File name     : mtc_partp.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC participant

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PARTP_H__
#define _MTC_PARTP_H__

/**
 * @file mtc_partp.h
 * @brief MTC Participant Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC participant list type */
typedef enum EN_MTC_PARTP_LST_TYPE
{
    EN_MTC_PARTP_LST_ONE,           /**< @brief one participant */
    EN_MTC_PARTP_LST_PREDEF_GRP,    /**< @brief pre-defined group participants */
    EN_MTC_PARTP_LST_URI_LST        /**< @brief URI list participants */
} EN_MTC_PARTP_LST_TYPE;

/** @brief MTC participant status type */
typedef enum EN_MTC_PARTP_STAT_TYPE
{
    EN_MTC_PARTP_STAT_PENDING,       /**< @brief pending */
    EN_MTC_PARTP_STAT_ACTIVE,        /**< @brief active */
    EN_MTC_PARTP_STAT_INACITVE,      /**< @brief inacitve */
    EN_MTC_PARTP_STAT_DEPARTED,      /**< @brief departed */
    EN_MTC_PARTP_STAT_BOOTED,        /**< @brief booted */
    EN_MTC_PARTP_STAT_FAILED,        /**< @brief failed */
    EN_MTC_PARTP_STAT_DELETED        /**< @brief deleted */
} EN_MTC_PARTP_STAT_TYPE;

/* @brief Type of MTC cmcc conference participant state type */
typedef enum EN_MTC_CMCC_CONF_PARTP_STATE_TYPE
{
    EN_MTC_CMCC_CONF_PARTP_STATE_PENDING,    /**<@brief Conference participant pending. */
    EN_MTC_CMCC_CONF_PARTP_STATE_INITIAL,    /**<@brief Conference participant initial. */
    EN_MTC_CMCC_CONF_PARTP_STATE_CONNECTING, /**<@brief Conference participant connecting. */
    EN_MTC_CMCC_CONF_PARTP_STATE_RINGING,    /**<@brief Conference participant ringing. */
    EN_MTC_CMCC_CONF_PARTP_STATE_DIALINGIN,  /**<@brief Conference participant dialing in. */
    EN_MTC_CMCC_CONF_PARTP_STATE_DIALINGOUT, /**<@brief Conference participant dialing out. */
    EN_MTC_CMCC_CONF_PARTP_STATE_ALERTING,   /**<@brief Conference participant alerting. */
    EN_MTC_CMCC_CONF_PARTP_STATE_CONNED,     /**<@brief Conference participant connected. */ 
    EN_MTC_CMCC_CONF_PARTP_STATE_ONHOLD,     /**<@brief Conference participant onhold. */
    EN_MTC_CMCC_CONF_PARTP_STATE_DISCING,    /**<@brief Conference participant disconnecting. */
    EN_MTC_CMCC_CONF_PARTP_STATE_DISCED,     /**<@brief Conference participant disconnected
                                                                                        (not normal termed the call) */
    EN_MTC_CMCC_CONF_PARTP_STATE_MUTED,      /**<@brief Conference participant muted. */
    EN_MTC_CMCC_CONF_PARTP_STATE_USER_NOT_AVAILABLE, /**<@brief Conference participant user not available. */
    EN_MTC_CMCC_CONF_PARTP_STATE_NOANSWER,        /**<@brief Conference participant user no answer. */
    EN_MTC_CMCC_CONF_PARTP_STATE_BUSY,            /**<@brief Conference participant busy. */
    EN_MTC_CMCC_CONF_PARTP_STATE_NOT_REACHABLE,   /**<@brief Conference participant user not reachable. */
    EN_MTC_CMCC_CONF_PARTP_STATE_ROUTE_FAILED,    /**<@brief Conference participant routing failure. */
    EN_MTC_CMCC_CONF_PARTP_STATE_UNAVAILABLE,     /**<@brief Conference participant unavailable. */
    EN_MTC_CMCC_CONF_PARTP_STATE_GENERAL_FAILURE, /**<@brief Conference participant general failure. */
    EN_MTC_CMCC_CONF_PARTP_STATE_TIMER_EXPIRED,   /**<@brief Conference participant timer expired. */
    EN_MTC_CMCC_CONF_PARTP_STATE_DELETED,         /**<@brief Conference participant deleted. */
    EN_MTC_CMCC_CONF_PARTP_STATE_FORBIDDEN,       /**<@brief Conference participant forbidden. */
    EN_MTC_CMCC_CONF_PARTP_STATE_HANG_UP,         /**<@brief Conference participant hangup
                                                                                         (normal termed the call). */
    EN_MTC_CMCC_CONF_PARTP_STATE_UNKNOWN          /**<@brief Conference participant unknown state. */ 
} EN_MTC_CMCC_CONF_PARTP_STATE_TYPE;

/** @brief MTC participant composing status type */
typedef enum EN_MTC_PARTP_ISCOMP_STAT_TYPE
{
    EN_MTC_PARTP_ISCOMP_STAT_UNKNOWN, /**< @brief composing unknown state */
    EN_MTC_PARTP_ISCOMP_STAT_IDLE,   /**< @brief composing idle state */
    EN_MTC_PARTP_ISCOMP_STAT_ACTIVE  /**< @brief composing active state */
} EN_MTC_PARTP_ISCOMP_STAT_TYPE;

/** @brief MTC participant roles type */
typedef enum EN_MTC_PARTP_ROLES_TYPE
{
    EN_MTC_PARTP_ROLES_UNKNOWN,      /**< @brief unknown roles */
    EN_MTC_PARTP_ROLES_CHAIRMAN,     /**< @brief chairman roles */
    EN_MTC_PARTP_ROLES_PARTP,        /**< @brief participant roles */
} EN_MTC_PARTP_ROLES_TYPE;

/** @brief MTC participant etype type */
typedef enum EN_MTC_PARTP_ETYPE_TYPE
{
    EN_MTC_PARTP_ETYPE_UNKNOWN,      /**< @brief unknown type */
    EN_MTC_PARTP_ETYPE_GPMANAGE,     /**< @brief gpmanage type */
} EN_MTC_PARTP_ETYPE_TYPE;

/** @brief MTC participant video stream state */
typedef enum EN_MTC_PARTP_VIDEO_STRM_STATE
{
    EN_MTC_PARTP_VIDEO_STRM_STATE_DISABLE,    /**< @brief video stream disable state */
    EN_MTC_PARTP_VIDEO_STRM_STATE_ENABLE,     /**< @brief video stream  enable state */
} EN_MTC_PARTP_VIDEO_STRM_STATE;

/** @brief MTC participant access network type */
typedef enum EN_MTC_PARTP_ACC_NET_TYPE
{
    EN_MTC_PARTP_ACC_NET_OTHER,     /**< @brief other access network type */
    EN_MTC_PARTP_ACC_NET_APP,       /**< @brief APP access network type */
    EN_MTC_PARTP_ACC_NET_VOLTE,     /**< @brief VOLTE access network type */
    EN_MTC_PARTP_ACC_NET_CS         /**< @brief CS access network type */
} EN_MTC_PARTP_ACC_NET_TYPE;

/** @brief MTC participant status fail reason */
typedef enum EN_MTC_PARTP_FAILED_REASON
{
    EN_MTC_PARTP_FAILED_NO,               /**< @brief no reason */
    EN_MTC_PARTP_FAILED_NOT_MEMBER,       /**< @brief not a member of the enterprise */
} EN_MTC_PARTP_FAILED_REASON;

/**
 * @brief Create a participant list.
 *
 * @param [in] iType The type for participant, see @ref EN_MTC_PARTP_LST_TYPE.
 *
 * @return The list id when create a participant list successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PartpLstCreate(ZUINT iType);

/**
 * @brief Delete a participant list.
 *
 * @param [in] iLstId The list id for participants.
 *
 */
ZFUNC ZVOID Mtc_PartpLstDelete(ZUINT iLstId);

/**
 * @brief Clone a participant list.
 *
 * @param [in] iLstId The list id for participants.
 *
 * @return The new list id when copy a participant list successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PartpLstClone(ZUINT iLstId);

/**
 * @brief Get participant list type.
 *
 * @param [in] iLstId The list id for participants.
 *
 * @return Participant list type, see @ref EN_MTC_PARTP_LST_TYPE.
 */
ZFUNC ZUINT Mtc_PartpLstGetType(ZUINT iLstId);

/**
 * @brief Set participant list type.
 *
 * @param [in] iLstId The list id for participants.
 * @param [in] iType The type for participant, see @ref EN_MTC_PARTP_LST_TYPE.
 *
 * @retval ZOK Set participant list type successfully.
 * @retval ZFAILED Set participant list type failed.
 */
ZFUNC ZINT Mtc_PartpLstSetType(ZUINT iLstId, ZUINT iType);

/**
 * @brief Get participant list size.
 *
 * @param [in] iLstId The list id for participants.
 *
 * @return Participant list size.
 */
ZFUNC ZINT Mtc_PartpLstGetSize(ZUINT iLstId);

/**
 * @brief Get a participant from participant list.
 *
 * @param [in] iLstId The list id for participants.
 * @param [in] iIndex The index of participant.
 * @param [out] ppcName The participant name.
 * @param [out] ppcUri The participant URI.
 * @param [out] piPartpId The participant id.
 * 
 * The caller must copy *ppcName and *ppcUri, then use.
 *
 * @retval ZOK Get a participant successfully.
 * @retval ZFAILED Get a participant failed.
 */
ZFUNC ZINT Mtc_PartpLstGetPartp(ZUINT iLstId, ZINT iIndex,
                ZCHAR **ppcName, ZCHAR **ppcUri, ZUINT *piPartpId);

/**
 * @brief Add a participant into participant list.
 *
 * @param [in] iLstId The list id for participants.
 * @param [in] pcName The participant name.
 * @param [in] pcUri The participant URI.
 *
 * @retval The participant id when add a participant successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PartpLstAddPartp(ZUINT iLstId, ZCHAR *pcName, 
                ZCHAR *pcUri);

/**
 * @brief Remove a participant from participant list.
 *
 * @param [in] iLstId The list id for participants.
 * @param [in] iPartpId The participant id.
 *
 * @retval ZOK Remove a participant successfully.
 * @retval ZFAILED Remove a participant failed.
 */
ZFUNC ZINT Mtc_PartpLstRmvPartp(ZUINT iLstId, ZUINT iPartpId);

/**
 * @brief Find a participant in participant list.
 *
 * @param [in] iLstId The list id for participants.
 * @param [in] pcUri The participant URI.
 *
 * @return The participant id if exist the participant, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PartpLstFindPartp(ZUINT iLstId, ZCHAR *pcUri);

/**
 * @brief Get a participant name from participant list.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The participant name string when get a participant name successfully, 
 *              otherwise return empty string.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PartpGetName(ZUINT iPartpId);

/**
 * @brief Get a participant URI from participant.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The participant URI string when get participant URI successfully, 
 *              otherwise return empty string.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_PartpGetUri(ZUINT iPartpId);

/**
 * @brief Get a participant status by participant id.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The participant status, see @ref EN_MTC_CMCC_CONF_PARTP_STATE_TYPE.
 */
ZFUNC ZUINT Mtc_PartpGetStat(ZUINT iPartpId);

/**
 * @brief Get a participant video stream id by participant id.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The participant video stream id.
 */
ZFUNC ZUINT Mtc_PartpGetVideoStrmId(ZUINT iPartpId);

/**
 * @brief Get a participant video stream state by participant id.
 *
 * @param [in] iPartpId The participant state, see @ref EN_MTC_PARTP_VIDEO_STRM_STATE.
 *
 * @return The participant video stream state.
 */
ZFUNC ZUINT Mtc_PartpGetVideoStrmState(ZUINT iPartpId);

/**
 * @brief Get a cmccc conf participant status from participant list.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The cmcc conf participant status, see @ref EN_MTC_CMCC_CONF_PARTP_STATE_TYPE.
 */
ZFUNC ZUINT Mtc_PartpGetCmccConfStat(ZUINT iPartpId);

/**
 * @brief Get a participant roles from participant list.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The participant roles, see @ref EN_MTC_PARTP_ROLES_TYPE.
 */
ZFUNC ZUINT Mtc_PartpGetRoles(ZUINT iPartpId);

/**
 * @brief Get a participant etype.
 * @param [in] iPartpId The participant id.
 *
 * @return The participant etype, see @ref EN_MTC_PARTP_ETYPE_TYPE.
 */
ZFUNC ZUINT Mtc_PartpGetEtype(ZUINT iPartpId);

/**
 * @brief Get a participant user level.
 * @param [in] iPartpId The participant id.
 *
 * @return The participant user level.
 */
ZFUNC ZUINT Mtc_PartpGetUserLevel(ZUINT iPartpId);

/**
 * @brief Get a participant failed reason.
 * @param [in] iPartpId The participant id.
 *
 * @return The participant failed reason, see @ref EN_MTC_PARTP_FAILED_REASON.
 */
ZFUNC ZUINT Mtc_PartpGetReason(ZUINT iPartpId);

/**
 * @brief Get a participant composing status.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The participant composing status, see @ref EN_MTC_PARTP_ISCOMP_STAT_TYPE.
 */
ZFUNC ZUCHAR Mtc_PartpGetCompsStat(ZUINT iPartpId);

/**
 * @brief Get a participant session id from participant list.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The participant session id.
 */
ZFUNC ZUINT Mtc_PartpGetSessId(ZUINT iPartpId);

/**
 * @brief Set a participant session id.
 *
 * @param [in] iPartpId The participant id.
 * @param [in] iSessId The participant session id.
 *
 * @retval ZOK Set a participant session id successfully.
 * @retval ZFAILED Set a participant session id failed.
 */
ZFUNC ZINT Mtc_PartpSetSessId(ZUINT iPartpId, ZUINT iSessId);

/**
 * @brief Get a participant log id.
 *
 * @param [in] iPartpId The participant id.
 *
 * @return The participant log id.
 */
ZFUNC ZUINT Mtc_PartpGetLogId(ZUINT iPartpId);
    
/**
 * @brief Set a participant log id.
 *
 * @param [in] iPartpId The participant id.
 * @param [in] iLogId The participant log id.
 *
 * @retval ZOK Set a participant log id successfully.
 * @retval ZFAILED Set a participant log id failed.
 */
ZFUNC ZINT Mtc_PartpSetLogId(ZUINT iPartpId, ZUINT iLogId);

/**
 * @brief Get a participant access network type from participant id.
 *
 * @param [in] iPartpId The participant id.
 *
 * @retval The participant access network type, see @ref EN_MTC_PARTP_ACC_NET_TYPE.
 */
ZFUNC ZUINT Mtc_PartpGetAccNetType(ZUINT iPartpId);

/**
* @brief Get a participant selected flag from participant id.
*
* @param [in] iPartpId The participant id.
*
* @retval The participant selected flag(true or false).
*/
ZFUNC ZBOOL Mtc_PartpGetSelected(ZUINT iPartpId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PARTP_H__ */

