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
  File name     : mtc_im_file.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC IM file transfer.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_FILE_H__
#define _MTC_IM_FILE_H__

/**
 * @file mtc_im_file.h
 * @brief MTC Instant Message File Transfer Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC IM file transfer content type */
#define MTC_IM_FILE_CONT_TXT_PLAIN "text/plain" /**< @brief text/plain content */
#define MTC_IM_FILE_CONT_TXT_HTML  "text/html"  /**< @brief text/html content */
#define MTC_IM_FILE_CONT_TXT_VCARD "text/x-vcard"  /**< @brief text/x-vcard content */
#define MTC_IM_FILE_CONT_IMG_JPEG  "image/jpeg" /**< @brief image/jpeg content */
#define MTC_IM_FILE_CONT_IMG_GIF   "image/gif"  /**< @brief image/gif content */
#define MTC_IM_FILE_CONT_IMG_PNG   "image/png"  /**< @brief image/png content */
#define MTC_IM_FILE_CONT_IMG_BMP   "image/bmp"  /**< @brief image/bmp content */
#define MTC_IM_FILE_CONT_IMG_MSBMP "image/x-ms-bmp"  /**< @brief image/x-ms-bmp content */
#define MTC_IM_FILE_CONT_IMG_WBMP  "image/vnd.wap.wbmp"  /**< @brief image/vnd.wap.wbmp content */
#define MTC_IM_FILE_CONT_IMG_WEBP  "image/webp"  /**< @brief image/webp content */
#define MTC_IM_FILE_CONT_AUDIO_MP3 "audio/mpeg"  /**< @brief audio/mpeg content */
#define MTC_IM_FILE_CONT_AUDIO_M4A "audio/mp4"  /**< @brief audio/mp4 content */
#define MTC_IM_FILE_CONT_AUDIO_WAV "audio/x-wav"  /**< @brief audio/x-wav content */
#define MTC_IM_FILE_CONT_AUDIO_AMR "audio/amr"  /**< @brief audio/amr content */
#define MTC_IM_FILE_CONT_AUDIO_AWB "audio/amr-wb"  /**< @brief audio/amr-wb content */
#define MTC_IM_FILE_CONT_AUDIO_WMA "audio/x-ms-wma"  /**< @brief audio/x-ms-wma content */
#define MTC_IM_FILE_CONT_AUDIO_3GP "audio/3gpp"  /**< @brief audio/3gpp content */
#define MTC_IM_FILE_CONT_AUDIO_OGG "audio/ogg"  /**< @brief audio/ogg content */
#define MTC_IM_FILE_CONT_AUDIO_AAC "audio/aac"  /**< @brief audio/aac content */
#define MTC_IM_FILE_CONT_AUDIO_ADTS "audio/aac-adts"  /**< @brief audio/aac-adts content */
#define MTC_IM_FILE_CONT_AUDIO_MKA "audio/x-matroska"  /**< @brief audio/x-matroska content */
#define MTC_IM_FILE_CONT_AUDIO_MID "audio/midi"  /**< @brief audio/midi content */
#define MTC_IM_FILE_CONT_AUDIO_SMF "audio/sp-midi"  /**< @brief audio/sp-midi content */
#define MTC_IM_FILE_CONT_AUDIO_IMY "audio/imelody"  /**< @brief audio/imelody content */
#define MTC_IM_FILE_CONT_AUDIO_M3U "audio/x-mpegurl"  /**< @brief audio/x-mpegurl content */
#define MTC_IM_FILE_CONT_AUDIO_XM3U "audio/mpegurl"  /**< @brief audio/mpegurl content */
#define MTC_IM_FILE_CONT_AUDIO_PLS "audio/x-scpls"  /**< @brief audio/x-scpls content */
#define MTC_IM_FILE_CONT_VIDEO_MPG "video/mpeg"  /**< @brief video/mpeg content */
#define MTC_IM_FILE_CONT_VIDEO_MP4 "video/mp4"  /**< @brief video/mp4 content */
#define MTC_IM_FILE_CONT_VIDEO_3GP "video/3gpp"  /**< @brief video/3gpp content */
#define MTC_IM_FILE_CONT_VIDEO_3G2 "video/3gpp2"  /**< @brief video/3gpp2 content */
#define MTC_IM_FILE_CONT_VIDEO_MKV "video/x-matroska"  /**< @brief video/x-matroska content */
#define MTC_IM_FILE_CONT_VIDEO_WEBM "video/webm"  /**< @brief video/webm content */
#define MTC_IM_FILE_CONT_VIDEO_MP2TS "video/mp2ts"  /**< @brief video/mp2ts content */
#define MTC_IM_FILE_CONT_VIDEO_AVI "video/avi"  /**< @brief video/avi content */
#define MTC_IM_FILE_CONT_VIDEO_WMV "video/x-ms-wmv"  /**< @brief video/x-ms-wmv content */
#define MTC_IM_FILE_CONT_VIDEO_ASF "video/x-ms-asf"  /**< @brief video/x-ms-asf content */
#define MTC_IM_FILE_CONT_VIDEO_MP2PS "video/mp2p"  /**< @brief video/mp2p content */
#define MTC_IM_FILE_CONT_APP_OSTRM "application/octet-stream" /**< @brief application/octet-stream content */

