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
  File name     : mtc_mod_cmcc.h
  Module        : mtc module cmcc register
  Author        : steven.wu
  Created on    : 2015-11-19
  Description   :
      Function implement required by mtc module cmcc.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_MOD_CMCC_H__
#define _MTC_MOD_CMCC_H__

/**
 * @file mtc_mod_cmcc.h
 * @brief MTC module cmcc Interface Functions
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Mtc CMCC module register.
 *
 * attention: after load lib lemon.so you should register
 * this module by call this funciton
 */
ZFUNC ZINT Mtc_ModCmcc_Register(ZFUNC_VOID);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_MOD_CMCC_H__ */

