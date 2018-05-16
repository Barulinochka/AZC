#include "manqueue.h"
#include "iostream"
#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

manqueue::manqueue(int newSpeed,QObject *parent) : QObject(parent)
{
    speed = 60/newSpeed;
    timer = new QTimer;
    q = 0;

    connect(timer,SIGNAL(timeout()),SLOT(Distribution()));
}

void manqueue::Start(){
    timer->start(speed);
}
void manqueue::Stop(){
    timer->stop();
}

void manqueue::SetManQueue(int queue){
    q = queue;
}
void manqueue::SetSpeed(int newSpeed){

    speed =newSpeed*1000;
    qDebug() << "Car queue speed set "<<newSpeed;
}

void manqueue::Distribution(){
    emit addMan();
    qDebug() << "Очередь у кассы" << q;
}
