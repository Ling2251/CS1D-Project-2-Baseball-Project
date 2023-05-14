#ifndef DODGERSTADIUMTRIP_H
#define DODGERSTADIUMTRIP_H

#include <QDialog>

namespace Ui {
class dodgerstadiumtrip;
}

class dodgerstadiumtrip : public QDialog
{
    Q_OBJECT

public:
    explicit dodgerstadiumtrip(QWidget *parent = nullptr);
    ~dodgerstadiumtrip();

private slots:
    //void on_tableView_activated(const QModelIndex &index);

private:
    Ui::dodgerstadiumtrip *ui;
};

#endif // DODGERSTADIUMTRIP_H
