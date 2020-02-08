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
  File name     : mtc_conf_cmcc_cb.h
  Module        : multimedia talk client
  Author        : kerwin.peng
  Created on    : 2016-11-02
  Description   :
      Data structure and function declare required by MTC conference callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CONF_CMCC_CB_H__
#define _MTC_CONF_CMCC_CB_H__

/**
 * @file mtc_conf_cb.h
 * @brief MTC Conference Callback Interfaces
 *
 * This file includes conference callback interface function. Those function
 * is used to manage sessions and conferences.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC cmcc conference callback. */
typedef ZVOID (*PFN_MTCCONFCMCCCB)(ZUINT iConfId);

/** @brief Type define of MTC cmcc conference callback. */
typedef ZVOID (*PFN_MTCCONFCMCCCBX)(ZUINT iConfId, ZCHAR *pcUserUri);

/** @brief Type define of MTC cmcc conference callback. */
typedef ZVOID (*PFN_MTCCONFCMCCCBURI)(ZCHAR *pcConfUri);

/** @brief Type define of MTC cmcc conference callback for notify participant list updated. */
typedef ZVOID (*PFN_MTCCONFCMCCCBPTPTUPDT)(ZUINT iConfId, ZUINT iPartpLstId, 
                ZBOOL bFullNtfy);

/** @brief Type define of MTC cmcc conference callback for notify error. */
typedef ZVOID (*PFN_MTCCONFCMCCCBERR)(ZUINT iConfId, ZUINT iStatCode);

