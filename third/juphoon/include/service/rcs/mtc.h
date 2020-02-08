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
  File name     : mtc.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
    Marcos and structure definitions required by the mtc.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_H__
#define _MTC_H__

/**
 * @addtogroup MTC
 * @{
 * @brief Multimedia Talk Client
 *
 * This module is part of Multimedia Talk Client Entity. 
 * It provides interfaces using in GUI.
 * There are 2 main task got be done:
 * -# Wrap interfaces of MTF, to make it more easy to use.
 * -# Conceal the GUI process logic.
 *
 * To start MTC use code like:
 * @code
 //initialize the client
 Mtc_CliInit(profile director);

 // initialize callback functions
 Mtc_CliCbSetPrint(print callback);
 Mtc_CliCbSetRegOk(register ok callback);
 Mtc_CliCbSetRegFailed(register failed callback);
 ... (other callbacks)
 
 // open the client
 Mtc_CliOpen(user name);

 // set local ip
 Zos_InetGetLocalIp(&stIps);
 Mtc_CliDbSetLocalIp(stIps.astIps[0].u.iIp);
 
 // start client
 if (Mtc_CliStart() != ZOK)
 {
     Mtc_CliDestroy();
     return ZFAILED;
 }
 * @endcode
 *
 * To stop MTC use code like:
 * @code
 Mtc_CliStop();
 Mtc_CliClose();
 Mtc_CliDestroy();
 * @endcode
 *
 * Detail description of files in module:
 * -# @ref mtc_cli.h                 " MTC Client Interfaces "
 * -# @ref mtc_cli_cfg.h             " MTC Client Config Interfaces "
 * -# @ref mtc_cli_cb.h              " MTC Client Callback Interfaces "
 * -# @ref mtc_cli_db.h              " MTC Client Database Interfaces "
 * -# @ref mtc_buddy.h               " MTC OMA Buddy interface "
 * -# @ref mtc_buddy_blk.h           " MTC OMA Blocked Buddy Interfaces "
 * -# @ref mtc_buddy_rvk.h           " MTC OMA Revoked Buddy Interfaces "
 * -# @ref mtc_buddy_pnb.h           " MTC OMA Pnb Buddy Interfaces "
 * -# @ref mtc_buddy_cb.h            " MTC OMA Buddy Callback Interfaces "
 * -# @ref mtc_grp.h                 " MTC OMA Group interface "
 * -# @ref mtc_grp_cb.h              " MTC OMA Group Callback Interfaces "
 * -# @ref mtc_call.h                " MTC Call Interfaces "
 * -# @ref mtc_call_cfg.h            " MTC Call Config Interfaces "
 * -# @ref mtc_call_cb.h             " MTC Call Callback Interfaces "
 * -# @ref mtc_call_db.h             " MTC Call Database Interfaces "
 * -# @ref mtc_conf.h                " MTC Conference Session Interfaces "
 * -# @ref mtc_conf_cb.h             " MTC Conference Callback Interfaces "
 * -# @ref mtc_conf_db.h             " MTC Conference Database Interfaces "
 * -# @ref mtc_conf_cmcc.h           " MTC Conference Session Interfaces "
 * -# @ref mtc_conf_cmcc_cb.h        " MTC Conference Callback Interfaces "
 * -# @ref mtc_partp.h               " MTC Participant Interfaces "
 * -# @ref mtc_im.h                  " MTC IM Page Message Interfaces "
 * -# @ref mtc_im_cb.h               " MTC IM Callback Interfaces "
 * -# @ref mtc_im_db.h               " MTC IM Database Interfaces "
 * -# @ref mtc_im_large.h            " MTC IM Large Message Interfaces "
 * -# @ref mtc_im_sess.h             " MTC IM Session Interfaces "
 * -# @ref mtc_im_stfwd.h            " MTC IM Store And Forward Interfaces "
 * -# @ref mtc_im_file.h             " MTC IM File Transfer Interfaces "
 * -# @ref mtc_im_defer.h            " MTC IM Deferred Message Interfaces "
 * -# @ref mtc_im_ishare.h           " MTC IM Image Share Interfaces "
 * -# @ref mtc_im_imdn.h             " MTC IM Imdn Interfaces "
 * -# @ref mtc_im_ms.h               " MTC IM Message storage Interfaces "
 * -# @ref mtc_im_fthttp.h           " MTC IM File Transfer Via Http Interfaces "
 * -# @ref mtc_mwi.h                 " MTC MWI Interfaces "
 * -# @ref mtc_mwi_cb.h              " MTC MWI Callback Interfaces "
 * -# @ref mtc_pres.h                " MTC Presence Interface "
 * -# @ref mtc_pres_cb.h             " MTC Presence Callback Interface "
 * -# @ref mtc_pres_db.h             " MTC Presence Database Interfaces "
 * -# @ref mtc_pres_perm.h           " MTC Presence Permanent State Interface "
 * -# @ref mtc_pres_rule.h           " MTC Presence Rule interface "
 * -# @ref mtc_pres_srv.h            " MTC Presence Services Interface "
 * -# @ref mtc_pres_winfo.h          " MTC Presence Watcher Info Interface "
 * -# @ref mtc_pres_cinfo.h          " MTC Presence Contact Info Interface "
 * -# @ref mtc_vshare.h              " MTC Video share Interfaces "
 * -# @ref mtc_vshare_cb.h           " MTC Video share Callback Interfaces "
 * -# @ref mtc_vshare_db.h           " MTC Video share Database Interfaces "
 * -# @ref mtc_prof.h                " MTC Profile Interfaces "
 * -# @ref mtc_prof_cfg.h            " MTC Profile Config Interfaces "
 * -# @ref mtc_prof_db.h             " MTC Profile Database Interfaces "
 * -# @ref mtc_prov_cfg.h            " MTC Provision Config Interfaces "
 * -# @ref mtc_prov_db.h             " MTC Provision Database Interfaces "
 * -# @ref mtc_media.h               " MTC Media Interfaces "
 * -# @ref mtc_media_cb.h            " MTC Media Callback Interface "
 * -# @ref mtc_cap.h                 " MTC Capability Interface "
 * -# @ref mtc_cap_cb.h              " MTC Capability Callback Interface "
 * -# @ref mtc_cap_db.h              " MTC Capability Database Interface "
 * -# @ref mtc_cp.h                  " MTC Client Provisioning Interface "
 * -# @ref mtc_cp_cb.h               " MTC Client Provisioning Callback Interface "
 * -# @ref mtc_cp_db.h               " MTC Client Provisioning Database Interface "
 * -# @ref mtc_gs_ginfo.h            " MTC Geolocation Share Interface "
 * -# @ref mtc_gs_cb.h               " MTC Geolocation Share Callback Interface "
 * -# @ref mtc_gs_db.h               " MTC Geolocation Share Database Interface "
 * -# @ref mtc_ring.h                " MTC Ring Interfaces "
 * -# @ref mtc_uri.h                 " MTC URI Interfaces "
 * -# @ref mtc_lcs.h                 " MTC License Interfaces "
 * -# @ref mtc_util.h                " MTC Utility Interfaces "
 * -# @ref mtc_ver.h                 " MTC Version Interfaces "
 * @}
 *
 * @file mtc.h
 * @brief Multimedia Talk Client
 * 
 * To include the definitions of MTC, use the following directive:
 * @code
 * #include "mtc.h"
 * @endcode
 *
 * Detail description of files in module:
 * -# @ref mtc_cli.h                 " MTC Client Interfaces "
 * -# @ref mtc_cli_cfg.h             " MTC Client Config Interfaces "
 * -# @ref mtc_cli_cb.h              " MTC Client Callback Interfaces "
 * -# @ref mtc_cli_db.h              " MTC Client Database Interfaces "
 * -# @ref mtc_call.h                " MTC Call Interfaces "
 * -# @ref mtc_call_cfg.h            " MTC Call Config Interfaces "
 * -# @ref mtc_call_cb.h             " MTC Call Callback Interfaces "
 * -# @ref mtc_call_db.h             " MTC Call Database Interfaces "
 * -# @ref mtc_conf.h                " MTC Conference Session Interfaces "
 * -# @ref mtc_conf_cb.h             " MTC Conference Callback Interfaces "
 * -# @ref mtc_conf_db.h             " MTC Conference Database Interfaces "
 * -# @ref mtc_conf_cmcc.h           " MTC Conference Session Interfaces "
 * -# @ref mtc_conf_cmcc_cb.h        " MTC Conference Callback Interfaces "
 * -# @ref mtc_partp.h               " MTC Participant Interfaces "
 * -# @ref mtc_im.h                  " MTC IM Page Message Interfaces "
 * -# @ref mtc_im_cb.h               " MTC IM Callback Interfaces "
 * -# @ref mtc_im_db.h               " MTC IM Database Interfaces "
 * -# @ref mtc_im_large.h            " MTC IM Large Message Interfaces "
 * -# @ref mtc_im_sess.h             " MTC IM Session Interfaces "
 * -# @ref mtc_im_stfwd.h            " MTC IM Store And Forward Interfaces "
 * -# @ref mtc_im_file.h             " MTC IM File Transfer Interfaces "
 * -# @ref mtc_im_defer.h            " MTC IM Deferred Message Interfaces "
 * -# @ref mtc_im_ishare.h           " MTC IM Image Share Interfaces "
 * -# @ref mtc_im_imdn.h             " MTC IM Imdn Interfaces "
 * -# @ref mtc_im_ms.h               " MTC IM Message storage Interfaces "
 * -# @ref mtc_im_fthttp.h           " MTC IM File Transfer Via Http Interfaces "
 * -# @ref mtc_mwi.h                 " MTC MWI Interfaces "
 * -# @ref mtc_mwi_cb.h              " MTC MWI Callback Interfaces "
 * -# @ref mtc_pres.h                " MTC Presence Interface "
 * -# @ref mtc_pres_cb.h             " MTC Presence Callback Interface "
 * -# @ref mtc_pres_db.h             " MTC Presence Database Interfaces "
 * -# @ref mtc_pres_perm.h           " MTC Presence Permanent State Interface "
 * -# @ref mtc_pres_rule.h           " MTC Presence Rule interface "
 * -# @ref mtc_pres_srv.h            " MTC Presence Services Interface "
 * -# @ref mtc_pres_winfo.h          " MTC Presence Watcher Info Interface "
 * -# @ref mtc_pres_cinfo.h          " MTC Presence Contact Info Interface "
 * -# @ref mtc_vshare.h              " MTC Video share Interfaces "
 * -# @ref mtc_vshare_cb.h           " MTC Video share Callback Interfaces "
 * -# @ref mtc_vshare_db.h           " MTC Video share Database Interfaces "
 * -# @ref mtc_prof.h                " MTC Profile Interfaces "
 * -# @ref mtc_prof_cfg.h            " MTC Profile Config Interfaces "
 * -# @ref mtc_prof_db.h             " MTC Profile Database Interfaces "
 * -# @ref mtc_prov_cfg.h            " MTC Provision Config Interfaces "
 * -# @ref mtc_prov_db.h             " MTC Provision Database Interfaces "
 * -# @ref mtc_media.h               " MTC Media Interfaces "
 * -# @ref mtc_media_cb.h            " MTC Media Callback Interface "
 * -# @ref mtc_cap.h                 " MTC Capability Interface "
 * -# @ref mtc_cap_cb.h              " MTC Capability Callback Interface "
 * -# @ref mtc_cap_db.h              " MTC Capability Database Interface "
 * -# @ref mtc_cp.h                  " MTC Client Provisioning Interface "
 * -# @ref mtc_cp_cb.h               " MTC Client Provisioning Callback Interface "
 * -# @ref mtc_cp_db.h               " MTC Client Provisioning Database Interface "
 * -# @ref mtc_gs_ginfo.h            " MTC Geolocation Share Interface "
 * -# @ref mtc_gs_cb.h               " MTC Geolocation Share Callback Interface "
 * -# @ref mtc_gs_db.h               " MTC Geolocation Share Database Interface "
 * -# @ref mtc_ring.h                " MTC Ring Interfaces "
 * -# @ref mtc_uri.h                 " MTC URI Interfaces "
 * -# @ref mtc_lcs.h                 " MTC License Interfaces "
 * -# @ref mtc_util.h                " MTC Utility Interfaces "
 * -# @ref mtc_ver.h                 " MTC Version Interfaces "
 * -# @ref mtc_doodle.h              " MTC doodle interfaces "
 * -# @ref mtc_d2.h                  " MTC doodle interfaces version 2 "
 */
