#include "fileuimanagersave.h"//nuevo
#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window{a};
    window.show();

    return a.exec();
}
