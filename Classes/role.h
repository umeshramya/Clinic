#ifndef ROLE_H
#define ROLE_H
#include "user.h"


class Role
{
    QString roles[7]={"Admin", "Director", "Doctor", "Accountant", "Receptionist", "Guest"};
    static QString curRole;

public:

    Role();
    QString getCurRole() const;
    void setCurRole(const QString &value);

    QString getAllRoles();


};

#endif // ROLE_H
