#ifndef PLANNTINGTRIP_H
#define PLANNTINGTRIP_H

#include <QDialog>
#include <QVBoxLayout>
#include <QMessageBox>
#include <dbmanager.h>
#include <QDebug>
#include <graph.h>
#include <dbmanager.h>
#include <souvenirshop.h>
#include <intputdata.h>


namespace Ui {
class PlanntingTrip;
QT_END_NAMESPACE
}

class PlanntingTrip : public QDialog
{
    Q_OBJECT

public:
    explicit PlanntingTrip(QWidget *parent = nullptr);
    ~PlanntingTrip();

private slots:

    void on_DFSpushButton_clicked();

    void on_BFSpushButton_clicked();

    void on_MSTpushButton_clicked();

    void on_startPushButton_clicked();

    void on_addPushButton_clicked();

    void on_removePushButton_clicked();

    void on_simpleStartButton_clicked();


    void on_mainPagrButton_clicked();

private:
    Ui::PlanntingTrip *ui;
    DBmanager* database;
    Graph<QString>* graph;
    // contains list of team names for combo boxes
    vector<QString> nameList;
    vector<QString> tempList;
    vector<QString> selectedList;
    void rebuildGraph();
    souvenirShop *souvenirUI;
    intputData intputUI;
    void ifLogin();
};

#endif // PLANNTINGTRIP_H
