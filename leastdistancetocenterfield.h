#ifndef LEASTDISTANCETOCENTERFIELD_H
#define LEASTDISTANCETOCENTERFIELD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class leastDistanceToCenterField; }
QT_END_NAMESPACE

class leastDistanceToCenterField : public QMainWindow
{
    Q_OBJECT

public:
    leastDistanceToCenterField(QWidget *parent = nullptr);
    ~leastDistanceToCenterField();

private:
    Ui::leastDistanceToCenterField *ui;
};
#endif // LEASTDISTANCETOCENTERFIELD_H
