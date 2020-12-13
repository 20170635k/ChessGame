#include "mainwindow.h"
#include "fileuimanagersave.h"//nuevo
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    FileUIManagerSave fsave;
//    fsave.show();
    return a.exec();
}
