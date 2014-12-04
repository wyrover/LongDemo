#include "sysfunction.h"

//tinyxml2
#include <../../tinyxml2/tinyxml2.h>
#include <fstream>

SysFunction* SysFunction::_DefSysFunction = nullptr;
std::string SysFunction::m_ConfigName = std::string("Config.xml");

SysFunction::SysFunction()
{

}

SysFunction::~SysFunction()
{

}

SysFunction* SysFunction::ShareFunction()
{
    if( createXMLFile() )
        return nullptr;
    if( nullptr == _DefSysFunction )
    {
        _DefSysFunction = new SysFunction();
    }

    return _DefSysFunction;
}

bool SysFunction::createXMLFile()
{
    bool bRet = false;
    std::fstream _File;
    _File.open( m_ConfigName.c_str(), std::ios::in );
    if( !_File )
    {
        //文件不存在
        tinyxml2::XMLDocument *pxmlDoc = new tinyxml2::XMLDocument();
        pxmlDoc->LinkEndChild( pxmlDoc->NewDeclaration() );
        tinyxml2::XMLElement *RootNode = pxmlDoc->NewElement( "Config" );
        pxmlDoc->LinkEndChild( RootNode );

        pxmlDoc->SaveFile( m_ConfigName.c_str() );
    }
    else
    {
       //文件存在
        _File.close();
    }
    return bRet;
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
