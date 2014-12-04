#ifndef SYSFUNCTION_H
#define SYSFUNCTION_H

//这个类是用来解析本地配置文件Config.xml

#include <string>

class SysFunction
{
public:
    static SysFunction *ShareFunction();

private:
    SysFunction();
    ~SysFunction();
    static bool createXMLFile();

    static SysFunction* _DefSysFunction;
    static std::string m_ConfigName;
public:

    //保存字符串
    void SaveStringData(const char* lpszKey, const char* lpszData);

    // 功能描述:  读取字符数据
    bool LoadStringData(const char* lpszKey, std::string& strReturn);

private:


};

#endif // SYSFUNCTION_H
