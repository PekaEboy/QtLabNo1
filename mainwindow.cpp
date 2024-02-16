#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(
            ui->leCELSIUM, &QLineEdit::textChanged,
            this, &MainWindow::on_click
            );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbEXIT_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pbTRANSLATE_clicked()
{
    QString scelsium = ui->leCELSIUM->text();
    bool celsium_ok;
    double cel = scelsium.toDouble(&celsium_ok);
    if(celsium_ok) {
        double faren = 9*cel/5+32;
        double reomur = 4*cel/5;
        double kelvin = cel +273.15;
        ui->lblFAREN->setText(QString::number(faren, 'f', 2));
        ui->lblREOMUR->setText(QString::number(reomur, 'f', 2));
        ui->lblKELVIN->setText(QString::number(kelvin, 'f', 2));
    } else {
        QMessageBox msgb;   // Объявляем объект "окно сообщения"
        msgb.setText("Ошибка ввода");   // Задаём текст сообщения
        msgb.exec();
    }
}

void MainWindow::on_click() {
    ui->lblFAREN->setText("");
    ui->lblREOMUR->setText("");
    ui->lblKELVIN->setText("");
}

