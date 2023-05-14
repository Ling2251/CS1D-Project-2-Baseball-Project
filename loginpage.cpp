#include "loginpage.h"
#include "ui_loginpage.h"
#include "mainwindow.h"

loginPage::loginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPage)
{
    ui->setupUi(this);
    setWindowTitle("Login Page");
}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::on_pushButton_clicked()
{
    QString username,password;

    username=ui->lineEdit_1->text();
    password=ui->lineEdit_2->text();

    if(username == "Admin" && password == "12345")
    {
        QMessageBox::information(this, "Login", "Logged in");
        maintenancePage maintenance;
        hide();
        maintenance.setModal(true);
        maintenance.exec();
    }
    else
    {
        ui->label_3->setText("username or password is incorrect, please try again");
        //ui->label_3->setText(password);
        QMessageBox::warning(this, "Login", "Username or Password is Incorrect");
    }


}


void loginPage::on_pushButton_2_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
}


void loginPage::on_cancelButton_clicked()
{
    QList<QWidget*> topLevelWidgets = qApp->topLevelWidgets();
    foreach(QWidget *widget, topLevelWidgets) {
       QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);
       if (mainWindow) {
           // Show the main window if it was previously hidden
           if (!mainWindow->isVisible()) {
               mainWindow->show();
           }
           break;
       }
    }
    hide();
}

