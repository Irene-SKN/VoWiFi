#include "commFunc.h"
#if TMTC_PING_REMOTE
#include "ping.h"
#endif
#ifndef MAX_PATH
#define MAX_PATH 260
#endif

#define TMTC_RESET       "\033[0m"
#define TMTC_BLACK       "\033[30m"             /**< @brief Black */
#define TMTC_RED         "\033[31m"             /**< @brief Red */
#define TMTC_GREEN       "\033[32m"             /**< @brief Green */
#define TMTC_YELLOW      "\033[33m"             /**< @brief Yellow */
#define TMTC_BLUE        "\033[34m"             /**< @brief Blue */
#define TMTC_MAGENTA     "\033[35m"             /**< @brief Magenta */
#define TMTC_CYAN        "\033[36m"             /**< @brief Cyan */
#define TMTC_WHITE       "\033[37m"             /**< @brief White */
#define TMTC_BOLDBLACK   "\033[1m\033[30m"      /**< @brief Bold Black */
#define TMTC_BOLDRED     "\033[1m\033[31m"      /**< @brief Bold Red */
#define TMTC_BOLDGREEN   "\033[1m\033[32m"      /**< @brief Bold Green */
#define TMTC_BOLDYELLOW  "\033[1m\033[33m"      /**< @brief Bold Yellow */
#define TMTC_BOLDBLUE    "\033[1m\033[34m"      /**< @brief Bold Blue */
#define TMTC_BOLDMAGENTA "\033[1m\033[35m"      /**< @brief Bold Magenta */
#define TMTC_BOLDCYAN    "\033[1m\033[36m"      /**< @brief Bold Cyan */
#define TMTC_BOLDWHITE   "\033[1m\033[37m"      /**< @brief Bold White */

CCommFunc::CCommFunc()
{
}

ZCHAR * CCommFunc::UstrNCpy(ZCHAR *pcDst, const ZCHAR *pcSrc, ZINT iCount)
{
    ZCONST ZCHAR *pcTmpSrc = pcSrc;
    ZCHAR *pcTmpDst;

    if (!pcDst || !pcSrc)
        return ZNULL;

    pcTmpDst = pcDst;

    if (iCount)
    {
        do
        {
            if (!(*pcTmpDst++ = *pcTmpSrc++)) break;
        } while (--iCount);
    }

    if (iCount) *pcTmpDst++ = '\0';

    return pcDst;
}

ZBOOL CCommFunc::UpingRemoteIp(const ZCHAR *acIp)
{
    cout << "Start Ping Remote Ip[" << acIp << "]" << endl;
#if TMTC_PING_REMOTE
    PingResult pingRet;
    Ping ping;

    // SOCK_RAW need root authority
    ping.ping(acIp, 1, pingRet);
    if (pingRet.nreceived != pingRet.nsend)
        return ZFALSE;
#endif
    return ZTRUE;
}

ZVOID CCommFunc::AccountAdp(ZUINT iType, ZCHAR *pcUserName, ZCHAR *pcDomain, string &strAuthName, string &strUsrName)
{
    if (TCHECK_ISEMPTY_STR(pcUserName) || TCHECK_ISEMPTY_STR(pcDomain))
        return;
    switch (iType)
    {
     case EN_ACCOUNT_FIXSNUMBER:
     {
        strAuthName += "+";
        strAuthName += pcUserName;
        strAuthName += "@";
        strAuthName += pcDomain;

        strUsrName += "+";
        strUsrName += pcUserName;
        strUsrName += "@";
        strUsrName += pcDomain;
     }
     break;
     case EN_ACCOUNT_SIP:
     {
        strAuthName = pcUserName;
        strUsrName  = pcUserName;
     }
     break;
     case EN_ACCOUNT_PHONE:
     {
        strAuthName += pcUserName;
        strAuthName += "@";
        strAuthName += pcDomain;

        strUsrName += "+";
        strUsrName += pcUserName;
        strUsrName += "@";
        strUsrName += pcDomain;
     }
     break;
    default:
        break;
    }
}

ZVOID CCommFunc::CoverToUri(ZCHAR *pcIp, const string &strSrc, string &strDst)
{
    strDst.clear();
    if (TCHECK_ISEMPTY_STR(pcIp))
     {
          strDst += string("tel:");
          strDst += strSrc;
     }
     else
     {
         strDst += string("sip:");
         strDst += strSrc;
         strDst += string("@");
         strDst += pcIp;
     }

    return ;
}

ZVOID CCommFunc::PrintInTermiate(ZUCHAR uacType, const string& strPrint, ZBOOL bBold /*= ZFALSE*/)
{
   switch(uacType)
   {
     case EN_PRINT_WHITE:
     {
        if (bBold)
            std::cout << TMTC_BOLDWHITE << strPrint << endl;
        else
            std::cout << TMTC_WHITE << strPrint << endl;

        std::cout << TMTC_RESET;
     }
     break;
     case EN_PRINT_RED:
     {
        if (bBold)
           std::cout << TMTC_BOLDRED << strPrint << endl;
        else
           std::cout << TMTC_RED << strPrint << endl;

        std::cout << TMTC_RESET;
     }
     break;
     case EN_PRINT_GREEN:
     {
         if (bBold)
             std::cout << TMTC_BOLDGREEN << strPrint << endl;
         else
             std::cout << TMTC_GREEN << strPrint << endl;

         std::cout << TMTC_RESET;
     }
     break;
     case EN_PRINT_RESET:
     {
        std::cout << TMTC_RESET;
     }
     break;
     default:
     {
        if (bBold)
            std::cout << TMTC_BOLDBLACK << strPrint << endl;
        else
            std::cout << TMTC_BLACK  << strPrint << endl;

        std::cout << TMTC_RESET;
     }
     break;
   }
}