/** @brief MTC file transfer imdn type */
#define MTC_IM_FILE_IMDN_REG         0x00000000 /**< @brief no notification request, regular file transfer */
#define MTC_IM_FILE_IMDN_UNKNOWN     0x00000001 /**< @brief unknown imdn type */
#define MTC_IM_FILE_IMDN_DELI_SUCC   0x00000002 /**< @brief file transfer with delivery succeed notification request */
#define MTC_IM_FILE_IMDN_DELI_FAIL   0x00000004 /**< @brief file transfer with delivery fail notification request */
#define MTC_IM_FILE_IMDN_DELI_FWD    0x00000008 /**< @brief file transfer with delivery forward notification request */
#define MTC_IM_FILE_IMDN_DISP        0x00000010 /**< @brief file transfer with display notification request */
#define MTC_IM_FILE_IMDN_BURN        0x00000020 /**< @brief file transfer with burn after reading notification request */


/** @brief MTC file transfer direct type */
typedef enum EN_MTC_FILE_DIRECT_TYPE
{
    EN_MTC_FILE_DIRECT_UNKNOWN,     /**< @brief file transfer direct unknown */
    EN_MTC_FILE_DIRECT_SENDER,      /**< @brief file transfer direct sender */
    EN_MTC_FILE_DIRECT_RECVER       /**< @brief file transfer direct receiver */
} EN_MTC_FILE_DIRECT_TYPE;

/** @brief MTC file session reject reason type */
typedef enum EN_MTC_IM_FILE_REJECT_REASON_TYPE
{
    EN_MTC_IM_FILE_REJECT_REASON_NORMAL,        /**< @brief normal */
    EN_MTC_IM_FILE_REJECT_REASON_FILE_TOO_LARGE /**< @brief file too large */
} EN_MTC_IM_FILE_REJECT_REASON_TYPE;

/** @brief MTC IM file message spam type */
typedef enum EN_MTC_IM_FILE_SPAM_TYPE
{
    EN_MTC_IM_FILE_SPAM_MIN,
    EN_MTC_IM_FILE_SPAM_POLITICAL_RUMOR,            /**< @brief political rumor msg */
    EN_MTC_IM_FILE_SPAM_JURISPRUDENCE,                /**< @brief jurisprudence msg */
    EN_MTC_IM_FILE_SPAM_FRAUD,                               /**< @brief fraud msg */
    EN_MTC_IM_FILE_SPAM_MALICIOUS_MARKETING,   /**< @brief malicious marketing msg */
    EN_MTC_IM_FILE_SPAM_VIOLENCE,                          /**< @brief violence msg */
    EN_MTC_IM_FILE_SPAM_OTHER= 9,                          /**< @brief other msg */
    EN_MTC_IM_FILE_SPAM_MAX
} EN_MTC_IM_FILE_SPAM_TYPE;

