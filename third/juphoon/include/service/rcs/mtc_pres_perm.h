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
  File name     : mtc_pres_perm.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Function implement required by MTC OMA presence permanent state.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PRES_PERM_H__
#define _MTC_PRES_PERM_H__

/**
 * @file mtc_pres_perm.h
 * @brief MTC Presence Permanent State Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC presence icon type */
typedef enum EN_MTC_PRES_ICON_TYPE
{
    EN_MTC_PRES_ICON_NULL,           /**< @brief null picture */
    EN_MTC_PRES_ICON_GIF,            /**< @brief GIF picture */
    EN_MTC_PRES_ICON_JPEG,           /**< @brief JPEG picture */
    EN_MTC_PRES_ICON_PNG             /**< @brief PNG picture */
} EN_MTC_PRES_ICON_TYPE;

/**
 * @brief Load presence permanent state information.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetPermsLoadOk or @ref Mtc_PresCbSetPermsLoadFailed.
 *
 * @retval ZOK Loading permanent state successfully.
 * @retval ZFAILED Loading permanent state failed.
 *
 * @see @ref Mtc_PresPermUpload
 */
ZFUNC ZINT Mtc_PresPermLoad(ZFUNC_VOID);

/**
 * @brief Upload presence status information.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetPermsUploadOk or @ref Mtc_PresCbSetPermsUploadFailed.
 *
 * GUI should set information Mtc_PresPermSetNickName, Mtc_PresPermSetHomePage,
 * @ref Mtc_PresPermSetNote, Mtc_PresPermSetIconType before upload presence status.
 *
 * @retval ZOK Uploading presence status successfully.
 * @retval ZFAILED Uploading presence status failed.
 *
 * @see @ref Mtc_PresPermLoad
 */
ZFUNC ZINT Mtc_PresPermUpload(ZFUNC_VOID);

/**
 * @brief Load presence status icon.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetStatIconLoadOk or @ref Mtc_PresCbSetStatIconLoadFailed.
 *
 * According to RCS specification, the icon file should follow below:
 *  - Icon aspect_ratio (width:height)  --->  3:4 or 4:3
 *  - Icon maximum dimensions  --->  240x320
 *  - Icon minimum dimensions  --->  60x80
 *  - Icon file type  --->  gif (both static and animated), jpeg or png
 *  - Document maximum size ---> less than or equal 200kB
 *
 * @retval ZOK Loading presence status icon successfully.
 * @retval ZFAILED Loading presence status icon failed.
 *
 * @see @ref Mtc_PresPermUploadIcon
 */
ZFUNC ZINT Mtc_PresPermLoadIcon(ZFUNC_VOID);

/**
 * @brief Upload presence status icon.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetStatIconUploadOk or @ref Mtc_PresCbSetStatIconUploadFailed.
 *
 * GUI must import icon data using Mtc_PresPermImportIconFile before upload icon.
 *
 * GUI would better clear icon data @ref Mtc_PresPermClrIconData after uploaded icon file.
 * The reason is icon file will occupy big memory(less than or equal 200KB).
 *
 * @retval ZOK Uploading presence status icon successfully.
 * @retval ZFAILED Uploading presence status icon failed.
 *
 * @see @ref Mtc_PresPermLoadIcon
 */
ZFUNC ZINT Mtc_PresPermUploadIcon(ZFUNC_VOID);

/**
 * @brief Get presence status nick name.
 * 
 * @return The nick name.
 * The caller must copy it, then use.
 *
 * @see @ref Mtc_PresPermSetNickName
 */
ZFUNC ZCHAR * Mtc_PresPermGetNickName(ZFUNC_VOID);

/**
 * @brief Set presence status nick name.
 * 
 * @param [in] pcName The nick name.
 *
 * @retval ZOK Set nick name successfully.
 * @retval ZFAILED Set nick name failed.
 *
 * @see @ref Mtc_PresPermGetNickName
 */
ZFUNC ZINT Mtc_PresPermSetNickName(ZCHAR *pcName);

/**
 * @brief Get presence status home page.
 * 
 * @return The home page.
 * The caller must copy it, then use.
 *
 * @see @ref Mtc_PresPermSetHomePage
 */
