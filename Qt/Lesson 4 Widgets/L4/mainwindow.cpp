#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton->setText("Correct reload after 100 percent");
    ui->radioButton_2->setText("Button 'GO' work correctly");

    ui->comboBox->addItem("10 percent");
    ui->comboBox->addItem("20 percent");
    ui->comboBox->addItem("30 percent");

    ui->pushButton->setText("GO");
    ui->pushButton->setCheckable(true);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int value = ui->progressBar->value();
        if (value >= ui->progressBar->maximum()) {
            ui->progressBar->setValue(0);
        } else {
            ui->progressBar->setValue(value + 1);
        }
}

