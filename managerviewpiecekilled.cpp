#include "managerviewpiecekilled.h"

ManagerViewPieceKilled::ManagerViewPieceKilled(QGridLayout *white, QGridLayout *black):
    whiteBoxPieces{white}, blackBoxPieces(black)
{

}

void ManagerViewPieceKilled:: addPieceKilled(Piece *killed){
    QPushButton* pieceKilled=new QPushButton();
    pieceKilled->setMaximumWidth(20);//agregamos las dimensiones del boton
    pieceKilled->setMaximumHeight(20);//
    pieceKilled->setMinimumWidth(20);
    pieceKilled->setMinimumHeight(20);
    pieceKilled->setIconSize(QSize(20,20));//agrega el tamaño al icono de este boton
    pieceKilled->setIcon(QIcon(("C:/Users/pc/Desktop/UNIVERSIDAD/8vo semestre/TO/Proyecto/ChessGame/iconos/"+killed->getImagen()).c_str()));
    if(killed->getType()==killed->TYPE_BLACK){
        blackBoxPieces->addWidget(pieceKilled,this->sizeblack/8,this->sizeblack%8);
        blackPieces.push_back(killed);
        sizeblack++;
    }else{
        whiteBoxPieces->addWidget(pieceKilled,this->sizewhite/8,this->sizewhite%8);
        whitePieces.push_back(killed);
        sizewhite++;
    }

}

