#ifndef RECEIPTPAGE_H
#define RECEIPTPAGE_H

#include <QDialog>

namespace Ui {
class receiptPage;
}

class receiptPage : public QDialog
{
    Q_OBJECT

public:
    explicit receiptPage(QWidget *parent = nullptr);
    ~receiptPage();

private:
    Ui::receiptPage *ui;
};

#endif // RECEIPTPAGE_H
