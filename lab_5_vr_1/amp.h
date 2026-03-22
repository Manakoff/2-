#ifndef AMP_H
#define AMP_H

#include "r.h"

class AmP : public R {
private:
    QString second_name;

public:
    void setSecondName(QString s)
    {
        second_name = s;
    }

    QString getExtraName()
    {
        if (second_name.isEmpty())
        {
            return "-";
        }
        else
        {
            return second_name;
        }
    }

    bool Craft();
};

#endif
