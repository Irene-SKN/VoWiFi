/************************************************************************

        Copyright (c) 2005-2014 by Juphoon System Software, Inc.
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
  File name     : mtc_cprof.h
  Module        : multimedia talk client
  Author        : phil.zhou
  Created on    : 2014-09-25
  Description   :
      Function implement required by MTC CMCC profile.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CPROF_H__
#define _MTC_CPROF_H__

/**
 * @file mtc_cprof.h
 * @brief MTC CMCC Profile Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC CMCC profile status code. */
#define MTC_CPROF_ERR_NO               (MTC_EBASE_CPROF + 0) /**< @brief no error */
#define MTC_CPROF_ERR_AUTH_FAILED      (MTC_EBASE_CPROF + 1) /**< @brief authentication failed, invalid user or password */
#define MTC_CPROF_ERR_CONN_FAILED      (MTC_EBASE_CPROF + 2) /**< @brief transport connect failed */
#define MTC_CPROF_ERR_SEND_FAILED      (MTC_EBASE_CPROF + 3) /**< @brief transport send failed */
#define MTC_CPROF_ERR_SERV_DISCED      (MTC_EBASE_CPROF + 4) /**< @brief transport disconnected by server */
#define MTC_CPROF_ERR_SERV_ERR         (MTC_EBASE_CPROF + 5) /**< @brief server internal error */
#define MTC_CPROF_ERR_REQ_TIMEOUT      (MTC_EBASE_CPROF + 6) /**< @brief request timeout */
#define MTC_CPROF_ERR_BAD_XML_MSG      (MTC_EBASE_CPROF + 7) /**< @brief bad xml message */
#define MTC_CPROF_ERR_REPEATED         (MTC_EBASE_CPROF + 8) /**< @brief element repeated */
#define MTC_CPROF_ERR_NOT_FOUND        (MTC_EBASE_CPROF + 9) /**< @brief not found */
#define MTC_CPROF_ERR_FORBIDDEN        (MTC_EBASE_CPROF + 10) /**< @brief forbidden */
#define MTC_CPROF_ERR_OTHER            (MTC_EBASE_CPROF + 11) /**< @brief other error */

/** @brief MTC CMCC profile pcc type */
typedef enum EN_MTC_CPROF_PCC_TYPE
{
    EN_MTC_CPROF_PCC_INDVDL,               /**< @brief individual */
    EN_MTC_CPROF_PCC_ORG,                  /**< @brief organization */
    EN_MTC_CPROF_PCC_GRP                   /**< @brief group */
} EN_MTC_CPROF_PCC_TYPE;

/** @brief MTC CMCC profile pcc name type */
typedef enum EN_MTC_CPROF_PCC_NAME_TYPE
{
    EN_MTC_CPROF_PCC_NAME_ALIAS,           /**< @brief Alias */
    EN_MTC_CPROF_PCC_NAME_LEGALNAME,       /**< @brief LegalName */
    EN_MTC_CPROF_PCC_NAME_KNOWNAS,         /**< @brief KnownAs */
    EN_MTC_CPROF_PCC_NAME_MAIDENNAME,      /**< @brief MaidenName */
    EN_MTC_CPROF_PCC_NAME_FORMERNAME,      /**< @brief FormerName */
    EN_MTC_CPROF_PCC_NAME_NAMEATBIRTH,     /**< @brief NameAtBirth */
    EN_MTC_CPROF_PCC_NAME_OFFICIALNAME,    /**< @brief OfficialName */
    EN_MTC_CPROF_PCC_NAME_OTHER,           /**< @brief Other */
} EN_MTC_CPROF_PCC_NAME_TYPE;

/** @brief MTC CMCC profile pcc address type */
typedef enum EN_MTC_CPROF_PCC_ADDR_TYPE
{
    EN_MTC_CPROF_PCC_ADDR_HOME,            /**< @brief Home */
    EN_MTC_CPROF_PCC_ADDR_WORK,            /**< @brief Work */
    EN_MTC_CPROF_PCC_ADDR_BUSINESS,        /**< @brief Business */
    EN_MTC_CPROF_PCC_ADDR_TRAVEL,          /**< @brief Travel */
    EN_MTC_CPROF_PCC_ADDR_NAMEATBIRTH,     /**< @brief NameAtBirth */
    EN_MTC_CPROF_PCC_ADDR_OFFICIALNAME,    /**< @brief OfficialName */
    EN_MTC_CPROF_PCC_ADDR_OTHER,           /**< @brief Other */
} EN_MTC_CPROF_PCC_ADDR_TYPE;

/** @brief MTC CMCC profile pcc uri type */
typedef enum EN_MTC_CPROF_PCC_URI_TYPE
{
    EN_MTC_CPROF_PCC_URI_WORK,             /**< @brief Work */
    EN_MTC_CPROF_PCC_URI_HOME,             /**< @brief Home */
    EN_MTC_CPROF_PCC_URI_FAX,              /**< @brief Fax */
    EN_MTC_CPROF_PCC_URI_MOBILE,           /**< @brief Mobile */
    EN_MTC_CPROF_PCC_URI_FIXED,            /**< @brief Fixed */
    EN_MTC_CPROF_PCC_URI_EMAIL,            /**< @brief Email */
    EN_MTC_CPROF_PCC_URI_PAGER,            /**< @brief Pager */
    EN_MTC_CPROF_PCC_URI_SIP_URI,          /**< @brief SIP-URI */
    EN_MTC_CPROF_PCC_URI_IM,               /**< @brief IM */
    EN_MTC_CPROF_PCC_URI_VIDEO,            /**< @brief Video */
    EN_MTC_CPROF_PCC_URI_OTHER,            /**< @brief Other */
} EN_MTC_CPROF_PCC_URI_TYPE;

/** @brief MTC CMCC profile pcc tel type */
typedef enum EN_MTC_CPROF_PCC_TEL_TYPE
{
    EN_MTC_CPROF_PCC_TEL_WORK,             /**< @brief Work */
    EN_MTC_CPROF_PCC_TEL_HOME,             /**< @brief Home */
    EN_MTC_CPROF_PCC_TEL_FAX,              /**< @brief Fax */
    EN_MTC_CPROF_PCC_TEL_MOBILE,           /**< @brief Mobile */
    EN_MTC_CPROF_PCC_TEL_FIXED,            /**< @brief Fixed */
    EN_MTC_CPROF_PCC_TEL_EMAIL,            /**< @brief Email */
    EN_MTC_CPROF_PCC_TEL_OTHER,            /**< @brief Other */
} EN_MTC_CPROF_PCC_TEL_TYPE;

/** @brief MTC CMCC profile pcc xui type */
typedef enum EN_MTC_CPROF_PCC_XUI_TYPE
{
    EN_MTC_CPROF_PCC_XUI_CAB,              /**< @brief CAB */
    EN_MTC_CPROF_PCC_XUI_OTHER,            /**< @brief Other */
} EN_MTC_CPROF_PCC_XUI_TYPE;

