#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include <iostream>
#include <iomanip>
#include <QString>
#include <QMessageBox>
#include <maintenancepage.h>
#include <dbmanager.h>
#include<QPixmap>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
using namespace std;


namespace Ui {
class loginPage;
}

class loginPage : public QDialog
{
    Q_OBJECT

public:
    explicit loginPage(QWidget *parent = nullptr);
    ~loginPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_cancelButton_clicked();

private:
    Ui::loginPage *ui;
};

#endif // LOGINPAGE_H
