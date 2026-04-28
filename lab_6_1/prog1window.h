#ifndef PROG1WINDOW_H
#define PROG1WINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class prog1Window;
}

class prog1Window : public QDialog
{
    Q_OBJECT

public:
    explicit prog1Window(QWidget *parent = nullptr);
    ~prog1Window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::prog1Window *ui;
    QFile inputFile;
    QTextStream *inStream = nullptr;
};

#endif // PROG1WINDOW_H
