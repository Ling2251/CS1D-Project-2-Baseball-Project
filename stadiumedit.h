#ifndef STADIUMEDIT_H
#define STADIUMEDIT_H

#include <QDialog>
#include"loginpage.h"
#include"souveniredit.h"
#include"dbmanager.h"
#include<qstandarditemmodel>
#include<QModelIndex>

namespace Ui {
class stadiumEdit;
}

class stadiumEdit : public QDialog
{
    Q_OBJECT

public:
    explicit stadiumEdit(QWidget *parent = nullptr);
    ~stadiumEdit();

    void teamCombox();

private slots:


    void on_enter_clicked();

    void on_update_clicked();


    void on_maintainancePushButton_clicked();

    void on_teamInfotableView_activated(const QModelIndex &index);

private:
    Ui::stadiumEdit *ui;
};

#endif // STADIUMEDIT_H
