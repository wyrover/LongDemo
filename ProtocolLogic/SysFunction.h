#ifndef SysFunction_h
#define SysFunction_h

#include <iostream>
#include <string>

class SysFunction
{
private:
    SysFunction();
    virtual ~SysFunction();

public:
    // 功能描述:  写Log
    static void PrintLog(const char* lpszLog);

    //是否是线数字
    static bool IsDigitStr(const std::string strKey );
};

#endif
