#include "role.h"

QString Role::getCurRole() const
{
    return curRole;
}

void Role::setCurRole(const QString &value)
{
    QString role = value;
    int foundRole = this->roles->indexOf(role);
    if(foundRole < 0){
        throw QString("Invalid Role");
    }else{
        this->curRole=role;
    }

}

Role::Role()
{
}

QString Role::curRole=QString("Guest");
