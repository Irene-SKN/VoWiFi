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
  File name     : mtc_conf_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2010-02-06
  Description   :
      Data structure and function declare required by MTC conference database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CONF_DB_H__
#define _MTC_CONF_DB_H__

/**
 * @file mtc_conf_db.h
 * @brief MTC Conference Database Interface Functions.
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/* mtc conf resolution ratio type */
typedef enum EN_MTC_CONF_DB_RES_RATIO_TYPE
{
    EN_MTC_CONF_DB_RES_RATIO_DEFAULT,        /* use default resolution ratio */
    EN_MTC_CONF_DB_RES_RATIO_288P,           /* use 352X288 resolution ratio */
    EN_MTC_CONF_DB_RES_RATIO_480P,           /* use 640X480 resolution ratio */
    EN_MTC_CONF_DB_RES_RATIO_720P,           /* use 1280X720 resolution ratio */
    EN_MTC_CONF_DB_RES_RATIO_1080P           /* use 1920X1080 resolution ratio */
} EN_MTC_CONF_DB_RES_RATIO_TYPE;

/**
 * @brief Get conference factory URI.
 *
 * @return The string of conference factory URI.
 *
 * @see @ref Mtc_ConfDbSetFactUri
 */
ZFUNC ZCHAR * Mtc_ConfDbGetFactUri(ZFUNC_VOID);

/**
 * @brief Set conference factory URI.
 *
 * @param [in] pcUri Conference factory URI.
 *
 * @retval ZOK Set conference factory URI successfully.
 * @retval ZFAILED Set conference factory URI failed.
 *
 * @see @ref Mtc_ConfDbGetFactUri
 */
ZFUNC ZINT Mtc_ConfDbSetFactUri(ZCHAR *pcUri);

/**
 * @brief Get video conference factory URI.
 *
 * @return The string of video conference factory URI.
 *
 * @see @ref Mtc_ConfDbSetVideoFactUri
 */
ZFUNC ZCHAR * Mtc_ConfDbGetVideoFactUri(ZFUNC_VOID);

/**
 * @brief Set video conference factory URI.
 *
 * @param [in] pcUri Video Conference factory URI.
 *
 * @retval ZOK Set video conference factory URI successfully.
 * @retval ZFAILED Set video conference factory URI failed.
 *
 * @see @ref Mtc_ConfDbGetVideoFactUri
 */
ZFUNC ZINT Mtc_ConfDbSetVideoFactUri(ZCHAR *pcUri);

/**
 * @brief Get conference control URI.
 *
 * @return The string of conference control URI.
 *
 * @see @ref Mtc_ConfDbSetConfControlUri
 */
ZFUNC ZCHAR * Mtc_ConfDbGetConfControlUri(ZFUNC_VOID);

/**
 * @brief Set conference control URI.
 *
 * @param [in] pcUri Conference control URI.
 *
 * @retval ZOK Set conference control URI successfully.
 * @retval ZFAILED Set conference control URI failed.
 *
 * @see @ref Mtc_ConfDbGetConfControlUri
 */
ZFUNC ZINT Mtc_ConfDbSetConfControlUri(ZCHAR *pcUri);

/**
 * @brief Get conference APP ID.
 *
 * @return The string of conference  APP ID.
 *
 * @see @ref Mtc_ConfDbSetConfAppId
 */
ZFUNC ZCHAR * Mtc_ConfDbGetConfAppId();

/**
 * @brief Set conference  APP ID.
 *
 * @param [in] pcUri Conference  APP ID(set app id  for multi-stream,
 * 47 for testing environment, 34 for business environment).
 * As for CS conference,  app id is 203 for testing environment, 
 * 121 for business environment.
 *
 * @retval ZOK Set conference  APP ID successfully.
 * @retval ZFAILED Set conference  APP ID failed.
 *
 * @see @ref Mtc_ConfDbGetConfAppId
 */
ZFUNC ZINT Mtc_ConfDbSetConfAppId(ZCHAR *pcAppId);

/**
 * @brief Get conference APP password.
 *
 * @return The string of conference  APP password.
 *
 * @see @ref Mtc_ConfDbSetConfPwd
 */
ZFUNC ZCHAR * Mtc_ConfDbGetConfPwd();

/**
 * @brief Set conference  APP password.
 *
 * @param [in] pcUri Conference  APP password.
 *
 * @retval ZOK Set conference  APP password successfully.
 * @retval ZFAILED Set conference  APP password failed.
 *
 * @see @ref Mtc_ConfDbGetConfPwd
 */
