#include "souveniredit.h"
#include "ui_souveniredit.h"

souvenirEdit::souvenirEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::souvenirEdit)
{
    ui->setupUi(this);
    setWindowTitle("Souvenir Home");
    teamNameComboBox();
}

souvenirEdit::~souvenirEdit()
{
    delete ui;
}

void souvenirEdit::teamNameComboBox()
{
    //connect database
    QSqlDatabase conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn);

    // only put the college name out from the souvenirs
    list->prepare("select stadiumName as \"Campuses\" from stadium_Souvenirs group by stadiumName;");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);

    //set college name into comboBox
    ui->TeamNameComBox->setModel(modal);
}

void souvenirEdit::on_comboxEnterButton_clicked()
{
    //connect database
    QSqlDatabase conn;

    QSqlQueryModel * modal = new QSqlQueryModel();


    QSqlQuery* qry = new QSqlQuery(conn);

    //create a current string
    QString currentName;

    //set this variabble bycomboBox
    currentName = ui->TeamNameComBox->currentText();

    //selects the list in the data base
    qry->prepare("select * from stadium_Souvenirs where stadiumName= ?");
    qry->addBindValue(currentName);

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The souvenir report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->souvenirTableView->setModel(modal);

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

/*Update button to update the cost of each souvenir that you want
 *This button will connect the college comboBox and souvenirs comboBox
 *Also this button will connect with the tableView
*/
void souvenirEdit::on_souvenirUpdateButton_clicked()
{
    //connect database
    QSqlDatabase conn;

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(conn);

    //create three string variables
    QString teamName,souvenirs,cost;

    //assign those variables with the current text
    teamName = ui->teamNameLine->text();
    souvenirs = ui->souvenirNameLine->text();
    cost = ui->costLine->text();

    bool result = isNumber(cost);

    //open the database
    conn.open();

    //update function to update the cost
    if(!result)
    {
        QMessageBox::critical(this,tr("Error::"),tr("Wrong!!!! Please type the numeric value"));
    }
    else
    {
        qry->prepare("update stadium_Souvenirs set price='"+cost+"'where itemName='"+souvenirs+"'and stadiumName='"+teamName+"'");
    }

    //if update succesfully then will display a messageBox::Update
    if(qry->exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Updated"));
    }
    else
    {
        //QMessageBox::critical(this,tr("Error::"),qry->lastError().text());
    }
}


void souvenirEdit::on_souvenirTableView_activated(const QModelIndex &index)
{
    //Set val to tableView model
    QString val = ui->souvenirTableView->model()->data(index).toString();

    //connect database
    QSqlDatabase conn;
    QSqlQuery qry;

    QString stadiumName = ui->TeamNameComBox->currentText();
    //select the souvenirName and cost that you want
    qry.prepare("select * from stadium_Souvenirs where itemName= '"+val+"'or price= '"+val+"'");

    //if qry.exec, it will assign the info in to collegeLine, souvenirsLine, and costLine
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->teamNameLine->setText(stadiumName);
            ui->souvenirNameLine->setText(qry.value(1).toString());
            ui->costLine->setText(qry.value(2).toString());
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


void souvenirEdit::on_addButton_clicked()
{
    // opned the data base
    QSqlDatabase conn;

    conn.open();


    QSqlQuery qry;
    QString teamName,souvenirName,price;

    //get the data in from the ui intput
    teamName   = ui->teamNameLine->text();
    souvenirName  = ui->souvenirNameLine->text();
    price = ui->costLine->text();

    bool result = isNumber(price);

    if(result)
    {
        // error checking input
        if(teamName != "" && price != "" && souvenirName != ""){
            addOrDelet = true;
        }
        else{
            addOrDelet = false;
        }

        if(addOrDelet){
            // add the item
            qry.prepare("insert into stadium_Souvenirs (stadiumName, itemName, price) values ('"+teamName+"', '"+souvenirName+"', '"+price+"')");

            // error message if the item can't be added due to the data base
            if(qry.exec())
            {
                QMessageBox::about(this, "", "The item was added, double check if error occured");
                // close the connection to data base
                conn.close();
            }
            else
            {
                QMessageBox::about(this, "Error", "Database not found double check path to database");
            }
        }
        else{
            QMessageBox::about(this, "Error", "Can't enter an empty input to add an item, please try agin");
            //ClearSreen();
        }
    }else
    {
        QMessageBox::critical(this,tr("Error::"),tr("Wrong!!!! Please type the numeric value"));
    }

}


void souvenirEdit::on_deleteButton_clicked()
{
    // opned the data base
   QSqlDatabase conn;

   conn.open();
   //get the data in from the ui intput
   QSqlQuery qry;
   QString teamName,souvenirName,price;

   //get the data in from the ui intput
   teamName   = ui->teamNameLine->text();
   souvenirName  = ui->souvenirNameLine->text();
   price = ui->costLine->text();

   // error checking input
   if(teamName != "" && price != "" && souvenirName != ""){
       addOrDelet = true;
   }
   else{
       addOrDelet = false;
   }

   if(addOrDelet)
   {
       // delete the item
       qry.prepare("Delete from stadium_Souvenirs where stadiumName=='"+teamName+"'and itemName=='"+souvenirName+"'and price=='"+price+"'");

       // error message if the item can't be deleted due to the data base
       if(qry.exec())
       {
           QMessageBox::about(this, "", "The item(s) was/were deleted, double check if error occured");
       }
       else
       {
           QMessageBox::about(this, "Error", "Database not found double check path to database");
       }
   }

   else
   {
       QMessageBox::about(this, "Error", "Can't enter an empty or invaild input to delet an item , please try agin");
   }
}


void souvenirEdit::on_pushButton_clicked()
{
    maintenancePage maintenance;
    hide();
    maintenance.setModal(true);
    maintenance.exec();
}

bool souvenirEdit::isNumber(const QString& text)
{
    QRegularExpression regex("^[0-9]+(\\.[0-9]+)?$"); // pattern to match numbers with or without decimal points
    QRegularExpressionMatch match = regex.match(text);
    return match.hasMatch();
}


