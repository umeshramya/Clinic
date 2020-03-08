#ifndef DATACONNECTION_H
#define DATACONNECTION_H
#include "QtSql"
#include "QDebug"

//Singleton class
class DataConnection
{
  static DataConnection* instance;
  DataConnection(){};
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
public:
  static DataConnection* getInstance();
    QSqlDatabase openConnection();
    void closeConnection();
};

#endif // DATACONNECTION_H
