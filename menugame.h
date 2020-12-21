#ifndef MENUGAME_H
#define MENUGAME_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include "fileuimanagersave.h"
#include <QApplication>
class MenuGame : public QDialog
{
    Q_OBJECT
public:
    explicit MenuGame(QApplication &a,QWidget *parent=0);
    virtual ~MenuGame() {}
private:
    QVBoxLayout *layoutContainer;
    QPushButton *startGame;
    QPushButton *saveLogGame;
    QPushButton *exit;
    QLabel *imageLogo;
    QLabel * imageFondo;
    FileUIManagerSave* formSaveGame;//--nuevo
};

#endif // MENUGAME_H
