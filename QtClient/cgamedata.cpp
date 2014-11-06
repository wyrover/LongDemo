#include "cgamedata.h"

CGameData::CGameData()
{
}

CGameData::~CGameData()
{

}

void CGameData::ReSet()
{

}

CGameData* CGameData::ShareGameData()
{
    static CGameData *m_pGameData = nullptr;
    if( nullptr == m_pGameData )
    {
        m_pGameData = CreateGameData();
    }
    return m_pGameData;
}

CGameData* CGameData::CreateGameData()
{
    CGameData* lpGD = new CGameData;
    if( lpGD != nullptr)
    {
        lpGD->ReSet();
    }

    return lpGD;
}
