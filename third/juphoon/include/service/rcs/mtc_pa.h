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
  File name     : mtc_pa.h
  Module        : multimedia talk client
  Author        : nero.fang
  Created on    : 2014-09-30
  Description   :
      Function implement required by MTC public account.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_PA_H__
#define _MTC_PA_H__

/**
 * @file mtc_pa.h
 * @brief MTC CMCC Public Account Interface Functions
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC public account status code. */
#define MTC_PA_ERR_NO               (MTC_EBASE_PA + 0) /**< @brief no error */
#define MTC_PA_ERR_AUTH_FAILED      (MTC_EBASE_PA + 1) /**< @brief authentication failed, invalid user or password */
#define MTC_PA_ERR_CONN_FAILED      (MTC_EBASE_PA + 2) /**< @brief transport connect failed */
#define MTC_PA_ERR_SEND_FAILED      (MTC_EBASE_PA + 3) /**< @brief transport send failed */
#define MTC_PA_ERR_RECV_FAILED      (MTC_EBASE_PA + 4) /**< @brief transport received failed */
#define MTC_PA_ERR_SERV_DISCED      (MTC_EBASE_PA + 5) /**< @brief transport disconnected by server */
#define MTC_PA_ERR_SERV_ERR         (MTC_EBASE_PA + 6) /**< @brief server internal error */
#define MTC_PA_ERR_REQ_TIMEOUT      (MTC_EBASE_PA + 7) /**< @brief request timeout */
#define MTC_PA_ERR_BAD_XML_MSG      (MTC_EBASE_PA + 8) /**< @brief bad xml message */
#define MTC_PA_ERR_FORBIDDEN        (MTC_EBASE_PA + 9) /**< @brief forbidden */
#define MTC_PA_ERR_RESULT           (MTC_EBASE_PA + 10) /**< @brief server result */
#define MTC_PA_ERR_OTHER            (MTC_EBASE_PA + 11) /**< @brief other */

/** @brief MTC public account media type */
typedef enum EN_MTC_PA_MEDIA_TYPE
{
    EN_MTC_PA_MEDIA_UNKNOWN,         /**< @brief unknown message */
    EN_MTC_PA_MEDIA_TXT,             /**< @brief text message */
    EN_MTC_PA_MEDIA_TMPL,            /**< @brief template message */
    EN_MTC_PA_MEDIA_VCARD,           /**< @brief vCard message */
    EN_MTC_PA_MEDIA_GEO,             /**< @brief geolocation message */
    EN_MTC_PA_MEDIA_PIC,             /**< @brief picture message */
    EN_MTC_PA_MEDIA_VIDEO,           /**< @brief video message */
    EN_MTC_PA_MEDIA_AUDIO,           /**< @brief audio message */
    EN_MTC_PA_MEDIA_SART,            /**< @brief single article message */
    EN_MTC_PA_MEDIA_MART,            /**< @brief multi-article message */
    EN_MTC_PA_MEDIA_CARD,            /**< @brief card message */
    EN_MTC_PA_MEDIA_SMS,             /**< @brief SMS message */
    EN_MTC_PA_MEDIA_SUBLST_UPDT,     /**< @brief subsribe list update message */
    EN_MTC_PA_MEDIA_DETAIL_UPDT,     /**< @brief detail update message */
} EN_MTC_PA_MEDIA_TYPE;

/** @brief MTC pubilc account type */
typedef enum EN_MTC_PA_TYPE
{
    EN_MTC_PA_UNKNOWN,               /**< @brief unknown type */
    EN_MTC_PA_HOT,                   /**< @brief hot type */
    EN_MTC_PA_READ,                  /**< @brief read type */
    EN_MTC_PA_STAR,                  /**< @brief star type */
    EN_MTC_PA_FOOD,                  /**< @brief food type */
    EN_MTC_PA_CORP,                  /**< @brief corporation type */
    EN_MTC_PA_SOCAIL,                /**< @brief social type */
    EN_MTC_PA_GAME,                  /**< @brief game type */
    EN_MTC_PA_MUSIC,                 /**< @brief music type */
    EN_MTC_PA_EDU,                   /**< @brief education type */
    EN_MTC_PA_OTHER = 99,            /**< @brief other type */
} EN_MTC_PA_TYPE;

