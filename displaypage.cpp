#include "displaypage.h"
#include "ui_displaypage.h"
#include "mainwindow.h"

DisplayPage::DisplayPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayPage)
{
    ui->setupUi(this);
}

DisplayPage::~DisplayPage()
{
    delete ui;
}



void DisplayPage::on_mainPagrButton_clicked()
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

