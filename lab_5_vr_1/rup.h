#ifndef RUP_H
#define RUP_H

#include "r.h"


class RuP : public R {
private:
    QString patronymic;

public:
    void setPatronymic(QString p)
    {
        patronymic = p;
    }

    QString getExtraName()
    {
        if (patronymic.isEmpty())
        {
            return "-";
        }
        else
        {
            return patronymic;
        }
    }

    bool Craft();
};

#endif
