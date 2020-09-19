#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addflat.h"
#include "flat.h"
#include <QFile>
#include <QInputDialog>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>

Flat* firstFlat = nullptr;
Flat* lastFlat = nullptr;

Flat* createFlat(QString address, int roomCount, int livingSpace, int hasBalcony) {
    Flat* newFlat = new Flat;
    newFlat->address = address;
    newFlat->roomCount = roomCount;
    newFlat->livingSpace = livingSpace;
    newFlat->hasBalcony = hasBalcony;
    newFlat->prev = nullptr;
    newFlat->next = nullptr;

    return newFlat;
}

void insertFirst(Flat* newFlat) {
    newFlat->prev = nullptr;
    newFlat->next = firstFlat;

    if (firstFlat != nullptr) {
        firstFlat->prev = newFlat;
    }

    if (lastFlat == nullptr) {
        lastFlat = newFlat;
    }

    firstFlat = newFlat;
}

void insertLast(Flat* newFlat) {
    newFlat->next = nullptr;
    newFlat->prev = lastFlat;

    if (lastFlat != nullptr) {
        lastFlat->next = newFlat;
    }

    if (firstFlat == nullptr) {
        firstFlat = newFlat;
    }

    lastFlat = newFlat;
}

void insertAfter(int no, Flat* newFlat) {
    Flat* temp = firstFlat;
    for (int i = 0; i < no; i++) {
        temp = temp->next;
    }

    newFlat->prev = temp;
    newFlat->next = temp->next;

    if (temp == lastFlat) {
        lastFlat = newFlat;
    }
}

void removeFlat(int no) {
    Flat* temp = firstFlat;
    for (int i = 0; i < no; i++) {
        temp = temp->next;
    }

    if (temp == firstFlat && temp == lastFlat) {
        firstFlat = nullptr;
        lastFlat = nullptr;
    } else if (temp == firstFlat) {
        firstFlat = temp->next;
        temp->next->prev = nullptr;
    } else if (temp == lastFlat) {
        lastFlat = temp->prev;
        temp->prev->next = nullptr;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
}

Flat* getFlat(int no) {
    Flat* temp = firstFlat;
    for (int i = 0; i < no; i++) {
        temp = temp->next;
    }
    return temp;
}

int flatSize() {
    int i = 0;
    Flat* f = firstFlat;
    while (f) {
        f = f->next;
        i++;
    }
    return i;
}

int deleteFlats() {
    int i = 0;
    Flat* f = firstFlat;
    while (f) {

        f = f->next;
        removeFlat(0);
        i++;
    }
    return i;
}

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

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(0);

    Flat* f = firstFlat;
    int i = 0;
    while(f)
    {
        ui->tableWidget->setRowCount(i+1);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(f->address));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(f->roomCount)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(f->livingSpace)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(((f->hasBalcony == 1) ? "Yes" : "No")));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(f->roomCount > 2 && f->livingSpace > 60 ? "Yes" : "No"));

        f = f->next;
        i++;
    }
}

void MainWindow::on_pushButton_new_clicked()
{
    AddFlat* add = new AddFlat();
    add->setModal(true);
    add->exec();

    Flat* newFlat = createFlat(add->flat.address, add->flat.roomCount, add->flat.livingSpace, add->flat.hasBalcony);
    insertLast(newFlat);

    updateTable();
}

void MainWindow::on_pushButton_saveBin_clicked()
{
    QString dest = QFileDialog::getSaveFileName(this, "Choose file", "../lab12/files", "Binary file (*.dat)");

    QFile file(dest);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    out << flatSize();

    Flat* f = firstFlat;
    int i = 0;
    while(f)
    {
        out << f->address;
        out << f->roomCount;
        out << f->livingSpace;
        out << f->hasBalcony;

        f = f->next;
        i++;
    }
}

void MainWindow::on_pushButton_loadBin_clicked()
{
    QString dest = QFileDialog::getOpenFileName(this, "Choose file", "../lab12/files", "Binary file (*.dat)");

    QFile file(dest);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    QString address;
    qint32 roomCount;
    qint32 livingSpace;
    qint32 hasBalcony;
    qint32 size;
    Flat* f;

    in >> size;

    deleteFlats();

    for (int i = 0; i < size; i++)
    {
        in >> address;
        in >> roomCount;
        in >> livingSpace;
        in >> hasBalcony;

        f = createFlat(address, roomCount, livingSpace, hasBalcony);
        insertLast(f);
    }
    updateTable();
}

void MainWindow::on_pushButton_delete_clicked()
{
    bool ok;
    int num = QInputDialog::getInt(this, "Delete flat", "Enter a number", 0, 1, flatSize(), 1, &ok);

    removeFlat(num - 1);

    updateTable();
}

void MainWindow::on_pushButton_saveHum_clicked()
{
    QString text = "";
    int size = flatSize();

    text += "Flat count: " + QString::number(size) + "\n";

    Flat* f = firstFlat;
    int i = 0;
    while(f)
    {
        text += "-----------\n";
        text += "Address: " + f->address + "\n";
        text += "Room count: " + QString::number(f->roomCount) + "\n";
        text += "Living space: " + QString::number(f->livingSpace) + "\n";
        QString balcony = f->hasBalcony ? "Yes" : "No";
        text += "Has balcony: " + balcony + "\n";

        f = f->next;
        i++;
    }

    QString dest = QFileDialog::getSaveFileName(this, "Choose file", "../lab12/files", "Text file (*.txt)");

    QFile file(dest);

    if(file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&file);

        out << text;
    }
}

void MainWindow::on_pushButton_sort_clicked()
{
    bool ok;
    QString item = QInputDialog::getItem(this, "Sort", "Sort by item", {"Address", "Room count", "Living space", "Balcony"}, 0, false, &ok);
    // выбираем поле для сортировки

    if (ok)
    {
        Flat* f = firstFlat;

        for (int j = 0; j < flatSize(); j++) {
            f = firstFlat;
            for (int i = 0; i < flatSize() - 1; i++) {
                bool swap = false;
                // если поле совпадает и текущее значение больше следующего, то меняем
                if      (item == "Address"      && f->address > f->next->address)         swap = true;
                else if (item == "Room count"   && f->roomCount > f->next->roomCount)     swap = true;
                else if (item == "Living space" && f->livingSpace > f->next->livingSpace) swap = true;
                else if (item == "Balcony"      && f->hasBalcony > f->next->hasBalcony)   swap = true;

                if (swap) {
                    Flat* f0 = nullptr;
                    Flat* f1 = nullptr;
                    Flat* f2 = nullptr;
                    Flat* f3 = nullptr;

                    f0 = f->prev; // пред элемент
                    f1 = f;       // текущий элемент
                    f2 = f->next; // следующий элемент
                    f3 = f2->next;// след через один элемент

                    if (f0 != nullptr) // если пред не нулл, тоесть текуший элемент не первый
                        f0->next = f2; // то указатель пред элемента указываем на след, на след пушто мы их свапаем
                    else
                        firstFlat = f2; // иначе меняем указатель на первый эл

                    f2->prev = f0; // меняем текущ и след
                    f2->next = f1;

                    f1->prev = f2;
                    f1->next = f3;

                    if (f3 != nullptr ) // как с первым
                        f3->prev = f1;
                    else
                        lastFlat = f1;

                    f = f2; // мы свапаем элементы поэтому
                }
                f = f->next; // след элем в списке
            }
        }
        updateTable();
    }
}
