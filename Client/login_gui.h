#ifndef LOGIN_GUI_H
#define LOGIN_GUI_H

#include <QObject>
#include <QString>

class Login_Gui : public QObject
{
    Q_OBJECT

    //属性：用户名
    Q_PROPERTY(QString userID READ userID WRITE setUserID NOTIFY userIDChanged)

    //用户密码
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)

    //记住密码
    Q_PROPERTY(bool flagRebPwd READ flagRebPwd WRITE setFlagRebPwd NOTIFY flagRebPwdChanged)

    //自动登陆
    Q_PROPERTY(bool bAutoLogon READ bAutoLogon WRITE setBAutoLogon NOTIFY bAutoLogonChanged)
public:
    explicit Login_Gui(QObject *parent = 0);
    ~Login_Gui();

public:
    QString userID();//读取用户名
    void setUserID(const QString& str);//写入用户名

    QString password();
    void setPassword(const QString& str);

    bool flagRebPwd();
    void setFlagRebPwd(bool flagRebPwd);

    bool bAutoLogon();
    void setBAutoLogon(bool bAutoLogon);

signals:
    void userIDChanged();//用户名改变信号

    void passwordChanged();

    void flagRebPwdChanged();

    void bAutoLogonChanged();

public slots:
    void OnLogin(); //登录请求
    void OnRegister(); //注册

private:
    QString _strUserid{""};//用户名
    QString _strPassword{""};//密码
    bool _bRembPwd{false};//
    bool _bAutoLogon{false}; //自动登陆
};

#endif // LOGIN_GUI_H
