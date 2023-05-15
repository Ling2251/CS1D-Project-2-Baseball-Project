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
        qDebug() << "\nError Loading baseball team informations\n";
    }
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
//        }
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
        qDebug() << "\nError Loading National League team info\n";
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
        qDebug() << "\nError Loading American League team info\n";
    }

    model->setQuery(qry);
    return model;
}

// loads the team form the databse that hase the smallest center distance return in model so can only use for table view or any view.
QSqlQueryModel* DBmanager::loadSmallCenterDistanceTeam(){
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "SELECT teamName, stadiumName, distanceToCenterFileld FROM stadium_info WHERE distanceToCenterFileld = (SELECT MIN(distanceToCenterFileld) FROM stadium_info)";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading the team form the databse that hase the smallest center distance\n";
    }

    model->setQuery(qry);
    return model;
}

// loads the team form the databse that hase the grest center distance return in model so can only use for table view or any view.
QSqlQueryModel* DBmanager::loadGreatesCenterDistanceTeam(){
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "SELECT teamName, stadiumName, distanceToCenterFileld FROM stadium_info WHERE distanceToCenterFileld = (SELECT MAX(distanceToCenterFileld) FROM stadium_info)";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading the team form the databse that hase the smallest center distance\n";
    }

    model->setQuery(qry);
    return model;
}

// loads the all the team form the databse that has opend roof type return in model so can only use for table view or any view.
QSqlQueryModel* DBmanager::loadOpenRoofTypeTeam(){
    QSqlQueryModel* model = new QSqlQueryModel();
    QString roofType = "Open";

    QString sQry = "select teamName, stadiumName from stadium_info where roofType = '" +roofType+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading American League team info\n";
    }

    model->setQuery(qry);
    return model;
}


int DBmanager::getseatingCapacity()
{
    int totalSeatingCapacity = 0;

    QString sQry = "SELECT SUM(seatingCapacity) FROM stadium_info";
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec()) {
        qWarning() << "Query failed:" << qry.lastError().text();
        return 0;
    }

    if (qry.next()) {
        totalSeatingCapacity = qry.value(0).toInt();
    } else {
        qWarning() << "No result returned from query";
        return 0;
    }

    return totalSeatingCapacity;
}


vector<graphInfo> DBmanager::loadKruskalMST()
{
  
    QString sQry = "select * from stadium_Distances;";
    QSqlQuery qry;
    qry.prepare(sQry);
    graphInfo currCity;  //current City in loop
    if(!qry.exec())
    {
        qDebug() << "\nError Loading baseball team informations\n";
    } else {
        while(qry.next()){
        currCity.src = qry.value(0).toString();
        currCity.dest = qry.value(1).toString();
        currCity.wt = qry.value(2).toInt();
        graphVector.push_back(currCity);
        }
    }

   
    return graphVector;
}

