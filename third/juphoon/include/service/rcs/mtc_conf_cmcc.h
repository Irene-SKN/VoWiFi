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
  File name     : mtc_conf_cmcc.h
  Module        : multimedia talk client
  Author        : kewin.peng
  Created on    : 2016-10-31
  Description   :
      Data structure and function declare required by MTC cmcc conference manage.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CONF_CMCC_H__
#define _MTC_CONF_CMCC_H__

/**
 * @file mtc_conf_cmcc.h
 * @brief MTC Cmcc Conference Manage Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** 
 * @brief MTC conference cmc create.
 *
 * @return The id of this new created conference on succeed, otherwise return ZMAXUINT.
 *
 * Different with the method of session creation, this function only malloc
 * the resource of conference. If you want to setup or join a conference, you need
 * step ahead by calling other functions.
 *
 * @see @ref Mtc_ConfCmccSetup
 */
ZFUNC ZUINT Mtc_ConfCmccCreate(ZFUNC_VOID);

/** 
 * @brief MTC setup a new cmcc conference as the creator.
 *
 * If setup a new conference as the creator, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCmccCbSetOutgoing, @ref Mtc_ConfCmccCbSetAlerted,
 *            @ref Mtc_ConfCmccCbSetConned
 *
 * While receiving conference invitation, GUI will be notified by callback which 
 * was set by @ref Mtc_ConfCmccCbSetIncoming.
 *
 * @param [in] iConfId The id of conference which you want to setup.
 * @param [in] zCookie Used to correspond conference with UI resource.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfCmccCreate
 */
ZFUNC ZINT Mtc_ConfCmccSetup(ZUINT iConfId, ZCOOKIE zCookie);

/** 
 * @brief MTC cmcc conference get conference URI and display name.
 *
 * @param [in] iConfId The id of conference which you want to get.
 * @param [out] ppcDispName The display name of conference.
 * @param [out] ppcUri The URI of conference.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfCmccGetConfUri(ZUINT iConfId, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri);

/** 
 * @brief MTC invite new participant list to a new conference, this interface 
 *        will setup a new conference automatically.
 *
 * @param [in] iConfId The id of conference to which you want invite new
 *                      participant list.
 * @param [in] zCookie Used to correspond conference with UI resource.
 * @param [in] iPartpLstId The participant list id, UI shall use 
 *                      @ref Mtc_PartpLstCreate, @ref Mtc_PartpLstAddPartp 
 *                      to create the id.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_ConfKickUser
 */
ZFUNC ZINT Mtc_ConfCmccIvtUserLst(ZUINT iConfId, ZCOOKIE zCookie, 
                ZUINT iPartpLstId);

/**
 * @brief MTC chairman join cmcc conference with subcribe.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ConfCmccCbSetJoinOk or @ref Mtc_ConfCmccCbSetJoinFailed.
 *
 * @param [in] pcConfUri The uri of exist conference.
 *
 * @return The id of conference, otherwise return ZMAXUINT.
 *
 */
ZFUNC ZUINT Mtc_ConfCmccJoin(ZCHAR *pcConfUri);

/**
 * @brief MTC participant join cmcc conference with REFER.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ConfCmccCbSetJoinOkX or @ref Mtc_ConfCmccCbSetJoinFailedX.
 *
 * @param [in] pcConfUri The uri of exist conference.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 */
ZFUNC ZINT Mtc_ConfCmccJoinX(ZCHAR *pcConfUri);

/**
 * @brief MTC cmcc term conference.
 *
 * @param [in] iConfId The id of the conference.
 *
 * @retval ZOK term conference successfully.
 * @retval ZFAILED term conference failed.
 *
 * Actually Mtc_ConfTerm does not free all resource allocated for this
 * conference. It only starts a terminating procedure. All resource will be
 * freed automatically when the procedure ends.
 *
 * @see @ref Mtc_ConfCmccSetup, @ref Mtc_ConfCmccJoin,
 */
ZFUNC ZINT Mtc_ConfCmccTerm(ZUINT iConfId);

/** 
 * @brief MTC cmcc conference invite an user to conference.
 *
 * @param [in] iConfId The id of conference to which you want invite new
 *                      participant.
 * @param [in] pcUserUri The uri of destination participant.
 *
 * @retval ZOK invite user successfully.
 * @retval ZFAILED invite user failed.
 *
 * @see @ref Mtc_ConfCmccKickOutUser
 */
ZFUNC ZINT Mtc_ConfCmccIvtUser(ZUINT iConfId, ZCHAR *pcUserUri);

/** 
 * @brief MTC cmcc kick out an user from conference. 
 *
 * @param [in] iConfId The id of conference to which you want kick participant.
 * @param [in] pcUserUri The uri of destination participant.
 *
 * @retval ZOK kick out user successfully.
 * @retval ZFAILED kick out user failed.
 *
 * @see @ref Mtc_ConfCmccIvtUser
 */
ZFUNC ZINT Mtc_ConfCmccKickOutUser(ZUINT iConfId, ZCHAR *pcUserUri);

/** 
 * @brief MTC cmcc mute a participant. 
 *
 * @param [in] iConfId The id of conference to which you want mute a participant.
 * @param [in] pcUserUri The uri of destination participant.
 *
 * @retval ZOK mute user successfully.
 * @retval ZFAILED mute user failed.
 *
 * @see @ref Mtc_ConfCmccUnmute, Mtc_ConfCmccUnmuteAll
 */
ZFUNC ZINT Mtc_ConfCmccMute(ZUINT iConfId, ZCHAR *pcUserUri);

/** 
 * @brief MTC cmcc unmute a participant. 
 *
 * @param [in] iConfId The id of conference to which you want unmute a participant.
 * @param [in] pcUserUri The uri of destination participant.
 *
 * @retval ZOK unmute user successfully.
 * @retval ZFAILED unmute user failed.
 *
 * @see @ref Mtc_ConfCmccMute, Mtc_ConfCmccMuteAll
 */
ZFUNC ZINT Mtc_ConfCmccUnmute(ZUINT iConfId, ZCHAR *pcUserUri);

/** 
 * @brief MTC cmcc mute all participant. 
 *
 * @param [in] iConfId The id of conference to which you want mute all participant.
 *
 * @retval ZOK mute user successfully.
 * @retval ZFAILED mute user failed.
 *
 * @see @ref Mtc_ConfCmccUnmuteAll, Mtc_ConfCmccUnmute
 */
ZFUNC ZINT Mtc_ConfCmccMuteAll(ZUINT iConfId);

/** 
 * @brief MTC cmcc unmute all participant. 
 *
 * @param [in] iConfId The id of conference to which you want unmute all participant.
 *
 * @retval ZOK unmute user successfully.
 * @retval ZFAILED unmute user failed.
 *
 * @see @ref Mtc_ConfCmccMuteAll, Mtc_ConfCmccMute
 */
ZFUNC ZINT Mtc_ConfCmccUnmuteAll(ZUINT iConfId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CONF_CMCC_H__ */

