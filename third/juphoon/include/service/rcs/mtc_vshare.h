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
  File name     : mtc_vshare.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC video share

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_VSHARE_H_
#define _MTC_VSHARE_H_

/**
 * @file mtc_vshare.h
 * @brief MTC video share Interface Functions
 *
 * This file includes video share interface function. Those function is used to manage video shares.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC call status code(error no or terminated code). */
#define MTC_VSHARE_ERR_NO               (MTC_EBASE_VSHARE + 0) /**< @brief no error. */
#define MTC_VSHARE_ERR_AUTH_FAILED      (MTC_EBASE_VSHARE + 1) /**< @brief authentication failed, invalid user or password. */
#define MTC_VSHARE_ERR_SESS_TMR         (MTC_EBASE_VSHARE + 2) /**< @brief call refresh error. */
#define MTC_VSHARE_ERR_FORBIDDEN        (MTC_EBASE_VSHARE + 3) /**< @brief call forbidden. */
#define MTC_VSHARE_ERR_NOT_FOUND        (MTC_EBASE_VSHARE + 4) /**< @brief call participant not found. */
#define MTC_VSHARE_ERR_NOT_ACPTED       (MTC_EBASE_VSHARE + 5) /**< @brief call not accepted. */
#define MTC_VSHARE_ERR_TEMP_UNAVAIL     (MTC_EBASE_VSHARE + 6) /**< @brief call participant temp unavailable. */
#define MTC_VSHARE_ERR_REQ_TERMED       (MTC_EBASE_VSHARE + 7) /**< @brief call request terminated. */
#define MTC_VSHARE_ERR_INTERNAL_ERR     (MTC_EBASE_VSHARE + 8) /**< @brief server internal error. */
#define MTC_VSHARE_ERR_SRV_UNAVAIL      (MTC_EBASE_VSHARE + 9) /**< @brief service unavailable. */
#define MTC_VSHARE_ERR_NOT_EXIST        (MTC_EBASE_VSHARE + 10) /**< @brief not exist. */
#define MTC_VSHARE_ERR_OTHER            (MTC_EBASE_VSHARE + 11) /**< @brief other error. */

#define MTC_VSHARE_TERM_BYE             (MTC_EBASE_VSHARE + 21) /**< @brief Terminated by bye. */
#define MTC_VSHARE_TERM_CANCEL          (MTC_EBASE_VSHARE + 22) /**< @brief Terminated by cancel. */
#define MTC_VSHARE_TERM_TIMEOUT         (MTC_EBASE_VSHARE + 23) /**< @brief Terminated by timeout. */
#define MTC_VSHARE_TERM_BUSY            (MTC_EBASE_VSHARE + 24) /**< @brief Terminated by busy. */
#define MTC_VSHARE_TERM_DECLINE         (MTC_EBASE_VSHARE + 25) /**< @brief Terminated by decline. */
#define MTC_VSHARE_TERM_TRSFED          (MTC_EBASE_VSHARE + 26) /**< @brief Terminated by transfered. */
#define MTC_VSHARE_TERM_REDIRECT        (MTC_EBASE_VSHARE + 27) /**< @brief Terminated by redirect. */

#define MTC_VSHARE_ALERT_RING           (MTC_EBASE_VSHARE + 41) /**< @brief Alerted by 180. */
#define MTC_VSHARE_ALERT_QUEUED         (MTC_EBASE_VSHARE + 42) /**< @brief Alerted by 182. */
#define MTC_VSHARE_ALERT_PROGRESS       (MTC_EBASE_VSHARE + 43) /**< @brief Alerted by 183. */

/** @brief MTC video share terminate reason type */
typedef enum EN_MTC_VSHARE_TERM_REASON_TYPE
{
    EN_MTC_VSHARE_TERM_REASON_NORMAL, /**< @brief normal session term, bye or cancel */
    EN_MTC_VSHARE_TERM_REASON_BUSY,  /**< @brief the session is rejected */
    EN_MTC_VSHARE_TERM_REASON_DECLINE, /**< @brief decline the session */
    EN_MTC_VSHARE_TERM_REASON_NOT_AVAILABLE, /**< @brief the user is not available */
} EN_MTC_VSHARE_TERM_REASON_TYPE;

