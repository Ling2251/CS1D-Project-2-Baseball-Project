#ifndef INTPUTDATA_H
#define INTPUTDATA_H

#include <QDialog>
#include <QCoreApplication>
#include <QFileDialog>
#include <QTextStream>
#include "dbmanager.h"

namespace Ui {
class intputData;
}

class intputData : public QDialog
{
    Q_OBJECT

public:
    explicit intputData(QWidget *parent = nullptr);
    ~intputData();

private slots:
    void on_NewStadiumInfo_clicked();

    void on_NewDistenctInfo_clicked();

private:
    Ui::intputData *ui;
    DBmanager my_database;
};

#endif // INTPUTDATA_H
