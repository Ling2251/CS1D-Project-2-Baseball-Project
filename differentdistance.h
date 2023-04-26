#ifndef DIFFERENTDISTANCE_H
#define DIFFERENTDISTANCE_H

#include <QDialog>

namespace Ui {
class DifferentDistance;
}

class DifferentDistance : public QDialog
{
    Q_OBJECT

public:
    explicit DifferentDistance(QWidget *parent = nullptr);
    ~DifferentDistance();

private slots:
    void on_mainPagrButton_clicked();

private:
    Ui::DifferentDistance *ui;
};

#endif // DIFFERENTDISTANCE_H