#include "zos_type.h"
#include "mtc_limit.h"
/* mtc support dll export */
#ifdef MTC_SUPT_DLL_EXPORT
#undef ZFUNC
#define ZFUNC ZFUNC_EXPORT
#endif /* MTC_SUPT_DLL_EXPORT */


#if((defined LIMITED_MOD_COM) || (defined LIMITED_MOD_LEMON))
    #include "mtc_util.h"                /* MTC Utility Interfaces */
    #include "mtc_cli.h"                 /* MTC Client Interfaces */
    #include "mtc_cli_cfg.h"             /* MTC Client Config Interfaces */
    #include "mtc_cli_cb.h"              /* MTC Client Callback Interfaces */
    #include "mtc_cli_db.h"              /* MTC Client Database Interfaces */
    #include "mtc_cap.h"                 /* MTC Capability Interface */
    #include "mtc_cap_cb.h"              /* MTC Capability Callback Interface */
    #include "mtc_cap_db.h"              /* MTC Capability Database Interface */
    #include "mtc_prof.h"                /* MTC Profile Interfaces */
    #include "mtc_prof_cfg.h"            /* MTC Profile Config Interfaces */
    #include "mtc_prof_db.h"             /* MTC Profile Database Interfaces */
    #include "mtc_prov_cfg.h"            /* MTC Provision Config Interfaces */
    #include "mtc_prov_db.h"             /* MTC Provision Database Interfaces */
    #include "mtc_gba.h"                 /* MTC GBA Interface */
    #include "mtc_gba_cb.h"              /* MTC GBA Callback Interface */
    #include "mtc_mwi.h"                 /* MTC MWI Interfaces */
    #include "mtc_mwi_cb.h"              /* MTC MWI Callback Interfaces */
    #include "mtc_lcs.h"                 /* MTC License Interfaces */
    #include "mtc_acv.h"                 /* MTC archive Interfaes */
    #include "mtc_acv_db.h"              /* MTC archive database Interfaes */
    #include "mtc_partp.h"               /* MTC Participant Interfaces */
    #include "mtc_uri.h"                 /* MTC URI Interfaces */
    #include "mtc_ver.h"                 /* MTC Version Interfaces */
    #include "mtc_lcs_cb.h"              /* MTC license Callback Interfaces */
    #ifdef LIMITED_MOD_COM
    #include "mtc_mod_com.h"             /* MTC module common Interfaces */  
    #endif
