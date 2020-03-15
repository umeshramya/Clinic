#include "role.h"

Role *Role::getInstance()
{
    if(!instance){
        instance = new Role;
    }
    return  instance;
}

QString Role::getCurRole() const
{
    return curRole;
}

void Role::setCurRole(const QString &value)
{
    QString role = value;
    int foundRole = this->roles.indexOf(role);
    if(foundRole < 0){
        throw QString("Invalid Role");
    }else{
        this->curRole=role;
    }

}

QStringList Role::getAllRoles()
{

    this->roles.append("Admin");
    this->roles.append("Director");
    this->roles.append("Doctor");
    this->roles.append("Accontant");
    this->roles.append("Receptionest");
    this->roles.append("Guest");
    return this->roles;

}



Role* Role::instance=0;
