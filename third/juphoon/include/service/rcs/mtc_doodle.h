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
  File name     : mtc_doodle.h
  Module        : multimedia talk client
  Author        : xiangbo.hui
  Created on    : 2015-03-27
  Description   :
      Data structure and function declare required by MTC statistics

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_DOODLE_H__
#define _MTC_DOODLE_H__

/**
 * @file mtc_doodle.h
 * @brief MTC Doodle Interface Functions
 *
 * This file includes doodle interface function.
 */

/**
 * @defgroup MtcDoodleKey MTC notification key for doodle.
 * @{
 */

/**
 * @brief A key whose value is a number object reflecting
 * the type of image, @ref EN_MTC_DOODLE_IMAGE_TYPE.
 */
#define MtcDoodleImageTypeKey       "MtcDoodleImageTypeKey"

/**
 * @brief A key whose value is a string object reflecting
 * the image name.
 */
#define MtcDoodleImageNameKey       "MtcDoodleImageNameKey"

/**
 * @brief A key whose value is a string object reflecting
 * the image URI.
 */
#define MtcDoodleImageUriKey        "MtcDoodleImageUriKey"

/**
 * @brief A key whose value is a array object contains 2 number object reflecting
 * the resolution in pixels.
 */
#define MtcDoodleResolutionKey      "MtcDoodleResolutionKey"

/**
 * @brief A key whose value is a array object contains 2 number object reflecting
 * the position of point, which value is from -1 to 1.
 */
#define MtcDoodlePositionKey        "MtcDoodlePositionKey"

/**
 * @brief A key whose value is a number object reflecting
 * the type of action, @ref EN_MTC_DOODLE_ACTION_TYPE.
 */
#define MtcDoodleActionTypeKey      "MtcDoodleActionTypeKey"

/**
 * @brief A key whose value is a number object reflecting
 * the sequence of action.
 */
#define MtcDoodleSeqNoKey           "MtcDoodleSeqNoKey"

/**
 * @brief A key whose value is a object reflecting
 * the brush's info, contains @ref MtcDoodleWidthKey, @ref MtcDoodleColorKey.
 */
#define MtcDoodleBrushKey           "MtcDoodleBrushKey"

/**
 * @brief A key whose value is a number object reflecting
 * the width in pixels.
 */
#define MtcDoodleWidthKey           "MtcDoodleWidthKey"

/**
 * @brief A key whose value is a number object reflecting
 * the color.
 */
#define MtcDoodleColorKey           "MtcDoodleColorKey"

/**
 * @brief A key whose value is a number object reflecting
 * the index of page.
 */
#define MtcDoodlePageIdKey          "MtcDoodlePageIdKey"

/**
 * @brief A key whose value is a number object reflecting
 * the count of page.
 */
#define MtcDoodlePageCountKey       "MtcDoodlePageCountKey"

/**
 * @brief A key whose value is a string object reflecting
 * the user's URI.
 */
#define MtcDoodleUserUriKey         "MtcDoodleUserUriKey"

/**
 * @brief A key whose value is a string object reflecting
 * the action's content.
 */
#define MtcDoodleContentKey         "MtcDoodleContentKey"

/** @} */

/**
 * @defgroup MtcDoodleNotification MTC notification names for doodle.
 * @{
 */

/** @} */

typedef size_t MTC_IMG;
typedef size_t MTC_ACT;
typedef size_t MTC_SESS;

/** @brief The type of image. */
typedef enum EN_MTC_DOODLE_IMAGE_TYPE
{
    EN_MTC_DOODLE_IMAGE_PNG = 1,
    EN_MTC_DOODLE_IMAGE_JPEG,
    EN_MTC_DOODLE_IMAGE_BMP
} EN_MTC_DOODLE_IMAGE_TYPE;

/** @brief The type of action. */
typedef enum EN_MTC_DOODLE_ACTION_TYPE
{
    EN_MTC_DOODLE_ACTION_DRAW,
    EN_MTC_DOODLE_ACTION_ERASE,
    EN_MTC_DOODLE_ACTION_CLEAN,
    EN_MTC_DOODLE_ACTION_UNDO,
    EN_MTC_DOODLE_ACTION_SELECT_PAGE,
    EN_MTC_DOODLE_ACTION_START,
    EN_MTC_DOODLE_ACTION_STOP,
    EN_MTC_DOODLE_ACTION_LASER_POINT,
    EN_MTC_DOODLE_ACTION_ARROW,
    EN_MTC_DOODLE_ACTION_DRAW_RECTANGLE,
    EN_MTC_DOODLE_ACTION_DRAW_ELLIPSE,
    EN_MTC_DOODLE_ACTION_TEXT,
} EN_MTC_DOODLE_ACTION_TYPE;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create image object.
 * @return            Image object.
 */
