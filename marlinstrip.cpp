#include "marlinstrip.h"
#include "ui_marlinstrip.h"

marlinstrip::marlinstrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::marlinstrip)
{
    ui->setupUi(this);
}

marlinstrip::~marlinstrip()
{
    delete ui;
}
