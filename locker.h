#ifndef LOCKER_H
#define LOCKER_H
#include <QPushButton>
#include <iostream>
#include "mainwindow.h"
#include "piece.h"

class MainWindow;

class Lockerc:public QPushButton
{
    Q_OBJECT
public:
    Lockerc(QWidget *parent=nullptr);

    virtual ~Lockerc(){};

    void setPiece(Piece* piece);
    Piece* getPiece();

    void setMainWindow(MainWindow*);

    void rePaint(std::string msg);
    void rePaint();
    void pintarCamino();
    void despintarCamino();
    void setStroke();
    void removeStroke();
    void setPosition(uint16_t x, uint16_t y);
    Position* getPosition();
    bool getHabilitado();
    void setHabilitado(bool);

public slots:
    void handleButton();
private:
    Piece* piece{nullptr};
    MainWindow *contenedor;
    Position* pos;
    bool habilitado=false;

};
#endif // LOCKER_H
