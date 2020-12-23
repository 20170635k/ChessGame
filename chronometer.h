#ifndef CHRONOMETER_H
#define CHRONOMETER_H
#include <QElapsedTimer>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <iostream>
class Chronometer : public QWidget {
    Q_OBJECT
    QTime startTime;
    QTimer t;
    QLabel * l;

private:
    uint32_t countTime{0};
    uint32_t shotTime{0};
    bool playing{false};

public:
    Chronometer(QWidget *parent=nullptr);
    static uint32_t DURATION_TIME;
public slots:
    void updateTime() {
            shotTime=startTime.elapsed();
            l->setText(QTime(0, 0).addMSecs(DURATION_TIME-(shotTime-countTime)).toString());
            //std::cout<<QTime(0, 0).addMSecs(DURATION_TIME-(shotTime-countTime)).toString().toStdString()<<std::endl;

    }

    void start() {
        countTime=0;
        shotTime=0;
        l->setText(QTime(0, 0).addMSecs(DURATION_TIME).toString());
        startTime.restart();
        t.start(1000);
    }
    void resume(){
        countTime+=startTime.elapsed()-shotTime;
        t.start(1000);
    }
    void pause(){
        t.stop();
    }
    void stop() {
        t.stop();
    }

};

#endif // CHRONOMETER_H
