#ifndef SHORTCUSTOMTRIP_H
#define SHORTCUSTOMTRIP_H
#include<QLabel>
#include<QDialog>

struct EdgeS{
    QString destination;
    int distance;
};
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
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

private:
    Ui::shortcustomtrip *ui;
    QMap<QString, QList<EdgeS>> graph;
    QLabel* distanceLabel;

    void addEdge(const QString& source, const QString& destination, int distance);
    int calculateDistance(const QString& source, const QString& destination);
};

#endif // SHORTCUSTOMTRIP_H
