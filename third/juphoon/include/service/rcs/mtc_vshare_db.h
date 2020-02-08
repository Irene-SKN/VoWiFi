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
  File name     : mtc_vshare_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2010-02-06
  Description   :
      Data structure and function declare required by mtc call database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_VSHARE_DB_H__
#define _MTC_VSHARE_DB_H__

/**
 * @file mtc_vshare_db.h
 * @brief MTC Video Share Database Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get video codec count.
 *
 * @return Video used codec count.
 */
ZFUNC ZUINT Mtc_VShareDbGetVideoCodecCount(ZFUNC_VOID);

/**
 * @brief Get video codec from database.
 *
 * @param [in] ucPriority Codec priority.
 *
 * @return The string of Codec name successfully or empty string failed.
 *
 * @see @ref Mtc_VShareDbSetVideoCodecByPriority
 */
ZFUNC ZCHAR * Mtc_VShareDbGetVideoCodecByPriority(ZUCHAR ucPriority);

/**
 * @brief Set the video codec priority.
 *
 * @param [in] pcCodec Codec name.
 * @param [in] ucPriority Codec priority.
 *
 * @retval ZOK Set the video codec priority successfully.
 * @retval ZFAILED Set the video codec priority failed.
 *
 * @see @ref Mtc_VShareDbGetVideoCodecByPriority
 */
ZFUNC ZINT Mtc_VShareDbSetVideoCodecByPriority(ZCHAR *pcCodec,
                ZUCHAR ucPriority);

/**
 * @brief Get video bitrate.
 *
 * @retval Video bitrate parameter in bps.
 *
 * @see @ref Mtc_VShareDbSetVideoBitrate
 */
ZFUNC ZUINT Mtc_VShareDbGetVideoBitrate();

/**
 * @brief Set video bitrate.
 *
 * @param [in] iBitRate Video bitrate parameter in bps.
 *
 * @retval ZOK Set the video bitrate successfully.
 * @retval ZFAILED Set the video bitrate failed.
 *
 * @see @ref Mtc_VShareDbGetVideoBitrate
 */
ZFUNC ZINT Mtc_VShareDbSetVideoBitrate(ZUINT iBitRate);

/**
 * @brief Get video frame rate.
 *
 * @retval Video frame rate parameter in fps.
 *
 * @see @ref Mtc_VShareDbSetVideoFramerate
 */
ZFUNC ZUINT Mtc_VShareDbGetVideoFramerate();

/**
 * @brief Set video frame rate.
 *
 * @param [in] iFrameRate Video frame rate parameter in fps.
 *
 * @retval ZOK Set the video frame rate successfully.
 * @retval ZFAILED Set the video frame rate failed.
 *
 * @see @ref Mtc_VShareDbGetVideoFramerate
 */
ZFUNC ZINT Mtc_VShareDbSetVideoFramerate(ZUINT iFrameRate);

/**
 * @brief Get video resolution.
 *
 * @param [out] piWidth Pixel value in horizontal direction.
 * @param [out] piHeight Pixel value in vertical direction.
 *
 * @retval ZOK Get the video resolution successfully.
 * @retval ZFAILED Get the video resolution failed.
 *
 * @see @ref Mtc_VShareDbSetVideoResolution
 */
ZFUNC ZINT Mtc_VShareDbGetVideoResolution(ZUINT *piWidth, 
                ZUINT *piHeight);

/**
 * @brief Set video resolution.
 *
 * @param [in] iWidth Pixel value in horizontal direction.
 * @param [in] iHeight Pixel value in vertical direction.
 *
 * @retval ZOK Set the video resolution successfully.
 * @retval ZFAILED Set the video resolution failed.
 *
 * @see @ref Mtc_VShareDbGetVideoResolution
 */
ZFUNC ZINT Mtc_VShareDbSetVideoResolution(ZUINT iWidth, 
                ZUINT iHeight);

/**
 * @brief Get video resolution.
 *
 * @return The string of video resolution name or "UNKNOWN" failed.
 *
 * @see @ref Mtc_VShareDbSetVideoResolutionX
 */
ZFUNC ZCHAR * Mtc_VShareDbGetVideoResolutionX();

/**
 * @brief Set video resolution.
 *
 * @param [in] pcName Video resolution name string.
 *
 * @retval ZOK Set the video resolution successfully.
 * @retval ZFAILED Set the video resolution failed.
 *
 * @see @ref Mtc_VShareDbGetVideoResolutionX
 */
