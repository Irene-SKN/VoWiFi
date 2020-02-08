/************************************************************************

        Copyright (c) 2005-2016 by Juphoon System Software, Inc.
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
  File name     : mtc_im_cmcc.h
  Module        : multimedia talk client
  Author        : anthouny.zhou
  Created on    : 2016-02-14
  Description   :
      Data structure and function declare required by MTC IM in CMCC model

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_CMCC_H__
#define _MTC_IM_CMCC_H__

/**
 * @file mtc_im_cmcc.h
 * @brief MTC Instant Messaging Interface Functions In CMCC Model
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC IM cmcc group type */
typedef enum EN_MTC_IM_CMCC_IVT_TYPE
{
    EN_MTC_IM_CMCCGRP_IVT_ONLINE_CREATE,       /**< @brief online create invitation */
    EN_MTC_IM_CMCCGRP_IVT_ACTIVATE,            /**< @brief activate invitation */
    EN_MTC_IM_CMCCGRP_IVT_OFFLINE_CREATE,      /**< @brief offline create invitation */    
} EN_MTC_IM_CMCC_IVT_TYPE;

/** @brief MTC IM page message content type */
typedef enum EN_MTC_CMCCGRP_PMSG_CTYPE
{   
    EN_MTC_CMCCGRP_PMSG_CONT_UNKNOWN,        /**< @brief unknown content */
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_TXT_PLAIN,  /**< @brief content type of "text/plain" wrapt by cpim */
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_VEMOTICON,  /**< @brief content type of "application/vemoticon+xml" wrapt by cpim */
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_CLOUD_FILE, /**< @brief content type of "application/cloudfile+xml" wrapt by cpim */
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_CMRED_BAG,  /**< @brief content type of "application/cmredbag+xml" wrapt by cpim */
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_CARD,       /**< @brief content type of "application/card+xml" wrapt by cpim */
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_COM_TEMP,   /**< @brief content type of "application/commontemplate+xml" wrapt by cpim */
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_REVOKE,     /**< @brief content type of "application/vnd.gsma.rcsrevoke+xml" wrapt by cpim */
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_CHRED_BAG,  /**< @brief content type of "application/chredbag+xml" wrapt by cpim */    
    EN_MTC_CMCCGRP_PMSG_CONT_MSG_GRP_DATA,       /**< @brief content type of "application/vnd.oma.cpm-groupdata+xml" wrapt by cpim */
} EN_MTC_CMCCGRP_PMSG_CTYPE;

/** @brief MTC IM page message At type */
typedef enum EN_MTC_CMCCGRP_PMSG_AT_TYPE
{
    EN_MTC_CMCCGRP_PMSG_AT_PARTIAL,          /**< @brief user @ some members  in the group */
    EN_MTC_CMCCGRP_PMSG_AT_ALL,              /**< @brief user @ all members in the group */
    EN_MTC_CMCCGRP_PMSG_AT_NONE,             /**< @brief user @ no body in the group */
} EN_MTC_CMCCGRP_PMSG_AT_TYPE;

/** @brief MTC IM page message imdn type */
typedef enum EN_MTC_CMCCGRP_PMSG_IMDN_TYPE
{
    EN_MTC_CMCCGRP_PMSG_IMDN_UNKNOWN,        /**< @brief display notification unknown imdn */
    EN_MTC_CMCCGRP_PMSG_IMDN_REG,            /**< @brief regular message */
    EN_MTC_CMCCGRP_PMSG_IMDN_DELI,           /**< @brief message with delivery notification request */
    EN_MTC_CMCCGRP_PMSG_IMDN_DISP,           /**< @brief message with display notification request */
    EN_MTC_CMCCGRP_PMSG_IMDN_BOTH,           /**< @brief message with delivery & display notification request */
    EN_MTC_CMCCGRP_PMSG_IMDN_BURN            /**< @brief message with burn after reading notification request */
} EN_MTC_CMCCGRP_PMSG_IMDN_ITYPE;

/* mmf groupdata type */
typedef enum EN_MTC_GROUP_DATA_TYPE
{
    EN_MTC_GROUP_DATA_NONE,                /* none */
    EN_MTC_GROUP_DATA_SUBJECT,             /* subject */
    EN_MTC_GROUP_DATA_CHAIRMAN,            /* chair man*/
} EN_MTC_GROUP_DATA_TYPE;

