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
    pieceKilled->setIcon(QIcon((":/images/iconos/"+killed->getImagen()).c_str()));
    if(killed->getType()==killed->TYPE_BLACK){
        blackBoxPieces->addWidget(pieceKilled,this->sizeblack/8,this->sizeblack%8);
        blackPieces.push_back(pieceKilled);
        sizeblack++;
    }else{
        whiteBoxPieces->addWidget(pieceKilled,this->sizewhite/8,this->sizewhite%8);
        whitePieces.push_back(pieceKilled);
        sizewhite++;
    }

}

void ManagerViewPieceKilled:: clearManager(){
    for(unsigned i =0;i<whitePieces.size();i++){
        whiteBoxPieces->removeWidget(whitePieces[i]);
    }
    for(unsigned i =0;i<blackPieces.size();i++){
       blackBoxPieces->removeWidget(blackPieces[i]);
    }

    whitePieces.clear();
    blackPieces.clear();
}