/** @brief MTC CMCC profile pcc calendars type */
typedef enum EN_MTC_CPROF_PCC_CAL_TYPE
{
    EN_MTC_CPROF_PCC_CAL_AKAN,             /**< @brief Akan */
    EN_MTC_CPROF_PCC_CAL_ASSYRIAN,         /**< @brief Assyrian */
    EN_MTC_CPROF_PCC_CAL_ARMENIAN,         /**< @brief Armenian */
    EN_MTC_CPROF_PCC_CAL_AZTEC,            /**< @brief Aztec */
    EN_MTC_CPROF_PCC_CAL_BABYLONIAN,       /**< @brief Babylonian */
    EN_MTC_CPROF_PCC_CAL_BAHAI,            /**< @brief Bahai */
    EN_MTC_CPROF_PCC_CAL_BENGALI,          /**< @brief Bengali */
    EN_MTC_CPROF_PCC_CAL_BERBER,           /**< @brief Berber */
    EN_MTC_CPROF_PCC_CAL_BIKRAM_SAVAT,     /**< @brief Bikram Savat */
    EN_MTC_CPROF_PCC_CAL_BUDDHIST,         /**< @brief Buddhist */
    EN_MTC_CPROF_PCC_CAL_BURMESE,          /**< @brief Burmese */
    EN_MTC_CPROF_PCC_CAL_BYZANTINE,        /**< @brief Byzantine */
    EN_MTC_CPROF_PCC_CAL_CELTIC,           /**< @brief Celtic */
    EN_MTC_CPROF_PCC_CAL_CHINESE,          /**< @brief Chinese */
    EN_MTC_CPROF_PCC_CAL_COPTIC,           /**< @brief Coptic */
    EN_MTC_CPROF_PCC_CAL_EGYPTIAN,         /**< @brief Egyptian */
    EN_MTC_CPROF_PCC_CAL_ETHIOPIAN,        /**< @brief Ethiopian */
    EN_MTC_CPROF_PCC_CAL_FRENCH_REPUBLICAN, /**< @brief French Republican */
    EN_MTC_CPROF_PCC_CAL_GERMANIC,         /**< @brief Germanic */
    EN_MTC_CPROF_PCC_CAL_HEBREW,           /**< @brief Hebrew */
    EN_MTC_CPROF_PCC_CAL_HELLENIC,         /**< @brief Hellenic */
    EN_MTC_CPROF_PCC_CAL_HINDU,            /**< @brief Hindu */
    EN_MTC_CPROF_PCC_CAL_IGBO,             /**< @brief Igbo */
    EN_MTC_CPROF_PCC_CAL_INDIAN,           /**< @brief Indian */
    EN_MTC_CPROF_PCC_CAL_IRANIAN,          /**< @brief Iranian */
    EN_MTC_CPROF_PCC_CAL_IRISH,            /**< @brief Irish */
    EN_MTC_CPROF_PCC_CAL_ISLAMIC,          /**< @brief Islamic */
    EN_MTC_CPROF_PCC_CAL_JAPANSES,         /**< @brief Japanese */
    EN_MTC_CPROF_PCC_CAL_JAVANSES,         /**< @brief Javanese */
    EN_MTC_CPROF_PCC_CAL_JUCHE,            /**< @brief Juche */
    EN_MTC_CPROF_PCC_CAL_JULIAN,           /**< @brief Julian */
    EN_MTC_CPROF_PCC_CAL_KOREAN,           /**< @brief Korean */
    EN_MTC_CPROF_PCC_CAL_KURDISH,          /**< @brief Kurdish */
    EN_MTC_CPROF_PCC_CAL_LITHUANIAN,       /**< @brief Lithuanian */
    EN_MTC_CPROF_PCC_CAL_MALAYALAM,        /**< @brief Malayalam */
    EN_MTC_CPROF_PCC_CAL_MAYA,             /**< @brief Maya */
    EN_MTC_CPROF_PCC_CAL_NANAKSHAHI,       /**< @brief Nanakshahi */
    EN_MTC_CPROF_PCC_CAL_NEPAL_SAMBAT,     /**< @brief Nepal Sambat */
    EN_MTC_CPROF_PCC_CAL_SOVIET,           /**< @brief Soviet */
    EN_MTC_CPROF_PCC_CAL_TAMIL,            /**< @brief Tamil */
    EN_MTC_CPROF_PCC_CAL_TIBETAN,          /**< @brief Tibetan */
    EN_MTC_CPROF_PCC_CAL_THAI,             /**< @brief Thai */
    EN_MTC_CPROF_PCC_CAL_VIETNAMESE,       /**< @brief Vietnamese */
    EN_MTC_CPROF_PCC_CAL_XHOSA,            /**< @brief Xhosa */
    EN_MTC_CPROF_PCC_CAL_YORUBA,           /**< @brief Yoruba */
} EN_MTC_CPROF_PCC_CAL_TYPE;

/** @brief MTC CMCC profile mime type */
typedef enum EN_MTC_CPROF_MIME_TYPE
{
    EN_MTC_CPROF_MIME_UNKNOWN,             /**< @brief unknwon */
    EN_MTC_CPROF_MIME_IMAGE_JPG,           /**< @brief image/jpg */
    EN_MTC_CPROF_MIME_IMAGE_PNG,           /**< @brief image/png */
    EN_MTC_CPROF_MIME_IMAGE_GIF,           /**< @brief image/gif */
} EN_MTC_CPROF_MIME_TYPE;

/** @brief MTC CMCC profile encoding type */
typedef enum EN_MTC_CPROF_ENCODING_TYPE
{
    EN_MTC_CPROF_ENCODING_UNKNOWN,         /**< @brief unknwon */
    EN_MTC_CPROF_ENCODING_BASE64,          /**< @brief base64 */
} EN_MTC_CPROF_ENCODING_TYPE;

/** @brief MTC CMCC profile X-Resolution type */
typedef enum EN_MTC_CPROF_XRESOLUTION_TYPE
{
    EN_MTC_CPROF_XRESOLUTION_16,           /**< @brief 16*16 */
    EN_MTC_CPROF_XRESOLUTION_24,           /**< @brief 24*24 */
    EN_MTC_CPROF_XRESOLUTION_32,           /**< @brief 32*32 */
    EN_MTC_CPROF_XRESOLUTION_42,           /**< @brief 42*42 */
    EN_MTC_CPROF_XRESOLUTION_48,           /**< @brief 48*48 */
    EN_MTC_CPROF_XRESOLUTION_64,           /**< @brief 64*64 */
    EN_MTC_CPROF_XRESOLUTION_120,          /**< @brief 120*120 */
    EN_MTC_CPROF_XRESOLUTION_640,          /**< @brief 640*640 */
} EN_MTC_CPROF_XRESOLUTION_TYPE;

/**
 * @brief Load pcc document from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccAllLoadOk or @ref Mtc_CprofCbSetPccAllLoadFailed.
 * 
 * @retval ZOK Start loading pcc successfully.
 * @retval ZFAILED Client load pcc failed.
 *
 * @see Mtc_CprofPccUploadAll
 */
ZFUNC ZINT Mtc_CprofPccLoadAll(ZFUNC_VOID);

/**
 * @brief Upload pcc document into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccAllUploadOk or @ref Mtc_CprofCbSetPccAllUploadFailed.
 * 
 * @retval ZOK Start uploading pcc successfully.
 * @retval ZFAILED Client upload pcc failed.
 *
 * @see Mtc_CprofPccLoadAll
 */
ZFUNC ZINT Mtc_CprofPccUploadAll(ZFUNC_VOID);

/**
 * @brief Load pcc name from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccNameLoadOk or @ref Mtc_CprofCbSetPccNameLoadFailed.
 * 
 * @retval ZOK Start loading pcc name successfully.
 * @retval ZFAILED Client load pcc name failed.
 *
 * @see Mtc_CprofPccUploadName
 */
ZFUNC ZINT Mtc_CprofPccLoadName(ZFUNC_VOID);

/**
 * @brief Upload pcc name into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccNameUploadOk or @ref Mtc_CprofCbSetPccNameUploadFailed.
 * 
 * @retval ZOK Start uploading pcc name successfully.
 * @retval ZFAILED Client upload pcc name failed.
 *
 * @see Mtc_CprofPccLoadName
 */
ZFUNC ZINT Mtc_CprofPccUploadName(ZFUNC_VOID);

