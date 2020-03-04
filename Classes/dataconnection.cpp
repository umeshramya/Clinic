#include "dataconnection.h"
#include "Classes/settings.h"


DataConnection::DataConnection()
{

}

QSqlDatabase DataConnection::openConnection(){
    if(!this->db.isOpen()){
        Settings setting;
        this->db.setDatabaseName(setting.getDataBaseConnectionString());
        if(!this->db.open()){
            qDebug() << this->db.lastError().text();
        }

    }
    return db;
}

void DataConnection::closeConnection(){
    db.close();
}
