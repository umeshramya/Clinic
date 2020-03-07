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
    User user;
    Role role;

//    DataConnection* Conn = DataConnection::getInstance();
    QSqlDatabase db = DataConnection::getInstance()->openConnection();

    try {

        QString userName = ui->lineEdit_userName->text();
        QString password = ui->lineEdit_password->text();
        QString sql =  SQL::LoginUser();

        QSqlQuery query;
        query.prepare(sql);
        query.bindValue(":username", userName);
        query.bindValue(":password", password);
        query.exec();
        while(query.next()){
            //id, username, name, email, mobile, address, is_doctor, is_active, role"
            QMessageBox::information(this, "", query.value(1).toString());
            role.setCurRole(query.value(8).toString());

            user.setId(query.value(0).toInt());
            user.setUserName(query.value(1).toString());
            user.setName(query.value(2).toString());
            user.setEmail(query.value(3).toString());
            user.setMobile(query.value(4).toString());
            user.setAddress(query.value(5).toString());
            user.setIsDoctor(query.value(6).toBool());
            user.setIsActive(query.value(7).toBool());
            user.setRole(query.value(8).toString());

        }

        DataConnection::getInstance()->closeConnection();
        Login::close();

    } catch (QString error) {
        QMessageBox::critical(this, "Invalid Login", error);
    }

}

void Login::on_pushButton_quit_clicked()
{
    QApplication::quit();
}
