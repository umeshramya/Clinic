#include "dataconnection.h"
#include "Classes/settings.h"


DataConnection::DataConnection()
{

}

QSqlDatabase DataConnection::openConnection(){
    Settings set;
    if(!this->db.isOpen()){

        this->db.setDatabaseName(set.getDataBaseConnectionString());
        if(!this->db.open()){
            qDebug() << this->db.lastError().text();
        }

    }
    return db;
}

void DataConnection::closeConnection(){
    db.close();
}
