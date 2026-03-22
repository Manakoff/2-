#ifndef R_H
#define R_H

#include <QString>
#include "Date.h"

class R
{
protected:
    QString last_name;
    QString first_name;
    BirthDay birthday;


public:
    R() {}
    R(QString last, QString first, BirthDay day)
    {
        last_name = last;
        first_name = first;
        birthday = day;
    }
    virtual ~R() {};

    virtual bool Craft() = 0;

    QString getFirstName()
    {
        return first_name;
    }
    QString getLastName()
    {
        return last_name;
    }
    QString getBirthDay()
    {
        return birthday.inStringRu();
    }

    virtual QString getExtraName() = 0;

    void setData(QString f, QString l, int d, int m, int y)
    {
        last_name = l;
        first_name = f;
        birthday = {d, m, y};
    }

};

#endif
