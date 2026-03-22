#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rup.h"
#include "amp.h"
#include <QTableWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QVector>


QVector<R*> people;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Фамилия", "Имя", "Отчество / 2-е имя", "Дата рождения"});
    ui->tableWidget->verticalHeader()->hide();
}

MainWindow::~MainWindow()
{
    for(R* p : people)
        delete p;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Открыть список", "", "*.txt");

    if (path.isEmpty())
        return;

    QFile file(path);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        for(R* p : people)
            delete p;
        people.clear();

        ui->tableWidget->setRowCount(0);

        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.trimmed().isEmpty())
                continue;

            QStringList list = line.split(',', Qt::KeepEmptyParts);

            if (list.size() < 7)
                continue;

            int code = list[0].toInt();

            if (code == 1)
            {
                RuP* p = new RuP();

                p->setData(list[2], list[1], list[4].toInt(), list[5].toInt(), list[6].toInt());
                p->setPatronymic(list[3]);
                people.append(p);
            }
            else if (code == 2)
            {
                AmP* p = new AmP();

                p->setData(list[1], list[3], list[5].toInt(), list[4].toInt(), list[6].toInt());
                p->setSecondName(list[2]);
                people.append(p);
            }
        }

        file.close();


        ui->tableWidget->setRowCount(0);

        for (R* p : people)
        {
            int row = ui->tableWidget->rowCount();

            ui->tableWidget->insertRow(row);

            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(p->getLastName()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(p->getFirstName()));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(p->getExtraName()));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(p->getBirthDay()));
        }
    }
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    int row = item->row();

    if (row < 0 || row >= people.size())
        return;

    if (people[row]->Craft())
    {
        delete people.takeAt(row);

        ui->tableWidget->removeRow(row);
    }
}


