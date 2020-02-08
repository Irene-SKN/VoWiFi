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
  File name     : mtc_im_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC instant message callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_CB_H__
#define _MTC_IM_CB_H__

/**
 * @file mtc_im_cb.h
 * @brief MTC Instant Message Callback Interface Functions
 *
 * This file includes IM callback interface function. Those function
 * is used to manage IM.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC IM operation ok. */
typedef ZVOID (*PFN_MTCIMCB)(ZFUNC_VOID);

/** @brief Type define of MTC IM operation ok. */
typedef ZVOID (*PFN_MTCIMXDCB)(ZBOOL bUpdate);

/** @brief Type define of MTC IM operation failed. */
typedef ZVOID (*PFN_MTCIMXCB)(ZUINT iStatCode);

/** @brief Type define of MTC IM imdn operation ok. */
typedef ZVOID (*PFN_MTCIMIMDNCB)(ZUINT iImdnId);

/** @brief Type define of MTC IM imdn operation failed. */
typedef ZVOID (*PFN_MTCIMIMDNXCB)(ZUINT iImdnId, ZUINT iStatCode);

/** @brief Type define of MTC IM message(page or large) operation ok. */
typedef ZVOID (*PFN_MTCIMMSGCB)(ZUINT iMsgId);

/** @brief Type define of MTC IM message(page or large) operation failed. */
typedef ZVOID (*PFN_MTCIMMSGXCB)(ZUINT iMsgId, ZUINT iStatCode);

/** @brief Type define of MTC IM session operation ok. */
typedef ZVOID (*PFN_MTCIMSESSCB)(ZUINT iSessId);

/** @brief Type define of MTC IM session operation failed. */
typedef ZVOID (*PFN_MTCIMSESSXCB)(ZUINT iSessId, ZUINT iStatCode);

/** @brief Type define of MTC IM session replace previous session operation ok. */
typedef ZVOID (*PFN_MTCIMSESSREPLACECB)(ZUINT iSessId, ZUINT iReSessId);

/** @brief Type define of MTC IM session replace previous session operation ok. */
typedef ZVOID (*PFN_MTCIMSESSREPLACEMCB)(ZUINT iSessId, ZUINT iReSessId,
                ZUINT iMsgId);

/** @brief Type define of MTC IM session participant id operation ok. */
typedef ZVOID (*PFN_MTCIMSESSPARTPIDCB)(ZUINT iSessId, 
                ZUINT iPartpId);

/** @brief Type define of MTC IM session participant operation ok. */
typedef ZVOID (*PFN_MTCIMSESSPARTPCB)(ZUINT iSessId, 
                ZUINT iPartpLstId);

/** @brief Type define of MTC IM session participant operation failed. */
typedef ZVOID (*PFN_MTCIMSESSPARTPXCB)(ZUINT iSessId, 
                ZUINT iPartpLstId, ZUINT iStatCode);

/** @brief Type define of MTC IM session participant operation update ok. */
typedef ZVOID (*PFN_MTCIMSESSPARTPUPDTCB)(ZUINT iSessId,
                ZUINT iPartpLstId, ZBOOL bFullNtfy);

/** @brief Type define of MTC IM session message operation ok. */
typedef ZVOID (*PFN_MTCIMSMSGCB)(ZUINT iSessId, ZUINT iMsgId);

/** @brief Type define of MTC IM session message operation failed. */
typedef ZVOID (*PFN_MTCIMSMSGXCB)(ZUINT iSessId, ZUINT iMsgId, 
                ZUINT iStatCode);

/** @brief Type define of MTC IM file transfer operation ok. */
typedef ZVOID (*PFN_MTCIMFILECB)(ZUINT iTrsfId);

/** @brief Type define of MTC IM file transfer operation failed. */
typedef ZVOID (*PFN_MTCIMFILEXCB)(ZUINT iTrsfId, ZUINT iStatCode);

/** @brief Type define of MTC IM file transfer received ok. */
typedef ZVOID (*PFN_MTCIMFILERECVCB)(ZUINT iTrsfId, ZUINT iRecvSize, 
                ZUINT iTotalSize);

/** @brief Type define of MTC IM file transfer sending ok. */
typedef ZVOID (*PFN_MTCIMFILESENDCB)(ZUINT iTrsfId, ZUINT iSentSize, 
                ZUINT iTotalSize);

/** @brief Type define of MTC IM file transfer via http operation ok. */
typedef ZVOID (*PFN_MTCIMFTHTTPCB)(ZUINT iFtHttpId);

/** @brief Type define of MTC IM file transfer via http operation failed. */
typedef ZVOID (*PFN_MTCIMFTHTTPXCB)(ZUINT iFtHttpId, ZUINT iStatCode);

/** @brief Type define of MTC IM file transfer via http received ok. */
typedef ZVOID (*PFN_MTCIMFTHTTPRECVCB)(ZUINT iFtHttpId, ZUINT iRecvSize, 
                ZUINT iTotalSize);

