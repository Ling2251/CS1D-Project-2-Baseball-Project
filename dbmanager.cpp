#include "DBmanager.h"

DBmanager::DBmanager()
{
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    //m_database.setDatabaseName("../collegelist.db");

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
