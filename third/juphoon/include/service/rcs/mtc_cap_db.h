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
  File name     : mtc_cap_db.h
  Module        : multimedia talk client
  Author        : logan.huang
  Created on    : 2011-02-06
  Description   :
      Data structure and function declare required by MTC 
      capability query database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CAP_DB_H__
#define _MTC_CAP_DB_H__

/**
 * @file mtc_cap_db.h
 * @brief MTC capability Database Interface Functions.
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief MTC cap db restore configuration of current user for speicifc mode.
 *
 * @param [in] iMode The combination of EN_MTC_PROF_SERVICE_MODE 
 *
 * This interface should be invoke after @ref Mtc_CliInit and 
 * @ref Mtc_CliOpen was called.
 *
 * @retval ZOK Restore provision successfully.
 * @retval ZFAILED Restore provision failed.
 */
ZFUNC ZINT Mtc_CapDbRestoreProvision(ZUINT iMode);

/**
 * @brief Get capability info expired time.
 *
 * @return The capability info expired time.
 *
 * @see @ref Mtc_CapDbSetCapInfoExpire
 */
ZFUNC ZUINT Mtc_CapDbGetCapInfoExpire(ZFUNC_VOID);

/**
 * @brief Get capability polling period.
 *
 * @return The capability polling period.
 *
 * @see @ref Mtc_CapDbSetCapPollingPeriod
 */
ZFUNC ZUINT Mtc_CapDbGetCapPollingPeriod(ZFUNC_VOID);

/**
 * @brief Get capability polling rate.
 *
 * @return The capability polling rate.
 *
 * @see @ref Mtc_CapDbSetCapPollingRate
 */
ZFUNC ZUINT Mtc_CapDbGetCapPollingRate(ZFUNC_VOID);

/**
 * @brief Get capability polling rate period.
 *
 * @return The capability polling rate period.
 *
 * @see @ref Mtc_CapDbSetCapPollingRatePeriod
 */
ZFUNC ZUINT Mtc_CapDbGetCapPollingRatePeriod(ZFUNC_VOID);

/**
 * @brief Get capability default discovery mechanism.
 *
 * @return The capability default discovery mechanism.
 *
 * @see @ref Mtc_CapDbSetCapDefaultDisc
 */
ZFUNC ZBOOL Mtc_CapDbGetCapDefaultDisc(ZFUNC_VOID);

/**
 * @brief Get capability discovery common stack.
 *
 * @return The capability discovery common stack.
 *
 * @see @ref Mtc_CapDbSetCapDiscCommonStack
 */
ZFUNC ZBOOL Mtc_CapDbGetCapDiscCommonStack(ZFUNC_VOID);

/**
 * @brief Get capability discovery via presence enable.
 *
 * @return The capability discovery via presence enable.
 *
 * @see @ref Mtc_CapDbSetCapDiscViaPresEnable
 */
ZFUNC ZBOOL Mtc_CapDbGetCapDiscViaPresEnable(ZFUNC_VOID);

/**
 * @brief Get capability messaging capabilities validity.
 *
 * @return The capability messaging capabilities validity.
 *
 * @see @ref Mtc_CapDbSetCapMsgCapValidity
 */
ZFUNC ZUINT Mtc_CapDbGetCapMsgCapValidity(ZFUNC_VOID);

/**
 * @brief Get capability tag converg flag in OPTIONS from database.
 *
 * @retval ZTRUE the feature tag in OPTIONS will converg.
 * @retval ZFALSE the feature tag in OPTIONS will not converg.
 *
 * @see @ref Mtc_CapDbSetCapTagConverg
 */
ZFUNC ZBOOL Mtc_CapDbGetCapTagConverg();

