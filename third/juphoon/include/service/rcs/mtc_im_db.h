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
  File name     : mtc_im_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-02-06
  Description   :
      Data structure and function declare required by MTC IM database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_IM_DB_H__
#define _MTC_IM_DB_H__

/**
 * @file mtc_im_db.h
 * @brief MTC IM Database Interface Functions.
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief MTC im file transfer mechanism type */
typedef enum EN_MTC_IM_FT_MECH_TYPE
{
    EN_MTC_IM_FT_MECH_UNKNOWN,         /**< @brief unknown */
    EN_MTC_IM_FT_MECH_MSRP,            /**< @brief use msrp */
    EN_MTC_IM_FT_MECH_HTTP             /**< @brief use http */
} EN_MTC_IM_FT_MECH_TYPE;

/** @brief MTC im media protocol type */
typedef enum EN_MTC_IM_PROTO_TYPE
{
    EN_MTC_IM_PROTO_MSRP_TCP,          /**< @brief msrp over tcp */
    EN_MTC_IM_PROTO_MSRP_TLS           /**< @brief msrp over tls */
} EN_MTC_IM_PROTO_TYPE;

/** @brief MTC IM page allowed terminal type */
typedef enum EN_MTC_PMSG_ALLOWDTER_TYPE
{
    EN_MTC_PMSG_ALLOWDTER_PC_NONE,      /* pc none*/
    EN_MTC_PMSG_ALLOWDTER_PC_CALLER,   /* pc caller*/
    EN_MTC_PMSG_ALLOWDTER_PC_CALLED,  /* pc called */
    EN_MTC_PMSG_ALLOWDTER_PC_ENTIRE,  /* entire pc */
    EN_MTC_PMSG_ALLOWDTER_BOX_NONE,      /* box none */
    EN_MTC_PMSG_ALLOWDTER_BOX_CALLER,   /* box caller*/
    EN_MTC_PMSG_ALLOWDTER_BOX_CALLED,  /* box called */
    EN_MTC_PMSG_ALLOWDTER_BOX_ENTIRE,  /* entire box */
    EN_MTC_PMSG_ALLOWDTER_WEB_NONE,      /* web none */
    EN_MTC_PMSG_ALLOWDTER_WEB_CALLER,   /* web caller*/
    EN_MTC_PMSG_ALLOWDTER_WEB_CALLED,  /* web called */
    EN_MTC_PMSG_ALLOWDTER_WEB_ENTIRE,  /* entire web */
    EN_MTC_PMSG_ALLOWDTER_ALL_NONE,      /* all none*/
    EN_MTC_PMSG_ALLOWDTER_ALL_CALLER,   /* all caller*/
    EN_MTC_PMSG_ALLOWDTER_ALL_CALLED,  /* all called */
    EN_MTC_PMSG_ALLOWDTER_ALL_ENTIRE,  /* entire all */

    EN_MTC_PMSG_ALLOWDTER_UNKOWN   /* unkown option */
} EN_MTC_PMSG_ALLOWDTER_TYPE;

/** @brief MTC IM allowed SMS type */
typedef enum EN_MTC_IM_ALLOWED_SMS_TYPE
{
    EN_MTC_IM_ALLOWED_SMS_SERVER,          /* server allowed SMS */    
    EN_MTC_IM_ALLOWED_SMS_YES,             /* terminal allowed SMS */
    EN_MTC_IM_ALLOWED_SMS_NO,              /* terminal not allowed SMS */
} EN_MTC_ALLOWED_SMS_TYPE;

/**
 * @brief MTC im db restore configuration of current user for speicifc mode.
 *
 * @param [in] iMode The combination of EN_MTC_PROF_SERVICE_MODE 
 *
 * This interface should be invoke after @ref Mtc_CliInit and 
 * @ref Mtc_CliOpen was called.
 *
 * @retval ZOK Restore provision successfully.
 * @retval ZFAILED Restore provision failed.
 */
ZFUNC ZINT Mtc_ImDbRestoreProvision(ZUINT iMode);

/**
 * @brief Get IM defer retrieve factory URI.
 *
 * @return The string of defer retrieve URI.
 * The caller must copy it, then use.
 *
 * @see @ref Mtc_ImDbSetDeferRetvUri
 */
ZFUNC ZCHAR * Mtc_ImDbGetDeferRetvUri(ZFUNC_VOID);

/**
 * @brief Get IM defer delete factory URI.
 *
 * @return The string of defer delete URI.
 * The caller must copy it, then use.
 *
 * @see @ref Mtc_ImDbSetDeferDelUri
 */
ZFUNC ZCHAR * Mtc_ImDbGetDeferDelUri(ZFUNC_VOID);

/**
 * @brief Get IM imdn send delivery succeed request enable.
 *
 * @retval ZTRUE Send delivery succeed request is enable.
 * @retval ZFALSE Send delivery succeed request is disable.
 *
 * @see @ref Mtc_ImDbSetSendDeliSuccReqEnable
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDeliSuccReqEnable(ZFUNC_VOID);

/**
 * @brief Get IM imdn send delivery failed request enable.
 *
 * @retval ZTRUE Send delivery failed request is enable.
 * @retval ZFALSE Send delivery failed request is disable.
 *
 * @see @ref Mtc_ImDbSetSendDeliFailReqEnable
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDeliFailReqEnable(ZFUNC_VOID);

/**
 * @brief Get IM imdn send delivery forwarded request enable.
 *
 * @retval ZTRUE Send delivery forwarded request is enable.
 * @retval ZFALSE Send delivery forwarded request is disable.
 *
 * @see @ref Mtc_ImDbSetSendDeliFwdReqEnable
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDeliFwdReqEnable(ZFUNC_VOID);

/**
 * @brief Get IM imdn send delivery succeed request enbale in group chat.
 *
 * @retval ZTRUE Send delivery succeed request is enable.
 * @retval ZFALSE Send delivery succeed request is diasble.
 *
 * @see @ref Mtc_ImDbSetSendDeliSuccReqEnableG
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDeliSuccReqEnableG(ZFUNC_VOID);

/**
 * @brief Get IM imdn send delivery failed request enable in group chat.
 *
 * @retval ZTRUE Send delivery failed request is enable.
 * @retval ZFALSE Send delivery failed request is disable.
 *
 * @see @ref Mtc_ImDbSetSendDeliFailReqEnableG
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDeliFailReqEnableG(ZFUNC_VOID);

/**
 * @brief Get IM imdn send display request enable in group chat.
 *
 * @retval ZTRUE Send display request is enable.
 * @retval ZFALSE Send display request is disable.
 *
 * @see @ref Mtc_ImDbSetSendDispReqEnableG
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDispReqEnableG(ZFUNC_VOID);

/**
 * @brief Get IM imdn send display request enable.
 *
 * @retval ZTRUE Send display request is enable.
 * @retval ZFALSE Send display request is disable.
 *
 * @see @ref Mtc_ImDbSetSendDispReqEnable
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDispReqEnable(ZFUNC_VOID);

/**
 * @brief Get IM imdn send delivery response enable.
 *
 * @retval ZTRUE Send delivery response is enable.
 * @retval ZFALSE Send delivery response is disable.
 *
 * @see @ref Mtc_ImDbSetSendDeliRspEnable
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDeliRspEnable(ZFUNC_VOID);

/**
 * @brief Get IM imdn send display response enable.
 *
 * @retval ZTRUE Send display response is enable.
 * @retval ZFALSE Send display response is disable.
 *
 * @see @ref Mtc_ImDbSetSendDispRspEnable
 */
ZFUNC ZBOOL Mtc_ImDbGetSendDispRspEnable(ZFUNC_VOID);

/**
 * @brief Get IM imdn auto send delivery notification.
 *
 * @retval ZTRUE Send delivery request is enable.
 * @retval ZFALSE Send delivery request is disable.
 *
 * @see @ref Mtc_ImDbSetImdnAutoSendDeliNtfy
 */
ZFUNC ZBOOL Mtc_ImDbGetImdnAutoSendDeliNtfy(ZFUNC_VOID);

/**
 * @brief Get IM cpim base64 encode enable.
 *
 * @retval ZTRUE base64 encode is enable.
 * @retval ZFALSE base64 encode is disable.
 *
 * @see @ref Mtc_ImDbSetCpimBase64EncodeEnable
 */
ZFUNC ZBOOL Mtc_ImDbGetCpimBase64EncodeEnable(ZFUNC_VOID);

