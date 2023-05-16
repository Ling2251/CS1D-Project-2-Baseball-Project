#include "differentdistance.h"
#include "ui_differentdistance.h"
#include "mainwindow.h"
#include "dbmanager.h"
#include "graph.h"

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


//void DifferentDistance::on_DFSpushButton_clicked()
//{
//    Graph dfs;

//        int distance = graph->startDFS("Oracle Park");
//        QString pathStr;
//        for (const auto &dest : graph->dfsOrder) {
//            pathStr += dest + "\n";
//        }

//        QMessageBox msgBox;
//        msgBox.setText("DFS starting from Oracle Park (San Francisco Giants)");
//        msgBox.setInformativeText("Total distance: " + QString::number(distance));
//        msgBox.setDetailedText(pathStr);
//        msgBox.exec();
//}


//void DifferentDistance::on_BFSpushButton_clicked()
//{
//    int distance = graph->startBFS("Target Field");
//    QString pathStr;
//    for (const auto &dest : graph->bfsOrder) {
//        pathStr += dest + "\n";
//    }

//    QMessageBox msgBox;
//    msgBox.setText("BFS starting from Target Field (Minnesota Twins)");
//    msgBox.setInformativeText("Total distance: " + QString::number(distance));
//    msgBox.setDetailedText(pathStr);
//    msgBox.exec();
//}

