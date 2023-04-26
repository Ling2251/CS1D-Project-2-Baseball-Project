#include "differentdistance.h"
#include "ui_differentdistance.h"
#include "mainwindow.h"

DifferentDistance::DifferentDistance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DifferentDistance)
{
    ui->setupUi(this);
}

DifferentDistance::~DifferentDistance()
{
    delete ui;
}

void DifferentDistance::on_mainPagrButton_clicked()
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