ZFUNC MTC_IMG Mtc_DoodleCreateImage(ZFUNC_VOID);

/**
 * @brief Delete image object.
 * @param  zImage The image object.
 */
ZFUNC ZVOID Mtc_DoodleDeleteImage(MTC_IMG zImage);

/**
 * @brief Create image object from text.
 * @param  pcMsg The text.
 * @return       The Image object.
 */
ZFUNC MTC_IMG Mtc_DoodleParseImage(ZCONST ZCHAR *pcMsg);

/**
 * @brief Save image object to text.
 * @param  zImage The image object.
 * @return        The text string.
 */
ZFUNC ZCONST ZCHAR * Mtc_DoodlePrintImage(MTC_IMG zImage);

/**
 * @brief Set image attributes.
 * @param  zImage The image object.
 * @param  pcInfo The attributes in JSON format which contains
 *                @ref MtcDoodlePageIdKey
 *                @ref MtcDoodleImageTypeKey
 *                @ref MtcDoodleImageNameKey
 *                @ref MtcDoodleImageUriKey
 *                @ref MtcDoodleResolutionKey
 *                @ref MtcDoodlePositionKey
 * @return        ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_DoodleSetImageAttr(MTC_IMG zImage,
    ZCONST ZCHAR *pcInfo);

/**
 * @brief Get image attributes.
 * @param  zImage The image object.
 * @return        The attributes in JSON format which contains
 *                @ref MtcDoodlePageIdKey
 *                @ref MtcDoodleImageTypeKey
 *                @ref MtcDoodleImageNameKey
 *                @ref MtcDoodleImageUriKey
 *                @ref MtcDoodleResolutionKey
 *                @ref MtcDoodlePositionKey
 */
ZFUNC ZCONST ZCHAR * Mtc_DoodleGetImageAttr(MTC_IMG zImage);

/**
 * @brief Create action object.
 * @return            The action object.
 */
ZFUNC MTC_ACT Mtc_DoodleCreateAction(ZFUNC_VOID);

/**
 * @brief Delete action object.
 * @param  zAction The action object.
 */
ZFUNC ZVOID Mtc_DoodleDeleteAction(MTC_ACT zAction);

/**
 * @brief Create action object from text.
 * @param  pcMsg The text.
 * @return       The action object.
 */
ZFUNC MTC_ACT Mtc_DoodleParseAction(ZCONST ZCHAR *pcMsg);

/**
 * @brief Save action object to text.
 * @param  zAction The action object.
 * @return         The text string.
 */
ZFUNC ZCONST ZCHAR * Mtc_DoodlePrintAction(MTC_ACT zAction);

/**
 * @brief Set action attributes.
 * @param  zAction The action object.
 * @param  pcInfo  The attributes in JSON format which contains
 *                 @ref MtcDoodleActionTypeKey
 *                 @ref MtcDoodleSeqNoKey
 *                 @ref MtcDoodleBrushKey
 *                 @ref MtcDoodlePageIdKey
 *                 @ref MtcDoodleContentKey
 * @return         ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_DoodleSetActionAttr(MTC_ACT zAction,
    ZCONST ZCHAR *pcInfo);

/**
 * @brief Get action attributes.
 * @param  zAction The action object.
 * @return         The attributes in JSON format which contains
 *                 @ref MtcDoodleActionTypeKey
 *                 @ref MtcDoodleSeqNoKey
 *                 @ref MtcDoodleBrushKey
 *                 @ref MtcDoodlePageIdKey
 *                 @ref MtcDoodleContentKey
 */
ZFUNC ZCONST ZCHAR * Mtc_DoodleGetActionAttr(MTC_ACT zAction);