/**
 * @brief Load pcc address from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccAddrLoadOk or @ref Mtc_CprofCbSetPccAddrLoadFailed.
 * 
 * @retval ZOK Start loading pcc address successfully.
 * @retval ZFAILED Client load pcc address failed.
 *
 * @see Mtc_CprofPccUploadAddr
 */
ZFUNC ZINT Mtc_CprofPccLoadAddr(ZFUNC_VOID);

/**
 * @brief Upload pcc address into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccAddrUploadOk or @ref Mtc_CprofCbSetPccAddrUploadFailed.
 * 
 * @retval ZOK Start uploading pcc address successfully.
 * @retval ZFAILED Client upload pcc address failed.
 *
 * @see Mtc_CprofPccLoadAddr
 */
ZFUNC ZINT Mtc_CprofPccUploadAddr(ZFUNC_VOID);

/**
 * @brief Load pcc comm-addr from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccCommAddrLoadOk or @ref Mtc_CprofCbSetPccCommAddrLoadFailed.
 * 
 * @retval ZOK Start loading pcc comm-addr successfully.
 * @retval ZFAILED Client load pcc comm-addr failed.
 *
 * @see Mtc_CprofPccUploadCommAddr
 */
ZFUNC ZINT Mtc_CprofPccLoadCommAddr(ZFUNC_VOID);

/**
 * @brief Upload pcc comm-addr into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccCommAddrUploadOk or @ref Mtc_CprofCbSetPccCommAddrUploadFailed.
 * 
 * @retval ZOK Start uploading pcc comm-addr successfully.
 * @retval ZFAILED Client upload pcc comm-addr failed.
 *
 * @see Mtc_CprofPccLoadCommAddr
 */
ZFUNC ZINT Mtc_CprofPccUploadCommAddr(ZFUNC_VOID);

/**
 * @brief Load pcc birth from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccBirthLoadOk or @ref Mtc_CprofCbSetPccBirthLoadFailed.
 * 
 * @retval ZOK Start loading pcc birth successfully.
 * @retval ZFAILED Client load pcc birth failed.
 *
 * @see Mtc_CprofPccUploadBirth
 */
ZFUNC ZINT Mtc_CprofPccLoadBirth(ZFUNC_VOID);

/**
 * @brief Upload pcc birth into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccBirthUploadOk or @ref Mtc_CprofCbSetPccBirthUploadFailed.
 * 
 * @retval ZOK Start uploading pcc birth successfully.
 * @retval ZFAILED Client upload pcc birth failed.
 *
 * @see Mtc_CprofPccLoadBirth
 */
ZFUNC ZINT Mtc_CprofPccUploadBirth(ZFUNC_VOID);

/**
 * @brief Load pcc career from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccCareerLoadOk or @ref Mtc_CprofCbSetPccCareerLoadFailed.
 * 
 * @retval ZOK Start loading pcc career successfully.
 * @retval ZFAILED Client load pcc career failed.
 *
 * @see Mtc_CprofPccUploadCareer
 */
ZFUNC ZINT Mtc_CprofPccLoadCareer(ZFUNC_VOID);

/**
 * @brief Upload pcc career into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccCareerUploadOk or @ref Mtc_CprofCbSetPccCareerUploadFailed.
 * 
 * @retval ZOK Start uploading pcc career successfully.
 * @retval ZFAILED Client upload pcc career failed.
 *
 * @see Mtc_CprofPccLoadCareer
 */
ZFUNC ZINT Mtc_CprofPccUploadCareer(ZFUNC_VOID);

/**
 * @brief Load pcc icon from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccIconLoadOk or @ref Mtc_CprofCbSetPccIconLoadFailed.
 * 
 * @param [in] iXResolution The X-Resolution type, @see @ref EN_MTC_CPROF_XRESOLUTION_TYPE.
 * @param [in] pcEtag The entity tag.
 * 
 * @retval ZOK Start loading pcc icon successfully.
 * @retval ZFAILED Client load pcc icon failed.
 *
 * @see Mtc_CprofPccUploadIcon
 */
ZFUNC ZINT Mtc_CprofPccLoadIcon(ZUINT iXResolution, ZCHAR *pcEtag);

/**
 * @brief Upload pcc icon into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetPccIconUploadOk or @ref Mtc_CprofCbSetPccIconUploadFailed.
 * 
 * @retval ZOK Start uploading pcc icon successfully.
 * @retval ZFAILED Client upload pcc icon failed.
 *
 * @see Mtc_CprofPccLoadIcon
 */
ZFUNC ZINT Mtc_CprofPccUploadIcon(ZFUNC_VOID);

/**
 * @brief Load qr card document from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetQrCardAllLoadOk or @ref Mtc_CprofCbSetQrCardAllLoadFailed.
 * 
 * @retval ZOK Start loading qr card successfully.
 * @retval ZFAILED Client load qr card failed.
 */
ZFUNC ZINT Mtc_CprofQrCardLoadAll(ZFUNC_VOID);

/**
 * @brief Load qr card flag from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetQrCardFlagLoadOk or @ref Mtc_CprofCbSetQrCardFlagLoadFailed.
 * 
 * @retval ZOK Start loading qr card flag successfully.
 * @retval ZFAILED Client load qr card flag failed.
 *
 * @see Mtc_CprofQrCardUploadFlag
 */
ZFUNC ZINT Mtc_CprofQrCardLoadFlag(ZFUNC_VOID);

/**
 * @brief Upload qr card flag into OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetQrCardFlagUploadOk or @ref Mtc_CprofCbSetQrCardFlagUploadFailed.
 * 
 * @retval ZOK Start uploading qr card flag successfully.
 * @retval ZFAILED Client upload qr card flag failed.
 *
 * @see Mtc_CprofQrCardLoadFlag
 */
ZFUNC ZINT Mtc_CprofQrCardUploadFlag(ZFUNC_VOID);

/**
 * @brief Load qr card pcc from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetQrCardPccLoadOk or @ref Mtc_CprofCbSetQrCardPccLoadFailed.
 *
 * @param [in] pcUrl The pcc url.
 * 
 * @return qr card pcc id successfully or ZMAXUINT failed.
 */
ZFUNC ZUINT Mtc_CprofQrCardLoadPcc(ZCHAR *pcUrl);

/**
 * @brief Load qr card pcc icon from OMA XDMS.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_CprofCbSetQrCardPccIconLoadOk or @ref Mtc_CprofCbSetQrCardPccIconLoadFailed.
 *
 * @param [in] pcUri The pcc icon uri.
 * @param [in] iXResolution The X-Resolution type, @see @ref EN_MTC_CPROF_XRESOLUTION_TYPE.
 * @param [in] pcEtag The entity tag.
 * 
 * @return qr card pcc icon id successfully or ZMAXUINT failed.
 */
ZFUNC ZUINT Mtc_CprofQrCardLoadPccIcon(ZCHAR *pcUri, ZUINT iXResolution, 
                ZCHAR *pcEtag);

/**
 * @brief Get the pcc type.
 *
 * @return The pcc type, @see @ref EN_MTC_CPROF_PCC_TYPE.
 *
 * @see Mtc_CprofPccSetPccType
 */
ZFUNC ZUINT Mtc_CprofPccGetPccType(ZFUNC_VOID);

/**
 * @brief Set the pcc type.
 *
 * @param [in] iType The pcc type, @see @ref EN_MTC_CPROF_PCC_TYPE.
 *
 * @retval ZOK Set pcc type successfully.
 * @retval ZFAILED Set pcc type failed.
 *
 * @see Mtc_CprofPccGetPccType
 */
ZFUNC ZINT Mtc_CprofPccSetPccType(ZUINT iType);

