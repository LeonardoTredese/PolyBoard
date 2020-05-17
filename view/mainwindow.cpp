#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QWidget(parent), mainLayout(new QVBoxLayout(this)), gridLayout(new QGridLayout())
{
    addMenu();
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(gridLayout);
    setStyle();
    setLayout(mainLayout);
}

void mainWindow::addMenu()
{
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
    //alla pressione del tasto "Nuova partita", esso viene raccolto
    //dallo slot "Nuova partita" di mainwindow.
    connect(nuova, SIGNAL(triggered()), this, SLOT(nuovaPartita()));
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

void mainWindow::addChessboard(int width, int height) 
{
    //TODO: Creare vector per i QPushButton, per raggiungerli più
    //facilmente
    cleanGrid();
    boardWidth = width;
    boardHeight = height;
    bool j = false;
    for(int i=0; i<width*height; ++i)
    {
        if(i % width)
            j = !j;
        ChessButton *button = new ChessButton(Posizione(i%width,i/width), this);
        button->setMinimumHeight(button->width());
        connect(button, SIGNAL(clicked(Posizione)), this, SIGNAL(casellaSelezionata(Posizione)));
        if(j)
            button->setObjectName("black");
        else
            button->setObjectName("white");
        //button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        gridLayout->addWidget(button, i/width, i%width);
    }
}

//quando viene invocato il metodo di resize, imposta l'altezza in base alla larghezza con setFixedHeight(width)
void mainWindow::resizeEvent(QResizeEvent *event)  // TODO
{
    event->accept();
    setFixedHeight(width()); 
    for(int i=0; i < gridLayout->count(); i++)
    {
        ChessButton* button = static_cast<ChessButton*>(gridLayout->itemAt(i)->widget());
        button->setMinimumHeight(button->width());
        button->setIconSize(button->size()*0.8);
    }   
}

void mainWindow::setStyle()
{
    //setFixedSize(width(), height());   
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    int dim = height > width ? width:height;
    dim *= 0.95;
    setMaximumSize(dim,dim); 
    gridLayout->setSpacing(0);
    QFile file(":/resources/chess/style.css"); // TODO: mettere style globale
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}
void mainWindow::cleanGrid()
{
    for(int i=gridLayout->count()-1; i >= 0; i--)
        delete gridLayout->itemAt(i)->widget();
}

void mainWindow::nuovaPartita() const
{
    SelettoreGioco* sel = new SelettoreGioco(); // TODO: Senza this come parent esegue delete automatica?
    connect(sel, SIGNAL(creaScacchi()), this, SIGNAL(nuovaPartitaScacchi()));
}

void mainWindow::mossaNonValida()
{
    QDialog *err = new QDialog(this);
    QVBoxLayout *layout_errore = new QVBoxLayout(err);
    layout_errore->addWidget(new QLabel(QString("Mossa non valida, reinserire posizione!"),err));
    err->show();
}

void mainWindow::aggiungiPedina(const Posizione& pos, const ID& pedina, const TipoGioco& tipoGioco)
{
    QString pathIcon(QString::fromStdString(":/resources/"+tipoGiocoToString(tipoGioco)+"/icons/"));
    if(tipoGioco == chess)
    {
        switch(pedina.getTipo())
        {
            case 'B': 
                pathIcon += "bishop";  
                break;
            case 'N': 
                pathIcon += "knight";
                break;
            case 'K':
                pathIcon += "king";
                break;
            case 'P':
                pathIcon += "pawn";
                break;
            case 'Q':
                pathIcon += "queen";
                break;
            case 'R': 
                pathIcon += "rook";
                break;
            default:
                pathIcon = "";
                break;
        }
    }
    pathIcon += "_"; 
    switch(pedina.getColore())
    {
        case bianco:
            pathIcon += "white";
            break;
        case nero:
            pathIcon += "black";
            break;
        default:
            pathIcon = "";
            break;
    }
    pathIcon += ".png";
    ChessButton* button = static_cast<ChessButton*>(gridLayout->itemAt(pos.x+pos.y*boardWidth)->widget());
    button->setIcon(QIcon(pathIcon));
    button->setMinimumHeight(button->width());
    button->setIconSize(button->size()*0.8);
}

void mainWindow::pulisciCella(const Posizione& pos)
{
    ChessButton* button = dynamic_cast<ChessButton*>(gridLayout->itemAt(pos.x+pos.y*boardWidth)->widget());
    button->setIcon(QIcon());
}

void mainWindow::selezionaPromozioneScacchi()
{
    SelettorePromozioneScacchi *sel = new SelettorePromozioneScacchi();
    connect(sel, SIGNAL(pedinaSelezionata(char)), this, SIGNAL(promozioneScacchi(char)));
}