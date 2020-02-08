/************************************************************************

        Copyright (c) 2005-2018 by Juphoon System Software, Inc.
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
  File name     : mtc_limit.h
  Module        : multimedia talk client
  Author        : honglin.chen
  Created on    : 2018-05-31
  Description   :
    limit the mod by the mtc.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_LIMIT_H__
#define _MTC_LIMIT_H__

/* Define if it is controled by mod. */
#undef LIMITED_MOD_LEMON
#define LIMITED_MOD_COM
#define LIMITED_MOD_CP
#undef LIMITED_MOD_MSG
#undef LIMITED_MOD_PRES
#undef LIMITED_MOD_PROF
#undef LIMITED_MOD_PA
#define LIMITED_MOD_VOIP
#undef LIMITED_MOD_VOICE
#undef LIMITED_MOD_DOODLE

#endif /* _MTC_LIMIT_H__ */