#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "locker.h"
#include "piece.h"
#include "player.h"
#include "fileuimanagersave.h"
#include <QHBoxLayout>
#include "managerviewpiecekilled.h"
#include "chronometer.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class Lockerc;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initButtons(int16_t x,int16_t y,Piece* newpiece);
    void setPushed(Lockerc*);
    Lockerc* getPushed();
    bool isPushed();
    Player* getPlayerTurn();
    void setPlayerTurn(Player* turnplayer);
    void changeTurn();
    void playControl(Lockerc* bpushed);
private:
    Ui::MainWindow *ui;
    //posición presionada
    Lockerc *pushed{nullptr};
    std::vector<Lockerc*> casilleros;
    Player* white;
    Player* black;
    Player* playerturn{nullptr};
    FileUIManagerSave* formSaveGame;//--nuevo
    ManagerViewPieceKilled *killedViewManager;
    Chronometer* chronowhite;
    Chronometer* chronoblack;


};
#endif // MAINWINDOW_H