/**
 * @brief Get IM thumbnail base64 encode enable.
 *
 * @retval ZTRUE base64 encode is enable.
 * @retval ZFALSE base64 encode is disable.
 *
 * @see @ref Mtc_ImDbSetThumbBase64EncodeEnable
 */
ZFUNC ZBOOL Mtc_ImDbGetThumbBase64EncodeEnable(ZFUNC_VOID);

/**
 * @brief Get IM pres-srv-cap enable.
 *
 * @retval ZTRUE pres-srv-cap is enable.
 * @retval ZFALSE pres-srv-cap is disable.
 */
ZFUNC ZBOOL Mtc_ImDbGetPresSrvCap(ZFUNC_VOID);

/**
 * @brief Get IM max adhoc group size.
 *
 * @return The max adhoc group size.
 */
ZFUNC ZUINT Mtc_ImDbGetMaxAdhocGroupSize(ZFUNC_VOID);

/**
 * @brief Get IM conference factory uri.
 *
 * @return The conference factory uri.
 */
ZFUNC ZCHAR * Mtc_ImDbGetConfFctyUri(ZFUNC_VOID);

/**
 * @brief Get IM exploder uri.
 *
 * @return The exploder uri.
 */
ZFUNC ZCHAR * Mtc_ImDbGetExploderUri(ZFUNC_VOID);

/**
 * @brief Get IM deferred msg func uri.
 *
 * @return The deferred msg func uri.
 */
ZFUNC ZCHAR * Mtc_ImDbGetDeferredMsgFuncUri(ZFUNC_VOID);

/**
 * @brief Get IM multi-text uri.
 *
 * @return The multi-text uri.
 */
ZFUNC ZCHAR * Mtc_ImDbGetMultiTextUri(ZFUNC_VOID);

/**
 * @brief Get IM msgmatter-fcty-uri.
 *
 * @return The msgmatter-fcty-uri.
 */
ZFUNC ZCHAR * Mtc_ImDbGetMsgMatterUri(ZFUNC_VOID);

/**
 * @brief Get IM the authorization for the user to use the chat service.
 *
 * @retval ZTRUE Indicates that chat service is enabled.
 * @retval ZFALSE Indicates that chat service is disabled.
 * 
 * @see @ref Mtc_ImDbSetChatAuth.
 */
ZFUNC ZBOOL Mtc_ImDbGetChatAuth(ZFUNC_VOID);

/**
 * @brief Get IM the authorization for the user to use the group chat service.
 *
 * @retval ZTRUE Indicates that group chat service is enabled.
 * @retval ZFALSE Indicates that group chat service is disabled.
 * 
 * @see @ref Mtc_ImDbSetGroupChatAuth.
 */
ZFUNC ZBOOL Mtc_ImDbGetGroupChatAuth(ZFUNC_VOID);

/**
 * @brief Get IM the authorization for user to use the standalone messaging service.
 *
 * @retval ZTRUE The standalone messaging service is provided and uses CPM.
 * @retval ZFALSE The standalone messaging service is not provided.
 * 
 * @see @ref Mtc_ImDbSetStandaloneMsgAuth.
 */
ZFUNC ZBOOL Mtc_ImDbGetStandaloneMsgAuth(ZFUNC_VOID);

/**
 * @brief Get IM whether the chat capability needs to be on independently of 
 *   whether or not the other end is registered.
 *
 * @retval ZTRUE RCS Messaging Server based store and forward is enabled.
 * @retval ZFALSE RCS Messaging Server based store and forward is disabled.
 * 
 * @see @ref Mtc_ImDbSetImCapAlwaysOn.
 */
ZFUNC ZBOOL Mtc_ImDbGetImCapAlwaysOn(ZFUNC_VOID);

/**
 * @brief Get IM whether the UX should alert the user that messages are handled 
 *   differently when the store and forward functionality is involved.
 *   It is required to be instantiated if a service provider enables Chat. 
 *
 * @retval ZTRUE The user is made aware via the UX when the messages are deferred using S&F.
 * @retval ZFALSE The user is not aware that messages are deferred.
 *  
 * @see @ref Mtc_ImDbSetImWarnSf.
 */
ZFUNC ZBOOL Mtc_ImDbGetImWarnSf(ZFUNC_VOID);

/**
 * @brief Get IM whether the service provider for the device provides the full store 
 *   and forward feature for Group Chat.
 *   It is required to be instantiated if a service provider enables Group Chat. 
 *
 * @retval ZTRUE Indicates support for Full Store and Forward for Group Chat.
 * @retval ZFALSE Indicates no support for Full Store and Forward for Group Chat (default value).
 * 
 * @see @ref Mtc_ImDbSetGroupChatFullStandFwd.
 */
ZFUNC ZBOOL Mtc_ImDbGetGroupChatFullStandFwd(ZFUNC_VOID);

/**
 * @brief Get IM whether the service provider allows all users to be invited for a 
 *   group chat or only those that support the full store and forward feature for Group Chat.
 *   It is only relevant to be instantiated if a service provider enables Group Chat, but is not 
 *   required to be instantiated even then.
 *
 * @retval ZTRUE Indicates that only users that support for Full Store and Forward may be 
 *   invited for Group Chat.
 * @retval ZFALSE Indicates all users may be invited for Group Chat regardless of their 
 *   support for Full Store and Forward (default value).
 * 
 * @see @ref Mtc_ImDbSetGroupChatOnlyFStandFwd.
 */
ZFUNC ZBOOL Mtc_ImDbGetGroupChatOnlyFStandFwd(ZFUNC_VOID);

/**
 * @brief Get IM whether the Chat capability needs to be on independently of 
 *   whether or not the other end is an RCS contact.
 *   It is required to be instantiated if a service provider enables Chat. 
 *
 * @retval ZTRUE RCS Messaging Server based interworking is enabled.
 * @retval ZFALSE RCS Messaging Server based interworking is disabled.
 * 
 * @see @ref Mtc_ImDbSetImCapNonRcs.
 */
ZFUNC ZBOOL Mtc_ImDbGetImCapNonRcs(ZFUNC_VOID);

/**
 * @brief Get IM whether the UX should alert the user that messages are handled 
 *   differently when the interworking functionality is involved.
 *   It is required to be instantiated if a service provider enables Chat. 
 *
 * @retval ZTRUE The user is made aware via the UX when the messages are interworked to SMS/MMS.
 * @retval ZFALSE The user is not aware that messages are interworked.
 * 
 * @see @ref Mtc_ImDbSetImWarnIw.
 */
ZFUNC ZBOOL Mtc_ImDbGetImWarnIw(ZFUNC_VOID);

/**
 * @brief Get IM the authorization for the device to propose automatically a SMS 
 *   fallback in case of chat initiation failure.
 *   It is required to be instantiated if a service provider enables 1-to-1 Chat.
 *
 * @retval ZTRUE Indicates authorization is non ok.
 * @retval ZFALSE Indicates authorization is ok.
 */
ZFUNC ZBOOL Mtc_ImDbGetSmsFallbackAuth(ZFUNC_VOID);

/**
 * @brief Get IM the automatic/manual chat session answer mode.
 *   It is required to be instantiated if a service provider enables 1-to-1 Chat.
 *
 * @retval ZTRUE Indicates automatic answer mode (default value).
 * @retval ZFALSE Indicates manual answer mode.
 */
ZFUNC ZBOOL Mtc_ImDbGetAutAccept(ZFUNC_VOID);

/**
 * @brief Get IM parameter when the receiver client/device implementation should return the 
 *   200 OK initiating the MSRP session associated to a 1-to-1 chat.
 *   It is required to be instantiated if a service provider enables 1-to-1 Chat. 
 *
 * @retval 0 (RCS 5.1 default): 
 *   The 200 OK is sent when the receiver consumes the notification by opening the chat window.
 * @retval 1 (RCS Release 2-4 default): 
 *   The 200 OK is sent when the receiver starts to type a message to be sent back in the chat window.
 * @retval 2 (new option): 
 *   The 200 OK is sent when the receiver presses the button to send a message (That 
 *   is the message will be buffered in the client until the MSRP session is established).
 * 
 * @see @ref Mtc_ImDbSetImSessionStart.
 */
ZFUNC ZUINT Mtc_ImDbGetImSessionStart(ZFUNC_VOID);

/**
 * @brief Get IM the automatic/manual Group Chat session answer mode.
 *   It is required to be instantiated if a service provider enables Group Chat.
 *
 * @retval ZTRUE Indicates automatic answer mode (default value).
 * @retval ZFALSE Indicates manual answer mode.
 */
ZFUNC ZBOOL Mtc_ImDbGetAutAcceptGroupChat(ZFUNC_VOID);