/** @brief MTC file transfer status type */
typedef enum EN_MTC_FILE_STATUS_TYPE
{
    EN_MTC_FILE_STATUS_NO,          /**< @brief file transfer status no */       
    EN_MTC_FILE_STATUS_READY,       /**< @brief file transfer status ready */
    EN_MTC_FILE_STATUS_SENDING,     /**< @brief file transfer status sending */
    EN_MTC_FILE_STATUS_RECVING,     /**< @brief file transfer status recving */
    EN_MTC_FILE_STATUS_ENDING,      /**< @brief file transfer status ending */     
} EN_MTC_FILE_STATUS_TYPE;


/**
 * @brief MTC Sending a file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsf(ZCOOKIE zCookie, ZCHAR *pcSubject, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration);

/**
 * @brief MTC Forwarding a file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iFileSize The file size.
 * @param [in] pcFileHashVal The file hash value.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, forward file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFw(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iFileSize, 
                ZCHAR *pcFileHashVal, ZUINT iDuration);

/**
 * @brief MTC Sending a burn after reading file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * Gui can get the burn after reading flag when receiving IM by @ref Mtc_ImFileHasBurnInd.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, if send file transfer(burn after reading) invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfB(ZCOOKIE zCookie, ZCHAR *pcSubject, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration);

/**
 * @brief MTC Sending a public message file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * Gui can get the burn after reading flag when receiving IM by @ref Mtc_ImFileHasBurnInd.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, if send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfP(ZCOOKIE zCookie, ZCHAR *pcSubject, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration);

/**
 * @brief MTC Forwarding a public message file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * Gui can get the burn after reading flag when receiving IM by @ref Mtc_ImFileHasBurnInd.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iFileSize The file size. 
 * @param [in] pcFileHashVal The file hash value.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, if forward file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFwP(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iFileSize, 
                ZCHAR *pcFileHashVal, ZUINT iDuration);

/**
 * @brief MTC Sending a spam file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfS(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration, 
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate);

/**
 * @brief MTC Sending a spam file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 * @param [in] iSpamType The spam information type.
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfST(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration, 
                ZCHAR *pcFromUri, ZCHAR *pcToUri, ZMTIME_T zDate, ZUINT iSpamType);

/**
 * @brief MTC Sending a file to URI-List.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration);

/**
 * @brief MTC Forwarding a file to URI-List.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN.
 * @param [in] iFileSize The file size. 
 * @param [in] pcFileHashVal The file hash value.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, forward file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFwU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iFileSize, 
                ZCHAR *pcFileHashVal, ZUINT iDuration);


/**
 * @brief MTC Sending a file in a group chat.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The group chat URI.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfX(ZCOOKIE zCookie, ZCHAR *pcSubject, ZCHAR *pcUri,
                ZCHAR *pcGrpChatId, ZCHAR *pcFileName, ZCHAR *pcFileType, 
                ZUINT iDuration);

/**
 * @brief MTC Forwarding a file in a group chat.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The group chat URI.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iFileSize The file size.
 * @param [in] pcFileHashVal The file hash value.
 * @param [in] iDuration The file duration.
 *
 * @return The file transfer id, forward file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFwX(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri,  ZCHAR *pcGrpChatId, ZCHAR *pcFileName,
                ZCHAR *pcFileType, ZUINT iFileSize, ZCHAR *pcFileHashVal, ZUINT iDuration);

/**
 * @brief MTC Sending a file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 * @param [in] pData The file thumbnail data, thumbnail  shall  be  smaller  than  10  kB 
 * @param [in] iDataSize The file thumbnail size, thumbnail  shall  be  smaller  than  10  kB 
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfCThumb(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration, 
                ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Forward a file to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM forwarding start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report forward
 * file status.
 *
 * If IM forward successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM forward failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iFileSize The file size.
 * @param [in] pcFileHashVal The file hash value.
 * @param [in] iDuration The file duration.
 * @param [in] pData The file thumbnail data, thumbnail  shall  be  smaller  than  10  kB 
 * @param [in] iDataSize The file thumbnail size, thumbnail  shall  be  smaller  than  10  kB 
 *
 * @return The file transfer id, forward file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFwCThumb(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iFileSize, 
                ZCHAR *pcFileHashVal, ZUINT iDuration, ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Sending a file to public account.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 * @param [in] pData The file thumbnail data, thumbnail  shall  be  smaller  than  10  kB 
 * @param [in] iDataSize The file thumbnail size, thumbnail  shall  be  smaller  than  10  kB 
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfCThumbP(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration, 
                ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC forward a file to public account.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iFileSize The file size.
 * @param [in] pcFileHashVal The file hash value.
 * @param [in] iDuration The file duration.
 * @param [in] pData The file thumbnail data, thumbnail  shall  be  smaller  than  10  kB 
 * @param [in] iDataSize The file thumbnail size, thumbnail  shall  be  smaller  than  10  kB 
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFwCThumbP(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iFileSize, 
                ZCHAR *pcFileHashVal, ZUINT iDuration, ZVOID *pData, ZUINT iDataSize);


/**
 * @brief MTC Sending a file to URI-List.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN.
 * @param [in] iDuration The file duration.
 * @param [in] pData The file thumbnail data.
 * @param [in] iDataSize The file thumbnail size, thumbnail shall be smaller than 10 kB 
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfCThumbU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration, 
                ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Forwarding a file to URI-List.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN.
 * @param [in] iFileSize The file size.
 * @param [in] pcFileHashVal The file hash value.
 * @param [in] iDuration The file duration.
 * @param [in] pData The file thumbnail data.
 * @param [in] iDataSize The file thumbnail size, thumbnail shall be smaller than 10 kB 
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFwCThumbU(ZCOOKIE zCookie, ZUINT iPartpLstId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iFileSize, 
                ZCHAR *pcFileHashVal, ZUINT iDuration, ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Sending a file in a group chat.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iDuration The file duration.
 * @param [in] pData The file thumbnail data, thumbnail  shall  be  smaller  than  10  kB 
 * @param [in] iDataSize The file thumbnail size, thumbnail  shall  be  smaller  than  10  kB 
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileTrsfCThumbX(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri,  ZCHAR *pcGrpChatId, ZCHAR *pcFileName,
                ZCHAR *pcFileType, ZUINT iDuration, ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Forwarding a file in a group chat.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetFileAcpted or @ref Mtc_ImCbSetFileRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSending for report sending
 * file status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetFileSendFailed.
 *
 * While receiving file transfer invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecving. 
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetFileRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN etc.
 * @param [in] iFileSize The file size.
 * @param [in] pcFileHashVal The file hash value.
 * @param [in] iDuration The file duration.
 * @param [in] pData The file thumbnail data, thumbnail  shall  be  smaller  than  10  kB 
 * @param [in] iDataSize The file thumbnail size, thumbnail  shall  be  smaller  than  10  kB 
 *
 * @return The file transfer id, send file transfer invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFwCThumbX(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri,  ZCHAR *pcGrpChatId, ZCHAR *pcFileName,
                ZCHAR *pcFileType, ZUINT iFileSize, ZCHAR *pcFileHashVal, ZUINT iDuration, 
                ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Sending file resume invitation to one participant by sender.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcIMsgId The imdn-message-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iDuration The file duration.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 * @param [in] pData The file thumbnail data.
 * @param [in] iDataSize The file thumbnail size, thumbnail shall be smaller than 10 kB.
 *
 * @return The file transfer id, send file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeBySender(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcTransId, ZCHAR *pcIMsgId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration, 
                ZUINT iStartOffset, ZUINT iStopOffset, ZVOID *pData, 
                ZUINT iDataSize);

/**
 * @brief MTC Sending burn after reading file resume invitation to one participant by sender.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcIMsgId The imdn-message-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iDuration The file duration.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 *
 * @return The file transfer id, send burn after reading file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeBySenderB(ZCOOKIE zCookie, 
                    ZCHAR *pcSubject, ZCHAR *pcUri,  ZCHAR *pcTransId, 
                    ZCHAR *pcIMsgId, ZCHAR *pcFileName, ZCHAR *pcFileType, 
                    ZUINT iDuration, ZUINT iStartOffset, ZUINT iStopOffset);

/**
 * @brief MTC Sending public message file resume invitation to participant list by sender.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcIMsgId The imdn-message-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iDuration The file duration.
 * @param [in] iStartOffset The file start offset.
 * @param [in] iStopOffset The file stop offset.
 * @param [in] pData The file thumbnail data.
 * @param [in] iDataSize The file thumbnail size, thumbnail shall be smaller than 10 kB.
 *
 * @return The file transfer id, send burn after reading file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeBySenderP(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcTransId, ZCHAR *pcIMsgId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration, 
                ZUINT iStartOffset, ZUINT iStopOffset, ZVOID *pData, 
                ZUINT iDataSize);

/**
 * @brief MTC Sending spam file resume invitation to one participant by sender.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcIMsgId The imdn-message-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iDuration The file duration.
 * @param [in] iStartOffset The file start offset.
 * @param [in] iStopOffset The file stop offset.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds).
 *
 * @return The file transfer id, send burn after reading file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeBySenderS(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcTransId, ZCHAR *pcIMsgId, ZCHAR *pcFileName, 
                ZCHAR *pcFileType, ZUINT iDuration, ZUINT iStartOffset, 
                ZUINT iStopOffset, ZCHAR *pcFromUri, ZCHAR *pcToUri, 
                ZMTIME_T zDate);

/**
 * @brief MTC Sending spam file resume invitation to one participant by sender.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcIMsgId The imdn-message-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iDuration The file duration.
 * @param [in] iStartOffset The file start offset.
 * @param [in] iStopOffset The file stop offset.
 * @param [in] pcFromUri The from uri.
 * @param [in] pcToUri The to uri.
 * @param [in] zDate The date(milliseconds). 
 * @param [in] iSpamtype The spam information type.
 *
 * @return The file transfer id, send burn after reading file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeBySenderST(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcTransId, ZCHAR *pcIMsgId, ZCHAR *pcFileName, 
                ZCHAR *pcFileType, ZUINT iDuration, ZUINT iStartOffset, 
                ZUINT iStopOffset, ZCHAR *pcFromUri, ZCHAR *pcToUri, 
                ZMTIME_T zDate, ZUINT iSpamtype);


/**
 * @brief MTC Sending file resume invitation to participant list by sender.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] iPartpLstId The participant list id.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcIMsgId The imdn-message-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iDuration The file duration.
 * @param [in] iStartOffset The file start offset.
 * @param [in] iStopOffset The file stop offset.
 * @param [in] pData The file thumbnail data.
 * @param [in] iDataSize The file thumbnail size, thumbnail shall be smaller than 10 kB.
 *
 * @return The file transfer id, send burn after reading file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeBySenderU(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZUINT iPartpLstId, ZCHAR *pcTransId, ZCHAR *pcIMsgId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iDuration, 
                ZUINT iStartOffset, ZUINT iStopOffset, ZVOID *pData, 
                ZUINT iDataSize);

/**
 * @brief MTC Sending file resume invitation to group chat by sender.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcIMsgId The imdn-message-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iDuration The file duration.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 * @param [in] pData The file thumbnail data.
 * @param [in] iDataSize The file thumbnail size, thumbnail shall be smaller than 10 kB.
 *
 * @return The file transfer id, send file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeBySenderX(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcGrpChatId, ZCHAR *pcTransId, 
                ZCHAR *pcIMsgId, ZCHAR *pcFileName, ZCHAR *pcFileType, 
                ZUINT iDuration, ZUINT iStartOffset, ZUINT iStopOffset, 
                ZVOID *pData, ZUINT iDataSize);

/**
 * @brief MTC Sending file resume invitation to one participant by receiver.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 *
 * @return The file transfer id, send file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeByRecver(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcTransId, ZCHAR *pcFileName, 
                ZCHAR *pcFileType, ZUINT iStartOffset, ZUINT iStopOffset);

/**
 * @brief MTC Sending burn after reading file resume invitation to one participant by receiver.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 *
 * @return The file transfer id, send file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeByRecverB(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcTransId, ZCHAR *pcFileName, 
                ZCHAR *pcFileType, ZUINT iStartOffset, ZUINT iStopOffset);

/**
 * @brief MTC Sending file resume invitation to group chat by receiver.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The participant URI.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 *
 * @return The file transfer id, send file resume invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileResumeByRecverX(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcGrpChatId, ZCHAR *pcTransId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType, ZUINT iStartOffset, 
                ZUINT iStopOffset);

/**
 * @brief MTC Sending file fetch invitation to one participant via msrp.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 *
 * @return The file transfer id, send file fetch invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFetchViaMsrp(ZCOOKIE zCookie, ZCHAR *pcUri, 
                ZCHAR *pcTransId, ZCHAR *pcFileName, ZCHAR *pcFileType);

/**
 * @brief MTC Sending file fetch invitation to group chat via msrp.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcSubject The user subject.
 * @param [in] pcUri The The group chat Session Identity.
 * @param [in] pcGrpChatId The group chat id.
 * @param [in] pcTransId The file-transfer-id string.
 * @param [in] pcFileName The file name.
 * @param [in] pcFileType The file type.
 *
 * @return The file transfer id, send file fetch invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImFileFetchViaMsrpX(ZCOOKIE zCookie, ZCHAR *pcSubject, 
                ZCHAR *pcUri, ZCHAR *pcGrpChatId, ZCHAR *pcTransId, 
                ZCHAR *pcFileName, ZCHAR *pcFileType);

/**
 * @brief MTC Accept a file transfer invitation.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in] pcFileName The local file name for save.
 *
 * @retval ZOK Accept file transfer invitation successfully.
 * @retval ZFAILED Accept file transfer invitation failed.
 */
