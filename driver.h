#ifndef DRIVER_H
#define DRIVER_H

#include <QObject>
#include "azs.h"
#include "cashbox.h"
#include "queue.h"
#include "manqueue.h"


class driver : public QObject
{
    Q_OBJECT
public:
    explicit driver(QObject *parent = 0);
    ~driver();

signals:
    void FirstQueueChanged(int);
    void SecondQueueChanged(int);
    void ThirdQueueChanged(int);
    void ManQueueChanged(int);

public slots:
    void Start();
    void Stop();
    void Clear();
    void SetServiceManTime(int);
    void SetServiceCarTime(int);
    void SetSpeedCarQueue(int);
    void SetSpeedManQueue(int);

    void okGoToCB();

private:
    cashbox *man;
    azs *first, *second, *third;
    queue *carQueue;
    manqueue *manQueue;
};

#endif // DRIVER_H