/**
 * @brief Get capability IM enable.
 *
 * @return The capability IM enable.
 *
 * @see @ref Mtc_CapDbSetCapIMEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapIMEn(ZFUNC_VOID);

/**
 * @brief Get capability file transfer enable.
 *
 * @return The capability file transfer enable.
 *
 * @see @ref Mtc_CapDbSetCapFTEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapFTEn(ZFUNC_VOID);

/**
 * @brief Get capability standalone messaging enable.
 *
 * @return The capability standalone messaging enable.
 *
 */
ZFUNC ZBOOL Mtc_CapDbGetCapStandMsgEn(ZFUNC_VOID);

/**
 * @brief Get capability video share outside of a voice call enable.
 *
 * @return The capability video share outside of a voice call enable.
 *
 * @see @ref Mtc_CapDbSetCapVSOutVCEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapVSOutVCEn(ZFUNC_VOID);

/**
 * @brief Get capability video share enable.
 *
 * @return The capability video share enable.
 *
 * @see @ref Mtc_CapDbSetCapVSEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapVSEn(ZFUNC_VOID);

/**
 * @brief Get capability image share enable.
 *
 * @return The capability image share enable.
 *
 * @see @ref Mtc_CapDbSetCapISEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapISEn(ZFUNC_VOID);

/**
 * @brief Get capability discovery presence enable.
 *
 * @return The capability discovery presence enable.
 *
 * @see @ref Mtc_CapDbSetCapDPEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapDPEn(ZFUNC_VOID);

/**
 * @brief Get capability social presence enable.
 *
 * @return The capability social presence enable.
 *
 * @see @ref Mtc_CapDbSetCapSPEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapSPEn(ZFUNC_VOID);

/**
 * @brief Get capability IP voice call enable.
 *
 * @return The capability IP voice call enable.
 *
 * @see @ref Mtc_CapDbSetCapVoicCallEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapVoicCallEn(ZFUNC_VOID);

/**
 * @brief Get capability IP voice call enable.
 *
 * @return The capability IP voice call enable.
 *
 * @see @ref Mtc_CapDbSetCapVideoCallEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapVideoCallEn(ZFUNC_VOID);

/**
 * @brief Get capability geolocation pull enable.
 *
 * @return The capability geolocation pull enable.
 *
 * @see @ref Mtc_CapDbSetCapGeoPullEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapGeoPullEn(ZFUNC_VOID);

/**
 * @brief Get capability geolocation push enable.
 *
 * @return The capability geolocation push enable.
 *
 * @see @ref Mtc_CapDbSetCapGeoPushEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapGeoPushEn(ZFUNC_VOID);

/**
 * @brief Get capability full store and forward for group chat enable.
 *
 * @return The capability full store and forward for group chat enable.
 *
 * @see @ref Mtc_CapDbSetCapGpChatFStFwdEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapGpChatFStFwdEn(ZFUNC_VOID);

/**
 * @brief Get capability file transfer thumbnail enable.
 *
 * @return The capability file transfer thumbnail enable.
 *
 * @see @ref Mtc_CapDbSetCapFTThumbEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapFTThumbEn(ZFUNC_VOID);

/**
 * @brief Get capability file transfer store and forward enable.
 *
 * @return The capability file transfer store and forward enable.
 *
 * @see @ref Mtc_CapDbSetCapFTStFwdEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapFTStFwdEn(ZFUNC_VOID);

/**
 * @brief Get capability file transfer via HTTP enable.
 *
 * @return The capability file transfer via HTTP enable.
 *
 * @see @ref Mtc_CapDbSetCapFTHTTPEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapFTHTTPEn(ZFUNC_VOID);

/**
 * @brief Get capability geolocation pull using file transfer enable.
 *
 * @return The capability geolocation pull using file transfer enable.
 *
 * @see @ref Mtc_CapDbSetCapGeoPullFTEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapGeoPullFTEn(ZFUNC_VOID);

/**
 * @brief Get capability public message enable.
 *
 * @return The capability public message enable.
 *
 * @see @ref Mtc_CapDbSetCapPubMsgEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapPubMsgEn();

/**
 * @brief Get capability cloud file enable.
 *
 * @return The capability cloud file enable.
 *
 * @see @ref Mtc_CapDbSetCapCloudFileEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapCloudFileEn();

/**
 * @brief Get capability vemoticon enable.
 *
 * @return The capability vemoticon enable.
 *
 * @see @ref Mtc_CapDbSetCapVemEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapVemEn();

/**
 * @brief Get capability group manage enable.
 *
 * @return The capability group manage enable.
 *
 * @see @ref Mtc_CapDbSetCapGrpManEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapGrpManEn();

/**
 * @brief Get capability cpm msessage enable.
 *
 * @return The capability cpm msessage enable.
 *
 * @see @ref Mtc_CapDbSetCapCpmMsgEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapCpmMsgEn();

/**
 * @brief Get capability cpm large msessage enable.
 *
 * @return The capability cpm large msessage enable.
 *
 * @see @ref Mtc_CapDbSetCapCpmLargeEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapCpmLargeEn();

/**
 * @brief Get capability cpm file transfer enable.
 *
 * @return The capability cpm file transfer enable.
 *
 * @see @ref Mtc_CapDbSetCapCpmFtEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapCpmFtEn();

/**
 * @brief Get capability cpm session enable.
 *
 * @return The capability cpm session enable.
 *
 * @see @ref Mtc_CapDbSetCapCpmSessEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapCpmSessEn();

/**
 * @brief Get capability burn after reading enable.
 *
 * @return The capability burn after reading enable.
 *
 * @see @ref Mtc_CapDbSetCapBurnEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapBurnEn();

/**
 * @brief Get capability group qrcode enable.
 *
 * @return The capability group qrcode enable.
 *
 * @see @ref Mtc_CapDbSetCapGrpQrcodeEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapGrpQrcodeEn();

/**
 * @brief Get  burn after reading time length.
 *
 * @return The  burn after reading time length.
 *
 * @see @ref Mtc_CapDbSetCapBurnTimeLen
 */
