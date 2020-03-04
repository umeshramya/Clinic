#include "doctor.h"



QString Doctor::getName() const
{
    return name;
}

void Doctor::setName(const QString &value)
{
    name = value;
}

QString Doctor::getQualification() const
{
    return qualification;
}

void Doctor::setQualification(const QString &value)
{
    qualification = value;
}

QString Doctor::getRegistrationNumber() const
{
    return registrationNumber;
}

void Doctor::setRegistrationNumber(const QString &value)
{
    registrationNumber = value;
}

QString Doctor::getGender() const
{
    return gender;
}

void Doctor::setGender(const QString &value)
{
    gender = value;
}

QString Doctor::getDepartment() const
{
    return department;
}

void Doctor::setDepartment(const QString &value)
{
    department = value;
}

Doctor::Doctor()
{
    
}


QString Doctor::name                = "";
QString Doctor::qualification       = "";
QString Doctor::registrationNumber  = "";
QString Doctor::gender              = "";
QString Doctor::department          = "";
