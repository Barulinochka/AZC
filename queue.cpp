#include "queue.h"
#include "iostream"
#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

queue::queue(int newSpeed,QObject *parent) : QObject(parent)
{
    speed = 60/newSpeed;
    timer = new QTimer;
    first=0;
    second=0;
    third=0;

    connect(timer, SIGNAL(timeout()), SLOT (Distribution()));

}

void queue::Start(){
    timer->start(speed);
}
void queue::Stop(){
    timer->stop();
}

void queue::SetFirstQueue(int queue){
    first = queue;
}
void queue::SetSecondQueue(int queue){
    second = queue;
}
void queue::SetThirdQueue(int queue){
    third = queue;
}
void queue::SetSpeed(int newSpeed){
    speed =newSpeed*1000;
    qDebug() << "Car queue speed set "<<newSpeed;
}

void queue::Distribution(){
    if (third >= second || third >= first){
        if (second >= first) emit addFirst();
        else emit addSecond();
    }
    else emit addThird();
    qDebug() << "Очередь 'Первая' = " << first << " 'Вторая' = " << second << " 'Третья' = " << third;
}
void queue::okGoToHomeCar(){
   // first--;
}