ZFUNC ZUINT Mtc_CapDbGetCapBurnTimeLen();

/**
 * @brief Get capability ex-vcard enable.
 *
 * @return The capability ex-vcard enable.
 *
 * @see @ref Mtc_CapDbSetCapExvcardEn
 */
ZFUNC ZBOOL Mtc_CapDbGetCapExvcardEn();

/**
 * @brief Set capability info expire time.
 *
 * @param [in] iCapInfoExpiry capability info expires time.
 *
 * @retval ZOK Set capability info expire time successfully.
 * @retval ZFAILED Set capability info expire time failed.
 *
 * @see @ref Mtc_CapDbGetCapInfoExpire
 */
ZFUNC ZINT Mtc_CapDbSetCapInfoExpire(ZUINT iCapInfoExpiry);

/**
 * @brief Set capability polling period.
 *
 * @param [in] iPollingPeriod capability polling period.
 *
 * @retval ZOK Set capability polling period successfully.
 * @retval ZFAILED Set capability polling period failed.
 *
 * @see @ref Mtc_CapDbGetCapPollingPeriod
 */
ZFUNC ZINT Mtc_CapDbSetCapPollingPeriod(ZUINT iPollingPeriod);

/**
 * @brief Set capability Polling Rate.
 *
 * @param [in] iPollingRate maximum rate.
 *
 * @retval ZOK Set polling rate successfully.
 * @retval ZFAILED Set polling rate failed.
 *
 * @see @ref Mtc_CapDbGetCapPollingRate
 */
ZFUNC ZINT Mtc_CapDbSetCapPollingRate(ZUINT iPollingRate);

/**
 * @brief Set capability Polling Rate Period
 *
 * @param [in] iPollingRatePeriod polling rate period.
 *
 * @retval ZOK Set polling rate successfully.
 * @retval ZFAILED Set polling rate failed.
 *
 * @see @ref Mtc_CapDbGetCapPollingRatePeriod
 */
ZFUNC ZINT Mtc_CapDbSetCapPollingRatePeriod(ZUINT iPollingRatePeriod);

