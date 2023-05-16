#include "shortcustomtrip.h"
#include "ui_shortcustomtrip.h"
#include "souvenirshop.h"

shortcustomtrip::shortcustomtrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shortcustomtrip)
{
    ui->setupUi(this);
}

shortcustomtrip::~shortcustomtrip()
{
    delete ui;
}

void shortcustomtrip::on_pushButton_3_clicked()
{
    souvenirShop souvenirShopUI;
    souvenirShopUI.setModal(true);
    souvenirShopUI.exec();
}

