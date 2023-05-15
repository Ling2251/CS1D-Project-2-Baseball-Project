#include "marlinstrip.h"
#include "ui_marlinstrip.h"
#include<QStandardItem>
#include<QStandardItemModel>

marlinstrip::marlinstrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::marlinstrip)
{
    ui->setupUi(this);

    //set QLabel to say "Marlins Park"
    ui->label_2->setText("Current Stadium: Marlins Park");

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
            model->setItem(3, 0, new QStandardItem("Dodger Stadium"));
            model->setItem(4, 0, new QStandardItem("Oracle Park"));
            model->setItem(5, 0, new QStandardItem("Oakland-Alameda County Coliseum"));
            model->setItem(6, 0, new QStandardItem("Angel Stadium of Anaheim"));
            model->setItem(7, 0, new QStandardItem("Petco Park"));
            model->setItem(8, 0, new QStandardItem("Chase Field"));
            model->setItem(9, 0, new QStandardItem("Safeco Field"));
            model->setItem(10, 0, new QStandardItem("Coors Field"));
            model->setItem(11, 0, new QStandardItem("Globe Life Park in Arlington"));
            model->setItem(12, 0, new QStandardItem("Minute Maid Park"));
            model->setItem(13, 0, new QStandardItem("Target Field"));
            model->setItem(14, 0, new QStandardItem("Kauffman Stadium"));
            model->setItem(15, 0, new QStandardItem("Busch Stadium"));
            model->setItem(16, 0, new QStandardItem("Miller Park"));
            model->setItem(17, 0, new QStandardItem("Wrigley Field"));
            model->setItem(18, 0, new QStandardItem("Guaranteed Rate Field"));
            model->setItem(19, 0, new QStandardItem("Comerica Park"));
            model->setItem(20, 0, new QStandardItem("Progressive Field"));
            model->setItem(21, 0, new QStandardItem("Great American Ball Park"));
            model->setItem(22, 0, new QStandardItem("Sun Trust Park"));
            model->setItem(23, 0, new QStandardItem("Sun Trust Park"));
            model->setItem(24, 0, new QStandardItem("Tropicana Field"));
            model->setItem(25, 0, new QStandardItem("Marlins Park"));
            model->setItem(26, 0, new QStandardItem("Rogers Centre"));
            model->setItem(27, 0, new QStandardItem("PNC Park"));
            model->setItem(28, 0, new QStandardItem("Yankee Stadium"));
            model->setItem(29, 0, new QStandardItem("Citizens Bank"));
            model->setItem(30, 0, new QStandardItem("Oriole Park at Camden Yard"));
            model->setItem(31, 0, new QStandardItem("Nationals Park"));
            model->setItem(32, 0, new QStandardItem("Fenway Park"));
            model->setItem(33, 0, new QStandardItem("Citi Field"));
            model->setItem(34, 0, new QStandardItem("Citizens Bank Park"));
        ui->tableView->setModel(model);

        QHeaderView *header = ui->tableView->horizontalHeader();
        header->setSectionResizeMode(0, QHeaderView::Stretch);
}

marlinstrip::~marlinstrip()
{
    delete ui;
}

void marlinstrip::on_comboBox_activated(int index)
{
    QString text = ui->comboBox->currentText();
    qDebug() << "Selected item: " << index << "-----" << text;
}

