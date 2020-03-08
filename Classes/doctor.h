#ifndef DOCTOR_H
#define DOCTOR_H
#include "QString"

//Singleton Class
class Doctor
{
    static Doctor* instance;
    Doctor(){};
    QString name;
    QString qualification;
    QString registrationNumber;
    QString gender;
    QString department;

public:
    static Doctor* getInstance();

    QString getName() const;
    void setName(const QString &value);

    QString getQualification() const;
    void setQualification(const QString &value);

    QString getRegistrationNumber() const;
    void setRegistrationNumber(const QString &value);

    QString getGender() const;
    void setGender(const QString &value);

    QString getDepartment() const;
    void setDepartment(const QString &value);
};

#endif // DOCTOR_H
