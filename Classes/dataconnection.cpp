#include "dataconnection.h"
#include "Classes/settings.h"




QSqlDatabase DataConnection::openConnection(){
    Settings set;
    if(!this->db.isOpen()){

        this->db.setDatabaseName(set.getDataBaseConnectionString());
        if(!this->db.open()){
            throw this->db.lastError().text();
        }

    }
    return db;
}

void DataConnection::closeConnection(){
    db.close();
}


DataConnection *DataConnection::instance=0;
