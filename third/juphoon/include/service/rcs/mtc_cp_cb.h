/************************************************************************

        Copyright (c) 2005-2012 by Juphoon System Software, Inc.
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
  File name     : mtc_cp_cb.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2012-08-11
  Description   :
      Data structure and function declare required by MTC client 
      provisioning callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CP_CB_H__
#define _MTC_CP_CB_H__

/**
 * @file mtc_cp_cb.h
 * @brief MTC Client Provisioning Callback Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC client provisioning callback. */
typedef ZVOID (*PFN_MTCCPCB)(ZFUNC_VOID);

/** @brief Type define of MTC client provisioning ok callback. */
typedef ZVOID (*PFN_MTCCPOKCB)(ZUINT iCpId);

/** @brief Type define of MTC client provisioning failed callback. */
typedef ZVOID (*PFN_MTCCPFAILEDCB)(ZUINT iCpId, ZCHAR *pcRspCode, 
                ZUINT iStatCode);

/** @brief Type define of MTC client provisioning receive message callback. */
typedef ZVOID (*PFN_MTCCPRECVMSGCB)(ZUINT iCpId, ZCHAR *pcTitle, 
                ZCHAR *pcMsg);

/** @brief Type define of MTC client provisioning prompt callback. */
typedef ZVOID (*PFN_MTCCPPROMPTCB)(ZUINT iCpId);

/** 
* @brief Type define of MTC client provisioning expire callback. 
* @param iExpireType The expire type(see @ref EN_MTC_CP_EXPIRE_TYPE).
*/
typedef ZVOID (*PFN_MTCCPEXPIRECB)(ZUINT iExpireType);

/** @brief Type define of MTC client provisioning end user message confirmation request callback. */
typedef ZVOID (*PFN_MTCCPEMSGREQCB)(ZUINT iMsgId, ZCHAR *pcSubject, 
                ZCHAR *pcText, ZCHAR *pcAcptBtnTxt, ZCHAR *pcDeclBtnTxt, 
                ZBOOL bNeedPIN);

/** @brief Type define of MTC client provisioning end user message confirmation ack callback. */
typedef ZVOID (*PFN_MTCCPEMSGACKCB)(ZUINT iMsgId, ZCHAR *pcSubject, 
                ZCHAR *pcText);

/** @brief Type define of MTC client provisioning end user message notification callback. */
typedef ZVOID (*PFN_MTCCPEMSGNTFYCB)(ZUINT iMsgId, ZCHAR *pcSubject, 
                ZCHAR *pcText, ZCHAR *pcOKBtnTxt);

/** 
 * @brief MTC client provisioning ok callback.
 * 
 * @param [in] pfnCb The callback will be notify provisioning ok.
 */
ZFUNC ZVOID Mtc_CpCbSetCpOk(PFN_MTCCPOKCB pfnCb);

/** 
 * @brief MTC client provisioning failed callback.
 * 
 * @param [in] pfnCb The callback will be notify provisioning failed.
 */
ZFUNC ZVOID Mtc_CpCbSetCpFailed(PFN_MTCCPFAILEDCB pfnCb);

/** 
 * @brief MTC client provisioning expire callback.
 * 
 * @param [in] pfnCb The callback will be notify provisioning expire.
 */
ZFUNC ZVOID Mtc_CpCbSetCpExpire(PFN_MTCCPEXPIRECB pfnCb);

/** 
 * @brief MTC client provisioning configure indication callback.
 * 
 * @param [in] pfnCb The callback will be notify provisioning configure indication.
 */
ZFUNC ZVOID Mtc_CpCbSetCpCfgInd(PFN_MTCCPCB pfnCb);

/** 
 * @brief MTC client provisioning reconfigure indication callback.
 * 
 * @param [in] pfnCb The callback will be notify provisioning reconfigure indication.
 */
ZFUNC ZVOID Mtc_CpCbSetCpReCfgInd(PFN_MTCCPCB pfnCb);

/** 
 * @brief MTC client provisioning authorizaiton indication callback.
 * 
 * @param [in] pfnCb The callback will be notify provisioning authorizaiton indication.
 */
ZFUNC ZVOID Mtc_CpCbSetCpAuthInd(PFN_MTCCPOKCB pfnCb);

/** 
 * @brief MTC auto client provisioning authorizaiton indication callback.
 * 
 * @param [in] pfnCb The callback will be notify provisioning authorizaiton indication.
 */
ZFUNC ZVOID Mtc_CpCbSetCpAutoAuthInd(PFN_MTCCPOKCB pfnCb);

/** 
 * @brief MTC client provisioning receive message callback.
 * 
 * @param [in] pfnCb The callback will be notify provisioning receive message.
 */
ZFUNC ZVOID Mtc_CpCbSetCpRecvMsg(PFN_MTCCPRECVMSGCB pfnCb);

/** 
 * @brief MTC client provisioning prompt for OTP callback by primary device.
 * 
 * @param [in] pfnCb The callback will be notify provisioning prompt for MSISDN.
 */
ZFUNC ZVOID Mtc_CpCbSetCpPromptMSISDN(PFN_MTCCPPROMPTCB pfnCb);

/** 
 * @brief MTC client provisioning prompt for OTP callback over SMS by primary device.
 * 
 * @param [in] pfnCb The callback will be notify provisioning prompt for OTP.
 */
ZFUNC ZVOID Mtc_CpCbSetCpPromptOTP(PFN_MTCCPPROMPTCB pfnCb);

/** 
 * @brief MTC client provisioning prompt for OTP callback over SMS by additional device.
 * 
 * @param [in] pfnCb The callback will be notify provisioning prompt for OTP.
 */
ZFUNC ZVOID Mtc_CpCbSetCpPromptOTPSMS(PFN_MTCCPPROMPTCB pfnCb);

/** 
 * @brief MTC client provisioning prompt for OTP callback over PIN by additional device.
 * 
 * @param [in] pfnCb The callback will be notify provisioning prompt for OTP.
 */
ZFUNC ZVOID Mtc_CpCbSetCpPromptOTPPIN(PFN_MTCCPPROMPTCB pfnCb);

/** 
 * @brief MTC client provisioning receive end user message confirmation request.
 * 
 * @param [in] pfnCb The callback will be notify when receive end user message confirmation request.
 */
ZFUNC ZVOID Mtc_CpCbSetEMsgReq(PFN_MTCCPEMSGREQCB pfnCb);

/** 
 * @brief MTC client provisioning receive end user message confirmation ack.
 * 
 * @param [in] pfnCb The callback will be notify when receive end user message confirmation ack.
 */
ZFUNC ZVOID Mtc_CpCbSetEMsgAck(PFN_MTCCPEMSGACKCB pfnCb);

/** 
 * @brief MTC client provisioning receive end user message notification.
 * 
 * @param [in] pfnCb The callback will be notify when receive end user message notification.
 */
ZFUNC ZVOID Mtc_CpCbSetEMsgNtfy(PFN_MTCCPEMSGNTFYCB pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CP_CB_H__ */

