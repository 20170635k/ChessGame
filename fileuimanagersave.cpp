#include "fileuimanagersave.h"

FileUIManagerSave::FileUIManagerSave(QWidget *parent):
    QDialog(parent)
{
    setWindowTitle("Save file Manager");
    saveButton= new QPushButton();
    nameFile= new QTextEdit();
    layoutContainer= new QHBoxLayout();

    layoutContainer->addWidget(nameFile);
    layoutContainer->addWidget(saveButton);
    setLayout(layoutContainer);

    //pruebas
    movements.push_back(new MovementPiece);
    movements.push_back(new MovementPiece);
    movements.push_back(new MovementPiece);

    //connect SIGNAL TO BUTTON save
    QObject::connect(saveButton,SIGNAL(clicked()),this,SLOT(saveGameData()));
}

void FileUIManagerSave:: saveGameData(){
    QString nameGame=nameFile->toPlainText();
    QString fname="C:\\Users\\pc\\Desktop\\UNIVERSIDAD\\8vo semestre\\TO\\Proyecto\\ChessGame-copy\\games\\"+nameGame+".txt";
    QFile file(fname);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream stream(&file);
        vectorMovemetsToStream(movements,stream);
    }
    file.close();
}
void FileUIManagerSave:: vectorMovemetsToStream(std::vector<MovementPiece*> movements, QTextStream &stream){

    for(auto c:movements){
        stream<<c->formatString()<<endl;
    }
}
