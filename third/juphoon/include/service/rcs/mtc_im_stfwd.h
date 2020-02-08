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
  File name     : mtc_im_stfwd.h
  Module        : multimedia talk client
  Author        : anthouny.zhou
  Created on    : 2013-03-01
  Description   :
      Data structure and function declare required by MTC store and forward session

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_STFWD_H__
#define _MTC_IM_STFWD_H__

/**
 * @file mtc_im_stfwd.h
 * @brief MTC Instant Store And Forward Session Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC IM store and forward session content type */
typedef enum EN_MTC_IM_STFWD_CONT_TYPE
{
    EN_MTC_IM_STFWD_CONT_UNKNOWN,    /**< @brief unknown content */
    EN_MTC_IM_STFWD_CONT_TXT_PLAIN,  /**< @brief text/plain content */
    EN_MTC_IM_STFWD_CONT_MSG_TXT_PLAIN,/**< @brief content type of "text/plain" wrapt by cpim */
    EN_MTC_IM_STFWD_CONT_MSG_IMAGE_JPEG,/**< @brief content type of "image/jpeg" wrapt by cpim */
    EN_MTC_IM_STFWD_CONT_MSG_IMAGE_BMP  /**< @brief content type of "image/bmp" wrapt by cpim */
} EN_MTC_IM_STFWD_CONT_TYPE;

/** @brief MTC IM store and forward session imdn request type */
typedef enum EN_MTC_IM_STFWD_IMDN_TYPE
{
    EN_MTC_IM_STFWD_IMDN_UNKNOWN,    /**< @brief unknown message */
    EN_MTC_IM_STFWD_IMDN_REG,        /**< @brief regular message */
    EN_MTC_IM_STFWD_IMDN_DELI,       /**< @brief message with delivery notification request */
    EN_MTC_IM_STFWD_IMDN_DISP,       /**< @brief message with display notification request */
    EN_MTC_IM_STFWD_IMDN_BOTH        /**< @brief message with delivery & display notification request */
} EN_MTC_IM_STFWD_IMDN_TYPE;

/**
 * @brief Accept a store and forward session invitation.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Accept store and forward session successfully.
 * @retval ZFAILED Accept store and forward session failed.
 */
ZFUNC ZINT Mtc_ImStFwdAccept(ZUINT iSessId);

/**
 * @brief Reject a store and forward session invitation.
 *
 * @param [in] iSessId The session id.
 *
 * @retval ZOK Reject store and forward session successfully.
 * @retval ZFAILED Reject store and forward session failed.
 */
ZFUNC ZINT Mtc_ImStFwdReject(ZUINT iSessId);

/**
 * @brief Get user subject from store and forward session.
 *
 * @param [in] iSessId The session id.
 *
 * @return User subject.
 * The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImStFwdGetSubject(ZUINT iSessId);

/**
 * @brief MTC Get participant type from store and forward session.
 *
 * @param [in] iSessId The session id.
 *
 * @return Type of IM store and forward session participant, see @ref EN_MTC_PARTP_LST_TYPE.
 *
 * If type is @ref EN_MTC_PARTP_LST_ONE, participant can be got by @ref Mtc_ImStFwdGetPartp.
 * If type is @ref EN_MTC_PARTP_LST_PREDEF_GRP, participant can be got by @ref Mtc_ImStFwdGetPartp.
 * If type is @ref EN_MTC_PARTP_LST_URI_LST, participant can be got by @ref Mtc_ImStFwdGetPartpLstId.
 */
ZFUNC ZUINT Mtc_ImStFwdGetPartpType(ZUINT iSessId);

/**
 * @brief MTC Get participant information from store and forward session.
 *
 * The participant is the remote client who is joining session.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImStFwdGetPartp(ZUINT iSessId, ZCHAR **ppcName, 
                ZCHAR **ppcUri);

/**
 * @brief Get participant list id from store and forward session.
 *
 * The participant list id is all remote clients who are joining session.
 *
 * @param [in] iSessId The session id.
 *
 * @return The participant list id on succeed or 0 on failed.
 *
 *  The caller is responsible for freeing it by @ref Mtc_PartpLstDelete.
 */
