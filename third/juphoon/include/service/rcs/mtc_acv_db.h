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
  File name     : mtc_acv_db.h
  Module        : multimedia talk client
  Author        : kerwin.peng
  Created on    : 2016-03-25
  Description   :
      Data structure and function declare required by MTC archive db

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_ACV_DB_H__
#define _MTC_ACV_DB_H__

/**
 * @file mtc_acv_db.h
 * @brief MTC archive db Interface Functions
 *
 * This file includes archive db interface function.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** 
 * @brief MTC archive db set archive server address.
 *
 * @param [in] pcServAddr The archive server address.
 *
 * @retval ZOK Set archive server address provision successfully.
 * @retval ZFAILED et archive server address provision failed.
 */
ZFUNC ZINT Mtc_AcvDbSetSrvAddr(ZCHAR *pcServAddr);

/** 
 * @brief MTC archive db get archive server address.
 *
 * @retval The archive server address.
 *
 */
ZFUNC ZCHAR *Mtc_AcvDbGetSrvAddr(ZFUNC_VOID);

/** 
 * @brief MTC archive db set archive server port.
 *
 * @param [in] wPort The archive server port.
 *
 * @retval ZOK Set archive server port provision successfully.
 * @retval ZFAILED et archive server port provision failed.
 */
ZFUNC ZINT Mtc_AcvDbSetSrvPort(ZUSHORT wPort);

/** 
 * @brief MTC archive db get archive server port.
 *
 * @retval The archive server port.
 *
 */
ZFUNC ZUSHORT Mtc_AcvDbGetSrvPort(ZFUNC_VOID);

/** 
 * @brief MTC archive db set archive url in the archive server.
 *
 * @param [in] pcServUrl The archive url in the archive server.
 *
 * @retval ZOK Set archive url provision successfully.
 * @retval ZFAILED et archive url provision failed.
 */
ZFUNC ZINT Mtc_AcvDbSetUrl(ZCHAR *pcUrl);

/** 
 * @brief MTC archive db get archive url in the archive server.
 *
 * @retval The archive url.
 *
 */
ZFUNC ZCHAR * Mtc_AcvDbGetUrl(ZFUNC_VOID);

#ifdef __cplusplus
}
#endif
                
#endif /* _MTC_ACV_DB_H__ */

