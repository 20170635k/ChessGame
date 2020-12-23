#ifndef MANAGERVIEWPIECEKILLED_H
#define MANAGERVIEWPIECEKILLED_H
#include <QGridLayout>
#include <QPushButton>
#include "piece.h"
class ManagerViewPieceKilled
{
public:
    ManagerViewPieceKilled(QGridLayout *white, QGridLayout *black);
    void addPieceKilled(Piece* killed);

//    void removePieceKilled(Piece* )
    void clearManager();

private:
    QGridLayout *whiteBoxPieces;
    QGridLayout *blackBoxPieces;
    std::vector<QPushButton*> whitePieces;
    std::vector<QPushButton*> blackPieces;
    uint16_t sizewhite{0};
    uint16_t sizeblack{0};
};

#endif // MANAGERVIEWPIECEKILLED_H