/**
 * @brief Get IM controls whether the initial message in the chat is sent in a CPIM body of the 
 *   SIP INVITE request or can only be sent once the MSRP session has been set up.
 *   It is required to be instantiated if a service provider enables 1-to-1 Chat. 
 *
 * @retval ZTRUE Indicates the message is added to the INVITE request as a CPIM body.
 * @retval ZFALSE Indicates the message is sent in the MSRP.
 * 
 * @see @ref Mtc_ImDbSetFirstMsgInvite.
 */
ZFUNC ZBOOL Mtc_ImDbGetFirstMsgInvite(ZFUNC_VOID);

/**
 * @brief Get IM the timeout for a chat session in idle mode (when there is no chat user activity).
 *   It is required to be instantiated if a service provider enables Chat.
 *
 * @return The timer value in seconds.
 */
ZFUNC ZUINT Mtc_ImDbGetTimerIdle(ZFUNC_VOID);

/**
 * @brief Get IM the maximum authorized number of sessions established from the device. 
 *   Once this number is reached a new session may not be established anymore until 
 *   another session is torn down.
 *   It is required to be instantiated if a service provider enables Chat.
 *
 * @return The max number of concurrent sessions, when set to 0 this limit does not apply.
 */
ZFUNC ZUINT Mtc_ImDbGetMaxConcurrentSession(ZFUNC_VOID);

/**
 * @brief Get IM controls whether or not the device can send and receive other content than 
 *   text in the chat session.
 *   It is not required to be instantiated if a service provider does not enable Chat.
 *
 * @retval ZTRUE Indicates all content allowed by SIMPLE IM or CPM may be sent in the chat session.
 * @retval ZFALSE Indicates the device can only sent and receive text content within the chat.
 */
ZFUNC ZBOOL Mtc_ImDbGetMultiMediaChat(ZFUNC_VOID);

/**
 * @brief Get IM the maximum authorized size of a content chat message in a 1-to-1 chat session.
 *   It is required to be instantiated if a service provider enables 1-to-1 Chat.
 *
 * @return The content maximum size in bytes.
 */
ZFUNC ZUINT Mtc_ImDbGetMaxSize1To1(ZFUNC_VOID);

/**
 * @brief Set IM the maximum authorized size of a chat content message in a Group Chat session.
 *  It is required to be instantiated if a service provider enables Group Chat.
 *
 * @return The content maximum size in bytes.
 */
ZFUNC ZINT Mtc_ImDbSetMaxSize1ToM(ZUINT iMaxSize);

/**
 * @brief Get IM the maximum authorized size of a chat content message in a Group Chat session.
 *  It is required to be instantiated if a service provider enables Group Chat.
 *
 * @return The content maximum size in bytes.
 */
ZFUNC ZUINT Mtc_ImDbGetMaxSize1ToM(ZFUNC_VOID);

/**
 * @brief Get IM the maximum authorized content size of a text or multimedia message.
 *
 * @return The content maximum size in bytes.
 */
ZFUNC ZUINT Mtc_ImDbGetMaxSizeStandalone(ZFUNC_VOID);

/**
 * @brief Get IM the server url of the Network-based Common Message Store server.
 *
 * @return the server url for accessing the Message Store, 
 *   if set to an empty string, the Message Store is not available.
 */
ZFUNC ZCHAR * Mtc_ImDbGetMsServerUrl(ZFUNC_VOID);

/**
 * @brief Get IM the server port of the Network-based Common Message Store server.
 *
 * @return the server port for accessing the Message Store, 
 */
ZFUNC ZUSHORT Mtc_ImDbGetMsServerPort(ZFUNC_VOID);

/**
 * @brief Get IM the TLS enable flag for accessing the Network-based Common Message Store server.
 *
 * @return the TLS enable flag for accessing the Message Store, 
 */
ZFUNC ZBOOL Mtc_ImDbGetMsUseTls();

/**
 * @brief Get IM the if the message storage follow and support CMCC.
 *
 * @return cmcc support enable flag of the Message Store, 
 */
ZFUNC ZBOOL Mtc_ImDbGetMsCmccSupport();

/**
 * @brief Get IM the authentication prot type of message store.
 *
 * @return authentication prot type of the Message Store, 
 */
ZFUNC ZBOOL Mtc_ImDbGetMsAuthProt();

/**
 * @brief Get IM the user name of the Network-based Common Message Store server.
 *
 * @return the user name for accessing the Message Store, 
 */
ZFUNC ZCHAR * Mtc_ImDbGetMsUserName(ZFUNC_VOID);

/**
 * @brief Get IM the user password for accessing the Network-based Common Message Store server.
 *
 * @return the user password for accessing the Message Store, 
 */
ZFUNC ZCHAR * Mtc_ImDbGetMsUserPwd(ZFUNC_VOID);

/**
 * @brief Get IM the user msidn for accessing the Network-based Common Message Store server.
 *
 * @return the user msidn for accessing the Message Store, 
 */
ZFUNC ZCHAR * Mtc_ImDbGetMsUserMsisdn(ZFUNC_VOID);

/**
 * @brief Get IM the cache directory for accessing the Network-based Common Message Store server.
 *
 * @return the cache directory for accessing the Message Store, 
 */
ZFUNC ZCHAR * Mtc_ImDbGetMsCacheDir(ZFUNC_VOID);

/**
 * @brief Get IM the spam uri.
 *
 * @return the spam uri, 
 */
ZFUNC ZCHAR * Mtc_ImDbGetSpamUri(ZFUNC_VOID);

/**
 * @brief Get IM parameter allows selecting what technology is used for the chat 
 *   service in 1-1 chat and group chat as well as for the File Transfer service.
 *   It is required to be instantiated if a service provider enables Chat.
 *
 * @retval ZTRUE CPM service is selected.
 * @retval ZFALSE SIMPLE IM service is selected (default value).
 *
 * @see @ref Mtc_ImDbSetImMsgTech.
 */
ZFUNC ZBOOL Mtc_ImDbGetImMsgTech(ZFUNC_VOID);

/**
 * @brief Get IM the authorization for user to use the File Transfer service.
 *
 * @retval ZTRUE Indicates that File Transfer service is enabled.
 * @retval ZFALSE Indicates that File Transfer service is disabled.
 *
 * @see @ref Mtc_ImDbSetFtAuth.
 */
ZFUNC ZBOOL Mtc_ImDbGetFtAuth(ZFUNC_VOID);

/**
 * @brief Get IM the maximum authorized size of a file that can be transfers using 
 *   the RCS File Transfer service.
 *   It is required to be instantiated in case a service provider enables File Transfer.
 *
 * @return The maximum file size threshold (in KB) or 0 to disable the limit.
 */
ZFUNC ZUINT Mtc_ImDbGetMaxSizeFileTr(ZFUNC_VOID);

/**
 * @brief Get IM the chat revoke timer be used to determines the maximum time
 *    that user can revoke the message had sended to somebody.
 * @return The Chat revoke timer value.
 *
 * @see @ref Mtc_ImDbSetImChatRevokeTimer.
 */
ZFUNC ZUINT Mtc_ImDbGetImChatRevokeTimer(ZFUNC_VOID);

/**
 * @brief Get IM the cmcc chat revoke timer be used to determines the maximum time
 *    that user can revoke the message had sended to somebody.
 * @return The Cmcc Chat revoke timer value.
 *
 * @see @ref Mtc_ImDbSetImCmccChatRevokeTimer.
 */
ZFUNC ZUINT Mtc_ImDbGetImCmccChatRevokeTimer();

/**
 * @brief Get IM the file transfer size threshold when the user should be 
*    warned about the potential charges associated to the transfer of a large file .
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @return The file size threshold (in KB) or 0 to disable the warning.
 *
 * @see @ref Mtc_ImDbSetFtWarnSize.
 */
ZFUNC ZUINT Mtc_ImDbGetFtWarnSize(ZFUNC_VOID);

/**
 * @brief Get IM controls whether or not the device can send and receive a thumbnail 
 *   in a File Transfer invitation
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @retval ZTRUE The device may send or receive thumbnails in the File Transfer Invitation.
 * @retval ZFALSE The device cannot send or receive a thumbnail in the File Transfer invitation 
 *   and should handle the capability exchange accordingly.
 */
ZFUNC ZBOOL Mtc_ImDbGetFtThumb(ZFUNC_VOID);

