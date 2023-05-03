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


// loads the team name only form the databse return in model so can only use for table view or any view.
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

// take in a selected team name and outputs all the information on that selected team, return in model so can only use a table view or any view
QSqlQueryModel* DBmanager::loadTeamInfo(QString selectedTeamName){
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select * from stadium_info where teamName ='" +selectedTeamName+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    qry.exec();
    qry.first();

    if(!qry.isValid())
    {
        qDebug() << "\nError Loading baseball team name\n";
    }else{
//        while(qry.next()){
//            team.teamName               = qry.value(0).toString();
//            team.stadiumName            = qry.value(1).toString();
//            team.seatingCapacity        = qry.value(2).toInt();
//            team.location               = qry.value(3).toString();
//            team.playingSurface         = qry.value(4).toString();
//            team.league                 = qry.value(5).toString();
//            team.dateOpened             = qry.value(6).toInt();
//            team.distanceToCenterFiled  = qry.value(7).toInt();
//            team.ballParkTypology       = qry.value(8).toString();
//            team.roofType               = qry.value(9).toString();
//                //print all the data out in the console
//        }
    }
    model->setQuery(qry);
    return model;
}

// loads the all the team form the databse return in model so can only use for table view or any view.
QSqlQueryModel* DBmanager::loadAllTeam(){
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select * from stadium_info;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading baseball team name\n";
    }

    model->setQuery(qry);
    return model;
}

// loads the all the team form the databse return in model so can only use for table view or any view.
QSqlQueryModel* DBmanager::loadMajorLeagueTeam(){
    QSqlQueryModel* model = new QSqlQueryModel();
    QString leagueName = "National";

    QString sQry = "select teamName, stadiumName from stadium_info where league = '" +leagueName+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading baseball team name\n";
    }

    model->setQuery(qry);
    return model;
}

// loads the all the team form the databse return in model so can only use for table view or any view.
QSqlQueryModel* DBmanager::loadAmericanLeagueTeam(){
    QSqlQueryModel* model = new QSqlQueryModel();
    QString leagueName = "American";

    QString sQry = "select teamName, stadiumName from stadium_info where league = '" +leagueName+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading baseball team name\n";
    }

    model->setQuery(qry);
    return model;
}

