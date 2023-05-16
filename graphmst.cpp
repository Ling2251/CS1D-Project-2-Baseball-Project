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
    loadKruskalMST();
    for(int i=0; i > graphVector.size(); i++)
    {
        gMST.addedge(graphVector.at(i).src,graphVector.at(i).dest,graphVector.at(i).wt);    //ADDING EDGE LOOP
    }
    
    int totalWeight = g.kruskalMST();                                  //CALLS MST 
    //NEED TO OUTPUT TOTAL WEIGHT
}