ZFUNC ZINT Mtc_ConfDbSetConfPwd(ZCHAR *pcPwd);

/**
 * @brief Set conference mcu prefix.
 *
 * @param [in] pcMcuPrefix Conference mcu prefix.
 *
 * @retval ZOK Set conference mcu prefix successfully.
 * @retval ZFAILED Set conference mcu prefix failed.
 *
 * @see @ref Mtc_ConfGetMcuPrefix
 */
ZFUNC ZINT Mtc_ConfSetMcuPrefix(ZCHAR *pcMcuPrefix);
 
 /**
 * @brief Get conference mcu prefix.
 *
 * @return The conference mcu prefix.
 *
 * @see @ref Mtc_ConfSetMcuPrefix
 */
ZFUNC ZCHAR * Mtc_ConfGetMcuPrefix(ZFUNC_VOID);

 /**
 * @brief Get http conference video switch mode.
 *
 * @return The video switch mode of http conference.
 *
 * @see @ref Mtc_ConfDbSetVideoSwitchMode
 */
ZFUNC ZUINT Mtc_ConfDbGetVideoSwitchMode(ZFUNC_VOID);

/**
 * @brief Set http conference video switch mode.
 *
 * @param [in] iMode video switch mode @ref EN_MTC_CONF_VIDEO_SWITCH_MODE.
 *
 * @retval ZOK Set conference video switch mode successfully.
 * @retval ZFAILED Set conference video switch mode failed.
 *
 * @see @ref Mtc_ConfDbGetVideoSwitchMode
 */
ZFUNC ZINT Mtc_ConfDbSetVideoSwitchMode(ZUINT iMode);

/**
 * @brief Get http conf token.
 *
 * @retval ZCHAR * the http conf token.
 *
 * @see @ref Mtc_ConfDbSetHttpConfToken
 */
ZFUNC ZCHAR * Mtc_ConfDbGetHttpConfToken();

/**
 * @brief Set http conf token.
 *
 * @retval ZOK Set the http conf token successfully.
 * @retval ZFAILED Set the http conf token failed.
 *
 * @see @ref Mtc_ConfDbGetHttpConfToken
 */
ZFUNC ZINT Mtc_ConfDbSetHttpConfToken(ZCHAR *pcToken);

 /**
 * @brief Get use https conf enable.
 *
 * @return The https conference enable flag.
 *
 * @see @ref Mtc_ConfDbSetConfHttpsEnable
 */
ZFUNC ZBOOL Mtc_ConfDbGetConfHttpsEnable(ZFUNC_VOID);

/**
 * @brief Set use https conf enable.
 *
 * @param [in] bEnable enable https conference.
 *
 * @retval ZOK Set enable https conference successfully.
 * @retval ZFAILED Set enable https conference failed.
 *
 * @see @ref Mtc_ConfDbGetConfHttpsEnable
 */
ZFUNC ZINT Mtc_ConfDbSetConfHttpsEnable(ZBOOL bEnable);

/**
* @brief Get  http conf video max partp count.
*
* @return The video max participants count(default 5) of http conference.
*
* @see @ref Mtc_ConfDbSetMaxPartpCount
*/
ZFUNC ZUINT Mtc_ConfDbGetMaxPartpCount(ZFUNC_VOID);

/**
 * @brief Set http conference video participants count.
 *
 * @param [in] iCount(default 5) video max participant count(0 or not set for server's max value
 *                 (at present server supports 9 participants including chairman).
 *
 * @retval ZOK Set conference video max participants count successfully.
 * @retval ZFAILED Set conference video max participants count  failed.
 *
 * @see @ref Mtc_ConfDbGetMaxPartpCount
 */
ZFUNC ZINT Mtc_ConfDbSetMaxPartpCount(ZUINT iCount);

/**
* @brief Get  http conf video max remote image count.
*
* @return The video max remote image count(default 4) of http conference.
*
* @see @ref Mtc_ConfDbSetMaxImageCount
*/
ZFUNC ZUINT Mtc_ConfDbGetMaxImageCount(ZFUNC_VOID);

/**
 * @brief Set http conference video remote image count.
 *
 * @param [in] iCount(default 4) video max remote image count(0 or not set for server's max value
 *                 (at present server supports 9 participants including chairman, which means  
 *                  server supports 8 remote images).
 *
 * @retval ZOK Set conference video max remote image count successfully.
 * @retval ZFAILED Set conference video max remote image count  failed.
 *
 * @see @ref Mtc_ConfDbGetMaxImageCount
 */
