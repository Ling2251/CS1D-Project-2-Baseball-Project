#ifndef SORTMAJORLEAGUENAMES_H
#define SORTMAJORLEAGUENAMES_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class sortMajorLeagueNames; }
QT_END_NAMESPACE

class sortMajorLeagueNames : public QMainWindow
{
    Q_OBJECT

public:
    sortMajorLeagueNames(QWidget *parent = nullptr);
    ~sortMajorLeagueNames();

private:
    Ui::sortMajorLeagueNames *ui;
};
#endif // SORTMAJORLEAGUENAMES_H
