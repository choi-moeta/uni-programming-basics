#ifndef FLAT_H
#define FLAT_H

#include <QString>

struct Flat {
    QString address;
    int roomCount;
    int livingSpace;
    int hasBalcony;
    Flat* next;
    Flat* prev;
};

#endif // FLAT_H
