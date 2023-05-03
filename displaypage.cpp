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
    // load the data into the UI

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
    // show the table view and hide the widget.
    ui->StadiumtableView->setModel(model);
    ui->StadiumtableWidget->hide();

    //sort the table view
    ui->StadiumtableView->setSortingEnabled(true);
    ui->StadiumtableView->sortByColumn(1);

}

// displays only one team information, base on what team name user selected in the combo box
void DisplayPage::on_displayTeamInfo_clicked()
{
    QString name = ui->TeamComboBox->currentText();
    showTeamInfoDisplay(my_database.loadTeamInfo(name));

}


void DisplayPage::on_allTeamDisplay_clicked()
{
    showTeamInfoDisplay(my_database.loadAllTeam());
}


void DisplayPage::on_majorLeagueDisplay_clicked()
{
    showTeamInfoDisplay(my_database.loadMajorLeagueTeam());
}


void DisplayPage::on_AmericanTeamDisplay_clicked()
{
    showTeamInfoDisplay(my_database.loadAmericanLeagueTeam());
}

