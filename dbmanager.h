#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QVector>
#include <QQueue>
#include <iostream>
using namespace std;

struct stadiumInfo{
    QString teamName;
    QString stadiumName;
    int     seatingCapacity;
    QString location;
    QString playingSurface;
    QString league;
    int     dateOpened;
    int     distanceToCenterFiled;
    QString ballParkTypology;
    QString roofType;
};

//vector<stadiumInfo> teamInfo;

class DBmanager
{
public:
    DBmanager();
    ~DBmanager();

    QSqlQueryModel* loadTeamNameOnly();
    QSqlQueryModel* loadTeamInfo(QString selectedTeamName);
    QSqlQueryModel* loadAllTeam();
    QSqlQueryModel* loadMajorLeagueTeam();
    QSqlQueryModel* loadAmericanLeagueTeam();
    QSqlQueryModel* loadSmallCenterDistanceTeam();
    QSqlQueryModel* loadGreatesCenterDistanceTeam();
    QSqlQueryModel* loadOpenRoofTypeTeam();

    stadiumInfo team;
private:

};

#endif // DBMANAGER_H
