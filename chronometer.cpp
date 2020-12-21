#include "chronometer.h"

Chronometer::Chronometer(QWidget *parent):
    QWidget(parent)
{
    QHBoxLayout * ly = new QHBoxLayout;
    setLayout(ly);//layout a his widget
    ly->addWidget(l = new QLabel(this));
    connect(&t, SIGNAL(timeout()), this, SLOT(updateTime()));
    this->start();
    this->pause();
}
uint32_t Chronometer:: DURATION_TIME=240000;
