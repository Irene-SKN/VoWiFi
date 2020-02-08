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
  File name     : mtc_call_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC call callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CALL_CB_H__
#define _MTC_CALL_CB_H__

/**
 * @file mtc_call_cb.h
 * @brief MTC Call Callback Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC call callback. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCB)(ZUINT iSessId);
#else
typedef ZVOID (*PFN_MTCCALLCB)(ZUINT iSessId);
#endif

/** @brief Type define of MTC call callback for notify alerted. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBALERTED)(ZUINT iSessId, ZUINT iAlertType);
#else
typedef ZVOID (*PFN_MTCCALLCBALERTED)(ZUINT iSessId, ZUINT iAlertType);
#endif

/** @brief Type define of MTC call callback for notify terminated. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBTERMED)(ZUINT iSessId, ZUINT iStatCode);
#else
typedef ZVOID (*PFN_MTCCALLCBTERMED)(ZUINT iSessId, ZUINT iStatCode);
#endif

/** @brief Type define of MTC call callback for notify replaced. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBREPLACED)(ZUINT iSessId);
#else
typedef ZVOID (*PFN_MTCCALLCBREPLACED)(ZUINT iSessId);
#endif

/** @brief Type define of MTC call callback for notify receive info. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBINFO)(ZUINT iSessId, ZCHAR *pcInfo);
#else
typedef ZVOID (*PFN_MTCCALLCBINFO)(ZUINT iSessId, ZCHAR *pcInfo);
#endif

/** @brief Type define of MTC call callback for notify receive info. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBINFOX)(ZCHAR *pcUri, ZCHAR *pcInfo);
#else
typedef ZVOID (*PFN_MTCCALLCBINFOX)(ZCHAR *pcUri, ZCHAR *pcInfo);
#endif

/** @brief Type define of MTC call callback for notify error. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBERR)(ZUINT iSessId, ZUINT iStatCode);
#else
typedef ZVOID (*PFN_MTCCALLCBERR)(ZUINT iSessId, ZUINT iStatCode);
#endif

/** @brief Type define of MTC call callback for video status change. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBVIDEOSTATUS)(ZUINT iSessId, ZUINT iParm1,
                ZUINT iParm2);
#else
typedef ZVOID (*PFN_MTCCALLCBVIDEOSTATUS)(ZUINT iSessId, ZUINT iParm1,
                ZUINT iParm2);
#endif

/** @brief Type define of MTC call callback for video size change. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBVIDEOSIZE)(ZUINT iSessId, ZUINT iWidth,
                ZUINT iHeight, ZINT iOrientation);
#else
typedef ZVOID (*PFN_MTCCALLCBVIDEOSIZE)(ZUINT iSessId, ZUINT iWidth,
                ZUINT iHeight, ZINT iOrientation);
#endif

/** @brief Type define of MTC call callback for capture */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBCAPTURE)(ZUINT iSessId, ZUINT iParm);
#else
typedef ZVOID (*PFN_MTCCALLCBCAPTURE)(ZUINT iSessId, ZUINT iParm);
#endif

/** @brief Type define of MTC call callback for capture size */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBCAPTURESIZE)(ZUINT iSessId, ZUINT iWidth,
                ZUINT iHeight);
#else
typedef ZVOID (*PFN_MTCCALLCBCAPTURESIZE)(ZUINT iSessId, ZUINT iWidth,
                ZUINT iHeight);
#endif

/** @brief Type define of MTC call callback for network status changed */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBNETSTATUSCHANGED)(ZUINT iSessId, 
                ZBOOL bVideo, ZBOOL bSend, ZINT iType);
#else
typedef ZVOID (*PFN_MTCCALLCBNETSTATUSCHANGED)(ZUINT iSessId, 
                ZBOOL bVideo, ZBOOL bSend, ZINT iType);
#endif

/** @brief Type define of MTC call callback for rtp connectivity */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBRTPCONNECTIVITY)(ZUINT iSessId, ZBOOL bConnected);
#else
typedef ZVOID (*PFN_MTCCALLCBRTPCONNECTIVITY)(ZUINT iSessId, ZBOOL bConnected);
#endif

