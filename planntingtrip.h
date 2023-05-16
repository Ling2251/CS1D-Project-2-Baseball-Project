#ifndef PLANNTINGTRIP_H
#define PLANNTINGTRIP_H

#include <QDialog>
#include"planntingtrip.h"
#include"dodgerstadiumtrip.h"
#include"customtrip.h"


namespace Ui {
class PlanntingTrip;
}

class PlanntingTrip : public QDialog
{
    Q_OBJECT

public:
    explicit PlanntingTrip(QWidget *parent = nullptr);
    ~PlanntingTrip();

private slots:
    void on_mainPagrButton_clicked();
    //void show_trip_window();

    //void on_mainPagrButton_2_clicked();

    void on_mainPagrButton_2_clicked();

    void on_mainPagrButton_4_clicked();

    void on_mainPagrButton_3_clicked();

    void on_mainPagrButton_5_clicked();

private:
    Ui::PlanntingTrip *ui;
};

#endif // PLANNTINGTRIP_H
