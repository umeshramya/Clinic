#include "newuser.h"
#include "ui_newuser.h"
#include "QMessageBox"
#include "Classes/dataconnection.h"
#include "Classes/role.h"
#include "Source/SQL.h"

NewUser::NewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUser)
{
    ui->setupUi(this);
    QStringList roles = Role::getInstance()->getAllRoles();
    ui->comboBox_role->addItems(roles);
    ui->comboBox_role->setCurrentText("Guest");
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

        QString userName= ui->lineEdit_userName->text().trimmed();
        QString password = ui->lineEdit_password->text().trimmed();
        QString confirmPassword = ui->lineEdit_confirmPassword->text().trimmed();
        QString name = ui->lineEdit_name->text().trimmed();
        QString email = ui->lineEdit_email->text().trimmed();
        QString mobile = ui->lineEdit_mobile->text().trimmed();
        QString role = ui->comboBox_role->currentText().trimmed();
        QString address = ui->textEdit_address->toPlainText().trimmed();
        bool isDoctor = ui->checkBox_isDoctor->isChecked();

    //validatde ui widgets
        if(userName.length() <= 0){throw  QString("username is required");}
        if(password.length() < 8){throw QString("Password has to be atleast 8 charector long");}
        if(name.length() <= 0){throw QString("Name is required");}
        if(email.length() <= 0){throw QString("Email is required");}
        if(mobile.length() <= 0){throw QString("Mobile is required");}
        if(address.length() <= 0){throw QString("Address is required");}

        QStringList roles = Role::getInstance()->getAllRoles();
        if(roles.indexOf(role) < 0){throw ("Invalid Role");}

        if(password.compare(confirmPassword) != 0){
            throw QString("Password and Confirm password are to same");
        }

//        :username, :password, :name, :email, :mobile, :address, :doctor, :role

        query.bindValue("username", userName);
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
