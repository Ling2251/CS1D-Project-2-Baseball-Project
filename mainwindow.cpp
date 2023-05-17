#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
   hide();
   uiConnect.linkToLoginPage();
}


void MainWindow::on_displayButton_clicked()
{
    hide();
    uiConnect.linkToDisplayPage();
}


void MainWindow::on_planTripButton_clicked()
{
    hide();
    uiConnect.linkToPlanTripPage();
}



