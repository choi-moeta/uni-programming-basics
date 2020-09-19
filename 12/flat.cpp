#include <QString>

struct Flat {
    QString address;
    int roomCount;
    int livingSpace;
    int hasBalcony;
    Flat* next;
    Flat* prev;
};
