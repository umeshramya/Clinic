#ifndef DATACONNECTION_H
#define DATACONNECTION_H
#include "QtSql"
#include "QDebug"


class DataConnection
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
public:
    DataConnection();
    QSqlDatabase openConnection();
    void closeConnection();
};

#endif // DATACONNECTION_H
