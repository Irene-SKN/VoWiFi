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
  File name     : mtc_grp.h
  Module        : multi-xdmc framework
  Author        : leo.lv
  Created on    : 2011-02-22
  Description   :
      Function implement required by mtc pre-arranged group.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_GRP_H__
#define _MTC_GRP_H__

/**
 * @file mtc_grp.h
 * @brief MTC OMA Pre-Arranged Group Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC OMA group status code. */
#define MTC_GRP_ERR_NO                 (MTC_EBASE_GRP + 0) /**< @brief no error */
#define MTC_GRP_ERR_AUTH_FAILED        (MTC_EBASE_GRP + 1) /**< @brief authentication failed, invalid user or password */
#define MTC_GRP_ERR_CONN_FAILED        (MTC_EBASE_GRP + 2) /**< @brief transport connect failed */
#define MTC_GRP_ERR_SEND_FAILED        (MTC_EBASE_GRP + 3) /**< @brief transport send failed */
#define MTC_GRP_ERR_SERV_DISCED        (MTC_EBASE_GRP + 4) /**< @brief transport disconnected by server */
#define MTC_GRP_ERR_SERV_ERR           (MTC_EBASE_GRP + 5) /**< @brief server internal error */
#define MTC_GRP_ERR_REQ_TIMEOUT        (MTC_EBASE_GRP + 6) /**< @brief request timeout */
#define MTC_GRP_ERR_BAD_XML_MSG        (MTC_EBASE_GRP + 7) /**< @brief bad xml message */
#define MTC_GRP_ERR_REPEATED           (MTC_EBASE_GRP + 8) /**< @brief element repeated */
#define MTC_GRP_ERR_NOT_FOUND          (MTC_EBASE_GRP + 9) /**< @brief not found */
#define MTC_GRP_ERR_OTHER              (MTC_EBASE_GRP + 10) /**< @brief other error */

/**
 * @brief Load all pre-arranged groups from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_GrpCbSetLoadAllOk or @ref Mtc_GrpCbSetLoadAllFailed.
 *
 * @retval ZOK Start loading groups successfully.
 * @retval ZFAILED Client loading groups failed.
 */
ZFUNC ZINT Mtc_GrpsLoadAllGrp(ZFUNC_VOID);

/**
 * @brief Load a pre-arranged group from OMA XDMS.
 * 
 * @retval ZOK Start loading a group successfully.
 * @retval ZFAILED Client loading a group failed.
 */
ZFUNC ZINT Mtc_GrpsLoadGrp(ZUINT iGrpId);

/**
 * @brief Load a pre-arranged group by group uri from OMA XDMS.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_GrpCbSetLoadOk or @ref Mtc_GrpCbSetLoadFailed.
 *
 * @return The id of group successfully or ZMAXUINT failed.
 */
ZFUNC ZUINT Mtc_GrpsLoadGrpU(ZCHAR *pcGrpUri);

/**
 * @brief Upload a pre-arranged group into OMA XDMS.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_GrpCbSetGrpAddOk or @ref Mtc_GrpCbSetGrpAddFailed.
 *
 * @retval ZOK Start uploading a group successfully.
 * @retval ZFAILED Client uploading a group failed.
 */
ZFUNC ZINT Mtc_GrpsUploadGrp(ZUINT iGrpId);

/**
 * @brief Get OMA pre-arranged group set size.
 *
 * @return Pre-arranged group set size.
 *
 * @see @ref Mtc_GrpsGetGrp
 */
ZFUNC ZUINT Mtc_GrpsGetSize(ZFUNC_VOID);

/**
 * @brief Get One pre-arranged group by index.
 *
 * @param [in] iIndex The index of group.
 *
 * @return The id of group.
 *
 * @see @ref Mtc_GrpsGetSize
 */
ZFUNC ZUINT Mtc_GrpsGetGrp(ZINT iIndex);

