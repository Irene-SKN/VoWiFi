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
  File name     : mtc_pres_srv.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by MTC OMA presence service.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PRES_SRV_H__
#define _MTC_PRES_SRV_H__

/**
 * @file mtc_pres_srv.h
 * @brief MTC Presence RLS-Service Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif
 
/** @brief MTC presence service presence list type  */
typedef enum EN_MTC_PRES_SRV_LST_TYPE
{
    EN_MTC_PRES_SRV_LST_RCS,         /**< @brief rcs */
    EN_MTC_PRES_SRV_LST_RCS_POLL     /**< @brief rcs_poll */
} EN_MTC_PRES_SRV_LST_TYPE;

/**
 * @brief Load presence services information.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetSrvLoadOk or @ref Mtc_PresCbSetSrvLoadFailed.
 *
 * Note: Before load presence services, user MUST load buddy successfully(@ref Mtc_BuddysLoad).
 *
 * @retval ZOK Start to load services successfully.
 * @retval ZFAILED Load services failed.
 */
ZFUNC ZINT Mtc_PresSrvsLoad(ZFUNC_VOID);

/**
 * @brief Upload presence services information.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetSrvUploadOk or @ref Mtc_PresCbSetSrvUploadFailed.
 *
 * Note: Before upload presence services, user MUST has loaded service successfully.
 *
 * @retval ZOK Start to load services successfully.
 * @retval ZFAILED Load services failed.
 */
ZFUNC ZINT Mtc_PresSrvsUpload(ZFUNC_VOID);

/**
 * @brief Get presence service list buddy set size.
 *
 * @param [in] iPresLstType The type of presence list, @see @ref EN_MTC_PRES_SRV_LST_TYPE.
 *
 * @return Buddy set size.
 *
 * @see @ref Mtc_PresSrvGetBuddy
 */
ZFUNC ZINT Mtc_PresSrvGetBuddySize(ZUINT iPresLstType);

/**
 * @brief Get One buddy from presence service list by index.
 *
 * Note: The buddy uri and name can get by Mtc_BuddyGetUri and Mtc_BuddyGetDispName.
 *
 * @param [in] iPresLstType The type of presence list, @see @ref EN_MTC_PRES_SRV_LST_TYPE.
 * @param [in] iIndex The index of buddy.
 *
 * @return One buddy Id.
 *
 * @see @ref Mtc_PresSrvGetBuddySize
 */
ZFUNC ZUINT Mtc_PresSrvGetBuddy(ZUINT iPresLstType, ZINT iIndex);

/**
 * @brief Add one buddy presence service list.
 *  
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetSrvAddBuddyOk or @ref Mtc_PresCbSetSrvAddBuddyFailed.
 *
 * @param [in] iPresLstType The type of presence list, @see @ref EN_MTC_PRES_SRV_LST_TYPE.
 * @param [in] iBuddyId The id of buddy.
 *
 * @retval ZOK Start to add one buddy successfully.
 * @retval ZFAILED Start to add one buddy failed.
 *
 * @see @ref Mtc_PresSrvRmvBuddy
 */
ZFUNC ZINT Mtc_PresSrvAddBuddy(ZUINT iPresLstType, ZUINT iBuddyId);

/**
 * @brief Add one buddy presence service list in local cache.
 * 
 * @param [in] iPresLstType The type of presence list, @see @ref EN_MTC_PRES_SRV_LST_TYPE.
 * @param [in] iBuddyId The id of buddy.
 *
 * @retval ZOK Start to add one buddy successfully.
 * @retval ZFAILED Start to add one buddy failed.
 *
 * @see @ref Mtc_PresSrvRmvBuddyL
 */
ZFUNC ZINT Mtc_PresSrvAddBuddyL(ZUINT iPresLstType, ZUINT iBuddyId);

/**
 * @brief Remove one buddy from presence service list.
 *  
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetSrvRmvBuddyOk or @ref Mtc_PresCbSetSrvRmvBuddyFailed.
 *
 * @param [in] iPresLstType The type of presence list, @see @ref EN_MTC_PRES_SRV_LST_TYPE.
 * @param [in] iBuddyId The id of buddy.
 *
 * @retval ZOK Start to remove one buddy successfully.
 * @retval ZFAILED Start to remove one buddy failed.
 *
 * @see @ref Mtc_PresSrvAddBuddy
 */
ZFUNC ZINT Mtc_PresSrvRmvBuddy(ZUINT iPresLstType, ZUINT iBuddyId);

/**
 * @brief Remove one buddy from presence service list in local cache.
 *
 * @param [in] iPresLstType The type of presence list, @see @ref EN_MTC_PRES_SRV_LST_TYPE.
 * @param [in] iBuddyId The id of buddy.
 *
 * @retval ZOK Start to remove one buddy successfully.
 * @retval ZFAILED Start to remove one buddy failed.
 *
 * @see @ref Mtc_PresSrvAddBuddyL
 */
ZFUNC ZINT Mtc_PresSrvRmvBuddyL(ZUINT iPresLstType, ZUINT iBuddyId);

/**
 * @brief Find One buddy from presence service list.
 *
 * @param [in] iPresLstType The type of presence list, @see @ref EN_MTC_PRES_SRV_LST_TYPE.
 * @param [in] iBuddyId The id of buddy.
 *
 * @return ZTRUE if buddy in service list, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_PresSrvFindBuddy(ZUINT iPresLstType, ZUINT iBuddyId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PRES_SRV_H__ */