/**
 * @brief Get IM whether the File Transfer store and forward functionality is enabled
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @retval ZTRUE The file store and forward functionality is enabled and, consequently, 
 *   the file transfer store and forward capability is reported as available.
 * @retval ZFALSE means the opposite, consequently, the capability is reported as not available.
 *
 * @see @ref Mtc_ImDbSetFtStAndFwEnabled.
 */
ZFUNC ZBOOL Mtc_ImDbGetFtStAndFwEnabled(ZFUNC_VOID);

/**
 * @brief Get IM the maximum number of 1 to many recipient.
 *
 * @return the maximum 1 to many recipient.
 *
 * @see @ref Mtc_ImDbSetMax1ToNRecipient.
 */
ZFUNC ZUINT Mtc_ImDbGetMax1ToNRecipient(ZFUNC_VOID);

/**
 * @brief Get IM the file transfer maximum number of 1 to many recipient.
 *
 * @return the file transfer maximum 1 to many recipient.
 *
 * @see @ref Mtc_ImDbSetFtMax1ToNRecipient.
 */
ZFUNC ZUINT Mtc_ImDbGetFtMax1ToNRecipient(ZFUNC_VOID);

/**
 * @brief Get IM whether the file transfer capability needs to be on independently of 
 *   whether or not the other end is registered.
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @retval ZTRUE RCS Messaging Server based store and forward is enabled.
 * @retval ZFALSE RCS Messaging Server based store and forward is disabled.
 *
 * @see @ref Mtc_ImDbSetFtCapAlwaysOn.
 */
ZFUNC ZBOOL Mtc_ImDbGetFtCapAlwaysOn(ZFUNC_VOID);

/**
 * @brief Get IM whether a File Transfer invitation can be automatically accepted.
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @retval ZTRUE Indicates the File Transfer invitation shall be accepted if the size of the file 
 *   is smaller than the File Transfer warning size as configured by the FT WARN SIZE parameter.
 * @retval ZFALSE Indicates automatic acceptance is not possible (regardless of the size of the file).
 *
 * @see @ref Mtc_ImDbSetFtAutAccept.
 */
ZFUNC ZBOOL Mtc_ImDbGetFtAutAccept(ZFUNC_VOID);

/**
 * @brief Get IM parameter configures the URI of the HTTP content server where files are 
 *   going to be uploaded on the originating side if the destination cannot accept within
 *   the validity period.
 *   Note: it is not required to be instantiated because it is not mandatory for a service provider 
 *   to have this originating solution based on a HTTP content server.
 *
 * @return The string containing the URI of the HTTP content server in charge of storing the files.
 *
 * @see @ref Mtc_ImDbSetFtHttpCsUri.
 */
ZFUNC ZCHAR * Mtc_ImDbGetFtHttpCsUri(ZFUNC_VOID);

/**
 * @brief Get IM parameter configures the user of the HTTP content server where files are 
 *   going to be uploaded on the originating side if the destination cannot accept within
 *   the validity period.
 *   Note: it is not required to be instantiated because it is not mandatory for a service provider 
 *   to have this originating solution based on a HTTP content server.
 *
 * @return The string containing the user of the HTTP content server in charge of storing the files.
 *
 * @see @ref Mtc_ImDbSetFtHttpCsUser.
 */
ZFUNC ZCHAR * Mtc_ImDbGetFtHttpCsUser();

/**
 * @brief Get IM parameter configures the password of the HTTP content server where files are 
 *   going to be uploaded on the originating side if the destination cannot accept within
 *   the validity period.
 *   Note: it is not required to be instantiated because it is not mandatory for a service provider 
 *   to have this originating solution based on a HTTP content server.
 *
 * @return The string containing the password of the HTTP content server in charge of storing the files.
 *
 * @see @ref Mtc_ImDbSetFtHttpCsPwd.
 */
ZFUNC ZCHAR * Mtc_ImDbGetFtHttpCsPwd();

/**
 * @brief Get IM file transfer mechanism (MSRP or HTTP) shall be used by default 
 *   if both ends support both of them.
 *   It is required to be instantiated if a Service Provider enables File Transfer and configures 
 *   the URI for the HTTP content server to enable File Transfer using HTTP
 *
 * @return The file transfer mechanism type, see @ref EN_MTC_IM_FT_MECH_TYPE.
 *
 * @see @ref Mtc_ImDbSetFtDefaultMech.
 */
ZFUNC ZUINT Mtc_ImDbGetFtDefaultMech(ZFUNC_VOID);

/* mtc im db get download file path directory */
/**
 * @brief Get IM file transfer download file path directory for save 
 *
 * @return The download file path directory.
 *
 * @see @ref Mtc_ImDbSetFtFileDirect.
 */
ZFUNC ZCHAR * Mtc_ImDbGetFtFileDirect(ZFUNC_VOID);

/**
 * @brief Get IM the authorization for user to use Image Share service.
 *
 * @retval ZTRUE Indicates that Image Share service is enabled.
 * @retval ZFALSE Indicates that Image Share service is disabled.
 *
 * @see @ref Mtc_ImDbSetIsAuth.
 */
ZFUNC ZBOOL Mtc_ImDbGetIsAuth(ZFUNC_VOID);

/**
 * @brief Get IM the maximum authorized size of the content that can be sent in 
 *   an Image Share session .
 *
 * @return content maximum size in bytes, value equals to 0 means no limitation.
 *
 * @see @ref Mtc_ImDbSetMaxSizeImageShare.
 */
ZFUNC ZUINT Mtc_ImDbGetMaxSizeImageShare(ZFUNC_VOID);

/**
 * @brief Get IM the ImageShareQuery for user to use Image Share service.
 *
 * @retval ZTRUE Indicates that send query with sdp before Image Share.
 * @retval ZFALSE Indicates that not send query before Image Share.
 *
 * @see @ref Mtc_ImDbSetImageShareQuery.
 */
ZFUNC ZUINT Mtc_ImDbGetImageShareQuery();

/**
 * @brief Get IM media protocal type.
 *
 * @return media protocal type, @see @ref EN_MTC_IM_PROTO_TYPE.
 *
 * @see @ref Mtc_ImDbSetMediaProtoType.
 */
ZFUNC ZUINT Mtc_ImDbGetMediaProtoType();

/**
 * @brief Get IM file transfer maxnumber running vusers.
 *
 * @return IM file transfer maxnumber running vusers.
 *
 * @see @ref Mtc_ImDbSetFtMaxRunVusers.
 */
ZFUNC ZUINT Mtc_ImDbGetFtMaxRunVusers();

/**
 * @brief Get IM use session mode message.
 *
 * @return IM use session mode message.
 *
 * @see @ref Mtc_ImDbSetUseSessModeMsg.
 */
ZFUNC ZBOOL Mtc_ImDbGetUseSessModeMsg();

/**
 * @brief Get IM get http get conference info server port.
 *
 * @return conference info server port.
 *
 * @see @ref Mtc_ImDbSetHttpGetConfInfoServPort.
 */
ZFUNC ZUSHORT Mtc_ImDbGetHttpGetConfInfoServPort();

/**
 * @brief Get vemoticon version.
 *
 * @return The exploder uri.
 */
ZFUNC ZCHAR * Mtc_ImDbGetVemMsgVersion();

/**
 * @brief Get subscribe conference info expire.
 *
 * @return The subscribe expire.
 *
 * @see @ref Mtc_ImDbSetSubsConfInfoExpire.
 */
ZFUNC ZUINT Mtc_ImDbGetSubsConfInfoExpire();


/**
 * @brief Get cc allowd terminal type.
 *
 * @return The allowd terminal type @ref EN_MTC_PMSG_ALLOWDTER_TYPE.
 *
 * @see @ref Mtc_ImDbSetCCAllowedTerminalType.
 */
ZFUNC ZUCHAR Mtc_ImDbGetCCAllowedTerminalType();

/**
 * @brief Get IM allowed sms.
 *
 * @return IM allowed sms.
 *
 * @see @ref Mtc_ImDbSetAllowedSms.
 */
ZFUNC ZBOOL Mtc_ImDbGetAllowedSms();

/**
 * @brief Get IM allowed offline.
 *
 * @return IM allowed offline.
 *
 * @see @ref Mtc_ImDbSetAllowedOffline.
 */
ZFUNC ZBOOL Mtc_ImDbGetAllowedOffline();

/**
 * @brief Get IM the supportive for the user to use the group chat service.
 *
 * @retval ZTRUE Indicates that group chat service is enabled.
 * @retval ZFALSE Indicates that group chat service is disabled.
 * 
 * @see @ref Mtc_ImDbSetGroupChatSupt.
 */
