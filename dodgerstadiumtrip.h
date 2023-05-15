#ifndef DODGERSTADIUMTRIP_H
#define DODGERSTADIUMTRIP_H

#include <QtCore/QCoreApplication>
#include <QtCore/QMap>
#include <QtCore/QSet>
#include <QtCore/QVector>
#include <QtCore/QDebug>
#include <QDialog>
#include<QComboBox>
#include <QString>
#include<QVBoxLayout>
#include<iostream>
#include <QStandardItemModel>

typedef QMap<QString, QMap<QString, double>> Graph;

namespace Ui {
class dodgerstadiumtrip;
}

class dodgerstadiumtrip : public QDialog
{
    Q_OBJECT

public:
    explicit dodgerstadiumtrip(QWidget *parent = nullptr);
    ~dodgerstadiumtrip();
    double dijkstra(const Graph &graph, const QString& start, const QString& end, QMap<QString, QString> &previous)
    {
        QMap<QString, double> distances;
        for (const QString &node : graph.keys())
        {
            distances[node] = std::numeric_limits<double>::infinity();
            previous[node] = "";
        }
        distances[start] = 0.0;

        QSet<QString> unvisitedNodes;
        for (const QString &node : graph.keys())
        {
            distances[node] = std::numeric_limits<double>::infinity();
            previous[node] = "";
        }
        distances[start] = 0.0;

        while (!unvisitedNodes.isEmpty())
        {
            QString currentNode;
            double shortestDistance = std::numeric_limits<double>::infinity();
            for (const QString &node : unvisitedNodes)
            {
                if (distances[node] < shortestDistance)
                {
                    currentNode = node;
                    shortestDistance = distances[node];
                }
            }

            unvisitedNodes.remove(currentNode);

            for(const QString &neighbor : graph[currentNode].keys())
            {
                double distance = distances[currentNode] + graph[currentNode][neighbor];
                if(distance < distances[neighbor])
                {
                    distances[neighbor] = distance;
                    previous[neighbor] = currentNode;
                }
            }
        }
        return distances[end];
    }


QVector<QString> getPath(const QMap<QString, QString> &previous, const QString &start, const QString &end)
{
    QVector<QString> path;
    QString currentNode = end;
    while (currentNode != start)
    {
        path.prepend(currentNode);
        currentNode = previous[currentNode];
    }
    path.prepend(start);
    return path;
}

void displayDijkstra()
{
    //QCoreApplication a();

    // Example graph representing the area around Dodgers stadium and a few nearby locations
    Graph graph = {
        {"Dodgers stadium", {{"Union Station", 1.5}, {"Echo Park Lake", 0.8}}},
        {"Union Station", {{"Dodgers stadium", 1.5}, {"Los Angeles City Hall", 1.2}}},
        {"Echo Park Lake", {{"Dodgers stadium", 0.8}, {"Elysian Park", 1.3}}},
        {"Elysian Park", {{"Echo Park Lake", 1.3}, {"Griffith Observatory", 3.5}}},
        {"Griffith Observatory", {{"Elysian Park", 3.5}, {"Santa Monica Pier", 15.2}}},
        {"Santa Monica Pier", {{"Griffith Observatory", 15.2}, {"Other team location", 14.5}}},
        {"Other team location", {{"Santa Monica Pier", 14.5}}}
    };

    QMap<QString, QString> previous;
    double distance = dijkstra(graph, "Dodgers stadium", "Other team location", previous);
    QVector<QString> path = getPath(previous, "Dodgers stadium", "Other team location");

    qDebug() << "Shortest distance:" << distance << "miles";
    qDebug() << path.join(" -> ");

    //return a.exec();
}

//comboBox is not being added
//void showDialog()
//{
//    QDialog dialog;
//    QComboBox *comboBox = new QComboBox();
//    comboBox->addItem("Dodger Stadium");
//    comboBox->addItem("Angel Stadium");
//    comboBox->addItem("Petco Park");
//    comboBox->addItem("Fenway Park");

//    QVBoxLayout *layout = new QVBoxLayout();
//    layout->addWidget(comboBox);
//    dialog.setLayout(layout);
//    dialog.exec();
//}

private slots:
   // void on_stadiumComboBox_activated(const QString &text);
    void on_stadiumComboBox_activated(int index);

private:
    Ui::dodgerstadiumtrip *ui;
    QStandardItemModel *m_model;
};

#endif // DODGERSTADIUMTRIP_H

