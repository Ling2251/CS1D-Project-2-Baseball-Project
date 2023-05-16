#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QDialog>

namespace Ui {
class customtrip;
}

class customtrip : public QDialog
{
    Q_OBJECT

public:
    explicit customtrip(QWidget *parent = nullptr);
    ~customtrip();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

private:
    Ui::customtrip *ui;
};

#endif // CUSTOMTRIP_H
