#include "login_gui.h"
#include <iostream>

#include <QDebug>

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
    std::cout << "登录" << std::endl;
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
    qDebug() << "UserID:" << str;
}

QString Login_Gui::password()
{
    return _strPassword;
}

void Login_Gui::setPassword(const QString &str)
{
    if(_strPassword != str)
    {
        _strPassword = str;
        emit passwordChanged();
    }
}

bool Login_Gui::flagRebPwd()
{
    return _bRembPwd;
}

void Login_Gui::setFlagRebPwd(bool flagRebPwd)
{
    if(_bRembPwd != flagRebPwd)
    {
        _bRembPwd = flagRebPwd;
        emit flagRebPwdChanged();
    }
    std::cout << "remember:" << flagRebPwd << std::endl;
}

bool Login_Gui::bAutoLogon()
{
    return _bAutoLogon;
}

void Login_Gui::setBAutoLogon(bool bAutoLogon)
{
    if(_bAutoLogon != bAutoLogon)
    {
        _bAutoLogon = bAutoLogon;
        emit bAutoLogonChanged();
    }
    std::cout << "AutoLogon:" << bAutoLogon << std::endl;
}
