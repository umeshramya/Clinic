#include "SQL.h"



QString SQL::LoginUser()
{
    return QString("SELECT * FROM users WHERE users.username = :username AND users.password = :password");
}