/**
 * @brief Get the pcc name size.
 *
 * @return The name size.
 *
 * @see Mtc_CprofPccGetNameId
 */
ZFUNC ZINT Mtc_CprofPccGetNameSize(ZFUNC_VOID);

/**
 * @brief Get the pcc name id by index.
 *
 * @param [in] iIndex The name index.
 *
 * @return The name id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofPccGetNameSize
 */
ZFUNC ZUINT Mtc_CprofPccGetNameId(ZUINT iIndex);

/**
 * @brief Add the pcc name.
 *
 * @return The name id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofPccRmvName
 */
ZFUNC ZUINT Mtc_CprofPccAddName(ZFUNC_VOID);

/**
 * @brief Remove the pcc name.
 *
 * @param [in] iNameId The name id.
 *
 * @retval ZOK Remove name successfully.
 * @retval ZFAILED Remove name failed.
 *
 * @see Mtc_CprofPccAddName
 */
ZFUNC ZINT Mtc_CprofPccRmvName(ZUINT iNameId);

/**
 * @brief Get the pcc given name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The given name.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccNameSetGiven
 */
ZFUNC ZCHAR * Mtc_CprofPccNameGetGiven(ZUINT iNameId);

/**
 * @brief Set the pcc given name.
 *
 * @param [in] iNameId The name id.
 * @param [in] pcGiven The given name .
 *
 * @retval ZOK Set given name successfully.
 * @retval ZFAILED Set given name failed.
 *
 * @see Mtc_CprofPccNameGetGiven
 */
ZFUNC ZINT Mtc_CprofPccNameSetGiven(ZUINT iNameId, ZCHAR *pcGiven);

/**
 * @brief Get the pcc middle name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The middle name.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccNameSetMiddle
 */
ZFUNC ZCHAR * Mtc_CprofPccNameGetMiddle(ZUINT iNameId);

/**
 * @brief Set the pcc middle name .
 *
 * @param [in] iNameId The name id.
 * @param [in] pcMiddle The middle name .
 *
 * @retval ZOK Set middle name successfully.
 * @retval ZFAILED Set middle name failed.
 *
 * @see Mtc_CprofPccNameGetMiddle
 */
ZFUNC ZINT Mtc_CprofPccNameSetMiddle(ZUINT iNameId, ZCHAR *pcMiddle);

/**
 * @brief Get the pcc family name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The family name.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccNameSetFamily
 */
ZFUNC ZCHAR * Mtc_CprofPccNameGetFamily(ZUINT iNameId);

/**
 * @brief Set the pcc family name .
 *
 * @param [in] iNameId The name id.
 * @param [in] pcFamily The family name .
 *
 * @retval ZOK Set family name successfully.
 * @retval ZFAILED Set family name failed.
 *
 * @see Mtc_CprofPccNameGetFamily
 */
ZFUNC ZINT Mtc_CprofPccNameSetFamily(ZUINT iNameId, ZCHAR *pcFamily);

/**
 * @brief Get the pcc display name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The display name.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccNameSetDispName
 */
ZFUNC ZCHAR * Mtc_CprofPccNameGetDispName(ZUINT iNameId);

/**
 * @brief Set the pcc display name .
 *
 * @param [in] iNameId The name id.
 * @param [in] pcDispName The display name .
 *
 * @retval ZOK Set display name successfully.
 * @retval ZFAILED Set display name failed.
 *
 * @see Mtc_CprofPccNameGetDispName
 */
ZFUNC ZINT Mtc_CprofPccNameSetDispName(ZUINT iNameId, ZCHAR *pcDispName);

/**
 * @brief Get the pcc first name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The first name.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccNameSetFirst
 */
ZFUNC ZCHAR * Mtc_CprofPccNameGetFirst(ZUINT iNameId);

/**
 * @brief Set the pcc first name .
 *
 * @param [in] iNameId The name id.
 * @param [in] pcFirst The first name .
 *
 * @retval ZOK Set first name successfully.
 * @retval ZFAILED Set first name failed.
 *
 * @see Mtc_CprofPccNameGetFirst
 */
ZFUNC ZINT Mtc_CprofPccNameSetFirst(ZUINT iNameId, ZCHAR *pcFirst);

/**
 * @brief Get the pcc name type.
 *
 * @param [in] iNameId The name id.
 *
 * @return The name type, @see @ref EN_MTC_CPROF_PCC_NAME_TYPE.
 *
 * @see Mtc_CprofPccNameSetType
 */
ZFUNC ZUINT Mtc_CprofPccNameGetType(ZUINT iNameId);

/**
 * @brief Set the pcc name type.
 *
 * @param [in] iNameId The name id.
 * @param [in] iType The name type, @see @ref EN_MTC_CPROF_PCC_NAME_TYPE.
 *
 * @retval ZOK Set name type successfully.
 * @retval ZFAILED Set name type failed.
 *
 * @see Mtc_CprofPccNameGetType
 */
ZFUNC ZINT Mtc_CprofPccNameSetType(ZUINT iNameId, ZUINT iType);

/**
 * @brief Get the pcc name preference.
 *
 * @param [in] iNameId The name id.
 *
 * @return The name preference.
 *
 * @see Mtc_CprofPccNameSetPref
 */
ZFUNC ZUINT Mtc_CprofPccNameGetPref(ZUINT iNameId);

/**
 * @brief Set the pcc name preference.
 *
 * @param [in] iNameId The name id.
 * @param [in] iPref The name preference.
 *
 * @retval ZOK Set name preference successfully.
 * @retval ZFAILED Set name preference failed.
 *
 * @see Mtc_CprofPccNameGetPref
 */
ZFUNC ZINT Mtc_CprofPccNameSetPref(ZUINT iNameId, ZUINT iPref);

/**
 * @brief Get the pcc address size.
 *
 * @return The address size.
 *
 * @see Mtc_CprofPccGetAddrId
 */
ZFUNC ZINT Mtc_CprofPccGetAddrSize(ZFUNC_VOID);

/**
 * @brief Get the pcc address id by index.
 *
 * @param [in] iIndex The address index.
 *
 * @return The address id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofPccGetAddrSize
 */
ZFUNC ZUINT Mtc_CprofPccGetAddrId(ZUINT iIndex);

/**
 * @brief Add the pcc address.
 *
 * @return The address id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofPccRmvAddr
 */
ZFUNC ZUINT Mtc_CprofPccAddAddr(ZFUNC_VOID);

/**
 * @brief Remove the pcc address.
 *
 * @param [in] iAddrId The address id.
 *
 * @retval ZOK Remove address successfully.
 * @retval ZFAILED Remove address failed.
 *
 * @see Mtc_CprofPccAddAddr
 */
ZFUNC ZINT Mtc_CprofPccRmvAddr(ZUINT iAddrId);

/**
 * @brief Get the pcc address label.
 *
 * @param [in] iAddrId The address id.
 *
 * @return The address label.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccAddrSetLabel
 */
ZFUNC ZCHAR * Mtc_CprofPccAddrGetLabel(ZUINT iAddrId);

/**
 * @brief Set the pcc address label .
 *
 * @param [in] iAddrId The address id.
 * @param [in] pcLabel The address label .
 *
 * @retval ZOK Set address label successfully.
 * @retval ZFAILED Set address label failed.
 *
 * @see Mtc_CprofPccAddrGetLabel
 */
ZFUNC ZINT Mtc_CprofPccAddrSetLabel(ZUINT iAddrId, ZCHAR *pcLabel);

/**
 * @brief Get the pcc address string.
 *
 * @param [in] iAddrId The address id.
 *
 * @return The address string.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccAddrSetAddr
 */
ZFUNC ZCHAR * Mtc_CprofPccAddrGetAddr(ZUINT iAddrId);

