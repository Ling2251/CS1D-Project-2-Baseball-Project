#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connecteUIPgae.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_displayButton_clicked();

    void on_planTripButton_clicked();

    void on_differentDistanceButton_clicked();

private:
    Ui::MainWindow *ui;
    DBmanager my_database;
    ConnecteUIPage uiConnect;
};
#endif // MAINWINDOW_H
