#include "sysfunction.h"

//tinyxml2
#include <../../tinyxml2/tinyxml2.h>
#include <fstream>

SysFunction::SysFunction()
{
    std::fstream _File;
    _File.open( m_ConfigName.c_str(), std::ios::in );
    if( !_File )
    {
        //文件不存在
    }
    else
    {
       //文件存在
    }
}

SysFunction::~SysFunction()
{

}

SysFunction* SysFunction::ShareFunction()
{
    static SysFunction *m_SysFunction = nullptr;
    if( nullptr == m_SysFunction )
    {
        m_SysFunction = CreateFunction();
    }

    return m_SysFunction;
}

SysFunction* SysFunction::CreateFunction()
{
    SysFunction* lpSF = new SysFunction;
    if( lpSF != nullptr) {
        //lpSF->Reset();
    }

    return lpSF;
}

void SysFunction::SaveStringData(const char *lpszKey, const char *lpszData)
{

}

bool SysFunction::LoadStringData(const char *lpszKey, std::string &strReturn)
{
    tinyxml2::XMLDocument pDoc;
    pDoc.LoadFile( m_ConfigName.c_str() );

    //node
    tinyxml2::XMLElement *resEle = pDoc.RootElement()->FirstChildElement();
    const char *att = resEle->Attribute( lpszKey );
    if( nullptr != att )
    {
        strReturn = att;
    }

    pDoc.Clear();

    if( "" == strReturn )
        return false;

    return true;
}