ZFUNC ZBOOL Mtc_ImDbGetGroupChatSupt(ZFUNC_VOID);

/**
 * @brief Get gzip list number.
 *
 * @return The list number that list should be gziped.
 *
 * @see @ref Mtc_ImDbSetGzipListNumber
 */
ZFUNC ZUINT Mtc_ImDbGetGzipListNumber(ZFUNC_VOID);

/**
 * @brief get file transfer support inactive flag.
 *
 *
 * @retval ZTRUE  if support inactive flag, otherwise retval ZFALSE
 *
 */
ZFUNC ZBOOL Mtc_ImDbGetSupInactive();

/**
 * @brief Set IM defer retrieve factory URI.
 *
 * @param [in] pcUri defer retrieve URI.
 *
 * @retval ZOK Set defer retrieve URI successfully.
 * @retval ZFAILED Set defer retrieve URI failed.
 *
 * @see @ref Mtc_ImDbGetDeferRetvUri
 */
ZFUNC ZINT Mtc_ImDbSetDeferRetvUri(ZCHAR *pcUri);

/**
 * @brief Set IM defer delete factory URI.
 *
 * @param [in] pcUri defer delete URI.
 *
 * @retval ZOK Set defer delete URI successfully.
 * @retval ZFAILED Set defer delete URI failed.
 *
 * @see @ref Mtc_ImDbGetDeferDelUri
 */
ZFUNC ZINT Mtc_ImDbSetDeferDelUri(ZCHAR *pcUri);

/**
 * @brief Set IM imdn send delivery succeed request enable.
 *
 * @param [in] bEnable send delivery succeed request enable.
 *
 * @retval ZOK Set send delivery succeed request enable successfully.
 * @retval ZFAILED Set send delivery succeed request enable failed.
 *
 * @see @ref Mtc_ImDbGetSendDeliSuccReqEnable
*/
ZFUNC ZINT Mtc_ImDbSetSendDeliSuccReqEnable(ZBOOL bEnable);

/**
 * @brief Set IM imdn send delivery failed request enable.
 *
 * @param [in] bEnable send delivery failed request enable.
 *
 * @retval ZOK Set send delivery failed request enable successfully.
 * @retval ZFAILED Set send delivery failed request enable failed.
 *
 * @see @ref Mtc_ImDbGetSendDeliFailReqEnable
*/
ZFUNC ZINT Mtc_ImDbSetSendDeliFailReqEnable(ZBOOL bEnable);

/**
 * @brief Set IM imdn send delivery forwarded request enable.
 *
 * @param [in] bEnable send delivery forwarded request enable.
 *
 * @retval ZOK Set send delivery forwarded request enable successfully.
 * @retval ZFAILED Set send delivery forwarded request enable failed.
 *
 * @see @ref Mtc_ImDbGetSendDeliFwdReqEnable
*/
ZFUNC ZINT Mtc_ImDbSetSendDeliFwdReqEnable(ZBOOL bEnable);

/**
 * @brief Set IM imdn send delivery succeed request enable in group chat.
 *
 * @param [in] bEnable send delivery succeed request enable.
 *
 * @retval ZOK Set send delivery succeed request enable successfully.
 * @retval ZFAILED Set send delivery succeed request enable failed.
 *
 * @see @ref Mtc_ImDbGetSendDeliSuccReqEnableG
*/
ZFUNC ZINT Mtc_ImDbSetSendDeliSuccReqEnableG(ZBOOL bEnable);

/**
 * @brief Set IM imdn send delivery failed request enable in group chat.
 *
 * @param [in] bEnable send delivery failed request enable.
 *
 * @retval ZOK Set send delivery failed request enable successfully.
 * @retval ZFAILED Set send delivery failed request enable failed.
 *
 * @see @ref Mtc_ImDbGetSendDeliFailReqEnableG
*/
ZFUNC ZINT Mtc_ImDbSetSendDeliFailReqEnableG(ZBOOL bEnable);

/**
 * @brief Set IM imdn send display request enable in group chat.
 *
 * @param [in] bEnable send display request enable.
 *
 * @retval ZOK Set send display request enable successfully.
 * @retval ZFAILED Set send display request enable failed.
 *
 * @see @ref Mtc_ImDbGetSendDispReqEnableG
 */
ZFUNC ZINT Mtc_ImDbSetSendDispReqEnableG(ZBOOL bEnable);

/**
 * @brief Set IM imdn send display request enable.
 *
 * @param [in] bEnable send display request enable.
 *
 * @retval ZOK Set send display request enable successfully.
 * @retval ZFAILED Set send display request enable failed.
 *
 * @see @ref Mtc_ImDbGetSendDispReqEnable
 */
ZFUNC ZINT Mtc_ImDbSetSendDispReqEnable(ZBOOL bEnable);

/**
 * @brief Set IM imdn send delivery response enable.
 *
 * @param [in] bEnable send delivery response enable.
 *
 * @retval ZOK Set send delivery response enable successfully.
 * @retval ZFAILED Set send delivery response enable failed.
 *
 * @see @ref Mtc_ImDbGetImdnSendDeliReqEnable
 */
ZFUNC ZINT Mtc_ImDbSetSendDeliRspEnable(ZBOOL bEnable);

/**
 * @brief Set IM imdn send display response enable.
 *
 * @param [in] bEnable send display response enable.
 *
 * @retval ZOK Set send display response enable successfully.
 * @retval ZFAILED Set send display response enable failed.
 *
 * @see @ref Mtc_ImDbGetSendDispRspEnable
 */
ZFUNC ZINT Mtc_ImDbSetSendDispRspEnable(ZBOOL bEnable);

/**
 * @brief Set IM imdn auto send delivery notification.
 *
 * @param [in] bEnable auto send delivery notification.
 *
 * @retval ZOK Set auto send delivery notification successfully.
 * @retval ZFAILED Set auto send delivery notification failed.
 *
 * @see @ref Mtc_ImDbGetImdnAutoSendDeliNtfy
 */
ZFUNC ZINT Mtc_ImDbSetImdnAutoSendDeliNtfy(ZBOOL bEnable);

/**
 * @brief Set IM cpim base64 encode enable.
 *
 * @param [in] bEnable base64 encode enable.
 *
 * @retval ZOK Set base64 encode enable successfully.
 * @retval ZFAILED Set base64 encode enable failed.
 *
 * @see @ref Mtc_ImDbGetCpimBase64EncodeEnable
 */
ZFUNC ZINT Mtc_ImDbSetCpimBase64EncodeEnable(ZBOOL bEnable);

/**
 * @brief Set IM thumbnail base64 encode enable.
 *
 * @param [in] bEnable base64 encode enable.
 *
 * @retval ZOK Set base64 encode enable successfully.
 * @retval ZFAILED Set base64 encode enable failed.
 *
 * @see @ref Mtc_ImDbGetThumbBase64EncodeEnable
 */
ZFUNC ZINT Mtc_ImDbSetThumbBase64EncodeEnable(ZBOOL bEnable);

/**
 * @brief Set IM max adhoc group size.
 *
 * @param [in] iMaxAdhocGroupSize max adhoc group size.
 *
 * @retval ZOK Set max adhoc group size successfully.
 * @retval ZFAILED Set max adhoc group size failed.
 *
 * @see @ref Mtc_ImDbGetMaxAdhocGroupSize
 */
ZFUNC ZINT Mtc_ImDbSetMaxAdhocGroupSize(ZUINT iMaxAdhocGroupSize);

/**
 * @brief Set IM conference factory uri.
 *
 * @retval ZOK Set display enable successfully.
 * @retval ZFAILED Set display enable failed.
 *
 * @see @ref Mtc_ImDbGetConfFctyUri
 */
ZFUNC ZINT Mtc_ImDbSetConfFctyUri(ZCHAR *pcConfFctyUri);

/**
 * @brief Set IM multi text uri.
 *
 * @retval ZOK Set multi text uri successfully.
 * @retval ZFAILED Set multi text uri failed.
 *
 * @see @ref Mtc_ImDbGetMultiTextUri
 */
ZFUNC ZINT Mtc_ImDbSetMultiTextUri(ZCHAR *pcMultiTextUri);

/**
 * @brief Set IM msg matter uri.
 *
 * @retval ZOK Set msg matter uri successfully.
 * @retval ZFAILED Set msg matter uri failed.
 *
 * @see @ref Mtc_ImDbGetMsgMatterUri
 */
ZFUNC ZINT Mtc_ImDbSetMsgMatterUri(ZCHAR *pcMsgMatterUri);