/**
 * @brief Set the pcc address string.
 *
 * @param [in] iAddrId The address id.
 * @param [in] pcAddr The address string.
 *
 * @retval ZOK Set address string successfully.
 * @retval ZFAILED Set address string failed.
 *
 * @see Mtc_CprofPccAddrGetAddr
 */
ZFUNC ZINT Mtc_CprofPccAddrSetAddr(ZUINT iAddrId, ZCHAR *pcAddr);

/**
 * @brief Get the pcc address type.
 *
 * @param [in] iAddrId The address id.
 *
 * @return The address type, @see @ref EN_MTC_CPROF_PCC_ADDR_TYPE.
 *
 * @see Mtc_CprofPccAddrSetType
 */
ZFUNC ZUINT Mtc_CprofPccAddrGetType(ZUINT iAddrId);

/**
 * @brief Set the pcc address type.
 *
 * @param [in] iAddrId The address id.
 * @param [in] iType The address type, @see @ref EN_MTC_CPROF_PCC_ADDR_TYPE.
 *
 * @retval ZOK Set address type successfully.
 * @retval ZFAILED Set address type failed.
 *
 * @see Mtc_CprofPccAddrGetAddr
 */
ZFUNC ZINT Mtc_CprofPccAddrSetType(ZUINT iAddrId, ZUINT iType);

/**
 * @brief Get the pcc address preference.
 *
 * @param [in] iAddrId The address id.
 *
 * @return The address preference.
 *
 * @see Mtc_CprofPccAddrSetPref
 */
ZFUNC ZUINT Mtc_CprofPccAddrGetPref(ZUINT iAddrId);

/**
 * @brief Set the pcc address preference.
 *
 * @param [in] iAddrId The address id.
 * @param [in] iPref The address preference.
 *
 * @retval ZOK Set address preference successfully.
 * @retval ZFAILED Set address preference failed.
 *
 * @see Mtc_CprofPccAddrGetPref
 */
ZFUNC ZINT Mtc_CprofPccAddrSetPref(ZUINT iAddrId, ZUINT iPref);

/**
 * @brief Get the pcc uri size.
 *
 * @return The uri size.
 *
 * @see Mtc_CprofPccCommAddrGetUriId
 */
ZFUNC ZINT Mtc_CprofPccCommAddrGetUriSize(ZFUNC_VOID);

/**
 * @brief Get the pcc uri id by index.
 *
 * @param [in] iIndex The uri index.
 *
 * @return The uri id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofPccCommAddrGetUriSize
 */
ZFUNC ZUINT Mtc_CprofPccCommAddrGetUriId(ZUINT iIndex);

/**
 * @brief Add the pcc uri.
 *
 * @return The uri id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofPccCommAddrRmvUri
 */
ZFUNC ZUINT Mtc_CprofPccCommAddrAddUri(ZFUNC_VOID);

/**
 * @brief Remove the pcc uri.
 *
 * @param [in] iUriId The uri id.
 *
 * @retval ZOK Remove uri successfully.
 * @retval ZFAILED Remove uri failed.
 *
 * @see Mtc_CprofPccCommAddrAddUri
 */
ZFUNC ZINT Mtc_CprofPccCommAddrRmvUri(ZUINT iUriId);

/**
 * @brief Get the pcc uri label.
 *
 * @param [in] iUriId The uri id.
 *
 * @return The uri label.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccUriSetLabel
 */
ZFUNC ZCHAR * Mtc_CprofPccUriGetLabel(ZUINT iUriId);

/**
 * @brief Set the pcc uri label .
 *
 * @param [in] iUriId The uri id.
 * @param [in] pcLabel The uri label .
 *
 * @retval ZOK Set address uri successfully.
 * @retval ZFAILED Set address uri failed.
 *
 * @see Mtc_CprofPccAddrGetLabel
 */
ZFUNC ZINT Mtc_CprofPccUriSetLabel(ZUINT iUriId, ZCHAR *pcLabel);

/**
 * @brief Get the pcc uri string.
 *
 * @param [in] iUriId The uri id.
 *
 * @return The uri string.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccUriSetUri
 */
ZFUNC ZCHAR * Mtc_CprofPccUriGetUri(ZUINT iUriId);

/**
 * @brief Set the pcc uri string.
 *
 * @param [in] iUriId The uri id.
 * @param [in] pcUri The uri string.
 *
 * @retval ZOK Set uri string successfully.
 * @retval ZFAILED Set uri string failed.
 *
 * @see Mtc_CprofPccUriGetUri
 */
ZFUNC ZINT Mtc_CprofPccUriSetUri(ZUINT iUriId, ZCHAR *pcUri);

/**
 * @brief Get the pcc uri type.
 *
 * @param [in] iUriId The uri id.
 *
 * @return The uri type, @see @ref EN_MTC_CPROF_PCC_URI_TYPE.
 *
 * @see Mtc_CprofPccUriSetType
 */
ZFUNC ZUINT Mtc_CprofPccUriGetType(ZUINT iUriId);

/**
 * @brief Set the pcc uri type.
 *
 * @param [in] iUriId The uri id.
 * @param [in] iType The uri type, @see @ref EN_MTC_CPROF_PCC_URI_TYPE.
 *
 * @retval ZOK Set uri type successfully.
 * @retval ZFAILED Set uri type failed.
 *
 * @see Mtc_CprofPccUriGetType
 */
ZFUNC ZINT Mtc_CprofPccUriSetType(ZUINT iUriId, ZUINT iType);

/**
 * @brief Get the pcc uri preference.
 *
 * @param [in] iUriId The uri id.
 *
 * @return The uri preference.
 *
 * @see Mtc_CprofPccUriSetPref
 */
ZFUNC ZUINT Mtc_CprofPccUriGetPref(ZUINT iUriId);

/**
 * @brief Set the pcc uri preference.
 *
 * @param [in] iUriId The uri id.
 * @param [in] iPref The uri preference.
 *
 * @retval ZOK Set uri preference successfully.
 * @retval ZFAILED Set uri preference failed.
 *
 * @see Mtc_CprofPccUriGetPref
 */
ZFUNC ZINT Mtc_CprofPccUriSetPref(ZUINT iUriId, ZUINT iPref);

/**
 * @brief Get the pcc tel size.
 *
 * @return The tel size.
 *
 * @see Mtc_CprofPccCommAddrGetTelId
 */
ZFUNC ZINT Mtc_CprofPccCommAddrGetTelSize(ZFUNC_VOID);

/**
 * @brief Get the pcc tel id by index.
 *
 * @param [in] iIndex The tel index.
 *
 * @return The tel id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofPccCommAddrGetTelSize
 */
ZFUNC ZUINT Mtc_CprofPccCommAddrGetTelId(ZUINT iIndex);

/**
 * @brief Add the pcc tel.
 *
 * @return The tel id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofPccCommAddrRmvTel
 */
ZFUNC ZUINT Mtc_CprofPccCommAddrAddTel(ZFUNC_VOID);

/**
 * @brief Remove the pcc tel.
 *
 * @param [in] iTelId The tel id.
 *
 * @retval ZOK Remove tel successfully.
 * @retval ZFAILED Remove tel failed.
 *
 * @see Mtc_CprofPccCommAddrAddTel
 */
ZFUNC ZINT Mtc_CprofPccCommAddrRmvTel(ZUINT iTelId);

/**
 * @brief Get the pcc tel label.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The tel label.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccTelSetLabel
 */
ZFUNC ZCHAR * Mtc_CprofPccTelGetLabel(ZUINT iTelId);

