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
  File name     : mtc_pres_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2010-02-06
  Description   :
      Data structure and function declare required by MTC presence database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PRES_DB_H__
#define _MTC_PRES_DB_H__

/**
 * @file mtc_pres_db.h
 * @brief MTC Presence Database Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC presence favlink mode type */
typedef enum EN_MTC_PRES_FAVLINK_MODE_TYPE
{
    EN_MTC_PRES_FAVLINK_MODE_UNKNOWN,    /**< @brief unknown */
    EN_MTC_PRES_FAVLINK_MODE_AUTO,       /**< @brief auto */
    EN_MTC_PRES_FAVLINK_MODE_MAN,        /**< @brief manual */
    EN_MTC_PRES_FAVLINK_MODE_BOTH,       /**< @brief both anto and manual */
} EN_MTC_PRES_FAVLINK_MODE_TYPE;

/**
 * @brief Get presence publish entity tag.
 *
 * @return Presence publish entity tag.
 *
 * @see @ref Mtc_PresDbSetPubETag
 */
ZFUNC ZCHAR * Mtc_PresDbGetPubETag(ZFUNC_VOID);

/**
 * @brief Get presence publish expires.
 *
 * @return Presence publish expires, default is 3600 seconds.
 *
 * @see @ref Mtc_PresDbSetPubPresExpire
 */
ZFUNC ZUINT Mtc_PresDbGetPubPresExpire(ZFUNC_VOID);

/**
 * @brief Get presence subscription expires.
 *
 * @return Presence subscription expires, default is 3600 seconds.
 *
 * @see @ref Mtc_PresDbSetSubsPresExpire
 */
ZFUNC ZUINT Mtc_PresDbGetSubsPresExpire(ZFUNC_VOID);

/**
 * @brief Get presence winfo subscription expires.
 *
 * @return Presence winfo subscription expires, default is 3600 seconds.
 *
 * @see @ref Mtc_PresDbSetSubsWinfoExpire
 */
ZFUNC ZUINT Mtc_PresDbGetSubsWinfoExpire(ZFUNC_VOID);

/**
 * @brief Get presence hyper availability period.
 *
 * @return Presence hyper availability period, default is 7200 seconds.
 *
 * @see @ref Mtc_PresDbSetHyperAvailPeriod
 */
ZFUNC ZUINT Mtc_PresDbGetHyperAvailPeriod(ZFUNC_VOID);

/**
 * @brief Get presence profile.
 *
 * @return Presence profile enable flag.
 *
 * @see @ref Mtc_PresDbSetPresProf
 */
ZFUNC ZBOOL Mtc_PresDbGetPresProf(ZFUNC_VOID);

/**
 * @brief Get presence client object data limit.
 *
 * @return Presence client object data limit in bytes.
 */
ZFUNC ZUINT Mtc_PresDbGetCliObjDtlmt(ZFUNC_VOID);

/**
 * @brief Get presence content server uri.
 *
 * @return Presence content server uri.
 */
ZFUNC ZCHAR * Mtc_PresDbGetCttSrvUri(ZFUNC_VOID);

/**
 * @brief Get presence source throttle publish.
 *
 * @return Presence source throttle publish.
 */
ZFUNC ZUINT Mtc_PresDbGetSrcThrtPub(ZFUNC_VOID);

/**
 * @brief Get presence max number of subscriptions.
 *
 * @return Presence max number of subscriptions.
 */
ZFUNC ZUINT Mtc_PresDbGetMaxSubsNum(ZFUNC_VOID);

/**
 * @brief Get presence service uri template.
 *
 * @return Presence service uri template.
 */
ZFUNC ZCHAR * Mtc_PresDbGetSrvUriTmpl(ZFUNC_VOID);

/**
 * @brief Get presence rls uri.
 *
 * @return Presence rls uri.
 */
ZFUNC ZCHAR * Mtc_PresDbGetRlsUri(ZFUNC_VOID);

/**
 * @brief Get presence availability authorisation.
 *
 * @return Presence availability authorisation.
 */
ZFUNC ZBOOL Mtc_PresDbGetAvailAuth(ZFUNC_VOID);

/**
 * @brief Get presence auto manual type.
 *
 * @return Presence auto manual type, @see @ref EN_MTC_PRES_FAVLINK_MODE_TYPE.
 */
ZFUNC ZUINT Mtc_PresDbGetAutoMan(ZFUNC_VOID);

/**
 * @brief Get presence option favourite uri.
 *
 * @return Presence option favourite uri.
 */
ZFUNC ZCHAR * Mtc_PresDbGetOptFavUri(ZFUNC_VOID);

