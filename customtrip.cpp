#include "customtrip.h"
#include "ui_customtrip.h"

customtrip::customtrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customtrip)
{
    ui->setupUi(this);
}

customtrip::~customtrip()
{
    delete ui;
}