/**
 * @brief Set the pcc tel label .
 *
 * @param [in] iTelId The tel id.
 * @param [in] pcLabel The tel label .
 *
 * @retval ZOK Set address tel successfully.
 * @retval ZFAILED Set address tel failed.
 *
 * @see Mtc_CprofPccAddrGetLabel
 */
ZFUNC ZINT Mtc_CprofPccTelSetLabel(ZUINT iTelId, ZCHAR *pcLabel);

/**
 * @brief Get the pcc tel string.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The tel string.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccTelSetTel
 */
ZFUNC ZCHAR * Mtc_CprofPccTelGetTel(ZUINT iTelId);

/**
 * @brief Set the pcc tel string.
 *
 * @param [in] iTelId The tel id.
 * @param [in] pcTel The tel string.
 *
 * @retval ZOK Set tel string successfully.
 * @retval ZFAILED Set tel string failed.
 *
 * @see Mtc_CprofPccTelGetTel
 */
ZFUNC ZINT Mtc_CprofPccTelSetTel(ZUINT iTelId, ZCHAR *pcTel);

/**
 * @brief Get the pcc tel type.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The tel type, @see @ref EN_MTC_CPROF_PCC_TEL_TYPE.
 *
 * @see Mtc_CprofPccTelSetTelType
 */
ZFUNC ZUINT Mtc_CprofPccTelGetTelType(ZUINT iTelId);

/**
 * @brief Set the pcc tel type.
 *
 * @param [in] iTelId The tel id.
 * @param [in] iType The tel type, @see @ref EN_MTC_CPROF_PCC_TEL_TYPE.
 *
 * @retval ZOK Set tel type successfully.
 * @retval ZFAILED Set tel type failed.
 *
 * @see Mtc_CprofPccTelGetTelType
 */
ZFUNC ZINT Mtc_CprofPccTelSetTelType(ZUINT iTelId, ZUINT iType);

/**
 * @brief Get the pcc xui type.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The xui type, @see @ref EN_MTC_CPROF_PCC_XUI_TYPE.
 *
 * @see Mtc_CprofPccTelSetXuiType
 */
ZFUNC ZUINT Mtc_CprofPccTelGetXuiType(ZUINT iTelId);

/**
 * @brief Set the pcc xui type.
 *
 * @param [in] iTelId The tel id.
 * @param [in] iType The xui type, @see @ref EN_MTC_CPROF_PCC_XUI_TYPE.
 *
 * @retval ZOK Set xui type successfully.
 * @retval ZFAILED Set xui type failed.
 *
 * @see Mtc_CprofPccTelGetXuiType
 */
ZFUNC ZINT Mtc_CprofPccTelSetXuiType(ZUINT iTelId, ZUINT iType);

/**
 * @brief Get the pcc tel preference.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The tel preference.
 *
 * @see Mtc_CprofPccTelSetPref
 */
ZFUNC ZUINT Mtc_CprofPccTelGetPref(ZUINT iTelId);

/**
 * @brief Set the pcc tel preference.
 *
 * @param [in] iTelId The tel id.
 * @param [in] iPref The tel preference.
 *
 * @retval ZOK Set tel preference successfully.
 * @retval ZFAILED Set tel preference failed.
 *
 * @see Mtc_CprofPccTelGetPref
 */
ZFUNC ZINT Mtc_CprofPccTelSetPref(ZUINT iTelId, ZUINT iPref);

/**
 * @brief Get the pcc birth date.
 *
 * @return The birth date.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccBirthSetDate
 */
ZFUNC ZCHAR * Mtc_CprofPccBirthGetDate(ZFUNC_VOID);

/**
 * @brief Set the pcc birth date.
 *
 * @param [in] pcDate The birth date.
 *
 * @retval ZOK Set birth date successfully.
 * @retval ZFAILED Set birth date failed.
 *
 * @see Mtc_CprofPccBirthGetDate
 */
ZFUNC ZINT Mtc_CprofPccBirthSetDate(ZCHAR *pcDate);

/**
 * @brief Get the pcc birth non-gregorian.
 *
 * @return The birth non-gregorian.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccBirthSetNonGregDate
 */
ZFUNC ZCHAR * Mtc_CprofPccBirthGetNonGregDate(ZFUNC_VOID);

/**
 * @brief Set the pcc birth non-gregorian.
 *
 * @param [in] pcNonGregDate The birth non-gregorian.
 *
 * @retval ZOK Set birth non-gregorian successfully.
 * @retval ZFAILED Set birth non-gregorian failed.
 *
 * @see Mtc_CprofPccBirthGetNonGregDate
 */
ZFUNC ZINT Mtc_CprofPccBirthSetNonGregDate(ZCHAR *pcNonGregDate);

/**
 * @brief Get the pcc birth place.
 *
 * @return The birth place.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccBirthSetPlace
 */
ZFUNC ZCHAR * Mtc_CprofPccBirthGetPlace(ZFUNC_VOID);

/**
 * @brief Set the pcc birth place.
 *
 * @param [in] pcPlace The birth place.
 *
 * @retval ZOK Set birth place successfully.
 * @retval ZFAILED Set birth place failed.
 *
 * @see Mtc_CprofPccBirthGetPlace
 */
ZFUNC ZINT Mtc_CprofPccBirthSetPlace(ZCHAR *pcPlace);

/**
 * @brief Get the pcc birth calendars type.
 *
 * @return The calendars type, @see @ref EN_MTC_CPROF_PCC_CAL_TYPE.
 *
 * @see Mtc_CprofPccBirthSetCalType
 */
ZFUNC ZUINT Mtc_CprofPccBirthGetCalType(ZFUNC_VOID);

/**
 * @brief Set the pcc birth calendars type.
 *
 * @param [in] iType The calendars type, @see @ref EN_MTC_CPROF_PCC_CAL_TYPE.
 *
 * @retval ZOK Set calendars type successfully.
 * @retval ZFAILED Set calendars type failed.
 *
 * @see Mtc_CprofPccBirthGetCalType
 */
ZFUNC ZINT Mtc_CprofPccBirthSetCalType(ZUINT iType);

/**
 * @brief Get the pcc career employer.
 *
 * @return The career employer.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccCareerSetEmployer
 */
ZFUNC ZCHAR * Mtc_CprofPccCareerGetEmployer(ZFUNC_VOID);

/**
 * @brief Set the pcc career employer.
 *
 * @param [in] pcEmployer The career employer.
 *
 * @retval ZOK Set career employer successfully.
 * @retval ZFAILED Set career employer failed.
 *
 * @see Mtc_CprofPccCareerGetEmployer
 */
ZFUNC ZINT Mtc_CprofPccCareerSetEmployer(ZCHAR *pcEmployer);

/**
 * @brief Get the pcc career duty.
 *
 * @return The career duty.
 *   The caller must copy it, then use.
 *
 * @see Mtc_CprofPccCareerSetDuty
 */
ZFUNC ZCHAR * Mtc_CprofPccCareerGetDuty(ZFUNC_VOID);

/**
 * @brief Set the pcc career duty.
 *
 * @param [in] pcDuty The career duty.
 *
 * @retval ZOK Set career duty successfully.
 * @retval ZFAILED Set career duty failed.
 *
 * @see Mtc_CprofPccCareerGetDuty
 */
ZFUNC ZINT Mtc_CprofPccCareerSetDuty(ZCHAR *pcDuty);

/**
 * @brief Get the pcc icon mime type.
 *
 * @return The mime type, @see @ref EN_MTC_CPROF_MIME_TYPE.
 *
 * @see Mtc_CprofPccIconSetMimeType
 */
ZFUNC ZUINT Mtc_CprofPccIconGetMimeType(ZFUNC_VOID);

