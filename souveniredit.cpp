#include "souveniredit.h"
#include "ui_souveniredit.h"

souvenirEdit::souvenirEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::souvenirEdit)
{
    ui->setupUi(this);
}

souvenirEdit::~souvenirEdit()
{
    delete ui;
}
