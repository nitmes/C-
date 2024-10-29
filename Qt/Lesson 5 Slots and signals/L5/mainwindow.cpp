#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("00:00:00");
    ui->pushButton->setText("Start");
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setText("Split");
    ui->pushButton_3->setText("Reset");
    elapsedMinutes=0;
    elapsedSeconds = 0;
    elapsedMilliseconds = 0;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateStopWatch);
    lapNumber = 1;
    lastLapTime=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->isChecked()) {
           ui->pushButton->setText("    Stop");
            timer->start(100);
       } else {
           ui->pushButton->setText("Start");
           timer->stop();
       }
}
void MainWindow::updateStopWatch()
{
    elapsedMilliseconds += 100;
    if (elapsedMilliseconds >= 1000) {
        elapsedSeconds++;
        elapsedMilliseconds = 0;
    }
    if (elapsedSeconds >= 60) {
        elapsedSeconds = 0;
        elapsedMinutes++;
    }

    QString timeText = QString("%1:%2:%3")
                       .arg(elapsedMinutes, 2, 10, QChar('0'))
                       .arg(elapsedSeconds, 2, 10, QChar('0'))
                       .arg(elapsedMilliseconds / 10, 2, 10, QChar('0'));

    ui->label->setText(timeText);
}
void MainWindow::on_pushButton_2_clicked()
{
    int currentLapTime = elapsedSeconds + (elapsedMinutes * 60);
    int lapDifference = currentLapTime - lastLapTime;
    lastLapTime = currentLapTime;
    QString lapTime = QString("Круг %1: %2:%3.%4 (разница: %5:%6)")
                        .arg(lapNumber++)
                        .arg(elapsedMinutes, 2, 10, QChar('0'))
                        .arg(elapsedSeconds, 2, 10, QChar('0'))
                        .arg(elapsedMilliseconds / 10, 2, 10, QChar('0'))
                        .arg(lapDifference / 60, 2, 10, QChar('0'))
                        .arg(lapDifference % 60, 2, 10, QChar('0')); \

    ui->textBrowser->append(lapTime);

}
void MainWindow::on_pushButton_3_clicked()
{
    elapsedSeconds = 0;
    elapsedMilliseconds = 0;
    ui->label->setText("00:00:00");
    ui->pushButton->setText("Start");
    lapNumber = 1;
    ui->textBrowser->clear();
    timer->stop();
}




