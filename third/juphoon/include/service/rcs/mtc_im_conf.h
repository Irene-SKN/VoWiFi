/************************************************************************

        Copyright (c) 2005-2014 by Juphoon System Software, Inc.
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
  File name     : mtc_im_conf.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2014-11-22
  Description   :
      Data structure and function declare required by MTC IM conference manage.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_CONF_H__
#define _MTC_IM_CONF_H__

/**
 * @file mtc_im_conf.h
 * @brief MTC Instant Message Conference Manage Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/* mtc conference manage type */
typedef enum EN_MTC_CONFM_STATE_TYPE
{
    EN_MTC_CONFM_STATE_IDLE,        /* conference manage idle state */
    EN_MTC_CONFM_STATE_ACTIVE       /* conference manage active state */
} EN_MTC_CONFM_STATE_TYPE;

/* mtc conference manage type */
typedef enum EN_MTC_CONFM_USER_STATUS_TYPE
{
    EN_MTC_CONFM_USER_STATUS_OK,        /* conference manage user status ok */
    EN_MTC_CONFM_USER_STATUS_LEAVED,    /* conference manage user is leaved */  
    EN_MTC_CONFM_USER_STATUS_DISSOLVED  /* conference manage group is dissolved */     
} EN_MTC_CONFM_GRP_STATUS_TYPE;

/**
 * @brief MTC Subscribe conference list.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetConfSubsLstOk or @ref Mtc_ImCbSetConfSubsLstFailed.
 *
 * @param [in] iGrpType Type of subscribe, @ref EN_MTC_GROUP_TYPE.
 * @param [in] iGrpLstVer The group list version.
 *
 * @retval ZOK Start to subscribe conference list successfully.
 * @retval ZFAILED Subscribe conference list failed.
 */
ZFUNC ZINT Mtc_ImConfMSubsConfLst(ZUINT iGrpType, ZUINT iGrpLstVer);

/**
 * @brief MTC Subscribe conference info.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetConfSubsInfoOk or @ref Mtc_ImCbSetConfSubsInfoFailed.
 *
 * @param [in] pcGroupId The group session identity.
 *
 * @return conference id successfully or ZMAXUINT failed.
 */
ZFUNC ZUINT Mtc_ImConfMSubsConf(ZCHAR *pcGroupId);

/**
 * @brief MTC Get group list version.
 *
 * @return group list version.
 */
ZFUNC ZINT Mtc_ImConfMGetGrpLstVer(ZFUNC_VOID);

/**
 * @brief MTC Get conference group size.
 *
 * @return conference group size.
 */
ZFUNC ZINT Mtc_ImConfMGetConfGrpSize(ZFUNC_VOID);

/**
 * @brief MTC Get conference group id by index.
 *
 * @param [in] iIndex The group index.
 *
 * @return conference group id successfully or ZMAXUINT failed.
 */
ZFUNC ZUINT Mtc_ImConfMGetConfGrpId(ZUINT iIndex);

/**
 * @brief MTC Get conference group session identity.
 *
 * @param [in] iGrpId The group id.
 *
 * @return conference group session identity.
 */
ZFUNC ZCHAR * Mtc_ImConfMGetConfGrpSessId(ZUINT iGrpId);

/**
 * @brief MTC Get conference conversation id.
 *
 * @param [in] iGrpId The group id.
 *
 * @return conference conversation id.
 */
ZFUNC ZCHAR * Mtc_ImConfMGetConfConvId(ZUINT iGrpId);

/**
 * @brief MTC Get conference version.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference version.
 */
ZFUNC ZUINT Mtc_ImConfGetVersion(ZUINT iConfId);

/**
 * @brief MTC Get conference name.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference name.
 */
ZFUNC ZCHAR * Mtc_ImConfMGetConfName(ZUINT iGrpId);

/**
 * @brief MTC Get conference group type.
 *
 * @param [in] iGrpId The group id.
 *
 * @return conference group type @ref EN_MTC_GROUP_TYPE.
 */
ZFUNC ZUINT Mtc_ImConfMGetConfGrpType(ZUINT iGrpId);

/**
 * @brief MTC Get conference group version.
 *
 * @param [in] iGrpId The group id.
 *
 * @return conference group version.
 */
ZFUNC ZUINT Mtc_ImConfMGetConfGrpVer(ZUINT iGrpId);

/**
 * @brief MTC Get conference active.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference active.
 */
ZFUNC ZBOOL Mtc_ImConfGetActive(ZUINT iConfId);

