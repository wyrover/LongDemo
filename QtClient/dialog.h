#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLineEdit>
#include<QPushButton>
#include<QCheckBox>
#include<QFile>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void accept();
    void CheckRemPwd();
    void CheckAuto();
    
private:
    QLineEdit *UserName;
    QLineEdit *PassWord;
    QPushButton *LoginBtn;
    QCheckBox *RememberPwd;
    QCheckBox *AutoLogin;
    QFile *Config;
};

#endif // DIALOG_H
