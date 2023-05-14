#ifndef INTPUTDATA_H
#define INTPUTDATA_H

#include <QDialog>

namespace Ui {
class intputData;
}

class intputData : public QDialog
{
    Q_OBJECT

public:
    explicit intputData(QWidget *parent = nullptr);
    ~intputData();

private:
    Ui::intputData *ui;
};

#endif // INTPUTDATA_H