ZVOID CCommFunc::GetCurDirecoty(const string & strName, string& strPath)
{
    strPath.clear();
    ZCHAR szWorkDir[MAX_PATH] = {0} ;

    if(!getcwd(szWorkDir, MAX_PATH))
    {
        return ;
    }

    strPath = szWorkDir ;
    strPath.append("/") ;
    strPath.append(strName);
}

ZINT CCommFunc::DirMake(ZCHAR *pcDirName, ZUINT iFlag)
{
    if (!pcDirName) return ZFAILED;

    mode_t tMode = 0;

    if (iFlag & ZFILE_URD) tMode |= S_IRUSR;
    if (iFlag & ZFILE_UWR) tMode |= S_IWUSR;
    if (iFlag & ZFILE_UEXE) tMode |= S_IXUSR;

    if (iFlag & ZFILE_GRD) tMode |= S_IRGRP;
    if (iFlag & ZFILE_GWR) tMode |= S_IWGRP;
    if (iFlag & ZFILE_GEXE) tMode |= S_IXGRP;

    if (iFlag & ZFILE_ORD) tMode |= S_IROTH;
    if (iFlag & ZFILE_OWR) tMode |= S_IWOTH;
    if (iFlag & ZFILE_OEXE) tMode |= S_IXOTH;

    /* make the dir */
    if (mkdir(pcDirName, tMode) != 0)
    {
        string strTmp = string(pcDirName) + string("Directory Make failed.");
        CCommFunc::PrintInTermiate(EN_PRINT_RED, strTmp);
        return ZFAILED;
    }

    return ZOK;
}

ZINT CCommFunc::DirRemove(ZCHAR *pcDirName)
{
    /* remove the dir */
    if (rmdir(pcDirName) != 0)
    {
        string strTmp = string(pcDirName) + string("DirRemove dir failed.");
        CCommFunc::PrintInTermiate(EN_PRINT_RED, strTmp);
        return ZFAILED;
    }

    return ZOK;
}

