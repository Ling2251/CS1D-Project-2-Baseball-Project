#ifndef SOUVENIREDIT_H
#define SOUVENIREDIT_H

#include "loginpage.h"
#include "dbmanager.h"
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

private:
    Ui::souvenirEdit *ui;
};

#endif // SOUVENIREDIT_H
