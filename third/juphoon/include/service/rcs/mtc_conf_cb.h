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
  File name     : mtc_conf_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC conference callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CONF_CB_H__
#define _MTC_CONF_CB_H__

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

/** @brief Type define of MTC conference callback. */
typedef ZVOID (*PFN_MTCCONFCB)(ZUINT iConfId);

/** @brief Type define of MTC conference callback for failed. */
typedef ZVOID (*PFN_MTCCONFCBFAILED)(ZUINT iConfId, ZCHAR *pcUri, ZUINT iStatCode);

/** @brief Type define of MTC conference callback. */
typedef ZVOID (*PFN_MTCCONFCBX)(ZUINT iConfId, ZCHAR *pcUri);

/** @brief Type define of MTC conference callback for notify participant updated. */
typedef ZVOID (*PFN_MTCCONFCBPTPTUPDT)(ZUINT iConfId, ZUINT iPartpLstId, 
                ZBOOL bFullNtfy);

/** @brief Type define of MTC conference callback for notify video stream participant list updated. */
typedef ZVOID (*PFN_MTCCONFCBVIDEOPTPTLSTIUPDT)(ZUINT iConfId, ZUINT iPartpLstId);

/** @brief Type define of MTC conference callback for notify video stream participant info updated. */
typedef ZVOID (*PFN_MTCCONFCBVIDEOSTRMPTPTUPDT)(ZUINT iConfId, ZUINT iStrmId,
                ZCHAR *pcUri);

/** @brief Type define of MTC conference callback for notify audio stream participant speak state updated. */
typedef ZVOID (*PFN_MTCCONFCBPTPTSPKSTATEUPDT)(ZUINT iConfId, ZCHAR *pcUri);

/** @brief Type define of MTC conference callback for notify audio stream no participant speak. */
typedef ZVOID (*PFN_MTCCONFCBNOPTPTSPK)(ZUINT iConfId);

/** @brief Type define of MTC call callback for network status changed */
typedef ZVOID (*PFN_MTCCONFCBNETSTATUSCHANGED)(ZUINT iConfId, 
                ZBOOL bSend, ZINT iType);

/** @brief Type define of MTC conference callback for notify error. */
typedef ZVOID (*PFN_MTCCONFCBERR)(ZUINT iConfId, ZUINT iStatCode);

/** @brief Type define of MTC conference callback for result code. */
typedef ZVOID (*PFN_MTCCONFCBRESULT)(ZUINT iResultCode);

/** @brief Type define of MTC conference callback for query account result code. */
typedef ZVOID (*PFN_MTCCONFCBQUERYRESULT)(ZUINT iResultCode, ZCHAR *pcResult, 
                ZUINT iTotalLeftBalance);

/** @brief Type define of MTC conference callback for account failed. */
typedef ZVOID (*PFN_MTCCONFCBACCOUNTFAILED)(ZUINT iRspCode);

