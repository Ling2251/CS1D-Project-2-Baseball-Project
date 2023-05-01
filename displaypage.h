#ifndef DISPLAYPAGE_H
#define DISPLAYPAGE_H

#include <QDialog>

namespace Ui {
class DisplayPage;
}

class DisplayPage : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayPage(QWidget *parent = nullptr);
    ~DisplayPage();

private slots:


    void on_mainPagrButton_clicked();

private:
    Ui::DisplayPage *ui;
};

#endif // DISPLAYPAGE_H