/** @brief MTC pubilc account recommand level type */
typedef enum EN_MTC_PA_RECMD_LV_TYPE
{
    EN_MTC_PA_RECMD_LV_UNKNOWN,      /**< @brief level unknown type */
    EN_MTC_PA_RECMD_LV_ONE,          /**< @brief level one type */
    EN_MTC_PA_RECMD_LV_TWO,          /**< @brief level two type */
    EN_MTC_PA_RECMD_LV_THREE,        /**< @brief level three type */
    EN_MTC_PA_RECMD_LV_FOUR,         /**< @brief level four type */
    EN_MTC_PA_RECMD_LV_FIVE,         /**< @brief level five type */
} EN_MTC_PA_RECMD_LV_TYPE;

/** @brief MTC pubilc account menu command type */
typedef enum EN_MTC_PA_MENU_CMD_TYPE
{
    EN_MTC_PA_MENU_CMD_SMLT_MSG,     /**< @brief simulative message type */
    EN_MTC_PA_MENU_CMD_LINK,         /**< @brief link type */
    EN_MTC_PA_MENU_CMD_DEV_API,      /**< @brief device API type */
    EN_MTC_PA_MENU_CMD_APP_API,      /**< @brief application API type */
} EN_MTC_PA_MENU_CMD_TYPE;

/** @brief MTC public account id type */
typedef enum EN_MTC_PA_ID_TYPE
{
    EN_MTC_PA_ID_UNKNOWN,            /**< @brief unknown type */
    EN_MTC_PA_ID_COMPANY,            /**< @brief company type */
    EN_MTC_PA_ID_PERSONAL,           /**< @brief personal type */
} EN_MTC_PA_ID_TYPE;

/** @brief MTC public account color type */
typedef enum EN_MTC_PA_COLOR_TYPE
{
    EN_MTC_PA_COLOR_UNKNOWN,         /**< @brief unknown type */
    EN_MTC_PA_COLOR_RED,             /**< @brief RGB(255,0,24) #ff0018 */
    EN_MTC_PA_COLOR_DARKRED,         /**< @brief RGB(152,42,42) #982a2a */
    EN_MTC_PA_COLOR_ORANGE,          /**< @brief RGB(255,120,0) #ff7800 */
    EN_MTC_PA_COLOR_YELLOW,          /**< @brief RGB(255,192,0) #ffc000 */
    EN_MTC_PA_COLOR_GREEN,           /**< @brief RGB(0,213,85) #00d555 */
    EN_MTC_PA_COLOR_BLUE,            /**< @brief RGB(0,120,255) #0078ff */
    EN_MTC_PA_COLOR_DARKBLUE,        /**< @brief RGB(29,50,155) #1d3273 */
    EN_MTC_PA_COLOR_PURPLE,          /**< @brief RGB(154,72,255) #9a48ff */
    EN_MTC_PA_COLOR_PINK,            /**< @brief RGB(253,93,255) #fd5dff */
    EN_MTC_PA_COLOR_DEEPPINK,        /**< @brief RGB(190,39,128) #be2780 */
    EN_MTC_PA_COLOR_GRAY,            /**< @brief RGB(204,204,204) #CCCCCC */
    EN_MTC_PA_COLOR_DARKGRAY,        /**< @brief RGB(133,133,133) #858585 */
    EN_MTC_PA_COLOR_BLACK,           /**< @brief RGB(0,0,0) #000000 */
    EN_MTC_PA_COLOR_WHITE,           /**< @brief RGB(255,255,255) #ffffff */
} EN_MTC_PA_COLOR_TYPE;

