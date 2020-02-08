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
  File name     : mtc_d2.h
  Module        : multimedia talk client
  Author        : xiangbo.hui
  Created on    : 2015-03-27
  Description   :
      Data structure and function declare required by MTC statistics

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_D2_H__
#define _MTC_D2_H__

/**
 * @file mtc_d2.h
 * @brief MTC Doodle Interface Functions
 *
 * This file includes doodle interface function.
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create image object.
 * @return            Image object.
 */
ZFUNC MTC_IMG Mtc_D2CreateImage(ZFUNC_VOID);

/**
 * @brief Delete image object.
 * @param  zImage The image object.
 */
ZFUNC ZVOID Mtc_D2DeleteImage(MTC_IMG zImage);

/**
 * @brief Create image object from text.
 * @param  pcMsg The text.
 * @return       The Image object.
 */
ZFUNC MTC_IMG Mtc_D2ParseImage(ZCONST ZCHAR *pcMsg);

/**
 * @brief Save image object to text.
 * @param  zImage The image object.
 * @return        The text string.
 */
ZFUNC ZCONST ZCHAR * Mtc_D2PrintImage(MTC_IMG zImage);

/**
 * @brief Set image parameters.
 * @param  zImage The image object.
 * @param  pcInfo The parameters in JSON format which contains
 *                @ref MtcDoodlePageIdKey
 *                @ref MtcDoodleImageTypeKey
 *                @ref MtcDoodleImageNameKey
 *                @ref MtcDoodleImageUriKey
 *                @ref MtcDoodleResolutionKey
 *                @ref MtcDoodlePositionKey
 * @return        ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2SetImageParms(MTC_IMG zImage,
    ZCONST ZCHAR *pcInfo);

/**
 * @brief Get image parameters.
 * @param  zImage The image object.
 * @return        The parameters in JSON format which contains
 *                @ref MtcDoodlePageIdKey
 *                @ref MtcDoodleImageTypeKey
 *                @ref MtcDoodleImageNameKey
 *                @ref MtcDoodleImageUriKey
 *                @ref MtcDoodleResolutionKey
 *                @ref MtcDoodlePositionKey
 */
ZFUNC ZCONST ZCHAR * Mtc_D2GetImageParms(MTC_IMG zImage);

/**
 * @brief Create action object.
 * @return            The action object.
 */
ZFUNC MTC_ACT Mtc_D2CreateAction(ZFUNC_VOID);

/**
 * @brief Delete action object.
 * @param  zAction The action object.
 */
ZFUNC ZVOID Mtc_D2DeleteAction(MTC_ACT zAction);

/**
 * @brief Create action object from text.
 * @param  pcMsg The text.
 * @return       The action object.
 */
ZFUNC MTC_ACT Mtc_D2ParseAction(ZCONST ZCHAR *pcMsg);

/**
 * @brief Save action object to text.
 * @param  zAction The action object.
 * @return         The text string.
 */
ZFUNC ZCONST ZCHAR * Mtc_D2PrintAction(MTC_ACT zAction);

/**
 * @brief Set action parameters.
 * @param  zAction The action object.
 * @param  pcInfo  The parameters in JSON format which contains
 *                 @ref MtcDoodleActionTypeKey
 *                 @ref MtcDoodleSeqNoKey
 *                 @ref MtcDoodleBrushKey
 *                 @ref MtcDoodlePageIdKey
 *                 @ref MtcDoodleContentKey
 * @return         ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2SetActionParms(MTC_ACT zAction,
    ZCONST ZCHAR *pcInfo);

/**
 * @brief Get action parameters.
 * @param  zAction The action object.
 * @return         The parameters in JSON format which contains
 *                 @ref MtcDoodleActionTypeKey
 *                 @ref MtcDoodleSeqNoKey
 *                 @ref MtcDoodleBrushKey
 *                 @ref MtcDoodlePageIdKey
 *                 @ref MtcDoodleContentKey
 */
ZFUNC ZCONST ZCHAR * Mtc_D2GetActionParms(MTC_ACT zAction);

/**
 * @brief Add action position.
 * @param  zAction The action object.
 * @param  fX      The X value from -1.0 to 1.0.
 * @param  fY      The Y value from -1.0 to 1.0.
 * @return         ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2AddActionPosition(MTC_ACT zAction,
    ZFLOAT fX, ZFLOAT fY);

/**
 * @brief Set action positions.
 * @param  zAction The action object.
 * @param  fX      The value from -1.0 to 1.0.
 * @param  fY      The value from -1.0 to 1.0.
 * @param  iIntVal The interval.
 * @return         ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2AddActionPositionX(MTC_ACT zAction,
    ZFLOAT fX, ZFLOAT fY, ZUINT iIntVal);

/**
 * @brief Get count of positions in action object.
 * @param  zAction The action object.
 * @return         The count of positions.
 */
ZFUNC ZUINT Mtc_D2GetActionPositionCount(MTC_ACT zAction);

/**
 * @brief Get the interval of position.
 * @param  zAction The action object.
 * @param  iIndex  The index of position, from 0 to count-1.
 * @return         The interval in milliseconds.
 */
