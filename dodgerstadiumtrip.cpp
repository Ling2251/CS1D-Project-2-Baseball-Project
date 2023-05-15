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

    m_model = new QStandardItemModel(this);
    // Connect the activated() signal to the on_stadiumComboBox_activated() slot
    //connect(ui->stadiumComboBox, SIGNAL(activated(QString)),
    //        this, SLOT(on_stadiumComboBox_activated(QString)));

    connect(ui->stadiumComboBox, QOverload<int>::of(&QComboBox::activated),
        this, &dodgerstadiumtrip::on_stadiumComboBox_activated);


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
    m_model->setItem(3, 0, new QStandardItem("Dodger Stadium"));
    m_model->setItem(4, 0, new QStandardItem("Oracle Park"));
    m_model->setItem(5, 0, new QStandardItem("Oakland-Alameda County Coliseum"));
    m_model->setItem(6, 0, new QStandardItem("Angel Stadium of Anaheim"));
    m_model->setItem(7, 0, new QStandardItem("Petco Park"));
    m_model->setItem(8, 0, new QStandardItem("Chase Field"));
    m_model->setItem(9, 0, new QStandardItem("Safeco Field"));
    m_model->setItem(10, 0, new QStandardItem("Coors Field"));
    m_model->setItem(11, 0, new QStandardItem("Globe Life Park in Arlington"));
    m_model->setItem(12, 0, new QStandardItem("Minute Maid Park"));
    m_model->setItem(13, 0, new QStandardItem("Target Field"));
    m_model->setItem(14, 0, new QStandardItem("Kauffman Stadium"));
    m_model->setItem(15, 0, new QStandardItem("Busch Stadium"));
    m_model->setItem(16, 0, new QStandardItem("Miller Park"));
    m_model->setItem(17, 0, new QStandardItem("Wrigley Field"));
    m_model->setItem(18, 0, new QStandardItem("Guaranteed Rate Field"));
    m_model->setItem(19, 0, new QStandardItem("Comerica Park"));
    m_model->setItem(20, 0, new QStandardItem("Progressive Field"));
    m_model->setItem(21, 0, new QStandardItem("Great American Ball Park"));
    m_model->setItem(22, 0, new QStandardItem("Sun Trust Park"));
    m_model->setItem(23, 0, new QStandardItem("Sun Trust Park"));
    m_model->setItem(24, 0, new QStandardItem("Tropicana Field"));
    m_model->setItem(25, 0, new QStandardItem("Marlins Park"));
    m_model->setItem(26, 0, new QStandardItem("Rogers Centre"));
    m_model->setItem(27, 0, new QStandardItem("PNC Park"));
    m_model->setItem(28, 0, new QStandardItem("Yankee Stadium"));
    m_model->setItem(29, 0, new QStandardItem("Citizens Bank"));
    m_model->setItem(30, 0, new QStandardItem("Oriole Park at Camden Yard"));
    m_model->setItem(31, 0, new QStandardItem("Nationals Park"));
    m_model->setItem(32, 0, new QStandardItem("Fenway Park"));
    m_model->setItem(33, 0, new QStandardItem("Citi Field"));
    m_model->setItem(34, 0, new QStandardItem("Citizens Bank Park"));
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
    // Do something when an item in the combo box is activated
    QString text = ui->stadiumComboBox->currentText();
    qDebug() << "Selected item:" << index << "---" << text;
    //call dijkstra
    //qDebug << "Calling Dijkstra on selected stadium";

}


