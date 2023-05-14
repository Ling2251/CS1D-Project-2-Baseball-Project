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
//    QComboBox *comboBox = ui->stadiumComboBox;
}

dodgerstadiumtrip::~dodgerstadiumtrip()
{
    delete ui;
}

//void dodgerstadiumtrip::on_tableView_activated(const QModelIndex &index)
//{
//    //show the stadium names

//}





//void dodgerstadiumtrip::on_tableView_clicked()
//{
    //having trouble displaying the stadium names
//    QVector<QString> stadiumNames {"Dodger Stadium",
//                                       "Oracle Park",
//                                       "Oakland-Alameda County Coliseum",
//                                       "Angel Stadium of Anaheim",
//                                       "Petco Park",
//                                       "Chase Field",
//                                       "Safeco Field",
//                                       "Coors Field",
//                                       "Globe Life Park in Arlington",
//                                       "Minute Maid Park",
//                                       "Target Field",
//                                       "Kauffman Stadium",
//                                       "Busch Stadium",
//                                       "Miller Park",
//                                       "Wrigley Field",
//                                       "Guaranteed Rate Field",
//                                       "Comerica Park",
//                                       "Progressive Field",
//                                       "Great American Ball Park",
//                                       "Sun Trust Park",
//                                       "Sun Trust Park",
//                                       "Tropicana Field",
//                                       "Marlins Park",
//                                       "Rogers Centre",
//                                       "PNC Park",
//                                       "Yankee Stadium",
//                                       "Citizens Bank",
//                                       "Oriole Park at Camden Yard",
//                                       "Nationals Park",
//                                       "Fenway Park",
//                                       "Citi Field",
//                                       "Citizens Bank Park"
//                                      };
//        QStandardItemModel *model = new QStandardItemModel(this);
//        model->setRowCount(stadiumNames.size());
//        model->setColumnCount(1);
//        for(int i = 0; i < stadiumNames.size(); i++)
//        {
//            QStandardItem *item = new QStandardItem(stadiumNames[i]);
//            model->setItem(i, 0, item);
//        }
//        ui->tableView->setModel(model);
//}


//void dodgerstadiumtrip::on_stadiumComboBox_activated(int index)
//{
//    QComboBox *comboBox = ui->stadiumComboBox;
//    QStringList stadiumNames {"Dodger Stadium",
//                                       "Oracle Park",
//                                       "Oakland-Alameda County Coliseum",
//                                       "Angel Stadium of Anaheim",
//                                       "Petco Park",
//                                       "Chase Field",
//                                       "Safeco Field",
//                                       "Coors Field",
//                                       "Globe Life Park in Arlington",
//                                       "Minute Maid Park",
//                                       "Target Field",
//                                       "Kauffman Stadium",
//                                       "Busch Stadium",
//                                       "Miller Park",
//                                       "Wrigley Field",
//                                       "Guaranteed Rate Field",
//                                       "Comerica Park",
//                                       "Progressive Field",
//                                       "Great American Ball Park",
//                                       "Sun Trust Park",
//                                       "Sun Trust Park",
//                                       "Tropicana Field",
//                                       "Marlins Park",
//                                       "Rogers Centre",
//                                       "PNC Park",
//                                       "Yankee Stadium",
//                                       "Citizens Bank",
//                                       "Oriole Park at Camden Yard",
//                                       "Nationals Park",
//                                       "Fenway Park",
//                                       "Citi Field",
//                                       "Citizens Bank Park"
//                                      };
//    for(const QString &stadiumName : stadiumNames)
//    {
//        comboBox->addItem(stadiumName);
//    }

//    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index) {
//        QString selectedStadium = comboBox->itemText(index);
//        // Update the QTableView with the selected stadium's information
//    });

//}


void dodgerstadiumtrip::on_comboBox_currentTextChanged(const QList<QString> stadiums)
{
    QList<QString> myString = {"Dodger Stadium",
               "Oracle Park",
                "Oakland-Alameda County Coliseum",
                "Angel Stadium of Anaheim",
                "Petco Park",
                "Chase Field",
                "Safeco Field",
                "Coors Field",
                "Globe Life Park in Arlington",
                "Minute Maid Park",
                "Target Field",
                "Kauffman Stadium",
                "Busch Stadium",
                "Miller Park",
                "Wrigley Field",
                "Guaranteed Rate Field",
                "Comerica Park",
                "Progressive Field",
                "Great American Ball Park",
                "Sun Trust Park",
                "Sun Trust Park",
                "Tropicana Field",
                "Marlins Park",
                "Rogers Centre",
                "PNC Park",
                "Yankee Stadium",
                "Citizens Bank",
                "Oriole Park at Camden Yard",
                "Nationals Park",
                "Fenway Park",
                "Citi Field",
                "Citizens Bank Park"
                };
    stadiums = myString.toList();
    ui->comboBox->addItems(myString);
}

