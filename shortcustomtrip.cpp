#include "shortcustomtrip.h"
#include "ui_shortcustomtrip.h"

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
