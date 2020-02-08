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
  File name     : mtc_mwi_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC MWI callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_MWI_CB_H__
#define _MTC_MWI_CB_H__

/**
 * @file mtc_mwi_cb.h
 * @brief MTC Message Wait Indication Callback Interface Functions
 *
 * This file includes MWI callback interface function. Those function
 * is used to manage MWI.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC MWI callback. */
typedef ZINT (*PFN_MTCMWICB)(ZFUNC_VOID);

/**
 * @brief Set the incoming message wait indication callback.
 * The callback will be notified if user subscribe MWI service.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_MwiCbSetIncoming(PFN_MTCMWICB pfnCb);   

#ifdef __cplusplus
}
#endif

#endif /* _MTC_MWI_CB_H__ */

