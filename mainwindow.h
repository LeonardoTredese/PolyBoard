#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

class mainWindow : public QMainWindow
{
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;

    //aggiunge il menù alla vista
    void addMenu();
    void addButtons(int, int);
signals:

};

#endif // MAINWINDOW_H
