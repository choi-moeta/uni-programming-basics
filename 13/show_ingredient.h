#ifndef SHOW_INGREDIENT_H
#define SHOW_INGREDIENT_H

#include <QDialog>
#include "dish_ingredient.h"

namespace Ui {
class Show_Ingredient;
}

class Show_Ingredient : public QDialog
{
    Q_OBJECT

public:
    QString dish;
    Dish_Ingredient* di;
    Dish_Ingredient::D* d;
    explicit Show_Ingredient(Dish_Ingredient*);
    ~Show_Ingredient();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Show_Ingredient *ui;
};

#endif // SHOW_INGREDIENT_H
