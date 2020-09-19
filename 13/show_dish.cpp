#include "show_dish.h"
#include "ui_show_dish.h"

Show_Dish::Show_Dish(Dish_Ingredient* _di) :
    ui(new Ui::Show_Dish)
{
    ui->setupUi(this);
    di = _di;
    d = di->getFirst();
    QStringList names;
    while (d) {
        if (!names.contains(d->data->getName()))
            names.push_back(d->data->getName());
        d = d->next;
    }
    ui->comboBox->addItems(names);
}

Show_Dish::~Show_Dish()
{
    delete ui;
}

void Show_Dish::on_comboBox_currentIndexChanged(const QString &name)
{
    Dish_Ingredient::D* d = di->getFirst();
    int k = 0;
    while (d) {
        if ( name == d->data->getName()) {
            ui->tableWidget->setRowCount(k+1);
            ui->tableWidget->setItem(k, 0, new QTableWidgetItem(d->data->getName()));
            ui->tableWidget->setItem(k, 1, new QTableWidgetItem(d->relation->getName()));
            k++;
        }
        d = d->next;
    }
}
