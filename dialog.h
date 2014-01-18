#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLineEdit>
#include<QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void Login();
    
private:
    QLineEdit *UserName;
    QLineEdit *PassWord;
    QPushButton *LoginBtn;
};

#endif // DIALOG_H
