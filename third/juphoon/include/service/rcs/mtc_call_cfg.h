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
  File name     : mtc_call_cfg.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-04
  Description   :
      Data structure and function declare required by mtc call config 

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CALL_CFG_H__
#define _MTC_CALL_CFG_H__

/**
 * @file mtc_call_cfg.h
 * @brief MTC Call Config Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get using default call log management.
 *
 * @retval ZTRUE MTC provide call log management.
 * @retval ZFALSE MTC don't have call log management.
 *
 * @see @ref Mtc_CallCfgSetUseDftLog
 */
ZFUNC ZBOOL Mtc_CallCfgGetUseDftLog(ZFUNC_VOID);

/**
 * @brief Set using default call log management.
 *
 * @param [in] bUse Use default call log management.
 *
 * @retval ZOK Set use status successfully.
 * @retval ZFAILED Set use status failed.
 *
 * @see @ref Mtc_CallCfgGetUseDftLog
 */
ZFUNC ZINT Mtc_CallCfgSetUseDftLog(ZBOOL bUse);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CALL_CFG_H__ */

