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
  File name     : mtc_im_ishare.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC IM image share

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_ISHARE_H__
#define _MTC_IM_ISHARE_H__

/**
 * @file mtc_im_ishare.h
 * @brief MTC Instant Message Image Share Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC IM image share content type */
typedef enum EN_MTC_IM_ISHARE_CONT_TYPE
{
    EN_MTC_IM_ISHARE_CONT_IMG_JPEG,  /**< @brief image/jpeg content */
    EN_MTC_IM_ISHARE_CONT_IMG_GIF,   /**< @brief image/gif content */
    EN_MTC_IM_ISHARE_CONT_IMG_BMP,   /**< @brief image/bmp content */
    EN_MTC_IM_ISHARE_CONT_IMG_PNG    /**< @brief image/png content */
} EN_MTC_IM_ISHARE_CONT_TYPE;

/**
 * @brief MTC Sending image to one participant.
 *
 * If IM participant receive transfer invitation successfully, 
 * GUI will be notified by callback which was set by 
 * @ref Mtc_ImCbSetIShareAcpted or @ref Mtc_ImCbSetIShareRejected.
 *
 * If IM sending start, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetIShareSending for report sending
 * image status.
 *
 * If IM sent successfully, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetIShareSendOk.
 *
 * If IM send failed, GUI will be notified by callback which 
 * was set by @ref Mtc_ImCbSetIShareSendFailed.
 *
 * While receiving image share invitation, GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetIShareRecvIvt.
 *
 * While IM receiving start, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetIShareRecving.
 *
 * While IM received done, Remote GUI will be notified by callback which
 * was set by @ref Mtc_ImCbSetIShareRecvDone.
 *
 * @param [in] zCookie The user cookie.
 * @param [in] pcUri The participant URI.
 * @param [in] pcFileName The file name.
 * @param [in] iFileType The file type, see @ref EN_MTC_IM_ISHARE_CONT_TYPE.
 *
 * @return The image share id when send image share invitation successfully, 
 *              otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_ImIShareSend(ZCOOKIE zCookie, ZCHAR *pcUri,
                ZCHAR *pcFileName, ZUINT iFileType);

/**
 * @brief MTC Accept a image share invitation.
 *
 * @param [in] iShareId The image share id.
 * @param [in] pcFileName The local file name for save.
 *
 * @retval ZOK Accept image share invitation successfully.
 * @retval ZFAILED Accept image share invitation failed.
 */
ZFUNC ZINT Mtc_ImIShareAccept(ZUINT iShareId, ZCHAR *pcFileName);

/**
 * @brief MTC Reject a image share invitation.
 *
 * @param [in] iShareId The image share id.
 *
 * @retval ZOK Reject image share invitation successfully.
 * @retval ZFAILED Reject image share invitation failed.
 */
ZFUNC ZINT Mtc_ImIShareReject(ZUINT iShareId);

/**
 * @brief MTC Cancel a image share.
 * 
 * If IM participant canceled transfer invitation, Remote GUI will be 
 * notified by callback which was set by @ref Mtc_ImCbSetIShareCanceled.
 *
 * @param [in] iShareId The image share id.
 *
 * @retval ZOK Cancel image share invitation successfully.
 * @retval ZFAILED Cancel image share invitation failed.
 */
ZFUNC ZINT Mtc_ImIShareCancel(ZUINT iShareId);

/**
 * @brief MTC Release a image share.
 * 
 * If IM participant released file transfer, Remote GUI will be notified 
 * by callback which was set by @ref Mtc_ImCbSetIShareReleased.
 *
 * @param [in] iShareId The image share id.
 *
 * @retval ZOK Release image share successfully.
 * @retval ZFAILED Release image share failed.
 */
ZFUNC ZINT Mtc_ImIShareRelease(ZUINT iShareId);

/**
 * @brief MTC Get user cookie from a image share.
 *
 * @param [in] iShareId The image share id.
 *
 * @return User cookie.
 */
ZFUNC ZCOOKIE Mtc_ImIShareGetCookie(ZUINT iShareId);

/**
 * @brief MTC Set user cookie in a image share.
 *
 * @param [in] iShareId The image share id.
 * @param [in] zCookie The user cookie.
 *
 * @retval ZOK Set user cookie successfully.
 * @retval ZFAILED Set user cookie failed.
 */