/**
 * @brief Add One pre-arranged group and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_GrpCbSetGrpAddOk or @ref Mtc_GrpCbSetGrpAddFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The group display name.
 * @param [in] pcSubject The group subject.
 *
 * @return The id of group when add group successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_GrpsRmvGrp
 */
ZFUNC ZUINT Mtc_GrpsAddGrp(ZCOOKIE zCookie, ZCHAR *pcDispName, 
                ZCHAR *pcSubject); 

/**
 * @brief Add One pre-arranged group in local cache.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The group display name.
 * @param [in] pcSubject The group subject.
 *
 * @return The id of group when add group successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_GrpsRmvGrp
 */
ZFUNC ZUINT Mtc_GrpsAddGrpL(ZCOOKIE zCookie, ZCHAR *pcDispName, 
                ZCHAR *pcSubject); 

/**
 * @brief Rmove One pre-arranged group and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_GrpCbSetGrpRmvOk or @ref Mtc_GrpCbSetGrpRmvFailed.
 *
 * @param [in] iGrpId The group id.
 *
 * @retval ZOK Remove one group successfully.
 * @retval ZFAILED Remove one group failed.
 *
 * @see @ref Mtc_GrpsAddGrp
 */
ZFUNC ZINT Mtc_GrpsRmvGrp(ZUINT iGrpId); 

/**
 * @brief Find One pre-arranged group by uri.
 *
 * @param [in] pcUri The group uri.
 *
 * @return One group Id.
 *
 * @see @ref Mtc_GrpsRmvGrp
 */
ZFUNC ZUINT Mtc_GrpsFindGrp(ZCHAR *pcUri);

/**
 * @brief Get owner of a pre-arranged group.
 *
 * @param [in] iGrpId The group id.
 *
 * @return ZTRUE if group is owner, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_GrpGetOwner(ZUINT iGrpId);

/**
 * @brief Get cookie of a pre-arranged group.
 *
 * @param [in] iGrpId The group id.
 *
 * @return The group cookie id.
 *
 * @see @ref Mtc_GrpSetCookie
 */
ZFUNC ZCOOKIE Mtc_GrpGetCookie(ZUINT iGrpId);

/**
 * @brief Set cookie of a pre-arranged group.
 *
 * @param [in] iGrpId The group id.
 * @param [in] zCookie The group cookie.
 *
 * @retval ZOK Set group cookie successfully.
 * @retval ZFAILED Set group cookie failed.
 *
 * @see @ref Mtc_GrpGetCookie
 */
ZFUNC ZINT Mtc_GrpSetCookie(ZUINT iGrpId, ZCOOKIE zCookie);

/**
 * @brief Get group uri of a pre-arranged group.
 *
 * @param [in] iGrpId The group id.
 *
 * @return Group URI. 
 *   The caller must copy it, then use.
 *
 * @see @ref Mtc_GrpSetCookie
 */
ZFUNC ZCHAR * Mtc_GrpGetUri(ZUINT iGrpId);

/**
 * @brief Get a pre-arranged group display name.
 *
 * @param [in] iGrpId The group id.
 *
 * @return The group name.
 *   The caller must copy it, then use.
 *
 * @see @ref Mtc_GrpSetDispName
 */
ZFUNC ZCHAR * Mtc_GrpGetDispName(ZUINT iGrpId);

/**
 * @brief Set a pre-arranged group(only owner) name and update change to xdms.
 *
 * @param [in] iGrpId The group id.
 * @param [in] pcDispName The group display Name.
 *
 * @retval ZOK Set group display name successfully.
 * @retval ZFAILED Set group display name failed.
 *
 * @see @ref Mtc_GrpGetDispName
 */
ZFUNC ZINT Mtc_GrpSetDispName(ZUINT iGrpId, ZCHAR *pcDispName);

/**
 * @brief Set a pre-arranged group name(only owner).
 *
 * @param [in] iGrpId The group id.
 * @param [in] pcDispName The group display Name.
 *
 * @retval ZOK Set group display name successfully.
 * @retval ZFAILED Set group display name failed.
 *
 * @see @ref Mtc_GrpGetDispName
 */