/**
 * @brief Set IM the authorization for the user to use the chat service.
 *
 * @param [in] bChatAuth chat service enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetChatAuth.
 */
ZFUNC ZINT Mtc_ImDbSetChatAuth(ZBOOL bChatAuth);

/**
 * @brief Set IM the authorization for the user to use the group chat service.
 *
 * @param [in] bGroupChatAuth group chat service enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetGroupChatAuth.
 */
ZFUNC ZINT Mtc_ImDbSetGroupChatAuth(ZBOOL bGroupChatAuth);

/**
 * @brief Set IM the authorization for user to use the standalone messaging service.
 *
 * @param [in] bStandaloneMsgAuth standalone messaging service enable flag.
 * 
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetStandaloneMsgAuth.
 */
ZFUNC ZINT Mtc_ImDbSetStandaloneMsgAuth(ZBOOL bStandaloneMsgAuth);

/**
 * @brief Get IM whether the chat capability needs to be on independently of 
 *   whether or not the other end is registered.
 *
 * @param [in] bImCapAlwaysOn chat capability enable flag.
 * 
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetImCapAlwaysOn.
 */
ZFUNC ZINT Mtc_ImDbSetImCapAlwaysOn(ZBOOL bImCapAlwaysOn);

/**
 * @brief Set IM whether the UX should alert the user that messages are handled 
 *   differently when the store and forward functionality is involved.
 *   It is required to be instantiated if a service provider enables Chat. 
 *
 * @param [in] bImWarnSf chat warning enable flag.
 *  
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetImWarnSf.
 */
ZFUNC ZINT Mtc_ImDbSetImWarnSf(ZBOOL bImWarnSf);

/**
 * @brief Set IM whether the service provider for the device provides the full store 
 *   and forward feature for Group Chat.
 *   It is required to be instantiated if a service provider enables Group Chat. 
 *
 * @param [in] bGroupChatFullStandFwd Full Store and Forward for Group Chat enable flag.
 * 
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetGroupChatFullStandFwd.
 */
ZFUNC ZINT Mtc_ImDbSetGroupChatFullStandFwd(ZBOOL bGroupChatFullStandFwd);

/**
 * @brief Set IM whether the service provider allows all users to be invited for a 
 *   group chat or only those that support the full store and forward feature for Group Chat.
 *   It is only relevant to be instantiated if a service provider enables Group Chat, but is not 
 *   required to be instantiated even then.
 *
 * @param [in] bGroupChatOnlyFStandFwd users only support S&F to be invited enable flag.
 * 
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetGroupChatOnlyFStandFwd.
 */
ZFUNC ZINT Mtc_ImDbSetGroupChatOnlyFStandFwd(ZBOOL bGroupChatOnlyFStandFwd);

/**
 * @brief Set IM whether the Chat capability needs to be on independently of 
 *   whether or not the other end is an RCS contact.
 *   It is required to be instantiated if a service provider enables Chat. 
 *
 * @param [in] bImCapNonRcs RCS Messaging Server based interworking enable flag.
 * 
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetImCapNonRcs.
 */
ZFUNC ZINT Mtc_ImDbSetImCapNonRcs(ZBOOL bImCapNonRcs);

/**
 * @brief Set IM whether the UX should alert the user that messages are handled 
 *   differently when the interworking functionality is involved.
 *   It is required to be instantiated if a service provider enables Chat. 
 *
 * @param [in] bImWarnIw alert user enable flag.
 * 
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetImWarnIw.
 */
ZFUNC ZINT Mtc_ImDbSetImWarnIw(ZBOOL bImWarnIw);

/**
 * @brief Set IM the automatic/manual chat session answer mode.
 *   It is required to be instantiated if a service provider enables 1-to-1 Chat.
 *
 * @param [in] bAutAccept IM automatic/manual flag.
 * 
 * @retval ZOK Set session start type successfully.
 * @retval ZFAILED Set session start type failed.
 *
 * @see @ref Mtc_ImDbGetImSessionStart.
 */
ZFUNC ZINT Mtc_ImDbSetAutAccept(ZBOOL bAutAccept);

/**
 * @brief Set IM parameter when the receiver client/device implementation should return the 
 *   200 OK initiating the MSRP session associated to a 1-to-1 chat.
 *   It is required to be instantiated if a service provider enables 1-to-1 Chat. 
 *
 * @param [in] iImSessionStart session start type.
 * 
 * @retval ZOK Set session start type successfully.
 * @retval ZFAILED Set session start type failed.
 *
 * @see @ref Mtc_ImDbGetImSessionStart.
 */
ZFUNC ZINT Mtc_ImDbSetImSessionStart(ZUINT iImSessionStart);

/**
 * @brief Set IM the automatic/manual Group Chat session answer mode.
 *   It is required to be instantiated if a service provider enables Group Chat.
 *
 * @param [in] bAutAcceptGroupChat The group chat auto accept flag.
 * 
 * @retval ZOK Set group chat auto accept successfully.
 * @retval ZFAILED Set group chat auto accept failed.
 */
ZFUNC ZINT Mtc_ImDbSetAutAcceptGroupChat(ZBOOL bAutAcceptGroupChat);

/**
 * @brief Set IM controls whether the initial message in the chat is sent in a CPIM body of the 
 *   SIP INVITE request or can only be sent once the MSRP session has been set up.
 *   It is required to be instantiated if a service provider enables 1-to-1 Chat. 
 *
 * @param [in] bFirstMessageInvite SIP INVITE request with message enable flag.
 * 
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetFirstMsgInvite.
 */
ZFUNC ZINT Mtc_ImDbSetFirstMsgInvite(ZBOOL bFirstMessageInvite);

/**
 * @brief Set IM parameter allows selecting what technology is used for the chat 
 *   service in 1-1 chat and group chat as well as for the File Transfer service.
 *   It is required to be instantiated if a service provider enables Chat.
 *
 * @param [in] bImMsgTech if ZTRUE use CPM, else user SIMPLE IM.
 *
 * @retval ZOK Set selection successfully.
 * @retval ZFAILED Set selection failed.
 *
 * @see @ref Mtc_ImDbGetImMsgTech.
 */
ZFUNC ZINT Mtc_ImDbSetImMsgTech(ZBOOL bImMsgTech);

/**
 * @brief Set IM the authorization for user to use the File Transfer service.
 *
 * @param [in] bFtAuth File Transfer service enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetFtAuth.
 */
ZFUNC ZINT Mtc_ImDbSetFtAuth(ZBOOL bFtAuth);

/**
 * @brief Get IM the file transfer size threshold when the user should be 
*    telled about the potential charges associated to the transfer of a large file .
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @param [in] iMaxSizeFileTr The file size threshold (in KB).
 *
 * @retval ZOK Set file size successfully.
 * @retval ZFAILED Set file size failed.
 *
 * @see @ref Mtc_ImDbSetMaxSizeFileTr.
 */
ZFUNC ZINT Mtc_ImDbSetMaxSizeFileTr(ZUINT iMaxSizeFileTr);

/**
 * @brief Set IM the chat revoke timer be used to determines the maximum time
 *    that user can revoke the message had sended to somebody.
 * @return The Chat revoke timer value.
 *
 * @retval ZOK Set chat revoke timer successfully.
 * @retval ZFAILED Set chat revoke timer failed.
 */
ZFUNC ZINT Mtc_ImDbSetImChatRevokeTimer(ZUINT iImChatRevokeTimer);

/**
 * @brief Set IM the Cmcc chat revoke timer be used to determines the maximum time
 *    that user can revoke the message had sended to somebody.
 * @return The Cmcc Chat revoke timer value.
 *
 * @retval ZOK Set Cmcc chat revoke timer successfully.
 * @retval ZFAILED Set Cmcc chat revoke timer failed.
 */
ZFUNC ZINT Mtc_ImDbSetImCmccChatRevokeTimer(ZUINT iImCmccChatRevokeTimer);

/**
 * @brief Get IM the file transfer size threshold when the user should be 
 *   warned about the potential charges associated to the transfer of a large file .
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @param [in] iFtWarnSize The file size threshold (in KB).
 *
 * @retval ZOK Set file size successfully.
 * @retval ZFAILED Set file size failed.
 *
 * @see @ref Mtc_ImDbGetFtWarnSize.
 */
ZFUNC ZINT Mtc_ImDbSetFtWarnSize(ZUINT iFtWarnSize);

/**
 * @brief Set IM the file transfer contain thumb.
 *
 * @param [in] bFtThumb The file contain thumb.
 *
 * @retval ZOK Set ftThumb successfully.
 * @retval ZFAILED ftThumb size failed.
 *
 * @see @ref Mtc_ImDbGetFtThumb.
 */
