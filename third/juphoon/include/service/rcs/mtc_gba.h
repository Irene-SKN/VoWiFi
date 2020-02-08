/************************************************************************

        Copyright (c) 2005-2015 by Juphoon System Software, Inc.
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
  File name     : mtc_gba.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2015-04-29
  Description   :
      Function implement required by MTC GBA.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_GBA_H__
#define _MTC_GBA_H__

/**
 * @file mtc_gba.h
 * @brief MTC GBA Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC gba status code. */
#define MTC_GBA_ERR_NO               (MTC_EBASE_GBA + 0) /**< @brief no error */
#define MTC_GBA_ERR_AUTH_FAIL        (MTC_EBASE_GBA + 1) /**< @brief authentication failed */
#define MTC_GBA_ERR_PICK_XML         (MTC_EBASE_GBA + 2) /**< @brief pick xml */
#define MTC_GBA_ERR_TIMEOUT          (MTC_EBASE_GBA + 3) /**< @brief timeout */
#define MTC_GBA_ERR_NETWORK          (MTC_EBASE_GBA + 4) /**< @brief network */
#define MTC_GBA_ERR_OTHER            (MTC_EBASE_GBA + 200) /**< @brief other */

/** @brief Type define of MTC GBA bootstrapping type */
typedef enum EN_MTC_GBA_BOOT_TYPE
{
    EN_MTC_GBA_BOOT_UNKNWON,
    EN_MTC_GBA_BOOT_ME,
    EN_MTC_GBA_BOOT_UICC,
} EN_MTC_GBA_BOOT_TYPE;

/** @brief Type define of ua security protocol identifier type */
typedef enum EN_MTC_GBA_UA_SEC_PROT_TYPE
{
    EN_MTC_GBA_UA_SEC_PROT_HTTP,
    EN_MTC_GBA_UA_SEC_PROT_IMAP,
} EN_MTC_GBA_UA_SEC_PROT_TYPE;

/**
 * @brief gba bootstrapping start.
 *
 * @param [in] iBootType The boot type, @see @ref EN_MTC_GBA_BOOT_TYPE.
 * @param [in] iCookie The user cookie.
 *
 * @return boot id successfully, otherwise ZMAXUINT.
 *
 * @see @ref Mtc_GbaBootStop
 */
ZFUNC ZUINT Mtc_GbaBootStart(ZUINT iBootType, ZUINT iCookie);

/**
 * @brief gba bootstrapping stop.
 *
 * @param [in] iBootId The boot id.
 *
 * @see @ref Mtc_GbaBootStart
 */
ZFUNC ZVOID Mtc_GbaBootStop(ZUINT iBootId);

/**
 * @brief gba enter security context.
 *
 * @param [in] iBootId The boot id.
 * @param [in] pcRsp The reponse.
 * @param [in] pcIk The ik.
 * @param [in] pcCk The ck.
 * @param [in] pcAuts The auts.
 *
 * @retval ZOK enter successfully.
 * @retval ZFAILED enter failed.
 */
ZFUNC ZINT Mtc_GbaAuthEnterSecCtx(ZUINT iBootId, ZCHAR *pcRsp, 
                ZCHAR *pcIk, ZCHAR *pcCk, ZCHAR *pcAuts);

/**
 * @brief gba set Ks_ext_NAF.
 *
 * @param [in] pcKsExtNaf The Ks_ext_NAF.
 *
 * @retval ZOK set successfully.
 * @retval ZFAILED set failed.
 */
ZFUNC ZINT Mtc_GbaAuthSetKsExtNaf(ZCHAR *pcKsExtNaf);

/**
 * @brief gba get Ks_NAF.
 *
 * @param [in] pcNafFqdn The naf fqdn.
 * @param [in] iUaSecProt The ua security protocol identifier type.
 *
 * @return Ks_NAF base64 string successfully, otherwise return empty string.
 *
 * @see @ref Mtc_GbaAuthGetBtid
 */
ZFUNC ZCHAR * Mtc_GbaAuthGetKsNaf(ZCHAR *pcNafFqdn, ZUINT iUaSecProt);

/**
 * @brief gba get B-TID.
 *
 * @return B-TID string successfully, otherwise return empty string.
 *
 * @see @ref Mtc_GbaAuthGetKsNaf
 */
ZFUNC ZCHAR * Mtc_GbaAuthGetBtid();

#ifdef __cplusplus
}
#endif
                
#endif /* _MTC_GBA_H__ */