ZFUNC ZINT Mtc_ImFileAccept(ZUINT iTrsfId, ZCHAR *pcFileName);

/**
 * @brief MTC Accept a file resume invitation.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in] pcFileName The local file name for save.
 * @param [in] iStartOffset The file start offset, value must bigger than 0.
 * @param [in] iStopOffset The file stop offset, value 0 means the end of whole file.
 *
 * @retval ZOK Accept file resume invitation successfully.
 * @retval ZFAILED Accept file resume invitation failed.
 */
ZFUNC ZINT Mtc_ImFileAcceptResume(ZUINT iTrsfId, ZCHAR *pcFileName, 
                ZUINT iStartOffset, ZUINT iStopOffset);

/**
 * @brief MTC Reject a file transfer invitation.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in] iReason The reason for rejection, @see @ref EN_MTC_IM_FILE_REJECT_REASON_TYPE.
 *
 * @retval ZOK Reject file transfer invitation successfully.
 * @retval ZFAILED Reject file transfer invitation failed.
 */
ZFUNC ZINT Mtc_ImFileReject(ZUINT iTrsfId, ZUINT iReason);

/**
 * @brief MTC Cancel a file transfer.
 * 
 * If IM participant canceled transfer invitation, Remote client will be 
 * notified by callback which was set by @ref Mtc_ImCbSetFileCanceled.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZOK Cancel file transfer invitation successfully.
 * @retval ZFAILED Cancel file transfer invitation failed.
 */
