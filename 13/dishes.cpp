#include "dishes.h"
#include "dish.h"
#include <QString>
//#include <QtDebug>

Dishes::Dishes() {
    _first = _cur = nullptr;
}

Dishes::~Dishes() {}

Dish* Dishes::getFirst() {
    return _first;
}

void Dishes::setFirst(Dish* first) {
    _first = first;
}

int Dishes::getSize() {
    Dish* temp = _first;
    int i = 0;
    while (temp) {
        temp = temp->next;
        i++;
    }
    return i;
}

Dish* Dishes::getNext() {
    if (_cur != nullptr) {
        _cur = _cur->next;
        return _cur;
    }
    return nullptr;
}

Dish* Dishes::getLast() {
    Dish* temp = _first;
    while (temp && temp->next) {
        temp = temp->next;
    }
    return temp;
}

void Dishes::remove(int no) {
//    int no = getSize() - num;

    Dish* temp = _first;
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

Dish* Dishes::find(QString name) {
    Dish* temp = _first;
    while (temp || temp->next) {
        if (temp->getName() == name)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

Dish* Dishes::pushFirst(QString name, QString category, double cost) {
    Dish* temp = _first;

    Dish* newDish = new Dish(name, category, cost);

    if (temp != nullptr) {
        newDish->next = temp;
        temp->prev = newDish;
    }
    else {
        newDish->next = nullptr;
    }

    newDish->prev = nullptr;
    _first = newDish;

    return newDish;
}

Dish* Dishes::pushBack(QString name, QString category, double cost) {
    Dish* last = getLast();

    Dish* newDish = new Dish(name, category, cost);
    newDish->next = nullptr;

    if (last != nullptr) {
        last->next = newDish;
        newDish->prev = last;
    } else {
        _first = newDish;
        newDish->prev = nullptr;
    }
}
