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
  File name     : mtc_prof_cfg.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-04
  Description   :
      Data structure and function declare required by MTC profile config

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PROF_CFG_H__
#define _MTC_PROF_CFG_H__

/**
 * @file mtc_prof_cfg.h
 * @brief MTC Profile Config Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get using default profile management.
 *
 * MTC provide default profile management. Each account profile
 * is stored in different directory under "profiles" directory.
 * Every Account profile have provision.xml etc configuration files.
 *
 * If client using another profile management, client should close 
 * it by @ref Mtc_ProfCfgSetUseDft. After @ref Mtc_CliOpen, client should
 * assign database configuration by @ref Mtc_CliDbSetLocalIp etc interfaces.
 *
 * @retval ZTRUE MTC provide profile management.
 * @retval ZFALSE MTC don't have profile management.
 *
 * @see @ref Mtc_ProfCfgSetUseDft
 */
ZFUNC ZBOOL Mtc_ProfCfgGetUseDft(ZFUNC_VOID);

/**
 * @brief Set using default profile management.
 *
 * @param [in] bUse Use default profile management.
 *
 * @retval ZOK Set use status successfully.
 * @retval ZFAILED Set use status failed.
 *
 * @see @ref Mtc_ProfCfgGetUseDft
 */
ZFUNC ZINT Mtc_ProfCfgSetUseDft(ZBOOL bUse);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PROF_CFG_H__ */

