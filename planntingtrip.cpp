#include "planntingtrip.h"
#include "ui_planntingtrip.h"

PlanntingTrip::PlanntingTrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanntingTrip)
{
    ui->setupUi(this);
}

PlanntingTrip::~PlanntingTrip()
{
    delete ui;
}
