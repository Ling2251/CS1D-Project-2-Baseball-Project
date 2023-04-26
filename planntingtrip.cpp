#include "planntingtrip.h"
#include "ui_planntingtrip.h"
#include "mainwindow.h"

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

void PlanntingTrip::on_mainPagrButton_clicked()
{
    QList<QWidget*> topLevelWidgets = qApp->topLevelWidgets();
    foreach(QWidget *widget, topLevelWidgets) {
       QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);
       if (mainWindow) {
           // Show the main window if it was previously hidden
           if (!mainWindow->isVisible()) {
               mainWindow->show();
           }
           break;
       }
    }
    hide();
}

