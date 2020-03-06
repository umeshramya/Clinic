#include "SQL.h"




QString SQL::LoginUser()
{
     QString sql("SELECT id, username, name, email, mobile, address, is_doctor, is_active, role");
             sql.append(" FROM users WHERE users.username = :username AND users.password = :password AND is_active = true");

     return  sql;
}


QString SQL::CreatUser()
{
   QString sql("INSERT INTO users (username, password, name, email, mobile, address, doctor)" );
    sql.append(" VALUES ");
    sql.append("(:username, :password, :name, :email, :mobile, :address, :doctor)");
    return  sql;
}