ZFUNC ZINT Mtc_GrpSetDispNameL(ZUINT iGrpId, ZCHAR *pcDispName);

/**
 * @brief Get a pre-arranged group min participant count.
 *
 * @param [in] iGrpId The group id.
 *
 * @return The minimum participant count.
 *
 * @see @ref Mtc_GrpSetMinPartCountL
 */
ZFUNC ZUINT Mtc_GrpGetMinPartCount(ZUINT iGrpId);

/**
 * @brief Set a pre-arranged group min participant count(only owner).
 *
 * @param [in] iGrpId The group id.
 * @param [in] iCount The group min participant count.
 *
 * @retval ZOK Set group min participant count successfully.
 * @retval ZFAILED Set group min participant count failed.
 *
 * @see @ref Mtc_GrpGetMinPartCount
 */
ZFUNC ZINT Mtc_GrpSetMinPartCountL(ZUINT iGrpId, ZUINT iCount);

/**
 * @brief Get a pre-arranged group max participant count.
 *
 * @param [in] iGrpId The group id.
 *
 * @return The maximum participant count.
 *
 * @see @ref Mtc_GrpSetMaxPartCountL
 */
ZFUNC ZUINT Mtc_GrpGetMaxPartCount(ZUINT iGrpId);

/**
 * @brief Set a pre-arranged group max participant count(only owner).
 *
 * @param [in] iGrpId The group id.
 * @param [in] iCount The group max participant count.
 *
 * @retval ZOK Set group max participant count successfully.
 * @retval ZFAILED Set group max participant count failed.
 *
 * @see @ref Mtc_GrpGetMaxPartCount
 */
ZFUNC ZINT Mtc_GrpSetMaxPartCountL(ZUINT iGrpId, ZUINT iCount);

/**
 * @brief Add a entry into one pre-arranged group(only owner) and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_GrpCbSetEntryAddOk or @ref Mtc_GrpCbSetEntryAddFailed.
 *
 * @param [in] iGrpId The group id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The entry display name.
 * @param [in] pcUri The entry URI.
 *
 * @return The id of entry, add one entry successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_GrpGetSize
 */
ZFUNC ZUINT Mtc_GrpAddEntry(ZUINT iGrpId, ZCOOKIE zCookie, 
                ZCHAR *pcDispName, ZCHAR *pcUri);

/**
 * @brief Add a entry into one pre-arranged group(only owner).
 *
 * @param [in] iGrpId The group id.
 * @param [in] zCookie The user cookie.
 * @param [in] pcDispName The entry display name.
 * @param [in] pcUri The entry URI.
 *
 * @return The id of entry when add one entry successfully, otherwise return ZMAXUINT.
 *
 * @see @ref Mtc_GrpGetSize
 */
ZFUNC ZUINT Mtc_GrpAddEntryL(ZUINT iGrpId, ZCOOKIE zCookie, 
                ZCHAR *pcDispName, ZCHAR *pcUri);

/**
 * @brief Remove one entry from pre-arranged group and update change to xdms.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_GrpCbSetEntryRmvOk or @ref Mtc_GrpCbSetEntryRmvFailed.
 *
 * @param [in] iEntryId The id of entry.
 *
 * @retval ZOK Start to remove one entry successfully.
 * @retval ZFAILED Start to remove one entry failed.
 *
 * @see @ref Mtc_GrpAddEntry
 */
ZFUNC ZINT Mtc_GrpRmvEntry(ZUINT iEntryId); 

/**
 * @brief Remove one entry from OMA pre-arranged group.
 *
 * @param [in] iEntryId The id of entry.
 *
 * @retval ZOK Start to remove one entry successfully.
 * @retval ZFAILED Start to remove one entry failed.
 *
 * @see @ref Mtc_GrpAddEntry
 */