/**
 * @brief The public account add subscribe.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaAddSubsOk or @ref Mtc_PaCbSetPaAddSubsFailed.
 *
 * @param [in] pcPaUuid The pa uuid.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessAddSubs(ZCHAR *pcPaUuid);

/**
 * @brief The public account cancle subscribe.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaCancelSubsOk or @ref Mtc_PaCbSetPaCancelSubsFailed.
 *
 * @param [in] pcPaUuid The pa uuid.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessCancelSubs(ZCHAR *pcPaUuid);

/**
 * @brief The public accounts query user subscribed.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaQryUsrSubsOk or @ref Mtc_PaCbSetPaQryUsrSubsFailed.
 *
 * @param [in] iOrder The public account list sorting strategy, 
 *             value 0 indicates order by subscribed time desc, 
 *             value 1 indicates ordey by name.
 * @param [in] iPageSize The public account id number each page.
 * @param [in] iPageNum The public account list pagination.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessQryUsrSubs(ZUINT iOrder, ZUINT iPageSize, 
                ZUINT iPageNum);

/**
 * @brief The public account get public list.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaGetPubLstOk or @ref Mtc_PaCbSetPaGetPubLstFailed.
 *
 * @param [in] pcKeyword The public account search keyword.
 * @param [in] iOrder The public account list sorting strategy.
 *             value 0 indicates order by subscribed time desc, 
 *             value 1 indicates ordey by name.
 * @param [in] iPageSize The public account id number each page.
 * @param [in] iPageNum The public account list pagination.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessGetPubLst(ZCHAR *pcKeyword, ZUINT iOrder, 
                ZUINT iPageSize, ZUINT iPageNum);

/**
 * @brief The public account get public list recommend.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaGetPubLstRecmdOk or @ref Mtc_PaCbSetPaGetPubLstRecmdFailed.
 *
 * @param [in] iType The public source type, @see @ref EN_MTC_PA_TYPE.
 * @param [in] iPageSize The public account id number each page.
 * @param [in] iPageNum The public account list pagination.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessGetPubLstRecmd(ZUINT iType, ZUINT iPageSize, 
                ZUINT iPageNum);

/**
 * @brief The public account get public detail.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaGetPubDetailOk or @ref Mtc_PaCbSetPaGetPubDetailFailed.
 *
 * @param [in] pcPaUuid The public account unique id.
 * @param [in] zUpdTime The public account detail last update time.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessGetPubDetail(ZCHAR *pcPaUuid, ZTIME_T zUpdTime);

/**
 * @brief The public account get public menu.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaGetPubMenuOk or @ref Mtc_PaCbSetPaGetPubMenuFailed.
 *
 * @param [in] pcPaUuid The public account unique id.
 * @param [in] zTimestamp The public account menu last update time.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessGetPubMenu(ZCHAR *pcPaUuid, ZTIME_T zTimestamp);

/**
 * @brief The public accounts get previous message.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaGetPrevMsgOk or @ref Mtc_PaCbSetPaGetPrevMsgFailed.
 *
 * @param [in] pcPaUuid The public account unique id.
 * @param [in] zTimestamp The public account query message start time.
 * @param [in] iOrder The public account query message time direction.
 * @param [in] iPageSize The public account id number each page.
 * @param [in] iPageNum The public account query message number.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessGetPrevMsg(ZCHAR *pcPaUuid, ZTIME_T zTimestamp, 
                ZUINT iOrder, ZUINT iPageSize, ZUINT iPageNum);

/**
 * @brief The public accounts complain public.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaComplainPubOk or @ref Mtc_PaCbSetPaComplainPubFailed.
 *
 * @param [in] pcPaUuid The public account unique id.
 * @param [in] iType The public account complain type,
 *             value 1 indicates complain public account,
 *             value 2 indicates complain public message.
 * @param [in] pcReason The public account complain reason.
 * @param [in] pcData The public message data, mandatory if iType euqal 2.
 * @param [in] pcDesc The public account behavior description, option.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessComplainPub(ZCHAR *pcPaUuid, ZUINT iType, 
                ZCHAR *pcReason, ZCHAR *pcData, ZCHAR *pcDesc);

/**
 * @brief The public accounts set accept status.
 * 
 * The result will be notified by callbacks which were set by 
 * @ref Mtc_PaCbSetPaComplainPubOk or @ref Mtc_PaCbSetPaComplainPubFailed.
 *
 * @param [in] pcPaUuid The public account unique id.
 * @param [in] pcReason The public account complain reason.
 * @param [in] pcDesc The public account behavior description.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessSetAcptStat(ZCHAR *pcPaUuid, ZBOOL bAcptStat);

/**
 * @brief The public accounts format text to xml message.
 * 
 * @param [in] pcText The text message.
 *
 * @return The xml message.
 */
