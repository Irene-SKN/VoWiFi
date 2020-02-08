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
  File name     : mtc_media.h
  Module        : multimedia talk client
  Author        : tanek.ye
  Created on    : 2011-05-06
  Description   :
    Marcos and structure definitions required by the mtc media.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_MEDIA_H__
#define _MTC_MEDIA_H__

/**
 * @file mtc_media.h
 * @brief MTC Media Interface Functions
 */

/** @brief Type of MTC media file type. */
typedef enum EN_MTC_MFILE_TYPE
{
    EN_MTC_MFILE_UNKNOW,              /**< @brief Unknow file type. */
    EN_MTC_MFILE_PCM,                 /**< @brief PCM file. */
    EN_MTC_MFILE_WAV,                 /**< @brief WAV file. */
    EN_MTC_MFILE_WAV_PCM,             /**< @brief WAV file with codec of PCM. */
    EN_MTC_MFILE_WAV_PCMU,            /**< @brief WAV file with codec of PCMU. */
    EN_MTC_MFILE_WAV_PCM_32K,         /**< @brief WAV file with codec of L16-32kHz*/    
    EN_MTC_MFILE_WAV_PCMA,            /**< @brief WAV file with codec of PCMA. */
    EN_MTC_MFILE_ILBC,                /**< @brief WAV file with codec of iLBC. */
    EN_MTC_MFILE_AMR,                 /**< @brief WAV file with codec of AMR. */
    EN_MTC_MFILE_AVI,                 /**< @brief AVI file. */
    EN_MTC_MFILE_AVI_VP8,             /**< @brief AVI file with codec of VP8. */
    EN_MTC_MFILE_AVI_I420,            /**< @brief AVI file with codec of I420. */
    EN_MTC_MFILE_AVI_H264,            /**< @brief AVI file with codec of H264. */
    EN_MTC_MFILE_MP4_H264,            /**< @brief MP4 file with codec of H264. */
} EN_MTC_MFILE_TYPE;

/** @brief Type of MTC adaptive negotiation bitrate mode type. */
typedef enum EN_MTC_AN_MODE
{
    EN_MTC_AN_UNKNOW,                /**< @brief Invalid mode type. */
    EN_MTC_AN_LOW,                   /**< @brief Low bitrate mode. */ 
    EN_MTC_AN_MID,                   /**< @brief Middle bitrate mode. */ 
    EN_MTC_AN_HIGH,                  /**< @brief High bitrate mode. */ 
} EN_MTC_AN_MODE;

/** @brief Record video quality level */
typedef enum EN_MTC_REC_QUALITY
{
    EN_MTC_REC_QUALITY_LOW,         /**< @brief low record video quality using low bitrate */
    EN_MTC_REC_QUALITY_MID,         /**< @brief middle record video quality using middle bitrate */
    EN_MTC_REC_QUALITY_HIGH         /**< @brief high record video quality using high bitrate */
}EN_MTC_REC_QUALITY;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Set an bitrate mode of sending direction
 * @param [in] ucMode @ref EN_MTC_AN_MODE.
 *
 * @retval ZOK on succeed.
 * @retval ZFAILED on failure.
 */
ZFUNC ZINT Mtc_MdmAnSetSendBitrateMode (ZUCHAR ucMode);

/**
 * @brief Set video Adaptive negotiation bitrate mode.
 *
 * @param [in] ucMode Adaptive negotiation bitrate mode @ref EN_MTC_AN_MODE.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see Mtc_MdmAnGetBitrateMode
 */
ZFUNC ZINT Mtc_MdmAnSetBitrateMode(ZUCHAR ucMode);

/**
 * @brief Get adaptive negotiation bitrate mode.
 *
 * @retval return adaptive negotiation bitrate mode, see @ref EN_MTC_AN_MODE.
 *
 */
ZFUNC ZUCHAR Mtc_MdmAnGetBitrateMode(ZFUNC_VOID);

/**
 * @brief Convert wav file to amr file.
 *
 * @param [in] pcInFile Input wav file name.
 * @param [in] pcOutFile Output amr file name.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see
 */
ZFUNC ZINT Mtc_MediaFileWavToAmr(ZCHAR *pcInFile, ZCHAR *pcOutFile);

/**
 * @brief Convert amr file to wav file.
 *
 * @param [in] pcInFile Input amr file name.
 * @param [in] pcOutFile Output wav file name.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 *
 * @see
 */
ZFUNC ZINT Mtc_MediaFileAmrToWav(ZCHAR *pcInFile, ZCHAR *pcOutFile);

#ifdef __cplusplus
}
#endif

#endif

