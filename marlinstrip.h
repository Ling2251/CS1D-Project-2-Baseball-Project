#ifndef MARLINSTRIP_H
#define MARLINSTRIP_H
#include<QMap>
#include<QSet>
#include<QDialog>
#include<QLabel>
#include<QVBoxLayout>

namespace Ui {
class marlinstrip;
}

struct Edge{
    QString destination;
    int distance;
};

class marlinstrip : public QDialog
{
    Q_OBJECT

public:
    explicit marlinstrip(QWidget *parent = nullptr);
    ~marlinstrip();

private slots:
    void on_comboBox_activated(int index);

    //void on_label_linkActivated(const QString &link);

private:
    Ui::marlinstrip *ui;
    QMap<QString, QList<Edge>> graph;
    QLabel* distanceLabel;

    void addEdge(const QString& source, const QString& destination, int distance);
    int calculateDistance(const QString& source, const QString& destination);
};

#endif // MARLINSTRIP_H
