#ifndef INTPUTDATA_H
#define INTPUTDATA_H

#include <QDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QAxObject>

namespace Ui {
class intputData;
}

class intputData : public QDialog
{
    Q_OBJECT

public:
    explicit intputData(QWidget *parent = nullptr);
    ~intputData();

private slots:
    void on_mainPagrButton_clicked();

    void on_submitButton_clicked();

    void on_InputFileDistenct_clicked();

    void on_InputFileMLB_clicked();

private:
    Ui::intputData *ui;
};

#endif // INTPUTDATA_H