/**
 * @brief Set default discovery mechanism.
 *
 * @param [in] bDefaultDisc enable discovery mechanism.
 *
 * @retval ZOK Set default discovery mechanism successfully.
 * @retval ZFAILED Set default discovery mechanism failed.
 *
 * @see @ref Mtc_CapDbGetCapDefaultDisc
 */
ZFUNC ZINT Mtc_CapDbSetCapDefaultDisc(ZBOOL bDefaultDisc);

/**
 * @brief Set discovery common stack.
 *
 * @param [in] bCapDiscCommonStack enable discovery common stack.
 *
 * @retval ZOK Set discovery common stack successfully.
 * @retval ZFAILED Set discovery common stack failed.
 *
 * @see @ref Mtc_CapDbGetCapDiscCommonStack
 */
ZFUNC ZINT Mtc_CapDbSetCapDiscCommonStack(ZBOOL bCapDiscCommonStack);

/**
 * @brief Set discovery via presence enable.
 *
 * @param [in] bDiscViaPresEnable enable discovery via presence.
 *
 * @retval ZOK Set discovery via presence enable successfully.
 * @retval ZFAILED Set discovery via presence enable failed.
 *
 * @see @ref Mtc_CapDbGetCapDiscViaPresEnable
 */
ZFUNC ZINT Mtc_CapDbSetCapDiscViaPresEnable(ZBOOL bDiscViaPresEnable);

/**
 * @brief Set capability messaging capabilities validity.
 *
 * @param [in] iMsgCapValidity the messaging capabilities validity.
 *
 * @retval ZOK Set messaging capabilities validity successfully.
 * @retval ZFAILED Set messaging capabilities validity failed.
 *
 * @see @ref Mtc_CapDbGetCapMsgCapValidity
 */
ZFUNC ZINT Mtc_CapDbSetCapMsgCapValidity(ZUINT iMsgCapValidity);

/**
 * @brief Set capability tag converg flag.
 *
 * @param [in] bTagConverg If ZTRUE, the feature tag in OPTIONS will converg.
 *
 * @retval ZOK Set capability tag converg flag successfully.
 * @retval ZFAILED Set capability tag converg flag failed.
 *
 * @see @ref Mtc_CapDbGetCapTagConverg
 */
ZFUNC ZINT Mtc_CapDbSetCapTagConverg(ZBOOL bTagConverg);

/**
 * @brief Set capability IM enable.
 *
 * @param [in] bIMEnable enable IM flag.
 *
 * @retval ZOK Set capability enable IM successfully.
 * @retval ZFAILED Set capability enable IM failed.
 *
 * @see @ref Mtc_CapDbGetCapIMEn
 */
ZFUNC ZINT Mtc_CapDbSetCapIMEn(ZBOOL bIMEnable);

/**
 * @brief Set capability file transfer enable.
 *
 * @param [in] bFTEnable enable file transfer flag.
 *
 * @retval ZOK Set capability enable file transfer successfully.
 * @retval ZFAILED Set capability enable file transfer failed.
 *
 * @see @ref Mtc_CapDbGetCapFTEn
 */
ZFUNC ZINT Mtc_CapDbSetCapFTEn(ZBOOL bFTEnable);

/**
 * @brief Set capability standalone messaging enable.
 *
 * @param [in] bStdMsgEnable enable standalone messaging.
 *
 * @retval ZOK Set capability enable standalone messaging successfully.
 * @retval ZFAILED Set capability enable standalone messaging failed.
 *
 */
ZFUNC ZINT Mtc_CapDbSetCapStdMsgEn(ZBOOL bStdMsgEnable);

/**
 * @brief Set capability video share outside of a voice call enable.
 *
 * @param [in] bVSOutVCEnable enable video share outside of a voice call.
 *
 * @retval ZOK Set capability enable video share outside of a voice call successfully.
 * @retval ZFAILED Set capability enable video share outside of a voice call failed.
 *
 * @see @ref Mtc_CapDbGetCapVSOutVCEn
 */
