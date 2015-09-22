#ifndef SysFunction_h
#define SysFunction_h

#include <iostream>

class SysFunction
{
private:
    SysFunction();
    ~SysFunction();

public:
    // 功能描述:  写Log
    static void PrintLog(const char* lpszLog);
};

#endif