/**
 * @brief Set the pcc icon mime type.
 *
 * @param [in] iType The mime type, @see @ref EN_MTC_CPROF_MIME_TYPE.
 *
 * @retval ZOK Set mime type successfully.
 * @retval ZFAILED Set mime type failed.
 *
 * @see Mtc_CprofPccIconGetMimeType
 */
ZFUNC ZINT Mtc_CprofPccIconSetMimeType(ZUINT iType);

/**
 * @brief Get the pcc icon encoding type.
 *
 * @return The encoding type, @see @ref EN_MTC_CPROF_ENCODING_TYPE.
 *
 * @see Mtc_CprofPccIconSetEncodingType
 */
ZFUNC ZUINT Mtc_CprofPccIconGetEncodingType();

/**
 * @brief Set the pcc icon encoding type.
 *
 * @param [in] iType The encoding type, @see @ref EN_MTC_CPROF_ENCODING_TYPE.
 *
 * @retval ZOK Set encoding type successfully.
 * @retval ZFAILED Set encoding type failed.
 *
 * @see Mtc_CprofPccIconGetEncodingType
 */
ZFUNC ZINT Mtc_CprofPccIconSetEncodingType(ZUINT iType);

/**
 * @brief Get the pcc icon description.
 *
 * @return The description.
 *
 * @see Mtc_CprofPccIconSetDesc
 */
ZFUNC ZCHAR * Mtc_CprofPccIconGetDesc();

/**
 * @brief Set the pcc icon description.
 *
 * @param [in] pcDesc The description.
 *
 * @retval ZOK Set description successfully.
 * @retval ZFAILED Set description failed.
 *
 * @see Mtc_CprofPccIconGetDesc
 */
ZFUNC ZINT Mtc_CprofPccIconSetDesc(ZCHAR *pcDesc);

/**
 * @brief Get the pcc icon data.
 *
 * @return The data.
 *
 * @see Mtc_CprofPccIconSetData
 */
ZFUNC ZCHAR * Mtc_CprofPccIconGetData();

/**
 * @brief Set the pcc icon data.
 *
 * @param [in] pcData The data.
 *
 * @retval ZOK Set data successfully.
 * @retval ZFAILED Set data failed.
 *
 * @see Mtc_CprofPccIconGetData
 */
ZFUNC ZINT Mtc_CprofPccIconSetData(ZCHAR *pcData);

/**
 * @brief Get the pcc icon X-Resolution type.
 *
 * @return The X-Resolution type, @see @ref EN_MTC_CPROF_XRESOLUTION_TYPE.
 */
ZFUNC ZUINT Mtc_CprofPccIconGetXResolution();

/**
 * @brief Get the pcc icon etag.
 *
 * @return The etag.
 */
ZFUNC ZCHAR * Mtc_CprofPccIconGetEtag();

/**
 * @brief Get the pcc icon export file.
 *
 * @param [in] pcFileName The file name with path.
 *
 * @retval ZOK Export file successfully.
 * @retval ZFAILED Export file failed.
 *
 * @see Mtc_CprofPccIconImportFile
 */
ZFUNC ZINT Mtc_CprofPccIconExportFile(ZCHAR *pcFileName);

/**
 * @brief Get the pcc icon import file.
 *
 * @param [in] pcFileName The file name with path.
 *
 * @retval ZOK Import file successfully.
 * @retval ZFAILED Import file failed.
 *
 * @see Mtc_CprofPccIconExportFile
 */
ZFUNC ZINT Mtc_CprofPccIconImportFile(ZCHAR *pcFileName);

/**
 * @brief Get the qr card business flag.
 *
 * @return The business flag.
 *
 * @see Mtc_CprofQrCardSetBusinessFlag
 */
ZFUNC ZBOOL Mtc_CprofQrCardGetBusinessFlag();

/**
 * @brief Set the qr card business flag.
 *
 * @param [in] bFlag The business flag.
 *
 * @retval ZOK Set business flag successfully.
 * @retval ZFAILED Set business flag failed.
 *
 * @see Mtc_CprofQrCardGetBusinessFlag
 */
ZFUNC ZINT Mtc_CprofQrCardSetBusinessFlag(ZBOOL bFlag);

/**
 * @brief Get the qr card content mime type.
 *
 * @return The mime type, @see @ref EN_MTC_CPROF_MIME_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardCttGetMimeType(ZFUNC_VOID);

/**
 * @brief Get the qr card content encoding type.
 *
 * @return The encoding type, @see @ref EN_MTC_CPROF_ENCODING_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardCttGetEncodingType(ZFUNC_VOID);

/**
 * @brief Get the qr card content description.
 *
 * @return The content description.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardCttGetDesc(ZFUNC_VOID);

/**
 * @brief Get the qr card content data.
 *
 * @return The content data.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardCttGetData(ZFUNC_VOID);

/**
 * @brief Get the qr card content export file.
 *
 * @param [in] pcFileName The file name with path.
 *
 * @retval ZOK Export file successfully.
 * @retval ZFAILED Export file failed.
 */
ZFUNC ZINT Mtc_CprofQrCardCttExportFile(ZCHAR *pcFileName);

/**
 * @brief Get the qr card pcc url.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The pcc url.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccGetUrl(ZUINT iTdcPccId);

/**
 * @brief Check the tdc pcc has vCard.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @retval ZTRUE Indicates the pcc has vCard.
 * @retval ZFALSE Indicates the pcc has not vCard.
 */
ZFUNC ZBOOL Mtc_CprofQrCardPccHasVcard(ZUINT iTdcPccId);

/**
 * @brief Get the tdc pcc vCard.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The pcc vCard.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccGetVcard(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc type.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The pcc type, @see @ref EN_MTC_CPROF_PCC_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccGetPccType(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc name size.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The name size.
 *
 * @see Mtc_CprofQrCardPccGetNameId
 */
