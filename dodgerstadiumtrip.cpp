#include "dodgerstadiumtrip.h"
#include "ui_dodgerstadiumtrip.h"

dodgerstadiumtrip::dodgerstadiumtrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodgerstadiumtrip)
{
    ui->setupUi(this);
}

dodgerstadiumtrip::~dodgerstadiumtrip()
{
    delete ui;
}

//void dodgerstadiumtrip::on_tableView_activated(const QModelIndex &index)
//{
//    //show the stadium names

//}

