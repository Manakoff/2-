#include "prog1window.h"
#include "ui_prog1window.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

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
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть данные", "", "Text Files (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        // 2. Читаем строки и сразу вставляем в LineEdit'ы
        // Убедитесь, что objectName полей совпадают с кодом ниже
        ui->lineEdit->setText(in.readLine());       // Название
        ui->lineEdit_2->setText(in.readLine());       // Описание
        ui->lineEdit_3->setText(in.readLine());     // Текущая прочность
        ui->lineEdit_4->setText(in.readLine());     // Начальная прочность
        ui->lineEdit_5->setText(in.readLine());     // Редкость
        ui->lineEdit_6->setText(in.readLine());      // Цена

        file.close();
    }
}


void prog1Window::on_pushButton_2_clicked()
{
    QString filePath = "data.json";
    QJsonArray rootArray;

    // 1. Читаем существующий файл (если он есть), чтобы не стереть старые данные
    QFile readFile(filePath);
    if (readFile.exists()) { // Проверяем, существует ли он вообще
        if (readFile.open(QIODevice::ReadOnly)) {
            QByteArray data = readFile.readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            if (doc.isArray()) {
                rootArray = doc.array();
            }
            readFile.close();
        }
    }

    // 2. Собираем новый объект из полей формы
    QJsonObject newItem;
    newItem["name"] = ui->lineEdit->text();
    newItem["description"] = ui->lineEdit_2->text();
    newItem["currentDurability"] = ui->lineEdit_3->text().toInt(); // сохраняем как текст для валидации позже
    newItem["initialDurability"] = ui->lineEdit_4->text().toInt();
    newItem["rarity"] = ui->lineEdit_5->text();
    newItem["price"] = ui->lineEdit_6->text().toInt();

    // 3. Добавляем в массив
    rootArray.append(newItem);

    // 4. Сохраняем обратно в файл
    QFile writeFile(filePath);
    if (writeFile.open(QIODevice::WriteOnly)) {
        writeFile.write(QJsonDocument(rootArray).toJson());
        writeFile.close();
    }

    // Опционально: закрыть окно после добавления
    this->close();
}