ZFUNC ZINT Mtc_ImFileCancel(ZUINT iTrsfId);

/**
 * @brief MTC Release a file transfer.
 * 
 * If IM participant released file transfer, Remote GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetFileReleased.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZOK Release file transfer successfully.
 * @retval ZFAILED Release file transfer failed.
 */
ZFUNC ZINT Mtc_ImFileRelease(ZUINT iTrsfId);

/**
 * @brief MTC Get user cookie from a file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImFileGetCookie(ZUINT iTrsfId);

/**
 * @brief MTC Set user cookie in a file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImFileSetCookie(ZUINT iTrsfId, ZCOOKIE zCookie);

/**
 * @brief MTC Get the Imdn type from file transfer.
 *
 * @param [in] iTrsfId The file transfer Id.
 *
 * @return Type of file transfer, see @ref EN_MTC_IM_FILE_IMDN_TYPE.
 */
ZFUNC ZUINT Mtc_ImFileGetImdnType(ZUINT iTrsfId);

/**
 * @brief MTC Get imdn message-id string of transfer id.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The imdn message-id.
 */
ZFUNC ZCHAR * Mtc_ImFileGetImdnMsgId(ZUINT iTrsfId);

/**
 * @brief MTC Get file-transfer-id string of IM message.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The file-transfer-id.
 */