/* mmf group manage type */
typedef enum EN_MTC_CMCCGRP_MAN_RESULT
{
    EN_MTC_CMCCGRP_MAN_NONE,                /* none */
    EN_MTC_CMCCGRP_MAN_OK,                  /* group manage set ok */
    EN_MTC_CMCCGRP_MAN_FAIL,                /* group manage set fail */
} EN_MTC_CMCCGRP_MAN_RESULT;

/**
 * @brief Creating cmcc group(ad-hoc) with URI-List.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The group subject.
 * @param [in] pcDispName The own display name in the cmcc group.
 * @param [in] iPartpLstId The participant list id.
 *
 * @return The (cmcc group) session id when send creat invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpCreat(ZCOOKIE zCookie, ZCHAR *pcSubject,
                ZCHAR *pcDispName, ZUINT iPartpLstId);

/**
 * @brief Accept a cmcc group invitation.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in] pcDispName The own display name in the group chat.
 *
 * @retval ZOK Accept cmcc group successfully.
 * @retval ZFAILED Accept cmcc group failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpAccept(ZUINT iSessId, ZCHAR *pcDispName);

/**
 * @brief Reject a cmcc group invitation.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @retval ZOK Reject cmcc group successfully.
 * @retval ZFAILED Reject cmcc group failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpReject(ZUINT iSessId);

/**
 * @brief Cancel a cmcc group in creating.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @retval ZOK Canceling cmcc group successfully.
 * @retval ZFAILED Canceling cmcc group failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpCancel(ZUINT iSessId);

/**
 * @brief Rejoin a cmcc group.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The group subject.
 * @param [in] pcDispName The own display name in group chat.
 * @param [in] pcGroupChatId The group chat id.
 * @param [in] pcGrpIdentity The focus Group Identity.
 * @param [in] iVersionId The group chat version.
 *
 * @return The rejoin group session id when send cmcc group invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpReJoin(ZCOOKIE zCookie, ZCHAR *pcSubject,
                ZCHAR *pcDispName, ZCHAR *pcGroupChatId, ZCHAR *pcGrpIdentity,
                ZUINT iVersionId);

/**
 * @brief Silencing a cmcc group chat.
 *
 * The method should be used when creat or join a cmcc group successfully, by
 * @ref Mtc_ImCbSetCmccGrpAcpted.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @retval ZOK Silencing cmcc group successfully.
 * @retval ZFAILED Silencing cmcc group failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpSilence(ZUINT iSessId);

/**
 * @brief Leaving a cmcc group chat.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetCmccGrpLeaveOk or @ref Mtc_ImCbSetCmccGrpLeaveFailed.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @retval ZOK Leaving cmcc group successfully.
 * @retval ZFAILED Leaving cmcc group failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpLeave(ZUINT iSessId);

/**
 * @brief Dissolve a cmcc group chat.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetCmccGrpDissolveOk or @ref Mtc_ImCbSetCmccGrpDissolveFailed.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @retval ZOK Dissolve cmcc group chat successfully.
 * @retval ZFAILED Dissolve cmcc group chat failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpDissolve(ZUINT iSessId);

/**
 * @brief Adding one user to a cmcc group chat.
 *
 * If IM add successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpPartpAddOk.
 *
 * If IM add failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpPartpAddFailed.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in] pcUri The participant URI.
 *
 * @return The refer id when send add partp invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpAddPartp(ZCHAR *pcGrpIdent, 
                ZCHAR *pcGrpChatId, ZCHAR *pcUri);

/**
 * @brief Adding multi-users to a cmcc group chat.
 *
 * If IM add successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpPartpAddOk.
 *
 * If IM add failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpPartpAddFailed.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in] iPartpLstId The participant list id.
 *
 * @return The refer id when send add partp invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpAddPartpU(ZCHAR *pcGrpIdent, 
                ZCHAR *pcGrpChatId, ZUINT iPartpLstId);

/**
 * @brief Expelling one user from a cmcc group chat.
 *
 * If IM expel successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpPartpEplOk.
 *
 * If IM expel failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpPartpEplFailed.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in] pcUri The participant URI.
 *
 * @return The refer id when send epl partp invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpEplPartp(ZCHAR *pcGrpIdent, 
                ZCHAR *pcGrpChatId, ZCHAR *pcUri);

/**
 * @brief Expelling muti-user from a cmcc group chat.
 *
 * If IM expel successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpPartpEplOk.
 *
 * If IM expel failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpPartpEplFailed.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in] iPartpLstId The participant list id.
 *
 * @return The refer id when send epl partp invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpEplPartpU(ZCHAR *pcGrpIdent, 
                ZCHAR *pcGrpChatId, ZUINT iPartpLstId);

/**
 * @brief Modify a cmcc group chat chairman.
 *
 * If IM expel successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpChairManMdfyOk.
 *
 * If IM expel failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpChairManMdfyFailed.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in] pcUri The Uri of new chairman.
 *
 * @return The refer id when send modify chairman invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpMdfyChairMan(ZCHAR *pcGrpIdent, 
                ZCHAR *pcGrpChatId, ZCHAR *pcChairMan);

/**
 * @brief Modify own display name in a cmcc group chat.
 *
 * If IM expel successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpDispNameMdfyOk.
 *
 * If IM expel failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetCmccGrpDispNameMdfyFailed.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in] pcDispName The own new display name in group chat.
 *
 * @return The refer id when send modify dispname invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpMdfyDispName(ZCHAR *pcGrpIdent, 
                ZCHAR *pcGrpChatId, ZCHAR *pcDispName);

/**
 * @brief MTC Get group chat identity from message refer.
 *
 * @param [in] iRferId The refer id.
 *
 * @return The group chat identity.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpRferGetGrpIdent(ZUINT iRferId);

/**
 * @brief MTC Get group chat id from message refer.
 *
 * @param [in] iRferId The refer id.
 *
 * @return The group chat id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpRferGetGrpChatId(ZUINT iRferId);

/**
 * @brief Get participant list id.
 *
 * The participant list id is all remote clients who are added or epled group.
 *
 * @param [in] iRferId The refer id.
 *
 * @return The participant list id on succeed or 0 on failed.
 *
 *  The caller is responsible for freeing it by @ref Mtc_PartpLstDelete.
 */
