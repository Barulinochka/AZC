#ifndef QUEUE_H
#define QUEUE_H

#include <QObject>
#include <QTimer>
#include "iostream"
using namespace std;

class queue : public QObject
{
    Q_OBJECT
public:
    explicit queue(int newSpeed, QObject *parent = 0);
   // ~queue();

signals:
    void addFirst();
    void addSecond();
    void addThird();

public slots:
    void Start();
    void Stop();
    void SetFirstQueue(int);
    void SetSecondQueue(int);
    void SetThirdQueue(int);
    void SetSpeed(int);
    void Distribution();
    void okGoToHomeCar();

private:
    float speed;
    QTimer *timer;
    int first, second, third;

};

#endif // QUEUE_H
