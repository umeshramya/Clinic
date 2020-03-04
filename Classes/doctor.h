#ifndef DOCTOR_H
#define DOCTOR_H
#include "QString"

class Doctor
{
    static QString name;
    static QString qualification;
    static QString registrationNumber;
    static QString gender;
    static QString department;

public:
    Doctor();
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