/** 
 * @brief MTC video share session call.
 *
 * If send a new call and the callee answered, GUI will be notified by callback which 
 * was set by @ref Mtc_VShareCbSetAlerted, @ref Mtc_VShareCbSetTalking
 *
 * If send a new call and the callee redirected, GUI will be notified by callback which 
 * was set by @ref Mtc_VShareCbSetOutgoing, @ref Mtc_VShareCbSetAlerted, @ref Mtc_VShareCbSetTalking
 *
 * If send a new call and the callee do not answered(timeout, busy now, etc.), GUI will be 
 * notified by callback which was set by @ref Mtc_VShareCbSetAlerted, @ref Mtc_VShareCbSetTermed
 *
 * While receiving call invitation, GUI will be notified by callback which 
 * was set by @ref Mtc_VShareCbSetIncoming.
 *
 * @param [in] pcUri The destination URI to which you want to make a video share session call.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by @ref Mtc_VSessGetCookie or reset by
 *                      @ref Mtc_VSessSetCookie at any time of session's life.
 *
 * @return The id of this new created session on succeed, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_VSessAnswer, @ref Mtc_VSessGetCookie, @ref Mtc_VSessSetCookie
 */
ZFUNC ZUINT Mtc_VSessCall(ZCHAR *pcUri, ZCOOKIE zCookie);

/** 
 * @brief MTC video share session call.
 *
 * @param [in] pcUri The destination uri to which you want make a video share call.
 * @param [in] pcFileName The video file to which you want make a video share call.
 * @param [in] zCookie Used to correspond video share with UI resource. The cookie
 *                      value could be get by @ref Mtc_VSessGetCookie or reset by
 *                      @ref Mtc_VSessSetCookie at any time of video share's life.
 *
 * @return The id of this new created session on succeed, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_VSessAnswer, @ref Mtc_VSessGetCookie, @ref Mtc_VSessSetCookie
 */
ZFUNC ZUINT Mtc_VSessCallX(ZCHAR *pcUri, ZCHAR *pcFileName, ZCOOKIE zCookie);

/** 
 * @brief MTC video share session answer an incoming session call which is notified by
 *        callback function which was set by @ref Mtc_VShareCbSetIncoming.
 *
 * @param [in] iSessId The id of incoming session which you want to answer.
 * @param [in] zCookie Used to correspond session with UI resource. The cookie
 *                      value could be get by @ref Mtc_VSessGetCookie or reset by
 *                      @ref Mtc_VSessSetCookie at any time of session's life.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_VSessCall, @ref Mtc_VShareCbSetIncoming, @ref Mtc_VSessGetCookie, @ref Mtc_VSessSetCookie
 */
ZFUNC ZINT Mtc_VSessAnswer(ZUINT iSessId, ZCOOKIE zCookie);

/** 
 * @brief MTC video share session terminiate.
 *
 * @param [in] iSessId The ID of session which you want to terminate.
 * @param [in] iReason Indicate the terminate reason which may trigger some
 *                   service in S-CSCF, see @ref EN_MTC_VSHARE_TERM_REASON_TYPE.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * Actually Mtc_SessTerm does not free all resource allocated for this
 * session. It only starts a terminating procedure. All resource will be
 * freed automatically when the procedure ends.
 *
 * @see @ref Mtc_VSessCall, @ref Mtc_VSessAnswer...
 */
ZFUNC ZINT Mtc_VSessTerm(ZUINT iSessId, ZUINT iReason);

/** 
 * @brief MTC video session attach camera.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] pcDevId The ID of video device.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_VSessCameraAttach(ZUINT iSessId, ZCONST ZCHAR *pcDevId);

/** 
 * @brief MTC video session detach camera.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_VSessCameraDetach(ZUINT iSessId);

/** 
 * @brief MTC video share session start video transmission.
 *
 * @param [in] iSessId The ID of session which you want to start video transmission.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_VSessVideoStart(ZUINT iSessId);

/** 
 * @brief MTC video share session stop video transmission.
 *
 * @param [in] iSessId The ID of session which you want to stop video transmission.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_VSessVideoStop(ZUINT iSessId);

/** 
 * @brief MTC check video share session has entered in talking state.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on talking state.
 * @retval ZFALSE on talking state.
 *
 * @see @ref Mtc_VSessCall, @ref Mtc_VSessAnswer
 */
