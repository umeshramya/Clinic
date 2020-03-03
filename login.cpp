#include "login.h"
#include "ui_login.h"
#include "Classes/dataconnection.h"
#include "Source/SQL.h"



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

    QString userName = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();
    QString sql = SQL::LoginUser();

    DataConnection Conn;
    QSqlDatabase db = Conn.openConnection();
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":username", userName);
    q.bindValue(":password", password);
    q.exec();
    while(q.next()){
        qDebug() << q.value(0);
        qDebug() << q.value(1);
        qDebug() << q.value(2);
    }





}
