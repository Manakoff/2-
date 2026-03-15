#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
