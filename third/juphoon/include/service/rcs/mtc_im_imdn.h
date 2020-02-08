/************************************************************************

        Copyright (c) 2005-2013 by Juphoon System Software, Inc.
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
  File name     : mtc_im_imdn.h
  Module        : multimedia talk client
  Author        : anthouny.zhou
  Created on    : 2013-03-06
  Description   :
      Data structure and function declare required by MTC IM imdn.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_IMDN_H__
#define _MTC_IM_IMDN_H__

/**
 * @file mtc_im_imdn.h
 * @brief MTC Instant Message Imdn Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief MTC Sending a display notification through imdn.
 *
 * @param [in] zCookie The user cookie. 
 * @param [in] pcIMsgId The The imdn message id.
 * @param [in] pcUri The message receiver URI.
 *
 * @retval ZOK Send a display notification successfully.
 * @retval ZFAILED Send a display notification failed.
 */
ZFUNC ZINT Mtc_ImdnSendDisp(ZCOOKIE zCookie, ZCHAR *pcIMsgId, 
                ZCHAR *pcUri);

/**
 * @brief MTC Sending a delivery notification through imdn.
 *
 * @param [in] zCookie The user cookie. 
 * @param [in] pcIMsgId The The imdn message id.
 * @param [in] pcUri The message receiver URI.
 *
 * @retval ZOK Send a delivery notification successfully.
 * @retval ZFAILED Send a delivery notification failed.
 */
ZFUNC ZINT Mtc_ImdnSendDeli(ZCOOKIE zCookie, ZCHAR *pcIMsgId, 
                ZCHAR *pcUri);

/**
 * @brief MTC Sending a display notification through imdn in group chat.
 *
 * @param [in] zCookie The user cookie. 
 * @param [in] pcIMsgId The The imdn message id.
 * @param [in] pcGrpUri The group URI. 
 * @param [in] pcUri The message receiver URI.
 * @param [in] pcConvId The message conversation id.
 *
 * @retval ZOK Send a display notification successfully.
 * @retval ZFAILED Send a display notification failed.
 */
ZFUNC ZINT Mtc_ImdnSendDispG(ZCOOKIE zCookie, ZCHAR *pcIMsgId, 
                ZCHAR *pcGrpUri, ZCHAR *pcUri, ZCHAR *pcConvId);

/**
 * @brief MTC Sending a delivery notification through imdn in group chat.
 *
 * @param [in] zCookie The user cookie. 
 * @param [in] pcIMsgId The The imdn message id.
 * @param [in] pcGrpUri The group URI.  
 * @param [in] pcUri The message receiver URI.
 * @param [in] pcConvId The message conversation id.
 *
 * @retval ZOK Send a delivery notification successfully.
 * @retval ZFAILED Send a delivery notification failed.
 */
ZFUNC ZINT Mtc_ImdnSendDeliG(ZCOOKIE zCookie, ZCHAR *pcIMsgId, 
                ZCHAR *pcGrpUri, ZCHAR *pcUri, ZCHAR *pcConvId);


/**
 * @brief MTC Sending a burned notification through imdn.
 *
 * @param [in] zCookie The user cookie. 
 * @param [in] pcIMsgId The The imdn message id.
 * @param [in] pcUri The message receiver URI.
 * @param [in] pcDeviceId The message receiver device id.
 * @param [in] pcConvId The message conversation id.
 *
 * @retval ZOK Send a burned notification successfully.
 * @retval ZFAILED Send a burned notification failed.
 */
ZFUNC ZINT Mtc_ImdnSendBurn(ZCOOKIE zCookie, ZCHAR *pcIMsgId, 
                ZCHAR *pcUri, ZCHAR *pcDeviceId, ZCHAR *pcConvId);

/**
 * @brief Get imdn message id from imdn.
 *
 * @param [in] iImdnId The imdn id.
 *
 * @return Imdn message id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImdnGetIMsgId(ZUINT iImdnId);

/**
 * @brief MTC Get participant information from imdn.
 *
 * The participant is the remote client who send a imdn notification message.
 *
 * @param [in] iImdnId The imdn id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImdnGetPartp(ZUINT iImdnId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief Get user cookie from imdn.
 *
 * @param [in] iImdnId The imdn id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImdnGetCookie(ZUINT iImdnId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_IMDN_H__ */