ZFUNC ZINT Mtc_VShareDbSetVideoResolutionX(ZCHAR *pcName);

/**
 * @brief Get resolution control of video stream.
 *
 * @retval ZTRUE Resolution control is enabled for video stream.
 * @retval ZFALSE Resolution control is disabled for video stream.
 *
 * @see @ref Mtc_VShareDbSetResolutionControl
 */
ZFUNC ZBOOL Mtc_VShareDbGetResolutionControl(ZFUNC_VOID);

/**
 * @brief Set resolution control of video stream.
 *
 * @param [in] bEnable ZTRUE to enable resolution control, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_VShareDbGetResolutionControl
 */
ZFUNC ZINT Mtc_VShareDbSetResolutionControl(ZBOOL bEnable);

/**
 * @brief Get framerate control of video stream.
 *
 * @retval ZTRUE Framerate control is enabled for video stream.
 * @retval ZFALSE Framerate control is disabled for video stream.
 *
 * @see @ref Mtc_VShareDbSetFramerateControl
 */
ZFUNC ZBOOL Mtc_VShareDbGetFramerateControl(ZFUNC_VOID);

/**
 * @brief Set framerate control of video stream.
 *
 * @param [in] bEnable ZTRUE to enable framerate control, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_VShareDbGetFramerateControl
 */
ZFUNC ZINT Mtc_VShareDbSetFramerateControl(ZBOOL bEnable);

/**
 * @brief Get CPU load control of video stream.
 *
 * @retval ZTRUE CPU load control is enabled for video stream.
 * @retval ZFALSE CPU load control is disabled for video stream.
 *
 * @see @ref Mtc_VShareDbSetCpuLoadControl
 */
ZFUNC ZBOOL Mtc_VShareDbGetCpuLoadControl(ZFUNC_VOID);

/**
 * @brief Set CPU load control of video stream.
 *
 * @param [in] bEnable ZTRUE to enable CPU load control, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_VShareDbGetCpuLoadControl
 */
ZFUNC ZINT Mtc_VShareDbSetCpuLoadControl(ZBOOL bEnable);

/**
 * @brief Get CPU load control of video stream.
 *
 * @return CPU load control target, from 0 to 100.
 *
 * @see @ref Mtc_VShareDbSetCpuLoadTarget
 */
ZFUNC ZUINT Mtc_VShareDbGetCpuLoadTarget(ZFUNC_VOID);

/**
 * @brief Set CPU load control of video stream.
 *
 * @param [in] iTarget CPU load control target, from 0 to 100.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_VShareDbGetCpuLoadTarget
 */
ZFUNC ZINT Mtc_VShareDbSetCpuLoadTarget(ZUINT iTarget);

/**
 * @brief Get FIR of video stream.
 *
 * @retval ZTRUE FIR is enabled for video stream.
 * @retval ZFALSE FIR is disabled for video stream.
 *
 * @see @ref Mtc_VShareDbSetFir
 */
ZFUNC ZBOOL Mtc_VShareDbGetFir(ZFUNC_VOID);

/**
 * @brief Set FIR of video stream.
 *
 * @param [in] bEnable ZTRUE to enable FIR, otherwise to disable.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_VShareDbGetFir
 */
ZFUNC ZINT Mtc_VShareDbSetFir(ZBOOL bEnable);

/**
 * @brief Get key frame period of video stream.
 *
 * @return Key frame period in milliseconds for video stream.
 *
 * @see @ref Mtc_VShareDbSetFramerateControl
 */
ZFUNC ZUINT Mtc_VShareDbGetKeyPeriod(ZFUNC_VOID);

/**
 * @brief Set framerate control of video stream.
 *
 * @param [in] iTimeLen Key frame period in milliseconds.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_VShareDbGetKeyPeriod
 */
ZFUNC ZINT Mtc_VShareDbSetKeyPeriod(ZUINT iTimeLen);

/**
 * @brief Get bw efficiency mode of video stream.
 *
 * @retval ZTRUE BEM is enabled for video stream.
 * @retval ZFALSE BEM is disabled for video stream.
 *
 * @see @ref Mtc_VShareDbSetVideoBem
 */
ZFUNC ZBOOL Mtc_VShareDbGetVideoBem(ZFUNC_VOID);

