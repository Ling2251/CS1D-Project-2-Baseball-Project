#ifndef SHORTCUSTOMTRIP_H
#define SHORTCUSTOMTRIP_H

#include <QDialog>
#include <connecteUIPgae.h>

namespace Ui {
class shortcustomtrip;
}

class shortcustomtrip : public QDialog
{
    Q_OBJECT

public:
    explicit shortcustomtrip(QWidget *parent = nullptr);
    ~shortcustomtrip();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::shortcustomtrip *ui;
    DBmanager m_database;           /**< database manager variable*/
};

#endif // SHORTCUSTOMTRIP_H
