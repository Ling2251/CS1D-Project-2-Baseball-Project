#include "graphmst.h"
#include "ui_graphmst.h"

graphMST::graphMST(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphMST)
{
    ui->setupUi(this);
}

graphMST::~graphMST()
{
    delete ui;
}

void graphMST::on_MSTpushButton_clicked()
{
    int totalWeight = kruskalMST();
    //NEED TO OUTPUT TOTAL WEIGHT
}