/**
 * @brief Set bw efficiency mode of video stream.
 *
 * @param [in] bEnable ZTRUE to enable BEM, otherwise to disable BEM.
 *
 * @retval ZOK Set the video BEM option successfully.
 * @retval ZFAILED Set the video BEM option failed.
 *
 * @see @ref Mtc_VShareDbGetVideoBem
 */
ZFUNC ZINT Mtc_VShareDbSetVideoBem(ZBOOL bEnable);

/**
 * @brief Get ARS option of video stream.
 *
 * @retval ZTRUE ARS is enabled for video stream.
 * @retval ZFALSE ARS is disabled for video stream.
 *
 * @see @ref Mtc_VShareDbSetVideoArs
 */
ZFUNC ZBOOL Mtc_VShareDbGetVideoArs(ZFUNC_VOID);

/**
 * @brief Set ARS option of video stream.
 *
 * @param [in] bEnable ZTRUE to enable ARS, otherwise to disable ARS.
 *
 * @retval ZOK Set the video ARS option successfully.
 * @retval ZFAILED Set the video ARS option failed.
 *
 * @see @ref Mtc_VShareDbGetVideoArs
 */
ZFUNC ZINT Mtc_VShareDbSetVideoArs(ZBOOL bEnable);

/**
 * @brief Get ARS parameter from database.
 *
 * @param [out] piBrHi Highest bitrate.
 * @param [out] piBrLo Lowest bitrate.
 * @param [out] piFrHi Highest framerate.
 * @param [out] piFrLo Lowest framerate.

 * @retval ZOK Get successfully.
 * @retval ZFAILED Get failed.
 *
 * @see @ref Mtc_VShareDbSetVideoArsParm
 */
ZFUNC ZINT Mtc_VShareDbGetVideoArsParm(ZUINT * piBrHi, ZUINT * piBrLo,
                ZUINT * piFrHi, ZUINT * piFrLo);

/**
 * @brief Set ARS parameter.
 *
 * @param [in] iBrHi Highest bitrate.
 * @param [in] iBrLo Lowest bitrate.
 * @param [in] iFrHi Highest framerate.
 * @param [in] iFrLo Lowest framerate.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_VShareDbGetVideoArsParm
 */
ZFUNC ZINT Mtc_VShareDbSetVideoArsParm(ZUINT iBrHi, ZUINT iBrLo,
                ZUINT iFrHi, ZUINT iFrLo);

/**
 * @brief Set option of red/fec.
 *
 * @param [in] bEnable ZTRUE to enable red/fec, otherwise to disable red/fec.
 *
 * @retval ZOK Set successfully.
 * @retval ZFAILED Set failed.
 *
 * @see @ref Mtc_VShareDbGetVideoRedFec
 */
ZFUNC ZINT Mtc_VShareDbSetVideoRedFec(ZBOOL bEnable);

/**
 * @brief Get option of red/fec.
 *
 * @retval ZTRUE ARS is enabled red/fec.
 * @retval ZFALSE ARS is disabled red/fec.
 *
 * @see @ref Mtc_VShareDbSetVideoRedFec
 */
ZFUNC ZBOOL Mtc_VShareDbGetVideoRedFec();  

/**
 * @brief Get NACK option from database.
 *
 * @retval ZTRUE Start NACK.
 * @retval ZFALSE Do not start NACK.
 *
 * @see @ref Mtc_VShareDbSetNackEnable
 */
ZFUNC ZBOOL Mtc_VShareDbGetNackEnable(ZFUNC_VOID);

/**
 * @brief Set NACK option.
 *
 * @param [in] bEnable NACK option.
 *
 * @retval ZOK Set NACK option successfully.
 * @retval ZFAILED Set NACK option failed.
 *
 * @see @ref Mtc_VShareDbGetNackEnable
 */
ZFUNC ZINT Mtc_VShareDbSetNackEnable(ZBOOL bEnable);

/**
 * @brief Get TMMBR option from database.
 *
 * @retval ZTRUE Start TMMBR.
 * @retval ZFALSE Do not start TMMBR.
 *
 * @see @ref Mtc_VShareDbSetTmmbrEnable
 */
ZFUNC ZBOOL Mtc_VShareDbGetTmmbrEnable(ZFUNC_VOID);

