#include "planntingtrip.h"
#include "ui_planntingtrip.h"
#include"dodgerstadiumtrip.h"
#include"ui_dodgerstadiumtrip.h"
#include"customtrip.h"
#include"ui_customtrip.h"
#include"marlinstrip.h"
#include"ui_marlinstrip.h"
#include"shortcustomtrip.h"
#include"ui_shortcustomtrip.h"
#include "mainwindow.h"
#include<QVBoxLayout>
#include<QInputDialog>
#include<QStandardItemModel>

PlanntingTrip::PlanntingTrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanntingTrip)
{
    ui->setupUi(this);
}

PlanntingTrip::~PlanntingTrip()
{
    delete ui;
}

void PlanntingTrip::on_mainPagrButton_clicked()
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

//void PlanntingTrip::on_mainPagrButton_2_clicked()
//{
//    //create button and combo box widgets
//    QPushButton *button = new QPushButton("Choose another team");
//    QDialog *comboBox = new QDialog();

//    //add items to the combo box
//    comboBox->addItem("Angels Stadium");
//    comboBox->addItem("Boston Red Sox");
//    comboBox->addItem("New York Yankees");
//    comboBox->addItem("San Francisco Giants");

//    //Connect the button to a function that changes the selected item in the combo box
//    QObject::connect(button, &QPushButton::clicked, [=]()
//    {
//        int nextIndex = (comboBox->currentIndex() + 1) % comboBox->count();
//        comboBox->setCurrentIndex(nextIndex);
//    });

//    // Add the button and combo box to the layout
//    QVBoxLayout *layout = new QVBoxLayout();
//    layout->addWidget(button);
//    layout->addWidget(comboBox);

//    // Set the layout on the main window
//    QWidget *window = new QWidget();
//    window->setLayout(layout);
//    window->show();
//}


void PlanntingTrip::on_mainPagrButton_2_clicked()
{
    //show window for dodger stadium trip
    // Create a new instance of the trip window
    dodgerstadiumtrip *tripWindow = new dodgerstadiumtrip(this);

    // Show the trip window
    tripWindow->show();
     //QComboBox *comboBox = ui->stadiumComboBox;
    //ask user to input the other team they want to visit from dodger stadium
//    int selectedCampus = QInputDialog::getInt(this, tr("Team you want to visit starting Dodger Stadium"), "Choose the Stadium: ");
//    qDebug() << selectedCampus;

//    //putting the stadiums in a vector starting from Dodger Stadium
//    QVector<QString> stadiumNames {"Dodger Stadium",
//                                   "Oracle Park",
//                                   "Oakland-Alameda County Coliseum",
//                                   "Angel Stadium of Anaheim",
//                                   "Petco Park",
//                                   "Chase Field",
//                                   "Safeco Field",
//                                   "Coors Field",
//                                   "Globe Life Park in Arlington",
//                                   "Minute Maid Park",
//                                   "Target Field",
//                                   "Kauffman Stadium",
//                                   "Busch Stadium",
//                                   "Miller Park",
//                                   "Wrigley Field",
//                                   "Guaranteed Rate Field",
//                                   "Comerica Park",
//                                   "Progressive Field",
//                                   "Great American Ball Park",
//                                   "Sun Trust Park",
//                                   "Sun Trust Park",
//                                   "Tropicana Field",
//                                   "Marlins Park",
//                                   "Rogers Centre",
//                                   "PNC Park",
//                                   "Yankee Stadium",
//                                   "Citizens Bank",
//                                   "Oriole Park at Camden Yard",
//                                   "Nationals Park",
//                                   "Fenway Park",
//                                   "Citi Field",
//                                   "Citizens Bank Park"
//                                  };
//    QStandardItemModel *model = new QStandardItemModel(this);
//    model->setRowCount(stadiumNames.size());
//    model->setColumnCount(1);
//    for(int i = 0; i < stadiumNames.size(); i++)
//    {
//        QStandardItem *item = new QStandardItem(stadiumNames[i]);
//        model->setItem(i, 0, item);
//    }
    //ui->mainPagrButton_2->findChild->tableView->setModel(model);
}


void PlanntingTrip::on_mainPagrButton_4_clicked()
{
    //show window for create your own custom trip
    customtrip *customWindow = new customtrip(this);

    customWindow->show();
}


void PlanntingTrip::on_mainPagrButton_3_clicked()
{
    //show winow for visisting teams from marlins park
    marlinstrip *marlinWindow = new marlinstrip(this);
    marlinWindow->show();
}


void PlanntingTrip::on_mainPagrButton_5_clicked()
{
    //show window for creating the shortest custom trip
    shortcustomtrip *sctWindow = new shortcustomtrip(this);
    sctWindow->show();
}

