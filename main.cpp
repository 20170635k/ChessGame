#include "fileuimanagersave.h"//nuevo
#include <QApplication>
#include "menugame.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MenuGame* m=new MenuGame(a);
    m->show();


//    FileUIManagerSave fsave;
//    fsave.show();
    return a.exec();
}
