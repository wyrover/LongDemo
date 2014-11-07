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
        tinyxml2::XMLDocument doc;
        tinyxml2::XMLDeclaration *declare = new tinyxml2::XMLDeclaration( "1.0", "," );
        doc.LinkEndChild( declare );
        doc.LinkEndChild( new tinyxml2::XMLComment("Config") );

        tinyxml2::XMLElement *root = new tinyxml2::XMLElement( "Config" );
        doc.LinkEndChild( root );

        doc.SaveFile( m_ConfigName.c_str() );
    }
    else
    {
       //文件存在
        _File.close();
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
    tinyxml2::XMLDocument pDoc;
    pDoc.LoadFile( m_ConfigName.c_str() );
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