ZVOID CCommFunc::ObtainCurTime(time_t time, string& strTime)
{
    ZCHAR cBuf[TMTC_DATA_LEN] ={0};
    tm *t = localtime(&time);
    strTime.clear();

    snprintf(cBuf, TMTC_DATA_LEN, "%4d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    strTime = cBuf;
}

#define TMTC_INVALID_SOCKET  -1
ZVOID CCommFunc::GetLocalMac(string &strMac)
{
    struct ifreq ifr_mac;
    ZCHAR acMacAddr[30];
    ZINT iSocket;

    strMac.clear();
    iSocket = socket( AF_INET, SOCK_STREAM, 0 );
    if(TMTC_INVALID_SOCKET == iSocket)
    {
        strMac = "";
        return ;
    }

    memset(&ifr_mac, 0, sizeof(ifr_mac));
    strncpy(ifr_mac.ifr_name, "eth0", sizeof(ifr_mac.ifr_name)-1);

    if((ioctl( iSocket, SIOCGIFHWADDR, &ifr_mac)) < 0)
      return;

    sprintf(acMacAddr,"%02x%02x%02x%02x%02x%02x",
                    (unsigned char)ifr_mac.ifr_hwaddr.sa_data[0],
                    (unsigned char)ifr_mac.ifr_hwaddr.sa_data[1],
                    (unsigned char)ifr_mac.ifr_hwaddr.sa_data[2],
                    (unsigned char)ifr_mac.ifr_hwaddr.sa_data[3],
                    (unsigned char)ifr_mac.ifr_hwaddr.sa_data[4],
                    (unsigned char)ifr_mac.ifr_hwaddr.sa_data[5]);

    LOGI << "Local Mac Address:" << acMacAddr;
    strMac= acMacAddr;
    close( iSocket );
    return ;
}

ZVOID CCommFunc::GetInitSign(const string& strCuei, const string& strMac, const string& strIp, string&strSign)
{
    string strTmp;
    ZCHAR acCharmd5[TMTC_MAX_MD5_LEN] = {0};
    strTmp = strCuei + strMac + strIp;

    strSign = Zmd5_StrX((ZUCHAR *)(strTmp.c_str()), strTmp.length(), ZFALSE, acCharmd5);
}

ZINT64 CCommFunc::getCurrentUnixTime()
{
    std::time_t rawtime = std::time(0);
    struct tm rawtm;
    memset(&rawtime, 0, sizeof(tm));
    auto timeInfo = localtime_r(&rawtime, &rawtm);
    if (!timeInfo)
        return false;

    return static_cast<ZINT64>(std::mktime(timeInfo));
}

ZVOID CCommFunc::PrintInLog(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    ZCHAR acLogInfo[1024] = {0};
    vsnprintf(acLogInfo, sizeof(acLogInfo)-1, format, ap);
    LOGI << acLogInfo ;
    va_end(ap);
}

ZVOID CCommFunc::EnumDirFiles(const string& dirPrefix,const string& dirName,vector<string>& vFiles)
{
    if (dirPrefix.empty() || dirName.empty())
        return;
    string dirNameTmp = dirName;
    string dirPre = dirPrefix;

    if (dirNameTmp.find_last_of("/") != dirNameTmp.length() - 1)
        dirNameTmp += "/";
    if (dirNameTmp[0] == '/')
        dirNameTmp = dirNameTmp.substr(1);
    if (dirPre.find_last_of("/") != dirPre.length() - 1)
        dirPre += "/";

    string path;

    path = dirPre + dirNameTmp;

    struct stat fileStat;
    DIR* pDir = opendir(path.c_str());
    if (!pDir) return;

    struct dirent* pDirEnt = NULL;
    while ( (pDirEnt = readdir(pDir)) != NULL )
    {
        if (strcmp(pDirEnt->d_name,".") == 0 || strcmp(pDirEnt->d_name,"..") == 0)
            continue;

        string tmpDir = dirPre + dirNameTmp + pDirEnt->d_name;
        if (stat(tmpDir.c_str(),&fileStat) != 0)
            continue;

        string innerDir = dirNameTmp + pDirEnt->d_name;
        if (fileStat.st_mode & S_IFDIR == S_IFDIR)
        {
            EnumDirFiles(dirPrefix,innerDir,vFiles);
            continue;
        }

        vFiles.push_back(innerDir);
    }

    if (pDir)
        closedir(pDir);
}

ZINT CCommFunc :: writeInZipFile(zipFile zFile,const string& file)
{
    fstream f(file.c_str(),std::ios::binary | std::ios::in);
    f.seekg(0, std::ios::end);
    long size = f.tellg();
    f.seekg(0, std::ios::beg);
    if ( size <= 0 )
    {
        return zipWriteInFileInZip(zFile, NULL, 0);
    }
    char* buf = new char[size];
    f.read(buf,size);
    int ret = zipWriteInFileInZip(zFile, buf, size);
    delete[] buf;
    return ret;
}

ZINT CCommFunc::CompressZipFile(string &dest, string &src)
{
    if (src.find_last_of("/") == src.length() - 1)
        src = src.substr(0,src.length()-1);

    struct stat fileInfo;
    stat(src.c_str(), &fileInfo);
    if (S_ISREG(fileInfo.st_mode))
    {
        zipFile zFile = zipOpen(dest.c_str(),APPEND_STATUS_CREATE);
        if (zFile == NULL)
        {
            cout<<"openfile failed"<<endl;
            return -1;
        }
        zip_fileinfo zFileInfo;
        memset(&zFileInfo, 0, sizeof(zip_fileinfo));
        int ret = zipOpenNewFileInZip(zFile,src.c_str(),&zFileInfo,NULL,0,NULL,0,NULL,0,Z_DEFAULT_COMPRESSION);
        if (ret != ZIP_OK)
        {
            cout<<"openfile in zip failed"<<endl;
            zipClose(zFile,NULL);
            return -1;
        }
        ret = writeInZipFile(zFile,src);
        if (ret != ZIP_OK)
        {
            cout<<"write in zip failed"<<endl;
            zipClose(zFile,NULL);
            return -1;
        }
        zipClose(zFile,NULL);
        cout<<"zip ok"<<endl;
    }
    else if (S_ISDIR(fileInfo.st_mode))
    {
        size_t pos = src.find_last_of("/");
        string dirName = src.substr(pos + 1);
        string dirPrefix = src.substr(0,pos);

        zipFile zFile = zipOpen(dest.c_str(),APPEND_STATUS_CREATE);
        if (zFile == NULL)
        {
            cout<<"openfile failed"<<endl;
            return -1;
        }

        vector<string> vFiles;
        EnumDirFiles(dirPrefix,dirName,vFiles);
        vector<string>::iterator itF = vFiles.begin();
        for(;itF != vFiles.end(); ++itF)
        {
            zip_fileinfo zFileInfo;
            memset(&zFileInfo, 0, sizeof(zip_fileinfo));
            int ret = zipOpenNewFileInZip(zFile,itF->c_str(),&zFileInfo,NULL,0,NULL,0,NULL,0,Z_DEFAULT_COMPRESSION);
            if (ret != ZIP_OK)
            {
                cout<<"openfile in zip failed"<<endl;
                zipClose(zFile,NULL);
                return -1;
            }
            ret = writeInZipFile(zFile,*itF);
            if (ret != ZIP_OK)
            {
                cout<<"write in zip failed"<<endl;
                zipClose(zFile,NULL);
                return -1;
            }
        }

        zipClose(zFile,NULL);
        cout<<"zip ok"<<endl;
    }

    return ZOK;
}
