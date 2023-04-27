#include "dbmanager.h"

DBmanager::DBmanager()
{
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("../Baseball_Database.db");

    if(m_database.open())
    {
        qDebug() << "Database: connection ok";
    }
    else
    {
       qDebug() << "Error: DBManager connection with database failed";
    }
}

DBmanager::~DBmanager(){}
