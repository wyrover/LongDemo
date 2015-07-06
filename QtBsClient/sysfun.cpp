#include "sysfun.h"


SysFun::SysFun()
{

}

bool SysFun::isDigitStr(QString src)
{
    //QString 转换为 char*
    QByteArray ba = src.toLatin1();
    const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

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
