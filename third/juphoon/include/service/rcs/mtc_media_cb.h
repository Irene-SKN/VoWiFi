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
  File name     : mtc_media_cb.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC call callback

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_MEDIA_CB_H__
#define _MTC_MEDIA_CB_H__

/**
 * @file mtc_media_cb.h
 * @brief MTC media Callback Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief Type define of MTC media callback. */
typedef ZVOID (*PFN_MTCMEDIACB)();

/**
 * @brief Set callback of indicate audio device was used by another application.
 *
 * GUI should terminate all call session for there is no resource.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_MediaCbSetAudioDevInterrupted(PFN_MTCMEDIACB pfnCb);

/**
 * @brief Set callback of indicate audio device list changed.
 *
 * GUI use @ref mtc_media.h "MTC Media Interfaces" to refresh the audio devcie
 * list.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_MediaCbSetAudioDevChanged(PFN_MTCMEDIACB pfnCb);

/**
 * @brief Set callback of indicate audio record did finish playing.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_MediaCbSetAudioRecDidFinishPlaying(PFN_MTCMEDIACB pfnCb);

/**
 * @brief Set callback of indicate video device list changed.
 *
 * GUI use @ref mtc_media.h "MTC Media Interfaces" to refresh the video devcie
 * list.
 *
 * @param [in] pfnCb Callback function.
 */
ZFUNC ZVOID Mtc_MediaCbSetVideoDevChanged(PFN_MTCMEDIACB pfnCb);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_MEDIA_CB_H__ */

