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
  File name     : mtc_im_defer.h
  Module        : multimedia talk client
  Author        : cathy.chen
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC IM deferred message

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_DEFER_H__
#define _MTC_IM_DEFER_H__

/**
 * @file mtc_im_defer.h
 * @brief MTC Instant Message Deferred Messages Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC Defer Message History type Type */
typedef enum EN_MTC_HIS_MODE_TYPE
{
    EN_MTC_HIS_MODE_PAGER,           /**< @brief Pager */
    EN_MTC_HIS_MODE_GROUP,           /**< @brief Pre-defined-group-invitation */
    EN_MTC_HIS_MODE_FILE,            /**< @brief Offline-file */
    EN_MTC_HIS_MODE_CONF,            /**< @brief Conference */
    EN_MTC_HIS_MODE_UNKNOW           /**< @brief Unknown */
} EN_MTC_HIS_MODE_TYPE;

/**
 * @brief MTC Retrieve all deferred message.
 *
 * If IM retrieve all deferred message successfully,
 * GUI will be notified by callback which was set by 
 * Mtc_ImCbSetDeferRetrieveOk or @ref Mtc_ImCbSetDeferRetrieveFailed.
 *
 * @return The deferred message id when send message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImDeferRetrieveAll(ZFUNC_VOID);
 
/**
 * @brief MTC Retrieve deferred message list.
 *
 * If IM retrieve deferred message list successfully,
 * GUI will be notified by callback which was set by 
 * Mtc_ImCbSetDeferRetrieveOk or @ref Mtc_ImCbSetDeferRetrieveFailed.
 *
 * @param [in] iMsgLstId The deferred message list id.
 *
 * @return The deferred message id when send message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImDeferRetrieveLst(ZUINT iMsgLstId);

/**
 * @brief MTC Retrieve deferred page message.
 *
 * If IM retrieve deferred message list successfully,
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetDeferRetrievePagerOk or @ref Mtc_ImCbSetDeferRetrievePagerFailed.
 *
 * @param [in] iMsgLstId The deferred message list id.
 *
 * @return The deferred message id when send message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImDeferRetrievePager(ZUINT iMsgLstId);

/**
 * @brief MTC Retrieve deferred file.
 *
 * If IM retrieve deferred message list successfully,
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetDeferRetrieveFileOk or @ref Mtc_ImCbSetDeferRetrieveFileFailed.
 *
 * @param [in] iMsgLstId The deferred message list id.
 * @param [in] pcFileName The deferred file name.
 *
 * @return The deferred message id when send message successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImDeferRetrieveFile(ZUINT iMsgLstId, 
                ZCHAR *pcFileName);

/**
 * @brief MTC Release deferred message.
 *
 * @param [in] iDeferId The deferred message id.
 *
 * @retval ZOK Delete deferred message successfully.
 * @retval ZFAILED Delete deferred message failed.
 */
ZFUNC ZINT Mtc_ImDeferRelease(ZUINT iDeferId);

/**
 * @brief MTC Get deferred message list size.
 *
 * @param [in] iDeferId The message session id.
 *
 * @return Message list size.
 */
ZFUNC ZINT Mtc_ImDeferMsgsGetSize(ZUINT iDeferId);

/**
 * @brief MTC Get a deferred message from message list.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iIndex The index of message.
 *
 * @return The deferred message id.
 */
ZFUNC ZVOID * Mtc_ImDeferMsgsGetMsg(ZUINT iDeferId, ZINT iIndex);

/**
 * @brief MTC Get content type from deferred message.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iDMsgId The message id.
 *
 * @return Content type.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImDeferMsgGetContentType(ZUINT iDeferId, 
                ZVOID * pDMsg);

/**
 * @brief MTC Get content length from deferred message.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iDMsgId The message id.
 *
 * @return The message content length.
 */
ZFUNC ZUINT Mtc_ImDeferMsgGetContentLen(ZUINT iDeferId, 
                ZVOID * pDMsg);

/**
 * @brief MTC Get content from deferred message.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iDMsgId The message id.
 *
 * @return The message content.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImDeferMsgGetContent(ZUINT iDeferId, 
                ZVOID * pDMsg);

/**
 * @brief MTC Get participant information from deferred message.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iDMsgId The message id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImDeferMsgGetPartp(ZUINT iDeferId, ZVOID * pDMsg, 
                ZCHAR **ppcName, ZCHAR **ppcUri);

/**
 * @brief MTC Get date time from deferred message.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iDMsgId The message id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time failed.
 */
