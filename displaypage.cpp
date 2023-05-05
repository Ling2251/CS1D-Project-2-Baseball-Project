#include "displaypage.h"
#include "ui_displaypage.h"
#include "mainwindow.h"

DisplayPage::DisplayPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayPage)
{
    ui->setupUi(this);
    // load team name in to the combo box
    showTeamNameCombo(my_database.loadTeamNameOnly());

}

DisplayPage::~DisplayPage()
{
    delete ui;
}

void DisplayPage::on_mainPagrButton_clicked()
{
    QList<QWidget*> topLevelWidgets = qApp->topLevelWidgets();
    foreach(QWidget *widget, topLevelWidgets) {
       QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);
       if (mainWindow) {
           // Show the main window if it was previously hidden
           if (!mainWindow->isVisible()) {
               mainWindow->show();
           }
           break;
       }
    }
    hide();
}

// gets and display all the team name in the database to the combo box
void DisplayPage::showTeamNameCombo(QSqlQueryModel *model){
    ui->TeamComboBox->setModel(model);
}

// the UI that display the information , this is useing table view not table widget
void DisplayPage::showTeamInfoDisplay(QSqlQueryModel *model){
    // show the table view and sort the data
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel;
    proxyModel->setSourceModel(model);
    ui->StadiumtableView->setModel(proxyModel);

    //resize the columns and sorted the data in the table view
    ui->StadiumtableView->resizeColumnsToContents();
    ui->StadiumtableView->setSortingEnabled(true);
    proxyModel->sort(0, Qt::AscendingOrder);

    // load the total seating capacity into the UI
    int totalSeatingCapacity = my_database.getseatingCapacity();
    ui->numberSeatingCapacity->setNum(totalSeatingCapacity);

}

// displays only one team information, base on what team name user selected in the combo box
void DisplayPage::on_displayTeamInfo_clicked()
{
    QString name = ui->TeamComboBox->currentText();
    ui->SortedLabel->setText("All Information Of Team " + name);
    showTeamInfoDisplay(my_database.loadTeamInfo(name));
}

void DisplayPage::on_allTeamDisplay_clicked()
{
    ui->SortedLabel->setText("All The Teams Information");
    showTeamInfoDisplay(my_database.loadAllTeam());
}

void DisplayPage::on_majorLeagueDisplay_clicked()
{
    ui->SortedLabel->setText("All The National League Teams Information");
    showTeamInfoDisplay(my_database.loadMajorLeagueTeam());
}

void DisplayPage::on_AmericanTeamDisplay_clicked()
{
    ui->SortedLabel->setText("All The American League Teams Information");
    showTeamInfoDisplay(my_database.loadAmericanLeagueTeam());
}

void DisplayPage::on_greatestDistanceDisplay_clicked()
{
    ui->SortedLabel->setText("The Team(s) That Has The Grest Center Distance");
    showTeamInfoDisplay(my_database.loadGreatesCenterDistanceTeam());
}


void DisplayPage::on_smallestDistanceDisplay_clicked()
{
    ui->SortedLabel->setText("The Team(s) That Has The Smallest Center Distance");
    showTeamInfoDisplay(my_database.loadSmallCenterDistanceTeam());
}


void DisplayPage::on_roofTypeDisplay_clicked()
{
    ui->SortedLabel->setText("The Team(s) That Has An Opened Roof Type");
    QSqlQueryModel* model = my_database.loadOpenRoofTypeTeam();
    showTeamInfoDisplay(model);

    int openedRoofNum = model->rowCount();
    ui->numberOfOpenedRoof->setText(QString::number(openedRoofNum));
}