/**
 * @brief Get presence label max length.
 *
 * @return Presence label max length in bytes.
 */
ZFUNC ZUINT Mtc_PresDbGetLabelMaxLen(ZFUNC_VOID);

/**
 * @brief Get presence icon max size.
 *
 * @return Presence icon max size in bytes.
 */
ZFUNC ZUINT Mtc_PresDbGetIconMaxSize(ZFUNC_VOID);

/**
 * @brief Get presence note max size.
 *
 * @return Presence note max size in bytes.
 */
ZFUNC ZUINT Mtc_PresDbGetNoteMaxSize(ZFUNC_VOID);

/**
 * @brief Get presence publish timer length.
 *
 * @return Presence publish timer length in bytes.
 */
ZFUNC ZUINT Mtc_PresDbGetPubTmrLen(ZFUNC_VOID);

/**
 * @brief Get presence nick name length.
 *
 * @return Presence nick name length in bytes.
 */
ZFUNC ZUINT Mtc_PresDbGetNickNameLen(ZFUNC_VOID);

/**
 * @brief Get presence text max length.
 *
 * @return Presence text max length in bytes.
 */
ZFUNC ZUINT Mtc_PresDbGetTxtMaxLen(ZFUNC_VOID);

/**
 * @brief Get presence location information max valid time.
 *
 * @return Presence location information max valid time in seconds.
 */
ZFUNC ZUINT Mtc_PresDbGetLocInfoMaxValidTime(ZFUNC_VOID);

/**
 * @brief Get presence non-vip poll period setting.
 *
 * @return Presence non-vip poll period setting in seconds.
 */
ZFUNC ZUINT Mtc_PresDbGetNonVipPollPeriodSet(ZFUNC_VOID);

/**
 * @brief Get presence non-vip poll per period.
 *
 * @return Presence non-vip poll per period.
 */
ZFUNC ZUINT Mtc_PresDbGetNonVipPollPerPeriod(ZFUNC_VOID);

/**
 * @brief Set presence publish entity tag.
 *
 * @param [in] pcEntTag The publish entity tag
 *
 * @retval ZOK Set presence publish entity tag successfully.
 * @retval ZFAILED Set presence publish entity tag failed.
 *
 * @see @ref Mtc_PresDbGetPubETag
 */
ZFUNC ZINT Mtc_PresDbSetPubETag(ZCHAR *pcEntTag);

/**
 * @brief Set presence publish expires.
 *
 * @param [in] iExpires The publish expires(second).
 *
 * @retval ZOK Set presence publish expires successfully.
 * @retval ZFAILED Set presence publish expires failed.
 *
 * @see @ref Mtc_PresDbGetPubPresExpire
 */
ZFUNC ZINT Mtc_PresDbSetPubPresExpire(ZUINT iExpires);

/**
 * @brief Set presence subscription expires.
 *
 * @param [in] iExpires The subscription expires(second).
 *
 * @retval ZOK Set presence subscription expires successfully.
 * @retval ZFAILED Set presence subscription expires failed.
 *
 * @see @ref Mtc_PresDbGetSubsPresExpire
 */
ZFUNC ZINT Mtc_PresDbSetSubsPresExpire(ZUINT iExpires);

/**
 * @brief Set presence winfo subscription expires.
 *
 * @param [in] iExpires The winfo subscription expires(second).
 *
 * @retval ZOK Set presence winfo subscription expires successfully.
 * @retval ZFAILED Set presence winfo subscription expires failed.
 *
 * @see @ref Mtc_PresDbGetSubsWinfoExpire
 */
ZFUNC ZINT Mtc_PresDbSetSubsWinfoExpire(ZUINT iExpires);

/**
 * @brief Set presence hyper availability period.
 *
 * @param [in] iPeriod The hyper availability period(second).
 *
 * @retval ZOK Set presence hyper availability period successfully.
 * @retval ZFAILED Set presence hyper availability period failed.
 *
 * @see @ref Mtc_PresDbGetHyperAvailPeriod
 */
ZFUNC ZINT Mtc_PresDbSetHyperAvailPeriod(ZUINT iPeriod);

/**
 * @brief Set presence profile enable.
 *
 * @param [in] bEnable The presence profile enable.
 *
 * @retval ZOK Set presence profile enable successfully.
 * @retval ZFAILED Set presence profile enable failed.
 *
 * @see @ref Mtc_PresDbGetPresProf
 */
ZFUNC ZINT Mtc_PresDbSetPresProf(ZBOOL bEnable);

#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_PRES_DB_H__ */

