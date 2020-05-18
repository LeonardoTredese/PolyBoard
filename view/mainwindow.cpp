#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), mainLayout(new QVBoxLayout(this)), gridLayout(new QGridLayout())
{
    addMenu();
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(gridLayout);
    setStyle();
    setLayout(mainLayout);
}

void MainWindow::addMenu()
{
    // Creare la barra dei menu, poi il menu e infine le azioni
    QMenuBar* menubar = new QMenuBar(this);
    //MENU FILE
    QMenu* file = new QMenu("File",menubar);
    QAction* save = new QAction("Salva",file);
    QAction* save_name = new QAction("Salva con Nome",file);
    QAction* load = new QAction("Carica",file);
    QAction* nuova= new QAction("Nuova Partita",file);

    file->addAction(nuova);
    file->addAction(load);
    file->addAction(save);
    file->addAction(save_name);

    //alla pressione del tasto "Nuova partita", esso viene raccolto
    //dallo slot "Nuova partita" di mainwindow.
    connect(nuova, SIGNAL(triggered()), this, SLOT(nuovaPartita()));
    //MENU PARTITA
    QMenu *partita = new QMenu("Partita",menubar);

    QAction *reset = new QAction("Reset",partita);
    QAction *resa = new QAction("Dichiara Resa",partita);
    QAction *pareggio = new QAction("Dichiara Pareggio",partita);
    connect(reset, SIGNAL(triggered()), this, SIGNAL(resetFinestra()));
    connect(resa,SIGNAL(triggered()),this,SIGNAL(resa()));
    connect(pareggio,SIGNAL(triggered()),this,SIGNAL(pareggio()));
    partita->addAction(reset);
    partita->addAction(resa);
    partita->addAction(pareggio);

    //aggiungo i menu alla menubar
    menubar->addMenu(file);
    menubar->addMenu(partita);

    // Aggiungo la menubar al layout
    mainLayout->addWidget(menubar);
}

void MainWindow::addChessboard(int width, int height) 
{
    //TODO: Creare vector per i QPushButton, per raggiungerli più
    //facilmente
    pulisciFinestra();
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
void MainWindow::resizeEvent(QResizeEvent *event)  // TODO
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

void MainWindow::setStyle()
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
void MainWindow::pulisciFinestra()
{
    for(int i=gridLayout->count()-1; i >= 0; i--)
        delete gridLayout->itemAt(i)->widget();
}

void MainWindow::nuovaPartita() const
{
    SelettoreGioco* sel = new SelettoreGioco(); // TODO: Senza this come parent esegue delete automatica?
    connect(sel, SIGNAL(creaScacchi()), this, SIGNAL(nuovaPartitaScacchi()));
}

void MainWindow::mossaNonValida()
{
    QDialog *err = new QDialog(this);
    QVBoxLayout *layout_errore = new QVBoxLayout(err);
    layout_errore->addWidget(new QLabel(QString("Mossa non valida, reinserire posizione!"),err));
    err->show();
}

void MainWindow::aggiungiPedina(const Posizione& pos, const ID& pedina, const TipoGioco& tipoGioco)
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

void MainWindow::pulisciCella(const Posizione& pos)
{
    ChessButton* button = dynamic_cast<ChessButton*>(gridLayout->itemAt(pos.x+pos.y*boardWidth)->widget());
    button->setIcon(QIcon());
}

void MainWindow::selezionaPromozioneScacchi()
{
    SelettorePromozioneScacchi *sel = new SelettorePromozioneScacchi();
    setEnabled(false);
    connect(sel, SIGNAL(pedinaSelezionata(char)), this, SIGNAL(promozioneScacchi(char)));
}

void MainWindow::dialogFinePartita(const QString& text)
{
    QDialog *winner= new QDialog(this);
    QVBoxLayout *winner_layout= new QVBoxLayout(winner);
    winner_layout->addWidget(new QLabel(text));
    setEnabled(false);
    connect(winner, SIGNAL(finished(int)), this, SIGNAL(terminaPartita()));
    winner->show();
}

void MainWindow::mostraVincitore(const Colore& vincitore)
{
    dialogFinePartita(QString::fromStdString("Ha vinto il giocatore " + coloreToString(vincitore)));
}

void MainWindow::mostraVincitoreResa(const Colore& vincitore)
{
    dialogFinePartita(QString::fromStdString("Il giocatore avversario si è arreso.\nHa vinto il giocatore " + coloreToString(vincitore)));
}

void MainWindow::mostraPareggio()
{
    dialogFinePartita(QString::fromStdString("La partita è terminata in pareggio."));
}
