#ifndef DISPLAYPAGE_H
#define DISPLAYPAGE_H

#include <QDialog>
#include <QAbstractTableModel>
#include <QTableView>
#include <QSortFilterProxyModel>
#include "dbmanager.h"

namespace Ui {
class DisplayPage;
}

class DisplayPage : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayPage(QWidget *parent = nullptr);
    ~DisplayPage();

private slots:

    void on_mainPagrButton_clicked();

    void on_displayTeamInfo_clicked();

    void on_allTeamDisplay_clicked();

    void on_majorLeagueDisplay_clicked();

    void on_AmericanTeamDisplay_clicked();

private:
    Ui::DisplayPage *ui;
    DBmanager my_database;

    void showTeamNameCombo(QSqlQueryModel *model);
    void showTeamInfoDisplay(QSqlQueryModel *model);
};

#endif // DISPLAYPAGE_H
