#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), stopwatch(this)
{
    ui->setupUi(this);
    ui->label->setText("00:00:00");
    ui->pushButton->setText("Start");
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setText("Split");
    ui->pushButton_3->setText("Reset");

    connect(&stopwatch, &StopWatch::timeUpdated, this, &MainWindow::updateDisplay);
    connect(&stopwatch, &StopWatch::lapRecorded, this, &MainWindow::displayLapTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->isChecked()) {
        ui->pushButton->setText("Stop");
        stopwatch.start();
    } else {
        ui->pushButton->setText("Start");
        stopwatch.stop();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->append(stopwatch.getLapTime());
}

void MainWindow::on_pushButton_3_clicked()
{
    stopwatch.reset();
    ui->label->setText("00:00:00");
    ui->pushButton->setText("Start");
    ui->textBrowser->clear();
    ui->pushButton->setChecked(false);
}

void MainWindow::updateDisplay(const QString &time)
{
    ui->label->setText(time);
}

void MainWindow::displayLapTime(const QString &lapTime)
{
    ui->textBrowser->append(lapTime);
}
