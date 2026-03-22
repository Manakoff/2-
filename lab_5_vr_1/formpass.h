#ifndef FORMPASS_H
#define FORMPASS_H

#include <QDialog>

namespace Ui {
class FormPass;
}

class FormPass : public QDialog
{
    Q_OBJECT

public:
    explicit FormPass(QString name, QString date, QWidget *parent = nullptr);
    ~FormPass();

private slots:

private:
    Ui::FormPass *ui;
};

#endif // FORMPASS_H
