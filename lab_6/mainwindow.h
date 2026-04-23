#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "prog1window.h"
#include "prog2window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_on_btnProgram1_clicked();

    void on_on_btnProgram2_clicked();

private:
    Ui::MainWindow *ui;
    prog1Window window1;
    prog2Window window2;
};
#endif // MAINWINDOW_H
