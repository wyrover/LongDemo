
#include "Logplus.h"

Logplus *Logplus::m_Instance = nullptr;

Logplus::Logplus()
{

}

Logplus::~Logplus()
{
    if( m_Instance != nullptr )
    {
        delete m_Instance;
        m_Instance = nullptr;
    }
}

Logplus* Logplus::GetInstance()
{
    if( m_Instance == nullptr )
    {
        m_Instance = new Logplus();
    }
    return m_Instance;
}