ZFUNC ZINT Mtc_CprofQrCardPccGetNameSize(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc name id by index.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 * @param [in] iIndex The name index.
 *
 * @return The name id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofQrCardPccGetNameSize
 */
ZFUNC ZUINT Mtc_CprofQrCardPccGetNameId(ZUINT iTdcPccId, ZUINT iIndex);

/**
 * @brief Get the qr card pcc given name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The given name.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccNameGetGiven(ZUINT iNameId);

/**
 * @brief Get the qr card pcc middle name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The middle name.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccNameGetMiddle(ZUINT iNameId);

/**
 * @brief Get the qr card pcc family name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The family name.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccNameGetFamily(ZUINT iNameId);

/**
 * @brief Get the qr card pcc display name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The display name.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccNameGetDispName(ZUINT iNameId);

/**
 * @brief Get the qr card pcc first name.
 *
 * @param [in] iNameId The name id.
 *
 * @return The first name.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccNameGetFirst(ZUINT iNameId);

/**
 * @brief Get the qr card pcc name type.
 *
 * @param [in] iNameId The name id.
 *
 * @return The name type, @see @ref EN_MTC_CPROF_PCC_NAME_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccNameGetType(ZUINT iNameId);

/**
 * @brief Get the qr card pcc name preference.
 *
 * @param [in] iNameId The name id.
 *
 * @return The name preference.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccNameGetPref(ZUINT iNameId);

/**
 * @brief Get the qr card pcc address size.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The address size.
 *
 * @see Mtc_CprofQrCardPccGetAddrId
 */
ZFUNC ZINT Mtc_CprofQrCardPccGetAddrSize(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc address id by index.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 * @param [in] iIndex The address index.
 *
 * @return The address id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofQrCardPccGetAddrSize
 */
ZFUNC ZUINT Mtc_CprofQrCardPccGetAddrId(ZUINT iTdcPccId, ZUINT iIndex);

/**
 * @brief Get the qr card pcc address label.
 *
 * @param [in] iAddrId The address id.
 *
 * @return The address label.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccAddrGetLabel(ZUINT iAddrId);

/**
 * @brief Get the qr card pcc address string.
 *
 * @param [in] iAddrId The address id.
 *
 * @return The address string.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccAddrGetAddr(ZUINT iAddrId);

/**
 * @brief Get the qr card pcc address type.
 *
 * @param [in] iAddrId The address id.
 *
 * @return The address type, @see @ref EN_MTC_CPROF_PCC_ADDR_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccAddrGetType(ZUINT iAddrId);

/**
 * @brief Get the qr card pcc address preference.
 *
 * @param [in] iAddrId The address id.
 *
 * @return The address preference.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccAddrGetPref(ZUINT iAddrId);

/**
 * @brief Get the qr card pcc media size.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The media size.
 *
 * @see Mtc_CprofQrCardPccGetMediaId
 */
ZFUNC ZINT Mtc_CprofQrCardPccGetMediaSize(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc media id by index.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 * @param [in] iIndex The media index.
 *
 * @return The media id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofQrCardPccGetMediaSize
 */
ZFUNC ZUINT Mtc_CprofQrCardPccGetMediaId(ZUINT iTdcPccId, ZUINT iIndex);

/**
 * @brief Get the qr card pcc media label.
 *
 * @param [in] iMediaId The media id.
 *
 * @return The media label.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccMediaGetLabel(ZUINT iMediaId);

/**
 * @brief Get the qr card pcc media url.
 *
 * @param [in] iMediaId The media id.
 *
 * @return The media url.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccMediaGetMediaUrl(ZUINT iMediaId);

/**
 * @brief Get the qr card pcc media type.
 *
 * @param [in] iMediaId The media id.
 *
 * @return The media type.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccMediaGetType(ZUINT iMediaId);

/**
 * @brief Get the qr card pcc media preference.
 *
 * @param [in] iMediaId The media id.
 *
 * @return The media preference.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccMediaGetPref(ZUINT iMediaId);

/**
 * @brief Get the qr card pcc uri size.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The uri size.
 *
 * @see Mtc_CprofQrCardPccCommAddrGetUriId
 */
ZFUNC ZINT Mtc_CprofQrCardPccCommAddrGetUriSize(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc uri id by index.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 * @param [in] iIndex The uri index.
 *
 * @return The uri id successfully or ZMAXUINT failed.
 *
 * @see Mtc_CprofQrCardPccCommAddrGetUriSize
 */
ZFUNC ZUINT Mtc_CprofQrCardPccCommAddrGetUriId(ZUINT iTdcPccId, ZUINT iIndex);

/**
 * @brief Get the qr card pcc uri label.
 *
 * @param [in] iUriId The uri id.
 *
 * @return The uri label.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccUriGetLabel(ZUINT iUriId);

/**
 * @brief Get the qr card pcc uri string.
 *
 * @param [in] iUriId The uri id.
 *
 * @return The uri string.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccUriGetUri(ZUINT iUriId);

/**
 * @brief Get the qr card pcc uri type.
 *
 * @param [in] iUriId The uri id.
 *
 * @return The uri type, @see @ref EN_MTC_CPROF_PCC_URI_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccUriGetType(ZUINT iUriId);

/**
 * @brief Get the qr card pcc uri preference.
 *
 * @param [in] iUriId The uri id.
 *
 * @return The uri preference.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccUriGetPref(ZUINT iUriId);

/**
 * @brief Get the qr card pcc tel size.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The tel size.
 */
ZFUNC ZINT Mtc_CprofQrCardPccCommAddrGetTelSize(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc tel id by index.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 * @param [in] iIndex The tel index.
 *
 * @return The tel id successfully or ZMAXUINT failed.
 *
 * @see Rpe_PccCommAddrGetTelSize
 */
ZFUNC ZUINT Mtc_CprofQrCardPccCommAddrGetTelId(ZUINT iTdcPccId, ZUINT iIndex);

/**
 * @brief Get the qr card pcc tel label.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The tel label.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccTelGetLabel(ZUINT iTelId);

/**
 * @brief Get the qr card pcc tel string.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The tel string.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccTelGetTel(ZUINT iTelId);

/**
 * @brief Get the qr card pcc tel type.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The tel type, @see @ref EN_MTC_CPROF_PCC_TEL_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccTelGetTelType(ZUINT iTelId);

/**
 * @brief Get the qr card pcc xui type.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The xui type, @see @ref EN_MTC_CPROF_PCC_XUI_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccTelGetXuiType(ZUINT iTelId);

/**
 * @brief Get the qr card pcc tel preference.
 *
 * @param [in] iTelId The tel id.
 *
 * @return The tel preference.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccTelGetPref(ZUINT iTelId);

/**
 * @brief Get the qr card pcc birth date.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The birth date.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccBirthGetDate(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc birth non-gregorian.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The birth non-gregorian.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccBirthGetNonGregDate(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc birth place.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The birth place.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccBirthGetPlace(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc birth calendars type.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The calendars type, @see @ref EN_MTC_CPROF_PCC_CAL_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccBirthGetCalType(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc career employer.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The career employer.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccCareerGetEmployer(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc career duty.
 *
 * @param [in] iTdcPccId The qr card pcc id.
 *
 * @return The career duty.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccCareerGetDuty(ZUINT iTdcPccId);

/**
 * @brief Get the qr card pcc icon uri.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @return The icon uri.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccIconGetUri(ZUINT iIconId);

/**
 * @brief Get the qr card pcc icon X-Resolution.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @return The icon X-Resolution type, @see @ref EN_MTC_CPROF_XRESOLUTION_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccIconGetXResolution(ZUINT iIconId);

/**
 * @brief Get the qr card pcc icon etag.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @return The icon etag.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccIconGetEtag(ZUINT iIconId);

/**
 * @brief Get the qr card pcc icon mime type.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @return The mime type, @see @ref EN_MTC_CPROF_MIME_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccIconGetMimeType(ZUINT iIconId);

/**
 * @brief Get the qr card pcc icon encoding type.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @return The encoding type, @see @ref EN_MTC_CPROF_ENCODING_TYPE.
 */
ZFUNC ZUINT Mtc_CprofQrCardPccIconGetEncodingType(ZUINT iIconId);

/**
 * @brief Get the qr card pcc icon description.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @return The icon description.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccIconGetDesc(ZUINT iIconId);

/**
 * @brief Get the qr card pcc icon data.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @return The icon data.
 *   The caller must copy it, then use.
 */
ZFUNC ZCHAR * Mtc_CprofQrCardPccIconGetData(ZUINT iIconId);

/**
 * @brief Check has the qr card pcc icon data.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @return ZTRUE if exist icon data, otherwise ZFALSE.
 */
ZFUNC ZBOOL Mtc_CprofQrCardPccIconHasData(ZUINT iIconId);

/**
 * @brief Clear the qr card pcc icon data.
 *
 * @param [in] iIconId The qr card pcc icon id.
 *
 * @retval ZOK Clear icon data successfully.
 * @retval ZFAILED Clear icon data failed.
 */
ZFUNC ZINT Mtc_CprofQrCardPccIconClrData(ZUINT iIconId);

/**
 * @brief Get the qr card pcc icon export file.
 *
 * @param [in] iIconId The qr card pcc icon id.
 * @param [in] pcFileName The file name with path.
 *
 * @retval ZOK Export file successfully.
 * @retval ZFAILED Export file failed.
 */
ZFUNC ZINT Mtc_CprofQrCardPccIconExportFile(ZUINT iIconId, 
                ZCHAR *pcFileName);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CPROF_H__ */

