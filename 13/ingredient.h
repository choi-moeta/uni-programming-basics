#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <QDate>
#include <QString>

class Ingredient
{
public:
    Ingredient(QString name, double weight, QDate expire) {
        _name = name;
        _weight = weight;
        _expire = expire;
    };
    QString getName();
    double getWeight();
    QDate  getExpire();
    void setName(QString);
    void setWeight(double);
    void setExpire(QDate);
    Ingredient* next;
    Ingredient* prev;

private:
    QString _name;
    double _weight;
    QDate  _expire;
    Ingredient* _next;
    Ingredient* _prev;
};

#endif // INGREDIENT_H
