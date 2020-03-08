#include "user.h"

int User::getId() const
{
    return id;
}

void User::setId(int value)
{
    id = value;
}

QString User::getUserName() const
{
    return userName;
}

void User::setUserName(const QString &value)
{
    userName = value;
}

QString User::getName() const
{
    return name;
}

void User::setName(const QString &value)
{
    name = value;
}

QString User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &value)
{
    email = value;
}

QString User::getMobile() const
{
    return mobile;
}

void User::setMobile(const QString &value)
{
    mobile = value;
}

QString User::getAddress() const
{
    return address;
}

void User::setAddress(const QString &value)
{
    address = value;
}

QString User::getRole() const
{
    return role;
}

void User::setRole(const QString &value)
{
    role = value;
}

bool User::getIsDoctor() const
{
    return isDoctor;
}

void User::setIsDoctor(bool value)
{
    isDoctor = value;
}

bool User::getIsActive() const
{
    return isActive;
}

void User::setIsActive(bool value)
{
    isActive = value;
}

User *User::getInstance()
{
    if(!instance){
        instance = new User;
    }

    return instance;
}

User* User::instance=0;
