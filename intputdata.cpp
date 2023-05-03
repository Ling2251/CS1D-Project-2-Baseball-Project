#include "intputdata.h"
#include "ui_intputdata.h"
#include "mainwindow.h"

intputData::intputData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::intputData)
{
    ui->setupUi(this);
}

intputData::~intputData()
{
    delete ui;
}

void intputData::on_mainPagrButton_clicked()
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


//void intputData::on_InputFileDistenct_clicked()
//{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Excel Files (*.xlsx);;All Files (*)"));
//    QStringList hLabels;
//    hLabels << "Team Name" << "Destination" << "Mileage";

//    if((!fileName.isEmpty())){
//        ui->tableWidget->setHorizontalHeaderLabels(hLabels);
//    }
//}

//void intputData::on_InputFileMLB_clicked()
//{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Excel Files (*.xlsx);;All Files (*)"));
//    QStringList hLabels;
//    hLabels << "Team Name" << "Stadium Name" << "Seating Capacity" << "Location" << "Playing Surface" << "League"
//            << "Date Opened" << "Distance To Center Field" << "Ballpark Typology" << "Roof Type";

//    if((!fileName.isEmpty())){
//        ui->tableWidget->setHorizontalHeaderLabels(hLabels);

//        QAxObject* excel = new QAxObject("Excel.Application");
//        QAxObject* workbooks = excel->querySubObject("Workbooks");
//        QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", fileName);
//        //QAxObject* worksheet = workbook->querySubObject("Worksheets(int)", 3);
//        cout << "file readed";

//        //QAxObject* used_range = worksheet->querySubObject("UsedRange");

//        for(int i=0; i<10; i++){

//        }

//    }
//}

//void intputData::on_submitButton_clicked()
//{

//}







