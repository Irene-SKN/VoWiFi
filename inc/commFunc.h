#pragma once
#include "commdatadef.h"
#include "commdatadef.h"

#ifdef TMTC_ZIP_COMPRESS
#include "zip.h"
#include "unzip.h"
#endif

class CCommFunc
{
public:
    CCommFunc();
public:
   static ZCHAR* UstrNCpy(ZCHAR *pcDst, const ZCHAR *pcSrc, ZINT iCount);
   static ZBOOL UpingRemoteIp(const ZCHAR *acIp);

   static ZVOID PrintInTermiate(ZUCHAR uacType, const string& strPrint, ZBOOL bBold = ZFALSE);
   static ZVOID PrintInLog(const char* format, ...);
   static ZVOID AccountAdp(ZUINT iType, ZCHAR *pcUserName, ZCHAR *pcDomain,
                           string &strAuthName, string &strUsrName);

   static ZVOID CoverToUri(ZCHAR *pcIp, const string &strSrc, string &strDst);

   static ZVOID GetCurDirecoty(const string & strName, string& strPath);

   static ZINT  DirMake(ZCHAR *pcDirName, ZUINT iFlag);
   static ZINT  DirRemove(ZCHAR *pcDirName);
   static ZVOID ObtainCurTime(time_t time, string& strTime);
   static ZVOID GetLocalMac(string &strMac);
   static ZVOID GetInitSign(const string& strCuei, const string& strMac, const string& strIp, string&strSign);

   static ZINT64 getCurrentUnixTime();

#ifdef TMTC_ZIP_COMPRESS
   static ZINT  CompressZipFile(string &dest, string &src);
   static ZINT   writeInZipFile(zipFile zFile,const string& file);
   static ZVOID  EnumDirFiles(const string& dirPrefix,const string& dirName,vector<string>& vFiles);
#endif
};


