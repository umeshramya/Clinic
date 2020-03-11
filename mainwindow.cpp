#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classes/dataconnection.h"
#include "Classes/settings.h"

#include "QFile"
#include "QDebug"
#include "QTextStream"

#include "login.h"
#include "newuser.h"
#include "frmsetting.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Settings* setting = Settings::getInstance();//set the settings

    QFile settingFile("settingFile.txt");//create file inside direct

    if(!settingFile.open(QFile::ReadOnly| QFile::Text)){//check for if exist
        settingFile.open(QFile::WriteOnly | QFile::Text);//if not exist create new file with defualt6 parametrs
        QTextStream out(&settingFile);//set write stream for file
        QString fileData =QString(setting->getDataBaseConnectionString() + "\n");
        fileData.append(setting->getTemplateFolderPath() + "\n");
        fileData.append(QString::number(setting->getLetterPadHeaderHeight()) + "\n");
        fileData.append(setting->getLetterpadType() + "\n");
        out << fileData;
        settingFile.flush();//flush after writing into file
        settingFile.close();//close file

    }else{//if file exist read the content
        QTextStream in(&settingFile);//create reading stream
        setting->setDataBaseConnectionString(in.readLine());//read line by line
        setting->setTemplateFolderPath(in.readLine());
        setting->setLetterPadHeaderHeight(in.readLine().toInt());
        setting->setLetterpadType(in.readLine());
        settingFile.close();

    }


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
