#ifndef CREATE_RELATION_H
#define CREATE_RELATION_H

#include <QDialog>
#include "dishes.h"
#include "ingredients.h"

namespace Ui {
class Create_relation;
}

class Create_relation : public QDialog
{
    Q_OBJECT

public:
    QString dish;
    QString ingredient;
    bool ok;
    explicit Create_relation(Dishes*, Ingredients*);
    ~Create_relation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Create_relation *ui;
};

#endif // CREATE_RELATION_H
