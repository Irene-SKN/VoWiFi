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
  File name     : mtc_util.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC utility

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_UTIL_H__
#define _MTC_UTIL_H__

/**
 * @file mtc_util.h
 * @brief MTC Utility Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief User defined callback when timer triggers. */
typedef ZVOID (*PFN_ZMTCTMRA)(ZTIMERID zTimerId, ZCOOKIE zCookie);

/** @brief User defined schedule when timer triggers. */
typedef ZVOID (*PFN_ZMTCTMRS)(ZCOOKIE zCookie);

/** @brief MTC app push type */
#define MTC_APP_PUSH_TYPE_SOCIAL_CIRCLE             (1 << 0)      /**< @brief cmcc.social-circle */
#define MTC_APP_PUSH_TYPE_PROFILE                   (1 << 1)      /**< @brief cmcc.Profile */
#define MTC_APP_PUSH_TYPE_NETWORK_ADDR              (1 << 2)      /**< @brief cmcc.Network-address */
#define MTC_APP_PUSH_TYPE_PC                        (1 << 3)      /**< @brief cmcc.pc */
#define MTC_APP_PUSH_TYPE_CMCC_APP                  (1 << 4)      /**< @brief cmcc.rcs-app */
#define MTC_APP_PUSH_TYPE_LOG_NOTIFICATION          (1 << 5)      /**< @brief cmcc.log-notification */
#define MTC_APP_PUSH_TYPE_VIDEOCONF_NOTIFICATION    (1 << 6)      /**< @brief cmcc.videoconference-notification */
#define MTC_APP_PUSH_TYPE_PUBLIC_PLATFORM           (1 << 7)      /**< @brief cmcc.PublicPlatform */
#define MTC_APP_PUSH_TYPE_RCS_OA                    (1 << 8)      /**< @brief cmcc.rcsoa */
#define MTC_APP_PUSH_TYPE_GROUP                     (1 << 9)      /**< @brief cmcc.group */


/** @brief MTC IM  message revoke result type */
typedef enum EN_MTC_REVOKE_RESULT_TYPE
{
    EN_MTC_REVOKE_RESULT_TYPE_NO,            /**< @brief no revoke result */
    EN_MTC_REVOKE_RESULT_TYPE_SUCCESS,  /**< @brief revoke result is success */
    EN_MTC_REVOKE_RESULT_TYPE_FAIL,          /**< @brief revoke result is fail */
} EN_MTC_REVOKE_RESULT_TYPE;

/** @brief Mtc system time. */
typedef struct tagMTC_SYS_TIME
{
    ZUSHORT wYear;                   /**< @brief Year */
    ZUCHAR ucMonth;                  /**< @brief Month 1 - 12 */
    ZUCHAR ucDay;                    /**< @brief Day 1 - 31 */
    ZUCHAR ucWeekDay;                /**< @brief Week day 0 - 6, 0 for Sunday */
    ZUCHAR ucHour;                   /**< @brief Hour 0 - 23 */
    ZUCHAR ucMinute;                 /**< @brief Minute 0 - 59 */
    ZUCHAR ucSecond;                 /**< @brief Second 0 - 59 */
    ZINT iTzOffset;                  /**< @brief Time zone offset in seconds */
} ST_MTC_SYS_TIME;

/**
 * @brief Print ERROR log with format string information.
 * User can specific log name as the log module prefix
 * Log print level can be set by Mtc_CliDbSetLogLevel.
 *
 * @param [in] pcLogName The log name. Default name is "ZOS" if no log name.
 * @param [in] pcFormat String format.
 * @param [in] ... String vars.
 *
 * @see @ref Mtc_AnyLogInfoStr
 */
ZFUNC ZVOID Mtc_AnyLogErrStr(ZCHAR *pcLogName, ZCHAR *pcFormat, ...) ZATTR_PRINTF(2,3);

/**
 * @brief Print INFO log with format string information.
 * User can specific log name as the log module prefix
 * Log print level can be set by Mtc_CliDbSetLogLevel.
 *
 * @param [in] pcLogName The log name. Default name is "ZOS" if no log name.
 * @param [in] pcFormat String format.
 * @param [in] ... String vars.
 *
 * @see @ref Mtc_AnyLogErrStr
 */
ZFUNC ZVOID Mtc_AnyLogInfoStr(ZCHAR *pcLogName, ZCHAR *pcFormat, ...) ZATTR_PRINTF(2,3);

/**
 * @brief Print DEBUG log with format string information.
 * User can specific log name as the log module prefix
 * Log print level can be set by Mtc_DbSetLogLevel.
 *
 * @param [in] pcLogName The log name. Default name is "ZOS" if no log name.
 * @param [in] pcFormat String format.
 * @param [in] ... String vars.
 *
 * @see @ref Mtc_AnyLogInfoStr
 */
