#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dishes.h"
#include "ingredients.h"
#include "dish_ingredient.h"
#include "sort.h"
#include "add_dish.h"
#include "add_ingredient.h"
#include "create_relation.h"
#include "show_dish.h"
#include "show_ingredient.h"
#include <QDebug>
#include <QFileDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dishes = new Dishes;
    ingredients = new Ingredients;
    dish_ingredient = new Dish_Ingredient;

    updateTables();
}

MainWindow::~MainWindow()
{
    delete ui;
}

Dishes* MainWindow::getDishes()
{
    return dishes;
}

Ingredients* MainWindow::getIngredients()
{
    return ingredients;
}

void MainWindow::updateTables()
{
    updateTable_dishes();
    updateTable_ingredients();
    updateTable_dish_ingredient();
}

void MainWindow::updateTable_dishes()
{
    ui->tableWidget_dishes->setRowCount(0);

    Dish* d = dishes->getFirst();
    int k = 0;
    while(d)
    {
        ui->tableWidget_dishes->setRowCount(k+1);
        ui->tableWidget_dishes->setItem(k, 0, new QTableWidgetItem(d->getName()));
        ui->tableWidget_dishes->setItem(k, 1, new QTableWidgetItem(d->getType()));
        ui->tableWidget_dishes->setItem(k, 2, new QTableWidgetItem(QString::number(d->getCost())));

        d = d->next;
        k++;
    }
}

void MainWindow::updateTable_ingredients()
{
    ui->tableWidget_ingredients->setRowCount(0);

    Ingredient* i = ingredients->getFirst();
    int k = 0;
    while(i)
    {
        ui->tableWidget_ingredients->setRowCount(k+1);
        ui->tableWidget_ingredients->setItem(k, 0, new QTableWidgetItem(i->getName()));
        ui->tableWidget_ingredients->setItem(k, 1, new QTableWidgetItem(QString::number(i->getWeight())));
        ui->tableWidget_ingredients->setItem(k, 2, new QTableWidgetItem(i->getExpire().toString("dd.MM.yyyy")));

        i = i->next;
        k++;
    }
}

void MainWindow::updateTable_dish_ingredient()
{
    ui->tableWidget_di->setRowCount(0);

    Dish_Ingredient::D* di = dish_ingredient->getFirst();
    int k = 0;
    while(di)
    {
        ui->tableWidget_di->setRowCount(k+1);
        ui->tableWidget_di->setItem(k, 0, new QTableWidgetItem(di->data->getName()));
        ui->tableWidget_di->setItem(k, 1, new QTableWidgetItem(di->relation->getName()));


        di = di->next;
        k++;
    }
}

void MainWindow::on_pushButton_add_dish_clicked()
{
    Add_dish* add = new Add_dish;
    add->setModal(true);
    add->exec();

    if (add->dish)
        dishes->pushBack(add->dish->getName(), add->dish->getType(), add->dish->getCost());

    updateTable_dishes();
}

void MainWindow::on_pushButton_add_ingredient_clicked()
{
    Add_ingredient* add = new Add_ingredient;
    add->setModal(true);
    add->exec();

    if (add->ingredient)
        ingredients->pushBack(add->ingredient->getName(), add->ingredient->getWeight(), add->ingredient->getExpire());

    updateTable_ingredients();
}

void MainWindow::on_pushButton_create_relation_clicked()
{
    Create_relation* create = new Create_relation(dishes, ingredients);
    create->setModal(true);
    create->exec();

    if (create->ok) {
        Dish* dish = dishes->find(create->dish);
        Ingredient* ingredient = ingredients->find(create->ingredient);


//    qDebug() << dish->getName() << ingredient->getName();

    dish_ingredient->pushFirst(dishes->find(create->dish), ingredients->find(create->ingredient));
//    dish_ingredient->pushBack(dishes->getFirst(), ingredients->getFirst());
    }

    updateTable_dish_ingredient();
}

void MainWindow::on_pushButton_save_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "Choose a file to write", "", "Text file *.bin");
    QFile outFile(path);
    if(outFile.open(QIODevice::WriteOnly | QFile::Truncate))
    {
        QDataStream out(&outFile);

        Dish* d = dishes->getFirst();
        while(d) {
            out << 0 << d->getName() << d->getType() << d->getCost();
            d = d->next;
        }

        Ingredient* i = ingredients->getFirst();
        while(i) {
            out << 1 << i->getName() << i->getWeight() << i->getExpire();
            i = i->next;
        }

        Dish_Ingredient::D* di = dish_ingredient->getFirst();
        while(di) {
            out << 2 << di->data->getName() << di->relation->getName();
            di = di->next;
        }
    }
    outFile.close();
}

void MainWindow::on_pushButton_load_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Choose file for read", "", "Text file *.bin");
    QFile inpFile(path);
    dishes = new Dishes;
    ingredients = new Ingredients;
    dish_ingredient = new Dish_Ingredient;
    if(inpFile.open(QIODevice::ReadOnly | QFile::Text))
    {
        QDataStream inp(&inpFile);

        if (inpFile.size() ==0)
        {
//            QMessageBox::about(this,"Error!","file is empty!");
        }
        else
        {
            while(!inp.atEnd())
            {
                int mode;
                inp >> mode;
                if(mode == 0)
                {
                    QString name;
                    QString type;
                    double cost;
                    inp >> name >> type >> cost;
                    dishes->pushBack(name, type, cost);
                }
                else if(mode == 1)
                {
                    QString name;
                    double weight;
                    QDate expire;
                    inp >> name >> weight >> expire;
                    ingredients->pushBack(name, weight, expire);
                }
                else if(mode == 2)
                {
                    QString name_dish;
                    QString name_ingredient;
                    inp >> name_dish >> name_ingredient;
                    dish_ingredient->pushFirst(dishes->find(name_dish), ingredients->find(name_ingredient));
                }
            }
            updateTables();
        }
    }
    inpFile.close();
}

