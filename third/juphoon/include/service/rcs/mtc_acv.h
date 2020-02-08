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
  File name     : mtc_acv.h
  Module        : multimedia talk client
  Author        : logan.huang
  Created on    : 2013-02-01
  Description   :
      Data structure and function declare required by MTC archive

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_ACV_H__
#define _MTC_ACV_H__

/**
 * @file mtc_acv.h
 * @brief MTC archive Interface Functions
 *
 * This file includes archive interface function.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** 
 * @brief MTC archive logs and commit to server.
 *
 * @param [in] pcRoot The root directory.
 * @param [in] pcDir The log diretory.
 * @param [in] pcAcvName The archived file name.
 * @param [in] pcMemo The memo.
 * @param [in] pcDeviceId The device id.
 *
 */
ZFUNC ZVOID Mtc_AcvCommit(ZCHAR *pcRoot, ZCHAR *pcDir, ZCHAR *pcAcvName, 
                ZCHAR *pcMemo, ZCHAR *pcDeviceId);

/** 
 * @brief MTC archive logs and commit to server.
 *
 * @param [in] pcRoot The root directory.
 * @param [in] ppcDirs The log diretories.
 * @param [in] pcAcvName The archived file name.
 * @param [in] pcMemo The memo.
 * @param [in] pcDeviceId The device id.
 *
 */
ZFUNC ZVOID Mtc_AcvCommitX(ZCHAR *pcRoot, ZCHAR **ppcDirs,
                ZCHAR *pcAcvName, ZCHAR *pcMemo, ZCHAR *pcDeviceId);

#ifdef __cplusplus
}
#endif
                
#endif /* _MTC_ACV_H__ */