ZFUNC ZUINT Mtc_ImCmccGrpRferGetPartpLstId(ZUINT iRferId);

/**
 * @brief Get the modify chair man from message refer.
 *
 * @param [in] iRferId The refer id.
 *
 * @return The modify chair man.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpRferGetChairMan(ZUINT iRferId);

/**
 * @brief Get the modify display name from message refer.
 *
 * @param [in] iRferId The refer id.
 *
 * @return The modify display name.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpRferGetDispName(ZUINT iRferId);

/**
 * @brief Get user cookie from cmcc group.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImCmccGrpGetCookie(ZUINT iSessId);

/**
 * @brief Set user cookie in a cmcc group.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in] zCookie The user cookie of cmcc group.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpSetCookie(ZUINT iSessId, ZCOOKIE zCookie);

/* mtc get cmcc group chat invite type */
/**
 * @brief MTC cmcc group get invite type.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @return invite type, @see @ref EN_MTC_IM_CMCC_IVT_TYPE.
 */
ZFUNC ZUINT Mtc_ImCmccGrpGetIvtType(ZUINT iSessId);

/**
 * @brief Get subject from cmcc group.
 *
 * @param [in] iSessId cmcc group The session id.
 *
 * @return cmcc group subject.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpGetSubject(ZUINT iSessId);

/**
 * @brief Get user display name from cmcc group.
 *
 * @param [in] iSessId The session id.
 *
 * @return User display name.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpGetDispName(ZUINT iSessId);

/**
 * @brief Get group Identity(group uri) from cmcc group.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @return Group Identity when get group successfully, otherwise return empty string.
 *
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpGetGrpIdent(ZUINT iSessId);

/**
 * @brief MTC Get group chat id from cmcc group.
 *
 * @param [in] iSessId The cmcc group session id.
 *
 * @return The group chat id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpGetGrpChatId(ZUINT iSessId);

/**
 * @brief MTC Get participant information from cmcc group..
 *
 * The participant is the remote client who is joining session.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpGetPartp(ZUINT iSessId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief Get original identity of participant URI from cmcc group.
 *
 * The participant is the initiator who initialized this cmcc group.
 * It will return local URI if local client is the session initiator.
 * It will return identity uri if invitation has P-Asserted-Identity information.
 *
 * @param [in] iSessId The cmcc group session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpGetOrigIdPartp(ZUINT iSessId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief MTC get group chat version.
 *
 * @param [in] iSessId The session id.
 *
 * @return group chat version.
 */
