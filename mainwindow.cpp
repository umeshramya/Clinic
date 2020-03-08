#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classes/dataconnection.h"
#include "login.h"
#include "newuser.h"
#include "frmsetting.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionLogin_triggered()
{
    Login login;
    login.setModal(true);
    login.exec();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionSignUp_triggered()
{
    NewUser newUser;
    newUser.setModal(true);
    newUser.exec();
}

void MainWindow::on_actionSettings_triggered()
{
    FrmSetting frmSetting;
    frmSetting.setModal(true);
    frmSetting.exec();
}