ZFUNC ZCHAR * Mtc_PaSessEncodeMsg(ZCHAR *pcText);

/**
 * @brief The public accounts decode public account xml message.
 * 
 * @param [in] pcMsg The public account xml message.
 *
 * @return The public account session id when successfully, otherwise return ZMAXUINT.
 *  When used completely, caller must release session, @see @ref Mtc_PaSessRelease.
 */
ZFUNC ZUINT Mtc_PaSessDecodeMsg(ZCHAR *pcXmlMsg);

/**
 * @brief The public accounts session release.
 *
 * @param [in] iSessId The session id.
 */
ZFUNC ZVOID Mtc_PaSessRelease(ZUINT iSessId);

/**
 * @brief The public accounts get xml message.
 *
 * @param [in] iSessId The session id.
 *
 * @return The xml message.
 */
ZFUNC ZCHAR * Mtc_PaSessGetXmlMsg(ZUINT iSessId);

/**
 * @brief The public accounts get pa size.
 *
 * @param [in] iSessId The session id.
 *
 * @return The pa size.
 */
ZFUNC ZINT Mtc_PaSessGetPaSize(ZUINT iSessId);

/**
 * @brief The public accounts get pa size.
 *
 * @param [in] iSessId The session id.
 * @param [in] iIndex The pa index.
 *
 * @return The pa id successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessGetPaId(ZUINT iSessId, ZINT iIndex);

/**
 * @brief Get public account the menu size.
 *
 * @param [in] iSessId The session id.
 *
 * @return The menu size.
 */
ZFUNC ZUINT Mtc_PaSessGetMenuSize(ZUINT iSessId);

/**
 * @brief Get public account menu id.
 *
 * @param [in] iSessId The session id.
 * @param [in] iIndex The menu index.
 *
 * @return The menu id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessGetMenuId(ZUINT iSessId, ZINT iIndex);

/**
 * @brief Get public account the message size.
 *
 * @param [in] iSessId The session id.
 *
 * @return The message size.
 */
ZFUNC ZUINT Mtc_PaSessGetMsgSize(ZUINT iSessId);

/**
 * @brief Get public account message id.
 *
 * @param [in] iSessId The session id.
 * @param [in] iIndex The message index.
 *
 * @return The message id when successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaSessGetMsgId(ZUINT iSessId, ZINT iIndex);

/**
 * @brief Get public account session result.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account session result.
 */
ZFUNC ZCHAR * Mtc_PaSessGetResult(ZUINT iSessId);

/**
 * @brief Get public account session pa uuid.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account uuid.
 */
ZFUNC ZCHAR * Mtc_PaSessGetPaUuid(ZUINT iSessId);

/**
 * @brief Check public account session has data.
 *
 * @param [in] iSessId The session id.
 *
 * @return The has data flag.
 */
ZFUNC ZBOOL Mtc_PaSessHasData(ZUINT iSessId);

/**
 * @brief Get public account uuid.
 *
 * @param [in] iPaId The public account id.
 *
 * @return The public account unique id.
 */
ZFUNC ZCHAR * Mtc_PaBscGetPaUuid(ZUINT iPaId);

/**
 * @brief Get public account name.
 *
 * @param [in] iPaId The public account id.
 *
 * @return The public account name.
 */
ZFUNC ZCHAR * Mtc_PaBscGetName(ZUINT iPaId);

/**
 * @brief Get public account recommend level.
 *
 * @param [in] iPaId The public account id.
 *
 * @return The public account recommend level, @see @ref EN_MTC_PA_RECMD_LV_TYPE.
 */
ZFUNC ZUINT Mtc_PaBscGetRecmdLv(ZUINT iPaId);

/**
 * @brief Get public account logo url.
 *
 * @param [in] iPaId The public account id.
 *
 * @return The public account logo url.
 */
