#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    bool GetNext();

    void Init();

private:
    Ui::MainWindow *ui;

private slots:
    void OnUpdate();

private:
    bool bNext;
};

#endif // MAINWINDOW_H