#endif

#if((defined LIMITED_MOD_MSG) || (defined LIMITED_MOD_LEMON))
    #include "mtc_im.h"                  /* MTC IM Page Message Interfaces */
    #include "mtc_im_cb.h"               /* MTC IM Callback Interfaces */
    #include "mtc_im_grp_cb.h"           /* MTC IM group Callback Interfaces */    
    #include "mtc_im_db.h"               /* MTC IM Database Interfaces */
    #include "mtc_im_large.h"            /* MTC IM Large Message Interfaces */
    #include "mtc_im_sess.h"             /* MTC IM Session Interfaces */
    #include "mtc_im_cmcc.h"             /* MTC IM CMCC Interfaces */
    #include "mtc_im_omsg.h"             /* MTC IM Offline Message Interfaces */
    #include "mtc_im_stfwd.h"            /* MTC IM Store And Forward Interfaces */
    #include "mtc_im_file.h"             /* MTC IM File Transfer Interfaces */
    #include "mtc_im_defer.h"            /* MTC IM Deferred Message Interfaces */
    #include "mtc_im_ishare.h"           /* MTC IM Image Share Interfaces */
    #include "mtc_im_imdn.h"             /* MTC IM Imdn Interfaces */
    #include "mtc_im_ms.h"               /* MTC IM Message storage Interfaces */
    #include "mtc_im_fthttp.h"           /* MTC IM File Transfer Via Http Interfaces */
    #include "mtc_im_grphttp.h"          /* MTC IM group manage Via Http Interfaces */
    #include "mtc_im_conf.h"             /* MTC IM Conference Manage Interfaces */
    #include "mtc_grp.h"                 /* MTC OMA Group interface */
    #include "mtc_grp_cb.h"              /* MTC OMA Group Callback Interfaces */
    #include "mtc_gs_ginfo.h"            /* MTC Geolocation Share Interface */
    #include "mtc_gs_cb.h"               /* MTC Geolocation Share Callback Interface */
    #include "mtc_gs_db.h"               /* MTC Geolocation Share Database Interface */
    #ifdef LIMITED_MOD_MSG
    #include "mtc_mod_msg.h"             /* MTC module message Interfaces */  
    #endif
