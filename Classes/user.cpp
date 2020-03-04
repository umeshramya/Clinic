#include "user.h"

User::User()
{

}

void User::setUser(StructCurUser user)
{
    this->curUser= user;
}

void User::setId(int id)
{
   this->curUser.id = id;
}

void User::setUserName(QString userName)
{
    this->curUser.userName=userName;
}

void User::setName(QString name)
{
    this->curUser.name=name;
}

void User::setEmail(QString email)
{
    this->curUser.email=email;
}

void User::setMobile(QString mobile)
{
    this->curUser.mobile=mobile;
}

void User::setAddress(QString address)
{
    this->curUser.address=address;
}

void User::setIsDoctor(bool isDoctor)
{
    this->curUser.isdoctor=isDoctor;
}

void User::setIsActive(bool isActive)
{
    this->curUser.isActive=isActive;
}



StructCurUser User::getUser()
{
    return  this->curUser;
}


StructCurUser U;
StructCurUser User::curUser= U;
