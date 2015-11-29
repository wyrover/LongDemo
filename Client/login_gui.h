#ifndef LOGIN_GUI_H
#define LOGIN_GUI_H

#include <QObject>
#include <QString>

class Login_Gui : public QObject
{
    Q_OBJECT

    //属性：用户名
    Q_PROPERTY(QString userID READ userID WRITE setUserID NOTIFY userIDChanged)

    //记住密码
    //Q_PROPERTY(bool flagRebPwd READ flagRebPwd WRITE setFlagRebPwd NOTIFY flagRebPwdChanged)
public:
    explicit Login_Gui(QObject *parent = 0);
    ~Login_Gui();

public:
    QString userID();//读取用户名
    void setUserID(const QString& str);//写入用户名

    bool flagRebPwd();
    void setFlagRebPwd(bool flagRebPwd);

signals:
    void userIDChanged();//用户名改变信号

public slots:
    void OnLogin(); //登录请求
    Q_INVOKABLE void OnRegister(); //注册

private:
    QString _strUserid;//用户名
    QString _strPassword;//密码
};

#endif // LOGIN_GUI_H
