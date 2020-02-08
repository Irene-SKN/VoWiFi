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
  File name     : mtc_ring.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
    Macros and structure definitions required by the MTC ring.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_RING_H__
#define _MTC_RING_H__

/**
 * @file mtc_ring.h
 * @brief MTC Ring Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Macro for playing ring forever. */
#define MTC_RING_FOREVER 0

/** @brief Macro for playing DTMF time length in milliseconds. */
#define MTC_RING_DTMF_LEN 200

/** @brief Macro for playing alert event time length in milliseconds. */
#define MTC_RING_ALERT_LEN 500

/** @brief Macro for playing terminated event time length in milliseconds. */
#define MTC_RING_TERM_LEN 2000

/** @brief Mask for use resource in asset for Android. */
#define MTC_RING_ASSET_MASK 0x80000000

/**
 * @brief MTC ring type
 */
typedef enum EN_MTC_RING_TYPE
{
    EN_MTC_RING_TONE_0,              /**< @brief tone 0 */
    EN_MTC_RING_TONE_1,              /**< @brief tone 1 */
    EN_MTC_RING_TONE_2,              /**< @brief tone 2 */
    EN_MTC_RING_TONE_3,              /**< @brief tone 3 */
    EN_MTC_RING_TONE_4,              /**< @brief tone 4 */
    EN_MTC_RING_TONE_5,              /**< @brief tone 5 */
    EN_MTC_RING_TONE_6,              /**< @brief tone 6 */
    EN_MTC_RING_TONE_7,              /**< @brief tone 7 */
    EN_MTC_RING_TONE_8,              /**< @brief tone 8 */
    EN_MTC_RING_TONE_9,              /**< @brief tone 9 */
    EN_MTC_RING_TONE_STAR,           /**< @brief tone * */
    EN_MTC_RING_TONE_POUND,          /**< @brief tone # */

    EN_MTC_RING_RING,                /**< @brief ring */
    EN_MTC_RING_RING_BACK,           /**< @brief ring back */
    EN_MTC_RING_CALL_FAILED,         /**< @brief call failed */
    EN_MTC_RING_BUSY,                /**< @brief busy */
    EN_MTC_RING_CALL_WAIT,           /**< @brief call waiting */
    EN_MTC_RING_FORWARD,             /**< @brief forwarding */
    EN_MTC_RING_TERM,                /**< @brief call terminated */
    EN_MTC_RING_HELD,                /**< @brief call held */

    EN_MTC_RING_MSG_RECV,            /**< @brief message received */
    EN_MTC_RING_SIZE                 /**< @brief ring size */
} EN_MTC_RING_TYPE;

/**
 * @brief Play ring, and ring type see @ref EN_MTC_RING_TYPE.
 *
 * It will play the custom set file if found. Or it will try to play
 * the default ring file. The default ring file path formed by the directory
 * set by @ref Mtc_RingSetDir, the ring name and ".wav" for extension name.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 * @param [in] iMilliSeconds The playing time length in milliseconds, 
 *                           0 is for forever.
 *
 * @retval ZOK Audio plays ring successfully.
 * @retval ZFAILED Audio plays ring failed.
 *
 * @see @ref Mtc_RingPlayX Mtc_RingStop
 */
ZFUNC ZINT Mtc_RingPlay(ZUINT iType, ZUINT iMilliSeconds);

/**
 * @brief Play ring with no loop, and ring type see @ref EN_MTC_RING_TYPE.
 *
 * It will play the custom set file if found. Or it will try to play
 * the default ring file. The default ring file path formed by the directory
 * set by @ref Mtc_RingSetDir, the ring name and ".wav" for extension name.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 *
 * @retval ZOK Audio plays ring successfully.
 * @retval ZFAILED Audio plays ring failed.
 *
 * @see @ref Mtc_RingPlay
 */
ZFUNC ZINT Mtc_RingPlayNoLoop(ZUINT iType);

/**
 * @brief Play ring file.
 *
 * The ring name and ".wav" for extension name.
 *
 * @param [in] pcFileName File name of ring file.
 * @param [in] iMilliSeconds The playing time length in milliseconds, 
 *                           0 is for forever.
 *
 * @retval ZOK Audio plays ring successfully.
 * @retval ZFAILED Audio plays ring failed.
 *
 * @see @ref Mtc_RingPlay Mtc_RingStop
 */