ZFUNC ZINT Mtc_ConfDbSetMaxImageCount(ZUINT iCount);

/**
 * @brief Set http conf video conference enable record audio flag.
 *
 * @param [in] bEnable enable video conference record audio.
 *
 * @retval ZOK Set enable video conference record audio successfully.
 * @retval ZFAILED Set enable video conference record audio failed.
 *
 * @see @ref Mtc_ConfDbGetAudioRecEnable
 */
ZFUNC ZINT Mtc_ConfDbSetAudioRecEnable(ZBOOL bEnable);

/**
* @brief Get http conf video conference enable record audio flag.
*
* @return The video http conference enable record audio flag.
*
* @see @ref Mtc_ConfDbSetAudioRecEnable
*/
ZFUNC ZBOOL Mtc_ConfDbGetAudioRecEnable(ZFUNC_VOID);

/**
* @brief Get conference subscribe enable flag.
*
* @return The conference subscribe enable flag.
*
* @see @ref Mtc_ConfDbSetConfSubsEnable
*/
ZFUNC ZBOOL Mtc_ConfDbGetConfSubsEnable(ZFUNC_VOID);

/**
 * @brief Set conference subscribe enable flag.
 *
 * @param [in] bEnable enable conference subscribe enable.
 *
 * @retval ZOK Set enable conference subscribe successfully.
 * @retval ZFAILED Set enable conference subscribe failed.
 *
 * @see @ref Mtc_ConfDbGetConfSubsEnable
 */
ZFUNC ZINT Mtc_ConfDbSetConfSubsEnable(ZBOOL bEnable);

/**
 * @brief Set MCU conference enablee flag.
 *
 * @param [in] bEnable enable MCU conference.
 *
 * @retval ZOK Set enable MCU conference successfully.
 * @retval ZFAILED Set enable MCU conference failed.
 *
 * @see @ref Mtc_ConfDbGetMcuConfEnable
 */
ZFUNC ZINT Mtc_ConfDbSetMcuConfEnable(ZBOOL bEnable);

/**
* @brief Get MCU conference enable flag.
*
* @return The MCU conference  enable flag.
*
* @see @ref Mtc_ConfDbSetMcuConfEnable
*/
ZFUNC ZBOOL Mtc_ConfDbGetMcuConfEnable();

/**
 * @brief Set resolution ratio type.
 *
 * @param [in] iType the type of resolution ratio.
 *
 * @retval ZOK Set resolution ratio type successfully.
 * @retval ZFAILED Set resolution ratio type failed.
 *
 * @see @ref Mtc_ConfDbSetResRatioType
 */
ZFUNC ZINT Mtc_ConfDbSetResRatioType(ZUINT iType);

/**
 * @brief Get resolution ratio type.
 *
 * @retval the conf video resolution ratio type.
 *
 * @see @ref Mtc_ConfDbGetResRatioType
 */
ZFUNC ZUINT Mtc_ConfDbGetResRatioType();

/**
 * @brief Set resolution ratio type.
 *
 * @param [in] iType the type of resolution ratio.
 *
 * @retval ZOK Set resolution ratio type successfully.
 * @retval ZFAILED Set resolution ratio type failed.
 *
 * @see @ref Mtc_McuConfDbSetResRatioType
 */
ZFUNC ZINT Mtc_McuConfDbSetResRatioType(ZUINT iType);

/**
 * @brief Get resolution ratio type.
 *
 * @retval the mcu conf video resolution ratio type.
 *
 * @see @ref Mtc_McuConfDbGetResRatioType
 */
ZFUNC ZUINT Mtc_McuConfDbGetResRatioType();

/**
 * @brief Set auto start http query enable flag in muti-conference.
 *
 * @param [in] bEnable enable auto start http query.
 *
 * @retval ZOK Set enable auto start http query successfully.
 * @retval ZFAILED Set auto start http query failed.
 *
 * @see @ref Mtc_ConfDbSetAutoHttpQry
 */
ZFUNC ZUINT Mtc_ConfDbSetAutoHttpQry(ZBOOL bEnable);

/**
* @brief Get auto start http query enable flag in muti-conference.
*
* @return The auto start http query enable flag.
*
* @see @ref Mtc_ConfDbGetAutoHttpQry
*/
ZFUNC ZBOOL Mtc_ConfDbGetAutoHttpQry();

#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_CONF_DB_H__ */