ZFUNC ZCHAR * Mtc_ImFileGetTrsfId(ZUINT iTrsfId);

/**
 * @brief MTC Get group chat id from transfer id.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The group chat id.
 */
ZFUNC ZCHAR * Mtc_ImFileGetGrpChatId(ZUINT iTrsfId);

/**
 * @brief MTC Get file name from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return File name.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFileGetName(ZUINT iTrsfId);

/**
 * @brief MTC Get file path from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return File path.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFileGetPath(ZUINT iTrsfId);

/**
 * @brief MTC Get file type from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return File type, see @ref MTC_IM_FILE_CONT_TXT_PLAIN....
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFileGetType(ZUINT iTrsfId);

/**
 * @brief MTC Get file duration from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The file duration.
 */
ZFUNC ZUINT Mtc_ImFileGetDuration(ZUINT iTrsfId);

/**
 * @brief MTC Get file size from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The file size.
 */
ZFUNC ZUINT Mtc_ImFileGetSize(ZUINT iTrsfId);

/**
 * @brief MTC Get file hash value from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The file hash value.
 */
ZFUNC ZCHAR * Mtc_ImFileGetHashValue(ZUINT iTrsfId);

/**
 * @brief MTC Get sent file data size from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The file data sent size.
 */
ZFUNC ZUINT Mtc_ImFileGetSentSize(ZUINT iTrsfId);

