#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableView>
#include <QCryptographicHash>
#include <vector>
#include <algorithm>
using namespace std;

struct teamData {
    QString team_name;
    QString stadium_name;
    int stadium_seating_capacity;
    QString stadium_location;
    QString stadium_playing_surface;
    QString team_league;
    int stadium_date_opened;
    int stadium_dist_ctrfield;
    QString stadium_typology;
    QString stadium_roof_type;
};

struct distanceEdge {
    QString team_name_origin;
    QString team_name_destination;
    int distance;
};

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
    int getseatingCapacity();
    QSqlQueryModel* loadTeamSouvenirs(QString stadiumName);
    QSqlQueryModel* loadSouvCart(QString sQry);
    void createCart();
    void deleteCart();
    void updateCartQuantity(QString stadiumName, QString souv, int quant);
    //!
    //! \brief getStadiumData
    //! \param stadium name of stadium to return data from
    //! \return teamData struct with stadium's data or team_name "ERROR" if team not found
    //!
    QString getStadiumData(const QString& stadium);
    //!
    //! \brief getStadiumNames
    //! \return vector of stadium names from database
    //!
    vector<QString> getStadiumNames();

    //!
    //! \brief getDistances
    //! \return vector containing distances to other stadiums
    //!
    vector<distanceEdge> getDistances(const QString& teamName);


private:

};

#endif // DBMANAGER_H