ZFUNC ZINT Mtc_CapDbSetCapVSOutVCEn(ZBOOL bVSOutVCEnable);

/**
 * @brief Set capability video share enable.
 *
 * @param [in] bVSEnable enable video share.
 *
 * @retval ZOK Set capability enable video share successfully.
 * @retval ZFAILED Set capability enable video share failed.
 *
 * @see @ref Mtc_CapDbGetCapVSEn
 */
ZFUNC ZINT Mtc_CapDbSetCapVSEn(ZBOOL bVSEnable);

/**
 * @brief Set capability image share enable.
 *
 * @param [in] bISEnable enable image share.
 *
 * @retval ZOK Set capability enable image share successfully.
 * @retval ZFAILED Set capability enable image share failed.
 *
 * @see @ref Mtc_CapDbGetCapISEn
 */
ZFUNC ZINT Mtc_CapDbSetCapISEn(ZBOOL bISEnable);

/**
 * @brief Set capability discovery presence enable.
 *
 * @param [in] bDPEnable enable discovery presence.
 *
 * @retval ZOK Set capability enable discovery presence successfully.
 * @retval ZFAILED Set capability enable discovery presence failed.
 *
 * @see @ref Mtc_CapDbGetCapDPEn
 */
ZFUNC ZINT Mtc_CapDbSetCapDPEn(ZBOOL bDPEnable);

/**
 * @brief Set capability social presence enable.
 *
 * @param [in] bSPEnable enable social presence.
 *
 * @retval ZOK Set capability social presence enable successfully.
 * @retval ZFAILED Set capability social presence enable failed.
 *
 * @see @ref Mtc_CapDbGetCapSPEn
 */
ZFUNC ZINT Mtc_CapDbSetCapSPEn(ZBOOL bSPEnable);

/**
 * @brief Set capability IP voice call enable.
 *
 * @param [in] bVoiceCallEnable enable IP voice call.
 *
 * @retval ZOK Set capability IP voice call enable successfully.
 * @retval ZFAILED Set capability IP voice call enable failed.
 *
 * @see @ref Mtc_CapDbGetCapVoicCallEn
 */
ZFUNC ZINT Mtc_CapDbSetCapVoicCallEn(ZBOOL bVoiceCallEnable);

/**
 * @brief Set capability IP video call enable.
 *
 * @param [in] bVideoCallEnable enable IP video call.
 *
 * @retval ZOK Set capability IP video call enable successfully.
 * @retval ZFAILED Set capability IP video call enable failed.
 *
 * @see @ref Mtc_CapDbGetCapVideoCallEn
 */
ZFUNC ZINT Mtc_CapDbSetCapVideoCallEn(ZBOOL bVideoCallEnable);

/**
 * @brief Set capability geolocation pull enable.
 *
 * @param [in] bGeoPullEnable enable geolocation pull.
 *
 * @retval ZOK Set capability geolocation pull enable successfully.
 * @retval ZFAILED Set capability geolocation pull enable failed.
 *
 * @see @ref Mtc_CapDbGetCapGeoPullEn
 */
ZFUNC ZINT Mtc_CapDbSetCapGeoPullEn(ZBOOL bGeoPullEnable);

/**
 * @brief Set capability geolocation push enable.
 *
 * @param [in] bGeoPushEnable enable geolocation push.
 *
 * @retval ZOK Set capability geolocation push enable successfully.
 * @retval ZFAILED Set capability geolocation push enable failed.
 *
 * @see @ref Mtc_CapDbGetCapGeoPushEn
 */
ZFUNC ZINT Mtc_CapDbSetCapGeoPushEn(ZBOOL bGeoPushEnable);

/**
 * @brief Set capability full store and forward for group chat enable.
 *
 * @param [in] bGpChatFStFwdEnable enable full store and forward for group chat.
 *
 * @retval ZOK Set capability full store and forward for group chat enable successfully.
 * @retval ZFAILED Set capability full store and forward for group chat enable failed.
 *
 * @see @ref Mtc_CapDbGetCapGpChatFStFwdEn
 */
