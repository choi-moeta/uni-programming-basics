#ifndef SHOW_DISH_H
#define SHOW_DISH_H

#include <QDialog>
#include "dish_ingredient.h"

namespace Ui {
class Show_Dish;
}

class Show_Dish : public QDialog
{
    Q_OBJECT

public:
    QString dish;
    Dish_Ingredient* di;
    Dish_Ingredient::D* d;
    explicit Show_Dish(Dish_Ingredient*);
    ~Show_Dish();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Show_Dish *ui;
};

#endif // SHOW_DISH_H
