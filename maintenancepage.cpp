#include "maintenancepage.h"
#include "ui_maintenancepage.h"

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

void maintenancePage::on_SouvenirButton_clicked()
{
    souvenirEdit souvenirEdit;
    hide();
    souvenirEdit.setModal(true);
    souvenirEdit.exec();
}

