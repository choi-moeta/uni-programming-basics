#ifndef DISH_H
#define DISH_H

#include <QString>

class Dish
{
public:
    Dish(QString name, QString type, double cost) {
        _name = name;
        _type = type;
        _cost = cost;
    };
    QString getName();
    QString getType();
    double  getCost();
    void setName(QString);
    void setType(QString);
    void setCost(double);
    Dish* next;
    Dish* prev;

private:
    QString _name;
    QString _type;
    double  _cost;
    Dish* _next;
    Dish* _prev;
};

#endif // DISH_H