#endif



#if((defined LIMITED_MOD_CP) || (defined LIMITED_MOD_LEMON))
    #include "mtc_cp.h"                  /* MTC Client Provisioning Interface */
    #include "mtc_cp_cb.h"               /* MTC Client Provisioning Callback Interface */
    #include "mtc_cp_db.h"               /* MTC Client Provisioning Database Interface */
    #ifdef LIMITED_MOD_CP
    #include "mtc_mod_cp.h"              /* MTC module cp Interfaces */  
    #endif
#endif

#ifdef LIMITED_MOD_PRES
    #include "mtc_pres.h"                /* MTC Presence Interface */
    #include "mtc_pres_cb.h"             /* MTC Presence Callback Interface */
    #include "mtc_pres_db.h"             /* MTC Presence Database Interfaces */
    #include "mtc_pres_perm.h"           /* MTC Presence Permanent State Interface */
    #include "mtc_pres_rule.h"           /* MTC Presence Rule interface */
    #include "mtc_pres_srv.h"            /* MTC Presence Services Interface */
    #include "mtc_pres_winfo.h"          /* MTC Presence Watcher Info Interface */
    #include "mtc_pres_cinfo.h"          /* MTC Presence Contact Info Interface */
    #include "mtc_buddy.h"               /* MTC OMA Buddy interface */
    #include "mtc_buddy_blk.h"           /* MTC OMA Blocked Buddy Interfaces */
    #include "mtc_buddy_rvk.h"           /* MTC OMA Revoked Buddy Interfaces */
    #include "mtc_buddy_pnb.h"           /* MTC OMA Pnb Buddy Interfaces */
    #include "mtc_buddy_cb.h"            /* MTC OMA Buddy Callback Interfaces */
    #include "mtc_mod_pres.h"            /* MTC module pres and buddy Interfaces */ 
