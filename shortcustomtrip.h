#ifndef SHORTCUSTOMTRIP_H
#define SHORTCUSTOMTRIP_H

#include <QDialog>

namespace Ui {
class shortcustomtrip;
}

class shortcustomtrip : public QDialog
{
    Q_OBJECT

public:
    explicit shortcustomtrip(QWidget *parent = nullptr);
    ~shortcustomtrip();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

private:
    Ui::shortcustomtrip *ui;
};

#endif // SHORTCUSTOMTRIP_H
