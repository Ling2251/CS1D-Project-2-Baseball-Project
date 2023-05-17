#include "dbmanager.h"

DBmanager::DBmanager()
{
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("../CS1D-Project-2-Baseball-Project/Baseball_Database.db");

    if (m_database.open())
    {
        qDebug() << "Database: connection ok";
    }
    else
    {
       qDebug() << "Error: DBManager connection with database failed";
    }
}

DBmanager::~DBmanager(){}

QSqlQueryModel* DBmanager::loadTeamNameOnly()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select teamName from stadium_info;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
    {
        qDebug() << "\nError Loading baseball team name\n";
    }

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* DBmanager::loadTeamInfo(QString selectedTeamName)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select * from stadium_info where teamName ='" +selectedTeamName+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    qry.exec();
    qry.first();

    if (!qry.isValid())
    {
        qDebug() << "\nError Loading baseball team name\n";
    }
    model->setQuery(qry);
    return model;
}

QSqlQueryModel* DBmanager::loadAllTeam()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select * from stadium_info;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
    {
        qDebug() << "\nError Loading baseball team informations\n";
    }

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* DBmanager::loadMajorLeagueTeam()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString leagueName = "National";

    QString sQry = "select teamName, stadiumName from stadium_info where league = '" +leagueName+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
    {
        qDebug() << "\nError Loading National League team info\n";
    }

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* DBmanager::loadAmericanLeagueTeam()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString leagueName = "American";

    QString sQry = "select teamName, stadiumName from stadium_info where league = '" +leagueName+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
    {
        qDebug() << "\nError Loading American League team info\n";
    }

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* DBmanager::loadSmallCenterDistanceTeam()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "SELECT teamName, stadiumName, distanceToCenterFileld FROM stadium_info WHERE distanceToCenterFileld = (SELECT MIN(distanceToCenterFileld) FROM stadium_info)";
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
    {
        qDebug() << "\nError Loading the team form the database that has the smallest center distance\n";
    }

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* DBmanager::loadGreatesCenterDistanceTeam()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "SELECT teamName, stadiumName, distanceToCenterFileld FROM stadium_info WHERE distanceToCenterFileld = (SELECT MAX(distanceToCenterFileld) FROM stadium_info)";
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
    {
        qDebug() << "\nError Loading the team form the database that has the greatest center distance\n";
    }

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* DBmanager::loadOpenRoofTypeTeam()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString roofType = "Open";

    QString sQry = "select teamName, stadiumName from stadium_info where roofType = '" +roofType+ "'";
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
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

QSqlQueryModel* DBmanager::loadTeamSouvenirs(QString stadiumName)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select itemName as 'Souvenirs', price as 'Cost($)' from stadium_Souvenirs where stadiumName = '" +stadiumName+ "';";
    qDebug() << sQry;
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
    {
        qDebug() << "\nError Loading stadium database\n";
    }

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* DBmanager::loadSouvCart(QString sQry)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare(sQry);

    if (!qry.exec())
    {
        qDebug() << "\nError Loading Souvenirs cart\n";
    }

    model->setQuery(qry);
    return model;
}

void DBmanager::createCart()
{
    QSqlQuery cartQry;
    cartQry.prepare("create table Cart as SELECT * from stadium_Souvenirs;");

    if (!cartQry.exec())
    {
        qDebug() << "\nError Creating Cart\n";
    }
    cartQry.prepare("ALTER table Cart add quantity real default 0;");
    if (!cartQry.exec())
    {
        qDebug() << "\nError Creating Quantity Column\n";
    }
}

void DBmanager::deleteCart()
{
    QSqlQuery cartQry;
    cartQry.prepare("drop table Cart;");

    if (!cartQry.exec())
    {
        qDebug() << "\nError dropping Cart\n";
    }
}

void DBmanager::updateCartQuantity(QString stadiumName, QString souv, int quant)
{
    QSqlQuery updateQry;
    QString uQry = "UPDATE Cart SET quantity = quantity+" +QString::number(quant)+ " WHERE stadiumName = '" +stadiumName+ "' and itemName = '" +souv+ "';";
    updateQry.prepare(uQry);

    if (!updateQry.exec())
    {
        qDebug() << "\nError updating Carts\n";
    }
}

QString DBmanager::getStadiumData(const QString& stadium)
{
    QString team;
    QSqlQuery query;

    query.prepare("select team_name FROM stadium_info where stadiumName='"+stadium+'"');

    query.exec();
    if (!query.next()) {
        team = query.value(0).toString();
    }
    return team;
}

vector<QString> DBmanager::getStadiumNames()
{
    vector<QString> stadiums;

    QSqlQuery query("SELECT DISTINCT stardingStadium FROM stadium_Distances");
    query.exec();

    while (query.next()) {
        QString out = query.value(0).toString();
        stadiums.push_back(out);
    }

    return stadiums;
}

vector<distanceEdge> DBmanager::getDistances(const QString& teamName)
{
    QSqlQuery query;
    vector<distanceEdge> distances;
    query.prepare("SELECT endingStadium, distance FROM stadium_Distances WHERE stardingStadium=:origin");
    query.bindValue(":origin", teamName);

    if (query.exec()) {
        while (query.next()) {
            distanceEdge edge;
            edge.team_name_origin = teamName;
            edge.team_name_destination = query.value(0).toString();
            edge.distance = query.value(1).toInt();
            distances.push_back(edge);
        }
    } else {
        qDebug() << "getDistances failed: " << query.lastError().text();
    }

    return distances;
}