ZFUNC ZINT Mtc_ImDbSetFtThumb(ZBOOL bFtThumb);

/**
 * @brief Set IM whether the File Transfer store and forward functionality is enabled
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @param [in] bFtStAndFwEnabled file store and forward functionality enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetFtStAndFwEnabled.
 */
ZFUNC ZINT Mtc_ImDbSetFtStAndFwEnabled(ZBOOL bFtStAndFwEnabled);

/**
 * @brief Get IM maximum number of 1 to many recipient.
 *
 * @param [in] iMax1ToNRecipient The maximum number of 1 to many recipient.
 *
 * @retval ZOK Set maximum number successfully.
 * @retval ZFAILED Set maximum number failed.
 *
 * @see @ref Mtc_ImDbGetMax1ToNRecipient.
 */
ZFUNC ZINT Mtc_ImDbSetMax1ToNRecipient(ZUINT iMax1ToNRecipient);

/**
 * @brief Get IM file transfer maximum number of 1 to many recipient.
 *
 * @param [in] iMax1ToNRecipient The file transfer maximum number of 1 to many recipient.
 *
 * @retval ZOK Set maximum number successfully.
 * @retval ZFAILED Set maximum number failed.
 *
 * @see @ref Mtc_ImDbGetFtMax1ToNRecipient.
 */
ZFUNC ZINT Mtc_ImDbSetFtMax1ToNRecipient(ZUINT iFtMax1ToNRecipient);

/**
 * @brief Set IM whether the file transfer capability needs to be on independently of 
 *   whether or not the other end is registered.
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @param [in] bFtCapAlwaysOn RCS Messaging Server based store and forward enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetFtCapAlwaysOn.
 */
ZFUNC ZINT Mtc_ImDbSetFtCapAlwaysOn(ZBOOL bFtCapAlwaysOn);

/**
 * @brief Set IM whether a File Transfer invitation can be automatically accepted.
 *   It is required to be instantiated if a service provider enables File Transfer.
 *
 * @param [in] bFtAutAccept File Transfer invitation auto accepted enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetFtAutAccept.
 */
ZFUNC ZINT Mtc_ImDbSetFtAutAccept(ZBOOL bFtAutAccept);

/**
 * @brief Set IM parameter configures the URI of the HTTP content server where files are 
 *   going to be uploaded on the originating side if the destination cannot accept within
 *   the validity period.
 *   Note: it is not required to be instantiated because it is not mandatory for a service provider 
 *   to have this originating solution based on a HTTP content server.
 *
 * @param [in] pcFtHttpCsUri The string containing the URI of the HTTP content server.
 *
 * @retval ZOK Set URI successfully.
 * @retval ZFAILED Set URI failed.
 *
 * @see @ref Mtc_ImDbGetFtHttpCsUri.
 */
ZFUNC ZINT Mtc_ImDbSetFtHttpCsUri(ZCHAR *pcFtHttpCsUri);

/**
 * @brief Set IM parameter configures the user of the HTTP content server where files are 
 *   going to be uploaded on the originating side if the destination cannot accept within
 *   the validity period.
 *   Note: it is not required to be instantiated because it is not mandatory for a service provider 
 *   to have this originating solution based on a HTTP content server.
 *
 * @param [in] pcFtHttpCsUser The string containing the user of the HTTP content server.
 *
 * @retval ZOK Set URI successfully.
 * @retval ZFAILED Set URI failed.
 *
 * @see @ref Mtc_ImDbGetFtHttpCsUser.
 */
ZFUNC ZINT Mtc_ImDbSetFtHttpCsUser(ZCHAR *pcFtHttpCsUser);

/**
 * @brief Set IM parameter configures the password of the HTTP content server where files are 
 *   going to be uploaded on the originating side if the destination cannot accept within
 *   the validity period.
 *   Note: it is not required to be instantiated because it is not mandatory for a service provider 
 *   to have this originating solution based on a HTTP content server.
 *
 * @param [in] pcFtHttpCsPwd The string containing the password of the HTTP content server.
 *
 * @retval ZOK Set URI successfully.
 * @retval ZFAILED Set URI failed.
 *
 * @see @ref Mtc_ImDbGetFtHttpCsPwd.
 */
ZFUNC ZINT Mtc_ImDbSetFtHttpCsPwd(ZCHAR *pcFtHttpCsPwd);

/**
 * @brief Set IM file transfer mechanism (MSRP or HTTP) shall be used by default 
 *   if both ends support both of them.
 *   It is required to be instantiated if a Service Provider enables File Transfer and configures 
 *   the URI for the HTTP content server to enable File Transfer using HTTP
 *
 * @param [in] iFtDefaultMech The file transfer mechanism type, see @ref EN_MTC_IM_FT_MECH_TYPE.
 *
 * @retval ZOK Set file transfer mechanism type successfully.
 * @retval ZFAILED Set file transfer mechanism type failed.
 *
 * @see @ref Mtc_ImDbGetFtDefaultMech.
 */
ZFUNC ZINT Mtc_ImDbSetFtDefaultMech(ZUINT iFtDefaultMech);

/**
 * @brief Set IM file transfer download file directory for save 
 *
 * @param [in] pcFileDirects The download file directory.
 
 * @retval ZOK Set download file path directory successfully.
 * @retval ZFAILED Set download file path directory failed.
 *
 * @see @ref Mtc_ImDbGetFtFileDirect.
 */
ZFUNC ZINT Mtc_ImDbSetFtFileDirect(ZCHAR *pcFileDirects);

/**
 * @brief Set IM the authorization for user to use Image Share service.
 *
 * @param [in] bIsAuth Image Share service enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetIsAuth.
 */
ZFUNC ZINT Mtc_ImDbSetIsAuth(ZBOOL bIsAuth);

/**
 * @brief Set IM the maximum authorized size of the content that can be sent in 
 *   an Image Share session .
 *
 * @param [in] iMaxSizeImageShare The content maximum size in bytes.
 *
 * @retval ZOK Set content maximum size successfully.
 * @retval ZFAILED Set content maximum size failed.
 *
 * @see @ref Mtc_ImDbGetMaxSizeImageShare.
 */
ZFUNC ZINT Mtc_ImDbSetMaxSizeImageShare(ZUINT iMaxSizeImageShare);

/**
 * @brief Set IM whether to send query with sdp before establishing Image Share session.
 *
 * @param [in] bImageShareQuery The query flage, 1 for send query before image share, 0 for not.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetImageShareQuery.
 */
ZFUNC ZINT Mtc_ImDbSetImageShareQuery(ZBOOL bImageShareQuery);

/**
 * @brief Set IM media protocol type.
 *
 * @param [in] iType The media protocol type, @see @ref EN_MTC_IM_PROTO_TYPE.
 *
 * @retval ZOK Set media protocol type successfully.
 * @retval ZFAILED Set media protocol type failed.
 *
 * @see @ref Mtc_ImDbGetMediaProtoType.
 */
ZFUNC ZINT Mtc_ImDbSetMediaProtoType(ZUINT iType);

/**
 * @brief Set IM file transfer maxnumber running vusers.
 *
 * @param [in] iMaxNum The file transfer maxnumber running vusers.
 *
 * @retval ZOK Set file transfer maxnumber running vusers successfully.
 * @retval ZFAILED Set file transfer maxnumber running vusers failed.
 *
 * @see @ref Mtc_ImDbGetFtMaxRunVusers.
 */
ZFUNC ZINT Mtc_ImDbSetFtMaxRunVusers(ZUINT iMaxNum);

/**
 * @brief Set IM set use session mode message.
 *
 * @param [in] bFlag The use session mode message.
 *
 * @retval ZOK Set use session mode message successfully.
 * @retval ZFAILED Set use session mode message failed.
 *
 * @see @ref Mtc_ImDbGetUseSessModeMsg.
 */
ZFUNC ZINT Mtc_ImDbSetUseSessModeMsg(ZBOOL bFlag);

/**
 * @brief Set vemoticon message version.
 *
 * @param [in] pcVersion The value of the version.
 *
 * @retval ZOK Set version  successfully.
 * @retval ZFAILED Set version failed.
 *
 * @see @ref Mtc_ImDbGetVemMsgVersion.
 */
ZFUNC ZINT Mtc_ImDbSetVemMsgVersion(ZCHAR *pcVersion);

/**
 * @brief Set subscribe conference info expire.
 *
 * @param [in] iExpire subscribe expire.
 *
 * @retval ZOK Set expire successfully.
 * @retval ZFAILED Set expire failed.
 *
 * @see @ref Mtc_ImDbGetSubsConfInfoExpire.
 */
