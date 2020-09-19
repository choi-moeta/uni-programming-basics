#ifndef CITYLIST_H
#define CITYLIST_H

#include <QString>

class CityList
{

public:
    QString file;
    QString *cities;
    CityList();
    void getCitiesArray(QString text);

private:
};

#endif // CITYLIST_H
