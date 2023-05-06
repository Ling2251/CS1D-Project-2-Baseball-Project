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

private:
    Ui::shortcustomtrip *ui;
};

#endif // SHORTCUSTOMTRIP_H
