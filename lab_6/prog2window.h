#ifndef PROG2WINDOW_H
#define PROG2WINDOW_H

#include <QDialog>

namespace Ui {
class prog2Window;
}

class prog2Window : public QDialog
{
    Q_OBJECT

public:
    explicit prog2Window(QWidget *parent = nullptr);
    ~prog2Window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::prog2Window *ui;
};

#endif // PROG2WINDOW_H
