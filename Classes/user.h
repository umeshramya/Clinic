#ifndef USER_H
#define USER_H
#include "QString"

//SingleTon Class
class User
{
    static User *instance;
    User(){};
    int id;
    QString userName;
    QString name;
    QString email;
    QString mobile;
    QString address;
    QString role;
    bool isDoctor;
    bool isActive;

public:
    static User* getInstance();
    int getId() const;
    void setId(int value);
    QString getUserName() const;
    void setUserName(const QString &value);
    QString getName() const;
    void setName(const QString &value);
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
};


#endif // USER_H
