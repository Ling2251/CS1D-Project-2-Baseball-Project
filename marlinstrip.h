#ifndef MARLINSTRIP_H
#define MARLINSTRIP_H

#include <QDialog>

namespace Ui {
class marlinstrip;
}

class marlinstrip : public QDialog
{
    Q_OBJECT

public:
    explicit marlinstrip(QWidget *parent = nullptr);
    ~marlinstrip();

private:
    Ui::marlinstrip *ui;
};

#endif // MARLINSTRIP_H
