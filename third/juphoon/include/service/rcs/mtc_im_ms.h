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
  File name     : mtc_im_ms.h
  Module        : multimedia talk client
  Author        : tanek.ye
  Created on    : 2013-05-15
  Description   :
      Data structure and function declare required by MTC IM message storage

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_MS_H__
#define _MTC_IM_MS_H__

/**
 * @file mtc_im_ms.h
 * @brief MTC Instant Message Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC IM message storage content type */
#define MTC_IM_MS_CONT_TEXT_PLAIN "text/plain"               /**< @brief text/plain content */
#define MTC_IM_MS_CONT_VEMOTICON "application/vemoticon+xml" /**< @brief application/vemoticon+xml content */
#define MTC_IM_MS_CONT_CLOUDFILE "application/cloudfile+xml" /**< @brief application/cloudfile+xml content */
#define MTC_IM_MS_CONT_GINFO "application/vnd.gsma.rcspushlocation+xml" /**< @brief application/vnd.gsma.rcspushlocation+xml content */
#define MTC_IM_MS_CONT_IMAGE_JPG "image/jpeg" /**< @brief image/jpeg content */
#define MTC_IM_MS_CONT_IMAGE_BMP "image/bmp"  /**< @brief image/bmp content */
#define MTC_IM_MS_CONT_AUDIO_VIDEO "application/octet-stream" /**< @brief application/octet-stream content */

/** @brief MTC IM message storage body encode type */
#define MTC_IM_MS_CONT_ENCODE_BINARY "binary" /**< @brief binary encode type */
#define MTC_IM_MS_CONT_ENCODE_BASE64 "base64" /**< @brief base64 encode type */

/** @brief MTC IM message storage body operate folder */
#define MTC_IM_MS_DIR_MSGBACKUP "msgBackup" /**< @brief message backup folder */
#define MTC_IM_MS_DIR_MSGFAVORITE "msgFavorite" /**< @brief message favorite folder */

/** @brief MTC IM message storage body operate folder */
#define MTC_IM_MS_OBJ_ONE_TO_ONE "1-1"      /**< @brief object type 1-1 */
#define MTC_IM_MS_OBJ_ONE_TO_MANY "1-many"  /**< @brief object type 1-many */
#define MTC_IM_MS_OBJ_AD_HOC "Ad-Hoc"       /**< @brief object type ad-hoc */

/* @brief MTC message storage object type */
typedef enum EN_MTC_IM_MS_OBJ_TYPE
{
    EN_MTC_IM_MS_OBJ_MSG,
    EN_MTC_IM_MS_OBJ_SESS,
    EN_MTC_IM_MS_OBJ_SESS_MSG,
    EN_MTC_IM_MS_OBJ_FT,
    EN_MTC_IM_MS_OBJ_FT_MSG
} EN_MTC_IM_MS_OBJ_TYPE;

/* @brief MTC message storage information type */
typedef enum EN_MTC_IM_MS_INFO_TYPE
{
    EN_MTC_IM_MS_INFO_FROM,
    EN_MTC_IM_MS_INFO_TO,
    EN_MTC_IM_MS_INFO_SUBJECT,
    EN_MTC_IM_MS_INFO_DATE_TIME,
    EN_MTC_IM_MS_INFO_DATE_MTIME,
    EN_MTC_IM_MS_INFO_CONTENT_TYPE,
    EN_MTC_IM_MS_INFO_CONTENT_ENCODE,
    EN_MTC_IM_MS_INFO_DATA,

    EN_MTC_IM_MS_INFO_SESS_TYPE,
    EN_MTC_IM_MS_INFO_INVT_PARTP_LST,
    EN_MTC_IM_MS_INFO_CONV_ID,
    EN_MTC_IM_MS_INFO_CONT_ID,
    EN_MTC_IM_MS_INFO_IRT_CONT_ID,
    EN_MTC_IM_MS_INFO_IMDN_MSG_ID,

    EN_MTC_IM_MS_INFO_FT_TYPE,
    EN_MTC_IM_MS_INFO_FILE_ID,
    EN_MTC_IM_MS_INFO_FILE_DESC,
    EN_MTC_IM_MS_INFO_FILE_NAME,
    EN_MTC_IM_MS_INFO_FILE_PATH,
    EN_MTC_IM_MS_INFO_FILE_TYPE,
    EN_MTC_IM_MS_INFO_FILE_DISP,
    EN_MTC_IM_MS_INFO_FILE_DATE,
    
    EN_MTC_IM_MS_INFO_TYPE_MAX
} EN_MTC_IM_MS_INFO_TYPE;

/**
 * @brief MTC create message storage session.
 * @return Message storage session ID when succeed, ZMAXUINT when failed.
 */
ZFUNC ZUINT Mtc_ImMsCreate();

/**
 * @brief MTC delete message storage session.
 * @param  iSessId Message storage session ID, created by @ref Mtc_ImMsCreate
 * @return          ZOK when succeed, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsDelete(ZUINT iSessId);

/**
 * @brief Set cookie to message storage session.
 * @param  iSessId Message storage session ID.
 * @param  zCookie  Cookie value.
 * @return          ZOK when succeed, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsSetCookie(ZUINT iSessId, ZCOOKIE zCookie);

/**
 * @brief Get cookie of message storage session.
 * @param  iSessId Message storage session ID.
 * @return          Cookie value when succeed, 0 when failed.
 */
ZFUNC ZCOOKIE Mtc_ImMsGetCookie(ZUINT iSessId);

