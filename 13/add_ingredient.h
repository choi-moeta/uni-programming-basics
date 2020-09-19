#ifndef ADD_INGREDIENT_H
#define ADD_INGREDIENT_H

#include <QDialog>
#include "ingredient.h"

namespace Ui {
class Add_ingredient;
}

class Add_ingredient : public QDialog
{
    Q_OBJECT

public:
    explicit Add_ingredient(QWidget *parent = nullptr);
    ~Add_ingredient();
    Ingredient* ingredient;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add_ingredient *ui;
};

#endif // ADD_INGREDIENT_H