ZFUNC ZINT Mtc_ImDbSetSubsConfInfoExpire(ZUINT iExpire);

/**
 * @brief Set server url of message store.
 *
 * @param [in] pcUrl the server url.
 *
 * @retval ZOK Set server url successfully.
 * @retval ZFAILED Set server url failed.
 *
 * @see @ref Mtc_ImDbGetMsServerUrl.
 */
ZFUNC ZINT Mtc_ImDbSetMsServerUrl(ZCHAR *pcUrl);

/**
 * @brief Set server port of message store.
 *
 * @param [in] wPort the server port.
 *
 * @retval ZOK Set server port successfully.
 * @retval ZFAILED Set server port failed.
 *
 * @see @ref Mtc_ImDbGetMsServerPort.
 */
ZFUNC ZINT Mtc_ImDbSetMsServerPort(ZUSHORT wPort);

/**
 * @brief Set the TLS enable flag of message store.
 *
 * @param [in] bEnable the TLS enable flag.
 *
 * @retval ZOK Set TLS enable successfully.
 * @retval ZFAILED Set TLS enable failed.
 *
 * @see @ref Mtc_ImDbGetMsUseTls.
 */
ZFUNC ZINT Mtc_ImDbSetMsUseTls(ZBOOL bEnable);

/**
 * @brief Set the CMCC support flag of message store.
 *
 * @param [in] bSupport the CMCC support flag.
 *
 * @retval ZOK Set CMCC support successfully.
 * @retval ZFAILED Set CMCC support failed.
 *
 * @see @ref Mtc_ImDbGetMsCmccSupport.
 */
ZFUNC ZINT Mtc_ImDbSetMsCmccSupport(ZBOOL bSupport);

/**
 * @brief Set the authentication prot of message store.
 *
 * @param [in] bMsAuthProt the authentication prot flag.
 *
 * @retval ZOK Set authentication prot successfully.
 * @retval ZFAILED Set authentication prot failed.
 *
 * @see @ref Mtc_ImDbGetMsAuthProt.
 */
ZFUNC ZINT Mtc_ImDbSetMsAuthProt(ZBOOL bMsAuthProt);

/**
 * @brief Set the user name of message store.
 *
 * @param [in] pcUserName the user name.
 *
 * @retval ZOK Set user name successfully.
 * @retval ZFAILED Set user name failed.
 *
 * @see @ref Mtc_ImDbGetMsUserName.
 */
ZFUNC ZINT Mtc_ImDbSetMsUserName(ZCHAR *pcUserName);

/**
 * @brief Set the user password of message store.
 *
 * @param [in] pcUserPwd the user password.
 *
 * @retval ZOK Set user password successfully.
 * @retval ZFAILED Set user password failed.
 *
 * @see @ref Mtc_ImDbGetMsUserPwd.
 */
ZFUNC ZINT Mtc_ImDbSetMsUserPwd(ZCHAR *pcUserPwd);

/**
 * @brief Set the user msidn of message store.
 *
 * @param [in] pcUserMsisdn the user msidn.
 *
 * @retval ZOK Set user msidn successfully.
 * @retval ZFAILED Set user msidn failed.
 *
 * @see @ref Mtc_ImDbGetMsUserMsisdn.
 */
ZFUNC ZINT Mtc_ImDbSetMsUserMsisdn(ZCHAR *pcUserMsisdn);

/**
 * @brief Set the cache directory of message store.
 *
 * @param [in] pcCacheDir the cache directory.
 *
 * @retval ZOK Set cache directory successfully.
 * @retval ZFAILED Set cache directory failed.
 *
 * @see @ref Mtc_ImDbGetMsCacheDir.
 */
ZFUNC ZINT Mtc_ImDbSetMsCacheDir(ZCHAR *pcCacheDir);

/**
 * @brief Set the im spam uri.
 *
 * @param [in] pcSpamUri the spam uri.
 *
 * @retval ZOK Set spam uri successfully.
 * @retval ZFAILED Set spam uri failed.
 *
 * @see @ref Mtc_ImDbGetMsCacheDir.
 */
ZFUNC ZINT Mtc_ImDbSetSpamUri(ZCHAR *pcSpamUri);

/**
 * @brief Get gzip list number.
 *
 * @param [in] iGzipLstNum The list number that list should be gziped.
 *
 * @retval ZOK Set the number successfully.
 * @retval ZFAILED Set the number failed.
 *
 * @see @ref Mtc_ImDbGetGzipListNumber
 */
ZFUNC ZINT Mtc_ImDbSetGzipListNumber(ZUINT iGzipLstNum);

/**
 * @brief set file transfer support inactive flag.
 *
 * @param [in] bSupInactive support inactive flag.
 *
 * @retval ZOK  if Set file transfer support inactive flag successfully, otherwise retval ZFAILED
 *
 */
ZFUNC ZINT Mtc_ImDbSetSupInactive(ZBOOL bSupInactive);

/**

 * @brief set http set conference info server port.
 *
 * @param [in] pcHost the conference info server port.
 *
 * @retval ZOK Set port successfully.
 * @retval ZFAILED Set port failed.
 *
 * @see @ref Mtc_ImDbGetHttpGetConfInfoServPort.
 */
ZFUNC ZINT Mtc_ImDbSetHttpGetConfInfoServPort(ZUSHORT wPort);

/**

 * @brief set carbon copy allowd terminal type.
 *
 * @param [in] ucType the allowd terminal type.
 *
 * @retval ZOK Set allowd terminal successfully.
 * @retval ZFAILED Set allowd terminal failed.
 *
 * @see @ref Mtc_ImDbGetCCAllowedTerminalType.
 */
ZFUNC ZINT Mtc_ImDbSetCCAllowedTerminalType(ZUCHAR ucType);

/**
 * @brief Set allowed sms.
 *
 * @param [in] bAllowedSms the allowed sms flag.
 *
 * @retval ZOK Set allowed sms successfully.
 * @retval ZFAILED Set allowed sms failed.
 *
 * @see @ref Mtc_ImDbGetAllowedSms.
 */
ZFUNC ZINT Mtc_ImDbSetAllowedSms(ZBOOL bAllowedSms);

/**
 * @brief Set allowed offline.
 *
 * @param [in] bAllowedOffline the allowed offline flag.
 *
 * @retval ZOK Set allowed offline successfully.
 * @retval ZFAILED Set allowed offline failed.
 *
 * @see @ref Mtc_ImDbGetAllowedOffline.
 */
ZFUNC ZINT Mtc_ImDbSetAllowedOffline(ZBOOL bAllowedOffline);

/**
 * @brief Set allowed sms type.
 *
 * @param [in] iAllowedSmsType the allowed sms type, @see @ref EN_MTC_IM_ALLOWED_SMS_TYPE.
 *
 * @retval ZOK Set allowed sms type successfully.
 * @retval ZFAILED Set allowed sms type failed.
 *
 * @see @ref Mtc_ImDbGetAllowedSmsType.
 */
ZFUNC ZINT Mtc_ImDbSetAllowedSmsType(ZUINT iAllowedSmsType);

/**
 * @brief Get allowed sms type.
 *
 * @return allowed sms type.
 *
 * @see @ref Mtc_ImDbSetAllowedSmsType.
 */
ZFUNC ZUINT Mtc_ImDbGetAllowedSmsType();

/**
 * @brief Set IM the supportive for the user to use the group chat service.
 *
 * @param [in] bGroupChatSupt group chat service enable flag.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetGroupChatSupt.
 */
ZFUNC ZINT Mtc_ImDbSetGroupChatSupt(ZBOOL bGroupChatSupt);

/**
 * @brief Set IM set use grp https enable.
 *
 * @param [in] bEnable enable https group manage.
 *
 * @retval ZOK Set enable flag successfully.
 * @retval ZFAILED Set enable flag failed.
 *
 * @see @ref Mtc_ImDbGetGrpHttpsEnable.
 */
ZFUNC ZINT Mtc_ImDbSetGrpHttpsEnable(ZBOOL bEnable);

/**
 * @brief Set IM get use grp https enable.
 *
 * @retval goup manage https flag.
 *
 * @see @ref Mtc_ImDbSetGrpHttpsEnable.
 */
ZFUNC ZBOOL Mtc_ImDbGetGrpHttpsEnable(ZFUNC_VOID);


#ifdef __cplusplus
}
#endif
    
#endif /* _MTC_IM_DB_H__ */