/**
 * @brief Set TMMBR option.
 *
 * @param [in] bEnable TMMBR option.
 *
 * @retval ZOK Set TMMBR option successfully.
 * @retval ZFAILED Set TMMBR option failed.
 *
 * @see @ref Mtc_VShareDbGetTmmbrEnable
 */
ZFUNC ZINT Mtc_VShareDbSetTmmbrEnable(ZBOOL bEnable);

/**
 * @brief Get RPSI option from database.
 *
 * @retval ZTRUE Start RPSI.
 * @retval ZFALSE Do not start RPSI.
 *
 * @see @ref Mtc_VShareDbSetRpsiEnable
 */
ZFUNC ZBOOL Mtc_VShareDbGetRpsiEnable(ZFUNC_VOID);

/**
 * @brief Set RPSI option.
 *
 * @param [in] bEnable RPSI option.
 *
 * @retval ZOK Set RPSI option successfully.
 * @retval ZFAILED Set RPSI option failed.
 *
 * @see @ref Mtc_VShareDbGetRpsiEnable
 */
ZFUNC ZINT Mtc_VShareDbSetRpsiEnable(ZBOOL bEnable);

/**
 * @brief Get small NALU option from database.
 *
 * @retval ZTRUE Enable small NALU.
 * @retval ZFALSE Disable small NALU.
 *
 * @see @ref Mtc_VShareDbSetSmallNaluEnable
 */
ZFUNC ZBOOL Mtc_VShareDbGetSmallNaluEnable(ZFUNC_VOID);

/**
 * @brief Set small NALU option.
 *
 * @param [in] bEnable Small NALU option.
 *
 * @retval ZOK Set small NALU option successfully.
 * @retval ZFAILED Set small NALU option failed.
 *
 * @see @ref Mtc_VShareDbGetSmallNaluEnable
 */
ZFUNC ZINT Mtc_VShareDbSetSmallNaluEnable(ZBOOL bEnable);

/**
 * @brief Get the authorization for user to use Video Share service.
 *
 * @retval ZTRUE Indicates that Video Share service is disabled.
 * @retval ZFALSE Indicates that Video Share service is disabled.
 *
 * @see @ref Mtc_VShareDbSetVsAuth
 */
ZFUNC ZBOOL Mtc_VShareDbGetVsAuth(ZFUNC_VOID);

/**
 * @brief Get whether or not the SDP attribute and value (e.g. a=recordpref:nopreference) 
 *   is included in the Video Share invitation.
 *
 * @retval -1 Indicates inclusion of the attribute and value is up to the user's preference.
 * @retval 0 Indicates the attribute is never included (default value).
 * @retval 1 Indicates the attribute is always included .
 *
 * @see @ref Mtc_VShareDbSetAllowVsSave
 */
ZFUNC ZINT Mtc_VShareDbGetAllowVsSave(ZFUNC_VOID);

/**
 * @brief Get the maximum authorized duration time for a Video Share session.
 *
 * @return timer value in seconds, value equals to 0 means no limitation.
 */
ZFUNC ZUINT Mtc_VShareDbGetMaxTimeVideoShare(ZFUNC_VOID);

/**
 * @brief Set the authorization for user to use Video Share service.
 *
 * @param [in] bVsAuth Video Share service enable flag;
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_VShareDbGetVsAuth
 */
ZFUNC ZINT Mtc_VShareDbSetVsAuth(ZBOOL bVsAuth);

/**
 * @brief Set whether or not the SDP attribute and value (e.g. a=recordpref:nopreference) 
 *   is included in the Video Share invitation.
 *
 * @param [in] iAllowVsSave The allow type.
 *
 * @retval ZOK Set allow type successfully.
 * @retval ZFAILED Set allow type failed.
 *
 * @see @ref Mtc_VShareDbGetAllowVsSave
 */
ZFUNC ZINT Mtc_VShareDbSetAllowVsSave(ZINT iAllowVsSave);

/**
 * @brief Get parameter for coordination of video orientation.
 *
 * @param [out] pbSend ZTRUE: CVO for sending is enabled.
 * @param [out] pbRecv ZTRUE: CVO for receiving is enabled.
 * @param [out] piId RTP extension ID for CVO.
 *
 * @retval ZOK Get option successfully.
 * @retval ZFAILED Get option failed.
 *
 * @see @ref Mtc_VShareDbSetVideoOrientParm
 */
ZFUNC ZINT Mtc_VShareDbGetVideoOrientParm(ZBOOL *pbSend, ZBOOL *pbRecv,
                ZUINT *piId);