/** @brief Type define of MTC session callback for notify participant updated. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBPARTPUPDTED)(ZUINT iSessId, ZCHAR *pcUri, 
                ZUINT iState);
#else
typedef ZVOID (*PFN_MTCCALLCBPARTPUPDTED)(ZUINT iSessId, ZCHAR *pcUri, 
                ZUINT iState);
#endif

/** @brief Type define of MTC call callback for crypto status change. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBCRYPTOSTACHANGED)(ZUINT iSessId, ZUINT iStateType,
                ZBOOL bVideo);
#else
typedef ZVOID (*PFN_MTCCALLCBCRYPTOSTACHANGED)(ZUINT iSessId, ZUINT iStateType,
                ZBOOL bVideo);
#endif

/** @brief Type define of MTC call callback for recving rtp packet  */
typedef ZVOID (*PFN_MTCCALLCBRECVRTPPACKET)(ZUINT iStrmId, ZBOOL bVideo,
                ZCHAR *pcData, ZUINT iLen);

/** @brief Type define of MTC call callback for sending rtp packet  */
typedef ZVOID (*PFN_MTCCALLCBSENDRTPPACKET)(ZUINT iTptId, ZCHAR *pcRmtAddr,
                ZCHAR *pcData, ZUINT iLen);

/** @brief Type define of MTC call callback for stream file play stoopedx. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBFILEPLAYSTOPPEDX)(ZUINT iSessId);
#else
typedef ZVOID (*PFN_MTCCALLCBFILEPLAYSTOPPEDX)(ZUINT iSessId);
#endif

/** @brief Type define of MTC subscription callback for subscription ok . */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCSUBSOK)(ZUINT iSubsId);
#else
typedef ZVOID (*PFN_MTCSUBSOK)(ZUINT iSubsId);
#endif

/** @brief Type define of MTC subscription callback for subscription failed . */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCSUBSFAILED)(ZUINT iSubsId, ZUINT iStatCode);
#else
typedef ZVOID (*PFN_MTCSUBSFAILED)(ZUINT iSubsId, ZUINT iStatCode);
#endif

/** @brief Type define of MTC call callback for notify receive subs info. */
#if (ZPLATFORM == ZPLATFORM_WIN32)
typedef ZVOID (__stdcall *PFN_MTCCALLCBSUBSINFO)(ZUINT iSubsId, ZCHAR *pcInfo);
#else
typedef ZVOID (*PFN_MTCCALLCBSUBSINFO)(ZUINT iSubsId, ZCHAR *pcInfo);
#endif

