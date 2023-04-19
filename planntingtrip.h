#ifndef PLANNTINGTRIP_H
#define PLANNTINGTRIP_H

#include <QDialog>

namespace Ui {
class PlanntingTrip;
}

class PlanntingTrip : public QDialog
{
    Q_OBJECT

public:
    explicit PlanntingTrip(QWidget *parent = nullptr);
    ~PlanntingTrip();

private:
    Ui::PlanntingTrip *ui;
};

#endif // PLANNTINGTRIP_H
