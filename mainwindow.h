#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QPushButton>
#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QPushButton>
#include <QProgressBar>
#include "azs.h"
#include "queue.h"
#include "manqueue.h"
#include "driver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void Start();
    void Stop();
    void Clear();

private:
    Ui::MainWindow *ui;
    QSlider *SliderInterval,*SliderRefuelCar,*SliderRefuelMan;
    QPushButton *ButtonStart,*ButtonStop,*ButtonClear;
    QProgressBar *CarQueueBar1,*CarQueueBar2,*CarQueueBar3,*ManQueueBar;
    QLabel *label, *label2, *label3, *label4, *label5;
    driver *Driver;
};

#endif // MAINWINDOW_H
