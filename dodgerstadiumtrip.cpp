#include "dodgerstadiumtrip.h"
#include "ui_dodgerstadiumtrip.h"
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include<QStandardItem>
#include<QStandardItemModel>

dodgerstadiumtrip::dodgerstadiumtrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodgerstadiumtrip)
{
    ui->setupUi(this);

    //set QLablel to say "Dodger Stadium"
    ui->label_2->setText("Current Stadium: Dodger Stadium");

    //create and add distance QLabel widget
    distanceLabel = new QLabel(this);

    m_model = new QStandardItemModel(this);
    // Connect the activated() signal to the on_stadiumComboBox_activated() slot
    //connect(ui->stadiumComboBox, SIGNAL(activated(QString)),
    //        this, SLOT(on_stadiumComboBox_activated(QString)));

    connect(ui->stadiumComboBox, QOverload<int>::of(&QComboBox::activated),
        this, &dodgerstadiumtrip::on_stadiumComboBox_activated);

    //add edges to graph
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

    ui->stadiumComboBox->addItem("Dodger Stadium");
    ui->stadiumComboBox->addItem("Yankee Stadium");
    ui->stadiumComboBox->addItem("Fenway Park");
    ui->stadiumComboBox->addItem("Dodger Stadium");
    ui->stadiumComboBox->addItem("Oracle Park");
    ui->stadiumComboBox->addItem("Oakland-Alameda County Coliseum");
    ui->stadiumComboBox->addItem("Angel Stadium of Anaheim");
    ui->stadiumComboBox->addItem("Petco Park");
    ui->stadiumComboBox->addItem("Chase Field");
    ui->stadiumComboBox->addItem("Safeco Field");
    ui->stadiumComboBox->addItem("Coors Field");
    ui->stadiumComboBox->addItem("Globe Life Park in Arlington");
    ui->stadiumComboBox->addItem("Minute Maid Park");
    ui->stadiumComboBox->addItem("Target Field");
    ui->stadiumComboBox->addItem("Kauffman Stadium");
    ui->stadiumComboBox->addItem("Busch Stadium");
    ui->stadiumComboBox->addItem("Miller Park");
    ui->stadiumComboBox->addItem("Wrigley Field");
    ui->stadiumComboBox->addItem("Guaranteed Rate Field");
    ui->stadiumComboBox->addItem("Comerica Park");
    ui->stadiumComboBox->addItem("Progressive Field");
    ui->stadiumComboBox->addItem("Great American Ball Park");
    ui->stadiumComboBox->addItem("Sun Trust Park");
    ui->stadiumComboBox->addItem("Sun Trust Park");
    ui->stadiumComboBox->addItem("Tropicana Field");
    ui->stadiumComboBox->addItem("Marlins Park");
    ui->stadiumComboBox->addItem("Rogers Centre");
    ui->stadiumComboBox->addItem("PNC Park");
    ui->stadiumComboBox->addItem("Yankee Stadium");
    ui->stadiumComboBox->addItem("Citizens Bank");
    ui->stadiumComboBox->addItem("Oriole Park at Camden Yard");
    ui->stadiumComboBox->addItem("Nationals Park");
    ui->stadiumComboBox->addItem("Fenway Park");
    ui->stadiumComboBox->addItem("Citi Field");
    ui->stadiumComboBox->addItem("Citizens Bank Park");




    m_model->setItem(0, 0, new QStandardItem("Dodger Stadium"));
    m_model->setItem(1, 0, new QStandardItem("Yankee Stadium "));
    m_model->setItem(2, 0, new QStandardItem("Fenway Park"));
    m_model->setItem(3, 0, new QStandardItem("Oracle Park"));
    m_model->setItem(4, 0, new QStandardItem("Oakland-Alameda County Coliseum"));
    m_model->setItem(5, 0, new QStandardItem("Angel Stadium of Anaheim"));
    m_model->setItem(6, 0, new QStandardItem("Petco Park"));
    m_model->setItem(7, 0, new QStandardItem("Chase Field"));
    m_model->setItem(8, 0, new QStandardItem("Safeco Field"));
    m_model->setItem(9, 0, new QStandardItem("Coors Field"));
    m_model->setItem(10, 0, new QStandardItem("Globe Life Park in Arlington"));
    m_model->setItem(11, 0, new QStandardItem("Minute Maid Park"));
    m_model->setItem(12, 0, new QStandardItem("Target Field"));
    m_model->setItem(13, 0, new QStandardItem("Kauffman Stadium"));
    m_model->setItem(14, 0, new QStandardItem("Busch Stadium"));
    m_model->setItem(15, 0, new QStandardItem("Miller Park"));
    m_model->setItem(16, 0, new QStandardItem("Wrigley Field"));
    m_model->setItem(17, 0, new QStandardItem("Guaranteed Rate Field"));
    m_model->setItem(18, 0, new QStandardItem("Comerica Park"));
    m_model->setItem(19, 0, new QStandardItem("Progressive Field"));
    m_model->setItem(20, 0, new QStandardItem("Great American Ball Park"));
    m_model->setItem(21, 0, new QStandardItem("Sun Trust Park"));
    m_model->setItem(22, 0, new QStandardItem("Tropicana Field"));
    m_model->setItem(23, 0, new QStandardItem("Marlins Park"));
    m_model->setItem(24, 0, new QStandardItem("Rogers Centre"));
    m_model->setItem(25, 0, new QStandardItem("PNC Park"));
    m_model->setItem(26, 0, new QStandardItem("Yankee Stadium"));
    m_model->setItem(27, 0, new QStandardItem("Oriole Park at Camden Yard"));
    m_model->setItem(28, 0, new QStandardItem("Nationals Park"));
    m_model->setItem(29, 0, new QStandardItem("Fenway Park"));
    m_model->setItem(30, 0, new QStandardItem("Citi Field"));
    m_model->setItem(31, 0, new QStandardItem("Citizens Bank Park"));

    // Set model data
       int row = 0;
       for (const QString& stadium : graph.keys()) {
           m_model->setItem(row++, 0, new QStandardItem(stadium));
       }
       ui->tableView->setModel(m_model);

    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Stretch);
}

dodgerstadiumtrip::~dodgerstadiumtrip()
{
    delete ui;
}

void dodgerstadiumtrip::on_stadiumComboBox_activated(int index)
{
    QString selectedStadium = ui->stadiumComboBox->currentText();
    qDebug() << "Selected item:" << index << "-----" << selectedStadium;

    // Calculate and display the total distance
    QString sourceStadium = "Dodger Stadium";
    int totalDistance = calculateDistance(sourceStadium, selectedStadium);
    qDebug() << "Total Distance:" << totalDistance;

    //update the text of the distance QLabel
    distanceLabel->setText("Total Distance: " + QString::number(totalDistance) + " mi");
}

void dodgerstadiumtrip::addEdge(const QString& source, const QString& destination, int distance)
{
    EdgeD edge;
    edge.destination = destination;
    edge.distance = distance;

    //assuming graph is undirected
    graph[source].append(edge);
    graph[destination].append({source, distance});
}

int dodgerstadiumtrip::calculateDistance(const QString& source, const QString& destination)
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
        for (const EdgeD& edge : graph[currentStadium])
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



