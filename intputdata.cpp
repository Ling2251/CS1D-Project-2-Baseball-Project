#include "intputdata.h"
#include "ui_intputdata.h"

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