/**
 * @brief MTC Get conference locked.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference locked.
 */
ZFUNC ZBOOL Mtc_ImConfGetLocked(ZUINT iConfId);

/**
 * @brief MTC Get conference ischange.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference ischange.
 */
ZFUNC ZBOOL Mtc_ImConfGetIsChange(ZUINT iConfId);

/**
 * @brief MTC Get conference offlinesm.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference offlinesm.
 */
ZFUNC ZINT Mtc_ImConfGetOfflineSm(ZUINT iConfId);

/**
 * @brief MTC Get conference max user count.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference max user count.
 */
ZFUNC ZUINT Mtc_ImConfGetMaxUsrCnt(ZUINT iConfId);

/**
 * @brief MTC Get conference group type.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference group type @ref EN_MTC_GROUP_TYPE .
 */
ZFUNC ZUINT Mtc_ImConfGetGroupType(ZUINT iConfId);

/**
 * @brief MTC Get conference user count.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference user count.
 */
ZFUNC ZUINT Mtc_ImConfGetUsrCnt(ZUINT iConfId);

/**
 * @brief MTC Get conference subject.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference subject.
 */
ZFUNC ZCHAR * Mtc_ImConfGetSubject(ZUINT iConfId);

/**
 * @brief MTC Get conference enterprise id.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference enterprise id.
 */
ZFUNC ZCHAR * Mtc_ImConfGetEnterpriseId(ZUINT iConfId);

/**
 * @brief MTC Get conference department id.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference department id.
 */
ZFUNC ZCHAR * Mtc_ImConfGetDepartmentId(ZUINT iConfId);

/**
 * @brief MTC Get conference display name.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference display name.
 */
ZFUNC ZCHAR * Mtc_ImConfGetDispName(ZUINT iConfId);

/**
 * @brief MTC Get conference group session identity.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference group session identity.
 */
ZFUNC ZCHAR * Mtc_ImConfGetGrpSessId(ZUINT iConfId);

/**
 * @brief MTC Get conference participant list id.
 *
 * @param [in] iConfId The conference id.
 *
 * @return conference participant list id.
 */
ZFUNC ZUINT Mtc_ImConfGetPartpLstId(ZUINT iConfId);

/**
 * @brief MTC Get conference group status
 *
 * @param [in] iConfId The conference id.
 *
 * @return group status, @ref EN_MTC_CONFM_GRP_STATUS_TYPE.
 */
ZFUNC ZUINT Mtc_ImConfGetGrpStatus(ZUINT iConfId);

/**
 * @brief Create a group list.
 *
 * @return The list id when create a group list successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImConfGrpLstCreate(ZFUNC_VOID);

/* mtc conference group list add group */
/**
 * @brief Add a group into group list.
 *
 * @param [in] iGrpLstId The list id for group.
 * @param [in] pcGrpIdentity The group identity.
 * @param [in] iGrpVersion The group version.
 *
 * @retval ZOK Add group into group list successfully.
 * @retval ZFAILED Add group into group list failed. 
 */
ZFUNC ZINT Mtc_ImConfGrpLstAdd(ZUINT iGrpLstId, ZCHAR* pcGrpIdentity, 
                ZUINT iGrpVersion);

/**
 * @brief MTC Subscribe conference info list.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_ImCbSetConfHttpSubsInfoLstOk or @ref Mtc_ImCbSetConfHttpSubsInfoLstFailed.
 *
 * @param [in] iGrpLstId The list id for group.
 * @param [in] bFull Indicate whether get full or part of list.
 * @param [in] pcToken The auth token.
 *
 * @return http id successfully or ZMAXUINT failed.
 */
ZFUNC ZUINT Mtc_ImConfHttpSubsInfoLst(ZUINT iGrpLstId, ZBOOL bFull, 
                ZCHAR* pcToken);

/**
 * @brief MTC Get conference info list size.
 *
 * @param [in] iHttpId The http id.
 *
 * @return conference list size.
 */
ZFUNC ZINT Mtc_ImConfHttpGetInfoLstSize(ZUINT iHttpId);

/**
 * @brief MTC Get conference id by index.
 *
 * @param [in] iHttpId The http id. 
 * @param [in] iIndex The conference index.
 *
 * @return conference id successfully or ZMAXUINT failed.
 */
ZFUNC ZUINT Mtc_ImConfHttpGetConfId(ZUINT iHttpId, ZUINT iIndex);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_CONF_H__ */

