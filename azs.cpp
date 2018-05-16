#include "azs.h"
#include "iostream"
#include <QtDebug>
using namespace std;

azs::azs(int time,QObject *parent) : QObject(parent)
{   queue = 0;
    serviceTime = time;
    timer = new QTimer;
    NoQueue=true;

    connect(timer,SIGNAL(timeout()),SLOT(Reduction()));
    connect(this,SIGNAL(busy()),SLOT(Start()));
    connect(this,SIGNAL(free()),SLOT(Stop()));

}

azs::~azs()
{

}

void azs::Start(){
    timer->start(serviceTime);

}
void azs::Stop(){
    timer->stop();
}
void azs::Clear(){
    queue = 0;
    emit queueChanged(queue);
}

void azs::SetServiceTime(int time){
    serviceTime = time*1000;
    qDebug() << "Service time of station (sec): " << time;
}

void azs::AddCars(){
    if (queue == 0) emit busy();
    queue++;
    emit queueChanged(queue);
}

void azs::Reduction(){
    if (queue == 0) emit free();
    else{
        emit goToCB();
        queue--;
    }
    emit queueChanged(queue);
    qDebug() << "Заправился, очердь в кассу: " << queue;
}

void azs::okGoToHome(){
    queue--;
    if (queue == 0) emit free();
    emit goToHomeCar();
}
