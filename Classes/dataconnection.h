#ifndef DATACONNECTION_H
#define DATACONNECTION_H
#include "QtSql"
#include "QDebug"


class DataConnection
{
  static DataConnection* instance;
  DataConnection(){};
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
public:
  static DataConnection* getInstance(){
      if(!instance){
          instance = new DataConnection;
      }
      return instance;
  }
    QSqlDatabase openConnection();
    void closeConnection();
};

#endif // DATACONNECTION_H
