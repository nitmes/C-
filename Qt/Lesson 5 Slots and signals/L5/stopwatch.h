#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QString>
#include <QTimer>

class StopWatch : public QObject
{
    Q_OBJECT

public:
    explicit StopWatch(QObject *parent = nullptr);

    QString getTimeText() const;
    QString getLapTime();
    void start();
    void stop();
    void reset();

signals:
    void timeUpdated(const QString &time);
    void lapRecorded(const QString &lapTime);

private slots:
    void update();

private:
    int elapsedMinutes;
    int elapsedSeconds;
    int elapsedMilliseconds;
    int lapNumber;
    int lastLapTime;
    QTimer *timer;
};

#endif // STOPWATCH_H