/**
 * @brief Add action position.
 * @param  zAction The action object.
 * @param  fX      The X value from -1.0 to 1.0.
 * @param  fY      The Y value from -1.0 to 1.0.
 * @return         ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_DoodleAddActionPosition(MTC_ACT zAction,
    ZFLOAT fX, ZFLOAT fY);

/**
 * @brief Set action positions.
 * @param  zAction The action object.
 * @param  fX      The value from -1.0 to 1.0.
 * @param  fY      The value from -1.0 to 1.0.
 * @param  iIntVal The interval.
 * @return         ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_DoodleAddActionPositionX(MTC_ACT zAction,
    ZFLOAT fX, ZFLOAT fY, ZUINT iIntVal);

/**
 * @brief Get count of positions in action object.
 * @param  zAction The action object.
 * @return         The count of positions.
 */
ZFUNC ZINT Mtc_DoodleGetActionPositionCount(MTC_ACT zAction);

/**
 * @brief Get the interval of position.
 * @param  zAction The action object.
 * @param  iIndex  The index of position, from 0 to count-1.
 * @return         The interval in milliseconds.
 */
ZFUNC ZINT Mtc_DoodleGetActionIntval(MTC_ACT zAction, ZINT iIndex);

/**
 * @brief Get the X value of position.
 * @param  zAction The action object.
 * @param  iIndex  The index of position, from 0 to count-1.
 * @return         The X value of postion.
 */
ZFUNC ZFLOAT Mtc_DoodleGetActionPositionX(MTC_ACT zAction, ZINT iIndex);

/**
 * @brief Get the Y value of position.
 * @param  zAction The action object.
 * @param  iIndex  The index of position, from 0 to count-1.
 * @return         The Y value of postion.
 */
ZFUNC ZFLOAT Mtc_DoodleGetActionPositionY(MTC_ACT zAction, ZINT iIndex);

/**
 * @brief Get the path of action.
 * @param  zAction The action object.
 * @return         The path in JSON format which is array contains
 *                 all positions. Each position is array of number.
 *                 First number is interval in milliseoncds.
 *                 Second number is X value of position.
 *                 Third number is Y value of position.
 */
ZFUNC ZCONST ZCHAR * Mtc_DoodleGetActionPath(MTC_ACT zAction);

/**
 * @brief Create session object.
 * @return            The session object.
 */
ZFUNC MTC_SESS Mtc_DoodleCreateSession(ZFUNC_VOID);

/**
 * @brief Delete session object.
 * @param  zSession The session object.
 */
ZFUNC ZVOID Mtc_DoodleDeleteSession(MTC_SESS zSession);

/**
 * @brief Set page count.
 * @param  zSession The session object.
 * @param  iCount   The count of pages.
 * @return          ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_DoodleSessionSetPageCount(MTC_SESS zSession, ZINT iCount);

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
ZFUNC ZINT Mtc_DoodleSessionAddImage(MTC_SESS zSession, MTC_IMG zImage);

/**
 * @brief Get the count of image.
 * @param  zSession The session object.
 * @return          The count of images.
 */
ZFUNC ZINT Mtc_DoodleSessionGetImageCount(MTC_SESS zSession);

/**
 * @brief Enumrate the image object.
 * @param  zSession The session object.
 * @param  iIndex   The index of image, from 0 to count-1.
 * @return          The image object.
 */
ZFUNC MTC_IMG Mtc_DoodleSessionEnumImage(MTC_SESS zSession, ZUINT iIndex);

/**
 * @brief Add action object to session.
 * @param  zSession The session object.
 * @param  bSelf    ZTRUE indicates the action was taken by self.
 *                  Otherwise the actions was taken by peer.
 * @param  zAction  The action object.
 * @return          ZOK on succeed, otherwise failed.
 */
ZFUNC ZINT Mtc_DoodleSessionAddAction(MTC_SESS zSession, ZBOOL bSelf,
    MTC_ACT zAction);

/**
 * @brief Get count of actions.
 * @param  zSession The session object.
 * @return          The count of actions.
 */
ZFUNC ZINT Mtc_DoodleSessionGetActionCount(MTC_SESS zSession);

/**
 * @brief Enumrate the actions in session.
 * @param  zSession The session object.
 * @param  iIndex   The index of action, from 0 to count-1.
 * @return          The action object.
 */
ZFUNC MTC_ACT Mtc_DoodleSessionEnumAction(MTC_SESS zSession, ZUINT iIndex);

/**
 * @brief Enumrate the self flags in session.
 * @param  zSession The session object.
 * @param  iIndex   The index of action, from 0 to count-1.
 * @return          The self flag.
 */
ZFUNC ZBOOL Mtc_DoodleSessionEnumSelf(MTC_SESS zSession, ZUINT iIndex);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_DOODLE_H__ */

