#include "marlinstrip.h"
#include "ui_marlinstrip.h"
#include<QStandardItem>
#include<QStandardItemModel>
#include<QLabel>
#include<QVBoxLayout>

marlinstrip::marlinstrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::marlinstrip)
{
    ui->setupUi(this);

    //set QLabel to say "Marlins Park"
    ui->label_2->setText("Current Stadium: Marlins Park");

    //create and add distance QLabel widget
    distanceLabel = new QLabel(this);
    // ui->label->setAccessibleName(distanceLabel);

    //add edges to the graph
    addEdge("Dodger Stadium", "Oakland-Alameda County Coliseum", 340);
    addEdge("Dodger Stadium", "Angel Stadium of Anaheim", 50);
    addEdge("Angel Stadium of Anaheim", "Petco Park", 110);
    addEdge("Petco Park", "Chase Field", 300);
    addEdge("Oracle Park", "Safeco Field", 680);
    addEdge("Oakland-Alameda County Coliseum", "Chase Field", 650);
    addEdge("Petco Park", "Coors Field", 830);
    addEdge("Chase Field", "Coors Field", 580);
    addEdge("Dodger Stadium", "Target Field", 1500);
    addEdge("Safeco Field", "Target Field", 1390);
    addEdge("Chase Field", "Globe Life Park in Arlington", 870);
    addEdge("Chase Field", "Minute Maid Park", 1115);
    addEdge("Globe Life Park in Arlington", "Minute Maid", 230);
    addEdge("Coors Field", "Globe Life Park in Arlington", 650);
    addEdge("Coors Field", "Kaufmann Stadium", 560);
    addEdge("Kaufmann Stadium", "Globe Life in Arlington", 460);
    addEdge("Kaufmann Stadium", "Busch Stadium", 235);
    addEdge("Safeco Field", "Fenway Park", 2070);
    addEdge("Target Field", "Miller Park", 300);
    addEdge("Miller Park", "Wrigley Park", 80);
    addEdge("Target Field", "Busch Stadium", 465);
    addEdge("Miller Park", "Rogers Centre", 430);
    addEdge("Rogers Centre", "Comerica Park", 210);
    addEdge("Comerica Park", "Guaranteed Rate Field", 240);
    addEdge("Wrigley Field", "Guaranteed Rate Field", 50);
    addEdge("Guaranteed Rate Field", "Great American Park", 250);
    addEdge("Busch Stadium", "Great American Park", 310);
    addEdge("Comerica Park", "Progressive Field", 90);
    addEdge("Comerica Park", "Progressive Field", 90);
    addEdge("Progressive Field", "PNC Park", 115);
    addEdge("Rogers Centre", "PNC Park", 225);
    addEdge("PNC Park", "Great American Park", 260);
    addEdge("Busch Stadium", "Minute Maid Park", 680);
    addEdge("Globe Life Park in Arlington", "Sun Trust Park", 740);
    addEdge("Great American Park", "Sun Trust Park", 375);
    addEdge("PNC Park", "Yankee Stadium", 315);
    addEdge("Great American Park", "Tropican Field", 790);
    addEdge("Sun Trust Park", "Marlins Parks", 600);
    addEdge("Minute Maid", "Tropicana Field", 790);
    addEdge("Minute Maid Park", "Marlins Park", 965);
    addEdge("PNC Park", "Oriole Park at Camden Yards", 195);
    addEdge("Nationals Park", "Sun Trust", 560);
    addEdge("Oriole Park", "Nationals Park", 50);
    addEdge("Oriole Park", "Citizens Bank", 90);
    addEdge("Citizens Bank Park", "Yankee Stadium", 80);
    addEdge("Yankee Stadium", "Citi Field", 50);
    addEdge("Nationals Park", "Marlins Park", 930);
    addEdge("Citi Field", "Fenway", 195);
    addEdge("Fenway Park", "Marlins Park", 1255);

    QStandardItemModel *model = new QStandardItemModel(this);

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), this, &marlinstrip::on_comboBox_activated);

    ui->comboBox->addItem("Marlins Park");
    ui->comboBox->addItem("Tropicana Field");
    ui->comboBox->addItem("Sun Trust Park");
    ui->comboBox->addItem("Nationals Park");
    ui->comboBox->addItem("Oriole Park at Camden Yards");
    ui->comboBox->addItem("Citizens Bank Park");
    ui->comboBox->addItem("Citi Field");
    ui->comboBox->addItem("Yankee Stadium");
    ui->comboBox->addItem("Fenway Park");
    ui->comboBox->addItem("Rogers Centre");
    ui->comboBox->addItem("PNC Park");
    ui->comboBox->addItem("Progressive Field");
    ui->comboBox->addItem("Great American Park");
    ui->comboBox->addItem("Comerica Park");
    ui->comboBox->addItem("Guaranteed Rate Field");
    ui->comboBox->addItem("Busch Stadium");
    ui->comboBox->addItem("Kaufmann Stadium");
    ui->comboBox->addItem("Wrigley Field");
    ui->comboBox->addItem("Miller Park");
    ui->comboBox->addItem("Target Field");
    ui->comboBox->addItem("Globe Life Park in Arlington");
    ui->comboBox->addItem("Minute Maid Park");
    ui->comboBox->addItem("Coors Field");
    ui->comboBox->addItem("Chase Field");
    ui->comboBox->addItem("Petco Park");
    ui->comboBox->addItem("Angel Stadium of Anaheim");
    ui->comboBox->addItem("Dodger Stadium");
    ui->comboBox->addItem("Oakland-Alameda County Coliseum");
    ui->comboBox->addItem("Oracle Park");
    ui->comboBox->addItem("Safeco Field");

    model->setItem(0, 0, new QStandardItem("Marlins Park"));
    model->setItem(1, 0, new QStandardItem("Yankee Stadium "));
    model->setItem(2, 0, new QStandardItem("Fenway Park"));
    model->setItem(3, 0, new QStandardItem("Oracle Park"));
    model->setItem(4, 0, new QStandardItem("Oakland-Alameda County Coliseum"));
    model->setItem(5, 0, new QStandardItem("Angel Stadium of Anaheim"));
    model->setItem(6, 0, new QStandardItem("Petco Park"));
    model->setItem(7, 0, new QStandardItem("Chase Field"));
    model->setItem(8, 0, new QStandardItem("Safeco Field"));
    model->setItem(9, 0, new QStandardItem("Coors Field"));
    model->setItem(10, 0, new QStandardItem("Globe Life Park in Arlington"));
    model->setItem(11, 0, new QStandardItem("Minute Maid Park"));
    model->setItem(12, 0, new QStandardItem("Target Field"));
    model->setItem(13, 0, new QStandardItem("Kauffman Stadium"));
    model->setItem(14, 0, new QStandardItem("Busch Stadium"));
    model->setItem(15, 0, new QStandardItem("Miller Park"));
    model->setItem(16, 0, new QStandardItem("Wrigley Field"));
    model->setItem(17, 0, new QStandardItem("Guaranteed Rate Field"));
    model->setItem(18, 0, new QStandardItem("Comerica Park"));
    model->setItem(19, 0, new QStandardItem("Progressive Field"));
    model->setItem(20, 0, new QStandardItem("Great American Ball Park"));
    model->setItem(21, 0, new QStandardItem("Sun Trust Park"));
    model->setItem(22, 0, new QStandardItem("Tropicana Field"));
    model->setItem(23, 0, new QStandardItem("Marlins Park"));
    model->setItem(24, 0, new QStandardItem("Rogers Centre"));
    model->setItem(25, 0, new QStandardItem("PNC Park"));
    model->setItem(26, 0, new QStandardItem("Yankee Stadium"));
    model->setItem(27, 0, new QStandardItem("Oriole Park at Camden Yard"));
    model->setItem(28, 0, new QStandardItem("Nationals Park"));
    model->setItem(29, 0, new QStandardItem("Fenway Park"));
    model->setItem(30, 0, new QStandardItem("Citi Field"));
    model->setItem(31, 0, new QStandardItem("Citizens Bank Park"));
    // Set model data
       int row = 0;
       for (const QString& stadium : graph.keys()) {
           model->setItem(row++, 0, new QStandardItem(stadium));
       }
       ui->tableView->setModel(model);
    //ui->tableView->setModel(model);

    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Stretch);
}

