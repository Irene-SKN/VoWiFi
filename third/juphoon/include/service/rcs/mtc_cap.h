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
  File name     : mtc_cap.h
  Module        : multimedia talk client
  Author        : logan.huang
  Created on    : 2012-02-20
  Description   :
      Data structure and function declare required by MTC capability query

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CAP_H__
#define _MTC_CAP_H__

/**
 * @file mtc_cap.h
 * @brief MTC Capability Qurey Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC capability type */
#define MTC_CAP_IM        0x00000001 /**< @brief instant message */
#define MTC_CAP_FT        0x00000002 /**< @brief file transfer */
#define MTC_CAP_IS        0x00000004 /**< @brief image share */
#define MTC_CAP_VS        0x00000008 /**< @brief video share */
#define MTC_CAP_SP        0x00000010 /**< @brief social information via presence */
#define MTC_CAP_DP        0x00000020 /**< @brief capability discovery via presence */
#define MTC_CAP_STDMSG    0x00000040 /**< @brief standalone messaging */
#define MTC_CAP_VSOUTVC   0x00000080 /**< @brief video share outside of a voice call */
#define MTC_CAP_VOICECALL 0x00000100 /**< @brief ip voice call */
#define MTC_CAP_VIDEOCALL 0x00000200 /**< @brief ip video call */
#define MTC_CAP_GEOPULL   0x00000400 /**< @brief geolocation pull */
#define MTC_CAP_GEOPUSH   0x00000800 /**< @brief geolocation push */
#define MTC_CAP_FSTFWDGP  0x00001000 /**< @brief full store and forward for group chat */
#define MTC_CAP_FTTHUMB   0x00002000 /**< @brief file transfer thumbnail */
#define MTC_CAP_FTSTFWD   0x00004000 /**< @brief file transfer store and forward */
#define MTC_CAP_FTHTTP    0x00008000 /**< @brief file transfer via HTTP */
#define MTC_CAP_GEOPULLFT 0x00010000 /**< @brief geolocation pull using file transfer */
#define MTC_CAP_BURN      0x00020000 /**< @brief burn after reading function */
#define MTC_CAP_PUB_MSG   0x00040000 /**< @brief public message */
#define MTC_CAP_CLOUD_FILE 0x00080000 /**< @brief cloud file */
#define MTC_CAP_VEM       0x00100000 /**< @brief vemoticon */
#define MTC_CAP_GRP_MAN   0x00200000 /**< @brief group manage */
#define MTC_CAP_CPM_MSG   0x00400000 /**< @brief cpm message */
#define MTC_CAP_CPM_LARGE 0x00800000 /**< @brief cpm large message */
#define MTC_CAP_CPM_FT    0x01000000 /**< @brief cpm file transfer */
#define MTC_CAP_CPM_SESS  0x02000000 /**< @brief cpm session */

/** @brief Type define of MTC capability status code */
#define EN_MTC_CAP_NO_ERR      (MTC_EBASE_CAP + 0) /* no error */
#define EN_MTC_CAP_NOT_FOUND   (MTC_EBASE_CAP + 1) /* user not found */
#define EN_MTC_CAP_TMP_UNAVAIL (MTC_EBASE_CAP + 2) /* user temporality unavailable */
#define EN_MTC_CAP_AUTH_FAILED (MTC_EBASE_CAP + 3) /* query authentication failed */
#define EN_MTC_CAP_NOT_ALLOW   (MTC_EBASE_CAP + 4) /* query method not allow */
#define EN_MTC_CAP_FORBIDDEN   (MTC_EBASE_CAP + 5) /* query forbidden */
#define EN_MTC_CAP_TIMEOUT     (MTC_EBASE_CAP + 6) /* query timeout */
#define EN_MTC_CAP_NOT_EXIST   (MTC_EBASE_CAP + 7) /* query not exist */
#define EN_MTC_CAP_NOT_IMP     (MTC_EBASE_CAP + 8) /* query not implement */
#define EN_MTC_CAP_OTHER_ERR   (MTC_EBASE_CAP + 9) /* other error */

/**
 * @brief Query option capability of one participant immediately.
 * Capability query will be operated by SIP OPTION method.
 *
 * While query ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CapCbSetCapOptOk.
 *
 * While query failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CapCbSetCapQFailed.
 *
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] zCookie The user cookie.
 * @param [in] iCapOpt The capability option.
 *
 * @retval ZOK capability option query will be running.
 * @retval ZFAILED capability option query  failed.
 */
ZFUNC ZINT Mtc_CapQryOpt(ZCHAR *pcUri, ZCOOKIE zCookie, ZUINT iCapOpt);

/**
 * @brief Query capability of one participant immediately.
 * Capability query will be operated by SIP OPTION method or SUBSCRIBE method.
 *
 * While query ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CapCbSetCapQOk.
 *
 * While query failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CapCbSetCapQFailed.
 *
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] zCookie The user cookie.
 * @param [in] iCapOpt The capability option.
 * @param [in] bOnce The once flag.
 *
 * @retval ZOK capability query will be running.
 * @retval ZFAILED Send message failed.
 */
ZFUNC ZINT Mtc_CapQryOneImd(ZCHAR *pcUri, ZCOOKIE zCookie, 
                ZUINT iCapOpt, ZBOOL bOnce);

/**
 * @brief Query capability of one participant.
 * Capability query will be operated by SIP OPTION method or SUBSCRIBE method.
 *
 * While query ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CapCbSetCapQOk.
 *
 * While query failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CapCbSetCapQFailed.
 *
 * @param [in] pcUri The message receiver SIP URI.
 * @param [in] zCookie The user cookie.
 * @param [in] iCapOpt The capability option.
 * @param [in] bOnce The once flag.
 *
 * @retval ZOK capability query will be running.
 * @retval ZFAILED Send message failed.
 */
ZFUNC ZINT Mtc_CapQryOne(ZCHAR *pcUri, ZCOOKIE zCookie, 
                ZUINT iCapOpt, ZBOOL bOnce);

/**
 * @brief Query capability of participant list.
 * Capability query will be operated by SIP OPTION method or SUBSCRIBE method.
 *
 * While query ok, GUI will be notified by callback which 
 * was set by @ref Mtc_CapCbSetCapQOk.
 *
 * While query failed, GUI will be notified by callback which 
 * was set by @ref Mtc_CapCbSetCapQFailed.
 *
 * @param [in] iPartpLstId The participant list id.
 * @param [in] zCookie The user cookie.
 * @param [in] bOnce The once flag.
 *
 * @retval ZOK capability query will be running. It will trigger the
               callback:Mtc_CapCbSetCapQOk, Mtc_CapCbSetCapQFailed
 * @retval ZFAILED Send message failed.
 */
ZFUNC ZINT Mtc_CapQryLst(ZUINT iPartpLstId, ZCOOKIE zCookie, ZBOOL bOnce);

/**
 * @brief Pause capability query.
 *
 * @retval ZOK Pause successfully.
 * @retval ZFAILED Pause failed.
 */
ZFUNC ZINT Mtc_CapQryPause(ZFUNC_VOID);

/**
 * @brief Resume capability query.
 *
 * @retval ZOK Resume successfully.
 * @retval ZFAILED Resume failed.
 */
ZFUNC ZINT Mtc_CapQryResume(ZFUNC_VOID);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CAP_H__ */