ZFUNC ZINT Mtc_D2GetActionIntval(MTC_ACT zAction, ZUINT iIndex);

/**
 * @brief Get the X value of position.
 * @param  zAction The action object.
 * @param  iIndex  The index of position, from 0 to count-1.
 * @return         The X value of postion.
 */
ZFUNC ZFLOAT Mtc_D2GetActionPositionX(MTC_ACT zAction, ZUINT iIndex);

/**
 * @brief Get the Y value of position.
 * @param  zAction The action object.
 * @param  iIndex  The index of position, from 0 to count-1.
 * @return         The Y value of postion.
 */
ZFUNC ZFLOAT Mtc_D2GetActionPositionY(MTC_ACT zAction, ZUINT iIndex);

/**
 * @brief Get the path of action.
 * @param  zAction The action object.
 * @return         The path in JSON format which is array contains
 *                 all positions. Each position is array of number.
 *                 First number is interval in milliseoncds.
 *                 Second number is X value of position.
 *                 Third number is Y value of position.
 */
ZFUNC ZCONST ZCHAR * Mtc_D2GetActionPath(MTC_ACT zAction);

/**
 * @brief Create session object.
 * @return            The session object.
 */
ZFUNC MTC_SESS Mtc_D2CreateSession();

/**
 * @brief Delete session object.
 * @param  zSession The session object.
 */
ZFUNC ZVOID Mtc_D2DeleteSession(MTC_SESS zSession);

/**
 * @brief Set session page count.
 * @param  zSession   The session object.
 * @param  iPageCount The page count.
 * @return          ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2SessionSetPageCount(MTC_SESS zSession, ZUINT iPageCount);

/**
 * @brief Add page in session.
 * @param  zSession The session object.
 * @return          ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2SessionAddPage(MTC_SESS zSession);

/**
 * @brief Get page count in session.
 * @param  zSession The session object.
 * @return          The page count.
 */
ZFUNC ZUINT Mtc_D2SessionGetPageCount(MTC_SESS zSession);

/**
 * @brief Add image object to session.
 *
 * You must not delete image after add this image to the session.
 * The image will replace the exist one with same MtcDoodlePageIdKey.
 * 
 * @param  zSession The session object.
 * @param  zImage   The image object.
 * @return          ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2SessionSetImage(MTC_SESS zSession, MTC_IMG zImage);

/**
 * @brief Enumrate the image object.
 * @param  zSession The session object.
 * @param  iIndex   The index of image, from 0 to count-1.
 * @return          The image object.
 */
ZFUNC MTC_IMG Mtc_D2SessionGetImage(MTC_SESS zSession, ZUINT iPageId);

/**
 * @brief Set context-free action of session.
 * @param  zSession The session object.
 * @param  pcKey    The key string.
 * @param  zAction  The action object.
 * @return          ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2SessionSetCfAction(MTC_SESS zSession,
    ZCONST ZCHAR *pcKey, MTC_ACT zAction);

/**
 * @brief Get context-free action of session.
 * @param  zSession The session object.
 * @param  pcKey    The key string.
 * @return          The action object when found. Otherwise return ZNULL.
 */
ZFUNC MTC_ACT Mtc_D2SessionGetCfAction(MTC_SESS zSession, ZCONST ZCHAR *pcKey);

/**
 * @brief Get count of context-free action in session.
 * @param  zSession The session object.
 * @return          The count of context-free actions in session.
 */
ZFUNC ZINT Mtc_D2SessionGetCfActionCount(MTC_SESS zSession);

/**
 * @brief Enumrate the key of context-free action in session.
 * @param  zSession The session object.
 * @param  iIndex   The index value, from 0 to count-1.
 * @return          The key of action.
 */
ZFUNC ZCONST ZCHAR * Mtc_D2SessionEnumCfActionKey(MTC_SESS zSession, ZUINT iIndex);

/**
 * @brief Enumrate the context-free action in session by index.
 * @param  zSession The session object.
 * @param  iIndex   The index value, from 0 to count-1.
 * @return          The context-free action object.
 */
ZFUNC MTC_ACT Mtc_D2SessionEnumCfAction(MTC_SESS zSession, ZUINT iIndex);

/**
 * @brief Add action object to session.
 * @param  zSession The session object.
 * @param  zAction  The action object.
 * @return          ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_D2SessionAddAction(MTC_SESS zSession, MTC_ACT zAction);

/**
 * @brief Get count of actions.
 * @param  zSession The session object.
 * @return          The count of actions.
 */
ZFUNC ZUINT Mtc_D2SessionGetActionCount(MTC_SESS zSession, ZUINT iPageId);

/**
 * @brief Enumrate the actions in session.
 * @param  zSession The session object.
 * @param  iIndex   The index of action, from 0 to count-1.
 * @return          The action object.
 */
ZFUNC MTC_ACT Mtc_D2SessionEnumAction(MTC_SESS zSession, ZUINT iPageId,
    ZUINT iIndex);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_D2_H__ */