ZFUNC ZBOOL Mtc_VSessHasTalk(ZUINT iSessId);

/** 
 * @brief MTC video share session get cookie value.
 *
 * @param [in] iSessId The ID of session which you want to get cookie of.
 *
 * @return The cookie of session.
 *
 * The cookie value could be set by @ref Mtc_VSessCall, @ref Mtc_VSessAnswer or
 * @ref Mtc_VSessSetCookie previously.
 *
 * @see @ref Mtc_VSessCall, @ref Mtc_VSessAnswer, @ref Mtc_VSessSetCookie
 */
ZFUNC ZCOOKIE Mtc_VSessGetCookie(ZUINT iSessId);

/** 
 * @brief MTC video share session set cookie value.
 *
 * @param [in] iSessId The ID of session which you want to set cookie.
 * @param [in] zCookie The cookie which you want to set.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see @ref Mtc_VSessCall, @ref Mtc_VSessAnswer, @ref Mtc_VSessGetCookie
 */
ZFUNC ZINT Mtc_VSessSetCookie(ZUINT iSessId, ZCOOKIE zCookie);

/** 
 * @brief MTC video share session get peer URI and display name.
 *
 * @param [in] iSessId The ID of session which you want to get.
 * @param [out] ppcDispName The display name of peer user.
 * @param [out] ppcUri The URI of peer user.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * The peer information get by this function is actually from FROM/TO header in
 * SIP message. So the true identity of peer user is not asserted by server.
 *
 * @see @ref Mtc_VSessGetPeerId
 */
ZFUNC ZINT Mtc_VSessGetPeerUri(ZUINT iSessId, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri);

/** 
 * @brief MTC video share session get peer id, based on polices.
 *
 * @param [in] iSessId The ID of session which you want to get.
 * @param [out] ppcDispName The display name of peer user which you have this
 *                         session with.
 * @param [out] ppcUri The URI of peer user which you have this session with.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * Note the result of this function may be different with @ref Mtc_VSessGetPeerUri
 * because the apply of polices. For example, OIP, OIR, TIP, TIR, and privacy.
 *
 * @see @ref Mtc_VSessGetPeerUri
 */
ZFUNC ZINT Mtc_VSessGetPeerId(ZUINT iSessId, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC video share session start record incoming video.
 *
 * @param [in] iSessId The ID of session.
 * @param [in] *pcFileName The name of output file.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_VSessRecVideoStop
 */
ZFUNC ZINT Mtc_VSessRecVideoStart(ZUINT iSessId, ZCHAR *pcFileName);

/**
 * @brief MTC video share session stop record incoming video.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 *
 * @see Mtc_VSessRecVideoStart
 */
ZFUNC ZINT Mtc_VSessRecVideoStop(ZUINT iSessId);

/**
 * @brief MTC video share session check incoming video can be recorded.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on can be recorded.
 * @retval ZFALSE on can not be recorded.
 *
 * @see 
 */
ZFUNC ZINT Mtc_VSessVideoCanRec(ZUINT iSessId);

/** 
 * @brief MTC video share check if the offer/answer exchange is completed.
 *
 * @param [in] iSessId The ID of session.
 *
 * @retval ZTRUE on offer has answer.
 * @retval ZFALSE on offer has not answer.
 */
ZFUNC ZBOOL Mtc_VSessHasOfferAnswer(ZUINT iSessId);

/** 
 * @brief MTC video share get video size.
 *
 * @param [in] iSessId The ID of session.
 * @param [out] piWidth Video width in pixel of specific session.
 * @param [out] piHeight Video height in pixel of specific session.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_VSessGetVideoSize(ZUINT iSessId, ZUINT *piWidth,
                ZUINT *piHeight);
                
/** 
 * @brief MTC video share get session name for Zmf_VideoRenderAdd use.
 *
 * @param [in] iSessId The ID of session.
 *
 * @return The session name successfully or ZNULL failed.
 */

ZFUNC ZCONST ZCHAR * Mtc_VSessGetName(ZUINT iSessId);

/**
 * @brief MTC video share session get terminate reason description.
 *
 * @param [in] iStatCode The status code.
 *
 * @return The status code description successfully or ZNULL failed.
 */
ZCHAR * Mtc_VSessGetStatDesc(ZUINT iStatCode);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_VSHARE_H_ */