ZFUNC ZINT Mtc_GrpRmvEntryL(ZUINT iEntryId); 

/**
 * @brief Get OMA entry from one pre-arranged group.
 *
 * @param [in] iGrpId The group id.
 *
 * @return Entry set size.
 *
 * @see @ref Mtc_GrpGetEntry
 */
ZFUNC ZINT Mtc_GrpGetSize(ZUINT iGrpId);

/**
 * @brief Get an entry from one pre-arranged group by index.
 *
 * @param [in] iGrpId The group id.
 * @param [in] iIndex The index of entry.
 *
 * @return One Entry Id.
 *
 * @see @ref Mtc_GrpGetSize
 */
ZFUNC ZUINT Mtc_GrpGetEntry(ZUINT iGrpId, ZINT iIndex);

/**
 * @brief Find an entry from one pre-arranged group.
 *
 * @param [in] iGrpId The group id.
 * @param [in] pcUri The entry uri.
 *
 * @return The entry id.
 *
 * @see @ref Mtc_GrpGetEntry
 */
ZFUNC ZUINT Mtc_GrpFindEntry(ZUINT iGrpId, ZCHAR *pcUri);

/**
 * @brief Get entry cookie id.
 *
 * @param [in] iEntryId The id of entry.
 *
 * @return Entry cookie id. 
 *
 * @see @ref Mtc_GrpEntrySetCookie
 */
ZFUNC ZCOOKIE Mtc_GrpEntryGetCookie(ZUINT iEntryId);

/**
 * @brief Set entry cookie id.
 *
 * @param [in] iEntryId The id of entry.
 * @param [in] zCookie The cookie id of entry.
 *
 * @retval ZOK Set entry cookie id successfully.
 * @retval ZFAILED Set entry cookie id failed.
 *
 * @see @ref Mtc_GrpEntryGetCookie
 */
ZFUNC ZINT Mtc_GrpEntrySetCookie(ZUINT iEntryId, ZCOOKIE zCookie);

/**
 * @brief Get an entry display name.
 *
 * @param [in] iEntryId The entry id.
 *
 * @return Entry display name.
 * The caller must copy it, then use.
 *
 * @see @ref Mtc_GrpEntrySetDispName
 */
ZFUNC ZCHAR * Mtc_GrpEntryGetDispName(ZUINT iEntryId);

/**
 * @brief Set an entry display name and update change to xdms.
 *
 * @param [in] iEntryId The entry id.
 * @param [in] pcDispName The display Name.
 *
 * @retval ZOK Set display name successfully.
 * @retval ZFAILED Set display name failed.
 *
 * @see @ref Mtc_GrpEntryGetDispName
 */
ZFUNC ZINT Mtc_GrpEntrySetDispName(ZUINT iEntryId, 
                ZCHAR *pcDispName);

/**
 * @brief Set an entry display name.
 *
 * @param [in] iEntryId The entry id.
 * @param [in] pcDispName The display Name.
 *
 * @retval ZOK Set display name successfully.
 * @retval ZFAILED Set display name failed.
 *
 * @see @ref Mtc_GrpEntryGetDispName
 */
ZFUNC ZINT Mtc_GrpEntrySetDispNameL(ZUINT iEntryId, 
                ZCHAR *pcDispName);

/**
 * @brief Get an entry uri.
 *
 * @param [in] iEntryId The entry id.
 *
 * @return Entry uri.
 * The caller must copy it, then use.
 *
 * @see @ref Mtc_GrpEntryGetDispName
 */
ZFUNC ZCHAR * Mtc_GrpEntryGetUri(ZUINT iEntryId);

/**
 * @brief Get the pre-arranged group id of one entry.
 *
 * @param [in] iEntryId The entry id.
 *
 * @return The group id.
 *
 * @see @ref Mtc_GrpEntryGetDispName
 */
ZFUNC ZUINT Mtc_GrpEntryGetGrpId(ZUINT iEntryId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_GRP_H__ */

