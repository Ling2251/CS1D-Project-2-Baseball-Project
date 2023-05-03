#ifndef GREATESTDISTANCETOCENTERFIELD_H
#define GREATESTDISTANCETOCENTERFIELD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class greatestDistanceToCenterField; }
QT_END_NAMESPACE

class greatestDistanceToCenterField : public QMainWindow
{
    Q_OBJECT

public:
    greatestDistanceToCenterField(QWidget *parent = nullptr);
    ~greatestDistanceToCenterField();

private:
    Ui::greatestDistanceToCenterField *ui;
};
#endif // GREATESTDISTANCETOCENTERFIELD_H
