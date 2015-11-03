#ifndef SysFunction_h
#define SysFunction_h

#include <iostream>

class SysFunction
{
private:
    SysFunction();
    virtual ~SysFunction();

public:
    // 功能描述:  写Log
    static void PrintLog(const char* lpszLog);

    template<class T>
    const T& add(const T&a, const T&b);
};

#endif
