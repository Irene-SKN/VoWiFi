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
  File name     : mtc_im_fthttp.h
  Module        : multimedia talk client
  Author        : anthouny.zhou
  Created on    : 2013-08-01
  Description   :
      Data structure and function declare required by MTC IM file transfer 
      via http.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_FTHTTP_H__
#define _MTC_IM_FTHTTP_H__

/**
 * @file mtc_im_fthttp.h
 * @brief MTC Instant Message File Transfer Via Http Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC IM file transfer via http hcontent type */
#define MTC_IM_FTHTTP_CONT_TXT_PLAIN "text/plain" /**< @brief text/plain content */
#define MTC_IM_FTHTTP_CONT_TXT_HTML  "text/html"  /**< @brief text/html content */
#define MTC_IM_FTHTTP_CONT_IMG_JPEG  "image/jpeg" /**< @brief image/jpeg content */
#define MTC_IM_FTHTTP_CONT_IMG_GIF   "image/gif"  /**< @brief image/gif content */
#define MTC_IM_FTHTTP_CONT_IMG_BMP   "image/bmp"  /**< @brief image/bmp content */
#define MTC_IM_FTHTTP_CONT_IMG_PNG   "image/png"  /**< @brief image/png content */

/** @brief MTC IM file transfer via http imdn type */
#define MTC_IM_FTHTTP_IMDN_NO              0x00000000 /**< @brief regular message */
#define MTC_IM_FTHTTP_IMDN_UNKNOWN         0x00000001 /**< @brief unknown imdn type */
#define MTC_IM_FTHTTP_IMDN_DELI_SUCC       0x00000002 /**< @brief message with delivery succeed notification request */
#define MTC_IM_FTHTTP_IMDN_DELI_FAIL       0x00000004 /**< @brief message with delivery fail notification request */
#define MTC_IM_FTHTTP_IMDN_DELI_FWD        0x00000008 /**< @brief message with delivery forward notification request */
#define MTC_IM_FTHTTP_IMDN_DISP            0x00000010 /**< @brief message with display notification request */


/**
 * @brief MTC Sending a file via http to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FTHTTP_CONT_TXT_PLAIN etc.
 * @param [in] pData The file thumbnail data, thumbnail  shall  be  smaller  than  10  kB 
 * @param [in] iDataSize The file thumbnail size, thumbnail  shall  be  smaller  than  10  kB 
 *
 * @return The file transfer via http id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFtHttpO(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, 
                ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Sending a file via http to group chat.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcGroupChatId The group chat id(Contribution-ID or Conversation-ID).
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FTHTTP_CONT_TXT_PLAIN.
 * @param [in] pData The file thumbnail data, thumbnail  shall  be  smaller  than  10  kB 
 * @param [in] iDataSize The file thumbnail size, thumbnail  shall  be  smaller  than  10  kB 
 *
 * @return The file transfer via http id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFtHttpG(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcGroupChatId, ZCHAR *pcFileName, ZCHAR *pcFileType,
                ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Resume a file transfer via http to one participant.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] bSender The user is file sender if ZRTUE.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] pcFtHttpTId file Transaction ID for resume.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 *
 * @return The file transfer via http id, if file resume successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFtHttpResumeO(ZCOOKIE zCookie, ZBOOL bSender, 
                ZCHAR *pcUri, ZCHAR *pcFileName, ZCHAR *pcFileType, 
                ZCHAR *pcFtHttpTId, ZUINT iStartOffset, ZUINT iStopOffset);

/**
 * @brief MTC Resume a file transfer via http to group chat.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] bSender The user is file sender if ZRTUE.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcGroupChatId The group chat id(Contribution-ID or Conversation-ID).
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] pcFtHttpTId file Transaction ID for resume.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 *
 * @return The file transfer via http id, if file resume successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFtHttpResumeG(ZCOOKIE zCookie, ZBOOL bSender, 
                ZUINT iPartpLstId, ZCHAR *pcGroupChatId, ZCHAR *pcFileName, 
                ZCHAR *pcFileType, ZCHAR *pcFtHttpTId, 
                ZUINT iStartOffset, ZUINT iStopOffset);

/**
 * @brief MTC Accept a file transfer via http invitation.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 * @param [in] pcFileName The file name.
 *
 * @retval ZOK Accept file transfer via http invitation successfully.
 * @retval ZFAILED Accept file transfer via http invitation failed.
 */
ZFUNC ZINT Mtc_ImFtHttpAccept(ZUINT iFtHttpId, ZCHAR *pcFileName);

/**
 * @brief MTC Reject a file transfer via http invitation.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @retval ZOK Reject file transfer invitation via http successfully.
 * @retval ZFAILED Reject file transfer via http invitation failed.
 */
ZFUNC ZINT Mtc_ImFtHttpReject(ZUINT iFtHttpId);

/**
 * @brief MTC Cancel a file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @retval ZOK Cancel file transfer via http successfully.
 * @retval ZFAILED Cancel file transfer via http  failed.
 */
ZFUNC ZINT Mtc_ImFtHttpCancel(ZUINT iFtHttpId);

/**
 * @brief MTC Release a file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @retval ZOK Release file transfer via http successfully.
 * @retval ZFAILED Release file transfer via http failed.
 */
ZFUNC ZINT Mtc_ImFtHttpRelease(ZUINT iFtHttpId);

/**
 * @brief MTC Get user cookie from a file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImFtHttpGetCookie(ZUINT iFtHttpId);

/**
 * @brief MTC Set user cookie in a file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImFtHttpSetCookie(ZUINT iFtHttpId, ZCOOKIE zCookie);

/**
 * @brief MTC Get message data from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return message data.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFtHttpGetMsgData(ZUINT iFtHttpId);

/**
 * @brief MTC Get file url from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return File url.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFtHttpGetUrl(ZUINT iFtHttpId);

/**
 * @brief MTC Get file validity from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return File validity
 */
