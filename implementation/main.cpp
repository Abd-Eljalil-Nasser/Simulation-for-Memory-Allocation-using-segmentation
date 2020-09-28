#include "mainwindow.h"
#include <QApplication>
#include<hole.h>
#include<List>
int MemorySize;
int NumberOfHoles;
int flag=0;
QString method;
std::list <hole> memory;
std::list<QString> combox;
int NumberOfSegments;
int processNumber =0;
int flag2;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
