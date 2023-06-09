#ifndef MAINTENANCEPAGE_H
#define MAINTENANCEPAGE_H

#include <QDialog>
#include <souveniredit.h>
#include <stadiumedit.h>
#include <intputdata.h>

namespace Ui {
class maintenancePage;
}

class maintenancePage : public QDialog
{
    Q_OBJECT

public:
    explicit maintenancePage(QWidget *parent = nullptr);
    ~maintenancePage();

private slots:


    void on_SouvenirButton_clicked();

    void on_stadiumButton_clicked();

    void on_mainPagrButton_clicked();

    void on_readNewData_clicked();

private:
    Ui::maintenancePage *ui;
};

#endif // MAINTENANCEPAGE_H
