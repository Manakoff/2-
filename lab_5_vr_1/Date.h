#ifndef DATE_H
#define DATE_H

#include <QString>

struct BirthDay {
    int day;
    int month;
    int year;

    QString inStringRu() const {
        return QString("%1.%2.%3")
        .arg(day, 2, 10, QChar('0'))
            .arg(month, 2, 10, QChar('0'))
            .arg(year);
    }
    QString inStringAm() const {
        return QString("%1-%2-%3")
        .arg(day, 2, 10, QChar('0'))
            .arg(month, 2, 10, QChar('0'))
            .arg(year);
    }

};

#endif // DATE_H
