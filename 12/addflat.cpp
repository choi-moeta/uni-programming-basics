#include "addflat.h"
#include "ui_addflat.h"


AddFlat::AddFlat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFlat)
{
    Flat flat;
    ui->setupUi(this);
}

AddFlat::~AddFlat()
{
    delete ui;
}

void AddFlat::on_pushButton_add_clicked()
{
    flat = {
        .address = ui->lineEdit_address->text(),
        .roomCount = ui->spinBox_roomCount->text().toInt(),
        .livingSpace = ui->spinBox_livingSpace->text().toInt(),
        .hasBalcony = ((ui->checkBox_hasBalcony->checkState()) ? 1 : 0)
    };
    this->close();
}

