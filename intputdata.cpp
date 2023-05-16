#include "intputdata.h"
#include "ui_intputdata.h"

intputData::intputData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::intputData)
{
    ui->setupUi(this);
}

intputData::~intputData()
{
    delete ui;
}

void intputData::on_NewStadiumInfo_clicked()
{
    // Prompt the user to choose a text file
    QString filePath = QFileDialog::getOpenFileName(this, "Select Text File", QString(), "Text Files (*.txt)");
    if (filePath.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }

    // Read data from the text file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    QString teamName = in.readLine();
    QString stadiumName = in.readLine();
    int capacity = in.readLine().toInt();
    QString location = in.readLine();
    QString playingSurface = in.readLine();
    QString league = in.readLine();
    int yearOpened = in.readLine().toInt();
    int seats = in.readLine().toInt();
    QString architecturalStyle = in.readLine();
    QString roofType = in.readLine();

    // Insert data into the SQL database
    QSqlQuery query;
    query.prepare("INSERT INTO stadium_info (teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenterFileld, ballParkTypology, roofType) "
                  "VALUES (:teamName, :stadiumName, :capacity, :location, :playingSurface, :league, :yearOpened, :seats, :architecturalStyle, :roofType)");

    query.bindValue(":teamName", teamName);
    query.bindValue(":stadiumName", stadiumName);
    query.bindValue(":capacity", capacity);
    query.bindValue(":location", location);
    query.bindValue(":playingSurface", playingSurface);
    query.bindValue(":league", league);
    query.bindValue(":yearOpened", yearOpened);
    query.bindValue(":seats", seats);
    query.bindValue(":architecturalStyle", architecturalStyle);
    query.bindValue(":roofType", roofType);

    if (!query.exec()) {
        qDebug() << "Failed to insert data:" << query.lastError().text();
        return;
    }

    file.close();
    qDebug() << "File processed and data inserted into the database.";
}


void intputData::on_NewDistenctInfo_clicked()
{
    // Prompt the user to choose a text file
    QString filePath = QFileDialog::getOpenFileName(this, "Select Text File", QString(), "Text Files (*.txt)");
    if (filePath.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }

    // Read data from the text file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()){
        QString stadiumName = in.readLine();
        QString teamName = in.readLine();
        int capacity = in.readLine().toInt();

        // Insert data into the SQL database
        QSqlQuery query;
        query.prepare("INSERT INTO stadium_Distances (stardingStadium, endingStadium, distance) VALUES (:stadiumName, :teamName, :capacity)");
        query.bindValue(":stadiumName", stadiumName);
        query.bindValue(":teamName", teamName);
        query.bindValue(":capacity", capacity);

        if (!query.exec()) {
            qDebug() << "Failed to insert data:" << query.lastError().text();
            return;
        }
    }
    file.close();
    qDebug() << "File processed and data inserted into the database.";

}

