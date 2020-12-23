#ifndef FILEUIMANAGER_H
#define FILEUIMANAGER_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QCoreApplication>
#include "filemovementpiecemanager.h"
#include "movementpiece.h"
#include <QTableWidget>
#include <QHeaderView>
class FileUIManagerSave:public QDialog
{
    Q_OBJECT
public:
    explicit FileUIManagerSave(QTableWidget* table,QWidget *parent=0);
    void addMovement(MovementPiece* movement);
    void vectorMovemetsToStream(std::vector<MovementPiece*> movements, QTextStream &stream);
private:
    FileMovementPieceManager *dataToSave;
    QPushButton * saveButton;
    QTextEdit * nameFile;
    QHBoxLayout * layoutContainer;
    std::vector<MovementPiece*> movements;
    QTableWidget* tableWidget;
private slots:
    void saveGameData();

};

#endif // FILEUIMANAGER_H
