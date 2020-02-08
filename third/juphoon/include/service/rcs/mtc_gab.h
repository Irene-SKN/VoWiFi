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
  File name     : mtc_gab.h
  Module        : multimedia talk client
  Author        : logan.huang
  Created on    : 2011-12-27
  Description   :
      Data structure and function declare required by MTC garbage bin

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_GAB_H__
#define _MTC_GAB_H__

/**
 * @file mtc_gab.h
 * @brief MTC garbage Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/* mtc add system string memory into garbage bin */
ZFUNC ZVOID Mtc_GabAddSysStr(ZCHAR *pcMem);

/* mtc remove system string memory in garbage bin */
ZVOID Mtc_GabRmvSysStr(ZCHAR *pcMem);

/* mtc add participant list id memory into garbage bin */
ZVOID Mtc_GabAddPartpLstId(ZUINT iPartpLstId);

/* mtc remove participant list id memory in garbage bin */
ZVOID Mtc_GabRmvPartpLstId(ZUINT iPartpLstId);

/* mtc clean up memory or any other resources from garbage bin */
ZVOID Mtc_GabCleanUp();

#ifdef __cplusplus
}
#endif

#endif /* _MTC_GAB_H__ */

