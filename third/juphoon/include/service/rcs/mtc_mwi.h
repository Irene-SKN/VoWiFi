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
  File name     : mtc_mwi.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC message wait indication

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_MWI_H__
#define _MTC_MWI_H__

/**
 * @file mtc_mwi.h
 * @brief MTC Message Wait Indication Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get voice message count.
 *
 * @param [in,out] piNewCount The new voice message count.
 * @param [in,out] piOldCount The old voice message count.
 * @param [in,out] piNewEmgCount The new emergency voice message count.
 * @param [in,out] piOldEmgCount The old emergency voice message count.
 *
 * @retval ZOK Get message count successfully.
 * @retval ZFAILED Get message count failed.
 *
 * @see @ref Mtc_MwiGetVideoMessageCount, @ref Mtc_MwiGetFaxMessageCount
 */
ZFUNC ZINT Mtc_MwiGetVoiceMessageCount(ZUINT *piNewCount, 
                ZUINT *piOldCount, ZUINT *piNewEmgCount, ZUINT *piOldEmgCount);

/**
 * @brief Get video message count.
 *
 * @param [in,out] piNewCount The new video message count.
 * @param [in,out] piOldCount The old video message count.
 * @param [in,out] piNewEmgCount The new emergency video message count.
 * @param [in,out] piOldEmgCount The old emergency video message count.
 *
 * @retval ZOK Get message count successfully.
 * @retval ZFAILED Get message count failed.
 *
 * @see @ref Mtc_MwiGetVoiceMessageCount, @ref Mtc_MwiGetFaxMessageCount
 */
ZFUNC ZINT Mtc_MwiGetVideoMessageCount(ZUINT *piNewCount, 
                ZUINT *piOldCount, ZUINT *piNewEmgCount, ZUINT *piOldEmgCount);

/**
 * @brief Get fax message count.
 *
 * @param [in,out] piNewCount The new fax message count.
 * @param [in,out] piOldCount The old fax message count.
 * @param [in,out] piNewEmgCount The new emergency fax message count.
 * @param [in,out] piOldEmgCount The old emergency fax message count.
 *
 * @retval ZOK Get message count successfully.
 * @retval ZFAILED Get message count failed.
 *
 * @see @ref Mtc_MwiGetVoiceMessageCount, @ref Mtc_MwiGetVideoMessageCount
 */
ZFUNC ZINT Mtc_MwiGetFaxMessageCount(ZUINT *piNewCount, 
                ZUINT *piOldCount, ZUINT *piNewEmgCount, ZUINT *piOldEmgCount);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_MWI_H__ */

