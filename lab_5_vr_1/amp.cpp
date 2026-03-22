#include "amp.h"
#include "formpass.h"

bool AmP::Craft()
{
    QString full = first_name + "\n" + getExtraName() + "\n" + last_name;

    FormPass dial(full, birthday.inStringAm());

    return (dial.exec() == QDialog::Accepted);
}
