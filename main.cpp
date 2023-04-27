#include "mainwindow.h"
#include "loginpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    loginPage login;
    login.show();
    return a.exec();
}