ZFUNC ZTIME_T Mtc_ImFtHttpGetValidity(ZUINT iFtHttpId);

/**
 * @brief MTC Get the Imdn type from file transfer via http.
 *
 * @param [in] iFtHttpId The The file transfer via http id.
 *
 * @return Type of message, @ref EN_MTC_IM_FTHTTP_IMDN_ITYPE.
 */
ZFUNC ZUINT Mtc_ImFtHttpGetImdnType(ZUINT iFtHttpId);

/**
 * @brief MTC get imdn message-id from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer id via http id.
 *
 * @return The Imdn message-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFtHttpGetImdnMsgId(ZUINT iFtHttpId);

/**
 * @brief MTC Get file Transaction ID string from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return The file Transaction ID.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFtHttpGetTransId(ZUINT iFtHttpId);

/**
 * @brief MTC Get group chat id from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return The group chat id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFtHttpGetGrpChatId(ZUINT iFtHttpId);

/**
 * @brief MTC Get file name from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @retval File name.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFtHttpGetName(ZUINT iFtHttpId);

/**
 * @brief MTC Get file path from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @retval File name.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFtHttpGetPath(ZUINT iFtHttpId);

 /**
 * @brief MTC Get file type from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return File type, see @ref MTC_IM_FTHTTP_CONT_TXT_PLAIN....
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFtHttpGetType(ZUINT iFtHttpId);

/**
 * @brief MTC Get file size from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer id via http.
 *
 * @return The file size.
 */
ZFUNC ZUINT Mtc_ImFtHttpGetSize(ZUINT iFtHttpId);

/**
 * @brief MTC Get sent file data size from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer id via http.
 *
 * @return The file data sent size.
 */
ZFUNC ZUINT Mtc_ImFtHttpGetSentSize(ZUINT iFtHttpId);

/**
 * @brief MTC Get received file data size from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer id via http.
 *
 * @return The file data received size.
 */
ZFUNC ZUINT Mtc_ImFtHttpGetRecvSize(ZUINT iFtHttpId);

/**
 * @brief MTC Get file start offset from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer id via http.
 *
 * @retval The file start offset.
 */
ZFUNC ZUINT Mtc_ImFtHttpGetStartOffset(ZUINT iFtHttpId);

/**
 * @brief MTC Get file start offset from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer id via http.
 *
 * @retval The file stop offset.
 */
ZFUNC ZUINT Mtc_ImFtHttpGetStopOffset(ZUINT iFtHttpId);

/**
 * @brief MTC Get participant type from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer id.
 *
 * @return Type of IM file transfer via http participant, see @ref EN_MTC_PARTP_LST_TYPE.
 * If type is EN_MTC_PARTP_LST_ONE, participant can be got by @ref Mtc_ImFtHttpGetPartp.
 * If type is EN_MTC_PARTP_LST_PREDEF_GRP, participant can be got by @ref Mtc_ImFtHttpGetPartp.
 * If type is EN_MTC_PARTP_LST_URI_LST, participant can be got by @ref Mtc_ImFtHttpGetPartpLstId.
 */
ZFUNC ZUINT Mtc_ImFtHttpGetPartpType(ZUINT iFtHttpId);

/**
 * @brief MTC Get participant information from file transfer via http.
 *
 * The participant is the remote client who transferred file via http.
 *
 * @param [in] iFtHttpId The file transfer id via http.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 * 
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImFtHttpGetPartp(ZUINT iFtHttpId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get participant list id from file transfer via http.
 *
 * The participant list id is all remote clients who transferred file.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return The participant list id.
 *  The caller is responsible for freeing it by @ref Mtc_PartpLstDelete.
 */
ZFUNC ZUINT Mtc_ImFtHttpGetPartpLstId(ZUINT iFtHttpId);

/**
 * @brief MTC Get original participant URI from file transfer via http.
 *
 * The participant is the session initiator who initialized this file transfer via http.
 * It will return local URI if local client is the file transfer initiator.
 * It will return From uri from file transfer invitation information.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 * 
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImFtHttpGetOrigIdPartp(ZUINT iFtHttpId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get date time from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time date failed.
 */
ZFUNC ZINT Mtc_ImFtHttpGetSysDateTime(ZUINT iFtHttpId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @return file transfer date time, otherwise return 0.
 */
ZFUNC ZTIME_T Mtc_ImFtHttpGetDateTime(ZUINT iFtHttpId);

/**
 * @brief MTC Get thumbnail flag from file transfer via http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @retval return ZTRUE if file transfer via http has thumbnail otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFtHttpHasThumb(ZUINT iFtHttpId);

/**
 * @brief MTC Get thumbnail date from file transfervia http.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 * @param [in,out] ppData thumbnail data. 
 * @param [in,out] piDataSize thumbnail data size. 
 *
 * @retval ZOK Get thumbnail date successfully.
 * @retval ZFAILED Get thumbnail date failed.
 */
/* mtc get thumbnail date from file transfer via http. */
ZFUNC ZINT Mtc_ImFtHttpGetThumbData(ZUINT iFtHttpId, ZVOID **ppData, 
                ZUINT *piDataSize);

/**
 * @brief MTC Clear thumbnail date.
 *
 * @param [in] iFtHttpId The file transfer via http id.
 *
 * @retval ZOK Clear thumbnail date successfully.
 * @retval ZFAILED Clear thumbnail date failed.
 */
ZFUNC ZINT Mtc_ImFtHttpClrThumbData(ZUINT iFtHttpId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_FTHTTP_H__ */