ZFUNC ZINT Mtc_RingPlayX(ZCONST ZCHAR *pcFileName, ZUINT iMilliSeconds);

/**
 * @brief Audio stop playback.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE. ZMAXUINT to
                     stop every ring play.
 *
 * @see @ref Mtc_RingPlay Mtc_RingPlayX
 */
ZFUNC ZVOID Mtc_RingStop(ZUINT iType);

/**
 * @brief Audio is playing.
 *
 * @retval ZTRUE Audio is playing.
 * @retval ZFALSE Audio is not playing.
 *
 * @see @ref Mtc_RingPlay
 */
ZFUNC ZBOOL Mtc_RingIsPlay(ZFUNC_VOID);

/**
 * @brief Get mute status.
 *
 * @retval ZTRUE In mute.
 * @retval ZFALSE In unmute.
 *
 * @see @ref Mtc_RingSetMute
 */
ZFUNC ZBOOL Mtc_RingGetMute(ZFUNC_VOID);

/**
 * @brief Set mute status.
 *
 * @param [in] bMute ZTRUE to mute ring, ZFALSE to unmute ring.
 *
 * @retval ZOK Set mute status successfully.
 * @retval ZFAILED Set mute status failed.
 *
 * @see @ref Mtc_RingGetMute
 */
ZFUNC ZINT Mtc_RingSetMute(ZBOOL bMute);

/**
 * @brief Get mute status of specific type.
 *
 * @param [in] iType Ring type, @ref EN_MTC_RING_TYPE.
 *
 * @retval ZTRUE In mute.
 * @retval ZFALSE In unmute.
 *
 * @see Mtc_RingSetMuteType
 */
ZFUNC ZBOOL Mtc_RingGetMuteType(ZUINT iType);

/**
 * @brief Set mute status of specific type.
 *
 * @param [in] iType Ring type, @ref EN_MTC_RING_TYPE.
 * @param [in] bMute ZTRUE to mute ring, ZFALSE to unmute ring.
 *
 * @retval ZOK Set mute status successfully.
 * @retval ZFAILED Set mute status failed.
 *
 * @see Mtc_RingGetMuteType
 */
ZFUNC ZINT Mtc_RingSetMuteType(ZUINT iType, ZBOOL bMute);

/**
 * @brief Get ring name by type.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 *
 * @return The ring name if found, otherwise return empty string.
 *
 * @see @ref Mtc_RingGetType
 */
ZFUNC ZCHAR * Mtc_RingGetName(ZUINT iType);

/**
 * @brief Get ring description by type.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 *
 * @return The ring description if found, otherwise return empty string.
 *
 * @see @ref Mtc_RingGetType
 */
ZFUNC ZCHAR * Mtc_RingGetDesc(ZUINT iType);

/**
 * @brief Get ring type by name.
 *
 * @param [in] pcName The ring name string.
 *
 * @return The ring type if found. Or return -1.
 *
 * @see @ref Mtc_RingGetName
 */
ZFUNC ZINT Mtc_RingGetType(ZCHAR *pcName);

/**
 * @brief Get custom ring file name by type.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 *
 * @return The ring custom ring file name if found, otherwise return empty string.
 *
 * @see @ref Mtc_RingSetCtmName
 */
ZFUNC ZCHAR * Mtc_RingGetCtmName(ZUINT iType);

/**
 * @brief Set custom ring file name.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 * @param [in] pcName The ring file name.
 *
 * @retval ZOK Set custom ring file name successfully.
 * @retval ZFAILED Set custom ring file name failed.
 *
 * @see @ref Mtc_RingGetCtmName
 */
ZFUNC ZINT Mtc_RingSetCtmName(ZUINT iType, ZCONST ZCHAR *pcName);

/**
 * @brief Get directory for default ring file.
 *
 * @return The directory for default ring file.
 *
 * @see @ref Mtc_RingSetDir
 */
ZFUNC ZCHAR * Mtc_RingGetDir(ZFUNC_VOID);

/**
 * @brief Set directory for default ring file.
 *
 * @param [in] pcName The directory name.
 * @param [in] wLen The string length of directory name.
 *
 * @retval ZOK Set directory for default ring file successfully.
 * @retval ZFAILED Set directory for default ring file failed.
 *
 * @see @ref Mtc_RingGetDir
 */
ZFUNC ZVOID Mtc_RingSetDir(ZCHAR *pcName, ZUSHORT wLen);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_RING_H__ */

