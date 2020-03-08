#include "login.h"
#include "ui_login.h"
#include "Classes/dataconnection.h"
#include "Source/SQL.h"
#include "Classes/role.h"
#include "Classes/user.h"
#include "QMessageBox"



Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_Login_clicked()
{





    try {
        DataConnection::getInstance()->openConnection();//opem connection
        QString userName = ui->lineEdit_userName->text();//set username
        QString password = ui->lineEdit_password->text();//set password

        QString sql =  SQL::LoginUser();//sql string

        QSqlQuery query;//sql query
        query.prepare(sql);//prepare
        query.bindValue(":username", userName);//bind username
        query.bindValue(":password", password);//bind password
        query.exec();//exec

        if(!query.first()){
            throw QString("Invalid username and password");
        }


        do{                 //loop of dataset
            //id, username, name, email, mobile, address, is_doctor, is_active, role"

           Role::getInstance()->setCurRole(query.value(8).toString());//set role and throw error if


            User::getInstance()->setId(query.value(0).toInt());//id
            User::getInstance()->setUserName(query.value(1).toString());//userbname
            User::getInstance()->setName(query.value(2).toString());//name
            User::getInstance()->setEmail(query.value(3).toString());//email
            User::getInstance()->setMobile(query.value(4).toString());//mobile
            User::getInstance()->setAddress(query.value(5).toString());//address
            User::getInstance()->setIsDoctor(query.value(6).toBool());//is_doctor
            User::getInstance()->setIsActive(query.value(7).toBool());//is_active
            User::getInstance()->setRole(query.value(8).toString());//role

        }while(query.next());

        DataConnection::getInstance()->closeConnection();//close connection
        Login::close();//close login ui

    } catch (QString error) {
        DataConnection::getInstance()->closeConnection();//close connection
        QMessageBox::critical(this, "Invalid Login", error);//error message box
    }

}

void Login::on_pushButton_quit_clicked()
{
    QApplication::quit();
}