ZFUNC ZINT Mtc_CapDbSetCapGpChatFStFwdEn(ZBOOL bGpChatFStFwdEnable);

/**
 * @brief Set capability file transfer thumbnail enable.
 *
 * @param [in] bFTThumbEnable enable file transfer thumbnail.
 *
 * @retval ZOK Set capability file transfer thumbnail enable successfully.
 * @retval ZFAILED Set capability file transfer thumbnail enable failed.
 *
 * @see @ref Mtc_CapDbGetCapFTThumbEn
 */
ZFUNC ZINT Mtc_CapDbSetCapFTThumbEn(ZBOOL bFTThumbEnable);

/**
 * @brief Set capability file transfer store and forward enable.
 *
 * @param [in] bFTStFwdEnable enable file transfer store and forward.
 *
 * @retval ZOK Set capability file transfer store and forward enable successfully.
 * @retval ZFAILED Set capability file transfer store and forward enable failed.
 *
 * @see @ref Mtc_CapDbGetCapFTStFwdEn
 */
ZFUNC ZINT Mtc_CapDbSetCapFTStFwdEn(ZBOOL bFTStFwdEnable);

/**
 * @brief Set capability file transfer via HTTP enable.
 *
 * @param [in] bFTHTTPEnable enable file transfer via HTTP.
 *
 * @retval ZOK Set capability file transfer via HTTP enable successfully.
 * @retval ZFAILED Set capability file transfer via HTTP enable failed.
 *
 * @see @ref Mtc_CapDbGetCapFTHTTPEn
 */
ZFUNC ZINT Mtc_CapDbSetCapFTHTTPEn(ZBOOL bFTHTTPEnable);

/**
 * @brief Set capability geolocation pull using file transfer enable.
 *
 * @param [in] bGeoPullFTEnable enable geolocation pull using file transfer.
 *
 * @retval ZOK Set capability geolocation pull using file transfer enable successfully.
 * @retval ZFAILED Set capability geolocation pull using file transfer enable failed.
 *
 * @see @ref Mtc_CapDbGetCapGeoPullFTEn
 */
ZFUNC ZINT Mtc_CapDbSetCapGeoPullFTEn(ZBOOL bGeoPullFTEnable);

/**
 * @brief Set capability public message enable.
 *
 * @param [in] bPubMsgEnable enable public message.
 *
 * @retval ZOK Set capability public message enable successfully.
 * @retval ZFAILED Set capability public message enable failed.
 *
 * @see @ref Mtc_CapDbGetCapPubMsgEn
 */
ZFUNC ZINT Mtc_CapDbSetCapPubMsgEn(ZBOOL bPubMsgEnable);

/**
 * @brief Set capability cloud file enable.
 *
 * @param [in] bCloudFileEnable cloud file message.
 *
 * @retval ZOK Set capability cloud file enable successfully.
 * @retval ZFAILED Set capability cloud file enable failed.
 *
 * @see @ref Mtc_CapDbGetCapCloudFileEn
 */
ZFUNC ZINT Mtc_CapDbSetCapCloudFileEn(ZBOOL bCloudFileEnable);

/**
 * @brief Set capability vemoticon enable.
 *
 * @param [in] bVemEnable vemoticon message.
 *
 * @retval ZOK Set capability vemoticon enable successfully.
 * @retval ZFAILED Set capability vemoticon enable failed.
 *
 * @see @ref Mtc_CapDbGetCapVemEn
 */
ZFUNC ZINT Mtc_CapDbSetCapVemEn(ZBOOL bVemEnable);

/**
 * @brief Set capability group manage enable.
 *
 * @param [in] bGrpManEnable group manage.
 *
 * @retval ZOK Set capability group manage enable successfully.
 * @retval ZFAILED Set capability group manage enable failed.
 *
 * @see @ref Mtc_CapDbGetCapGrpManEn
 */
