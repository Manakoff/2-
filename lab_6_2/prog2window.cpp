#include "prog2window.h"
#include "ui_prog2window.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QCloseEvent>
#include <QMessageBox>

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
    // Читаем файл
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите JSON файл", "", "JSON Files (*.json)");
    if (filePath.isEmpty())
        return;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (doc.isNull()) {
        QMessageBox::critical(this, "Ошибка файла",
                              "Файл поврежден, имеет неверный формат или не является списком объектов.");
    }
    QJsonArray allData = doc.array();
    file.close();

    // Очищаем таблицы
    ui->tableWidget->setRowCount(0);
    ui->tableWidget_2->setRowCount(0);

    QJsonArray validArray;
    QJsonArray errorArray;

    for (int i = 0; i < allData.size(); ++i) {
        QJsonObject obj = allData[i].toObject();

        QJsonValue vName = obj["name"];
        QJsonValue vDesc = obj["description"];
        QJsonValue vCur  = obj["currentDurability"];
        QJsonValue vIni  = obj["initialDurability"];
        QJsonValue vRar  = obj["rarity"];
        QJsonValue vPrice = obj["price"];

        bool isOk = true;

        // ПРОВЕРКА 1: Текстовые поля
        if (vName.isString() == false || vDesc.isString() == false || vRar.isString() == false)
        {
            isOk = false;
        }
        if (vName.toString().isEmpty() || vRar.toString().isEmpty())
        {
            isOk = false;
        }

        // ПРОВЕРКА 2: Числовые поля
        if (!vCur.isDouble() || !vIni.isDouble() || !vPrice.isDouble())
        {
            isOk = false;
        }
        if (vCur.isDouble() == false || vIni.isDouble() == false || vPrice.isDouble() == false)
        {
            isOk = false;
        } else
        {
            int cur = vCur.toInt();
            int ini = vIni.toInt();
            double price = vPrice.toInt();

            if (cur < 0 || ini <= 0 || cur > ini || price < 0)
            {
                isOk = false;
            }
        }

        // Выбор таблицы
        QTableWidget* target;
        if (isOk == true)
        {
            target = ui->tableWidget;
            validArray.append(obj);
        } else
        {
            target = ui->tableWidget_2;
            errorArray.append(obj);
        }

        // Вывод данных в выбранную таблицу
        QStringList displayValues;
        displayValues << vName.toVariant().toString()
                      << vDesc.toVariant().toString()
                      << vCur.toVariant().toString()
                      << vIni.toVariant().toString()
                      << vRar.toVariant().toString()
                      << vPrice.toVariant().toString();

        // 3. ВЫВОД В ВЫБРАННУЮ ТАБЛИЦУ
        int row = target->rowCount();
        target->insertRow(row);

        for (int col = 0; col < 6; ++col)
        {
            QTableWidgetItem *item = new QTableWidgetItem(displayValues[col]);

            if (isOk == false)
            {
                bool cellHasError = false;

                if (col == 0)
                { // Название
                    if (vName.isString() == false || vName.toString().isEmpty()) cellHasError = true;
                }
                else if (col == 1)
                { // Описание
                    if (vDesc.isString() == false) cellHasError = true;
                }
                else if (col == 2)
                { // Тек. прочность
                    if (vCur.isDouble() == false || vCur.toInt() < 0 || (vIni.isDouble() && vCur.toInt() > vIni.toInt()))
                        cellHasError = true;
                }
                else if (col == 4)
                { // Редкость
                    if (vRar.isString() == false || vRar.toString().isEmpty())
                        cellHasError = true;
                }
                else if (col == 3)
                { // Нач. прочность
                    if (vIni.isDouble() == false || vIni.toInt() <= 0)
                        cellHasError = true;
                }
                else if (col == 5)
                { // Цена
                    if (vPrice.isDouble() == false || vPrice.toDouble() < 0)
                        cellHasError = true;
                }

                if (cellHasError == true)
                {
                    item->setBackground(Qt::red);
                }
            }
            target->setItem(row, col, item);
        }
    }

    // Сохраняем результаты в файлы
    QFile vFile("data.json");
    if (vFile.open(QIODevice::WriteOnly))
    {
        vFile.write(QJsonDocument(validArray).toJson());
        vFile.close();
    }

    QFile eFile("errors.json");
    if (eFile.open(QIODevice::WriteOnly))
    {
        eFile.write(QJsonDocument(errorArray).toJson());
        eFile.close();
    }
}