ZFUNC ZUINT Mtc_ImCmccGrpGetVersionId(ZUINT iSessId);

/**
 * @brief MTC set group chat version.
 *
 * @param [in] iSessId The session id.
 * @param [in] iVer The group chat version.
 *
 * @retval ZOK Set version successfully.
 * @retval ZFAILED Set version failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpSetVersionId(ZUINT iSessId, ZUINT iVer);

/**
 * @brief MTC get enterprise group indication.
 *
 * @param [in] iSessId The session id.
 *
 * @return enterprise group indication.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpGetEnterPriseGrpInd(ZUINT iSessId);

/**
 * @brief MTC get party group indication from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return party group indication.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpGetPartyGrpInd(ZUINT iSessId);

/**
 * @brief Get participant list id.
 *
 * The participant list id is all remote clients who are joining session.
 *
 * @param [in] iSessId The session id.
 *
 * @return The participant list id on succeed or 0 on failed.
 *
 *  The caller is responsible for freeing it by @ref Mtc_PartpLstDelete.
 */
ZFUNC ZUINT Mtc_ImCmccGrpGetPartpLstId(ZUINT iSessId);

/**
 * @brief MTC Get date time from message session.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpGetSysDateTime(ZUINT iSessId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from message session.
 *
 * @param [in] iSessId The session id.
 *
 * @return message session date time(milliseconds), otherwise return 0.
 */
ZFUNC ZMTIME_T Mtc_ImCmccGrpGetDateTime(ZUINT iSessId);

/**
 * @brief Get subject from cmcc group information.
 *
 * This method should used when callback Mtc_ImCbSetCmccGrpInfoUpdate notified.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group subject.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpInfoGetSubject(ZUINT iGrpInfoId);

/**
 * @brief Get group chat id from cmcc group information.
 *
 * This method should used when callback Mtc_ImCbSetCmccGrpInfoUpdate notified.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group chat id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpInfoGetGrpChatId(ZUINT iGrpInfoId);

/**
 * @brief Get group Identity(group uri) from cmcc group information.
 *
 * This method should used when callback Mtc_ImCbSetCmccGrpInfoUpdate notified.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group Identity.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpInfoGetGrpIdent(ZUINT iGrpInfoId);

/**
 * @brief Get group version from cmcc group information.
 *
 * This method should used when callback Mtc_ImCbSetCmccGrpInfoUpdate notified.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group version.
 * The caller must copy it, then use.
 */
ZFUNC ZUINT Mtc_ImCmccGrpInfoGetVersion(ZUINT iGrpInfoId);

/**
 * @brief Get participant list id from cmcc group information.
 *
 * This method should used when callback Mtc_ImCbSetCmccGrpInfoUpdate notified.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return participant list id.
 * The caller must copy it, then use.
 */
ZFUNC ZUINT Mtc_ImCmccGrpInfoGetPartpLstId(ZUINT iGrpInfoId);

/**
 * @brief MTC Get max user count from cmcc group information.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group max user count.
 */
ZFUNC ZUINT Mtc_ImCmccGrpInfoGetMaxUsrCnt(ZUINT iGrpInfoId);

/**
 * @brief MTC Get group type from cmcc group information.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group type, @see @ref EN_MTC_GROUP_TYPE..
 */
ZFUNC ZUINT Mtc_ImCmccGrpInfoGetGroupType(ZUINT iGrpInfoId);

/**
 * @brief MTC Get user count from cmcc group information.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group user count.
 */
ZFUNC ZUINT Mtc_ImCmccGrpInfoGetUsrCnt(ZUINT iGrpInfoId);

