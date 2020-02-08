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
  File name     : mtc_pres_winfo.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by MTC OMA presence watcher info.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PRES_WINFO_H__
#define _MTC_PRES_WINFO_H__

/**
 * @file mtc_pres_winfo.h
 * @brief MTC Presence Watcher Information Interface Functions

 * <pre>
 *         subscribe,
 *         policy=       +----------+
 *         reject        |          |<------------------------+
 *         +------------>|terminated|<---------+              |
 *         |             |          |          |              |
 *         |             |          |          |noresource    |
 *         |             +----------+          |rejected      |
 *         |                  ^noresource      |deactivated   |
 *         |                  |rejected        |probation     |
 *         |                  |deactivated     |timeout       |noresource
 *         |                  |probation       |              |rejected
 *         |                  |giveup          |              |giveup
 *         |                  |                |              |approved
 *      +-------+         +-------+        +-------+          |
 *      |       |subscribe|       |approved|       |          |
 *      | init  |-------->|pending|------->|active |          |
 *      |       |no policy|       |        |       |          |
 *      |       |         |       |        |       |          |
 *      +-------+         +-------+        +-------+          |
 *         |                  |                ^              |
 *         | subscribe,       |                |              |
 *         +-----------------------------------+              |
 *           policy = accept  |            +-------+          |
 *                            |            |       |          |
 *                            |            |waiting|----------+
 *                            +----------->|       |
 *                             timeout     |       |
 *                                         +-------+
 * </pre>
 *
 * - EN_MTC_PRES_WINFO_STAT_PENDING:
 *   User received a subscription request, there is no authorization policy for the subscription.
 *   Server is awaiting an authorization decision.
 *   There is no presence notifications if presence state changed.
 *
 * - EN_MTC_PRES_WINFO_STAT_ACTIVE:
 *   User authorization decision is positive, it will generate presence notifications.
 *   There is no presence notifications if presence state changed.
 *
 * - EN_MTC_PRES_WINFO_STAT_WAITING:
 *   If a pending subscription suffers a timeout, it moves into the waiting state.
 *   If will enter terminated state while no resource, rejected, giveup and approved
 *
 * - EN_MTC_PRES_WINFO_STAT_TERM
 *   User authorization decision is negative, the subscription is rejected.
 *   The server can decide to end a pending or waiting subscription with giveup event.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC presence watcher info status type  */
typedef enum EN_MTC_PRES_WINFO_STAT_TYPE
{
    EN_MTC_PRES_WINFO_STAT_PENDING,  /**< @brief pending status */
    EN_MTC_PRES_WINFO_STAT_ACTIVE,   /**< @brief active status */
    EN_MTC_PRES_WINFO_STAT_WAITING,  /**< @brief waiting status */
    EN_MTC_PRES_WINFO_STAT_TERM      /**< @brief terminated status */
} EN_MTC_PRES_WINFO_STAT_TYPE;

/** @brief MTC presence watcher info event type */
typedef enum EN_MTC_PRES_WINFO_EVNT_TYPE
{
    EN_MTC_PRES_WINFO_EVNT_SUBS,     /**< @brief subscribe status */
    EN_MTC_PRES_WINFO_EVNT_APPROV,   /**< @brief approved status */
    EN_MTC_PRES_WINFO_EVNT_DEACTIVE, /**< @brief deactivated status */
    EN_MTC_PRES_WINFO_EVNT_PROBATION, /**< @brief probation status */
    EN_MTC_PRES_WINFO_EVNT_REJECT,   /**< @brief rejected status */
    EN_MTC_PRES_WINFO_EVNT_TIMEOUT,  /**< @brief timeout status */
    EN_MTC_PRES_WINFO_EVNT_GIVEUP,   /**< @brief giveup status */
    EN_MTC_PRES_WINFO_EVNT_NORES,    /**< @brief noresource status */
    EN_MTC_PRES_WINFO_EVNT_OTHER     /**< @brief other(unknown) status */
} EN_MTC_PRES_WINFO_EVNT_TYPE;

/**
 * @brief Subscribe watcher info.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetSubsWinfoOk or @ref Mtc_PresCbSetSubsWinfoFailed.
 *
 * Note: Before subscribe watcher info, user MUST load buddy successfully(@ref Mtc_BuddysLoad),
 * and MUST load RLS-Service document successfully(@ref Mtc_PresSrvsLoad),
 * and MUST load Pres-Rules document successfully(@ref Mtc_PresRulesLoad),
 * and should has started subscribe presence list(@ref Mtc_PresSubsBuddyLst).
 *
 * @retval ZOK Start to subscribe watcher info successfully.
 * @retval ZFAILED Subscribe watcher info failed.
 *
 * @see @ref Mtc_PresWinfoUnSubs
 */
ZFUNC ZINT Mtc_PresWinfoSubs(ZFUNC_VOID);

/**
 * @brief Stop subscribe watcher info.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetUnSubsWinfoOk or @ref Mtc_PresCbSetUnSubsWinfoFailed.
 *
 * @retval ZOK Start to un-subscribe watcher info successfully.
 * @retval ZFAILED Stop subscribe watcher info failed.
 *
 * @see @ref Mtc_PresWinfoSubs
 */
ZFUNC ZINT Mtc_PresWinfoUnSubs(ZFUNC_VOID);

/**
 * @brief Get watcher info size.
 *
 * @return Watcher info size.
 *
 * @see @ref Mtc_PresWinfoGetOne
 */
ZFUNC ZINT Mtc_PresWinfoGetSize(ZFUNC_VOID);

/**
 * @brief Get One watcher info by index.
 *
 * @param [in] iIndex The id of watcher info.
 * @param [out] piStatType The entry status type, see @ref EN_MTC_PRES_WINFO_STAT_TYPE.
 * @param [out] pdwEvntType The entry event type, see @ref EN_MTC_PRES_WINFO_EVNT_TYPE
 * @param [out] ppcDispName The entry display name.
 * @param [out] ppcUri The info entry URI.
 * @param [out] pdwExpires The info entry expire time value.
 *
 *   The caller must copy *ppcDispName and *ppcUri, then use.
 *
 * @retval ZOK Get one watcher info successfully.
 * @retval ZFAILED Get one watcher info failed.
 *
 * @see @ref Mtc_PresWinfoGetSize
 */
ZFUNC ZINT Mtc_PresWinfoGetOne(ZINT iIndex, ZUINT *piStatType,
                ZUINT *pdwEvntType, ZCHAR **ppcDispName, 
                ZCHAR **ppcUri, ZUINT *pdwExpires);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PRES_WINFO_H__ */