ZFUNC ZINT Mtc_CapDbSetCapGrpManEn(ZBOOL bGrpManEnable);

/**
 * @brief Set capability cpm message enable.
 *
 * @param [in] bGrpManEnable cpm message.
 *
 * @retval ZOK Set capability cpm message enable successfully.
 * @retval ZFAILED Set capability cpm message enable failed.
 *
 * @see @ref Mtc_CapDbGetCapCpmMsgEn
 */
ZFUNC ZINT Mtc_CapDbSetCapCpmMsgEn(ZBOOL bCpmMsgEnable);

/**
 * @brief Set capability cpm large message enable.
 *
 * @param [in] bGrpManEnable cpm large message.
 *
 * @retval ZOK Set capability cpm large message enable successfully.
 * @retval ZFAILED Set capability cpm large message enable failed.
 *
 * @see @ref Mtc_CapDbGetCapCpmLargeEn
 */
ZFUNC ZINT Mtc_CapDbSetCapCpmLargeEn(ZBOOL bCpmLargeEnable);

/**
 * @brief Set capability cpm file transfer enable.
 *
 * @param [in] bGrpManEnable cpm file transfer.
 *
 * @retval ZOK Set capability cpm file transfer enable successfully.
 * @retval ZFAILED Set capability cpm file transfer enable failed.
 *
 * @see @ref Mtc_CapDbGetCapCpmFtEn
 */
ZFUNC ZINT Mtc_CapDbSetCapCpmFtEn(ZBOOL bCpmFtEnable);

/**
 * @brief Set capability cpm session enable.
 *
 * @param [in] bGrpManEnable cpm session.
 *
 * @retval ZOK Set capability cpm session enable successfully.
 * @retval ZFAILED Set capability cpm session enable failed.
 *
 * @see @ref Mtc_CapDbGetCapCpmSessEn
 */
ZFUNC ZINT Mtc_CapDbSetCapCpmSessEn(ZBOOL bCpmSessEnable);

/**
 * @brief Set capability ex-vcard enable.
 *
 * @param [in] bXvcardEnable ex-vcard enable.
 *
 * @retval ZOK Set capability ex-vcard enable successfully.
 * @retval ZFAILED Set capability ex-vcard enable failed.
 *
 * @see @ref Mtc_CapDbGetCapExvcardEn
 */
ZFUNC ZINT Mtc_CapDbSetCapExvcardEn(ZBOOL bExvcardEnable);

/**
 * @brief Set capability burn after reading enable.
 *
 * @param [in] bBurnEnable enable burn after reading function.
 *
 * @retval ZOK Set capability burn after reading enable successfully.
 * @retval ZFAILED Set capability burn after reading enable failed.
 *
 * @see @ref Mtc_CapDbGetCapBurnEn
 */
ZFUNC ZINT Mtc_CapDbSetCapBurnEn(ZBOOL bBurnEnable);

/**
 * @brief Set capability group qrcode enable.
 *
 * @param [in] bGrpQrcodeEnable enable group qrcode function.
 *
 * @retval ZOK Set capability group qrcode enable successfully.
 * @retval ZFAILED Set capability group qrcode enable failed.
 *
 * @see @ref Mtc_CapDbGetCapGrpQrcodeEn
 */
ZFUNC ZINT Mtc_CapDbSetCapGrpQrcodeEn(ZBOOL bGrpQrcodeEnable);

/**
 * @brief Set burn after reading time length.
 *
 * @param [in] iBurnTimeLen burn after reading time length.
 *
 * @retval ZOK Set burn after reading time length successfully.
 * @retval ZFAILED Set burn after reading time length failed.
 *
 * @see @ref Mtc_CapDbGetCapBurnTimeLen
 */
ZFUNC ZINT Mtc_CapDbSetCapBurnTimeLen(ZUINT iBurnTimeLen);

#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_CAP_DB_H__ */

