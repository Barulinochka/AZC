#ifndef MANQUEUE_H
#define MANQUEUE_H

#include <QObject>
#include <QTimer>
#include "iostream"
using namespace std;

class manqueue : public QObject
{
    Q_OBJECT

public:
    explicit manqueue(int newSpeed, QObject *parent = 0);

signals:
    void addMan();

public slots:
    void Start();
    void Stop();
    void SetManQueue(int queue);
    void SetSpeed(int newSpeed);
    void Distribution();

private:
    float speed;
    QTimer *timer;
    int q1, q2, q3, q;

};

#endif // MANQUEUE_H
