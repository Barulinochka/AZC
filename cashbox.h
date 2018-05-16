#ifndef CASHBOX_H
#define CASHBOX_H

#include <QObject>
#include <QTimer>
#include <QtDebug>

class cashbox : public QObject
{
    Q_OBJECT
public:
    explicit cashbox(int time,QObject *parent = 0);
    ~cashbox();
signals:
    void queueChanged(int);
    void busy();
    void free();
    void goToHome();

public slots:
    void Start();
    void Stop();
    void Clear();
    void SetServiceTime(int);
    void AddMans();
    void Reduction();

private:
    unsigned int queue;
    double serviceTime;
    QTimer *timer;
    bool NoQueue;
};

#endif // CASHBOX_H
