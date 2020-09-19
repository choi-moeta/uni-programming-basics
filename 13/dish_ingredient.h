#ifndef DISH_INGREDIENT_H
#define DISH_INGREDIENT_H
#include "dish.h"
#include "ingredient.h"

class Dish_Ingredient
{
public:
    Dish_Ingredient();
    ~Dish_Ingredient();

    class D {
    public:
        D(Dish* _data, Ingredient* _relation) {
            data = _data;
            relation = _relation;
        }
        Dish* data;
        Ingredient* relation;
        D* next;
        D* prev;
    };
    class I {
        public:
        I(Ingredient* _data, Dish* _relation) {
            data = _data;
            relation = _relation;
        }
        Ingredient* data;
        Dish* relation;
        D* next;
        D* prev;
    };

    D* getFirst();
    D* getNext();
    D* getLast();
    int getSize();
    D* findData(QString);
    D* findRelation(QString);
    void remove(int);
    void pushBack(Dish*, Ingredient*);
    void pushFirst(Dish*, Ingredient*);

private:
    D* _first;
    D* _cur;
};

#endif // DISH_INGREDIENT_H
