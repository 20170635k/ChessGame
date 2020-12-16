#ifndef FILEUIMANAGER_H
#define FILEUIMANAGER_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QCoreApplication>
#include "filemovementpiecemanager.h"
#include "movementpiece.h"

class FileUIManagerSave:public QDialog
{
    Q_OBJECT
public:
    explicit FileUIManagerSave(QWidget *parent=0);
    void vectorMovemetsToStream(std::vector<MovementPiece*> movements, QTextStream &stream);
private:
    FileMovementPieceManager *dataToSave;
    QPushButton * saveButton;
    QTextEdit * nameFile;
    QHBoxLayout * layoutContainer;
    std::vector<MovementPiece*> movements;
private slots:
    void saveGameData();

};

#endif // FILEUIMANAGER_H
