#ifndef SOUVENIRSHOP_H
#define SOUVENIRSHOP_H

#include <QDialog>
#include <connecteUIPgae.h>

namespace Ui {
class souvenirShop;
}

class souvenirShop : public QDialog
{
    Q_OBJECT

public:
    /** \struct Souvenir
     * Struct for the information about a souvenir purchased by the student.
     */
    struct Souvenir
    {
        QString souvName;       /**< Souvenir name*/
        QString stadiumName;    /**< stadium of origin*/
        double cost;            /**< Cost of the souvenir */
        int quantity;           /**< Number of souvenirs purchased*/
    };

    explicit souvenirShop(QWidget *parent = nullptr);
    ~souvenirShop();
    void calculateTotal();
    void showSouvCartTableView(QSqlQueryModel *model);
    void showTotal(double total);
    void showSouvTableView(QSqlQueryModel *model);

private slots:
    void on_addSouvenir_button_clicked();

    void on_mainPagrButton_clicked();

private:
    Ui::souvenirShop *ui;
    Souvenir souv;                  /**< struct of the purchased souvenirs*/
    QStack<Souvenir> souvenirCart;  /**< stack of the purchased souvenirs*/
    QString sQry;                   /**< souvenir query - ACCUMULATOR*/
    DBmanager m_database;           /**< database manager variable*/
    double total;                   /**< double of the total price form the purchased souvenirs*/

};

#endif // SOUVENIRSHOP_H