/**
 * @brief MTC get active flag from cmcc group information.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group active flag.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpInfoGetActive(ZUINT iGrpInfoId);

/**
 * @brief MTC get locked flag from cmcc group information.
 *
 * @param [in] iGrpInfoId The cmcc group information session id.
 *
 * @return cmcc group locked flag.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpInfoGetLocked(ZUINT iGrpInfoId);

/**
 * @brief Sending pager instant message to cmcc group chat.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetCmccGrpPMsgSendOk or @ref Mtc_ImCbSetCmccGrpPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpIdentity The group identity(group uri).
 * @param [in] pcGroupChatId The group chat id.
 * @param [in] iMsgType The message type, see @ref EN_MTC_CMCCGRP_PMSG_CTYPE.
 * @param [in] pcMsg The message body.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] iAtType The at function type, see EN_MTC_CMCCGRP_PMSG_AT_TYPE.
 * @param [in] pcFontInfo The font information of message. 
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpPMsgSend(ZCOOKIE zCookie, 
                ZCHAR *pcGrpIdentity, ZCHAR *pcGrpChatId, ZUINT iMsgType, 
                ZCHAR *pcMsg, ZUINT iAtPartpLstId, ZUINT iAtType, 
                ZCHAR *pcFontInfo);

/**
 * @brief Resending pager instant message to cmcc group chat.
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetCmccGrpPMsgSendOk or @ref Mtc_ImCbSetCmccGrpPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcGrpIdentity The group identity(group uri).
 * @param [in] pcGroupChatId The group chat id.
 * @param [in] iMsgType The message type, see @ref EN_MTC_CMCCGRP_PMSG_CTYPE.
 * @param [in] pcMsg The message body.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] iAtType The at function type, see EN_MTC_CMCCGRP_PMSG_AT_TYPE.
 * @param [in] pcFontInfo The font information of message. 
 * @param [in] pcReImdnId The resend imdn message id.
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpPMsgReSend(ZCOOKIE zCookie, 
                ZCHAR *pcGrpIdentity, ZCHAR *pcGrpChatId, ZUINT iMsgType, 
                ZCHAR *pcMsg, ZUINT iAtPartpLstId, ZUINT iAtType, 
                ZCHAR *pcFontInfo, ZCHAR *pcReImdnId);

/**
 * @brief Sending pager instant message to one participant in cmcc group chat..
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetCmccGrpPMsgSendOk or @ref Mtc_ImCbSetCmccGrpPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcPeerUri The peer uri in group.
 * @param [in] pcGrpIdentity The group identity(group uri).
 * @param [in] pcGroupChatId The group chat id.
 * @param [in] iMsgType The message type, see @ref EN_MTC_CMCCGRP_PMSG_CTYPE.
 * @param [in] pcMsg The message body.
 * @param [in] pcFontInfo The font information of message. 
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpPMsgSendO(ZCOOKIE zCookie, ZCHAR *pcPeerUri, 
                ZCHAR *pcGrpIdentity, ZCHAR *pcGrpChatId, ZUINT iMsgType, 
                ZCHAR *pcMsg, ZCHAR *pcFontInfo);

/**
 * @brief Resending pager instant message to one participant in cmcc group chat..
 * IM will send by SIP MESSAGE method.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetCmccGrpPMsgSendOk or @ref Mtc_ImCbSetCmccGrpPMsgSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcPeerUri The peer uri in group.
 * @param [in] pcGrpIdentity The group identity(group uri).
 * @param [in] pcGroupChatId The group chat id.
 * @param [in] iMsgType The message type, see @ref EN_MTC_CMCCGRP_PMSG_CTYPE.
 * @param [in] pcMsg The message body.
 * @param [in] pcFontInfo The font information of message. 
 * @param [in] pcReImdnId The resend imdn message id. 
 *
 * @return The message id when send message successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImCmccGrpPMsgReSendO(ZCOOKIE zCookie, 
                ZCHAR *pcPeerUri, ZCHAR *pcGrpIdentity, ZCHAR *pcGrpChatId, 
                ZUINT iMsgType, ZCHAR *pcMsg, ZCHAR *pcFontInfo, 
                ZCHAR *pcReImdnId);

/**
 * @brief Get user cookie in a cmcc group page message.
 *
 * @param [in] iMsgId The message id.
 *
 * @retval User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImCmccGrpPMsgGetCookie(ZUINT iMsgId);

/**
 * @brief Set user cookie in a cmcc group page message.
 *
 * @param [in] iMsgId The message id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpPMsgSetCookie(ZUINT iMsgId, ZCOOKIE zCookie);

/**
 * @brief MMF Get group identity from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The group identity.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetGrpIdent(ZUINT iMsgId);

/**
 * @brief MMF Get group chat id from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The group chat id.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetGrpChatId(ZUINT iMsgId);

/**
 * @brief MMF Get imdn massage-id of cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The Imdn message-id.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetImdnMsgId(ZUINT iMsgId);

/**
 * @brief MTC Get date time from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The cmcc group pager message date time(milliseconds), otherwise return 0.
 */
