#ifndef ROLE_H
#define ROLE_H
#include "user.h"

//Singleton Class
class Role
{
    static Role* instance;
    Role(){};
    QString roles[7]={"Admin", "Director", "Doctor", "Accountant", "Receptionist", "Guest"};
    QString curRole = "Guest";

public:

    static Role* getInstance();
    QString getCurRole() const;
    void setCurRole(const QString &value);

    QString getAllRoles();


};

#endif // ROLE_H