/**
 * @brief Set callback of indicate received a new call.
 *
 * GUI use @ref mtc_call.h "MTC Session Interfaces", like 
 * @ref Mtc_SessGetPeerUri, to get detail information and present 
 * those to user. And wait for user action, accept or decline.
 * iSessId in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to get session
 *        status. 
 * - Use @ref Mtc_SessPeerOfferVideo to check if incoming call has video request.
 *   - Has video, show video call alert window with 3 options
 *     - accept
 *     - accept with video
 *     - decline
 *   - No Video, show voice call alert window with 2 options
 *     - accept
 *     - decline
 * - Assign iSessId to alert window. It will be used when invoke
 *   @ref Mtc_SessAnswer or @ref Mtc_SessTerm.
 * - Get peer information by @ref Mtc_SessGetPeerUri.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetIncoming(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate send a new call.
 *
 * GUI use @ref mtc_call.h "MTC Session Interfaces", like 
 * @ref Mtc_SessGetPeerUri, to get detail information and present 
 * those to user. And show a outgoing call window.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to get session
 *        status. 
 * - Use @ref Mtc_SessHasVideo to check if outgoing call has video request.
 *   - Has video, show video call window
 *   - No Video, show voice call window
 * - Get peer information by @ref Mtc_SessGetPeerUri.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetOutgoing(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate the callee is ringing.
 *
 * GUI should update the status of outgoing call window
 * "iSessId" in @ref PFN_MTCCALLCBALERTED is the ID of session.
 * GUI should use it to locate call window.
 * - Use @ref Mtc_SessGetEarlyMediaStatus and @ref Mtc_SessHasVideo to check 
 *   if there is a video early media. If so, use @ref Mtc_SessHasOfferAnswer
 *   to check if offer answer exchanged is completed. If so, GUI should
 *   invoke @ref Mtc_SessVideoStart to start receive video early media.
 *
 * "iAlertType" in @ref PFN_MTCCALLCBALERTED has below values:
 * - MTC_CALL_ALERT_RING Alerted by 180 ringing.
 * - MTC_CALL_ALERT_QUEUE Alerted by 182 queued.
 * - MTC_CALL_ALERT_PROGRESS Alerted by 183 session progress.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAlerted(PFN_MTCCALLCBALERTED pfnCb);

/**
 * @brief Set callback of indicate the call is forwarded.
 *
 * GUI should update the status of outgoing call window
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it 
 * to locate call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetForwarded(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate the callee receive prack.
 *
 * GUI may use reliable provision response to check if peer is still alive.
 * If do so, GUI should show a incoming call view in this callback instead
 * incoming callback. GUI should update the status of outgoing call window.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetPracked(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate the call has established.
 *
 * The call can be a received call or a send out call. GUI should switch 
 * to talking window.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 * - Use @ref Mtc_SessHasVideo to check if there is a video media. 
 *   If so, GUI should invoke @ref Mtc_SessVideoStart to start send and
 *   receive video media.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetTalking(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call is terminated.
 *
 * "iStatCode" in @ref PFN_MTCCALLCBTERMED has below values.
 * - @ref MTC_CALL_TERM_BYE Terminated by remote BYE
 * - @ref MTC_CALL_TERM_CANCEL Terminated by remote CANCEL
 * - @ref MTC_CALL_TERM_BUSY Terminated by 486 Busy Here
 * - @ref MTC_CALL_TERM_DECLINE Terminated by 603 Decline
 * - @ref MTC_CALL_ERR_FORBIDDEN Terminated by 403 Forbidden
 * - @ref MTC_CALL_ERR_NOT_FOUND Terminated by 404 Not Found
 * - @ref MTC_CALL_ERR_NOT_ACPTED Terminated by 406 Not Acceptable or 488 Not Acceptable Here
 * - @ref MTC_CALL_ERR_REQ_TERMED Terminated by 487 Request Terminated
 * - @ref MTC_CALL_ERR_INTERNAL_ERR Terminated by 500 Server Internal Error
 * - @ref MTC_CALL_ERR_SRV_UNAVAIL Terminated by 503 Service Unavailable
 * - @ref MTC_CALL_ERR_NOT_EXIST Terminated by 604 Does Not Exist Anywhere
 * The call can be a received call or a send out call. GUI should show 
 * the reason why the call was terminated for a few seconds, and switch to
 * main working window.
 * "iSessId" in @ref PFN_MTCCALLCBTERMED is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetTermed(PFN_MTCCALLCBTERMED pfnCb);

/**
 * @brief Set callback of indicate call modifying accepted.
 *
 * To change the attribute of media stream is called call modify, includes
 * hold and add or remove media stream. This callback indicates the 
 * modification is accept by peer. GUI should check which service has
 * been invoke by user. If user hold or un-hold the call, show hold or
 * un-hold successfully. If user add video upon a voice call, then switch
 * to video call window.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetMdfyAcpt(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call modifyed.
 *
 * This callback indicates modification was invoke by peer, and this 
 * modification is completed. GUI use @ref mtc_call.h 
 * "MTC Session Interfaces", like @ref Mtc_SessHasVideo, check media status.
 * And then show corresponding changes.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetMdfyed(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call modify request.
 *
 * This callback indicates modification was invoke by peer, and this 
 * modification is waiting for user's confirm. GUI use @ref mtc_call.h 
 * "MTC Session Interfaces", like @ref Mtc_SessHasAudio and
 * @ref Mtc_SessHasVideo, to check media status and make a decision whether
 * accept one or all of active these streams.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetMdfyReq(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call hold successfully.
 *
 * This callback indicates hold operation has been completed successfully.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetHoldOk(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call hold failed.
 *
 * This callback indicates hold operation has been failed.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetHoldFailed(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call un-hold successfully.
 *
 * This callback indicates un-hold operation has been completed successfully.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetUnHoldOk(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call un-hold failed.
 *
 * This callback indicates un-hold operation has been failed.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetUnHoldFailed(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call was held by peer.
 *
 * This callback indicates peer hold the call.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetHeld(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call was un-held by peer.
 *
 * This callback indicates un-held hold the call.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetUnHeld(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate adding voice stream has been 
 *  completed successfully.
 *
 * This callback indicates the operation of adding voice stream 
 * to the call has been completed successfully.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAddAudioOk(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate adding voice stream failed.
 *
 * This callback indicates failed to add voice stream to the call.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAddAudioFailed(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate removing voice stream has been 
 *  completed successfully.
 *
 * This callback indicates the operation of removing voice stream 
 * of the call has been completed successfully.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetRmvAudioOk(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate removing voice stream has been failed.
 *
 * This callback indicates failed to remove voice stream of the call.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetRmvAudioFailed(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate receiving request of adding voice stream.
 *
 * This callback indicates receiving request of adding voice stream
 * which was invoked by peer. GUI should show a message box to inform
 * user this information, and wait for user to accept or reject this requst.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAddAudioReq(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate cancel request of adding voice stream.
 *
 * This callback indicates cancel request of adding voice stream
 * which was invoked by peer. GUI should cancel showed message box.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAddAudioCancel(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate adding video stream has been 
 *  completed successfully.
 *
 * This callback indicates the operation of adding video stream 
 * to the call has been completed successfully.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAddVideoOk(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate adding video stream has been failed.
 *
 * This callback indicates failed to add video stream to the call.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCBTERMED is the ID of session. GUI should use it to locate
 * call window.
 *
 * "iStatCode" in @ref PFN_MTCCALLCBTERMED has below values.
 * - @ref MTC_CALL_ERR_REJECTED Failed by remote rejected
 * - @ref MTC_CALL_ERR_NETWORK Failed by network disconnected
 * - @ref MTC_CALL_ERR_TIMEOUT Failed by timeout for request
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAddVideoFailed(PFN_MTCCALLCBTERMED pfnCb);

/**
 * @brief Set callback of indicate removing video stream has been 
 *  completed successfully.
 *
 * This callback indicates the operation of removing video stream 
 * of the call has been completed successfully.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetRmvVideoOk(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate removing video stream has been failed.
 *
 * This callback indicates failed to remove video stream of the call.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCBTERMED is the ID of session. GUI should use it to locate
 * call window.
 *
 * "iStatCode" in @ref PFN_MTCCALLCBTERMED has below values.
 * - @ref MTC_CALL_ERR_REJECTED Failed by remote rejected
 * - @ref MTC_CALL_ERR_NETWORK Failed by network disconnected
 * - @ref MTC_CALL_ERR_TIMEOUT Failed by timeout for request
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetRmvVideoFailed(PFN_MTCCALLCBTERMED pfnCb);

/**
 * @brief Set callback of indicate receiving request of adding video stream.
 *
 * This callback indicates receiving request of adding video stream
 * which was invoked by peer. GUI should show a message box to inform
 * user this information, and wait for user to accept or reject this requst.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAddVideoReq(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate cancel request of adding video stream.
 *
 * This callback indicates cancel request of adding video stream
 * which was invoked by peer. GUI should cancel showed message box.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetAddVideoCancel(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call refered.
 *
 * This callback indicates the session is transfered by peer to a new
 * destination. The new session will be indicated by callback 
 * which was set by @ref Mtc_CallCbSetOutgoing.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetRefered(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call transferred accepted.
 *
 * This callback indicates receiving a transfer request. GUI should show
 * a dialog to inform user, current call was transfered.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetTrsfAcpt(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call transferred terminated.
 *
 * For extension.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetTrsfTerm(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call transferred failed.
 *
 * This callback indicates transfer failed. GUI should show
 * a dialog to inform user, current call was transfered.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetTrsfFailed(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call redirected.
 *
 * This callback indicates the outgoing call was forwarded to another
 * number. GUI should update call status.
 * "iSessId" in @ref PFN_MTCCALLCBREPLACED is the ID of session.
 * GUI should use it to locate call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetRedirected(PFN_MTCCALLCBREPLACED pfnCb);

/**
 * @brief Set callback of indicate call replaced.
 *
 * This callback indicates the call has replaced by another call, which
 * should happen when previous call was transfered to another peer. GUI
 * should update the peer information.
 * "iSessId" in @ref PFN_MTCCALLCBREPLACED is the ID of session replaced, 
 * GUI should use it to locate call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetReplaced(PFN_MTCCALLCBREPLACED pfnCb);

/**
 * @brief Set callback of indicate call replace ok.
 *
 * This callback indicates the call has replace ok by another call, which
 * should happen when previous call was transfered to another peer. GUI
 * should update the peer information.
 * "iSessId" in @ref PFN_MTCCALLCBREPLACED is the ID of session replace ok, 
 * GUI should use it to locate call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetReplaceOk(PFN_MTCCALLCBREPLACED pfnCb);

/**
 * @brief Set callback of indicate call replace failed.
 *
 * This callback indicates the call has replace failed by another call, which
 * should happen when previous call was transfered to another peer. GUI
 * should update the peer information.
 * "iSessId" in @ref PFN_MTCCALLCBREPLACED is the ID of session replace failed, 
 * GUI should use it to locate call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetReplaceFailed(PFN_MTCCALLCBREPLACED pfnCb);

/**
 * @brief Set callback of indicate receive info.
 *
 * This callback indicates the call has received info message. GUI
 * should update the INFO information.
 * "iSessId" in @ref PFN_MTCCALLCBINFO is the ID of session replaced, 
 * GUI should use it to locate call window.
 * "pcInfo" is the info string. 
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetInfo(PFN_MTCCALLCBINFO pfnCb);

/**
 * @brief Set callback of indicate receive info.
 *
 * This callback indicates the call has received info message
 * "iSessId" in @ref PFN_MTCCALLCBINFOX is the ID of session, 
 * GUI should use it to locate call window.
 * "pcUri" is the URI(SIP or TEL URI) info where the message from.
 * "pcInfo" is the info string. 
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetInfoX(PFN_MTCCALLCBINFOX pfnCb);

/**
 * @brief Set callback of indicate rtp connectivity.
 *
 * This callback indicates the RTP connectivity status is changed.
 *
 * "iSessId" in @ref PFN_MTCCALLCBRTPCONNECTIVITY is the ID of session, 
 * GUI should use it to locate call window.
 *
 * When "bConned" in @ref PFN_MTCCALLCBRTPCONNECTIVITY is ZTRUE indicate media
 * engine detected RTP packet received, ZFALSE indicate media engine hasn't
 * detected RTP packet received for about 20 seconds.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetRtpConnectivity(PFN_MTCCALLCBRTPCONNECTIVITY pfnCb);

/**
 * @brief Set callback of indicate call replaced.
 *
 * This callback indicates the camera has disconnected with this call.
 * "iSessId" in @ref PFN_MTCCALLCB is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetCamDisconned(PFN_MTCCALLCB pfnCb);

/**
 * @brief Set callback of indicate call's video size changed.
 *
 * This callback indicates the call's video size changed.
 * "iSessId" in @ref PFN_MTCCALLCBVIDEOSTATUS is the ID of session.
 * GUI should use it to locate call window.
 * "iWidth" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the width of frame.
 * "iHeight" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the height of frame.
 * "iOrientation" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the orientation.
 * @ref EN_MTC_ORIENTATION_TYPE
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetVideoSize(PFN_MTCCALLCBVIDEOSIZE pfnCb);

/**
 * @brief Set callback of indicate call's network status.
 *
 * This callback indicates the call's network status.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCBNETSTATUSCHANGED is the ID of session. GUI should 
 * use it to locate call window.
 * "bVideo" in @ref PFN_MTCCALLCBNETSTATUSCHANGED indicate if the network
 * status of video stream is changed.
 * "bSend" in @ref PFN_MTCCALLCBNETSTATUSCHANGED indicate if the network
 * status of sending direction is changed.
 * "iType" in @ref PFN_MTCCALLCBNETSTATUSCHANGED indicate the network status
 * type @ref EN_MTC_NET_STATUS_TYPE.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetNetStaChanged(PFN_MTCCALLCBNETSTATUSCHANGED pfnCb);

/**
 * @brief Set callback of indicate call's video incoming status.
 *
 * This callback indicates the call's video incoming status.
 * "iSessId" in @ref PFN_MTCCALLCBVIDEOSTATUS is the ID of session.
 * GUI should use it to locate call window.
 * "iParm1" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the framerate.
 * "iParm2" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the bitrate.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetVideoIncomingSta(PFN_MTCCALLCBVIDEOSTATUS pfnCb);

/**
 * @brief Set callback of indicate call's video outgoing status.
 *
 * This callback indicates the call's video outgoing status.
 * "iSessId" in @ref PFN_MTCCALLCBVIDEOSTATUS is the ID of session.
 * GUI should use it to locate call window.
 * "iParm1" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the framerate.
 * "iParm2" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the bitrate.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetVideoOutgoingSta(PFN_MTCCALLCBVIDEOSTATUS pfnCb);

/**
 * @brief Set callback of indicate call's video protection status.
 *
 * This callback indicates the call's video protection status.
 * "iSessId" in @ref PFN_MTCCALLCBVIDEOSTATUS is the ID of session.
 * GUI should use it to locate call window.
 * "iParm1" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the FEC bitrate in kbps.
 * "iParm2" in @ref PFN_MTCCALLCBVIDEOSTATUS indicate the NACK bitrate in kbps.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetVideoProtectSta(PFN_MTCCALLCBVIDEOSTATUS pfnCb);

/**
 * @brief Set callback of indicate capture framerate.
 *
 * This callback indicates the capture statistics.
 * "iSessId" in @ref PFN_MTCCALLCBCAPTURE is the ID of session.
 * GUI should use it to locate call window.
 * "iParm" in @ref PFN_MTCCALLCBCAPTURE indicate the framerate.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetCaptureFramerate(PFN_MTCCALLCBCAPTURE pfnCb);

/**
 * @brief Set callback of indicate capture framerate.
 *
 * This callback indicates the capture size.
 * "iSessId" in @ref PFN_MTCCALLCBCAPTURESIZE is the ID of session.
 * GUI should use it to locate call window.
 * "iWidth" in @ref PFN_MTCCALLCBCAPTURESIZE indicate capture width.
 * "iHeight" in @ref PFN_MTCCALLCBCAPTURESIZE indicate capture height.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetCaptureSize(PFN_MTCCALLCBCAPTURESIZE pfnCb);

/**
 * @brief Set callback of indicate session participant's status updated.
 *
 * GUI should update session participant's status.
 * "iSessId" in @ref PFN_MTCCALLCBPARTPUPDTED is the ID of session. GUI should use it to locate
 *        call window.
 * "pcUri" in @ref PFN_MTCCALLCBPARTPUPDTED is the URI of the participant which status has been updated.
 * "iState" in @ref PFN_MTCCALLCBPARTPUPDTED see below values:
 * -EN_MTC_SESS_PARTP_STATE_PENDING Unconfirmed state
 * -EN_MTC_SESS_PARTP_STATE_DIALINGIN Creating or join a session
 * -EN_MTC_SESS_PARTP_STATE_DIALINGOUT Being invited to a session
 * -EN_MTC_SESS_PARTP_STATE_ALERTING Being invited and is alerting
 * -EN_MTC_SESS_PARTP_STATE_CONNED Attend to a session successfully
 * -EN_MTC_SESS_PARTP_STATE_ONHOLD In hold state
 * -EN_MTC_SESS_PARTP_STATE_DISCING Leaving a session
 * -EN_MTC_SESS_PARTP_STATE_DISCED Already leave a session
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetPartpUpdted(PFN_MTCCALLCBPARTPUPDTED pfnCb); 

/**
 * @brief Set callback of indicate file play stoppedx.
 *
 * This callback indicates the capture size.
 * "iSessId" in @ref PFN_MTCCALLCBFILEPLAYSTOPPEDX is the ID of session.
 * GUI should use it to locate call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetFilePlayStoppedx(PFN_MTCCALLCBFILEPLAYSTOPPEDX pfnCb);

/**
 * @brief Set callback of indicate call error.
 *
 * This callback indicates error occured during call. GUI should show
 * the detail error information to user.
 * "iSessId" in @ref PFN_MTCCALLCBERR is the ID of the session which occurs error.
 * "iStatCode" in @ref PFN_MTCCALLCBERR is the error code(see MSF_STAT_ERR_NO), it can be
 * - If iStatCode < 0x1000, contains SIP response status code, use
 *      Sip_ReasonFromCode to get description string
 * - Otherwise, use @ref Mtc_SessGetStatDesc to get description string
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetError(PFN_MTCCALLCBERR pfnCb);

/**
 * @brief Set callback of indicate call's crypto status.
 *
 * This callback indicates the call's crypto status.
 * GUI should update session status according to session ID.
 * "iSessId" in @ref PFN_MTCCALLCBCRYPTOSTACHANGED is the ID of session. GUI should 
 * use it to locate call window.
 * "iStateType" in @ref PFN_MTCCALLCBCRYPTOSTACHANGED indicate the crypto status
 * type @ref EN_MTC_SESS_CRYPTO_STATE_TYPE.
 * "bVideo" in @ref PFN_MTCCALLCBCRYPTOSTACHANGED indicate if the crypto
 * status of video stream is changed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetCryptoStaChanged(PFN_MTCCALLCBCRYPTOSTACHANGED pfnCb);

/**
 * @brief Set callback of indicate receiving a rtp packtet.
 *
 * This callback indicates receiving a RTP packtet.
 *
 * "iStrmId" in @ref PFN_MTCCALLCBRECVRTPPACKET is the ID of stream(audio or video).
 *
 * "bVideo" in @ref PFN_MTCCALLCBRECVRTPPACKET is ZTRUE indicates RTP packet 
 * is video packet, ZFALSE indicate the rtp packet is audio packet.
 *
 * "pcData" in @ref PFN_MTCCALLCBRECVRTPPACKET is the RTP packet data.
 *
 * "iLen" in @ref PFN_MTCCALLCBRECVRTPPACKET is the RTP packet data length.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetRecvRtpPacket(PFN_MTCCALLCBRECVRTPPACKET pfnCb);

/**
 * @brief Set callback of indicate sending a rtp packtet.
 *
 * This callback indicates sending a  RTP packtet report.
 *
 * "iTptId" in @ref PFN_MTCCALLCBSENDRTPPACKET is the ID of transport id.
 *
 * "pcRmtAddr" in @ref PFN_MTCCALLCBSENDRTPPACKET indicates RTP packet 
 * will be sent the the remote addr
 *
 * "pcData" in @ref PFN_MTCCALLCBSENDRTPPACKET is the RTP packet data.
 *
 * "iLen" in @ref PFN_MTCCALLCBSENDRTPPACKET is the RTP packet data length.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetSendRtpPacket(PFN_MTCCALLCBSENDRTPPACKET pfnCb);

/**
 * @brief Set callback of indicate receive info.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbAddInfo(PFN_MTCCALLCBINFO pfnCb);

/**
 * @brief remove callback of indicate receive info.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbRmvInfo(PFN_MTCCALLCBINFO pfnCb);


/**
 * @brief Set callback of indicate subscription ok.
 *
 * This callback indicates the subscription ok.
 * "iSubsId" in @ref PFN_MTCSUBSOK is the ID of subscription.
 * GUI should use it to locate call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetSubsOk(PFN_MTCSUBSOK pfnCb);

/**
 * @brief Set callback of indicate subscription failed.
 *
 * This callback indicates the subscription failed.
 * "iSubsId" in @ref PFN_MTCSUBSFAILED is the ID of subscription.
  * "iStatCode" in @ref PFN_MTCCALLCBERR is the error code(see MSF_STAT_ERR_NO), it can be
 * - If iStatCode < 0x1000, contains SIP response status code, use
 *      Sip_ReasonFromCode to get description string
 * - Otherwise, use @ref Mtc_SessGetStatDesc to get description string
 *
 * GUI should use it to locate call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetSubsFailed(PFN_MTCSUBSFAILED pfnCb);

/**
 * @brief Set callback of indicate receive subs info.
 *
 * This callback indicates the call has received subs info message. GUI
 * should update the subscription info information.
 * "iSubsId" in @ref PFN_MTCCALLCBSUBSINFO is the ID of subscription, 
 * GUI should use it to locate call window.
 * "pcInfo" is the subs info string. 
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_CallCbSetSubsInfo(PFN_MTCCALLCBSUBSINFO pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CALL_CB_H__ */

