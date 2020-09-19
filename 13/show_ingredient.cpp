#include "show_ingredient.h"
#include "ui_show_ingredient.h"

Show_Ingredient::Show_Ingredient(Dish_Ingredient* _di) :
    ui(new Ui::Show_Ingredient)
{
    ui->setupUi(this);
    di = _di;
    d = di->getFirst();
    QStringList names;
    while (d) {
        if (!names.contains(d->relation->getName()))
            names.push_back(d->relation->getName());
        d = d->next;
    }
    ui->comboBox->addItems(names);
}

Show_Ingredient::~Show_Ingredient()
{
    delete ui;
}

void Show_Ingredient::on_comboBox_currentIndexChanged(const QString &name)
{
    Dish_Ingredient::D* d = di->getFirst();
    int k = 0;
    while (d) {
        if ( name == d->relation->getName()) {
            ui->tableWidget->setRowCount(k+1);
            ui->tableWidget->setItem(k, 0, new QTableWidgetItem(d->relation->getName()));
            ui->tableWidget->setItem(k, 1, new QTableWidgetItem(d->data->getName()));
            k++;
        }
        d = d->next;
    }
}
