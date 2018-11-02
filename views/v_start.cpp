#include "v_start.h"

v_start::v_start(QWidget* parent) :
    QWidget(parent),
    label(new QLabel(this)),
    table_ordini(new QTableWidget(12,4,this)),
    tab_reparto(new QTabWidget),
    area_banco (new QWidget),
    area_pizzeria (new QWidget),
       quit(new QPushButton("Quit", this)),
       unisci(new QPushButton("Unisci al tavolo [...]", this)),
       separa(new QPushButton("Separa [...]", this)),
       totale(new QPushButton("Visualizza totale", this)),
       chiudi_conto(new QPushButton("Chiudi conto", this)),
    intestaz_col(new QStringList),
    elimina (new QPushButton(QIcon("elimina.png"), "", this)),
    modifica(new QPushButton(QIcon("modifica.jpg"), "", this)),
    layout_est(new QVBoxLayout),
    layout(new QHBoxLayout),
    layout_int(new QVBoxLayout)

{
       setWindowTitle("Quor di pizza");
       setGeometry(500, 500, 850, 500);
       label->setText("Conto");
       label->setAlignment(Qt::AlignCenter);
       setStyleSheet(
                            "QLabel {"
                                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ff6666, stop: 1 #cc6666);"
                                    "alignment::center;"
                                    "border-radius:7px;"
                                    "border:1px solid #330000;"
                                    "color:#330000;"
                                    "font-size:15px;"
                                    "font-weight:bold;"
                                    "padding:4px 24px;"
                            "}"
        );

       *intestaz_col << "Descrizione" << "Prezzo" << "Modifica" << "Elimina";
       table_ordini->setHorizontalHeaderLabels(*intestaz_col);
       table_ordini->setColumnWidth(1, 60);
       table_ordini->setColumnWidth(2, 60);
       table_ordini->setColumnWidth(3, 60);

       QWidget* auxWidget = new QWidget();
       modifica->setMaximumWidth(30);
       QHBoxLayout* auxLayout = new QHBoxLayout(auxWidget);
       auxLayout->addWidget(modifica);
       auxLayout->setAlignment(Qt::AlignCenter);
       auxLayout->setContentsMargins(0, 0, 0, 0);
       auxWidget->setLayout(auxLayout);
       table_ordini->setCellWidget(0, 2, auxWidget);

       QWidget* auxxWidget = new QWidget();
       elimina->setMaximumWidth(30);
       QHBoxLayout* auxxLayout = new QHBoxLayout(auxxWidget);
       auxxLayout->addWidget(elimina);
       auxxLayout->setAlignment(Qt::AlignCenter);
       auxxLayout->setContentsMargins(0, 0, 0, 0);
       auxxWidget->setLayout(auxxLayout);
       table_ordini->setCellWidget(0, 3, auxxWidget);

       area_banco->setLayout(new QGridLayout);

       tab_reparto->setGeometry(50,50,200,200);
       tab_reparto->insertTab(0, area_banco, "Banco");
       tab_reparto->insertTab(1, area_pizzeria, "Pizzeria");
       //tab_reparto->insertTab(1, area_cucina, "Cucina");

       separa->setEnabled(false);

       layout_est->addWidget(label);
       layout_est->addItem(layout);

       layout->addWidget(tab_reparto);
       layout->addWidget(table_ordini);

       layout->addItem(layout_int);
       layout_int->addWidget(totale);
       layout_int->addWidget(chiudi_conto);
       layout_int->addWidget(unisci);
       layout_int->addWidget(separa);
       layout_int->addWidget(quit);
       setLayout(layout_est);
       show();
}

