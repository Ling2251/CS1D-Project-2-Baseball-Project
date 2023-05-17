#include "planntingtrip.h"
#include "ui_planntingtrip.h"

PlanntingTrip::PlanntingTrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanntingTrip)
{
    ui->setupUi(this);
    // check if admin has login and added new files
    ifLogin();

    // Initialize graph and database manager
    graph = nullptr;

    // populate graph and combo boxes
    rebuildGraph();
}

PlanntingTrip::~PlanntingTrip()
{
    delete graph;
    delete ui;
}

void PlanntingTrip::on_DFSpushButton_clicked()
{
    int distance = graph->startDFS("Oracle Park");
    QString pathStr;
    for (const auto &dest : graph->dfsOrder) {
        pathStr += dest + "\n";
    }

    QMessageBox msgBox;
    msgBox.setText("DFS starting from Oracle Park (San Francisco Giants)");
    msgBox.setInformativeText("Total distance: " + QString::number(distance));
    msgBox.setDetailedText(pathStr);
    msgBox.exec();
}

void PlanntingTrip::on_BFSpushButton_clicked()
{
    int distance = graph->startBFS("Target Field");
    QString pathStr;
    for (const auto &dest : graph->bfsOrder) {
        pathStr += dest + "\n";
    }

    QMessageBox msgBox;
    msgBox.setText("BFS starting from Target Field (Minnesota Twins)");
    msgBox.setInformativeText("Total distance: " + QString::number(distance));
    msgBox.setDetailedText(pathStr);
    msgBox.exec();
}

void PlanntingTrip::on_MSTpushButton_clicked()
{
    int distance = graph->startMST();
    QString pathStr = "MST Edges:\n";
    pathStr += graph->mstString;

    QMessageBox msgBox;
    msgBox.setStyleSheet("QLabel{min-width: 400px;}");
    msgBox.setText("MST");
    msgBox.setInformativeText("Total distance: " + QString::number(distance));
    msgBox.setDetailedText(pathStr);
    msgBox.exec();
}

void PlanntingTrip::on_addPushButton_clicked()
{
    if (ui->addComboBox->count() != 0) {
        QString team = ui->addComboBox->currentText();
        selectedList.push_back(team);

        ui->teamListWidget->addItem(team);
        ui->addComboBox->removeItem(ui->addComboBox->currentIndex());
        ui->startComboBox->addItem(team);
    }
}

void PlanntingTrip::on_removePushButton_clicked()
{
    if (ui->teamListWidget->currentItem() != nullptr) {
        QListWidgetItem *item = ui->teamListWidget->currentItem();
        int index = ui->teamListWidget->row(item);
        selectedList.erase(selectedList.begin() + index);

        ui->addComboBox->addItem(item->text());
        ui->startComboBox->removeItem(index);
        delete ui->teamListWidget->takeItem(index);  // Delete the item after removing it from the list
    }
}

void PlanntingTrip::on_simpleStartButton_clicked()
{
    int distance = 0;
    vector<QString> route;
    if (ui->simpleToComboBox->currentIndex() == 0) { // visit all option
        distance = graph->startMultiDijkstra(nameList,ui->simpleFromComboBox->currentText());
        route = graph->dijkstraOrder;
    } else {
        QString start = ui->simpleFromComboBox->currentText();
        QString dest = ui->simpleToComboBox->currentText();
        distance = graph->startDijkstra(start, dest);
        route.push_back(start);
        route.push_back(dest);
    }

    vector<QString> teams;
    QString teamName;
    for (const QString &stadium : route) {
        qDebug() << "[startPushButton] stadium name: " << stadium;
        teamName = database->getStadiumData(stadium);
        teams.push_back(stadium);
    }

    // display total distance
    QMessageBox msgBox;
    msgBox.setText("Total distance: " + QString::number(distance) + " miles");
    msgBox.exec();

    // go to souvenrs shop
    souvenirUI = new souvenirShop(teams,database,this);
    souvenirUI->setDist(distance);
    souvenirUI->exec();
    delete  souvenirUI;
}

