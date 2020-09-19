#include "ingredients.h"
#include "ingredient.h"
#include <QString>
//#include <QtDebug>

Ingredients::Ingredients() {
    _first = _last = _cur = nullptr;
}

Ingredients::~Ingredients() {}

Ingredient* Ingredients::getFirst() {
    return _first;
}

void Ingredients::setFirst(Ingredient* first) {
    _first = first;
}

void Ingredients::remove(int no) {
//    int no = getSize() - num;

    Ingredient* temp = _first;
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

int Ingredients::getSize() {
    Ingredient* temp = _first;
    int i = 0;
    while (temp) {
        temp = temp->next;
        i++;
    }
    return i;
}

Ingredient* Ingredients::getNext() {
    if (_cur != nullptr) {
        _cur = _cur->next;
        return _cur;
    }
    return nullptr;
}

Ingredient* Ingredients::getLast() {
    Ingredient* temp = _first;
    while (temp && temp->next) {
        temp = temp->next;
    }
    return temp;
}

Ingredient* Ingredients::find(QString name) {
    Ingredient* temp = _first;
    while (temp || temp->next) {
        if (temp->getName() == name)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

Ingredient* Ingredients::pushFirst(QString name, double weight, QDate expire) {
    Ingredient* temp = _first;

    Ingredient* newIngredient = new Ingredient(name, weight, expire);

    if (temp != nullptr) {
        newIngredient->next = temp;
        temp->prev = newIngredient;
    }
    else {
        newIngredient->next = nullptr;
    }

    newIngredient->prev = nullptr;
    _first = newIngredient;

    return newIngredient;
}

Ingredient* Ingredients::pushBack(QString name, double weight, QDate expire) {
    Ingredient* last = getLast();

    Ingredient* newIngredient = new Ingredient(name, weight, expire);
    newIngredient->next = nullptr;

    if (last != nullptr) {
        last->next = newIngredient;
        newIngredient->prev = last;
    } else {
        _first = newIngredient;
        newIngredient->prev = nullptr;
    }
}
