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
  File name     : mtc_lcs.h
  Module        : multimedia talk client
  Author        : steven.wu
  Created on    : 2013-09-18
  Description   :
      Function implement required by mtc licsence.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_LCS_H__
#define _MTC_LCS_H__

/**
 * @file mtc_lcs.h
 * @brief MTC lcs Interface Functions
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC OMA buddy status code. */
#define MTC_LCS_ERR_NEED_ACT_LICSEN     (MTC_EBASE_LCS + 1) /**< @brief not activate licsence, need activate it */
#define MTC_LCS_ERR_GET_DEVICEID_FAIL  (MTC_EBASE_LCS + 2)  /**< @brief get device id failed */
#define MTC_LCS_ERR_GET_INIT_FAIL  (MTC_EBASE_LCS + 3)  /**< @brief init failed */

/**
 * @brief activate the license
 *
 * The result will be notified by callbacks Mtc_LcsCbActiveResult, 
 * when pfnProc.bActivated == ZTRUE, meaning activate license OK;
 * else meaing activate license FAILED
 *
 * @param [in] pcServer Server address.
 * @param [in] iPort Server port.
 * @param [in] pcUri The license request uri.
 * @param [in] pcFileName License name.
 * @param [in] pcName Company name.
 * @param [in] pcProductName Product name .
 *
 * @retval ZOK License active success
 * @retval ZFAILED License active failed.
 */
ZFUNC ZINT Mtc_LcsActivate(ZCONST ZCHAR *pcServer, ZUINT iPort, 
        ZCONST ZCHAR *pcUri,ZCONST ZCHAR *pcFileName, ZCONST ZCHAR *pcCompanyName, 
        ZCONST ZCHAR *pcProductName);

/**
 * @brief check if license has audio codec
 *
 * @retval ZOK License active success
 * @retval ZFAILED License active failed.
 */
ZFUNC ZBOOL Mtc_LcsHasAudioCodec();

/**
 * @brief get specified key size
 *
 * @param [in] pcSect Section name.
 * @param [in] pcKey Key name.
 *
 * @return The key size.
 */
ZFUNC ZUINT Mtc_LcsGetSpecifiedKeySize(ZCHAR *pcSect, ZCHAR *pcKey);

/**
 * @brief get specified key value by index
 *
 * @param [in] pcSect Section name.
 * @param [in] pcKey Key name.
 * @param [in] iIndex Key index.
 *
 * @return The key value.
 */
ZFUNC ZCHAR * Mtc_LcsGetSpecifiedKeyVal(ZCHAR *pcSect, ZCHAR *pcKey, 
                ZUINT iIndex);
                
/**
 * @brief mtc license event leave
 *
 * @param [in] bLicenseActive license active.
 *
 * @retval ZOK License active success
 * @retval ZFAILED License active failed.
 */
ZFUNC ZINT Mtc_LcsEvntLeave(ZBOOL bLicenseActive);

/**
 * @brief mtc license active event
 *
 * @param [in] zEvntId event id.
 *
 * @retval ZOK License active success
 */
ZFUNC ZINT Mtc_LcsActiveEvnt(ZEVNT zEvntId);


#ifdef __cplusplus
}
#endif

#endif /* _MTC_LCS_H__ */

