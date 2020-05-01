#include "mainwindow.h"
#include <QApplication>
#include <iostream>

using std::cout; using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow window;
    window.show();
    return a.exec();
}
