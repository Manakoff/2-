#include "rup.h"
#include "formpass.h"

bool RuP::Craft()
{
    QString full = last_name + "\n" + first_name + "\n" + getExtraName();

    FormPass dial(full, birthday.inStringRu());

    return (dial.exec() == QDialog::Accepted);
}