/** @brief Type define of MTC IM file transfer via http sending ok. */
typedef ZVOID (*PFN_MTCIMFTHTTPSENDCB)(ZUINT iFtHttpId, ZUINT iSentSize, 
                ZUINT iTotalSize);

/** @brief Type define of MTC IM file http operation ok. */
typedef ZVOID (*PFN_MTCIMHTTPCB)(ZUINT iHttpId);

/** @brief Type define of MTC IM image share operation ok. */
typedef ZVOID (*PFN_MTCIMSHARECB)(ZUINT iShareId);

/** @brief Type define of MTC IM image share operation failed. */
typedef ZVOID (*PFN_MTCIMSHAREXCB)(ZUINT iShareId, ZUINT iStatCode);

/** @brief Type define of MTC IM image share received ok. */
typedef ZVOID (*PFN_MTCIMSHARERECVCB)(ZUINT iShareId, ZUINT iRecvSize, 
                ZUINT iTotalSize);

/** @brief Type define of MTC IM image share sending ok. */
typedef ZVOID (*PFN_MTCIMSHARESENDCB)(ZUINT iShareId, ZUINT iSentSize, 
                ZUINT iTotalSize);

/** @brief Type define of MTC IM deferred message ok callback. */
typedef ZVOID (*PFN_MTCIMDEFERCB)(ZUINT iDeferId);

/** @brief Type define of MTC IM deferred message failed callback. */
typedef ZVOID (*PFN_MTCIMDEFERXCB)(ZUINT iDeferId, ZUINT iStatCode);

/** @brief Type define of MTC IM deferred-list load ok callback. */
typedef ZVOID (*PFN_MTCDMSGLOADOKCB)(ZFUNC_VOID);

/** @brief Type define of MTC IM deferred-list load failed callback. */
typedef ZVOID (*PFN_MTCDMSGLOADFAILEDCB)(ZUINT iStatCode);

/** @brief Type define of MTC IM deferred-list remove ok callback. */
typedef ZVOID (*PFN_MTCDMSGRMVOKCB)(ZFUNC_VOID);

/** @brief Type define of MTC IM deferred-list remove failed callback. */
typedef ZVOID (*PFN_MTCDMSGRMVFAILEDCB)(ZUINT iStatCode);

/** @brief Type define of MTC IM deferred-list remove a history ok callback. */
typedef ZVOID (*PFN_MTCDMSGRMVHISOKCB)(ZUINT iHisId);

/** @brief Type define of MTC IM deferred-list remove a history failed callback. */
typedef ZVOID (*PFN_MTCDMSGRMVHISFAILEDCB)(ZUINT iHisId, ZUINT iStatCode);

/** @brief Type define of MTC IM message storage state callback. */
typedef ZVOID (*PFN_MTCMSSTATECB)(ZUINT iSessId);

/** @brief Type define of MTC IM message storage state callback. */
typedef ZVOID (*PFN_MTCMSOBJECTCB)(ZUINT iSessId, ZUINT iObjId);

/** @brief Type define of MTC IM conference operation ok. */
typedef ZVOID (*PFN_MTCIMCONFCB)(ZUINT iConfId);

/** @brief Type define of MTC IM conference operation failed. */
typedef ZVOID (*PFN_MTCIMCONFXCB)(ZUINT iConfId, ZUINT iStatCode);

/** @brief Type define of MTC Cmcc Offline operation Start. */
typedef ZVOID (*PFN_MTCIMOFFLINECB)(ZUINT iSessId);

/** @brief Type define of MTC Cmcc Offline operation Stop. */
typedef ZVOID (*PFN_MTCIMOFFLINEXCB)(ZUINT iSessId, ZUINT iStatCode);

/** @brief Type define of MTC Cmcc Offline Message List Recv. */
typedef ZVOID (*PFN_MTCIMOFFLINEMSGLSTRECVCB)(ZUINT iMsgLstId);

/** @brief Type define of MTC IM group manage via http operation ok. */
typedef ZVOID (*PFN_MTCIMGRPHTTPCB)(ZUINT iGrpHttpId);

/** @brief Type define of MTC IM group manage via http operation failed. */
typedef ZVOID (*PFN_MTCIMGRPHTTPXCB)(ZUINT iGrpHttpId, ZUINT iStatCode);

/** @brief Type define of MTC IM receive group infomation callback. */
typedef ZVOID (*PFN_MTCIMGINFO)(ZUINT iGrpInfoId, ZBOOL bFullNtfy);


/** @brief Type define of MTC IM conference http operation ok. */
typedef ZVOID (*PFN_MTCIMCONFHTTPCB)(ZUINT iHttpId);

/** @brief Type define of MTC IM conference http  operation failed. */
typedef ZVOID (*PFN_MTCIMCONFHTTPXCB)(ZUINT iHttpId, ZUINT iStatCode);

