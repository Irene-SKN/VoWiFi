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
  File name     : mtc_prof.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC profile

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PROF_H__
#define _MTC_PROF_H__

/**
 * @file mtc_prof.h
 * @brief MTC Profile Interface Functions.
 *
 * MTC provides profile management for multi-user environment. Each user will
 * have his own configuration, contact and log information. They are stored
 * in a sub-directory named with user's name.
 *
 * To load profile of specific user, invoke @ref Mtc_CliInit and 
 * @ref Mtc_CliOpen. To load bob's profile in "profiles" directory, use code:
 * @code
   //initialize the client
   Mtc_CliInit("profiles");
   
   // initialize callback functions
   Mtc_CliCbSetPrint(print callback);
   Mtc_CliCbSetRegOk(register ok callback);
   Mtc_CliCbSetRegFailed(register failed callback);
   ... (other callbacks)
   Mtc_CliOpen("bob");
 * @endcode
 *
 * It can also not to use profile management. Just use code:
 * @code
   //initialize the client
   Mtc_CliInit(profile director);
   
   // initialize callback functions
   Mtc_CliCbSetPrint(print callback);
   Mtc_CliCbSetRegOk(register ok callback);
   Mtc_CliCbSetRegFailed(register failed callback);
   ... (other callbacks)
   Mtc_CliOpen(ZNULL);
 * @endcode
 * Now the configuration is default. It may not work properly. So before 
 * @ref Mtc_CliStart, GUI should sets configuration using @ref mtc_cli_db.h etc
 * "MTC DB Interfaces".
 */
 
#ifdef __cplusplus
extern "C" {
#endif

/** @brief The profile mode mask */
#define MTC_PROV_MEDIA_MASK 0xFf
#define MTC_PROV_SERVICE_MASK 0xFF00

/** @brief The profile media mode type. */
typedef enum EN_MTC_PROF_MEDIA_MODE
{
    EN_MTC_PROF_MEDIA_BASE    = 0x00,/**< @brief media base */
    EN_MTC_PROF_MEDIA_ENHANCE = 0x01/**< @brief media enhance */
} EN_MTC_PROF_MEDIA_MODE;

/** @brief The profile service mode type. */
typedef enum EN_MTC_PROF_SERVICE_MODE
{
    EN_MTC_PROF_SERVICE_VOIP  = 0x0000,/**< @brief voip service */
    EN_MTC_PROF_SERVICE_MMTEL = 0x0100,/**< @brief mmtel service */
    EN_MTC_PROF_SERVICE_RCS5  = 0x0200,/**< @brief rcs5 service */
    EN_MTC_PROF_SERVICE_JOYN_HF = 0x0400,/**< @brief joyn HF service */
    EN_MTC_PROF_SERVICE_JOYN_BB = 0x0800,/**< @brief joyn BB service */
    EN_MTC_PROF_SERVICE_CMCC_RCS = 0x1000 /**< @brief cmcc rcs service */
} EN_MTC_PROF_SERVICE_MODE;

/**
 * @brief Get user count in profile management.
 *
 * This interface should be invoke after @ref Mtc_CliInit was called.
 *
 * @return The profile user size.
 */
ZFUNC ZINT Mtc_ProfGetUserSize(ZFUNC_VOID);

/**
 * @brief MTC profile get user name by index 
 *
 * This interface should be invoke after @ref Mtc_CliInit was called.
 *
 * @param [in] iIndex The index in profile list, 0 to size - 1.
 *
 * @return The user name string.
 *   The caller must copy it, then use.
 */  
ZFUNC ZCHAR * Mtc_ProfGetUser(ZINT iIndex);

/**
 * @brief MTC profile get current user.
 *
 * This interface should be invoke after @ref Mtc_CliInit and 
 * @ref Mtc_CliOpen was called.
 *
 * @return The current user string, if client is not open return ZNULL.
 */
ZFUNC ZCHAR * Mtc_ProfGetCurUser(ZFUNC_VOID);

/**
 * @brief MTC profile create a user.
 *
 * This interface should be invoke after @ref Mtc_CliInit was called.
 *
 * @param [in] pcUserName The new user name. 
 *
 * @retval ZOK Create a user successfully.
 * @retval ZFAILED Create a user failed.
 */
ZFUNC ZINT Mtc_ProfCreateUser(ZCHAR *pcUserName);

/**
 * @brief MTC profile delete a user.
 *
 * This interface should be invoke after @ref Mtc_CliInit was called.
 *
 * @param [in] pcUserName The name of the user will be deleted. 
 *
 * @retval ZOK Delete a user successfully.
 * @retval ZFAILED Delete a user failed.
 */
ZFUNC ZINT Mtc_ProfDeleteUser(ZCHAR *pcUserName);

/**
 * @brief MTC profile check exist the user.
 *
 * This interface should be invoke after @ref Mtc_CliInit was called.
 *
 * @param [in] pcUserName The name of the user will be checked. 
 *
 * @retval ZTRUE The user is exist.
 * @retval ZFALSE The user is not exist.
 */
ZFUNC ZBOOL Mtc_ProfExistUser(ZCHAR *pcUserName);

/**
 * @brief MTC profile save configuration of current user.
 *
 * This interface should be invoke after @ref Mtc_CliInit and 
 * @ref Mtc_CliOpen was called.
 *
 * @retval ZOK Save provision successfully.
 * @retval ZFAILED Save provision failed.
 */
ZFUNC ZINT Mtc_ProfSaveProvision(ZFUNC_VOID);

/**
 * @brief MTC profile reset configuration of current user.
 *
 * This interface should be invoke after @ref Mtc_CliInit and 
 * @ref Mtc_CliOpen was called.
 *
 * @retval ZOK Reset provision successfully.
 * @retval ZFAILED Reset provision failed.
 */
ZFUNC ZINT Mtc_ProfResetProvision(ZFUNC_VOID);

/**
 * @brief MTC profile restore configuration of current user for speicifc mode.
 *
 * @param [in] iMode The combination of EN_MTC_PROF_SERVICE_MODE 
 *
 * This interface should be invoke after @ref Mtc_CliInit and 
 * @ref Mtc_CliOpen was called.
 *
 * @retval ZOK Restore provision successfully.
 * @retval ZFAILED Restore provision failed.
 */
ZFUNC ZINT Mtc_ProfRestoreProvision(ZUINT iMode);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_PROF_H__ */