ZFUNC ZINT Mtc_ImIShareSetCookie(ZUINT iShareId, ZCOOKIE zCookie);

/**
 * @brief MTC Get image name from image share.
 *
 * @param [in] iShareId The image share id.
 *
 * @return The file name.
 */
ZFUNC ZCHAR * Mtc_ImIShareGetName(ZUINT iShareId);

/**
 * @brief MTC Get image type from image share.
 *
 * @param [in] iShareId The image share id.
 *
 * @return The image file type, see @ref EN_MTC_IM_ISHARE_CONT_TYPE.
 */
ZFUNC ZUINT Mtc_ImIShareGetType(ZUINT iShareId);

/**
 * @brief MTC Get image size from image share.
 *
 * @param [in] iShareId The image share id.
 *
 * @return The image file size.
 */
ZFUNC ZUINT Mtc_ImIShareGetSize(ZUINT iShareId);

/**
 * @brief MTC Get image data sent size from image share.
 *
 * @param [in] iShareId The image share id.
 *
 * @return The image file data sent size.
 */
ZFUNC ZUINT Mtc_ImIShareGetSentSize(ZUINT iShareId);

/**
 * @brief MTC Get image data received size from image share.
 *
 * @param [in] iShareId The image share id.
 *
 * @return The image file data received size.
 */
ZFUNC ZUINT Mtc_ImIShareGetRecvSize(ZUINT iShareId);

/**
 * @brief MTC Get participant type from image share.
 *
 * @param [in] iShareId The image share id.
 *
 * @return Type of IM image share participant, see @ref EN_MTC_PARTP_LST_TYPE.
 * If type is EN_MTC_PARTP_LST_ONE, participant can be got by @ref Mtc_ImIShareGetPartp.
 * If type is EN_MTC_PARTP_LST_PREDEF_GRP, participant can be got by @ref Mtc_ImIShareGetPartp.
 * If type is EN_MTC_PARTP_LST_URI_LST, participant can be got by @ref Mtc_ImIShareGetPartpLstId.
 */
ZFUNC ZUINT Mtc_ImIShareGetPartpType(ZUINT iShareId);

/**
 * @brief MTC Get participant information from image share.
 *
 * The participant is the remote client who shared image.
 *
 * @param [in] iShareId The image share id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImIShareGetPartp(ZUINT iShareId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief MTC Get participant list id from image share.
 *
 * The participant list id is all remote clients who shared image.
 *
 * @param [in] iShareId The image share id.
 *
 * @return The participant list id on succeed or 0 on failed.
 *  The caller is responsible for freeing it by @ref Mtc_PartpLstDelete.
 */
ZFUNC ZUINT Mtc_ImIShareGetPartpLstId(ZUINT iShareId);

/**
 * @brief MTC Get original participant URI from image share.
 *
 * The participant is the session initiator who initialized this shared image.
 * It will return local URI if local client is the image share initiator.
 * It will return From uri from image share invitation information.
 *
 * @param [in] iShareId The image share id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImIShareGetOrigPartp(ZUINT iShareId, 
                ZCHAR **ppcName, ZCHAR **ppcUri);

/**
 * @brief MTC Get original identity of participant URI from image share.
 *
 * The participant is the image share initiator who initialized image share.
 * It will return local URI if local client is the image share initiator.
 * It will return identity uri if image share invitation has P-Asserted-Identity information.
 *
 * @param [in] iShareId The image share id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original identity of participant successfully.
 * @retval ZFAILED Get original identity of participant failed.
 */
ZFUNC ZINT Mtc_ImIShareGetOrigIdPartp(ZUINT iShareId, 
                ZCHAR **ppcName, ZCHAR **ppcUri);

/**
 * @brief MTC Get date time from image share.
 *
 * @param [in] iShareId The image share id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time date failed.
 */
ZFUNC ZINT Mtc_ImIShareGetSysDateTime(ZUINT iShareId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from image share.
 *
 * @param [in] iShareId The image share id.
 *
 * @return image share date time, otherwise return 0.
 */
ZFUNC ZTIME_T Mtc_ImIShareGetDateTime(ZUINT iShareId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_ISHARE_H__ */

