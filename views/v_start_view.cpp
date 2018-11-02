#include "v_start_view.h"

ListinoWindow::ListinoWindow(QMainWindow* parent) :
    QMainWindow(parent),
    dettagli(new QPushButton("Dettagli del prodotto", this)),
    elimina(new QPushButton("Elimina", this)),
    inserisci(new QPushButton("Inserisci", this)),
    tabella_listino(new QTableWidget(12,3,this)),
    intestaz_col(new QStringList),
    toolbar(addToolBar("ciao")),
    controller (new ControllerListino)
{
       //serve un selectedRow e non una selectRow
       //connect(dettagli_prodotto, SIGNAL(clicked()), this, SLOT(cercaView( tabella_listino->selectRow();-1 )));
       /*
       tabella_listino->setSelectionMode(QAbstractItemView::SingleSelection);

       connect(elimina, SIGNAL(clicked()), this, slotElimina());
-       */
       connect(dettagli, SIGNAL(clicked()), controller, SLOT(showDetails()));
       setGeometry(50,50,350,700);
       setCentralWidget(tabella_listino);
       toolBarArea(toolbar);
       toolbar->setMovable(false);
       toolbar->addWidget(dettagli);
       toolbar->addWidget(inserisci);
       toolbar->addWidget(elimina);
       tabella_listino->setGeometry(10,10,350,700);
       *intestaz_col << "Descrizione" << "Prezzo" << "[...]";
       tabella_listino->setHorizontalHeaderLabels(*intestaz_col);
       elimina->setEnabled(false);
       dettagli->setEnabled(false);
       connect(tabella_listino, SIGNAL(cellClicked(int, int)), this, SLOT(abilitaDettagli()));
       connect(tabella_listino, SIGNAL(cellClicked(int, int)), this, SLOT(abilitaElimina()));
       show();
}

QTableWidget* ListinoWindow::centralWidget() {return static_cast<QTableWidget*>(QMainWindow::centralWidget());}

/*
void ListinoWindow::slotElimina () {
    QModelIndexList selezione = table->selectionModel()->selectedRows();
    int selected_row = selezione.at(0).row();
    MyVector::eliminaProdotto(0);
    //cioè eliminazione dal vettore e dal file
    MyVector.load();
}
*/
void ListinoWindow::abilitaElimina() {
    elimina->setEnabled(true);
}

void ListinoWindow::abilitaDettagli() {
    dettagli->setEnabled(true);
}