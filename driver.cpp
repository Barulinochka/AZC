#include "driver.h"
#include <QtDebug>

driver::driver(QObject *parent) :
    QObject(parent)
{   first = new azs(1);
    second = new azs(1);
    third = new azs(1);
    carQueue = new queue(1);

    man = new cashbox(1);
    manQueue = new manqueue(5);

    connect(first,SIGNAL(queueChanged(int)),carQueue,SLOT(SetFirstQueue(int)));
    connect(first,SIGNAL(queueChanged(int)),SIGNAL(FirstQueueChanged(int)));

    connect(second,SIGNAL(queueChanged(int)),carQueue,SLOT(SetSecondQueue(int)));
    connect(second,SIGNAL(queueChanged(int)),SIGNAL(SecondQueueChanged(int)));

    connect(third,SIGNAL(queueChanged(int)),carQueue,SLOT(SetThirdQueue(int)));
    connect(third,SIGNAL(queueChanged(int)),SIGNAL(ThirdQueueChanged(int)));

    connect(carQueue,SIGNAL(addFirst()),first,SLOT(AddCars()));
    connect(carQueue,SIGNAL(addSecond()),second,SLOT(AddCars()));
    connect(carQueue,SIGNAL(addThird()),third,SLOT(AddCars()));

    connect(man,SIGNAL(queueChanged(int)),manQueue,SLOT(SetManQueue(int)));
    connect(man,SIGNAL(queueChanged(int)),SIGNAL(ManQueueChanged(int)));

    connect(manQueue,SIGNAL(addMan()),man,SLOT(AddMans()));

    connect(first, SIGNAL(goToCB()), manQueue, SLOT(Distribution()));
    connect(second, SIGNAL(goToCB()), manQueue, SLOT(Distribution()));
    connect(third, SIGNAL(goToCB()), manQueue, SLOT(Distribution()));

    connect(man, SIGNAL(goToHome()), first,SLOT(okGoToHome()));
    connect(man, SIGNAL(goToHome()), second,SLOT(okGoToHome()));
    connect(man, SIGNAL(goToHome()), third,SLOT(okGoToHome()));
    connect(first, SIGNAL(goToHomeCar()), carQueue, SLOT(okGoToHomeCar()));
    connect(second, SIGNAL(goToHomeCar()), carQueue, SLOT(okGoToHomeCar()));
    connect(third, SIGNAL(goToHomeCar()), carQueue, SLOT(okGoToHomeCar()));
}

driver::~driver()
{

}

void driver::Start(){
    carQueue->Start();
    manQueue->Start();
    qDebug() << "Start!";
}
void driver::Stop(){
    first->Stop();
    second->Stop();
    third->Stop();
    man->Stop();
    carQueue->Stop();
    manQueue->Stop();
    qDebug() << "Stop!";
}
void driver::Clear(){
    first->Clear();
    second->Clear();
    third->Clear();
    man->Clear();
}

void driver::SetServiceCarTime(int time){
    first->SetServiceTime(time);
    second->SetServiceTime(time);
    third->SetServiceTime(time);
}
void driver::SetServiceManTime(int time){
    man->SetServiceTime(time);
}
void driver::SetSpeedCarQueue(int speed){
    carQueue->SetSpeed(speed);
}

void driver::SetSpeedManQueue(int speed){
    manQueue->SetSpeed(speed);
}

void driver::okGoToCB(){
    manQueue->Start();
}
