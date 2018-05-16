#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Driver = new driver();


    connect(ui->SliderInterval, SIGNAL(valueChanged(int)), Driver, SLOT(SetSpeedCarQueue(int)));
    connect(ui->SliderRefuelCar, SIGNAL(valueChanged(int)), Driver, SLOT(SetServiceCarTime(int)));
    connect(ui->SliderRefuelMan, SIGNAL(valueChanged(int)), Driver, SLOT(SetServiceManTime(int)));
    connect(ui->SliderRefuelCar, SIGNAL(valueChanged(int)), Driver, SLOT(SetSpeedManQueue(int)));



    connect(Driver,SIGNAL(FirstQueueChanged(int)),ui->CarQueueBar1,SLOT(setValue(int)));
    connect(Driver,SIGNAL(SecondQueueChanged(int)),ui->CarQueueBar2,SLOT(setValue(int)));
    connect(Driver,SIGNAL(ThirdQueueChanged(int)),ui->CarQueueBar3,SLOT(setValue(int)));
    connect(Driver,SIGNAL(ManQueueChanged(int)),ui->ManQueueBar,SLOT(setValue(int)));

    connect(ui->ButtonStart,SIGNAL(clicked()),this,SLOT(Start()));
    connect(ui->ButtonStart,SIGNAL(clicked()),Driver,SLOT(Start()));
    connect(ui->ButtonStop,SIGNAL(clicked()),this,SLOT(Stop()));
    connect(ui->ButtonStop,SIGNAL(clicked()),Driver,SLOT(Stop()));
    connect(ui->ButtonClear,SIGNAL(clicked()),Driver,SLOT(Clear()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Start()
{

    ui->SliderInterval->setEnabled(false);
    ui->SliderRefuelCar->setEnabled(false);
    ui->SliderRefuelMan->setEnabled(false);
}
void MainWindow::Stop()
{

    ui->SliderInterval->setEnabled(true);
    ui->SliderRefuelCar->setEnabled(true);
    ui->SliderRefuelMan->setEnabled(true);
}
void MainWindow::Clear()
{
    ui->CarQueueBar1->reset();
    ui->CarQueueBar2->reset();
    ui->CarQueueBar3->reset();
    ui->ManQueueBar->reset();
}
