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
  File name     : mtc_im_omsg.h
  Module        : multimedia talk client
  Author        : shuia.xu
  Created on    : 2016-09-06
  Description   :
      Data structure and function declare required by MTC Offline Message.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_OMSG_H__
#define _MTC_IM_OMSG_H__

/**
 * @file mtc_im_omsg.h
 * @brief MTC Instant Message Offline Message Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/* mtc offline message message type */
typedef enum EN_MTC_OMSG_MSG_TYPE
{
    EN_MTC_OMSG_MSG_PAGE,            /* page offline message */
    EN_MTC_OMSG_MSG_LARGE,           /* large offline message */
    EN_MTC_OMSG_MSG_GINFO_IVTED,     /* geo-info invited offline message */
    EN_MTC_OMSG_MSG_FILE_IVTED,      /* file invited offline message */
    EN_MTC_OMSG_MSG_GRP_IVTED,       /* group invited offline message */
    EN_MTC_OMSG_MSG_GRP_MSG,         /* group message offline message */

    EN_MTC_OMSG_MSG_UNKOWN           /* unkown*/
} EN_MTC_OMSG_MSG_TYPE;

/**
 * @brief MTC Get Offline Message list Message Count.
 *
 * @param [in] iMsgLstId The offline-message list id.
 *
 * @retval The Message Count.
 */
ZFUNC ZUINT Mtc_ImOMsgGetMsgCount(ZUINT iMsgLstId);

/**
 * @brief MTC Get Offline Message Type By Index.
 *
 * @param [in] iMsgLstId The offline-message list id.
 * @param [in] iIndex The Index.
 *
 * @retval The Message Type.
 */
ZFUNC ZUINT Mtc_ImOMsgGetMsgTypeByIndex(ZUINT iMsgLstId, ZUINT iIndex);

/**
 * @brief MTC Get Offline Message MessageId By Index.
 *
 * @param [in] iMsgLstId The offline-message list id.
 * @param [in] iIndex The Index.
 *
 * @retval The Message Id.
 */
ZFUNC ZUINT Mtc_ImOMsgGetMsgIdByIndex(ZUINT iMsgLstId, ZUINT iIndex);

/**
 * @brief MTC Get Offline Message SessionId By Index.
 *
 * @param [in] iMsgLstId The offline-message list id.
 * @param [in] iIndex The Index.
 *
 * @retval The Session Id.
 */
ZFUNC ZUINT Mtc_ImOMsgGetSessIdByIndex(ZUINT iMsgLstId, ZUINT iIndex);


#ifdef __cplusplus
}
#endif

#endif /* _MTC_IM_OMSG_H__ */