/**
 * @brief Set callback of client setup an outgoing conference.
 *
 * This callback indicates client has setup an outgoing conference. GUI should not
 * close the conference window, just update the client status in conference.
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the ID of conference.
 *       GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetOutgoing(PFN_MTCCONFCMCCCB pfnCb);  

/**
 * @brief Set callback of receive response during conference establish.
 *
 * This client try to establish a conference. And when receive 1xx response
 * this callback will be invoked. GUI should update status of conference
 * window.
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the ID of conference.
 *       GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetAlerted(PFN_MTCCONFCMCCCB pfnCb);  

/**
 * @brief Set callback of cmcc conference has established.
 *
 * This callback indicates conference has established. GUI should update
 * status of conference window.
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the ID of conference.
 *      GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetConned(PFN_MTCCONFCMCCCB pfnCb); 

/**
 * @brief Set callback of client(chairman) join an exist cmcc conference ok.
 *
 * This callback indicates client has join an exist cmcc conference. GUI should not
 * close the conference window, just update the client status in conference.
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the ID of conference.
 *       GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetJoinOk(PFN_MTCCONFCMCCCB pfnCb);

/**
 * @brief Set callback of client(chairman) join an exist cmcc conference failed.
 *
 * This callback indicates client has join an exist cmcc conference. GUI should not
 * close the conference window, just update the client status in conference.
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the ID of conference.
 *       GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetJoinFailed(PFN_MTCCONFCMCCCB pfnCb);

/**
 * @brief Set callback of client(participant) join an exist cmcc conference ok.
 *
 * This callback indicates client has join an exist cmcc conference. GUI should not
 * close the conference window, just update the client status in conference.
 * "pcConfUri" in @ref PFN_MTCCONFCMCCCB is the URI of conference.
 *       GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetJoinOkX(PFN_MTCCONFCMCCCBURI pfnCb);

/**
 * @brief Set callback of client(participant) join an exist cmcc conference failed.
 *
 * This callback indicates client has join an exist cmcc conference. GUI should not
 * close the conference window, just update the client status in conference.
 * "pcConfUri" in @ref PFN_MTCCONFCMCCCBURI is the URI of conference.
 *       GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetJoinFailedX(PFN_MTCCONFCMCCCBURI pfnCb);  

/**
 * @brief Set callback of the invited user has accepted invite.
 *
 * This client add another user to the conference. This callback was invoked
 * when that user accept the invite. Usually, callback which was set by 
 * Mtc_ConfCmccCbSetPtptUpdt will be invoked sequentially. 
 * GUI should then update the participants of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCBX is the id of conference.
 *          GUI use it to locate the conference window.
 * "pcUserUri" in @ref PFN_MTCCONFCMCCCBX is the URI of the participant
 *          invited which server has been accepted.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetIvtAcpt(PFN_MTCCONFCMCCCBX pfnCb); 

/**
 * @brief Set callback of the invited user is failed.
 *
 * This client add another user to the conference. This callback was invoked
 * when that invite user failed. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCBX is the id of conference.
 *          GUI use it to locate the conference window.
 * "pcUserUri" in @ref PFN_MTCCONFCMCCCBX is the URI of the participant
 *          invited which server has been accepted.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetIvtFail(PFN_MTCCONFCMCCCBX pfnCb);

/**
 * @brief Set callback of kick user is accepted.
 *
 * This client want to remove a user from the conference. This callback 
 * was invoked when that user has been removed. Usually, 
 * callback which was set by @ref Mtc_ConfCmccCbSetPtptUpdt will be invoked sequentially. 
 * GUI should then update the participants of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCBX is the id of conference.
 *          GUI use it to locate the conference window.
 * "pcUserUri" in @ref PFN_MTCCONFCMCCCBX is the URI of the participant
 *          invited which server has been accepted.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetKickAcpt(PFN_MTCCONFCMCCCBX pfnCb); 

/**
 * @brief Set callback of kick user is failed.
 *
 * This client want to remove a user from the conference. This callback 
 * was invoked when that kick user failed.
 * "iConfId" in @ref PFN_MTCCONFCMCCCBX is the id of conference.
 *          GUI use it to locate the conference window.
 * "pcUserUri" in @ref PFN_MTCCONFCMCCCBX is the URI of the participant
 *          invited which server has been accepted.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetKickFail(PFN_MTCCONFCMCCCBX pfnCb);

/**
 * @brief Set callback of indicate conference participant's status updated.
 *
 * GUI should update conference participant's status.
 * "iConfId" in @ref PFN_MTCCONFCMCCCBPTPTUPDT is the id of conference.
 *          GUI use it to locate the conference window.
 * "iPartpLstId" in @ref PFN_MTCCONFCMCCCBPTPTUPDT is the participant list id of conference.
 * "bFullNtfy" in @ref PFN_MTCCONFCMCCCBPTPTUPDT is the conference state full flag, 
 *           TRUE for "full", FALSE for "partial".
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetPtptUpdt(PFN_MTCCONFCMCCCBPTPTUPDT pfnCb); 

/**
 * @brief Set callback of disconnected from conference.
 *
 * This callback indicates client has disconnected from conference. GUI 
 * should close conference window.
 * "iConfId" in @ref PFN_MTCCONFCMCCCBERR is the ID of conference.
 *      GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetDisced(PFN_MTCCONFCMCCCBERR pfnCb); 

/**
 * @brief Set callback of error occurred during conference.
 *
 * This callback indicates error occurred during call. GUI should show
 * the detail error information(english) to user.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetError(PFN_MTCCONFCMCCCBERR pfnCb); 

/**
 * @brief Set callback of mute participant ok.
 *
 * This chairman mutes a participant in the conference. This callback was invoked
 * when server accepts the MUTE request. GUI should then update the UI of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCBX is the id of conference.
 *          GUI use it to locate the conference window.
 * "pcUserUri" in @ref PFN_MTCCONFCMCCCBX is the URI of the participant.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetMuteOk(PFN_MTCCONFCMCCCBX pfnCb); 

/**
 * @brief Set callback of mute participant failed.
 *
 * This chairman mutes a participant in the conference. This callback was invoked
 * when server cannot accept the MUTE request. GUI should then update the UI of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCBX is the id of conference.
 *          GUI use it to locate the conference window.
 * "pcUserUri" in @ref PFN_MTCCONFCMCCCBX is the URI of the participant.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetMuteFailed(PFN_MTCCONFCMCCCBX pfnCb);

/**
 * @brief Set callback of unmute participant ok.
 *
 * This chairman unmutes a participant in the conference. This callback was invoked
 * when server accepts the UNMUTE request. GUI should then update the UI of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCBX is the id of conference.
 *          GUI use it to locate the conference window.
 * "pcUserUri" in @ref PFN_MTCCONFCMCCCBX is the URI of the participant.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetUnmuteOk(PFN_MTCCONFCMCCCBX pfnCb); 

/**
 * @brief Set callback of unmute participant failed.
 *
 * This chairman unmutes a participant in the conference. This callback was invoked
 * when server cannot accept the MUTE request. GUI should then update the UI of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCBX is the id of conference.
 *          GUI use it to locate the conference window.
 * "pcUserUri" in @ref PFN_MTCCONFCMCCCBX is the URI of the participant.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetUnmuteFailed(PFN_MTCCONFCMCCCBX pfnCb);

/**
 * @brief Set callback of mute all participants ok.
 *
 * This chairman mutes all participants in the conference. This callback was invoked
 * when server accepts the MUTE request. GUI should then update the UI of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the id of conference.
 *          GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetMuteAllOk(PFN_MTCCONFCMCCCB pfnCb); 

/**
 * @brief Set callback of mute all participants failed.
 *
 * This chairman mutes all participants in the conference. This callback was invoked
 * when server cannot accept the MUTE request. GUI should then update the UI of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the id of conference.
 *          GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetMuteAllFailed(PFN_MTCCONFCMCCCB pfnCb);

/**
 * @brief Set callback of unmute all participants ok.
 *
 * This chairman unmutes all participants in the conference. This callback was invoked
 * when server accepts the UNMUTE request. GUI should then update the UI of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the id of conference.
 *          GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetUnmuteAllOk(PFN_MTCCONFCMCCCB pfnCb); 

/**
 * @brief Set callback of unmute participants failed.
 *
 * This chairman unmutes all participants in the conference. This callback was invoked
 * when server cannot accept the MUTE request. GUI should then update the UI of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCMCCCB is the id of conference.
 *          GUI use it to locate the conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCmccCbSetUnmuteAllFailed(PFN_MTCCONFCMCCCB pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CONF_CMCC_CB_H__ */

