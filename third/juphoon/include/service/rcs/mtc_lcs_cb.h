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
  File name     : mtc_lcs_cb.h
  Module        : license
  Author        : jay.chen
  Created on    : 2016-07-29
  Description   :
    Macros and structure definitions required by the license callback.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_LCS_CB_H__
#define _MTC_LCS_CB_H__

/**
 * @file mtc_lcs_cb.h
 * @brief MTC License Callback Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** 
* @brief Type define of MTC license active result callback.
* @param bLicenseActive indicate if License active operation success or fail
*/
#if (ZPLATFORM == ZPLATFORM_WIN32)
    typedef ZVOID (__stdcall * PFN_MTCLCSACTIVERESULT)(ZBOOL bActivated);
#else
    typedef ZVOID (* PFN_MTCLCSACTIVERESULT)(ZBOOL bActivated);
#endif

/**
 * @brief Set license active result callback.
 * The callback will be notified when user to active the license.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_LcsCbSetActiveResult(PFN_MTCLCSACTIVERESULT pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_LCS_CB_H__ */

