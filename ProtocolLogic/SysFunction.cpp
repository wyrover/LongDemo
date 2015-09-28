#include "SysFunction.h"


SysFunction::SysFunction()
{

}

SysFunction::~SysFunction()
{

}

void SysFunction::PrintLog(const char *lpszLog)
{
    std::cout << lpszLog << std::endl;
}

bool SysFunction::IsDigitStr(const std::__cxx11::string strKey)
{
    const char* s = strKey.data();
    while (*s && *s >= '0' && *s <= '9')
    {
       s++;
    }

    if (*s)
    {
        //不是纯数字
        return false;
    }
    else
    {
        //是纯数字
        return true;
    }
}
