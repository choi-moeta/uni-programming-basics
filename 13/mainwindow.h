#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dishes.h"
#include "ingredients.h"
#include "dish_ingredient.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Dishes* getDishes();
    Ingredients* getIngredients();

private slots:
    void on_pushButton_add_dish_clicked();
    void on_pushButton_add_ingredient_clicked();
    void on_pushButton_create_relation_clicked();

    void on_pushButton_save_clicked();
    void on_pushButton_load_clicked();

    void on_pushButton_show_dish_clicked();

    void on_pushButton_show_ingredient_clicked();

    void on_pushButton_sort_dishes_clicked();

    void on_pushButton_sort_ingredients_clicked();

    void on_pushButton_delete_dish_clicked();

    void on_pushButton_delete_ingredient_clicked();

    void on_pushButton_delete_relation_clicked();

private:
    Dishes* dishes;
    Ingredients* ingredients;
    Dish_Ingredient* dish_ingredient;
    Ui::MainWindow *ui;
    void updateTables();
    void updateTable_dishes();
    void updateTable_ingredients();
    void updateTable_dish_ingredient();
};

#endif // MAINWINDOW_H