void MainWindow::on_pushButton_show_dish_clicked()
{
    Show_Dish* show = new Show_Dish(dish_ingredient);
    show->setModal(true);
    show->exec();
}

void MainWindow::on_pushButton_show_ingredient_clicked()
{
    Show_Ingredient* show = new Show_Ingredient(dish_ingredient);
    show->setModal(true);
    show->exec();
}

void MainWindow::on_pushButton_sort_dishes_clicked()
{
    bool ok;
    Dish* d;
    QString item = QInputDialog::getItem(this, "Sort", "Sort by item", {"Name", "Type", "Cost"}, 0, false, &ok);
    if (ok)
    {
        d = dishes->getFirst();
        d->prev = nullptr;

        for (int j = 0; j < dishes->getSize(); j++) {
            d = dishes->getFirst();
            for (int i = j; i < dishes->getSize() - 1; i++) {
                bool swap = false;
                if      (item == "Name"   && d->getName() > d->next->getName()) swap = true;
                else if (item == "Type"   && d->getType() > d->next->getType()) swap = true;
                else if (item == "Cost"   && d->getCost() > d->next->getCost()) swap = true;

                if (swap) {
                    Dish* d0 = nullptr;
                    Dish* d1 = nullptr;
                    Dish* d2 = nullptr;
                    Dish* d3 = nullptr;

                    d0 = d->prev; // пред элемент
                    d1 = d;       // текущий элемент
                    d2 = d->next; // следующий элемент
                    d3 = d2->next;// след через один элемент

                    if (d0 != nullptr) {
                        d0->next = d2; // то указатель пред элемента указываем на след, на след пушто мы их свапаем
                    } else {
                        dishes->setFirst(d2); // иначе меняем указатель на первый эл
                    }
                    d2->prev = d0; // меняем текущ и след
                    d2->next = d1;

                    d1->prev = d2;
                    d1->next = d3;

                    if (d3 != nullptr ) // как с первым
                        d3->prev = d1;

                    d = d2; // мы свапаем элементы поэтому
                }
                d = d->next; // след элем в списке
            }
        }
        updateTable_dishes();
    }
}

void MainWindow::on_pushButton_sort_ingredients_clicked()
{
    bool ok;
    Ingredient* d;
    QString item = QInputDialog::getItem(this, "Sort", "Sort by item", {"Name", "Weight", "Expire"}, 0, false, &ok);
    if (ok)
    {
        d = ingredients->getFirst();
        d->prev = nullptr;

        for (int j = 0; j < ingredients->getSize(); j++) {
            d = ingredients->getFirst();
            for (int i = j; i < ingredients->getSize() - 1; i++) {
                bool swap = false;
                if      (item == "Name"   && d->getName() > d->next->getName()) swap = true;
                else if (item == "Weight"   && d->getWeight() > d->next->getWeight()) swap = true;
                else if (item == "Expire"   && d->getExpire() > d->next->getExpire()) swap = true;

                if (swap) {
                    Ingredient* d0 = nullptr;
                    Ingredient* d1 = nullptr;
                    Ingredient* d2 = nullptr;
                    Ingredient* d3 = nullptr;

                    d0 = d->prev; // пред элемент
                    d1 = d;       // текущий элемент
                    d2 = d->next; // следующий элемент
                    d3 = d2->next;// след через один элемент

                    if (d0 != nullptr) {
                        d0->next = d2; // то указатель пред элемента указываем на след, на след пушто мы их свапаем
                    } else {
                        ingredients->setFirst(d2); // иначе меняем указатель на первый эл
                    }
                    d2->prev = d0; // меняем текущ и след
                    d2->next = d1;

                    d1->prev = d2;
                    d1->next = d3;

                    if (d3 != nullptr ) // как с первым
                        d3->prev = d1;

                    d = d2; // мы свапаем элементы поэтому
                }
                d = d->next; // след элем в списке
            }
        }
        updateTables();
    }
}

void MainWindow::on_pushButton_delete_dish_clicked()
{
    bool ok;
    int num = QInputDialog::getInt(this, "Delete dish", "Enter a number", 0, 1, dishes->getSize(), 1, &ok);

    dishes->remove(num - 1);

    updateTable_dishes();
}

void MainWindow::on_pushButton_delete_ingredient_clicked()
{
    bool ok;
    int num = QInputDialog::getInt(this, "Delete ingredient", "Enter a number", 0, 1, ingredients->getSize(), 1, &ok);

    ingredients->remove(num - 1);

    updateTable_ingredients();
}

void MainWindow::on_pushButton_delete_relation_clicked()
{
    bool ok;
    int num = QInputDialog::getInt(this, "Delete relation", "Enter a number", 0, 1, dish_ingredient->getSize(), 1, &ok);

    dish_ingredient->remove(num - 1);

    updateTable_dish_ingredient();
}
