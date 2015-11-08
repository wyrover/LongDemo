#ifndef LOGIN_GUI_H
#define LOGIN_GUI_H

#include <QObject>
#include <QString>

class Login_Gui : public QObject
{
    Q_OBJECT

    //属性：用户名
    Q_PROPERTY(QString m_strUserid READ get_user_id WRITE set_user_id NOTIFY sig_user_id_changed)
public:
    explicit Login_Gui(QObject *parent = 0);
    ~Login_Gui();

public:
    QString get_user_id();//读取用户名
    void set_user_id(QString user_id);//写入用户名

signals:
    void sig_user_id_changed();//用户名改变信号

public slots:
    void OnLogin(); //登录请求
    void OnRegister(); //注册

private:
    QString m_strUserid{""};//用户名
    QString m_strPassword{""};//密码
};

#endif // LOGIN_GUI_H