ZFUNC ZVOID Mtc_AnyLogDbgStr(ZCHAR *pcLogName, ZCHAR *pcFormat, ...) ZATTR_PRINTF(2,3);

/**
 * @brief This function flushs buffer into log file.
 *
 * @param [in] zLogId The log ID.
 *
 * @retval ZOK Flush operation successfully.
 * @retval ZFAILED Flush operation failed.
 *
 * @see 
 */
ZFUNC ZINT Mtc_AnyLogFlush();

/**
 * @brief Print login ERROR log with format string information.
 * User can specific log name as the log module prefix
 * Log print level can be set by Mtc_CliDbSetLogLevel.
 *
 * @param [in] pcLogName The login log name. Default name is "ZOS" if no log name.
 * @param [in] pcFormat String format.
 * @param [in] ... String vars.
 *
 * @see @ref Mtc_AnyLogLoginInfoStr
 */
ZFUNC ZVOID Mtc_AnyLogLoginErrStr(ZCHAR *pcLogName, ZCHAR *pcFormat, ...) ZATTR_PRINTF(2,3);

/**
 * @brief Print login INFO log with format string information.
 * User can specific log name as the log module prefix
 * Log print level can be set by Mtc_CliDbSetLogLevel.
 *
 * @param [in] pcLogName The login log name. Default name is "ZOS" if no log name.
 * @param [in] pcFormat String format.
 * @param [in] ... String vars.
 *
 * @see @ref Mtc_AnyLogLoginErrStr
 */
ZFUNC ZVOID Mtc_AnyLogLoginInfoStr(ZCHAR *pcLogName, ZCHAR *pcFormat, ...) ZATTR_PRINTF(2,3);

/**
 * @brief Print login DEBUG log with format string information.
 * User can specific log name as the log module prefix
 * Log print level can be set by Mtc_DbSetLogLevel.
 *
 * @param [in] pcLogName The login log name. Default name is "ZOS" if no log name.
 * @param [in] pcFormat String format.
 * @param [in] ... String vars.
 *
 * @see @ref Mtc_AnyLogLoginInfoStr
 */
ZFUNC ZVOID Mtc_AnyLogLoginDbgStr(ZCHAR *pcLogName, ZCHAR *pcFormat, ...) ZATTR_PRINTF(2,3);

/**
 * @brief This function flushs buffer into login log file.
 *
 * @param [in] zLogId The login log ID.
 *
 * @retval ZOK Flush operation successfully.
 * @retval ZFAILED Flush operation failed.
 *
 * @see 
 */
ZFUNC ZINT Mtc_AnyLogLoginFlush();

/**
 * @brief Get local ip count.
 *
 * @return Local ip count successfully, otherwise retrun 0.
 *
 * @see @ref Mtc_GetLclIp
 */
ZFUNC ZINT Mtc_GetLclIpCnt();

/**
 * @brief Get local ip.
 *
 * @param [in] iIndex Local ip index.
 *
 * @return Local ip successfully, otherwise return loopback address.
 *    the caller must copy it, then use.
 *
 * @see @ref Mtc_GetLclIpCnt
 */
ZFUNC ZCHAR * Mtc_GetLclIp(ZINT iIndex);

/**
 * @brief Get access network type.
 *
 * @return Access network type successfully, 
 * otherwise return MTC_ANET_UNKNOWN.
 */
ZFUNC ZUINT Mtc_GetAccessNetType();

/**
 * @brief Create a new timer.
 *
 * @param [in] iTimerType User defined timer type.
 * @param [in] bCycle Timer mode, cycle or once a time.
 * @param [in] pfnActive Timer active callback.
 * @param [out] pzTimerId Timer ID.
 *
 * @retval ZOK Timer create successfully.
 * @retval ZFAILED Timer create failed.
 *
 * @see @ref Mtc_TimerDelete
 */
ZFUNC ZINT Mtc_TimerCreate(ZUINT iTimerType, ZBOOL bCycle,
                PFN_ZMTCTMRA pfnActive, ZTIMERID *pzTimerId);

/**
 * @brief Delete a timer.
 *
 * @param [in] zTimerId Timer ID.
 *
 * @retval ZOK Timer delete successfully.
 * @retval ZFAILED Timer delete failed.
 *
 * @see @ref Mtc_TimerCreate
 */
ZFUNC ZINT Mtc_TimerDelete(ZTIMERID zTimerId);

/**
 * @brief Start a timer.
 *
 * @param [in] zTimerId Timer ID.
 * @param [in] iTimeLen Time interval in milliseconds.
 *
 * @retval ZOK Timer start successfully.
 * @retval ZFAILED Timer start failed.
 *
 * @note Timer must not in running state.
 *
 * @see @ref Mtc_TimerStop
 */
ZFUNC ZINT Mtc_TimerStart(ZTIMERID zTimerId, ZULONG iTimeLen);