ZFUNC ZINT Mtc_ImDeferMsgGetSysDateTime(ZUINT iDeferId, ZVOID * pDMsg,
               ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from deferred message.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iDMsgId The message id.
 *
 * @return defer message date time, otherwise return 0.
 */
ZFUNC ZTIME_T Mtc_ImDeferMsgGetDateTime(ZUINT iDeferId, 
                ZVOID * pDMsg);

/**
 * @brief MTC Get RCS SMS flag from deferred message.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iDMsgId The message id.
 *
 * @return ZTRUE if it is a RCS SMS message, otherwise ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImDeferMsgHasRcsSms(ZUINT iDeferId, 
                ZVOID * pDMsg); 

/**
 * @brief MTC Get RCS Imdn type from deferred message.
 *
 * @param [in] iDeferId The message session id.
 * @param [in] iDMsgId The message id.
 *
 * @return The Imdn type. See @ref EN_MTC_PMSG_IMDN_TYPE....
 */
ZFUNC ZUINT Mtc_ImDeferMsgGetImdnType(ZUINT iDeferId, 
                ZVOID * pDMsg);

/**
 * @brief MTC Get file name from deferred message.
 *
 * @param [in] iDeferId The deferred message id.
 *
 * @return The file name string.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImDeferFileGetFileName(ZUINT iDeferId);

/**
 * @brief MTC Get participant information from deferred message.
 *
 * The participant is the remote client who send file.
 *
 * @param [in] iDeferId The message session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant uri.
 * 
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImDeferFileGetPartp(ZUINT iDeferId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Load all histories from xdms .
 *
 * If IM retrieve all deferred message successfully,
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetDmsgLoadOk or @ref Mtc_ImCbSetDmsgLoadFailed.
 *
 * @retval ZOK Load deferred message successfully.
 * @retval ZFAILED Load deferred message failed.
 */
ZFUNC ZINT Mtc_DmsgLoadAll();

/**
 * @brief MTC Remove all histories from xdms.
 *
 * If IM remove all deferred message successfully,
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetDmsgRmvOk or @ref Mtc_ImCbSetDmsgRmvFailed.
 *
 * @retval ZOK Remove deferred message successfully.
 * @retval ZFAILED Remove deferred message failed.
 */
ZFUNC ZINT Mtc_DmsgRmvAll();

/**
 * @brief MTC Remove all histories in local cache.
 *
 * @retval ZOK Remove deferred message successfully.
 * @retval ZFAILED Remove deferred message failed.
 */
ZFUNC ZINT Mtc_DmsgRmvAllL();

/**
 * @brief MTC Get history list size.
 *
 * @return History list size.
 */
ZFUNC ZINT Mtc_DmsgGetSize();

/**
 * @brief MTC Get a history message from history list.
 *
 * @param [in] iIndex The index of message.
 *
 * @return The history id.
 */
ZFUNC ZUINT Mtc_DmsgGetHis(ZINT iIndex);

/**
 * @brief MTC Remove a history message in xdms.
 *
 * If Remove a history message successfully,
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetDmsgRmvHisOk or @ref Mtc_ImCbSetDmsgRmvHisFailed,
 * history in local cache will be removed after callback called.
 *
 * @param [in] iHisId The id of history.
 *
 * @retval ZOK Remove history message successfully.
 * @retval ZFAILED Remove history message failed.
 */
ZFUNC ZINT Mtc_DmsgRmvHis(ZUINT iHisId);

/**
 * @brief MTC Remove a history message in local cache.
 *
 * @param [in] iHisId The id of history.
 *
 * @retval ZOK Remove history message successfully.
 * @retval ZFAILED Remove history message failed.
 */
ZFUNC ZINT Mtc_DmsgRmvHisL(ZUINT iHisId);

/**
 * @brief MTC Get history type from deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return History type, see @ref EN_MTC_HIS_MODE_TYPE....
 */
ZFUNC ZUINT Mtc_DmsgHisGetType(ZUINT iHisId);

/**
 * @brief MTC Get history size element from deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return History size element.
 */
ZFUNC ZINT Mtc_DmsgHisGetSize(ZUINT iHisId);

/**
 * @brief MTC Get history expiry element from deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get expiry successfully.
 * @retval ZFAILED Get expiry failed.
 */
ZFUNC ZINT Mtc_DmsgHisGetExpiry(ZUINT iHisId, ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get history subject element from deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history subject element
 */
ZFUNC ZCHAR * Mtc_DmsgHisGetSubject(ZUINT iHisId);

/**
 * @brief MTC Get history date element from deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history date
 */
ZFUNC ZCHAR * Mtc_DmsgHisGetDate(ZUINT iHisId);

/**
 * @brief MTC Get history reference from deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history reference
 */
ZFUNC ZCHAR * Mtc_DmsgHisGetRef(ZUINT iHisId);

/**
 * @brief MTC Get time-stamp from Group deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get time-stamp successfully.
 * @retval ZFAILED Get time-stamp failed.
 */
ZFUNC ZINT Mtc_DmsgGroupGetSysTimeStamp(ZUINT iHisId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get time-stamp from Group deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return group deferred message time stamp, otherwise return 0. 
 */
ZFUNC ZTIME_T Mtc_DmsgGroupGetTimeStamp(ZUINT iHisId);

/**
 * @brief MTC Get from element from Group deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history from element
 */
 ZFUNC ZCHAR * Mtc_DmsgGroupGetFrom(ZUINT iHisId);

/**
 * @brief MTC Get to element from Group deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history to element
 */
ZFUNC ZCHAR * Mtc_DmsgGroupGetTo(ZUINT iHisId);

/**
 * @brief MTC Get group-id element from Group deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history group-id element
 */
ZFUNC ZCHAR * Mtc_DmsgGroupGetGrpId(ZUINT iHisId);

/**
 * @brief MTC Get time-stamp from File deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get time-stamp successfully.
 * @retval ZFAILED Get time-stamp failed.
 */
ZFUNC ZINT Mtc_DmsgFileGetSysTimeStamp(ZUINT iHisId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get from element from File deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history from element
 */
ZFUNC ZCHAR * Mtc_DmsgFileGetFrom(ZUINT iHisId);

/**
 * @brief MTC Get to element from File deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history to element
 */
ZFUNC ZCHAR * Mtc_DmsgFileGetTo(ZUINT iHisId);

/**
 * @brief MTC Get file-name element from File deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history file-name element
 */
ZFUNC ZCHAR * Mtc_DmsgFileGetFileName(ZUINT iHisId);

/**
 * @brief MTC Get time-stamp from Pager deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get time-stamp successfully.
 * @retval ZFAILED Get time-stamp failed.
 */
ZFUNC ZINT Mtc_DmsgPagerGetSysTimeStamp(ZUINT iHisId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get time-stamp from Pager deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return pager deferred message time-stamp, otherwise return 0.
 */
ZFUNC ZTIME_T Mtc_DmsgPagerGetTimeStamp(ZUINT iHisId);

/**
 * @brief MTC Get from element from Pager deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history from element
 */
ZFUNC ZCHAR * Mtc_DmsgPagerGetFrom(ZUINT iHisId);

/**
 * @brief MTC Get to element from Pager deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history to element
 */
ZFUNC ZCHAR * Mtc_DmsgPagerGetTo(ZUINT iHisId);

/**
 * @brief MTC Get recipient-list entry size from Pager deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history recipient-list entry size
 */
ZFUNC ZINT Mtc_DmsgPagerGetLstEntrySize(ZUINT iHisId);

/**
 * @brief MTC Get recipient-list entry from Pager deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in] iIndex The index.
 * @param [in,out] ppcDispName The entry display name.
 * @param [in,out] ppcUri The entry URI.
 *
 * @retval ZOK Get recipient-list entry successfully.
 * @retval ZFAILED Get recipient-list entry failed.
 */
ZFUNC ZINT Mtc_DmsgPagerGetLstEntry(ZUINT iHisId, ZINT iIndex,
                ZCHAR **ppcDispName, ZCHAR **ppcUri);

/**
 * @brief MTC Get recipient-list group uri and display-name
 * from Pager deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in,out] ppcDispName The recipient-list group display name.
 * @param [in,out] ppcUri The recipient-list group URI.
 *
 * @retval ZOK Get recipient-list group uri and display-name successfully.
 * @retval ZFAILED Get recipient-list group uri and display-name failed.
 */
ZFUNC ZINT Mtc_DmsgPagerGetLstGrp(ZUINT iHisId, ZCHAR **ppcDispName,
                ZCHAR **ppcUri);

/**
 * @brief MTC Get auth-id element from Pager deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history auth-id element
 */
ZFUNC ZCHAR * Mtc_DmsgPagerGetAuthId(ZUINT iHisId);

/**
 * @brief MTC Get time-start from Conference deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get time-start successfully.
 * @retval ZFAILED Get time-start failed.
 */
ZFUNC ZINT Mtc_DmsgConfGetTimeStart(ZUINT iHisId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get time-end from Conference deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get time-end successfully.
 * @retval ZFAILED Get time-end failed.
 */
ZFUNC ZINT Mtc_DmsgConfGetTimeEnd(ZUINT iHisId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get recoding-name from Conference deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history recoding-name
 */
ZFUNC ZCHAR * Mtc_DmsgConfGetRecdName(ZUINT iHisId);

/**
 * @brief MTC Get conf-list entry size from Conference deferred message.
 *
 * @param [in] iHisId The history id.
 *
 * @return history conf-list entry size
 */
ZFUNC ZINT Mtc_DmsgConfGetLstEntrySize(ZUINT iHisId);

/**
 * @brief MTC Get conf-list entry from Conference deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in] iIndex The index.
 * @param [in,out] ppcDispName The entry display name.
 * @param [in,out] ppcUri The entry URI.
 *
 * @retval ZOK Get conf-list entry successfully.
 * @retval ZFAILED Get conf-list entry failed.
 */
ZFUNC ZINT Mtc_DmsgConfGetLstEntry(ZUINT iHisId, ZINT iIndex,
                ZCHAR **ppcDispName, ZCHAR **ppcUri);

/**
 * @brief MTC Get conf-list group uri and display-name
 * from Conference deferred message.
 *
 * @param [in] iHisId The history id.
 * @param [in,out] ppcDispName The conf-list group display name.
 * @param [in,out] ppcUri The conf-list group URI.
 *
 * @retval ZOK Get conf-list group uri and display-name successfully.
 * @retval ZFAILED Get conf-list group uri and display-name failed.
 */
ZFUNC ZINT Mtc_DmsgConfGetLstGrp(ZUINT iHisId, ZCHAR **ppcDispName,
                ZCHAR **ppcUri);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_DEFER_H__ */

