#include "newuser.h"
#include "ui_newuser.h"
#include "QMessageBox"
#include "Classes/dataconnection.h"
#include "Source/SQL.h"

NewUser::NewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUser)
{
    ui->setupUi(this);
}

NewUser::~NewUser()
{
    delete ui;
}

void NewUser::on_pushButton_newUser_clicked()
{
    try {
        DataConnection::getInstance()->openConnection();
        QSqlQuery query;
        QString sql =SQL::CreatUser();

        query.prepare(sql);
        if(ui->lineEdit_name->text().length() <= 0){
            throw  QString("username is required");
        }

        QString username = ui->lineEdit_userName->text();
        QString password = ui->lineEdit_password->text();
        QString confirmPassword = ui->lineEdit_confirmPassword->text();
        QString name = ui->lineEdit_name->text();
        QString email = ui->lineEdit_email->text();
        QString mobile = ui->lineEdit_mobile->text();
        QString role = ui->comboBox_role->currentText();
        bool isDoctor = ui->checkBox_isDoctor->isChecked();
        QString address = ui->textEdit_address->toPlainText();




        if(password.compare(confirmPassword) != 0){
            throw QString("Password and Confirm password are to same");
        }

//        :username, :password, :name, :email, :mobile, :address, :doctor, :role

        query.bindValue("username", username);
        query.bindValue(":password", password);
        query.bindValue(":name", name);
        query.bindValue("email", email);
        query.bindValue(":mobile", mobile);
        query.bindValue(":address", address);
        query.bindValue(":doctor", isDoctor);
        query.bindValue(":role", role);

        query.exec();
        DataConnection::getInstance()->closeConnection();

    } catch (QString err) {
        DataConnection::getInstance()->closeConnection();
        QMessageBox::critical(this, "Criticle Error", err);

    }





}
