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
#include <QFile>
#include <QResizeEvent>
#include <QSize>
#include <QApplication>
#include <QScreen>
#include "selettore.h"

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
    void addChessboard(int width, int height);
protected:
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;

    //aggiunge il menù alla vista
    void addMenu();
    void setStyle();

    void cleanGrid();
private slots:
    void nuovaPartita();

signals:
    void selectedGame(Gioco*);

};

#endif // MAINWINDOW_H