/**
 * @brief Stop a timer.
 *
 * @param [in] zTimerId Timer ID.
 *
 * @retval ZOK Timer stop successfully.
 * @retval ZFAILED Timer stop failed.
 *
 * @see @ref Mtc_TimerStart
 */
ZFUNC ZINT Mtc_TimerStop(ZTIMERID zTimerId);

/**
 * @brief Check if a timer is running.
 *
 * @param [in] zTimerId Timer ID.
 *
 * @retval ZTRUE Timer has been started and still in counting.
 * @retval ZFALSE Otherwise.
 *
 * @see @ref Mtc_TimerStart
 */
ZFUNC ZBOOL Mtc_TimerIsRun(ZTIMERID zTimerId);

/**
 * @brief Schedule a new timer after some seconds.
 *
 * @param [in] iTimerType User defined timer type.
 * @param [in] pfnSchedule User defined schedule callback.
 * @param [in] iTimeLen Time interval in milliseconds.
 *
 * @retval ZOK Timer start successfully.
 * @retval ZFAILED Timer start failed.
 *
 * @note Timer must not in running state.
 *
 * @see @ref Mtc_TimerCreate
 */
ZFUNC ZINT Mtc_TimerSchedule(ZUINT iTimerType, PFN_ZMTCTMRS pfnSchedule, 
                ZULONG iTimeLen);

/**
 * @brief Convert time value from ZTIME_T to ST_MTC_SYS_TIME structure.
 *
 * @param [in] zTime Time value.
 * @param [out] pstTime Time value in ST_MTC_SYS_TIME structure.
 *
 * @retval ZOK Convert successfully.
 * @retval ZFAILED Convert failed.
 *
 * @see
 */
ZFUNC ZINT Mtc_Time2SysTime(ZTIME_T zTime, ST_MTC_SYS_TIME *pstTime);

/**
 * @brief Convert time value from ST_MTC_SYS_TIME structure to ZTIME_T.
 *
 * @param [in] pstTime Time value in ST_MTC_SYS_TIME structure.
 * @param [out] pzTime Time value in ZTIME_T structure.
 *
 * @retval ZOK Convert successfully.
 * @retval ZFAILED Convert failed.
 *
 * @see
 */
ZFUNC ZINT Mtc_SysTime2Time(ST_MTC_SYS_TIME *pstTime, ZTIME_T *pzTime);

/**
 * @brief Run debug command.
 *
 * @param [in] pcCmd Command string.
 *
 * @retval ZOK Run command successfully.
 * @retval ZFAILED Run command failed.
 *
 * @see
 */
ZFUNC ZINT Mtc_CmdRun(ZCONST ZCHAR *pcCmd);

/**
 * @brief Test sip decode.
 *
 * @param [in] pcData SIP data string.
 *
 * @retval ZOK Test successfully.
 * @retval ZFAILED Test failed.
 */
ZFUNC ZINT Mtc_TestSipDecode(ZCHAR *pcData);

/**
 * @brief Test http decode.
 *
 * @param [in] pcData HTTP data string.
 *
 * @retval ZOK Test successfully.
 * @retval ZFAILED Test failed.
 */
ZFUNC ZINT Mtc_TestHttpDecode(ZCHAR *pcData);

/**
 * @brief json prase
 *
 * @param [in] zmbuf.
 * @param [in] need prase string.
 * @param [in] need prase string length.
 *
 * @retval prase json.
 */
ZFUNC ZJSON Mtc_ZjsonParse(ZCBUF zMemBuf, ZCONST ZCHAR *pcText, ZUINT iLen);

/**
 * @brief json prase
 *
 * @param [in] json object.
 * @param [in] need find name.
 *
 * @retval prase json.
 */
ZFUNC ZJSON Mtc_ZjsonObjectGet(ZJSON zObject, ZCONST ZCHAR *pcName);

/**
 * @brief json prase
 *
 * @param [in] json object.
 * @param [in] need find name.
 *
 * @retval string.
 */
ZFUNC ZCONST ZCHAR * Mtc_ZjsonObjectGetString(ZJSON zObject, ZCONST ZCHAR *pcName);

/**
 * @brief json prase
 *
 * @param [in] json object.
 * @param [in] need find name.
 *
 * @retval number.
 */
ZFUNC size_t Mtc_ZjsonObjectGetNumber(ZJSON zObject, ZCONST ZCHAR *pcName);

/**
 * @brief Get imdn msg id.
 *
 * @return imdn msg id string.
 *
 */
ZFUNC ZCHAR * Mtc_GetImdnMsgId();

/**
 * @param [in] pServ service event
 * @param [in] event id.
 *
 * @retval ZOK Run successfully.
 * @retval ZFAILED Run failed.
 *
 */
ZFUNC ZINT Mtc_UtilLeave(ZVOID *pServ, ZEVNT zEvntId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_UTIL_H__ */

