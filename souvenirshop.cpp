#include "souvenirshop.h"
#include "ui_souvenirshop.h"
#include <mainwindow.h>

souvenirShop::souvenirShop(vector<QString> stadiums, DBmanager* dbase, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::souvenirShop)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->souvenirShope);

    m_database = dbase; // Assign dbase to m_database

    // clear the prices shopping cart item
    m_database->deleteCart();
    // Then create a new shopping cart
    m_database->createCart();

    // test only
    ui->selectCampus_comboBox->setModel(m_database->loadAllTeam());

    stadiumNames = stadiums;
    // populate the stadium information on init
    for(const auto &stadium : stadiumNames) {
        ui->TripOrder->addItem(stadium);
        ui->StadiumcomboBox->addItem(stadium);
    }
    showSouvTableView(m_database->loadTeamSouvenirs(ui->selectCampus_comboBox->currentText()));

}

souvenirShop::~souvenirShop()
{
    delete ui;
}

/*
 * on_addSouvenir_button_clicked()
 * The function adds souvenirs to the souvenir cart using an accumulator string to use as the query for the database.
 * It also adds the total of the item costs in an accumulator total.
 */
void souvenirShop::on_addSouvenir_button_clicked()
{
    //set the name and campus
    QString itemName, stadiumName;
    itemName = ui->souv_comboBox->currentText();
    souv.souvName = itemName;
    stadiumName = ui->selectCampus_comboBox->currentText();
    souv.stadiumName = stadiumName;

    //get the quantity and item cost
     quantity = ui-> quantity_spinBox -> cleanText().toInt();
    souv.quantity = quantity;

    souvenirCart.push(souv);

    //update Cart table
    m_database->updateCartQuantity(stadiumName, itemName, quantity);

    //displays cart in table
   if(sQry == "")
   {
       sQry += "select stadiumName as 'stadium', itemName as 'Souvenirs', price as 'Cost', quantity as 'Quantity' "
                       "from Cart where stadiumName = '" +stadiumName+ "' and itemName = '" +itemName+ "'";
   }
   else
   {
       sQry += " union select stadiumName as 'stadium', itemName as 'Souvenirs', price as 'Cost', quantity as 'Quantity'"
                       "from Cart where stadiumName = '" +stadiumName+ "' and itemName = '" +itemName+ "'";
   }

   showSouvCartTableView(m_database->loadSouvCart(sQry));


   // call the calculate function
   calculateTotal();

   showTotal(total);
  // showSouvCartTableView();
  // get the total cost here__YC:
}

/*
 * showSouvCartTableView(QSqlQueryModel *model)
 * The souvenir cart table view for the souvenir shop UI will display the information about the souvenirs selected held in a QStringListModel pointer.
 */
void souvenirShop::showSouvCartTableView(QSqlQueryModel *model)
{
    ui->souvCart_tableView->setModel(model);
    ui->souvenirsListView->setModel(model);
}

/*
 * showSouvTableView(QSqlQueryModel *model)
 * The souvenir table view for the souvenir shop UI will display the information about the souvenirs of a specified campus held in a QStringListModel pointer.
 */
void souvenirShop::showSouvTableView(QSqlQueryModel *model)
{
    ui->souv_tableView->setModel(model);
    ui->souv_comboBox->setModel(model);
}


//showTotal function is to display the total purchases in the label
//pass the variable total from calculateTotal()function
void souvenirShop::showTotal(double total)
{
    // associate the total with the label in the uo page
    ui->costLabel_2->setNum(total);
}

void souvenirShop::setDist(const int &dist){
    totalDistance = dist;
    ui->finalDistance_Lable->setNum(totalDistance);
}

//calculate function is to calculate total price from the cart table
//assign the variable into the elements in header file
void souvenirShop::calculateTotal()
{
    //initial a double type total
    double total = 0.0;

    // initial ary
    QSqlQuery qry;

    //if the statement is true, then run the calculation method
    if(true)
    {
        qry.prepare("select printf(\"%.2f\",sum(price * quantity)) from Cart;");
        qry.exec();
        if(qry.next())
        {
            total = qry.value(0).toDouble();
        }
    }

    //assign the value to the header
    this->total = total;

}

void souvenirShop::on_mainPagrButton_clicked()
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


void souvenirShop::on_doneBuying_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->receiptpage);
}




void souvenirShop::on_SearchButton_clicked()
{
    double eachStadiumPrice = 0.0;
    QString StadiumName;

    QSqlQuery qry;
    double cost = 0.00;

    StadiumName = ui->StadiumcomboBox->currentText();
    ui->SelectedCollegeLabel->setText(StadiumName);

    //qry.prepare("select cost from Cart where collegeName='"+campaseName+"'");
    qry.prepare("select printf(\"%.2f\",sum(cost * quantity)) from Cart where stadiumName='"+StadiumName+"'");
    qry.exec();
    if(qry.next()){
        cost = (qry.value(0).toDouble());
    }else{
        QMessageBox::warning(this, "ERROR", "There is issue with the displaying", QMessageBox::Ok, QMessageBox::NoButton);
    }

    eachStadiumPrice =  cost;
    ui->StadiumCostLabel->setNum(eachStadiumPrice);
}


void souvenirShop::on_selectCampus_comboBox_currentTextChanged(const QString &arg1)
{
    showSouvTableView(m_database->loadTeamSouvenirs(ui->selectCampus_comboBox->currentText()));
}

