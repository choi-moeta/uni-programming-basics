#include "ingredient.h"

QString Ingredient::getName() {
    return _name;
}

double Ingredient::getWeight() {
    return _weight;
}

QDate Ingredient::getExpire() {
    return _expire;
}

void Ingredient::setName(QString name) {
    _name = name;
}

void Ingredient::setWeight(double weight) {
    _weight = weight;
}

void Ingredient::setExpire(QDate expire) {
    _expire = expire;
}