/**
 * @brief Start backup progress.
 * @param  iSessId  Message storage session ID.
 * @param  pcDirName String of directory to store backup data.
 * @return           ZOK when command sent, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsBackupBegin(ZUINT iSessId, ZCONST ZCHAR *pcDirName);

/**
 * @brief Stop backup progress.
 * @param  iSessId Message storage session ID.
 * @return          ZOK when command sent, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsBackupEnd(ZUINT iSessId);

/**
 * @brief Append one message object to backup progress.
 * @param  iSessId Message storage session ID.
 * @param  iObjId  Message object ID, create by @ref Mtc_ImMsObjCreate.
 * @return          ZOK when command sent, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsBackupAppend(ZUINT iSessId, ZUINT iObjId);

/**
 * @brief Start restore progress.
 * @param  iSessId  Message storage session ID.
 * @param  pcDirName String of directory restore from.
 * @return           ZOK when command sent, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsRestoreBegin(ZUINT iSessId, ZCONST ZCHAR *pcDirName);

/**
 * @brief Stop restore progress.
 * @param  iSessId Message storage session ID.
 * @return          ZOK when command sent, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsRestoreEnd(ZUINT iSessId);

/**
 * @brief Get object count of message storage session.
 * @param  iSessId Message storage session ID.
 * @return          object count value.
 */
ZFUNC ZUINT Mtc_ImMsGetObjCount(ZUINT iSessId);

/**
 * @brief Get empty restore indication flag of message storage session.
 * @param  iSessId Message storage session ID.
 * @return          empty restore indication flag.
 */
ZFUNC ZBOOL Mtc_ImMsGetEmptyRestoreInd(ZUINT iSessId);

/**
 * @brief Create message object.
 * @param  iType Message object type @ref EN_MTC_IM_MS_OBJ_TYPE.
 * @return       Message object ID, ZMAXUINT when failed.
 */
ZFUNC ZUINT Mtc_ImMsObjCreate(ZUINT iType);

/**
 * @brief Get type of storage object.
 *
 * @param  iObjId Message object.
 *
 * @retval iType Message object type @ref EN_MTC_IM_MS_OBJ_TYPE.
 */
ZFUNC ZUINT Mtc_ImMsObjGetType(ZUINT iObjId);

/**
 * @brief Delete message object.
 * @param  iObjId Message object create by @ref Mtc_ImMsObjCreate.
 * @return         ZOK when succeed, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsObjDelete(ZUINT iObjId);

/** 
 * @brief Add child message object.
 * @param  iObjId   The parent message object ID.
 * @param  iChildId The child message object ID.
 * @return           ZOK when add succeed, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsObjAddChild(ZUINT iObjId, ZUINT iChildId);

/**
 * @brief Get the count of children message object.
 * @param  iObjId Message object ID.
 * @return         The count of children message object.
 */
ZFUNC ZUINT Mtc_ImMsObjGetChildCount(ZUINT iObjId);

/**
 * @brief Enumerate the child message object ID by index.
 * @param  iObjId Message object ID.
 * @param  iIndex  Index of child message object, from 0 to count-1.
 * @return         The child message object ID when succeed,
 *                 ZMAXUINT when failed.
 */
ZFUNC ZUINT Mtc_ImMsObjEnumChild(ZUINT iObjId, ZUINT iIndex);

/**
 * @brief Add information to message object in type of C string.
 * @param  iObjId Message object ID.
 * @param  iType   Information type, @ref EN_MTC_IM_MS_INFO_TYPE.
 * @param  pcValue C string value.
 * @return         ZOK when succeed, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsObjAddStr(ZUINT iObjId, ZUINT iType,
                ZCONST ZCHAR *pcValue);

/**
 * @brief Add information to message object in type of 64 bits value.
 * @param  iObjId Message object ID.
 * @param  iType   Information type, @ref EN_MTC_IM_MS_INFO_TYPE.
 * @param  qwValue Integer value.
 * @return         ZOK when succeed, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsObjAddInt(ZUINT iObjId, ZUINT iType, ZLLONG qwValue);

/**
 * @brief Add information to message object in type of memory data.
 * @param  iObjId  Message object ID.
 * @param  iType    Information type, @ref EN_MTC_IM_MS_INFO_TYPE.
 * @param  pData    Pointer to memory data.
 * @param  iDataLen Size in bytes of data.
 * @return          ZOK when succeed, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsObjAddData(ZUINT iObjId, ZUINT iType,
                ZVOID *pData, ZUINT iDataSize);

/**
 * @brief Get the information value of message object in type of C string.
 * @param  iObjId Message object ID.
 * @param  iType   Information type, @ref EN_MTC_IM_MS_INFO_TYPE.
 * @return         C string of information when succeed, ZNULL when failed.
 */
ZFUNC ZCONST ZCHAR * Mtc_ImMsObjGetStr(ZUINT iObjId, ZUINT iType);

/**
 * @brief Get the information value of message object in type of 64 bits integer.
 * @param  iObjId Message object ID.
 * @param  iType   Information type, @ref EN_MTC_IM_MS_INFO_TYPE.
 * @return         Integer value of information when succeed, 0 when failed.
 */
ZFUNC ZLLONG Mtc_ImMsObjGetInt(ZUINT iObjId, ZUINT iType);

/**
 * @brief Get the information value of message object in type of memory data.
 * @param  iObjId   Message object ID.
 * @param  iType   Information type, @ref EN_MTC_IM_MS_INFO_TYPE.
 * @param  ppData    Pointer to store the pointer of memory data.
 * @param  piDataLen Pointer to store the size in bytes of memory data.
 * @return           ZOK when succeed, otherwise when failed.
 */
ZFUNC ZINT Mtc_ImMsObjGetData(ZUINT iObjId, ZUINT iType,
                ZVOID **ppData, ZUINT *piDataSize);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_MS_H__ */