ZFUNC ZCHAR * Mtc_PaBscGetLogoUrl(ZUINT iPaId);

/**
 * @brief Get public account introduce.
 *
 * @param [in] iPaId The public account id.
 *
 * @return The public account introduce.
 */
ZFUNC ZCHAR * Mtc_PaBscGetIntro(ZUINT iPaId);

/**
 * @brief Get public account id type.
 *
 * @param [in] iPaId The public account id.
 *
 * @return The public account id type.
 */
ZFUNC ZUINT Mtc_PaBscGetIdType(ZUINT iPaId);

/**
 * @brief Get public account subscribe status.
 *
 * @param [in] iPaId The public account id.
 *
 * @return 1 when public account have subscribed, otherwise return 0.
 */
ZFUNC ZUINT Mtc_PaBscGetSubsStat(ZUINT iPaId);

/**
 * @brief Get public account uuid.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account unique id.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetPaUuid(ZUINT iSessId);

/**
 * @brief Get public account name.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account name.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetName(ZUINT iSessId);

/**
 * @brief Get public account authentication company.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account authentication company.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetCompany(ZUINT iSessId);

/**
 * @brief Get public account introduce.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account introduce.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetIntro(ZUINT iSessId);

/**
 * @brief Get public account the last information update time.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account update time.
 */
ZFUNC ZTIME_T Mtc_PaDetailGetUpdTime(ZUINT iSessId);

/**
 * @brief Get public account the menu timestamp.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account menu timestamp.
 */
ZFUNC ZTIME_T Mtc_PaDetailGetMenuTimestamp(ZUINT iSessId);

/**
 * @brief Get public account type.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account type.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetType(ZUINT iSessId);

/**
 * @brief Get public account recommend level type.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account recommend level type, @see @ref EN_MTC_PA_RECMD_LV_TYPE.
 */
ZFUNC ZUINT Mtc_PaDetailGetRecmdLv(ZUINT iSessId);

/**
 * @brief Get public account id type.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account id type, @see @ref EN_MTC_PA_ID_TYPE.
 */
ZFUNC ZUINT Mtc_PaDetailGetIdType(ZUINT iSessId);

/**
 * @brief Get public account menu type.
 *
 * @param [in] iSessId The session id.
 *
 * @return 1 when public account have menu setting, otherwise return 0.
 */
ZFUNC ZUINT Mtc_PaDetailGetMenuType(ZUINT iSessId);

/**
 * @brief The public account subscribe status.
 *
 * @param [in] iSessId The session id.
 *
 * @return 1 when public account have subscribed, otherwise return 0.
 */
ZFUNC ZUINT Mtc_PaDetailGetSubsStat(ZUINT iSessId);

/**
 * @brief The public account accept satus.
 *
 * @param [in] iSessId The session id.
 *
 * @return 1 when client accept public account pushed, otherwise return 0.
 */
ZFUNC ZUINT Mtc_PaDetailGetAcptStat(ZUINT iSessId);

/**
 * @brief The public account active satus.
 *
 * @param [in] iSessId The session id.
 *
 * @retval 0 Indicates public account is active status, 
 * @retval 1 Indicates public account is paused status.
 * @retval 2 Indicates public account is closed status.
 */
ZFUNC ZUINT Mtc_PaDetailGetActiveStat(ZUINT iSessId);

/**
 * @brief The public account tel.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account tel.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetTel(ZUINT iSessId);

/**
 * @brief The public account email.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account email.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetEmail(ZUINT iSessId);

/**
 * @brief The public account zip.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account zip.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetZip(ZUINT iSessId);

/**
 * @brief The public account address.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account address.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetAddr(ZUINT iSessId);

/**
 * @brief The public account field.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account field.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetField(ZUINT iSessId);

/**
 * @brief Get public account logo url.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account logo url.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetLogoUrl(ZUINT iSessId);

/**
 * @brief Get public account qrcode.
 *
 * @param [in] iSessId The session id.
 *
 * @return The public account qrcode.
 */
ZFUNC ZCHAR * Mtc_PaDetailGetQrCode(ZUINT iSessId);

