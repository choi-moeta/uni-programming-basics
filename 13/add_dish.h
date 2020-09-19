#ifndef ADD_DISH_H
#define ADD_DISH_H

#include <QDialog>
#include "dish.h"

namespace Ui {
class Add_dish;
}

class Add_dish : public QDialog
{
    Q_OBJECT

public:
    explicit Add_dish(QWidget *parent = nullptr);
    ~Add_dish();
    Dish* dish;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add_dish *ui;
};

#endif // ADD_DISH_H
