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
  File name     : mtc_prov_cfg.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-04
  Description   :
      Data structure and function declare required by MTC provision config

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PROV_CFG_H__
#define _MTC_PROV_CFG_H__

/**
 * @file mtc_prov_cfg.h
 * @brief MTC Provision Config Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get using default provision.
 *
 * Default 
 * @retval ZTRUE Detect local IP.
 * @retval ZFALSE Not detect local IP.
 *
 * @retval ZTRUE MTC provide provision management.
 * @retval ZFALSE MTC don't have provision management.
 *
 * @see @ref Mtc_ProvCfgSetUseDft
 */
ZFUNC ZBOOL Mtc_ProvCfgGetUseDft(ZFUNC_VOID);

/**
 * @brief Get provision file name.
 *
 * MTC provide default provision management. 
 * If client using another provision management, just ignore it.
 *
 * @return provision file name.
 *
 * @see @ref Mtc_ProvCfgSetFileName
 */
ZFUNC ZCHAR * Mtc_ProvCfgGetFileName(ZFUNC_VOID);

/**
 * @brief Set using default provision management.
 *
 * @param [in] bUse Use default provision management.
 *
 * @retval ZOK Set use provision successfully.
 * @retval ZFAILED Set use provision failed.
 *
 * @see @ref Mtc_ProvCfgGetUseDft
 */
ZFUNC ZINT Mtc_ProvCfgSetUseDft(ZBOOL bUse);

/**
 * @brief Set provision file name.
 *
 * @param [in] pcFile The provision file name.
 *
 * @retval ZOK Set provision file name successfully.
 * @retval ZFAILED Set provision file name failed.
 *
 * @see @ref Mtc_ProvCfgGetFileName
 */
ZFUNC ZINT Mtc_ProvCfgSetFileName(ZCHAR *pcFile);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PROV_CFG_H__ */