/**
 * @brief Set parameter for coordination of video orientation.
 *
 * @param [in] bSend ZTRUE to enable CVO for sending.
 * @param [in] bRecv ZTRUE to enable CVO for receiving.
 * @param [in] iId RTP extension ID for CVO.
 *
 * @retval ZOK Set option successfully.
 * @retval ZFAILED Set option failed.
 *
 * @see @ref Mtc_VShareDbGetVideoOrientParm
 */
ZFUNC ZINT Mtc_VShareDbSetVideoOrientParm(ZBOOL bSend, ZBOOL bRecv,
                ZUINT iId);

#define SRTP_SETTINGS

/**
 * @brief Get SRTP crypto type from database.
 *
 * @return SRTP crypto type, @ref EN_MTC_DB_SRTP_CRYPTO_TYPE.
 *
 * @see Mtc_VShareDbSetSrtpCryptoType
 */
ZFUNC ZUINT Mtc_VShareDbGetSrtpCryptoType(ZFUNC_VOID);

/**
 * @brief Set SRTP crypto type.
 *
 * @param [in] iType SRTP crypto type, @ref EN_MTC_DB_SRTP_CRYPTO_TYPE.
 *
 * @retval ZOK Set SRTP crypto type successfully.
 * @retval ZFAILED Set SRTP crypto type failed.
 *
 * @see Mtc_VShareDbGetSrtpCryptoType
 */
ZFUNC ZINT Mtc_VShareDbSetSrtpCryptoType(ZUINT iType);

/**
 * @brief Get authenticated SRTP option from database.
 *
 * @retval ZTRUE Enable authenticated SRTP.
 * @retval ZFALSE Disable authenticated SRTP.
 *
 * @see @ref Mtc_VShareDbSetSrtpAuthRtp
 */
ZFUNC ZBOOL Mtc_VShareDbGetSrtpAuthRtp(ZFUNC_VOID);

/**
 * @brief Set authenticated SRTP option.
 *
 * @param [in] bEnable ZTRUE to enable authenticated SRTP, ZFALSE to disable.
 *
 * @retval ZOK Set authenticated SRTP option successfully.
 * @retval ZFAILED Set authenticated SRTP option failed.
 *
 * @see @ref Mtc_VShareDbGetSrtpAuthRtp
 */
ZFUNC ZINT Mtc_VShareDbSetSrtpAuthRtp(ZBOOL bEnable);

/**
 * @brief Get encrypted SRTP option from database.
 *
 * @retval ZTRUE Enable encrypted SRTP.
 * @retval ZFALSE Disable encrypted SRTP.
 *
 * @see @ref Mtc_VShareDbSetSrtpEncryptRtp
 */
ZFUNC ZBOOL Mtc_VShareDbGetSrtpEncryptRtp(ZFUNC_VOID);

/**
 * @brief Set encrypted SRTP option.
 *
 * @param [in] bEnable ZTRUE to enable encrypted SRTP, ZFALSE to disable.
 *
 * @retval ZOK Set encrypted SRTP option successfully.
 * @retval ZFAILED Set encrypted SRTP option failed.
 *
 * @see @ref Mtc_VShareDbGetSrtpEncryptRtp
 */
ZFUNC ZINT Mtc_VShareDbSetSrtpEncryptRtp(ZBOOL bEnable);

/**
 * @brief Get encrypted SRTCP option from database.
 *
 * @retval ZTRUE Enable encrypted SRTCP.
 * @retval ZFALSE Disable encrypted SRTCP.
 *
 * @see @ref Mtc_VShareDbSetSrtpEncryptRtcp
 */
ZFUNC ZBOOL Mtc_VShareDbGetSrtpEncryptRtcp(ZFUNC_VOID);

/**
 * @brief Set encrypted SRTCP option.
 *
 * @param [in] bEnable ZTRUE to enable encrypted SRTCP, ZFALSE to disable.
 *
 * @retval ZOK Set encrypted SRTCP option successfully.
 * @retval ZFAILED Set encrypted SRTCP option failed.
 *
 * @see @ref Mtc_VShareDbGetSrtpEncryptRtcp
 */
ZFUNC ZINT Mtc_VShareDbSetSrtpEncryptRtcp(ZBOOL bEnable);

#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_VSHARE_DB_H__ */

