#include "receiptpage.h"
#include "ui_receiptpage.h"

receiptPage::receiptPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receiptPage)
{
    ui->setupUi(this);
}

receiptPage::~receiptPage()
{
    delete ui;
}
