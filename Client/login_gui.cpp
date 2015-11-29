#include "login_gui.h"
#include <iostream>

Login_Gui::Login_Gui(QObject *parent) : QObject(parent)
{
    _strUserid = "";
    _strPassword = "";
}

Login_Gui::~Login_Gui()
{

}

void Login_Gui::OnLogin()
{

}

void Login_Gui::OnRegister()
{
    std::cout << "register" << std::endl;
}

QString Login_Gui::userID()
{
    return _strUserid;
}

void Login_Gui::setUserID(const QString& str)
{
    if(_strUserid != str)
    {
        _strUserid = str;
        emit userIDChanged();
    }
}
