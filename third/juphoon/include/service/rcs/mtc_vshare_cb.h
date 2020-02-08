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
  File name     : mtc_vshare_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC call callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_VSHARE_CB_H__
#define _MTC_VSHARE_CB_H__

/**
 * @file MTC_VSHARE_cb.h
 * @brief MTC Call Callback Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC call callback. */
typedef ZVOID (*PFN_MTCVSHARECB)(ZUINT iSessId);

/** @brief Type define of MTC call callback for notify alerted. */
typedef ZVOID (*PFN_MTCVSHARECBALERTED)(ZUINT iSessId, ZUINT iAlertType);

/** @brief Type define of MTC call callback for notify terminated. */
typedef ZVOID (*PFN_MTCVSHARECBTERMED)(ZUINT iSessId, ZUINT iStatCode);

/** @brief Type define of MTC call callback for notify error. */
typedef ZVOID (*PFN_MTCVSHARECBERR)(ZUINT iSessId, ZUINT iStatCode);

/** @brief Type define of MTC call callback for video size change. */
typedef ZVOID (*PFN_MTCVSHARECBVIDEOSIZE)(ZUINT iSessId, ZUINT iWidth,
                ZUINT iHeight, ZUINT iOrientation);

/** @brief Type define of MTC call callback for capture size */
typedef ZVOID (*PFN_MTCVSHARECBCAPTURESIZE)(ZUINT iSessId, ZUINT iWidth,
                ZUINT iHeight);

