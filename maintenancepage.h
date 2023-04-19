#ifndef MAINTENANCEPAGE_H
#define MAINTENANCEPAGE_H

#include <QDialog>

namespace Ui {
class maintenancePage;
}

class maintenancePage : public QDialog
{
    Q_OBJECT

public:
    explicit maintenancePage(QWidget *parent = nullptr);
    ~maintenancePage();

private:
    Ui::maintenancePage *ui;
};

#endif // MAINTENANCEPAGE_H
