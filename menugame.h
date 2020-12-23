#ifndef MENUGAME_H
#define MENUGAME_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QApplication>
#include "fileuimanagersave.h"
#include "mainwindow.h"

class MenuGame : public QDialog
{
    Q_OBJECT
public:
    MenuGame(MainWindow* mainwindow, QApplication &a,FileUIManagerSave* saveManager,QWidget *parent=0);
    virtual ~MenuGame() {}

private:
    QVBoxLayout *layoutContainer;
    QPushButton *startGame;
    QPushButton *saveLogGame;
    QPushButton *exit;
    QLabel *imageLogo;
    QLabel * imageFondo;
    FileUIManagerSave* formSaveGame;//--nuevo
    MainWindow *mainwindow;
public slots:
    void startGameSlot();
};

#endif // MENUGAME_H