ZFUNC ZUINT Mtc_ImStFwdGetPartpLstId(ZUINT iSessId);

/**
 * @brief Get original participant URI from store and forward session.
 *
 * The participant is the session initiator who initialized this store and forward session.
 * It will return From uri from session invitation information.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImStFwdGetOrigPartp(ZUINT iSessId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief Get original identity of participant URI from store and forward session.
 *
 * The participant is the session initiator who initialized this store and forward session.
 * It will return identity uri if session invitation has P-Asserted-Identity information.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get original participant successfully.
 * @retval ZFAILED Get original participant failed.
 */
ZFUNC ZINT Mtc_ImStFwdGetOrigIdPartp(ZUINT iSessId, ZCHAR **ppcName,
                ZCHAR **ppcUri);

/**
 * @brief MTC Get date time from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time failed.
 */
ZFUNC ZINT Mtc_ImStFwdGetSysDateTime(ZUINT iSessId, 
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get date time from store and forward session.
 *
 * @param [in] iSessId The session id.
 *
 * @return message session date time, otherwise return 0.
 */
ZFUNC ZTIME_T Mtc_ImStFwdGetDateTime(ZUINT iSessId);

/**
 * @brief MTC Get message Imdn type from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return Type of imdn, see @ref EN_MTC_IM_STFWD_IMDN_TYPE.
 */
ZFUNC ZUINT Mtc_ImStFwdMsgGetImdnType(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get imdn message-id from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The imdn message-id.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImStFwdMsgGetImdnMsgId(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get device id from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The device id.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImStFwdMsgGetDeviceId(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get message content type from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return Type of IM message, see @ref EN_MTC_IM_STFWD_CONT_TYPE.
 */
ZFUNC ZUINT Mtc_ImStFwdMsgGetContentType(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get message content length from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The message content length.
 */
ZFUNC ZUINT Mtc_ImStFwdMsgGetContentLen(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get message content from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return The message content.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_ImStFwdMsgGetContent(ZUINT iSessId, 
                ZUINT iMsgId);

/**
 * @brief MTC Get multi-media message content from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 * @param [out] ppData The multi-media message content.
 * @param [out] piDataSize The multi-media message content length.
 *
 * @retval ZOK Get message content successfully.
 * @retval ZFAILED Get message content failed.
 *   The caller must copy it, then use.
 */
ZFUNC ZINT Mtc_ImStFwdMsgGetMContent(ZUINT iSessId, 
                ZUINT iMsgId, ZVOID **ppData, ZUINT *piDataSize);

/**
 * @brief MTC Get participant information from store and forward session.
 *
 * The participant is the remote client who has sent message.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 * @param [in,out] ppcName The participant name.
 * @param [in,out] ppcUri The participant URI.
 *
 * The caller must copy out parameter, then use.
 *
 * @retval ZOK Get participant information successfully.
 * @retval ZFAILED Get participant information failed.
 */
ZFUNC ZINT Mtc_ImStFwdMsgGetPartp(ZUINT iSessId, ZUINT iMsgId, 
                ZCHAR **ppcName, ZCHAR **ppcUri);

/**
 * @brief MTC Get message date time from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 * @param [in,out] pstTime The date time value. 
 *
 * @retval ZOK Get date time successfully.
 * @retval ZFAILED Get date time failed.
 */
ZFUNC ZINT Mtc_ImStFwdMsgGetSysDateTime(ZUINT iSessId, ZUINT iMsgId,
                ST_MTC_SYS_TIME *pstTime);

/**
 * @brief MTC Get message date time from store and forward session.
 *
 * @param [in] iSessId The session id.
 * @param [in] iMsgId The message Id.
 *
 * @return message date time, otherwise return 0.
 */
ZFUNC ZTIME_T Mtc_ImStFwdMsgGetDateTime(ZUINT iSessId, 
                ZUINT iMsgId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_STFWD_H__ */
