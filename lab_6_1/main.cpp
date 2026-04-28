#include "prog1window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prog1Window w;
    w.show();
    return a.exec();
}
