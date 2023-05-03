#ifndef SORTMAJORLEAGUESTADIUMS_H
#define SORTMAJORLEAGUESTADIUMS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class sortMajorLeagueStadiums; }
QT_END_NAMESPACE

class sortMajorLeagueStadiums : public QMainWindow
{
    Q_OBJECT

public:
    sortMajorLeagueStadiums(QWidget *parent = nullptr);
    ~sortMajorLeagueStadiums();

private:
    Ui::sortMajorLeagueStadiums *ui;
};
#endif // SORTMAJORLEAGUESTADIUMS_H
