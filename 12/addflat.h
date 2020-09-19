#ifndef ADDFLAT_H
#define ADDFLAT_H

#include <QDialog>
#include "flat.h"

namespace Ui {
class AddFlat;
}

class AddFlat : public QDialog
{
    Q_OBJECT

public:
    Flat flat;
    explicit AddFlat(QWidget *parent = nullptr);
    ~AddFlat();

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::AddFlat *ui;
};

#endif // ADDFLAT_H
