#include "dish.h"

QString Dish::getName() {
    return _name;
}

QString Dish::getType() {
    return _type;
}

double Dish::getCost() {
    return _cost;
}

void Dish::setName(QString name) {
    _name = name;
}

void Dish::setType(QString type) {
    _type = type;
}

void Dish::setCost(double cost) {
    _cost = cost;
}
