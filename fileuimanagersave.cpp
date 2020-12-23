#include "fileuimanagersave.h"

FileUIManagerSave::FileUIManagerSave(QTableWidget* table,QWidget *parent):
    QDialog(parent),tableWidget{table}
{

    //caracteristicas de table
    tableWidget->setColumnCount(1);
    tableWidget->setRowCount(0);
    tableWidget->setColumnWidth(0,200);
    tableWidget->horizontalHeader()->hide();
    QLabel *label= new QLabel("Nombre de Juego");
    setWindowTitle("Guardar Juego");
    saveButton= new QPushButton("guardar");
    nameFile= new QTextEdit();
    layoutContainer= new QHBoxLayout();
    nameFile->setMaximumHeight(30);
    nameFile->setMinimumHeight(30);
    layoutContainer->addWidget(label);
    layoutContainer->addWidget(nameFile);
    layoutContainer->addWidget(saveButton);
    setLayout(layoutContainer);


    //pruebas
//    movements.push_back(new MovementPiece);
//    movements.push_back(new MovementPiece);
//    movements.push_back(new MovementPiece);

    //connect SIGNAL TO BUTTON save
    QObject::connect(saveButton,SIGNAL(clicked()),this,SLOT(saveGameData()));
}

void FileUIManagerSave:: saveGameData(){

    QString nameGame=nameFile->toPlainText();
    std::cout<<"name: "<<QCoreApplication::applicationDirPath().toStdString()<<std::endl;
    QString path=QCoreApplication::applicationDirPath()+"/"+nameGame +".txt";
    QFile file(path);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream stream(&file);
        vectorMovemetsToStream(movements,stream);
    }
    file.close();
}
void FileUIManagerSave:: vectorMovemetsToStream(std::vector<MovementPiece*> movements, QTextStream &stream){

    for(auto c:movements){
        stream<<c->getMovement()<<"\n";
    }
}
void FileUIManagerSave:: addMovement(MovementPiece *movement){
    movements.push_back(movement);
    std::string path=":/images/iconos/"+movement->getPieceMoved()->getImagen();
            QTableWidgetItem* i1=new QTableWidgetItem(
                        QIcon(path.c_str()),
                        movement->getMovement());
            tableWidget->setRowCount(tableWidget->rowCount()+1);
            tableWidget->setItem(tableWidget->rowCount()-1,0,i1);

}
