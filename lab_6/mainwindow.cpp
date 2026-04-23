#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_on_btnProgram1_clicked()
{
    window1.setWindowModality(Qt::ApplicationModal);
    window1.show();
}


void MainWindow::on_on_btnProgram2_clicked()
{
    window2.setWindowModality(Qt::ApplicationModal);
    window2.show();
}