/**
 * @brief Set callback of indicate received a new call.
 *
 * GUI use @ref MTC_VSHARE.h "MTC Session Interfaces", like 
 * @ref Mtc_SessGetPeerUri, to get detail information and present 
 * those to user. And wait for user action, accept or decline.
 * iSessId in @ref PFN_MTCVSHARECB is the ID of session. GUI should use it to get session
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
ZFUNC ZVOID Mtc_VShareCbSetIncoming(PFN_MTCVSHARECB pfnCb);

/**
 * @brief Set callback of indicate send a new call.
 *
 * GUI use @ref MTC_VSHARE.h "MTC Session Interfaces", like 
 * @ref Mtc_SessGetPeerUri, to get detail information and present 
 * those to user. And show a outgoing call window.
 * "iSessId" in @ref PFN_MTCVSHARECB is the ID of session. GUI should use it to get session
 *        status. 
 * - Use @ref Mtc_SessHasVideo to check if outgoing call has video request.
 *   - Has video, show video call window
 *   - No Video, show voice call window
 * - Get peer information by @ref Mtc_SessGetPeerUri.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_VShareCbSetOutgoing(PFN_MTCVSHARECB pfnCb);

/**
 * @brief Set callback of indicate the callee is ringing.
 *
 * GUI should update the status of outgoing call window
 * "iSessId" in @ref PFN_MTCVSHARECB is the ID of session. GUI should use it to locate
 * call window.
 * - Use @ref Mtc_SessGetEarlyMediaStatus and @ref Mtc_SessHasVideo to check 
 *   if there is a video early media. If so, use @ref Mtc_SessHasOfferAnswer
 *   to check if offer answer exchanged is completed. If so, GUI should
 *   invoke @ref Mtc_SessVideoStart to start receive video early media.
 *
 * "iAlertType" in @ref PFN_MTCVSHARECBALERTED has below values:
 * - MTC_VSHARE_ALERT_RING Alerted by 180 ringing.
 * - MTC_VSHARE_ALERT_QUEUE Alerted by 182 queued.
 * - MTC_VSHARE_ALERT_PROGRESS Alerted by 183 session progress.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_VShareCbSetAlerted(PFN_MTCVSHARECBALERTED pfnCb);


/**
 * @brief Set callback of indicate the call has established.
 *
 * The call can be a received call or a send out call. GUI should switch 
 * to talking window.
 * "iSessId" in @ref PFN_MTCVSHARECB is the ID of session. GUI should use it to locate
 * call window.
 * - Use @ref Mtc_SessHasVideo to check if there is a video media. 
 *   If so, GUI should invoke @ref Mtc_SessVideoStart to start send and
 *   receive video media.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_VShareCbSetTalking(PFN_MTCVSHARECB pfnCb);

/**
 * @brief Set callback of indicate call is terminated.
 *
 * "iStatCode" in @ref PFN_MTCVSHARECBTERMED has below values.
 * - MTC_VSHARE_TERM_BYE Terminated by remote BYE
 * - MTC_VSHARE_TERM_CANCEL Terminated by remote CANCEL
 * - MTC_VSHARE_TERM_BUSY Terminated by 486 Busy Here
 * - MTC_VSHARE_TERM_DECLINE Terminated by 603 Decline
 * - MTC_VSHARE_ERR_FORBIDDEN Terminated by 403 Forbidden
 * - MTC_VSHARE_ERR_NOT_FOUND Terminated by 404 Not Found
 * - MTC_VSHARE_ERR_NOT_ACPTED Terminated by 406 Not Acceptable or 488 Not Acceptable Here
 * - MTC_VSHARE_ERR_REQ_TERMED Terminated by 487 Request Terminated
 * - MTC_VSHARE_ERR_INTERNAL_ERR Terminated by 500 Server Internal Error
 * - MTC_VSHARE_ERR_SRV_UNAVAIL Terminated by 503 Service Unavailable
 * - MTC_VSHARE_ERR_NOT_EXIST Terminated by 604 Does Not Exist Anywhere
 * The call can be a received call or a send out call. GUI should show 
 * the reason why the call was terminated for a few seconds, and switch to
 * main working window.
 * "iSessId" in @ref PFN_MTCVSHARECBTERMED is the ID of session. GUI should use it to locate
 * call window.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_VShareCbSetTermed(PFN_MTCVSHARECBTERMED pfnCb);

/**
 * @brief Set callback of indicate video share's video size changed.
 *
 * This callback indicates the video share's video size changed.
 * "iSessId" in @ref PFN_MTCVSHARECBVIDEOSIZE is the ID of session.
 * GUI should use it to locate call window.
 * "iWidth" in @ref PFN_MTCVSHARECBVIDEOSIZE indicate the width of frame.
 * "iHeight" in @ref PFN_MTCVSHARECBVIDEOSIZE indicate the height of frame.
 * "iOrientation" in @ref PFN_MTCVSHARECBVIDEOSIZE indicate the orientation.
 * @ref EN_MTC_ORIENTATION_TYPE
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_VShareCbSetVideoSize(PFN_MTCVSHARECBVIDEOSIZE pfnCb);

/**
 * @brief Set callback of indicate capture size.
 *
 * This callback indicates the capture size.
 * "iSessId" in @ref PFN_MTCVSHARECBCAPTURESIZE is the ID of session.
 * GUI should use it to locate call window.
 * "iWidth" in @ref PFN_MTCVSHARECBCAPTURESIZE indicate capture width.
 * "iHeight" in @ref PFN_MTCVSHARECBCAPTURESIZE indicate capture height.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_VShareCbSetCaptureSize(PFN_MTCVSHARECBCAPTURESIZE pfnCb);

/**
 * @brief Set callback of indicate call error.
 *
 * This callback indicates error occured during call. GUI should show
 * the detail error information to user.
 * "iSessId" in @ref PFN_MTCVSHARECBERR is the ID of the session which occurs error.
 * "iStatCode" in @ref PFN_MTCVSHARECBERR is the error code(see MSF_STAT_ERR_NO), it can be
 * - If iStatCode < 0x1000, contains SIP response status code, use
 *      Sip_ReasonFromCode to get description string
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_VShareCbSetError(PFN_MTCVSHARECBERR pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_VSHARE_CB_H__ */

