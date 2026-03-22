#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    struct Ticket
    {
        QString ticket;
        QString data;
        QString prize;
        QString name;
        bool result;
        QStringList ifles;


        Ticket(QString tic, QString dat, QString priz, QString nam, bool res, QStringList ifl)
        {
            ticket = tic;
            data = dat;
            prize = priz;
            name = nam;
            result = res;
            ifles = ifl;
        }
        void saveObject(QString filename) {
            QFile file_out(filename);
            if (file_out.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file_out);
                QString resultText;

                if (result) {
                    resultText = "Победа";
                }
                else {
                    resultText = "Поражение";
                }
                out << "Билет: " << ticket << " | Дата: " << data
                    << " | Приз: " << prize << " | Имя: " << name
                    << " | Результ: " << resultText
                    << " | Условия: " << ifles.join(", ") << "\n";
                file_out.close();
            }
        }
    };

    QRegularExpression tic("^\\d-\\d{5}$");
    QRegularExpression dat("^(0[1-9]|[12][0-9]|3[01])\\.(0[1-9]|1[0-2])\\.\\d{4}$");
    QRegularExpression priz("^[A-ZА-Я][a-zа-я]*$");
    QRegularExpression nam("^[А-Я][а-я]*$");

    if (!tic.match(ui->lineEdit->text()).hasMatch())
    {
        QMessageBox::warning(this, "Внимани!", "Неверный ввод № билета (X-XXXXX)");
        return;
    }
    if (!dat.match(ui->lineEdit_2->text()).hasMatch())
    {
        QMessageBox::warning(this, "Внимани!", "Неверный ввод Дата (дд.мм.гггг)");
        return;
    }
    if (!priz.match(ui->lineEdit_3->text()).hasMatch())
    {
        QMessageBox::warning(this, "Внимани!", "Неверный ввод Приз (анг+рус, только первая буква слова капсом)");
        return;
    }
    if (!nam.match(ui->lineEdit_4->text()).hasMatch())
    {
        QMessageBox::warning(this, "Внимани!", "Неверный ввод Имя (рус, только первая буква слова капсом)");
        return;
    }
    if (!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked()) {
        QMessageBox::warning(this, "Ошибка", "Выберите результат (Победа/Поражение)");
        return;
    }

    QStringList ifgrup;
    if (ui->checkBox->isChecked())
    {
        ifgrup << "Личное присутствие";
    }
    if (ui->checkBox_2->isChecked())
    {
        ifgrup << "Только юр. лица";
    }
    if (ui->checkBox_3->isChecked())
    {
        ifgrup << "Подарок";
    }

    Ticket newTicket(
        ui->lineEdit->text(),
        ui->lineEdit_2->text(),
        ui->lineEdit_3->text(),
        ui->lineEdit_4->text(),
        ui->radioButton->isChecked(),
        ifgrup
        );

    newTicket.saveObject("result.txt");
    QMessageBox::information(this, "Всё корректно", "Данные сохранены");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->radioButton->setAutoExclusive(false);
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(false);
    ui->radioButton->setAutoExclusive(true);
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);

}

