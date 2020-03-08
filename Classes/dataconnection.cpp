#include "dataconnection.h"
#include "Classes/settings.h"




DataConnection *DataConnection::getInstance()
{
  if(!instance){
      instance = new DataConnection;
  }
  return instance;
}

QSqlDatabase DataConnection::openConnection(){

    if(!this->db.isOpen()){

        this->db.setDatabaseName(Settings::getInstance()->getDataBaseConnectionString());
        if(!this->db.open()){
            throw QString(this->db.lastError().text());
        }

    }
    return db;
}

void DataConnection::closeConnection(){
    db.close();
}


DataConnection *DataConnection::instance=0;
