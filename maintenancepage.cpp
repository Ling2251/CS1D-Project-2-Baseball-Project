#include "maintenancepage.h"
#include "ui_maintenancepage.h"
#include "mainwindow.h"

maintenancePage::maintenancePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maintenancePage)
{
    ui->setupUi(this);
}

maintenancePage::~maintenancePage()
{
    delete ui;
}

void maintenancePage::on_mainPagrButton_clicked()
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

void maintenancePage::on_SouvenirButton_clicked()
{
    souvenirEdit souvenirEdit;
    hide();
    souvenirEdit.setModal(true);
    souvenirEdit.exec();
}


//void maintenancePage::on_InputFileButton_clicked()
//{
//    intputData intputData;
//    hide();
//    intputData.setModal(true);
//    intputData.exec();
//}