ZFUNC ZMTIME_T Mtc_ImCmccGrpPMsgGetDateTime(ZUINT iMsgId);

/**
 * @brief MTC Get the content type from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return Type of page message, @ref EN_MTC_CMCCGRP_PMSG_CTYPE.
 *
 */
ZFUNC ZUINT Mtc_ImCmccGrpPMsgGetContentType(ZUINT iMsgId);

/**
 * @brief MTC Get the Imdn type from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return Type of page message, @ref EN_MTC_CMCCGRP_PMSG_IMDN_TYPE.
 */
ZFUNC ZUINT Mtc_ImCmccGrpPMsgGetImdnType(ZUINT iMsgId);

/**
 * @brief MTC Get the content from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The cmcc group pager message content.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetContent(ZUINT iMsgId);

/**
 * @brief MTC Get peer information from cmcc group pager message.
 *
 * Get receiver information when Mtc_ImCmccGrpPMsgHasCcInd is true
 * or Get sender information when Mtc_ImCmccGrpPMsgHasCcInd is false.
 *
 * The participant is the remote client who sent message
 * or the own multi client who carbon copy message
 *
 * @param [in] iMsgId The message Id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * ppcName and ppcUri must copy it, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImCmccGrpPMsgGetPeerPartp(ZUINT iMsgId, 
                ZCHAR **ppcName, ZCHAR **ppcUri);

/**
 * @brief MTC Get carbon copy indication flag from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a carbon copy message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpPMsgHasCcInd(ZUINT iMsgId);

/**
 * @brief MTC Get silence indication flag from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a silence message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpPMsgHasSilenceInd(ZUINT iMsgId);

/**
 * @brief mtcf MTC Get at indication flag from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it has at indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpPMsgHasAtInd(ZUINT iMsgId);

/**
 * @brief MTC Get group data message indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has group data message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpPMsgHasGrpDataInd(ZUINT iMsgId);

/**
 * @brief MTC Get offline indication flag from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return ZTRUE if it is a offline message, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpPMsgHasOffInd(ZUINT iMsgId);

/**
 * @brief MTC Get conversation-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The conversation-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetConvId(ZUINT iMsgId);

/**
 * @brief MTC Get contribution-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The contribution-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetContId(ZUINT iMsgId);

/**
 * @brief MTC Get revoke message-id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke message-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetRevokeMsgId(ZUINT iMsgId);

/**
 * @brief MTC Get revoke result from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke result.
 */
ZFUNC ZUCHAR Mtc_ImCmccGrpPMsgGetRevokeResult(ZUINT iMsgId);

/**
 * @brief MTC Get revoke from addr from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke from addr.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetRevokeFromAddr(ZUINT iMsgId);

/**
 * @brief MTC Get revoke to addr from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The revoke to addr.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImCmccGrpPMsgGetRevokeToAddr(ZUINT iMsgId);

/**
 * @brief MTC Get revoke message indication flag from im message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval ZTRUE if it has revoke message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImCmccGrpPMsgHasRevokeMsgInd(ZUINT iMsgId);

/**
 * @brief MTC create groupdata xml content.
 *
 * @param [in] pcMsg The groupdata target msg.
 * @param [in] ucDataType The groupdata type EN_MTC_GROUP_DATA_TYPE.
 * @param [out] The groupdata xml content.
 * The caller must copy it, then use.
 *
 * @retval groupdata id.
 */
ZFUNC ZUINT Mtc_ImCmccGrpCreateGrpDataXml(ZCHAR *pcMsg, ZUCHAR ucDataType, 
                ZCHAR **ppcGrpDataXml);

/**
 * @brief MTC Get group manage set result from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The group manage set result.
 */
ZFUNC ZUCHAR Mtc_ImCmccGetGrpManResult(ZUINT iMsgId);

/**
 * @brief MTC Get group data id from page message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @return The group data id.
 */
ZFUNC ZUINT Mtc_ImCmccGetGrpDataId(ZUINT iMsgId);

/**
 * @brief MTC Get font information from cmcc group pager message.
 *
 * @param [in] iMsgId The message Id.
 *
 * @retval The font information.
 */
ZFUNC ZCHAR* Mtc_ImCmccGrpPMsgGetFontInfo(ZUINT iMsgId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_CMCC_H__ */