ZFUNC ZCHAR * Mtc_PresPermGetHomePage(ZFUNC_VOID);

/**
 * @brief Set presence status home page.
 * 
 * @param [in] pcPage The home page.
 *
 * @retval ZOK Set home page successfully.
 * @retval ZFAILED Set home page failed.
 *
 * @see @ref Mtc_PresPermGetHomePage
 */
ZFUNC ZINT Mtc_PresPermSetHomePage(ZCHAR *pcPage);

/**
 * @brief Get presence person note.
 * 
 * @return The presence person note.
 * The caller must copy it, then use.
 *
 * @see @ref Mtc_PresPermSetNote
 */
ZFUNC ZCHAR * Mtc_PresPermGetNote(ZFUNC_VOID);

/**
 * @brief Set presence person note.
 * 
 * @param [in] pcNote The person note.
 *
 * @retval ZOK Set person note successfully.
 * @retval ZFAILED Set person note failed.
 *
 * @see @ref Mtc_PresPermGetNote
 */
ZFUNC ZINT Mtc_PresPermSetNote(ZCHAR *pcNote);

/**
 * @brief Get presence status icon type.
 * 
 * @return The icon type, see @ref EN_MTC_PRES_ICON_TYPE.
 *
 * @see @ref Mtc_PresPermSetIconType
 */
ZFUNC ZUINT Mtc_PresPermGetIconType(ZFUNC_VOID);

/**
 * @brief Set presence status icon type.
 * 
 * @param [in] iType The icon type, see @ref EN_MTC_PRES_ICON_TYPE.
 *
 * @retval ZOK Set icon type successfully.
 * @retval ZFAILED Set icon type failed.
 *
 * @see @ref Mtc_PresPermGetIconType
 */
ZFUNC ZINT Mtc_PresPermSetIconType(ZUINT iType);

/**
 * @brief Export presence status icon data into file.
 * 
 * GUI would better clear icon data @ref Mtc_PresPermClrIconData after exported icon file.
 * The reason is icon file will occupy big memory(less than or equal 200KB).
 *
 * @param [in] pcFileName The icon file name.
 *
 * @retval ZOK Export icon file successfully.
 * @retval ZFAILED Export icon file failed.
 *
 * @see @ref Mtc_PresPermImportIconFile
 */
ZFUNC ZINT Mtc_PresPermExportIconFile(ZCHAR *pcFileName);

/**
 * @brief Import presence status icon data from file.
 * 
 * @param [in] pcFileName The icon file name.
 *
 * @retval ZOK Import icon file successfully.
 * @retval ZFAILED Import icon file failed.
 *
 * @see @ref Mtc_PresPermExportIconFile
 */
ZFUNC ZINT Mtc_PresPermImportIconFile(ZCHAR *pcFileName);

/**
 * @brief Check has presence status icon data.
 * 
 * @return ZTRUE if exist icon data, otherwise ZFALSE.
 *
 * @see @ref Mtc_PresPermClrIconData
 */
ZFUNC ZBOOL Mtc_PresPermHasIconData(ZFUNC_VOID);

/**
 * @brief Clear presence status icon data.
 * 
 * @retval ZOK Clear icon data successfully.
 * @retval ZFAILED Clear icon data failed.
 */
ZFUNC ZINT Mtc_PresPermClrIconData(ZFUNC_VOID);

/**
 * @brief Subscribe document changes of permanent state.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetPermsSubsDocChgsOk or @ref Mtc_PresCbSetPermsSubsDocChgsFailed.
 *
 * @return Subscription id on succeed or ZMAXUINT on failed.
 */
ZFUNC ZUINT Mtc_PresPermSubsDocChgs(ZFUNC_VOID);

/**
 * @brief Un-subscribe document changes of permanent state.
 *
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PresCbSetPermsUnSubsDocChgsOk or @ref Mtc_PresCbSetPermsUnSubsDocChgsFailed.
 *
 * @param [in] iSubsId The subscription id.
 *
 * @retval ZOK Un-subscribe successfully
 * @retval ZFAILED Un-subscribe failed.
 */
ZFUNC ZUINT Mtc_PresPermUnSubsDocChgs(ZUINT iSubsId);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PRES_PERM_H__ */

