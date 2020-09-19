#include "add_dish.h"
#include "dish.h"
#include "ui_add_dish.h"

Add_dish::Add_dish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_dish)
{
    ui->setupUi(this);
    dish = nullptr;
}

Add_dish::~Add_dish()
{
    delete ui;
}

void Add_dish::on_pushButton_clicked()
{
        dish = new Dish(ui->Name->text(), ui->Type->text(), ui->Cost->text().toDouble());
        this->close();
}