/**
 * @brief Get public account menu command id.
 *
 * @param [in] iMenuId The menu id.
 *
 * @return The public account menu command id.
 */
ZFUNC ZCHAR * Mtc_PaMenuGetCmdId(ZUINT iMenuId);

/**
 * @brief Get public account menu command type.
 *
 * @param [in] iMenuId The menu id.
 *
 * @return The public account menu command type, @see @ref EN_MTC_PA_MENU_CMD_TYPE.
 */
ZFUNC ZUINT Mtc_PaMenuGetCmdType(ZUINT iMenuId);

/**
 * @brief Get public account menu title.
 *
 * @param [in] iMenuId The menu id.
 *
 * @return The public account menu title.
 */
ZFUNC ZCHAR * Mtc_PaMenuGetTitle(ZUINT iMenuId);

/**
 * @brief Get public account menu priority.
 *
 * @param [in] iMenuId The menu id.
 *
 * @return The public account menu priority.
 */
ZFUNC ZUINT Mtc_PaMenuGetPriority(ZUINT iMenuId);

/**
 * @brief Get public account submenu size.
 *
 * @param [in] iMenuId The menu id.
 *
 * @return The public account submenu size.
 */
ZFUNC ZUINT Mtc_PaMenuGetSubmenuSize(ZUINT iMenuId);

/**
 * @brief Get public account submenu size.
 *
 * @param [in] iMenuId The menu id.
 * @param [in] iIndex The submenu index.
 *
 * @return The public account submenu id successfully, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaMenuGetSubmenuId(ZUINT iMenuId, ZINT iIndex);

/**
 * @brief Get public account message media type.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account message media type, @see @ref EN_MTC_PA_MEDIA_TYPE.
 */
ZFUNC ZUINT Mtc_PaMsgGetMediaType(ZUINT iMsgId);

/**
 * @brief Get public account message unique id.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account message unique id.
 */
ZFUNC ZCHAR * Mtc_PaMsgGetMsgUuid(ZUINT iMsgId);

/**
 * @brief Get public account unique id.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account unique id.
 */
ZFUNC ZCHAR * Mtc_PaMsgGetPaUuid(ZUINT iMsgId);

/**
 * @brief Get public account short message digest.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account short message digest.
 */
ZFUNC ZCHAR * Mtc_PaMsgGetSmsDigest(ZUINT iMsgId);

/**
 * @brief Get public account text message.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account text message.
 */
ZFUNC ZCHAR * Mtc_PaMsgGetText(ZUINT iMsgId);

/**
 * @brief Get public account message create time.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account message create time.
 */
ZFUNC ZTIME_T Mtc_PaMsgGetCreateTime(ZUINT iMsgId);

/**
 * @brief Get public account message active status.
 *
 * @param [in] iMsgId The message id.
 *
 * @retval 0 Indicates public account is active status, 
 * @retval 1 Indicates public account is paused status.
 * @retval 2 Indicates public account is closed status.
 */
ZFUNC ZUINT Mtc_PaMsgGetActiveStat(ZUINT iMsgId);

/**
 * @brief Get public account message forwordable.
 *
 * @param [in] iMsgId The message id.
 *
 * @return 0 when message is forwordable, otherwise return 1.
 */
ZFUNC ZUINT Mtc_PaMsgGetFwdable(ZUINT iMsgId);

/**
 * @brief Get public account geolocation information id.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account geolocation information id on succeed, otherwise return ZMAXUINT.
 */
ZFUNC ZUINT Mtc_PaMsgGetGInfoId(ZUINT iMsgId);

/**
 * @brief Get public account article message size.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account article message size.
 */
ZFUNC ZINT Mtc_PaMsgGetArtMsgSize(ZUINT iMsgId);

/**
 * @brief Get public account article message size.
 *
 * @param [in] iMsgId The message id.
 *
 * @return Thepublic account article message id.
 */
ZFUNC ZUINT Mtc_PaMsgGetArtMsgId(ZUINT iMsgId, ZINT iIndex);

/**
 * @brief Get public account article message title.
 *
 * @param [in] iArtMsgId The article message id.
 *
 * @return The public account article message title.
 */