#endif

#if((defined LIMITED_MOD_PROF) || (defined LIMITED_MOD_LEMON))
    #include "mtc_cprof.h"               /* MTC CMCC Profile Interface */
    #include "mtc_cprof_cb.h"            /* MTC CMCC Profile Callback Interface */
    #ifdef LIMITED_MOD_PROF
    #include "mtc_mod_prof.h"            /* MTC module profile Interfaces */ 
    #endif
#endif

#if((defined LIMITED_MOD_PA) || (defined LIMITED_MOD_LEMON))
    #include "mtc_pa.h"                  /* MTC Public Account Interface */
    #include "mtc_pa_cb.h"               /* MTC Public Account callback interfaces */
    #ifdef LIMITED_MOD_PA
    #include "mtc_mod_pa.h"              /* MTC module public account Interfaces */  
    #endif
#endif

#if((defined LIMITED_MOD_VOIP) || (defined LIMITED_MOD_VOICE )|| (defined LIMITED_MOD_LEMON))
    #include "mtc_call.h"                /* MTC Call Interfaces */
    #include "mtc_call_cfg.h"            /* MTC Call Config Interfaces */
    #include "mtc_call_cb.h"             /* MTC Call Callback Interfaces */
    #include "mtc_call_db.h"             /* MTC Call Database Interfaces */
    #include "mtc_vshare.h"              /* MTC Video share Interfaces */
    #include "mtc_vshare_cb.h"           /* MTC Video share Callback Interfaces */
    #include "mtc_vshare_db.h"           /* MTC Video share Database Interfaces */
    #include "mtc_ring.h"                /* MTC Ring Interfaces */ 
    #include "mtc_conf.h"                /* MTC Conference Session Interfaces */
    #include "mtc_conf_cb.h"             /* MTC Conference Callback Interfaces */
    #include "mtc_conf_db.h"             /* MTC Conference Database Interfaces */
    #include "mtc_conf_cmcc.h"           /* MTC Conference cmcc Interfaces */
    #include "mtc_conf_cmcc_cb.h"        /* MTC Conference cmcc Callback Interfaces */
    #include "mtc_media.h"               /* MTC Media Interfaces */
    #include "mtc_media_cb.h"            /* MTC Media Callback Interface */
    #if ((defined LIMITED_MOD_VOIP) || (defined LIMITED_MOD_VOICE ))
    #include "mtc_mod_voip.h"            /* MTC module voip Interfaces */ 
    #endif
#endif

#if((defined LIMITED_MOD_PRES) || (defined LIMITED_MOD_PROF) || (defined LIMITED_MOD_MSG))
    #include "mtc_mod_xdmcom.h"          /* MTC module xdm common Interfaces */ 
#endif

#ifdef LIMITED_MOD_LEMON
    #include "mtc_mod_cmcc.h"            /* MTC module cmcc Interfaces */  
#endif
 
#ifdef LIMITED_MOD_DOODLE
#include "mtc_doodle.h"              /* MTC doodle interfaces */
#include "mtc_d2.h"                  /* MTC doodle interfaces version 2 */
#endif

#endif /* _MTC_H__ */

