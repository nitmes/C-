#include "stopwatch.h"

StopWatch::StopWatch(QObject *parent)
    : QObject(parent),
      elapsedMinutes(0), elapsedSeconds(0), elapsedMilliseconds(0),
      lapNumber(1), lastLapTime(0)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StopWatch::update);
}

void StopWatch::start()
{
    timer->start(100);
}

void StopWatch::stop()
{
    timer->stop();
}

void StopWatch::reset()
{
    elapsedMinutes = 0;
    elapsedSeconds = 0;
    elapsedMilliseconds = 0;
    lapNumber = 1;
    lastLapTime = 0;
    timer->stop();
}

QString StopWatch::getTimeText() const
{
    return QString("%1:%2:%3")
        .arg(elapsedMinutes, 2, 10, QChar('0'))
        .arg(elapsedSeconds, 2, 10, QChar('0'))
        .arg(elapsedMilliseconds / 10, 2, 10, QChar('0'));
}

QString StopWatch::getLapTime()
{
    int currentLapTime = elapsedSeconds + (elapsedMinutes * 60);
    int lapDifference = currentLapTime - lastLapTime;
    lastLapTime = currentLapTime;

    QString lapTime = QString("Круг %1: %2 (разница: %3:%4)")
        .arg(lapNumber++)
        .arg(getTimeText())
        .arg(lapDifference / 60, 2, 10, QChar('0'))
        .arg(lapDifference % 60, 2, 10, QChar('0'));
    return lapTime;
}

void StopWatch::update()
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

    emit timeUpdated(getTimeText());
}
