#include "add_ingredient.h"
#include "ingredient.h"
#include "ui_add_ingredient.h"

Add_ingredient::Add_ingredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_ingredient)
{
    ui->setupUi(this);
    ingredient = nullptr;
}

Add_ingredient::~Add_ingredient()
{
    delete ui;
}

void Add_ingredient::on_pushButton_clicked()
{
    ingredient = new Ingredient(ui->Name->text(), ui->Weight->text().toDouble(), ui->Date->date());
    this->close();
}
