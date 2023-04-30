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


// loads the team name only form the databse return in model so can only use for table widget or any widget.
QSqlQueryModel* DBmanager::loadTeamNameOnly(){
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select teamName from stadium_info;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading baseball team name\n";
    }

    model->setQuery(qry);
    return model;
}

// take in a selected team name and outputs all the information on that selected team, return in model so can only use a table widget or any widget
QSqlQueryModel* DBmanager::loadTeamInfo(QString selectedTeamName){
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select * from stadium_info where teamName ='" +selectedTeamName+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading baseball team name\n";
    }else{
//        for (auto & i : teamInfo){   //iterate through all objects in the vector
//            QString teamName                = i.teamName;
//            QString stadiumName             = i.stadiumName;
//            int     seatingCapacity         = i.seatingCapacity;
//            QString location                = i.location;
//            QString playingSurface          = i.playingSurface;
//            QString league                  = i.league;
//            int     dateOpened              = i.dateOpened;
//            int     distanceToCenterFiled   = i.distanceToCenterFiled;
//            QString ballParkTypology        = i.ballParkTypology;
//            QString roofType                = i.roofType;
//            //print all the data out in the console
//        }
    }
    model->setQuery(qry);
    return model;
}