marlinstrip::~marlinstrip()
{
    delete ui;
}

void marlinstrip::on_comboBox_activated(int index)
{
    QString selectedStadium = ui->comboBox->currentText();
    qDebug() << "Selected item:" << index << "-----" << selectedStadium;

    // Calculate and display the total distance
    QString sourceStadium = "Marlins Park";
    int totalDistance = calculateDistance(sourceStadium, selectedStadium);
    qDebug() << "Total Distance:" << totalDistance;

    //update the text of the distance QLabel
    distanceLabel->setText("Total Distance: " + QString::number(totalDistance) + " mi");
}

void marlinstrip::addEdge(const QString& source, const QString& destination, int distance)
{
    Edge edge;
    edge.destination = destination;
    edge.distance = distance;

    //assuming graph is undirected
    graph[source].append(edge);
    graph[destination].append({source, distance});
}

int marlinstrip::calculateDistance(const QString& source, const QString& destination)
{
    QMap<QString, int> distance;
    QSet<QString> visited;

    for (const QString& stadium : graph.keys())
    {
        distance[stadium] = INT_MAX;
    }

    distance[source] = 0;

    while(!visited.contains(destination))
    {
        QString currentStadium;
        int minDistance = INT_MAX;

        //find stadium with minimum distance
        for (const QString& stadium : graph.keys())
        {
            if (!visited.contains(stadium) && distance[stadium] < minDistance)
            {
                minDistance = distance[stadium];
                currentStadium = stadium;
            }
        }
        visited.insert(currentStadium);

        // Update distances for adjacent stadiums
        for (const Edge& edge : graph[currentStadium])
        {
            if (!visited.contains(edge.destination))
            {
                int newDistance = distance[currentStadium] + edge.distance;
                if (newDistance < distance[edge.destination])
                {
                    distance[edge.destination] = newDistance;
                }
            }
        }
    }
     return distance[destination];
}




