#ifndef USER_H
#define USER_H
#include "QString"


class User
{
    static int id;
    static QString userName;
    static QString name;
    static QString email;
    static QString mobile;
    static QString address;
    static QString role;
    static bool isDoctor;
    static bool isActive;

public:
    User();




    int getId() const;
    void setId(int value);

    QString getUserName() const;
    void setUserName(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getMobile() const;
    void setMobile(const QString &value);

    QString getAddress() const;
    void setAddress(const QString &value);

    QString getRole() const;
    void setRole(const QString &value);

    bool getIsDoctor() const;
    void setIsDoctor(bool value);

    bool getIsActive() const;
    void setIsActive(bool value);
    static QString getName();
    static void setName(const QString &value);
};


#endif // USER_H
