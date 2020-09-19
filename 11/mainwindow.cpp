#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addflat.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QInputDialog>
#include <QTextStream>
#include <QFileDialog>

QVector<Flat> flats;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/drive/university/OP/labs/11/lab11/db.db");
    db.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable()
{
    QSqlQuery query;
    query.exec("SELECT * FROM Flats");

    updateTableSql(query);
}

void MainWindow::updateTableSort(QString item)
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM Flats ORDER BY %1").arg(item));

    updateTableSql(query);
}

void MainWindow::updateTableSql(QSqlQuery query)
{
    flats.clear();

    int i = 0;
    while (query.next())
    {
        flats.push_back(Flat());
        flats[i].address = query.value(0).toString();
        flats[i].roomCount = query.value(1).toString().toInt();
        flats[i].livingSpace = query.value(2).toString().toInt();
        flats[i].hasBalcony = query.value(3).toString().toInt();
        i++;
    }

    ui->tableWidget->setRowCount(flats.size());
    for(int i = 0; i < flats.size(); i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((flats)[i].address));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number((flats)[i].roomCount)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number((flats)[i].livingSpace)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(((flats[i].hasBalcony == 1) ? "Yes" : "No")));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(flats[i].roomCount > 2 && flats[i].livingSpace > 60 ? "Yes" : "No"));
    }
}

void MainWindow::on_pushButton_new_clicked()
{
    AddFlat* add = new AddFlat();
    add->setModal(true);
    add->exec();

    flats.push_back(add->flat);

    QSqlQuery query;
    query.exec(
        QString("INSERT INTO Flats (Address, RoomCount, LivingSpace, Balcony) VALUES ('%1', %2, %3, %4);")
        .arg(add->flat.address)
        .arg(add->flat.roomCount)
        .arg(add->flat.livingSpace)
        .arg(add->flat.hasBalcony)
    );

    updateTable();
}

void MainWindow::on_pushButton_delete_clicked()
{
    bool ok;
    int num = QInputDialog::getInt(this, "Delete flat", "Enter a number", 0, 1, flats.size(), 1, &ok) - 1;

    if (ok && num && flats.size())
    {
        QSqlQuery query;
        query.exec(
            QString("DELETE FROM Flats WHERE address='%1' AND roomCount=%2 AND livingSpace=%3 AND balcony=%4;")
            .arg(flats[num].address)
            .arg(flats[num].roomCount)
            .arg(flats[num].livingSpace)
            .arg(flats[num].hasBalcony)
        );
    }

    updateTable();
}

void MainWindow::on_pushButton_save_clicked()
{
}

void MainWindow::on_pushButton_load_clicked()
{
    updateTable();
}


void MainWindow::on_pushButton_sort_clicked()
{
    bool ok;
    QStringList items = {"Address", "RoomCount", "LivingSpace", "Balcony"};
    QString item = QInputDialog::getItem(this, "Sort", "Sort by item", items, 0, false, &ok);

    if (ok)
    {
        updateTableSort(item);
    }
}
