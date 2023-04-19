#include "displaypage.h"
#include "ui_displaypage.h"

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
