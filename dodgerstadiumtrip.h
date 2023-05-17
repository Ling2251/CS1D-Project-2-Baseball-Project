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
#include<QLabel>

struct EdgeD{
    QString destination;
    int distance;
};


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
   // void on_stadiumComboBox_activated(const QString &text);
    void on_stadiumComboBox_activated(int index);

private:
    Ui::dodgerstadiumtrip *ui;
    QStandardItemModel *m_model;
    QMap<QString, QList<EdgeD>> graph;
    QLabel *distanceLabel;

    void addEdge(const QString& source, const QString& destination, int distance);
    int calculateDistance(const QString& source, const QString& destination);
};

#endif // DODGERSTADIUMTRIP_H

