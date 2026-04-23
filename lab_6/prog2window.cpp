#include "prog2window.h"
#include "ui_prog2window.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTableWidgetItem>

prog2Window::prog2Window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::prog2Window)
{
    ui->setupUi(this);

    QStringList headers = {"Название", "Описание", "Тек. прочн.", "Нач. прочн.", "Редкость", "Цена"};

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget_2->setColumnCount(6);
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
}

prog2Window::~prog2Window()
{
    delete ui;
}
void prog2Window::on_pushButton_clicked()
{
    // 1. Читаем файл
    QFile file("data.json");
    if (!file.open(QIODevice::ReadOnly)) return;
    QJsonArray allData = QJsonDocument::fromJson(file.readAll()).array();
    file.close();

    // 2. Очищаем таблицы перед выводом
    ui->tableWidget->setRowCount(0);
    ui->tableWidget_2->setRowCount(0);

    QJsonArray validArray;
    QJsonArray errorArray;

    // 3. Обрабатываем каждый объект
    for (int i = 0; i < allData.size(); ++i) {
        QJsonObject obj = allData[i].toObject();

        // 1. Сначала извлекаем значения как QJsonValue (общий тип)
        QJsonValue vName = obj["name"];
        QJsonValue vDesc = obj["description"];
        QJsonValue vCur  = obj["currentDurability"];
        QJsonValue vIni  = obj["initialDurability"];
        QJsonValue vRar  = obj["rarity"];
        QJsonValue vPrice = obj["price"];

        // 2. Проверяем типы: строки должны быть строками, числа — числами
        // Также проверяем, что поля вообще существуют (!isUndefined)
        bool isOk = vName.isString() && !vName.toString().isEmpty() &&
                    vDesc.isString() &&
                    vRar.isString()  &&
                    vCur.isDouble()  &&
                    vIni.isDouble()  &&
                    vPrice.isDouble();

        // 3. Если по типам всё ок, проверяем внутреннюю логику чисел
        if (isOk) {
            int cur = vCur.toInt();
            int ini = vIni.toInt();
            int price = vPrice.toInt();

            if (cur < 0 || ini <= 0 || cur > ini || price < 0) {
                isOk = false;
            }
        }

        // 4. Выбираем таблицу и выводим данные
        QTableWidget* targetTable = isOk ? ui->tableWidget : ui->tableWidget_2;
        int row = targetTable->rowCount();
        targetTable->insertRow(row);

        // Используем toVariant().toString(), чтобы корректно отобразить даже "битые" данные
        targetTable->setItem(row, 0, new QTableWidgetItem(vName.toVariant().toString()));
        targetTable->setItem(row, 1, new QTableWidgetItem(vDesc.toVariant().toString()));
        targetTable->setItem(row, 2, new QTableWidgetItem(vCur.toVariant().toString()));
        targetTable->setItem(row, 3, new QTableWidgetItem(vIni.toVariant().toString()));
        targetTable->setItem(row, 4, new QTableWidgetItem(vRar.toVariant().toString()));
        targetTable->setItem(row, 5, new QTableWidgetItem(vPrice.toVariant().toString()));

        if (!isOk) {
            targetTable->item(row, 0)->setBackground(Qt::red);
            errorArray.append(obj);
        } else {
            validArray.append(obj);
        }
    }

    // 4. Сохраняем результаты (без лишних функций, прямо здесь)
    QFile vFile("data.json");
    if (vFile.open(QIODevice::WriteOnly)) {
        vFile.write(QJsonDocument(validArray).toJson());
    }

    QFile eFile("errors.json");
    if (eFile.open(QIODevice::WriteOnly)) {
        eFile.write(QJsonDocument(errorArray).toJson());
    }
}


