#include "loginpage.h"
#include "ui_loginpage.h"

loginPage::loginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPage)
{
    ui->setupUi(this);
}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::on_pushButton_clicked()
{
    QString username, password;

    username=ui->lineEdit_1->text();
    password=ui->lineEdit_2->text();

    if(username == "user" && password == 12345)
    {

    }
    else if(username == "admin" && password == 12345)
    {

    }
    else
    {
        ui->label_3->setText("username or password is incorrect, please try again");
    }


}


void loginPage::on_pushButton_2_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
}

