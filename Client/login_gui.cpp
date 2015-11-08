#include "login_gui.h"

Login_Gui::Login_Gui(QObject *parent) : QObject(parent)
{

}

Login_Gui::~Login_Gui()
{

}

void Login_Gui::OnLogin()
{

}

void Login_Gui::OnRegister()
{

}

QString Login_Gui::get_user_id()
{
    return m_strUserid;
}

void Login_Gui::set_user_id(QString user_id)
{
    if( m_strUserid != user_id )
    {
        m_strUserid = user_id;
        emit sig_user_id_changed();
    }
}
