#include "shortcustomtrip.h"
#include "ui_shortcustomtrip.h"
#include<QStandardItem>
#include<QStandardItemModel>

shortcustomtrip::shortcustomtrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shortcustomtrip)
{
    ui->setupUi(this);

    //connect UI
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), this, &shortcustomtrip::on_comboBox_activated);

    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::activated), this, &shortcustomtrip::on_comboBox_2_activated);

    //display items in tableView
    QStandardItemModel *m_model = new QStandardItemModel(this);

    //add items to the first comboBox
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

    //add items in tableView
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

shortcustomtrip::~shortcustomtrip()
{
    delete ui;
}

void shortcustomtrip::on_comboBox_activated(int index)
{
    QString text = ui->comboBox->currentText();
    qDebug() << "Selected item: " << index << "-----" << text;
}


void shortcustomtrip::on_comboBox_2_activated(int index)
{
    //QString text = ui->comboBox_2->currentIndex();
    //QString text2 = ui->comboBox_2->currentIndex();
    qDebug() << "Selected item: " << index << "-----" << exit;
}