/**
 * @brief Set the page message received a new message callback.
 * The callback will be notified if user received a new message.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetPMsgRecvMsg(PFN_MTCIMMSGCB pfnCb); 

/**
 * @brief Set the page message received a new SMS-INFO message callback.
 * The callback will be notified if user received a new message.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetPMsgRecvSmsInfo(PFN_MTCIMMSGCB pfnCb); 

/**
 * @brief Set the page message send one text message successfully callback.
 * The callback is one of @ref Mtc_ImPMsgSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetPMsgSendOk(PFN_MTCIMMSGCB pfnCb); 

/**
 * @brief Set the page message send one text message failed callback.
 * The callback is one of @ref Mtc_ImPMsgSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetPMsgSendFailed(PFN_MTCIMMSGXCB pfnCb); 

/**
 * @brief Set the large message received a new large message callback.
 * The callback will be notified if user received a new message.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetLMsgRecvMsg(PFN_MTCIMMSGCB pfnCb); 

/**
 * @brief Set the large message send one large message successfully callback.
 * The callback is one of @ref Mtc_ImLMsgSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetLMsgSendOk(PFN_MTCIMMSGCB pfnCb); 

/**
 * @brief Set the large message send one large message failed callback.
 * The callback is one of @ref Mtc_ImLMsgSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetLMsgSendFailed(PFN_MTCIMMSGXCB pfnCb); 

/**
 * @brief Set the session received a new invitation callback.
 * The callback will be notified if user received session invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessRecvIvt(PFN_MTCIMSESSCB pfnCb); 

/**
 * @brief Set the session received a new invitation with frist message callback.
 * The callback will be notified if user received session invitation with frist message in it.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessRecvIvtM(PFN_MTCIMSMSGCB pfnCb); 

/**
 * @brief Set the session replace with the previous session id callback.
 * The callback will be notified if user received a new session invitation 
 * whitch will replace the previous session.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessReplace(PFN_MTCIMSESSREPLACECB pfnCb);

/**
 * @brief Set the session replace with the previous session id and a message in 
 * the new invite callback.
 * The callback will be notified if user received a new session invitation with 
 * first message whitch will replace the previous session.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessReplaceM(PFN_MTCIMSESSREPLACEMCB pfnCb);

/**
 * @brief Set the session invite signal accepted callback.
 * The callback is one of @ref Mtc_ImSessAcpted, @ref Mtc_ImSessEstab, @ref Mtc_ImSessEstabU 
 * or @ref Mtc_ImSessExtend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessSignalAcpted(PFN_MTCIMSESSCB pfnCb); 

/**
 * @brief Set the session invite accepted callback.
 * The callback is one of @ref Mtc_ImSessEstab, @ref Mtc_ImSessEstabU 
 * or @ref Mtc_ImSessExtend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessAcpted(PFN_MTCIMSESSCB pfnCb); 

/**
 * @brief Set the session invite rejected callback.
 * The callback is one of @ref Mtc_ImSessEstab, @ref Mtc_ImSessEstabU 
 * or @ref Mtc_ImSessExtend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessRejected(PFN_MTCIMSESSXCB pfnCb); 

/**
 * @brief Set the session canceled callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessCanceled(PFN_MTCIMSESSCB pfnCb); 

/**
 * @brief Set the session released callback.
 * The callback will be notified if user received session release.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessReleased(PFN_MTCIMSESSXCB pfnCb); 

/**
 * @brief Set the session leave successfully callback.
 * The callback is one of @ref Mtc_ImSessLeave results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessLeaveOk(PFN_MTCIMSESSCB pfnCb); 

/**
 * @brief Set the session leave failed callback.
 * The callback is one of @ref Mtc_ImSessLeave results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessLeaveFailed(PFN_MTCIMSESSXCB pfnCb); 

/**
 * @brief Set the session dissolve successfully callback.
 * The callback is one of @ref Mtc_ImSessDissolve results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessDissolveOk(PFN_MTCIMSESSCB pfnCb); 

/**
 * @brief Set the session dissolve failed callback.
 * The callback is one of @ref Mtc_ImSessDissolve results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessDissolveFailed(PFN_MTCIMSESSXCB pfnCb); 

/**
 * @brief Set the session composing callback.
 * The callback will be notified if the session iscomposing state change.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessComposing(PFN_MTCIMSESSPARTPIDCB pfnCb);

/**
 * @brief Set the session add participant successfully callback.
 * The callback is one of @ref Mtc_ImSessAddPartp, Mtc_ImSessAddPartpU results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessPartpAddOk(PFN_MTCIMSESSPARTPCB pfnCb); 

/**
 * @brief Set the session add participant failed callback.
 * The callback is one of @ref Mtc_ImSessAddPartp, Mtc_ImSessAddPartpU results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessPartpAddFailed(PFN_MTCIMSESSPARTPXCB pfnCb); 

/**
 * @brief Set the session expel participant successfully callback.
 * The callback is one of @ref Mtc_ImSessEplPartp results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessPartpEplOk(PFN_MTCIMSESSPARTPCB pfnCb); 

/**
 * @brief Set the session expel participant failed callback.
 * The callback is one of @ref Mtc_ImSessEplPartp results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessPartpEplFailed(PFN_MTCIMSESSPARTPXCB pfnCb); 

/**
 * @brief Set the session updated participant information callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessPartpUpted(PFN_MTCIMSESSPARTPUPDTCB pfnCb); 

/**
 * @brief Set the session subject modify successfully callback.
 * The callback is one of @ref Mtc_ImSessMdfySubject results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessSubjectMdfyOk(PFN_MTCIMSESSCB pfnCb);

/**
 * @brief Set the session subject modify failed callback.
 * The callback is one of @ref Mtc_ImSessMdfySubject results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessSubjectMdfyFailed(PFN_MTCIMSESSXCB pfnCb);

/**
 * @brief Set the session chairman modify successfully callback.
 * The callback is one of @ref Mtc_ImSessMdfyChairMan results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessChairManMdfyOk(PFN_MTCIMSESSCB pfnCb);

/**
 * @brief Set the session chairman modify failed callback.
 * The callback is one of @ref Mtc_ImSessMdfyChairMan results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessChairManMdfyFailed(PFN_MTCIMSESSXCB pfnCb);

/**
 * @brief Set the session chairman modify request callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessChairManMdfyReq(PFN_MTCIMSESSCB pfnCb);

/**
 * @brief Set the session own display name modify successfully callback.
 * The callback is one of @ref Mtc_ImSessMdfyDispName results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessDispNameMdfyOk(PFN_MTCIMSESSCB pfnCb);

/**
 * @brief Set the session own display name modify failed callback.
 * The callback is one of @ref Mtc_ImSessMdfyDispName results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessDispNameMdfyFailed(PFN_MTCIMSESSXCB pfnCb);

/**
 * @brief Set the session message received a new message callback.
 * The callback will be notified if user received a new message.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessMsgRecvMsg(PFN_MTCIMSMSGCB pfnCb); 

/**
 * @brief Set the session message send one message successfully callback.
 * The callback is one of @ref Mtc_ImSessMsgSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessMsgSendOk(PFN_MTCIMSMSGCB pfnCb); 

/**
 * @brief Set the session message send one message failed callback.
 * The callback is one of @ref Mtc_ImSessMsgSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetSessMsgSendFailed(PFN_MTCIMSMSGXCB pfnCb);

/**
 * @brief Set the store and forward received a new invitation callback.
 * The callback will be notified if user received store and forward invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetStFwdRecvIvt(PFN_MTCIMSESSCB pfnCb);

/**
 * @brief Set the store and forward received a new invitation with frist message callback.
 * The callback will be notified if user received store and forward with frist message invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetStFwdRecvIvtM(PFN_MTCIMSMSGCB pfnCb);

/**
 * @brief Set the store and forward replace with the previous session id callback.
 * The callback will be notified if user replace the store and forward session.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetStFwdReplace(PFN_MTCIMSESSREPLACECB pfnCb);

/**
 * @brief Set the store and forward replace with the previous session id and a message in the new invite callback.
 * The callback will be notified if user replace the store and forward session.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetStFwdReplaceM(PFN_MTCIMSESSREPLACEMCB pfnCb);

/**
 * @brief Set the store and forward session invite accepted callback.
 * The callback is one of @ref Mtc_ImStFwdAccept results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetStFwdAcpted(PFN_MTCIMSESSCB pfnCb); 

/**
 * @brief Set the store and forward canceled callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetStFwdCanceled(PFN_MTCIMSESSCB pfnCb);

/**
 * @brief Set the store and forward released callback.
 * The callback will be notified if user received store and forward release.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetStFwdReleased(PFN_MTCIMSESSXCB pfnCb);

/**
 * @brief Set the store and forward message received a new message callback.
 * The callback will be notified if user received a new store and forward message.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetStFwdMsgRecvMsg(PFN_MTCIMSMSGCB pfnCb);

/**
 * @brief Set the imdn received a delivery notification callback.
 * The callback will be notified if user received a imdn delivery notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnRecvDeliNtfy(PFN_MTCIMIMDNCB pfnCb);

/**
 * @brief Set the imdn received a delivery failed notification callback.
 * The callback will be notified if user received a imdn delivery failed notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnRecvDeliFailed(PFN_MTCIMIMDNXCB pfnCb);

/**
 * @brief Set the imdn received a delivery forwarded notification callback.
 * The callback will be notified if user received a imdn delivery forwarded notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnRecvDeliForwarded(PFN_MTCIMIMDNCB pfnCb);

/**
 * @brief Set the imdn received a display notification callback.
 * The callback will be notified if user received a imdn display notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnRecvDispNtfy(PFN_MTCIMIMDNCB pfnCb);

/**
 * @brief Set the imdn received a burned notification callback.
 * The callback will be notified if user received a imdn burned notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnRecvBurnNtfy(PFN_MTCIMIMDNCB pfnCb);

/**
 * @brief Set the file transfer received a new invitation callback.
 * The callback will be notified if user received file transfer invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileRecvIvt(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file transfer receiving a file data callback.
 * The callback will be notified if user receiving file transfer data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileRecving(PFN_MTCIMFILERECVCB pfnCb); 

/**
 * @brief Set the file transfer received a file data callback.
 * The callback will be notified if user received file transfer data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileRecvDone(PFN_MTCIMFILERECVCB pfnCb); 

/**
 * @brief Set the file transfer invite accepted callback.
 * The callback is one of @ref Mtc_ImFileTrsf or @ref Mtc_ImFileTrsfU results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileAcpted(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file transfer invite rejected callback.
 * The callback is one of @ref Mtc_ImFileTrsf or @ref Mtc_ImFileTrsfU results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileRejected(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file transfer session canceled callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileCanceled(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file transfer session released callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileReleased(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file transfer sending callback.
 * The callback is one of @ref Mtc_ImFileTrsf results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileSending(PFN_MTCIMFILESENDCB pfnCb); 

/**
 * @brief Set the file transfer send last file successfully callback.
 * The callback is one of @ref Mtc_ImFileTrsf results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileSendLast(PFN_MTCIMFILESENDCB pfnCb);

/**
 * @brief Set the file transfer send one file successfully callback.
 * The callback is one of @ref Mtc_ImFileTrsf results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileSendOk(PFN_MTCIMFILESENDCB pfnCb); 

/**
 * @brief Set the file transfer send one file failed callback.
 * The callback is one of @ref Mtc_ImFileTrsf results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFileSendFailed(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file resume received a new invitation from file sender callback.
 * The callback will be notified if user received file resume invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeRecvIvtFromSender(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file resume received a new invitation from file receiver callback.
 * The callback will be notified if user received file resume invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeRecvIvtFromRecver(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file resume receiving a file data callback.
 * The callback will be notified if user receiving file resume data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeRecving(PFN_MTCIMFILERECVCB pfnCb); 

/**
 * @brief Set the file resume received a file data callback.
 * The callback will be notified if user received file resume data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeRecvDone(PFN_MTCIMFILERECVCB pfnCb); 

/**
 * @brief Set the file resume invite accepted callback.
 * The callback is one of @ref Mtc_ImFileResumeBySender results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeAcpted(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file resume invite rejected callback.
 * The callback is one of @ref Mtc_ImFileResumeBySender results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeRejected(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file resume session canceled callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeCanceled(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file resume session released callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeReleased(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file resume sending callback.
 * The callback is one of @ref Mtc_ImFileResumeBySender results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeSending(PFN_MTCIMFILESENDCB pfnCb); 

/**
 * @brief Set the file resume send last file successfully callback.
 * The callback is one of @ref Mtc_ImFileResumeBySender results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeSendLast(PFN_MTCIMFILESENDCB pfnCb);

/**
 * @brief Set the file resume send one file successfully callback.
 * The callback is one of @ref Mtc_ImFileResumeBySender results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeSendOk(PFN_MTCIMFILESENDCB pfnCb); 

/**
 * @brief Set the file resume send one file failed callback.
 * The callback is one of @ref Mtc_ImFileResumeBySender results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFResumeSendFailed(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file fetch receiving a file data callback.
 * The callback will be notified if user receiving file fetch data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFFetchRecving(PFN_MTCIMFILERECVCB pfnCb); 

/**
 * @brief Set the file fetch received a file data callback.
 * The callback will be notified if user received file fetch data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFFetchRecvDone(PFN_MTCIMFILERECVCB pfnCb); 

/**
 * @brief Set the file fetch invite accepted callback.
 * The callback is one of @ref Mtc_ImFileFetchViaMsrp results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFFetchAcpted(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file fetch invite rejected callback.
 * The callback is one of @ref Mtc_ImFileFetchViaMsrp results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFFetchRejected(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file fetch session canceled callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFFetchCanceled(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file fetch session released callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFFetchReleased(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file store and forward received a new invitation callback.
 * The callback will be notified if user received file store and forward invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFStfwdRecvIvt(PFN_MTCIMFILECB pfnCb); 

/**
 * @brief Set the file store and forward receiving a file data callback.
 * The callback will be notified if user receiving file store and forward data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFStfwdRecving(PFN_MTCIMFILERECVCB pfnCb); 

/**
 * @brief Set the file store and forward received a file data callback.
 * The callback will be notified if user received file store and forward data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFStfwdRecvDone(PFN_MTCIMFILERECVCB pfnCb); 

/**
 * @brief Set the file store and forward session canceled callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFStfwdCanceled(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file store and forward session released callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFStfwdReleased(PFN_MTCIMFILEXCB pfnCb); 

/**
 * @brief Set the file transfer via http received a new invitation callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpRecvIvt(PFN_MTCIMFTHTTPCB pfnCb);

/**
 * @brief Set the file transfer via http receiving a file data callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpRecving(PFN_MTCIMFTHTTPRECVCB pfnCb);

/**
 * @brief Set the file transfer via http received a file data callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpRecvDone(PFN_MTCIMFTHTTPRECVCB pfnCb);

/**
 * @brief Set the file transfer via http receive a file failed callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpRecvFailed(PFN_MTCIMFTHTTPXCB pfnCb);

/**
 * @brief Set the file transfer via http released callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpReleased(PFN_MTCIMFTHTTPXCB pfnCb);

/**
 * @brief Set the file transfer via http sending callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpSending(PFN_MTCIMFTHTTPSENDCB pfnCb);

/**
 * @brief Set the file transfer via http send last file successfully callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpSendLast(PFN_MTCIMFTHTTPSENDCB pfnCb);

/**
 * @brief Set the file transfer via http send one file successfully callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpSendOk(PFN_MTCIMFTHTTPSENDCB pfnCb);

/**
 * @brief Set the file transfer via http send one file failed callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpSendFailed(PFN_MTCIMFTHTTPXCB pfnCb);

/**
 * @brief Set the file transfer via http send a file message successfully callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpMsgSendOk(PFN_MTCIMFTHTTPCB pfnCb);

/**
 * @brief Set the file transfer via http send a file message failed callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetFtHttpMsgSendFailed(PFN_MTCIMFTHTTPCB pfnCb);

/**
 * @brief Set the image share received a new invitation callback.
 * The callback will be notified if user received image share invitation.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareRecvIvt(PFN_MTCIMSHARECB pfnCb); 

/**
 * @brief Set the image share receiving a image data callback.
 * The callback will be notified if user received image share data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareRecving(PFN_MTCIMSHARERECVCB pfnCb); 

/**
 * @brief Set the image share received a image data callback.
 * The callback will be notified if user received image share data.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareRecvDone(PFN_MTCIMSHARERECVCB pfnCb); 

/**
 * @brief Set the image share invite accepted callback.
 * The callback is one of @ref Mtc_ImIShareSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareAcpted(PFN_MTCIMSHARECB pfnCb); 

/**
 * @brief Set the image share invite rejected callback.
 * The callback is one of @ref Mtc_ImIShareSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareRejected(PFN_MTCIMSHARECB pfnCb); 

/**
 * @brief Set the image share session canceled callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareCanceled(PFN_MTCIMSHARECB pfnCb); 

/**
 * @brief Set the image share session released callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareReleased(PFN_MTCIMSHAREXCB pfnCb); 

/**
 * @brief Set the image share session exited callback.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareExited(PFN_MTCIMSHARECB pfnCb); 

/**
 * @brief Set the image share sending callback.
 * The callback is one of @ref Mtc_ImIShareSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareSending(PFN_MTCIMSHARESENDCB pfnCb); 

/**
 * @brief Set the image share send last callback.
 * The callback is one of @ref Mtc_ImIShareSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareSendLast(PFN_MTCIMSHARESENDCB pfnCb);

/**
 * @brief Set the image share send one image successfully callback.
 * The callback is one of @ref Mtc_ImIShareSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareSendOk(PFN_MTCIMSHARESENDCB pfnCb); 

/**
 * @brief Set the image share send one image failed callback.
 * The callback is one of @ref Mtc_ImIShareSend results.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetIShareSendFailed(PFN_MTCIMSHAREXCB pfnCb); 

/**
 * @brief Set the deferred message retrieve metadata successfully callback.
 * The callback will be notified if user call @ref Mtc_ImDeferRetrieveAll.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDeferRetrieveOk(PFN_MTCIMDEFERCB pfnCb); 

/**
 * @brief Set the deferred message retrieve metadata failed callback.
 * The callback will be notified if user call @ref Mtc_ImDeferRetrieveAll.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDeferRetrieveFailed(PFN_MTCIMDEFERXCB pfnCb); 

/**
 * @brief Set the deferred page message retrieve metadata successfully callback.
 * The callback will be notified if user call @ref Mtc_ImDeferRetrievePager.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDeferRetrievePagerOk(PFN_MTCIMDEFERCB pfnCb); 

/**
 * @brief Set the deferred page message retrieve metadata failed callback.
 * The callback will be notified if user call @ref Mtc_ImDeferRetrievePager.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDeferRetrievePagerFailed(PFN_MTCIMDEFERXCB pfnCb); 

/**
 * @brief Set the deferred file retrieve metadata successfully callback.
 * The callback will be notified if user call @ref Mtc_ImDeferRetrieveFile.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDeferRetrieveFileOk(PFN_MTCIMDEFERCB pfnCb); 

/**
 * @brief Set the deferred file retrieve metadata failed callback.
 * The callback will be notified if user call @ref Mtc_ImDeferRetrieveFile.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDeferRetrieveFileFailed(PFN_MTCIMDEFERXCB pfnCb); 

/**
 * @brief Set the deferred-list load successfully callback.
 * The callback will be notified if user call @ref Mtc_DmsgLoadAll.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDmsgLoadOk(PFN_MTCDMSGLOADOKCB pfnCb);

/**
 * @brief Set the deferred-list load failed callback.
 * The callback will be notified if user call @ref Mtc_DmsgLoadAll.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDmsgLoadFailed(PFN_MTCDMSGLOADFAILEDCB pfnCb);

/**
 * @brief Set the deferred-list remove successfully callback.
 * The callback will be notified if user call @ref Mtc_DmsgRmvAll.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDmsgRmvOk(PFN_MTCDMSGRMVOKCB pfnCb);

/**
 * @brief Set the deferred-list remove failed callback.
 * The callback will be notified if user call @ref Mtc_DmsgRmvAll.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDmsgRmvFailed(PFN_MTCDMSGRMVFAILEDCB pfnCb);

/**
 * @brief Set the deferred-list remove a history successfully callback.
 * The callback will be notified if user call @ref Mtc_DmsgRmvHis.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDmsgRmvHisOk(PFN_MTCDMSGRMVHISOKCB pfnCb);

/**
 * @brief Set the deferred-list remove a history failed callback.
 * The callback will be notified if user call @ref Mtc_DmsgRmvHis.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetDmsgRmvHisFailed(PFN_MTCDMSGRMVHISFAILEDCB pfnCb);

/**
 * @brief Set the login OK callback.
 * The callback will be notified after @ref Mtc_ImMsLogin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsLoginOk(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the login failed callback.
 * The callback will be notified after @ref Mtc_ImMsLogin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsLoginFailed(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the backup directory create OK callback.
 * The callback will be notified after @ref Mtc_ImMsBackupBegin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsCreateOk(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the backup directory create failed callback.
 * The callback will be notified after @ref Mtc_ImMsBackupBegin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsCreateFailed(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the select backup directory OK callback.
 * The callback will be notified after @ref Mtc_ImMsBackupBegin.
 *
 * After this callback, UI can append message by Mtc_ImMsBackupAppend.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsSelectOk(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the select backup directory OK callback.
 * The callback will be notified after @ref Mtc_ImMsBackupBegin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsSelectFailed(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the append one message object OK callback.
 * The callback will be notified after @ref Mtc_ImMsBackupAppend.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsAppendOk(PFN_MTCMSOBJECTCB pfnCb);

/**
 * @brief Set the append one message object failed callback.
 * The callback will be notified after @ref Mtc_ImMsBackupAppend.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsAppendFailed(PFN_MTCMSOBJECTCB pfnCb);

/**
 * @brief Set the list restore directory OK callback.
 * The callback will be notified after @ref Mtc_ImMsRestoreBegin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsListOk(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the list restore directory failed callback.
 * The callback will be notified after @ref Mtc_ImMsRestoreBegin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsListFailed(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the fetch message object OK callback.
 * The callback will be notified after @ref Mtc_ImMsRestoreBegin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsFetchOk(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the fetch message failed callback.
 * The callback will be notified after @ref Mtc_ImMsRestoreBegin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsFetchFailed(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the close directory OK callback.
 * The callback will be notified after @ref Mtc_ImMsBackupEnd
 * @ref Mtc_ImMsRestoreEnd.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsCloseOk(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the close directory failed callback.
 * The callback will be notified after @ref Mtc_ImMsBackupEnd
 * @ref Mtc_ImMsRestoreEnd.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsCloseFailed(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the logout OK callback.
 * The callback will be notified after @ref Mtc_ImMsLogout.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsLogoutOk(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the logout failed callback.
 * The callback will be notified after @ref Mtc_ImMsLogout.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsLogoutFailed(PFN_MTCMSSTATECB pfnCb);

/**
 * @brief Set the receive one message object OK callback.
 * The callback will be notified after @ref Mtc_ImMsRestoreBegin.
 * 
 * @param  pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetMsObjectReceived(PFN_MTCMSOBJECTCB pfnCb);

/**
 * @brief Set the subscribe conference list ok callback.
 * The callback will be notified if user call @ref Mtc_ImConfMSubsConfLst.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetConfSubsLstOk(PFN_MTCIMCB pfnCb);

/**
 * @brief Set the subscribe conference list failed callback.
 * The callback will be notified if user call @ref Mtc_ImConfMSubsConfLst.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetConfSubsLstFailed(PFN_MTCIMXCB pfnCb);

/**
 * @brief Set the http subscribe conference list ok callback.
 * The callback will be notified if user call @ref Mtc_ImConfHttpSubsInfoLst.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetConfHttpSubsInfoLstOk(PFN_MTCIMCONFHTTPCB pfnCb);

/**
 * @brief Set the subscribe conference info list failed callback.
 * The callback will be notified if user call @ref Mtc_ImConfHttpSubsInfoLst.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetConfHttpSubsInfoLstFailed(PFN_MTCIMCONFHTTPXCB pfnCb);

/**
 * @brief Set the subscribe conference info ok callback.
 * The callback will be notified if user call @ref Mtc_ImConfMSubsConf.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetConfSubsInfoOk(PFN_MTCIMCONFCB pfnCb);

/**
 * @brief Set the subscribe conference info failed callback.
 * The callback will be notified if user call @ref Mtc_ImConfMSubsConf.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetConfSubsInfoFailed(PFN_MTCIMCONFXCB pfnCb);

/**
 * @brief Set the subscribe conference info failed callback.
 * The callback will be notified if conference info is updated.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetConfInfoUpdated(PFN_MTCIMCONFCB pfnCb);

/**
 * @brief Set the imdn send dilivery ok notification callback.
 * The callback will be notified if user send imdn dilivery ok notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnSendDeliOk(PFN_MTCIMIMDNCB pfnCb);

/**
 * @brief Set the imdn send a dilivery failed notification callback.
 * The callback will be notified if user send a imdn dilivery failed notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnSendDeliFailed(PFN_MTCIMIMDNXCB pfnCb);

/**
 * @brief Set the imdn sent a display ok notification callback.
 * The callback will be notified if user sent a imdn display ok notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnSendDispOk(PFN_MTCIMIMDNCB pfnCb);

/**
 * @brief Set the imdn sent a display failed notification callback.
 * The callback will be notified if user sent a imdn display failed notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnSendDispFailed(PFN_MTCIMIMDNXCB pfnCb);

/**
 * @brief Set the imdn send grp dilivery ok notification callback.
 * The callback will be notified if user send imdn dilivery ok notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnSendDeliGOk(PFN_MTCIMIMDNCB pfnCb);

/**
 * @brief Set the imdn send a grp dilivery failed notification callback.
 * The callback will be notified if user send a imdn dilivery failed notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnSendDeliGFailed(PFN_MTCIMIMDNXCB pfnCb);

/**
 * @brief Set the imdn sent a grp display ok notification callback.
 * The callback will be notified if user sent a imdn display ok notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnSendDispGOk(PFN_MTCIMIMDNCB pfnCb);

/**
 * @brief Set the imdn sent a grp display failed notification callback.
 * The callback will be notified if user sent a imdn display failed notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetImdnSendDispGFailed(PFN_MTCIMIMDNXCB pfnCb);


/**
 * @brief Set the offline message recv start.
 * The callback will be notified if offline messsage start notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetOfflineMsgStart(PFN_MTCIMOFFLINECB pfnCb);

/**
 * @brief Set the offline message recv stop.
 * The callback will be notified if offline messsage stop notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetOfflineMsgStop(PFN_MTCIMOFFLINEXCB pfnCb);

/**
 * @brief Set the offline message list recv.
 * The callback will be notified if offline messsage list recv notification.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetOfflineMsgLstRecv(PFN_MTCIMOFFLINEMSGLSTRECVCB pfnCb);

/**
 * @brief Set the group manage via http create a group ok callback.
 * The callback will be notified if create a group ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpCreateOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http create a group failed callback.
 * The callback will be notified if create a group failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpCreateFailed(PFN_MTCIMGRPHTTPXCB pfnCb); 

/**
 * @brief Set the group manage via http delete a group ok callback.
 * The callback will be notified if delete a group ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpDeleteOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http delete a group failed callback.
 * The callback will be notified if delete a group failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpDeleteFailed(PFN_MTCIMGRPHTTPXCB pfnCb); 

/**
 * @brief Set the group manage via http subs group list ok callback.
 * The callback will be notified if subs group list ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpSubsLstOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http subs group failed ok callback.
 * The callback will be notified if subs group list failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpSubsLstFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

/**
 * @brief Set the group manage via http subs group info ok callback.
 * The callback will be notified if subs group info ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpSubsInfoOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http subs group info failed ok callback.
 * The callback will be notified if subs group info failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpSubsInfoFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

/**
 * @brief Set the group manage via http modify subject ok callback.
 * The callback will be notified if modify subject ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpMdfySubjectOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http modify subject failed callback.
 * The callback will be notified if modify subject failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpMdfySubjectFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

/**
 * @brief Set the group manage via http modify displayname ok callback.
 * The callback will be notified if modify displayname ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpMdfyDispNameOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http modify displayname failed callback.
 * The callback will be notified if modify displayname failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpMdfyDispNameFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

/**
 * @brief Set the group manage via http modify chairman ok callback.
 * The callback will be notified if modify chairman ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpMdfyChairManOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http modify chairman failed callback.
 * The callback will be notified if modify chairman failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpMdfyChairManFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

/**
 * @brief Set the group manage via http add partp ok callback.
 * The callback will be notified if add partp ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpAddPartpOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http add partp failed callback.
 * The callback will be notified if add partp failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpAddPartpFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

/**
 * @brief Set the group manage via http epl partp ok callback.
 * The callback will be notified if epl partp ok.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpEplPartpOk(PFN_MTCIMGRPHTTPCB pfnCb); 

/**
 * @brief Set the group manage via http epl partp failed callback.
 * The callback will be notified if epl partp failed.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_ImCbSetGrpHttpEplPartpFailed(PFN_MTCIMGRPHTTPXCB pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_CB_H__ */

