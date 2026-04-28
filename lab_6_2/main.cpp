#include "prog2window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prog2Window w;
    w.show();
    return a.exec();
}
