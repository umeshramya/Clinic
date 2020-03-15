#ifndef ROLE_H
#define ROLE_H
#include "user.h"
#include "QStringList"

//Singleton Class
class Role
{
    static Role* instance;
    Role(){};
    QStringList roles;
    QString curRole = "Guest";

public:

    static Role* getInstance();
    QString getCurRole() const;
    void setCurRole(const QString &value);

    QStringList getAllRoles();


};

#endif // ROLE_H