/**
 * @brief MTC Get received file data size from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The file data received size.
 */
ZFUNC ZUINT Mtc_ImFileGetRecvSize(ZUINT iTrsfId);

/**
 * @brief MTC Get file start offset from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval The file start offset.
 */
ZFUNC ZUINT Mtc_ImFileGetStartOffset(ZUINT iTrsfId);

/**
 * @brief MTC Get file start offset from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval The file stop offset.
 */
ZFUNC ZUINT Mtc_ImFileGetStopOffset(ZUINT iTrsfId);

/**
 * @brief MTC Get participant type from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return Type of IM file transfer participant, see @ref EN_MTC_PARTP_LST_TYPE.
 * If type is EN_MTC_PARTP_LST_ONE, participant can be got by @ref Mtc_ImFileGetPartp.
 * If type is EN_MTC_PARTP_LST_PREDEF_GRP, participant can be got by @ref Mtc_ImFileGetPartp.
 * If type is EN_MTC_PARTP_LST_URI_LST, participant can be got by @ref Mtc_ImFileGetPartpLstId.
 */
ZFUNC ZUINT Mtc_ImFileGetPartpType(ZUINT iTrsfId);

/**
 * @brief MTC Get participant information from file transfer.
 * Get receiver information from feion carbon copy file transfer.
 *
 * The participant is the remote client who transferred file.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 * 
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImFileGetPartp(ZUINT iTrsfId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get participant list id from file transfer.
 *
 * The participant list id is all remote clients who transferred file.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The participant list id on succeed or 0 on failed.
 *  The caller is responsible for freeing it by @ref Mtc_PartpLstDelete.
 */
ZFUNC ZUINT Mtc_ImFileGetPartpLstId(ZUINT iTrsfId);

/**
 * @brief MTC Get original participant URI from file transfer.
 *
 * The participant is the session initiator who initialized this file transfer.
 * It will return local URI if local client is the file transfer initiator.
 * It will return From uri from file transfer invitation information.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 * 
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImFileGetOrigPartp(ZUINT iTrsfId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief MTC Get original identity of participant from file transfer.
 *
 * The participant is the file transfer initiator who initialized file transfer.
 * It will return local URI if local client is the file transfer initiator.
 * It will return identity uri if file transfer invitation has P-Asserted-Identity information.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant uri.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImFileGetOrigIdPartp(ZUINT iTrsfId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief MTC Get date time from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time date failed.
 */
