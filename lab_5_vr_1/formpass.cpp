#include "formpass.h"
#include "ui_formpass.h"

FormPass::FormPass(QString name, QString date, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormPass)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);

    ui->label_2->setText(name + "\n" + date);
}

FormPass::~FormPass()
{
    delete ui;
}
