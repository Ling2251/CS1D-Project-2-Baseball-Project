#ifndef SOUVENIRSHOP_H
#define SOUVENIRSHOP_H

#include <QDialog>

namespace Ui {
class souvenirShop;
}

class souvenirShop : public QDialog
{
    Q_OBJECT

public:
    explicit souvenirShop(QWidget *parent = nullptr);
    ~souvenirShop();

private:
    Ui::souvenirShop *ui;
};

#endif // SOUVENIRSHOP_H
