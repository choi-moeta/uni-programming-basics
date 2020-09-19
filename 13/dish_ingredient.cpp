#include "ingredient.h"
#include "dish_ingredient.h"
#include "dish.h"
#include <QString>
//#include <QtDebug>

Dish_Ingredient::Dish_Ingredient() {
    _first = _cur = nullptr;
}

Dish_Ingredient::~Dish_Ingredient() {}

Dish_Ingredient::D* Dish_Ingredient::getFirst() {
    return _first;
}

int Dish_Ingredient::getSize() {
    D* temp = _first;
    int i = 0;
    while (temp) {
        temp = temp->next;
        i++;
    }
    return i;
}

Dish_Ingredient::D* Dish_Ingredient::getNext() {
    if (_cur != nullptr) {
        _cur = _cur->next;
        return _cur;
    }
    return nullptr;
}

Dish_Ingredient::D* Dish_Ingredient::getLast() {
    D* temp = _first;
    while (temp && temp->next) {
        temp = temp->next;
    }
    return temp;
}

Dish_Ingredient::D* Dish_Ingredient::findData(QString name) {
    Dish_Ingredient::D* temp = _first;
    while (temp || temp->next) {
        if (temp->data->getName() == name)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

Dish_Ingredient::D* Dish_Ingredient::findRelation(QString name) {
    Dish_Ingredient::D* temp = _first;
    while (temp || temp->next) {
        if (temp->relation->getName() == name)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void Dish_Ingredient::remove(int no) {
    Dish_Ingredient::D* temp = _first;
    for (int i = 0; i < no; i++) {
        temp = temp->next;
    }

    if (temp->prev == nullptr && temp->next == nullptr) {
        _first = nullptr;
    } else if (temp == _first) {
        _first = temp->next;
        temp->next->prev = nullptr;
    } else if (temp->next == nullptr) {
        temp->prev->next = nullptr;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void Dish_Ingredient::pushFirst(Dish* dish, Ingredient* ingredient) {
    D* temp = _first;

    D* d = new D(dish, ingredient);
    I* i = new I(ingredient, dish);

    if (temp != nullptr) {
        d->next = temp;
        temp->prev = d;
    }
    else {
        d->next = nullptr;
    }

    d->prev = nullptr;
    _first = d;
}

void Dish_Ingredient::pushBack(Dish* dish, Ingredient* ingredient) {
    D* last = getLast();

    D* d = new D(dish, ingredient);
    I* i = new I(ingredient, dish);

    if (last != nullptr)
        last->next = d;
    else
        _first = d;
}
