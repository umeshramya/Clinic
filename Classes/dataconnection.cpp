#include "dataconnection.h"


DataConnection::DataConnection()
{

}

QSqlDatabase DataConnection::openConnection(){
    if(!this->db.isOpen()){
        this->db.setDatabaseName("D:/ClinicRecords/ClinicRecords/Database/clinicrecords.db");
        qDebug() << QCoreApplication::applicationDirPath();
        if(this->db.open()){
            qDebug() << "connected";
        }else{
            qDebug() << this->db.lastError().text();
        }
        return db;
    }
}

void DataConnection::closeConnection(){
    db.close();
}
