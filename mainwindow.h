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

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
protected:
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;

    //aggiunge il menù alla vista
    void addMenu();
    void addButtons(int, int);
    void setStyle();
signals:

};

#endif // MAINWINDOW_H
