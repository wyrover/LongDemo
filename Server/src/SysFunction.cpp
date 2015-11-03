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

template<class T>
const T& add( const T&a, const T&b )
{
    return a + b;
}
