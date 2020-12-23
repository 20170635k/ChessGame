#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "locker.h"
#include "piece.h"
#include "player.h"
#include "notificationmanager.h"
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
    MainWindow(QApplication&a, QWidget *parent = nullptr);
    ~MainWindow();
    void initButtons(int16_t x,int16_t y,Piece* newpiece);
    void setPushed(Lockerc*);
    Lockerc* getPushed();
    bool isPushed();
    Player* getPlayerTurn();
    void setPlayerTurn(Player* turnplayer);
    void changeTurn();
    void playControl(Lockerc* bpushed);
    void habilitarMov(Lockerc*pushed);
    void deshabilitarMov(Lockerc*pushed);
    void removerPieza(Lockerc*pushed);
    bool jake(Piece*jake);
    void endGame();
    void startNewGame();

    Piece* reyNegro;
    Piece * reyBlanco;
    NotificationManager* notificationManager;
    Chronometer* chronowhite;
    Chronometer* chronoblack;
    Player* white;
    Player* black;
    bool enJuego{false};
    FileUIManagerSave * movementManager;
    void startPieces();
private:
    Ui::MainWindow *ui;
    //posición presionada
    Lockerc *pushed{nullptr};
    std::vector<Lockerc*> casilleros;
    Player* playerturn{nullptr};

    NotificationManager* notificationManagerSpecial;
    ManagerViewPieceKilled *killedViewManager;



};



#endif // MAINWINDOW_H
