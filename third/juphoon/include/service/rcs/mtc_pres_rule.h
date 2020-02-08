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
  File name     : mtc_pres_rule.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by MTC OMA presence rule.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PRES_RULE_H__
#define _MTC_PRES_RULE_H__

/**
 * @file mtc_pres_rule.h
 * @brief MTC Presence Rules Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Load presence rule set from XDMS server.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetRuleLoadOk or @ref Mtc_PresCbSetRuleLoadFailed.
 *
 * Note: Before load presence rule, user MUST load buddy successfully(@ref Mtc_BuddysLoad).
 *
 * @retval ZOK Start loading presence rule successfully.
 * @retval ZFAILED Client Load presence rule failed.
 */
ZFUNC ZINT Mtc_PresRulesLoad(ZFUNC_VOID);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PRES_RULE_H__ */

