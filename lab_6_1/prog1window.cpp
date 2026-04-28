#include "prog1window.h"
#include "ui_prog1window.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>

prog1Window::prog1Window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::prog1Window)
{
    ui->setupUi(this);
}

prog1Window::~prog1Window()
{
    delete ui;
}

void prog1Window::on_pushButton_clicked()
{
    if (inStream == nullptr)
    {
        QString fileName = QFileDialog::getOpenFileName(this, "Открыть данные", "", "Text Files (*.txt)");
        if (fileName.isEmpty()) return;

        inputFile.setFileName(fileName);
        if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            inStream = new QTextStream(&inputFile);
        } else
        {
            return;
        }
    }

    if (!inStream->atEnd())
    {
        QString line = inStream->readLine();
        QStringList data = line.split(",");

        if (data.size() >= 6)
        {
            ui->lineEdit->setText(data[0].trimmed());
            ui->lineEdit_2->setText(data[1].trimmed());
            ui->lineEdit_3->setText(data[2].trimmed());
            ui->lineEdit_4->setText(data[3].trimmed());
            ui->lineEdit_5->setText(data[4].trimmed());
            ui->lineEdit_6->setText(data[5].trimmed());
        }
    } else
    {
        QMessageBox::information(this, "Конец", "Все строки из файла прочитаны.");
        inputFile.close();
        delete inStream;
        inStream = nullptr;
    }
}

void prog1Window::on_pushButton_2_clicked()
{

    if (ui->lineEdit->text().trimmed().isEmpty() &&
        ui->lineEdit_2->text().trimmed().isEmpty() &&
        ui->lineEdit_3->text().trimmed().isEmpty() &&
        ui->lineEdit_4->text().trimmed().isEmpty() &&
        ui->lineEdit_5->text().trimmed().isEmpty() &&
        ui->lineEdit_6->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Заполните хотя бы одно поле перед сохранением!");
        return;
    }

    QString filePath = "data.json";
    QJsonArray rootArray;

    //Читаем старые данные
    QFile readFile(filePath);
    if (readFile.open(QIODevice::ReadOnly))
    {
        rootArray = QJsonDocument::fromJson(readFile.readAll()).array();
        readFile.close();
    }

    QJsonObject newItem;

    // 1. Проверка Имени
    bool okName;
    int namVal = ui->lineEdit->text().toInt(&okName);
    if (!okName)
    {
        newItem["name"] = ui->lineEdit->text();
    }else
    {
        newItem["name"] = namVal;
    }

    // 2. Проверка Описания
    bool okDesc;
    int desVal = ui->lineEdit_2->text().toInt(&okDesc);
    if(!okDesc)
    {
        newItem["description"] = ui->lineEdit_2->text();
    }else
    {
        newItem["description"] = desVal;
    }

    // 3. Проверка Текущей прочности
    bool okCur;
    int curVal = ui->lineEdit_3->text().toInt(&okCur);
    if (okCur)
    {
        newItem["currentDurability"] = curVal; // Записываем как число
    } else
    {
        newItem["currentDurability"] = ui->lineEdit_3->text(); // Записываем как текст
    }

    // 4. Проверка Начальной прочности
    bool okIni;
    int iniVal = ui->lineEdit_4->text().toInt(&okIni);
    if (okIni)
    {
        newItem["initialDurability"] = iniVal;
    } else
    {
        newItem["initialDurability"] = ui->lineEdit_4->text();
    }

    // 5. Проверка Редкости
    bool okRar;
    int rarVal = ui->lineEdit_5->text().toInt(&okRar);
    if(!okRar)
    {
        newItem["rarity"] = ui->lineEdit_5->text();
    }else
    {
        newItem["rarity"] = rarVal;
    }

    // 6. Проверка Цены
    bool okPrice;
    double priceVal = ui->lineEdit_6->text().toInt(&okPrice);
    if (okPrice)
    {
        newItem["price"] = priceVal;
    } else
    {
        newItem["price"] = ui->lineEdit_6->text();
    }

    //Сохраняем данные
    rootArray.append(newItem);
    QFile writeFile(filePath);
    if (writeFile.open(QIODevice::WriteOnly))
    {
        writeFile.write(QJsonDocument(rootArray).toJson());
        writeFile.close();
    }

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();

    ui->lineEdit->setFocus();

    // this->close();
}