ZFUNC ZCHAR * Mtc_PaArtMsgGetTitle(ZUINT iArtMsgId);

/**
 * @brief Get public account article message author.
 *
 * @param [in] iArtMsgId The article message id.
 *
 * @return The public account article message author.
 */
ZFUNC ZCHAR * Mtc_PaArtMsgGetAuthor(ZUINT iArtMsgId);

/**
 * @brief Get public account article message thumb link.
 *
 * @param [in] iArtMsgId The article message id.
 *
 * @return The public account article message thumb link.
 */
ZFUNC ZCHAR * Mtc_PaArtMsgGetThumbLink(ZUINT iArtMsgId);

/**
 * @brief Get public account article message original link.
 *
 * @param [in] iArtMsgId The article message id.
 *
 * @return The public account article message original link.
 */
ZFUNC ZCHAR * Mtc_PaArtMsgGetOrigLink(ZUINT iArtMsgId);

/**
 * @brief Get public account article message body link.
 *
 * @param [in] iArtMsgId The article message id.
 *
 * @return The public account article message body link.
 */
ZFUNC ZCHAR * Mtc_PaArtMsgGetBodyLink(ZUINT iArtMsgId);

/**
 * @brief Get public account article message source link.
 *
 * @param [in] iArtMsgId The article message id.
 *
 * @return The public account article message source link.
 */
ZFUNC ZCHAR * Mtc_PaArtMsgGetSrcLink(ZUINT iArtMsgId);

/**
 * @brief Get public account article message main text.
 *
 * @param [in] iArtMsgId The article message id.
 *
 * @return The public account article message main text.
 */
ZFUNC ZCHAR * Mtc_PaArtMsgGetMainText(ZUINT iArtMsgId);

/**
 * @brief Get public account article message media unique id.
 *
 * @param [in] iArtMsgId The article message id.
 *
 * @return The public account article message media unique id.
 */
ZFUNC ZCHAR * Mtc_PaArtMsgGetMediaUuid(ZUINT iArtMsgId);

/**
 * @brief Get public account basic message title.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account basic message title.
 */
ZFUNC ZCHAR * Mtc_PaBscMsgGetTitle(ZUINT iMsgId);

/**
 * @brief Get public account basic message file size.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account basic message file size.
 */
ZFUNC ZUINT Mtc_PaBscMsgGetFileSize(ZUINT iMsgId);

/**
 * @brief Get public account basic message file type.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account basic message file type.
 */
ZFUNC ZCHAR * Mtc_PaBscMsgGetFileType(ZUINT iMsgId);

/**
 * @brief Get public account basic message file duration.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account basic message file duration.
 */
ZFUNC ZUINT Mtc_PaBscMsgGetFileDuration(ZUINT iMsgId);

/**
 * @brief Get public account basic message thumb link.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account basic message thumb link.
 */
ZFUNC ZCHAR * Mtc_PaBscMsgGetThumbLink(ZUINT iMsgId);

/**
 * @brief Get public account basic message original link.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account basic message original link.
 */
ZFUNC ZCHAR * Mtc_PaBscMsgGetOrigLink(ZUINT iMsgId);

/**
 * @brief Get public account basic message media unique id.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account basic message media unique id.
 */
ZFUNC ZCHAR * Mtc_PaBscMsgGetMediaUuid(ZUINT iMsgId);

/**
 * @brief Get public account basic message create time.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account basic message create time.
 */
ZFUNC ZTIME_T Mtc_PaBscMsgGetCreateTime(ZUINT iMsgId);

/**
 * @brief Get public account card message title.
 *
 * @param [in] iMsgId The card message id.
 *
 * @return The public account card message title.
 */
ZFUNC ZCHAR * Mtc_PaCardMsgGetTitle(ZUINT iMsgId);

/**
 * @brief Get public account card message author.
 *
 * @param [in] iMsgId The card message id.
 *
 * @return The public account card message author.
 */
ZFUNC ZCHAR * Mtc_PaCardMsgGetAuthor(ZUINT iMsgId);

/**
 * @brief Get public account card message thumb link.
 *
 * @param [in] iMsgId The card message id.
 *
 * @return The public account card message thumb link.
 */
