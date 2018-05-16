#ifndef AZS_H
#define AZS_H

#include <QObject>
#include <QTimer>
#include <QtDebug>

class azs : public QObject
{
    Q_OBJECT
public:
    explicit azs(int time,QObject *parent = 0);
    ~azs();
signals:
    void queueChanged(int);
    void busy();
    void free();
    void goToCB();
    void goToHomeCar();

public slots:
    void Start();
    void Stop();
    void Clear();
    void SetServiceTime(int);
    void AddCars();
    void Reduction();
    void okGoToHome();


private:
    unsigned int queue;
    double serviceTime;
    QTimer *timer;
    bool NoQueue;
};

#endif // AZS_H
