#include "customtrip.h"
#include "ui_customtrip.h"
#include<QStandardItem>
#include<QStandardItemModel>


customtrip::customtrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customtrip)
{
    ui->setupUi(this);

    //connect comboBox
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), this, &customtrip::on_comboBox_activated);

    //connect other comboBox
    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::activated), this, &customtrip::on_comboBox_2_activated);

    //display the items in table view
    QStandardItemModel *m_model = new QStandardItemModel(this);

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

    //add items to the box
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

    //add items to the second comboBox
    ui->comboBox_2->addItem("Marlins Park");
    ui->comboBox_2->addItem("Tropicana Field");
    ui->comboBox_2->addItem("Sun Trust Park");
    ui->comboBox_2->addItem("Nationals Park");
    ui->comboBox_2->addItem("Oriole Park at Camden Yards");
    ui->comboBox_2->addItem("Citizens Bank Park");
    ui->comboBox_2->addItem("Citi Field");
    ui->comboBox_2->addItem("Yankee Stadium");
    ui->comboBox_2->addItem("Fenway Park");
    ui->comboBox_2->addItem("Rogers Centre");
    ui->comboBox_2->addItem("PNC Park");
    ui->comboBox_2->addItem("Progressive Field");
    ui->comboBox_2->addItem("Great American Park");
    ui->comboBox_2->addItem("Comerica Park");
    ui->comboBox_2->addItem("Guaranteed Rate Field");
    ui->comboBox_2->addItem("Busch Stadium");
    ui->comboBox_2->addItem("Kaufmann Stadium");
    ui->comboBox_2->addItem("Wrigley Field");
    ui->comboBox_2->addItem("Miller Park");
    ui->comboBox_2->addItem("Target Field");
    ui->comboBox_2->addItem("Globe Life Park in Arlington");
    ui->comboBox_2->addItem("Minute Maid Park");
    ui->comboBox_2->addItem("Coors Field");
    ui->comboBox_2->addItem("Chase Field");
    ui->comboBox_2->addItem("Petco Park");
    ui->comboBox_2->addItem("Angel Stadium of Anaheim");
    ui->comboBox_2->addItem("Dodger Stadium");
    ui->comboBox_2->addItem("Oakland-Alameda County Coliseum");
    ui->comboBox_2->addItem("Oracle Park");
    ui->comboBox_2->addItem("Safeco Field");

    //add items to tableView
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

    ui->tableView->setModel(m_model);

    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Stretch);
}


customtrip::~customtrip()
{
    delete ui;
}

void customtrip::on_comboBox_activated(int index)
{
    // QString text = ui->comboBox->currentIndex();
    qDebug() << "Selected Item: " << index << "----" << exit;
}


void customtrip::on_comboBox_2_activated(int index)
{
    QString startingStadium = ui->comboBox->currentText();
    QString endingStadium = ui->comboBox_2->currentText();

    dijkstra(startingStadium);

    int totalDistance = distances[endingStadium];
    qDebug() << "Total distance from" << startingStadium << "to" << endingStadium << ":" << totalDistance;
}

void customtrip::addEdge(const QString& stadium1, const QString& stadium2, int distance)
{
    graph[stadium1][stadium2] = distance;
    graph[stadium2][stadium1] = distance;
}

void customtrip::dijkstra(const QString& startingStadium)
{
    QSet<QString> visitedStadiums;

    distances.clear();
    previousStadiums.clear();

    // Initialize distances with infinity for all stadiums except the starting stadium
    for (const QString& stadium : graph.keys()) {
        if (stadium == startingStadium)
            distances[stadium] = 0;
        else
            distances[stadium] = INT_MAX;
    }

    QList<QString> stadiumList = distances.keys();
    for (const QString& stadium : stadiumList) {
       int distance = distances[stadium];
        while (!visitedStadiums.contains(stadium))
        {
            QString currentStadium;
            int shortestDistance = INT_MAX;


            // Find the stadium with the shortest distance from the starting stadium
            for (const QString& stadium : distances.keys()) {
                if (!visitedStadiums.contains(stadium) && distances[stadium] < shortestDistance) {
                    currentStadium = stadium;
                    shortestDistance = distances[stadium];
                }
            }

            visitedStadiums.insert(currentStadium);

            // Update distances to neighboring stadiums
            for (const QString& neighbor : graph[currentStadium].keys()) {
                int distance = graph[currentStadium][neighbor];
                int totalDistance = distances[currentStadium] + distance;

                if (totalDistance < distances[neighbor]) {
                    distances[neighbor] = totalDistance;
                    previousStadiums[neighbor] = currentStadium;
                }
            }
        }
    }
}

