#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    gridLayout = new QGridLayout();
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);
    addMenu();
    addButtons(8,8);
    setStyle();
    mainLayout->addLayout(gridLayout);
    setLayout(mainLayout);
}


void mainWindow::addMenu(){
    // Creare la barra dei menu, poi il menu e infine le azioni
    QMenuBar* menubar = new QMenuBar(this);
    //MENU FILE
    QMenu* file = new QMenu("File",menubar);
    QAction* exit = new QAction("Exit",file);
    QAction* save = new QAction("Salva",file);
    QAction* save_name = new QAction("Salva con Nome",file);
    QAction* load = new QAction("Carica",file);
    QAction* nuova= new QAction("Nuova Partita",file);

    file->addAction(nuova);
    file->addAction(load);
    file->addAction(save);
    file->addAction(save_name);
    file->addAction(exit);

    //MENU PARTITA
    QMenu *partita = new QMenu("Partita",menubar);

    QAction *reset = new QAction("Reset",partita);
    QAction *resa = new QAction("Dichiara Resa",partita);
    QAction *pareggio = new QAction("Dichiara Pareggio",partita);

    partita->addAction(reset);
    partita->addAction(resa);
    partita->addAction(pareggio);

    //aggiungo i menu alla menubar
    menubar->addMenu(file);
    menubar->addMenu(partita);

    // Aggiungo la menubar al layout
    mainLayout->addWidget(menubar);
}

void mainWindow::addButtons(int width, int height)
{
    bool j = false;
    for(int i=0; i<width*height; ++i)
    {
        if(i % width)
            j = !j;
        QPushButton *button = new QPushButton(this);
        if(j)
            button->setObjectName("black");
        else
            button->setObjectName("white");
        button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        gridLayout->addWidget(button,i/width,i%width);
    }
}

//quando viene invocato il metodo di resize, imposta l'altezza in base alla larghezza con setFixedHeight(width)
void mainWindow::resizeEvent(QResizeEvent *event)  // TODO
{
    event->accept();
    setFixedHeight(width());
}

void mainWindow::setStyle()
{
    
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    int dim = height > width ? width:height;
    dim *= 0.95;
    setMaximumSize(dim,dim);
    setWindowFlags(Qt::Drawer);
    gridLayout->setSpacing(0);
    setMinimumSize(dim/4,dim/4);  // TODO
    QFile file(":/resources/chess/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}
