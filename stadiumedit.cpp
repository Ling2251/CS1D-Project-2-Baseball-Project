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
    //connect database
    QSqlDatabase conn;

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(conn);

    //create three string variables
    QString stadiumName;
    QString capacity;
    QString playingSurface;
    QString roofType;
    QString ballparkTypology;
    QString distanceToCenter;
    QString location;
    QString dateOpen;

    int capacity1 = capacity.toInt();

    QString teamName = ui->teamcomboBox->currentText();
    //assign those variables with the current text
    stadiumName = ui->stadiumName->text();
    capacity = ui->capacity->text();
    playingSurface = ui->playingSurface->text();
    roofType = ui->rooftype->text();
    ballparkTypology = ui->ballparktypology->text();
    distanceToCenter = ui->distanceToCenter->text();
    location = ui->Location->text();
    dateOpen = ui->DateOpened->text();

    /*QRegExp rx("-?\\d+(\\.\\d+)?([eE][-+]?\\d+)?");

    bool isCapacityNumber = rx.exactMatch(capacity);
    bool isDateOpenNumber = rx.exactMatch(dateOpen);
    bool isDistanceTocenterNumber = rx.exactMatch(distanceToCenter);*/

    //open the database
    conn.open();

    //update function to update the cost
    /*if(!isCapacityNumber && !isDateOpenNumber && !isDistanceTocenterNumber)
    {
        QMessageBox::critical(this,tr("Error::"),tr("Wrong!!!! Please type the numeric value"));
    }
    else
    {
        qry->prepare("update stadium_info set stadiumName='"+stadiumName+"' and seatingCapacity='"+capacity+"' and playingSurface='"+playingSurface+"' and location='"+location+"' and dateOpened='"+dateOpen+"' and distanceToCenterField='"+distanceToCenter+"' and ballParkTypology= '"+ballparkTypology+"' and roofType='"+roofType+"' where teamName='"+teamName+"'");
    }*/


    //qry->prepare("update stadium_info set stadiumName='"+stadiumName+"' and seatingCapacity='"+capacity+"' and playingSurface='"+playingSurface+"' and location='"+location+"' and dateOpened='"+dateOpen+"' and distanceToCenterField='"+distanceToCenter+"' and ballParkTypology= '"+ballparkTypology+"' and roofType='"+roofType+"' where teamName='"+teamName+"'");

    /*if(!isCapacityNumber && !isDateOpenNumber && !isDistanceTocenterNumber)
    {
       QMessageBox::critical(this,tr("Error::"),tr("Wrong!!!! Please type the numeric value"));
    }
    else
    {
        qry->prepare("update stadium_info set stadiumName='"+stadiumName+"' and seatingCapacity='"+capacity+"' where teamName='"+teamName+"'");

    }*/

    qry->prepare("update stadium_info set stadiumName='"+stadiumName+"' and seatingCapacity='"+capacity1+"' where teamName='"+teamName+"'");
    //qry->prepare("update stadium_info set seatingCapacity='"+capacity+"' where teamName='"+teamName+"'");




    /*
    QSqlQuery query(conn);
    query.prepare("UPDATE stadium_info SET stadiumName = :stadiumname, seatingCapacity = :capacity WHERE teamName = :teamname");

    // Bind the values to the placeholders in the query
    query.bindValue(":stadiumname", stadiumName);
    query.bindValue(":seatingCapacity", capacity1);
    query.bindValue(":teamname", teamName);



    if (query.exec()) {
        qDebug() << "Update successful";
    } else {
        qDebug() << "Update failed:" << query.lastError().text();
    }*/





    //if update succesfully then will display a messageBox::Update
    if(qry->exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Updated"));
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry->lastError().text());
    }
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


void stadiumEdit::on_teamInfotableView_activated(const QModelIndex &index)
{
    //Set val to tableView model
    QString val = ui->teamInfotableView->model()->data(index).toString();

    //connect database
    QSqlDatabase conn;
    QSqlQuery qry;

    QString teamName = ui->teamcomboBox->currentText();
    //select the souvenirName and cost that you want
   qry.prepare("select * from stadium_info where teamName= '"+teamName+"'or stadiumName= '"+val+"'");//or seatingCapacity= '"+val+"'or location= '"+val+"'or playingSurface= '"+val+"'or league= '"+val+"'or dateOpened= '"+val+"'or distanceToCenterField= '"+val+"'or ballParkTypology= '"+val+"'or roofType= '"+val+"'");

    //if qry.exec, it will assign the info in to collegeLine, souvenirsLine, and costLine
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->teamNameLine->setText(qry.value(0).toString());
            ui->stadiumName->setText(qry.value(1).toString());
            ui->capacity->setText(qry.value(2).toString());
            ui->Location->setText(qry.value(3).toString());
            ui->playingSurface->setText(qry.value(4).toString());
            ui->leagueLine->setText(qry.value(5).toString());
            ui->DateOpened->setText(qry.value(6).toString());
            ui->distanceToCenter->setText(qry.value(7).toString());
            ui->ballparktypology->setText(qry.value(8).toString());
            ui->rooftype->setText(qry.value(9).toString());
        }
        //close the database
        conn.close();
    }
    else
    {
        //else it will display the error
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

