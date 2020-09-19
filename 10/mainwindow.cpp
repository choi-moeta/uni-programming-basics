#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addflat.h"
#include <QFile>
#include <QInputDialog>
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVector<Flat> flats;

void MainWindow::on_pushButton_saveBin_clicked()
{
    QString dest = QFileDialog::getOpenFileName(this, "Choose file", "../lab10/files", "Binary file (*.dat)");

    QFile file(dest);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    out << flats.size();

    for (int i = 0; i < flats.size(); i++)
    {
        out << flats[i].address;
        out << flats[i].roomCount;
        out << flats[i].livingSpace;
        out << flats[i].hasBalcony;
    }
}

void MainWindow::on_pushButton_loadBin_clicked()
{
    QString dest = QFileDialog::getOpenFileName(this, "Choose file", "../lab10/files", "Binary file (*.dat)");

    QFile file(dest);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);    // read the data serialized from the file

    QString address;
    qint32 roomCount;
    qint32 livingSpace;
    qint32 hasBalcony;
    qint32 size;

    in >> size;
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(size));

    for (int i = 0; i < size; i++)
    {
        if (flats.size() != size)
            flats.push_back(Flat());

        in >> flats[i].address;
        in >> flats[i].roomCount;
        in >> flats[i].livingSpace;
        in >> flats[i].hasBalcony;
    }
    updateTable();
}

void MainWindow::on_pushButton_new_clicked()
{
    AddFlat* add = new AddFlat();
    add->setModal(true);
    add->exec();

    flats.push_back(add->flat);

    updateTable();
}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(0);
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

void MainWindow::on_pushButton_delete_clicked()
{
    bool ok;
    int num = QInputDialog::getInt(this, "Delete flat", "Enter a number", 0, 1, flats.size(), 1, &ok);

    if (ok && num && flats.size())
        flats.remove(num - 1);

    updateTable();
}

void MainWindow::on_pushButton_saveHum_clicked()
{
    QString text = "";

    text += "Flat count: " + QString::number(flats.size()) + "\n";

    for (int i = 0; i < flats.size(); i++)
    {
        text += "-----------\n";
        text += "Address: " + flats[i].address + "\n";
        text += "Room count: " + QString::number(flats[i].roomCount) + "\n";
        text += "Living space: " + QString::number(flats[i].livingSpace) + "\n";
        QString balcony = flats[i].hasBalcony ? "Yes" : "No";
        text += "Has balcony: " + balcony + "\n";
    }

    QString dest = QFileDialog::getOpenFileName(this, "Choose file", "../lab10/files", "Text file (*.txt)");

    QFile file(dest);

    if(file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&file);

        out << text;
    }
}

void MainWindow::on_pushButton_sort_clicked()
{
    QVector<int> sort;

    for(int i = 0; i < flats.size(); i++)
    {
        sort.push_back(i);
    }

    for(int i = 0; i < flats.size(); i++)
    {
        for(int j = i; j < flats.size(); j++)
        {
            if (flats[sort[i]].roomCount > flats[sort[j]].roomCount)
            {
                sort[i] = j;
                sort[j] = i;
            }
        }
    }

    QString text = QString::number(sort.size()) + "\n";
    for (int i = 0; i < sort.size(); i++) {
        text += QString::number(sort[i]) + " ";
    }

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(flats.size());
    for(int i = 0; i < flats.size(); i++)
    {
        ui->tableWidget->setItem(sort[i], 0, new QTableWidgetItem((flats)[i].address));
        ui->tableWidget->setItem(sort[i], 1, new QTableWidgetItem(QString::number((flats)[i].roomCount)));
        ui->tableWidget->setItem(sort[i], 2, new QTableWidgetItem(QString::number((flats)[i].livingSpace)));
        ui->tableWidget->setItem(sort[i], 3, new QTableWidgetItem(((flats[i].hasBalcony == 1) ? "Yes" : "No")));
        ui->tableWidget->setItem(sort[i], 4, new QTableWidgetItem(flats[i].roomCount > 2 && flats[i].livingSpace > 60 ? "Yes" : "No"));
    }
}

//void MainWindow::on_pushButton_saveTxt_clicked()
//{
//    QString text = QString::number(flats.size());

//    for (int i = 0; i < flats.size(); i++)
//    {
//        QString balcony = flats[i].hasBalcony ? "Yes" : "No";
//        text += "\n" + flats[i].address + " " + QString::number(flats[i].roomCount) + " " + QString::number(flats[i].livingSpace) + " " + balcony;
//    }

//    QString dest = QFileDialog::getOpenFileName(this, "Choose file", "../lab10/files", "Text file (*.txt)");

//    QFile file(dest);

//    if(file.open(QFile::WriteOnly | QFile::Truncate))
//    {
//        QTextStream out(&file);

//        out << text;
//    }
//}
