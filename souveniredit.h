#ifndef SOUVENIREDIT_H
#define SOUVENIREDIT_H

#include <loginpage.h>
#include <dbmanager.h>
#include <QDialog>

namespace Ui {
class souvenirEdit;
}

class souvenirEdit : public QDialog
{
    Q_OBJECT

public:
    explicit souvenirEdit(QWidget *parent = nullptr);
    ~souvenirEdit();

    void teamNameComboBox();

    bool isNumber(const QString& text);

private slots:
    void on_comboxEnterButton_clicked();

    void on_souvenirUpdateButton_clicked();

    void on_souvenirTableView_activated(const QModelIndex &index);

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::souvenirEdit *ui;

    bool addOrDelet;
};

#endif // SOUVENIREDIT_H
