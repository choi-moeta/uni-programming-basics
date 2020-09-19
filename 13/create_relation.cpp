#include "create_relation.h"
#include "ui_create_relation.h"
#include "mainwindow.h"
#include "dishes.h"
#include "ingredients.h"

Create_relation::Create_relation(Dishes* dishes, Ingredients* ingredients) :
//    QDialog(parent),
    ui(new Ui::Create_relation)
{
    ui->setupUi(this);
    ok = false;

    MainWindow mw;

    Dish* d = dishes->getFirst();
    Ingredient* i = ingredients->getFirst();

    while (d)
    {
        ui->dishes->addItem(d->getName());
        d = d->next;
    }
    while (i)
    {
        ui->ingredients->addItem(i->getName());
        i = i->next;
    }

//    ui->dishes
}

Create_relation::~Create_relation()
{
    delete ui;
}

void Create_relation::on_pushButton_clicked()
{
    ok = true;
    dish = ui->dishes->currentText();
    ingredient = ui->ingredients->currentText();
    this->close();
}
