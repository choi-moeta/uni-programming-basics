#ifndef DISHES_H
#define DISHES_H
#include "dish.h"

class Dishes
{
//    class Dish;

public:
    Dishes();
    ~Dishes();

    Dish* getFirst();
    void setFirst(Dish*);
    Dish* getNext();
    Dish* getLast();
    void remove(int);
    int getSize();
    Dish* find(QString);
    Dish* pushBack(QString name, QString category, double cost);
    Dish* pushFirst(QString name, QString category, double cost);

private:
    Dish* _first;
    Dish* _cur;
};

#endif // DISHES_H
