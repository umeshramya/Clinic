#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classes/dataconnection.h"
#include "login.h"

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
