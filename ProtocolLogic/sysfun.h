#ifndef SYSFUN_H
#define SYSFUN_H

#include <QString>

class SysFun
{
public:
    SysFun();

    static bool isDigitStr(QString src);

    //解析收到的数据
    static void AnalysisData( const QString& data );
};

#endif // SYSFUN_H