/**
 * @brief Set callback of client receive an incoming conference.
 *
 * This callback indicates client receive an incoming conference. GUI should 
 * show the conference window.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should assign it to the
 *   corresponding window, use Mtc_ConfGetPeerUri to get detail
 *   information of conference.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetIncoming(PFN_MTCCONFCB pfnCb);   

/**
 * @brief Set callback of client setup an outgoing conference.
 *
 * This callback indicates client has setup an outgoing conference. GUI should not
 * close the conference window, just update the client status in conference.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI use it to locate the conference
 *   window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetOutgoing(PFN_MTCCONFCB pfnCb);  

/**
 * @brief Set callback of receive response during conference establish.
 *
 * This client try to establish a conference. And when receive 1xx response
 * this callback will be invoked. GUI should update status of conference
 * window.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI use it to locate the conference
 *   window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetAlerted(PFN_MTCCONFCB pfnCb);  

/**
 * @brief Set callback of conference has established.
 *
 * This callback indicates conference has established. GUI should update
 * status of conference window.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI use it to locate the conference
 *   window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetConned(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of disconnected from conference.
 *
 * This callback indicates client has disconnected from conference. GUI 
 * should close conference window.
 * "iConfId" in @ref PFN_MTCCONFCBERR is the ID of conference. GUI use it to locate the conference
 *   window.
 * "iStatCode" in @ref PFN_MTCCONFCBERR is the status  error code. 
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetDisced(PFN_MTCCONFCBERR pfnCb); 

/**
 * @brief Set callback of the invited user has accepted invite.
 *
 * This client add another user to the conference. This callback was invoked
 * when that user accept the invite. Usually, callback which was set by 
 * Mtc_ConfCbSetPtptUpdt will be invoked sequentially. 
 * GUI should then update the participants of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCBX is the ID of conference. GUI use it to locate the conference
 *   window.
 * "pcUri" in @ref PFN_MTCCONFCBX is the URI of the participant invited which server has been accepted.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetIvtAcpt(PFN_MTCCONFCBX pfnCb); 

/**
 * @brief Set callback of the invited user is failed.
 *
 * This client add another user to the conference. This callback was invoked
 * when that invite user failed. 
 * "iConfId" in @ref PFN_MTCCONFCBFAILED is the ID of conference. GUI use it to locate the conference
 *   window.
 * "pcUri" in @ref PFN_MTCCONFCBFAILED is the URI of the participant invited failed.
 * "iStatCode" in @ref PFN_MTCCONFCBFAILED is the status  error code. 
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetIvtFail(PFN_MTCCONFCBFAILED pfnCb);

/**
 * @brief Set callback of kick user is accepted.
 *
 * This client want to remove a user from the conference. This callback 
 * was invoked when that user has been removed. Usually, 
 * callback which was set by @ref Mtc_ConfCbSetPtptUpdt will be invoked sequentially. 
 * GUI should then update the participants of the conference. 
 * "iConfId" in @ref PFN_MTCCONFCBX is the ID of conference. GUI use it to locate the conference
 *   window.
 * "pcUri" in @ref PFN_MTCCONFCBX is the URI of the participant kicked which server has been accepted.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetKickAcpt(PFN_MTCCONFCBX pfnCb); 

/**
 * @brief Set callback of kick user is failed.
 *
 * This client want to remove a user from the conference. This callback 
 * was invoked when that kick user failed.
 * "iConfId" in @ref PFN_MTCCONFCBFAILED is the ID of conference. GUI use it to locate the conference
 *   window.
 * "pcUri" in @ref PFN_MTCCONFCBFAILED is the URI of the participant kicked failed.
 * "iStatCode" in @ref PFN_MTCCONFCBFAILED is the status  error code. 
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetKickFail(PFN_MTCCONFCBFAILED pfnCb);

/**
* @brief Set callback of indicate conference participant's status updated.
*
* GUI should update conference participant's status.
* "iConfId" in @ref PFN_MTCCONFCBPTPTUPDT is the id of conference.
*          GUI use it to locate the conference window.
* "iPartpLstId" in @ref PFN_MTCCONFCBPTPTUPDT is the participant list id of conference.
* "bFullNtfy" in @ref PFN_MTCCONFCBPTPTUPDT is the conference state full flag, 
*           TRUE for "full", FALSE for "partial".
*
* @param [in] pfnCb Callback function.
*/
ZFUNC ZVOID Mtc_ConfCbSetPtptUpdt(PFN_MTCCONFCBPTPTUPDT pfnCb); 

/**
* @brief Set callback of indicate conference participant list updated.
*
* GUI should update conference participant list info.
* "iConfId" in @ref PFN_MTCCONFCBVIDEOPTPTLSTIUPDT is the id of conference.
*          GUI use it to locate the conference window.
* "iPartpLstId" in @ref PFN_MTCCONFCBVIDEOPTPTLSTIUPDT is the participant list id of conference.
*
* @param [in] pfnCb Callback function.
*/
ZFUNC ZVOID Mtc_ConfCbSetVideoPtptLstUpdt(PFN_MTCCONFCBVIDEOPTPTLSTIUPDT pfnCb); 