ZFUNC ZCHAR * Mtc_PaCardMsgGetThumbLink(ZUINT iMsgId);

/**
 * @brief Get public account card message original link.
 *
 * @param [in] iMsgId The card message id.
 *
 * @return The public account card message original link.
 */
ZFUNC ZCHAR * Mtc_PaCardMsgGetOrigLink(ZUINT iMsgId);

/**
 * @brief Get public account card message body link.
 *
 * @param [in] iMsgId The card message id.
 *
 * @return The public account card message body link.
 */
ZFUNC ZCHAR * Mtc_PaCardMsgGetBodyLink(ZUINT iMsgId);

/**
 * @brief Get public account card message source link.
 *
 * @param [in] iMsgId The card message id.
 *
 * @return The public account card message source link.
 */
ZFUNC ZCHAR * Mtc_PaCardMsgGetSrcLink(ZUINT iMsgId);

/**
 * @brief Get public account card message main text.
 *
 * @param [in] iMsgId The card message id.
 *
 * @return The public account card message main text.
 */
ZFUNC ZCHAR * Mtc_PaCardMsgGetMainText(ZUINT iMsgId);

/**
 * @brief Get public account card message media unique id.
 *
 * @param [in] iMsgId The card message id.
 *
 * @return The public account card message media unique id.
 */
ZFUNC ZCHAR * Mtc_PaCardMsgGetMediaUuid(ZUINT iMsgId);

/**
 * @brief Get public account template message top color.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message top color, @see @ref EN_MTC_PA_COLOR_TYPE.
 */
ZFUNC ZUINT Mtc_PaTmplMsgGetTopColor(ZUINT iMsgId);

/**
 * @brief Get public account template message title.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message title.
 */
ZFUNC ZCHAR * Mtc_PaTmplMsgGetTitle(ZUINT iMsgId);

/**
 * @brief Get public account template message first text.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message first text.
 */
ZFUNC ZCHAR * Mtc_PaTmplMsgGetFirstText(ZUINT iMsgId);

/**
 * @brief Get public account template message first color.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message first color, @see @ref EN_MTC_PA_COLOR_TYPE.
 */
ZFUNC ZUINT Mtc_PaTmplMsgGetFirstColor(ZUINT iMsgId);

/**
 * @brief Get public account template message last text.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message last text.
 */
ZFUNC ZCHAR * Mtc_PaTmplMsgGetLastText(ZUINT iMsgId);

/**
 * @brief Get public account template message last color.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message last color, @see @ref EN_MTC_PA_COLOR_TYPE.
 */
ZFUNC ZUINT Mtc_PaTmplMsgGetLastColor(ZUINT iMsgId);

/**
 * @brief Get public account template message url.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message url.
 */
ZFUNC ZCHAR * Mtc_PaTmplMsgGetUrl(ZUINT iMsgId);

/**
 * @brief Get public account template message key note size.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message key note size.
 */
ZFUNC ZINT Mtc_PaTmplMsgGetKeyNoteSize(ZUINT iMsgId);

/**
 * @brief Get public account template message key note size.
 *
 * @param [in] iMsgId The message id.
 *
 * @return Thepublic account template message key note id.
 */
ZFUNC ZUINT Mtc_PaTmplMsgGetKeyNoteId(ZUINT iMsgId, ZINT iIndex);

/**
 * @brief Get public account template message key note name.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message key note name.
 */
ZFUNC ZCHAR * Mtc_PaKeyNoteGetName(ZUINT iNoteId);

/**
 * @brief Get public account template message key note value text.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message key note value text.
 */
ZFUNC ZCHAR * Mtc_PaKeyNoteGetValueText(ZUINT iNoteId);

/**
 * @brief Get public account template message key note value color.
 *
 * @param [in] iMsgId The message id.
 *
 * @return The public account template message key note value color, @see @ref EN_MTC_PA_COLOR_TYPE.
 */
ZFUNC ZUINT Mtc_PaKeyNoteGetValueColor(ZUINT iNoteId);

#ifdef __cplusplus
}
#endif
                
#endif 
