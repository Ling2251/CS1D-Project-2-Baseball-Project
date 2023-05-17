#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H
#include<QLabel>
#include<QDialog>

namespace Ui {
class customtrip;
}

class customtrip : public QDialog
{
    Q_OBJECT

public:
    explicit customtrip(QWidget *parent = nullptr);
    ~customtrip();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

private:
    Ui::customtrip *ui;
    QLabel* distanceLabel;
    //graph representing the distances between stadiums
    QMap<QString, QMap<QString, int>> graph;
    //distances from the starting stadium to each stadium
    QMap<QString, int> distances;
    // Previous stadium in the shortest path from the starting stadium
    QMap<QString, QString> previousStadiums;

    void addEdge(const QString& stadium1, const QString& stadium2, int distance);
    void dijkstra(const QString& startingStadium);
};

#endif // CUSTOMTRIP_H
