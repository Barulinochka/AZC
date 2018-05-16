#include "cashbox.h"
#include "iostream"
#include <QtDebug>
using namespace std;

cashbox::cashbox(int time,QObject *parent) : QObject(parent)
{   queue = 0;
    serviceTime = time;
    timer = new QTimer;
    NoQueue=true;

    connect(timer,SIGNAL(timeout()),SLOT(Reduction()));
    connect(this,SIGNAL(busy()),SLOT(Start()));
    connect(this,SIGNAL(free()),SLOT(Stop()));
}

cashbox::~cashbox()
{

}

void cashbox::Start(){
    timer->start(serviceTime);

}
void cashbox::Stop(){
    timer->stop();
}
void cashbox::Clear(){
    queue = 0;
    emit queueChanged(queue);
}

void cashbox::SetServiceTime(int time){
   serviceTime = time*1000;
   qDebug() << "Service time of cashbox (sec): " << time;
}

void cashbox::AddMans(){
    if (queue==0) emit busy();
    queue++;
    emit queueChanged(queue);
}

void cashbox::Reduction(){
    if (queue == 0) emit free();
    else{
        emit goToHome();
        queue--;
    }
    emit queueChanged(queue);
    qDebug() << "Один обслужен, осталось ещё : " << queue;
}
