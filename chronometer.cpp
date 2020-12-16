#include "chronometer.h"

Chronometer::Chronometer(QWidget *parent):
    QWidget(parent)
{
    QHBoxLayout * ly = new QHBoxLayout;
    setLayout(ly);
    ly->addWidget(l = new QLabel(this));
    l->setText(QTime(0, 0).toString());
//      ly->addWidget(startB = new QPushButton("start", this));
//      ly->addWidget(stopB = new QPushButton("stop", this));
    connect(&t, SIGNAL(timeout()), this, SLOT(updateTime()));
//      connect(startB, SIGNAL(clicked(bool)), this, SLOT(start()));
//      connect(stopB, SIGNAL(clicked(bool)), &t, SLOT(stop()));
    this->start();
    this->pause();
}
uint32_t Chronometer:: DURATION_TIME=240000;
