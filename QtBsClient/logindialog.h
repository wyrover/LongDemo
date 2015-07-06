#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

signals:
    void SendLogin( const QString& msg );
    void SendReg( const QString& msg );

public slots:
    void ReadReg( const QString& msg );


private slots:
    void on_regbutton_clicked();

    void on_loginbutton_clicked();

    void on_Username_editingFinished();

private:
    Ui::LoginDialog *ui;

    QWidget* m_sParent;
};

#endif // LOGINDIALOG_H
