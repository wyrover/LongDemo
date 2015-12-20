#include "cglobaldata.h"

#include "../ProtocolLogic/rapidjson/filewritestream.h"
#include "../ProtocolLogic/rapidjson/filereadstream.h"
#include <fstream>
#include <new>

CGlobalData* CGlobalData::_instance = nullptr;

CGlobalData* CGlobalData::getInstance()
{
    if( nullptr == _instance )
    {
        _instance = new (std::nothrow) CGlobalData();
    }
    return _instance;
}

CGlobalData::CGlobalData()
{
    InitData();
}

void CGlobalData::InitData()
{
    _bLogonAuto = false;
    _bRemberPwd = false;
    std::ifstream iFile;
    iFile.open("data.json");
    if( !iFile )
    {
        //
        std::ofstream oFile("data.json");
    }
    else
    {
        //存在
    }
}

void CGlobalData::LoadParameter()
{
    std::ifstream iFile("data.json");
}

