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
  File name     : mtc_uri.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
      Data structure and function declare required by MTC URI

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_URI_H__
#define _MTC_URI_H__

/**
 * @file mtc_uri.h
 * @brief MTC URI Interface Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC URI format status */
#define MTC_URI_FMT_NOT_COMPLTE -1   /**< @brief URI is not complete */
#define MTC_URI_FMT_INVAL_URI   -2   /**< @brief URI is invalid format */
#define MTC_URI_FMT_EMPTY_URI   -3   /**< @brief URI is empty */


/** @brief MTC URI direst terminal type */
#define MTC_URI_TMNL_APP    "app"
#define MTC_URI_TMNL_PC     "pc"
#define MTC_URI_TMNL_MAC    "mac"
#define MTC_URI_TMNL_PAD    "pad"
#define MTC_URI_TMNL_WEB    "web"

/**
 * @brief Check URI is valid.
 *
 * @param [in] pcUri The URI string.
 *
 * @return ZTRUE if URI is valid SIP URI or TEL URI, otherwise ZFALSE.
 */
ZFUNC ZBOOL Mtc_UriIsValid(ZCHAR *pcUri);

/**
 * @brief Format early URI to a valid URI.
 *
 * @param [in] pcEarlyUri The early URI, it can be phone number, sip URI or tel URI.
 * @param [in] pcRealm The SIP server realm.
 * @param [in] bUserPhone The option of add user=phone parameter.
 *
 * @return The format result otherwise return ZNULL
 *    The caller must copy it parameter, then use.
 */
ZFUNC ZCHAR * Mtc_UriFormat(ZCHAR *pcEarlyUri, ZCHAR *pcRealm, 
                ZBOOL bUserPhone);

/**
 * @brief Format early URI to a valid URI.
 * It will automatically fill realm by @ref Mtc_CliDbGetSipRegRealm.
 *
 * @param [in] pcEarlyUri The early URI, it can be phone number, sip URI or tel URI.
 * @param [in] bUserPhone The option of add user=phone paramter.
 *
 * @return The format result otherwise return ZNULL
 *    The caller must copy it parameter, then use.
 */
ZFUNC ZCHAR * Mtc_UriFormatX(ZCHAR *pcEarlyUri, ZBOOL bUserPhone);

/**
 * @brief Format a TEL URI from phone.
 *
 * @param [in] pcPhone The phone number.
 *
 * @return The TEL URI string otherwise return ZNULL.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_UriFormatTelUri(ZCHAR *pcPhone);

/**
 * @brief Format a national URI from phone.
 *
 * @param [in] pcPhone The phone number.
 *
 * @return The TEL URI string otherwise return ZNULL.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_UriFormatNat(ZCHAR *pcPhone);

/**
 * @brief Format a international URI from phone.
 *
 * @param [in] pcPhone The phone number.
 *
 * @return The TEL URI string otherwise return ZNULL.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_UriFormatInt(ZCHAR *pcPhone);

/**
 * @brief Get user part from SIP or TEL URI.
 *
 * @param [in] pcUri The SIP or TEL URI string.
 * @param [in] iLen The user part name buffer length.
 *
 * @return The user part name string otherwise return ZNUL.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_UriGetName(ZCHAR *pcUri, ZUINT iLen);

/**
 * @brief Get user part(ex: phone number) of URI(SIP or TEL URI).
 *
 * @param [in] pcUri The URI string.
 *
 * @return The user part string otherwise return ZNULL.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_UriGetUserPart(ZCHAR *pcUri);

/**
 * @brief Get user part(ex: phone number) of URI(SIP or TEL URI).
 *
 * @param [in] pcUri The URI string otherwise return ZNULL.
 *
 * @return The host port string.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_UriGetHostPart(ZCHAR *pcUri);

/**
 * @brief Get direct uri.
 *
 * @param [in] pcTmnlType The type of direct terminal.
 *
 * @return The direct uri string.
 */
ZFUNC ZCHAR * Mtc_UriGetDirectUri(ZCHAR * pcTmnlType);

/**
 * @brief Get terminal type of uri
 *
 * @param [in] pcUserUri The URI string.
 *
 * @return The terminal type.
 */
ZFUNC ZCHAR * Mtc_UriGetTmnlType(ZCHAR *pcUserUri);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_URI_H__ */