ZFUNC ZINT Mtc_ImFileGetSysDateTime(ZUINT iTrsfId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return file transfer date time(milliseconds), otherwise return 0.
 */
ZFUNC ZMTIME_T Mtc_ImFileGetDateTime(ZUINT iTrsfId);

/* mtc get conversation-id from file transfer session. */
/**
 * @brief MTC Get conversation-id from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The conversation-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFileGetConvId(ZUINT iTrsfId);

/**
 * @brief MTC Get contribution-id from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The contribution-id.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFileGetContId(ZUINT iTrsfId);

/**
 * @brief MTC Get device id from file transfer session.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return The device id.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImFileGetDeviceId(ZUINT iTrsfId);

/**
 * @brief MTC Get thumbnail flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval return ZTRUE if file transfer has thumbnail otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFileHasThumb(ZUINT iTrsfId);

/**
 * @brief MTC Get thumbnail date from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 * @param [in,out] ppData thumbnail data. 
 * @param [in,out] piDataSize thumbnail data size. 
 *
 * @retval ZOK Get thumbnail date successfully.
 * @retval ZFAILED Get thumbnail date failed.
 */
ZFUNC ZINT Mtc_ImFileGetThumbData(ZUINT iTrsfId, ZVOID **ppData, 
                ZUINT *piDataSize);

/**
 * @brief MTC Clear thumbnail date.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZOK Clear thumbnail date successfully.
 * @retval ZFAILED Clear thumbnail date failed.
 */
ZFUNC ZINT Mtc_ImFileClrThumbData(ZUINT iTrsfId);

/**
 * @brief MTC Get IsFocus flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval return ZTRUE file transfer in group chat
 * @retval return ZFALSE file transfer in 1-1 chat.
 */
ZFUNC ZBOOL Mtc_ImFileGetIsFocus(ZUINT iTrsfId);

/**
 * @brief MTC Get subject from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval Subject.
 */
ZFUNC ZCHAR * Mtc_ImFileGetSubject(ZUINT iTrsfId);

/**
 * @brief MTC Get direct from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return direct of file transfer, @ref EN_MTC_FILE_DIRECT_TYPE.
 */
ZFUNC ZUINT Mtc_ImFileGetTrsfDirect(ZUINT iTrsfId);

/**
 * @brief MTC Get burn after reading indication flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZTRUE if it has burn after reading file indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFileHasBurnInd(ZUINT iTrsfId);

/**
 * @brief MTC Get burn after reading time length from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @return burn after reading time length.
 */
ZFUNC ZUINT Mtc_ImFileGetBurnTimeLen(ZUINT iTrsfId);

/**
 * @brief MTC Get public message indication flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZTRUE if it has public message indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFileHasPubInd(ZUINT iTrsfId);

/**
 * @brief MTC Get spam indication flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZTRUE if it has spam indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFileHasSpamInd(ZUINT iTrsfId);

/**
 * @brief MTC Get directional indication flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZTRUE if it has directional indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFileHasDirectInd(ZUINT iTrsfId);

/**
 * @brief MTC Get carbon copy indication flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZTRUE if it has carbon copy indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFileHasCcInd(ZUINT iTrsfId);

/**
 * @brief MTC Get silence indication flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZTRUE if it has silence indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFileHasSilenceInd(ZUINT iTrsfId);

/**
 * @brief MTC Get offline indication flag from file transfer.
 *
 * @param [in] iTrsfId The file transfer id.
 *
 * @retval ZTRUE if it has offline indication, otherwise return ZFALSE.
 */
ZFUNC ZBOOL Mtc_ImFileHasOffInd(ZUINT iTrsfId);

/**
 * @brief MTC Get file transfer state from file transfer id string.
 *
 * @param [in] pcTransId The file-transfer-id string.
 *
 * @return The file transfer state, @ref EN_MTC_FILE_STATUS_TYPE.
 */
ZFUNC ZUINT Mtc_ImFileGetTransState(ZCHAR *pcTransId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_FILE_H__ */

