#include "jpNetSDK.h"

int main()
{
   plog::init(plog::debug, "JpLog.txt", (1024*1024), 1);
   ZBOOL bRet = SDK_Init();
   if (!bRet)
   {
      CCommFunc::PrintInTermiate(EN_PRINT_RED, COVER_TO_CHAR("SDK_Init return FALSE."));
      CCommFunc::PrintInTermiate(EN_PRINT_RESET, "Termination....");
      return ZFAILED;
   }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "*          please input command		           " << endl;
    cout << "*	   -1  shutdown this                           " << endl;
    cout << "*		2 is to call please input the number       " << endl;
    cout << "*		3 is answer call                           " << endl;
    cout << "*		4 is term call                             " << endl;
    cout << "*		5 is to logout                             " << endl;
    cout << "*		6 is to login                              " << endl;
    cout << "*		7 is to send dtmf                          " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    enum EN_INPUT_TYPE
    {
        EN_INPUT_SHUTDOWN = -1,
        EN_INPUT_CALL_PHONE = 2,
        EN_INPUT_ANSWER_CALL,
        EN_INPUT_TERM_CALL,
        EN_INPUT_LOGUT,
        EN_INPUT_LOGIN,
        EN_INPUT_SENDDTMF,

        EN_INPUT_NUM
    };

    string strToNumber;
    ZINT iInputNum = EN_INPUT_NUM;
    bool bExit = false;

    CCommFunc::PrintInTermiate(EN_PRINT_WHITE, COVER_TO_CHAR("Please Input Order:"));
    while (!bExit)
    {
       cin >> iInputNum;

        if (EN_INPUT_SHUTDOWN == iInputNum)
        {
            bExit = ZTRUE;
            break;
        }
        else if(EN_INPUT_CALL_PHONE == iInputNum)
        {
            CCommFunc::PrintInTermiate(EN_PRINT_WHITE, "~~~~~~~~~~~~~~~~~~~~~");
            CCommFunc::PrintInTermiate(EN_PRINT_WHITE, COVER_TO_CHAR("Please Input Number:"));
            strToNumber.clear();

            cin >> strToNumber;

            if (!SDK_GetTakingState())
             {
                 if (!SDK_GetRegState())
                 {
                    SDK_Login(COVER_TO_CHAR("No Registed State, Upper Call OutSide."));
                    SDK_SetCallPhone(COVER_TO_CHAR(strToNumber.c_str()));
                 }
                 else
                 {
                    SDK_StartOneCall(COVER_TO_CHAR(strToNumber.c_str()));
                 }
             }
             else
             {
                 CCommFunc::PrintInTermiate(EN_PRINT_RED, COVER_TO_CHAR("It Is Calling So Can't Send Call."));
             }
        }
        else if(EN_INPUT_ANSWER_CALL == iInputNum)
        {
            CCommFunc::PrintInTermiate(EN_PRINT_WHITE, COVER_TO_CHAR("Answer Incoming Call."));
            SDK_PickUpOneCall();
        }
        else if (EN_INPUT_TERM_CALL == iInputNum)
        {
            CCommFunc::PrintInTermiate(EN_PRINT_WHITE, COVER_TO_CHAR("Term Call."));
            SDK_TermOneCall();
        }
        else if(EN_INPUT_LOGUT == iInputNum)
        {
            CCommFunc::PrintInTermiate(EN_PRINT_WHITE, COVER_TO_CHAR("Upper LogOut."));
            SDK_LoginOut();
        }
        else if(EN_INPUT_LOGIN == iInputNum)
        {
            CCommFunc::PrintInTermiate(EN_PRINT_WHITE, COVER_TO_CHAR("Upper retry Login."));
            SDK_Login(COVER_TO_CHAR("Upper Retry Login"));
        }
        else if(EN_INPUT_SENDDTMF == iInputNum)
        {
            if (!SDK_GetTakingState())
            {
               CCommFunc::PrintInTermiate(EN_PRINT_RED, COVER_TO_CHAR("Current Not Taking state."));
            }
            else
            {
               CCommFunc::PrintInTermiate(EN_PRINT_WHITE, COVER_TO_CHAR("Start Send Dtmf."));
               strToNumber.clear();
               cin >> strToNumber;

               SDK_SendDtmf(COVER_TO_CHAR(strToNumber.substr(0, 1).c_str()));
            }
        }
        else
        {
            CCommFunc::PrintInTermiate(EN_PRINT_RED, COVER_TO_CHAR("Error Order, Please Input again."));
        }

        usleep(100000);
    }

    CCommFunc::PrintInTermiate(EN_PRINT_RESET, "end....");
    return ZOK;
}

