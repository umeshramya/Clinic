#ifndef USER_H
#define USER_H
#include "QString"
struct StructCurUser{
    int id;
    QString userName;
    QString name;
    QString email;
    QString mobile;
    QString address;
    bool isdoctor;
    bool isActive;

};

class User
{
    static StructCurUser curUser;

public:
    User();
    void setUser(StructCurUser user);
    void setId(int id);
    void setUserName(QString userName);
    void setName(QString name);
    void setEmail(QString email);
    void setMobile(QString mobile);
    void setAddress(QString address);
    void setIsDoctor(bool isDoctor);
    void setIsActive(bool isActive);


    StructCurUser getUser();
};


#endif // USER_H
