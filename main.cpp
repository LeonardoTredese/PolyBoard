#include "controller.h"
#include <QApplication>
#include <iostream>
/*
CONTROLLER: main.cpp

VISTA: mainwindow.cpp

MODELLO: derivato di gioco.cpp(sacchi)
*/

using std::cout; using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c1(&a);
    return a.exec();
}