/**
 * @brief Set callback of indicate conference participant's video stream info updated.
 *
 * GUI should update conference participant's video stream info.
 * "iConfId" in @ref PFN_MTCCONFCBVIDEOSTRMPTPTUPDT is the id of conference.
 *          GUI use it to locate the conference window.
 * "iStrmId" in @ref PFN_MTCCONFCBVIDEOSTRMPTPTUPDT is the video stream id.
 *  "pcUri" is the number(not uri) of the participant. If no participant, the URI will be "clear".
 *  if camera is off, the URI will be "Number:PIC", e.g. "+8616000000313:PIC".
 *  if user is removed, the URI wii be "Number1:KICKNumber2",
 *          e.g."+8616000000313:KICK+861380000000", Number1 is chairman number,
 *          number2 is the number of removed participant.
 *
 */
ZFUNC ZVOID Mtc_ConfCbSetVideoStrmPtptUpdt(PFN_MTCCONFCBVIDEOSTRMPTPTUPDT pfnCb); 

/**
 * @brief Set callback of indicate conference modifying accepted.
 *
 * To change the attribute of media stream is called conference modify,
 * includes hold/unhold and add/remove media stream. This callback indicates
 * the modification is accept by peer. GUI should check which service has
 * been invoke by user. If user hold or unhold the call, show hold or
 * unhold successfully. If user add video upon a voice call, then switch
 * to video call window.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should use it to locate
 *        conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetMdfyAcpt(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of indicate conference modified.
 *
 * This callback indicates modification was invoke by peer, and this 
 * modification is completed. 
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should use it to locate
 *    conference window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetMdfyed(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of indicate conference hold OK.
 *
 * This callback indicates hold operation has been completed successfully.
 * GUI should update conference status according to conference ID.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should use it to locate
 *    call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetHoldOk(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of indicate conference hold failed.
 *
 * This callback indicates hold operation has been failed.
 * GUI should update conference status according to conference ID.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should use it to locate
 *    call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetHoldFailed(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of indicate conference un-hold OK.
 *
 * This callback indicates un-hold operation has been completed successfully.
 * GUI should update conference status according to conference ID.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should use it to locate
 *    call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetUnHoldOk(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of indicate conference un-hold failed.
 *
 * This callback indicates un-hold operation has been failed.
 * GUI should update conference status according to conference ID.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should use it to locate
 *    call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetUnHoldFailed(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of indicate conference was held by peer.
 *
 * This callback indicates peer hold the conference.
 * GUI should update conference status according to conference ID.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should use it to locate
 *    call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetHeld(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of indicate conference was un-held by peer.
 *
 * This callback indicates un-held hold the conference.
 * GUI should update conference status according to conference ID.
 * "iConfId" in @ref PFN_MTCCONFCB is the ID of conference. GUI should use it to locate
 *    call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetUnHeld(PFN_MTCCONFCB pfnCb); 

/**
 * @brief Set callback of indicate call's network status.
 *
 * This callback indicates the call's network status.
 * GUI should update session status according to session ID.
 * "iConfId" in @ref PFN_MTCCONFCBNETSTATUSCHANGED is the ID of session. GUI should 
 * use it to locate call window.
 * "bSend" in @ref PFN_MTCCONFCBNETSTATUSCHANGED indicate if the network
 * status of sending direction is changed.
 * "iType" in @ref PFN_MTCCONFCBNETSTATUSCHANGED indicate the network status
 * type @ref EN_MTC_CONF_NET_STATUS_TYPE.
 *
 * @param [in] pfnCb Confback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetNetStaChanged(PFN_MTCCONFCBNETSTATUSCHANGED pfnCb);

/**
 * @brief Set callback of error occurred during conference.
 *
 * This callback indicates error occurred during call. GUI should show
 * the detail error information(english) to user.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetError(PFN_MTCCONFCBERR pfnCb); 

/**
 * @brief Set callback of get conference state failed.
 *
 * This callback indicates error occurred during get conferen state. GUI should show
 * the detail error information(english) to user.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetConfStateFailed(PFN_MTCCONFCBERR pfnCb); 

/**
 * @brief Set callback of select user is accepted.
 *
 * This client want to select a user from the conference. This callback 
 * was invoked when that user has been selected.
 * "iConfId" in @ref PFN_MTCCONFCBX is the ID of conference. GUI use it to locate the conference
 *   window.
 * "pcUri" in @ref PFN_MTCCONFCBX is the URI of the participant selected which server has been accepted.
 * "iStatCode" in @ref PFN_MTCCONFCBX is the status  error code. 
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetSelectUsrOk(PFN_MTCCONFCBX pfnCb); 

/**
 * @brief Set callback of select user is failed.
 *
 * This client want to select a user from the conference. This callback 
 * was invoked when that select user failed.
 * "iConfId" in @ref PFN_MTCCONFCBFAILED is the ID of conference. GUI use it to locate the conference
 *   window.
 * "pcUri" in @ref PFN_MTCCONFCBFAILED is the URI of the participant select failed.
 * "iStatCode" in @ref PFN_MTCCONFCBFAILED is the status  error code. 
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetSelectUsrFail(PFN_MTCCONFCBFAILED pfnCb);

/**
 * @brief Set callback of participant is in speaking state.
 *
 * This client want to know which participant is in speaking state of  the conference. This callback 
 * was invoked when one participant is in speaking state.
 *
 * "iConfId" in @ref PFN_MTCCONFCBPTPTSPKSTATEUPDT is the ID of conference.
 *                 GUI use it to locate the conference window.
 * "pcUri" in @ref PFN_MTCCONFCBPTPTSPKSTATEUPDT is the number(not uri)  of the 
 *                 participant who is in speaking state.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetPtptSpkStateUpdt(PFN_MTCCONFCBPTPTSPKSTATEUPDT pfnCb);

/**
 * @brief Set callback of no participant is in speaking state.
 *
 * This client want to know which participant is in speaking state of  the conference. This callback 
 * was invoked when no participant is in speaking state.
 *
 * "iConfId" in @ref PFN_MTCCONFCBNOPTPTSPK is the ID of conference. GUI use it to locate the conference
 *   window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetNoPtptSpk(PFN_MTCCONFCBNOPTPTSPK pfnCb);

/**
 * @brief Set callback of create account result code(2xx response with result code in body).
 *
 * This client want to know result code of creating account performed by @ref Mtc_ConfCreateAccount.
 *
 * "iResultCode" in @ref PFN_MTCCONFCBRESULT is result code. GUI use it to check the result.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetCreateAccount(PFN_MTCCONFCBRESULT pfnCb);

/**
 * @brief Set callback of create account failed.
 *
 * This client want to know response code of creating account performed by @ref Mtc_ConfCreateAccount.
 *
 * "iRspCode" in @ref PFN_MTCCONFCBACCOUNTFAILED is responce status code. 
 *              GUI use it to check the result.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetCreateAccountFailed(PFN_MTCCONFCBACCOUNTFAILED pfnCb);

/**
 * @brief Set callback of delete account result code(2xx response with result code in body).
 *
 * This client want to know result code of deleting account performed by @ref Mtc_ConfDelAccount.
 *
 * "iResultCode" in @ref PFN_MTCCONFCBRESULT is result code. GUI use it to check the result.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetDelAccount(PFN_MTCCONFCBRESULT pfnCb);

/**
 * @brief Set callback of delete account failed.
 *
 * This client want to know response code of deleting account performed by @ref Mtc_ConfDelAccount.
 *
 * "iRspCode" in @ref PFN_MTCCONFCBACCOUNTFAILED is responce status code.
 *    GUI use it to check the result.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetDelAccountFailed(PFN_MTCCONFCBACCOUNTFAILED pfnCb);

/**
 * @brief Set callback of charge account result code(2xx response with result code in body).
 *
 * This client want to know result code of charging account performed by @ref Mtc_ConfChargeAccount.
 *
 * "iResultCode" in @ref PFN_MTCCONFCBRESULT is result code. GUI use it to check the result.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetCharge(PFN_MTCCONFCBRESULT pfnCb);

/**
 * @brief Set callback of charge account failed.
 *
 * This client want to know result code of charging account performed by @ref Mtc_ConfChargeAccount.
 *
 * "iRspCode" in @ref PFN_MTCCONFCBACCOUNTFAILED is responce status code.
 *    GUI use it to check the result.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetChargeFailed(PFN_MTCCONFCBACCOUNTFAILED pfnCb);

/**
 * @brief Set callback of query account result code(2xx response with result code in body).
 *
 * This client want to know result code of query account performed by @ref Mtc_ConfQueryAccount.
 *
 * "iResultCode" in @ref PFN_MTCCONFCBQUERYRESULT is result code. GUI use it to check the result.
 * "pcResult" in @ref PFN_MTCCONFCBQUERYRESULT is the left balance list with different package. 
 *             GUI use it to check the various left balance type. E.g. Leftbalance1^expirydate1^Type1
 *            ^ServiceType1| Leftbalance2^expirydate2^Type2^ServiceType2,
 *            expiry date:  YYYYMMDD,
 *            type: @ref EN_MTC_CONF_CHARGE_TYPE(see @mtc_conf.h or MtcConfConstrants.java),
 *            ServiceType: @ref EN_MTC_CONF_SERVICE_TYPE(see @mtc_conf.h or MtcConfConstrants.java),
 *"iTotalLeftBalance" in @ref PFN_MTCCONFCBQUERYRESULT is the total left balance(minutes).
 *             If server not return value of the parameter, the value will be 0,
 *             then UI can sum up the left balance list in "pcResult"
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetQuery(PFN_MTCCONFCBQUERYRESULT pfnCb);

/**
 * @brief Set callback of query account failed.
 *
 * This client want to know result code of query account performed by @ref Mtc_ConfQueryAccount.
 *
 * "iRspCode" in @ref PFN_MTCCONFCBACCOUNTFAILED is responce status code.
 *              GUI use it to check the result.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ConfCbSetQueryFailed(PFN_MTCCONFCBACCOUNTFAILED pfnCb);

/**
 * @brief Set callback of indicate conference participant's video stream speak-state info updated.
 *
 * GUI should update conference participant's video stream speak-state info.
 * "iConfId" in @ref PFN_MTCCONFCBVIDEOSTRMPTPTUPDT is the id of conference.
 *          GUI use it to locate the conference window.
 * "iStrmId" in @ref PFN_MTCCONFCBVIDEOSTRMPTPTUPDT is the video stream id.
 *  "pcUri" is the number(not uri) of the participant.
 *  if the participant is speaking, the URI will be "Number:VOL", e.g. "+8616000000313:VOL".
 *  if the participant is not speaking, the URI will be "Number:SLI", e.g. "+8616000000313:SLI".
 *
 */
ZFUNC ZVOID Mtc_ConfCbSetVideoStrmSpkStateUpdt(PFN_MTCCONFCBVIDEOSTRMPTPTUPDT pfnCb); 

/**
 * @brief Set callback of indicate conference participant's video stream remove-window info updated.
 *
 * GUI should update conference participant's video stream remove-window info.
 * "iConfId" in @ref PFN_MTCCONFCBVIDEOSTRMPTPTUPDT is the id of conference.
 *          GUI use it to locate the conference window.
 * "iStrmId" in @ref PFN_MTCCONFCBVIDEOSTRMPTPTUPDT is the video stream id.
 *  "pcUri" is the number(not uri) of the participant.
 *  if the chairman whose number is +8616000000313 removed the window of the participant whose number is +8613800000000, 
 *  the URI will be "Number:KICK:+Number", e.g. "+8616000000313:KICK:+13800000000".
 *
 */
ZFUNC ZVOID Mtc_ConfCbSetVideoStrmRmvWinUpdt(PFN_MTCCONFCBVIDEOSTRMPTPTUPDT pfnCb); 

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CONF_CB_H__ */

