#include "stadiumedit.h"
#include "ui_stadiumedit.h"

stadiumEdit::stadiumEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stadiumEdit)
{
    ui->setupUi(this);
    teamCombox();

}

stadiumEdit::~stadiumEdit()
{
    delete ui;
}


void stadiumEdit::on_enter_clicked()
{
    //connect database
    QSqlDatabase conn;

    QSqlQueryModel * modal = new QSqlQueryModel();


    QSqlQuery* qry = new QSqlQuery(conn);

    //create a current string
    QString currentName;

    //set this variabble bycomboBox
    currentName = ui->teamcomboBox->currentText();

    //selects the list in the data base
    qry->prepare("select * from stadium_info where teamName= ?");
    qry->addBindValue(currentName);

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The souvenir report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->teamInfotableView->setModel(modal);

            //closes connention to data base
            //counts rows from the model
            qDebug() <<(modal->rowCount());
        }
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }
}


void stadiumEdit::on_update_clicked()
{

}


void stadiumEdit::teamCombox()
{
    //connect database
    QSqlDatabase conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn);

    // only put the college name out from the souvenirs
    list->prepare("select teamName as \"Campuses\" from stadium_info group by teamName;");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);

    //set college name into comboBox
    ui->teamcomboBox->setModel(modal);

}


void stadiumEdit::on_maintainancePushButton_clicked()
{

    maintenancePage maintenance;
    hide();
    maintenance.setModal(true);
    maintenance.exec();

}

