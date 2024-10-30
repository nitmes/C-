#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stopwatch.h"
#include <QMainWindow>
#include <QTimer>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void updateDisplay(const QString &time);
    void displayLapTime(const QString &lapTime);

private:
    Ui::MainWindow *ui;
    StopWatch stopwatch;
};
#endif // MAINWINDOW_H
