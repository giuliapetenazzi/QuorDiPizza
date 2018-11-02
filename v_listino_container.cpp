#include "v_listino_container.h"


ListinoContainer::ListinoContainer() {
    load();
}

int ListinoContainer::load()  {
    QFile file("/home/giulia/projects/QuorDiPizza/prodotti.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) std::cout << "Errore nell'apertura" << std::endl;
    QTextStream in(&file);
    QString tipo_banco (in.readLine());
    QString tipo_pizza (in.readLine());
    in.readLine();
    int count_products =0;
    while(!in.atEnd()) {
        QString tipo = in.readLine();
        if(tipo== tipo_banco){
            QString d (in.readLine());
            double p (in.readLine().toDouble());
            QString c (in.readLine());
            listino.push_back(new Banco(d, p, c));

            count_products++;
        }
        else if(tipo== tipo_pizza) {
            QStringList* ingred = new QStringList;
            int n_ingr = in.readLine().toInt();
            for (int n=0; n < n_ingr; n++) {
                QString aux = in.readLine();
                *ingred << aux;
            }
            QString d (in.readLine());
            listino.push_back(new Pizza(d, *ingred));
            count_products++;
            in.readLine();
        }
    }
    //MyWidgetListino l(*this);
    //ListinoWindow lw;
    return count_products;
}
/*
int ListinoContainer::eliminaProdotto(int n) {
    QFile file("/home/giulia/projects/QuorDiPizza/prodotti.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) std::cout << "Errore nell'apertura" << std::endl;
    QTextStream in(&file);
    QString tipo_banco (in.readLine());
    QString tipo_pizza (in.readLine());
    in.readLine();
    int count_products =0;
    while(!in.atEnd()) {

    }
}
*/