#ifndef INGREDIENTS_H
#define INGREDIENTS_H
#include "ingredient.h"

class Ingredients
{
//    class Ingredient;

public:
    Ingredients();
    ~Ingredients();

    Ingredient* getFirst();
    void setFirst(Ingredient*);
    Ingredient* getNext();
    Ingredient* getLast();
    void remove(int);
    int getSize();
    Ingredient* find(QString);
    Ingredient* pushBack(QString name, double weight, QDate expire);
    Ingredient* pushFirst(QString name, double weight, QDate expire);

private:
    Ingredient* _first;
    Ingredient* _last;
    Ingredient* _cur;
};

#endif // INGREDIENTS_H