void PlanntingTrip::on_startPushButton_clicked()
{
    if (ui->mostEfficientRadioButton->isChecked()) {
        QString start = ui->startComboBox->currentText();
        vector<QString> stadiumNames;

        // get all stadium names selected
        for (int i = 0; i < ui->teamListWidget->count(); i++) {
            stadiumNames.push_back(ui->teamListWidget->item(i)->text());
        }

        // perform dijkstra recursively
        int distance = graph->startMultiDijkstra(stadiumNames, start);

        // convert stadium names to team names
        vector<QString> route = graph->dijkstraOrder;
        vector<QString> teams;
        QString teamName;
        for (const QString &stadium : route) {
            qDebug() << "[startPushButton] stadium name: " << stadium;
            teamName = database->getStadiumData(stadium);
            teams.push_back(stadium);
        }

        // display total distance
        QMessageBox msgBox;
        msgBox.setText("Total distance: " + QString::number(distance) + " miles");
        msgBox.exec();

        // go to souvenrs shop
        souvenirUI = new souvenirShop(teams,database,this);
        souvenirUI->setDist(distance);
        souvenirUI->exec();
        delete  souvenirUI;

    } else if (ui->shortestTripsRadioButton->isChecked()) {
        QString start = ui->startComboBox->currentText();
        vector<QString> stadiumNames;

        // get all stadium names selected
        for (int i = 0; i < ui->teamListWidget->count(); i++) {
            stadiumNames.push_back(ui->teamListWidget->item(i)->text());
        }

        int distance = 0;

        for (unsigned int i = 1; i < stadiumNames.size(); i++) {
            QString startStadium = ui->teamListWidget->item(i - 1)->text();
            QString endStadium = ui->teamListWidget->item(i)->text();
            int distanceToAdd = graph->startDijkstra(startStadium, endStadium);
            distance += distanceToAdd;
        }

        // convert stadium names to team names
        vector<QString> teams;
        QString teamName;
        for (const QString &stadium : stadiumNames) {
            teamName = database->getStadiumData(stadium);
            teams.push_back(stadium);
        }

        // display total distance
        QMessageBox msgBox;
        msgBox.setText("Total distance: " + QString::number(distance) + " miles");
        msgBox.exec();

        // go to souvenrs shop
        souvenirUI = new souvenirShop(teams,database,this);
        souvenirUI->setDist(distance);
        souvenirUI->exec();
        delete  souvenirUI;
    } else {
        QMessageBox::information(this, "Error", "Please select a trip order.");
    }
}

void PlanntingTrip::rebuildGraph()
{
    ui->simpleToComboBox->clear();
    ui->simpleFromComboBox->clear();
    ui->addComboBox->clear();

    // populate vectors and comboBox
    nameList = database->getStadiumNames();
    tempList = nameList;
    ui->simpleToComboBox->addItem("Visit all"); // visit all option

    for (auto teamName : nameList) {
        ui->simpleFromComboBox->addItem(teamName);
        ui->simpleToComboBox->addItem(teamName);
        ui->addComboBox->addItem(teamName);
    }

    // populate graph
    if(graph != nullptr) {
        delete graph;
    }
    graph = new Graph<QString>();
    vector<distanceEdge> edges;
    for (const QString &stadium : nameList) {
        qDebug() << "adding node:" << stadium;
        graph->addNode(stadium);
    }
    for (const QString &stadium : nameList) {
        edges = database->getDistances(stadium);
        for (const auto &edge : edges) {
            graph->addEdge(edge.team_name_origin, edge.team_name_destination,edge.distance);
            qDebug() << "adding edge:" << edge.team_name_origin << edge.team_name_destination << edge.distance;
        }
    }

}

void PlanntingTrip::ifLogin(){
    if(intputUI.HasReadFile()){
        rebuildGraph();
    }
}
