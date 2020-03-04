#include "login.h"
#include "ui_login.h"
#include "Classes/dataconnection.h"
#include "Source/SQL.h"
#include "Classes/user.h"



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
    QString userName = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();
    QString sql =  SQL::LoginUser();





    DataConnection Conn;
    QSqlDatabase db = Conn.openConnection();
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":username", userName);
    q.bindValue(":password", password);
    q.exec();
    while(q.next()){
//id, username, name, email, mobile, address, is_doctor, is_active"

        user.setId(q.value(0).toInt());
        user.setUserName(q.value(1).toString());
        user.setName(q.value(2).toString());
        user.setEmail(q.value(3).toString());
        user.setMobile(q.value(4).toString());
        user.setAddress(q.value(5).toString());
        user.setIsDoctor(q.value(6).toBool());
        user.setIsActive(q.value(7).toBool());

    }


}

void Login::on_pushButton_quit_clicked()
{
    QApplication::quit();
}
