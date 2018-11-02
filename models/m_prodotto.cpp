#include "models/m_prodotto.h"

Prodotto::Prodotto(const QString& d, double p) : descrizione(d), prezzo(p){}
Prodotto::~Prodotto() {};
double Prodotto::getPrezzo() const {return prezzo;}
QString Prodotto::getDescrizione() const {return descrizione;}
bool Prodotto::operator== (const Prodotto& p) {return prezzo==p.prezzo && descrizione==p.descrizione;}

Banco::Banco(const QString& descr, double pr, const QString& cat)
    : Prodotto(descr, pr), categoria(cat) {}
/*
Banco::~Banco() {
}
Pizza::~Pizza(){
}
*/
bool Banco::operator== (const Banco& b) {
    return  Prodotto::operator==(b) &&
            categoria == b.categoria;
}

QString Banco::getCategoria() const {
    return categoria;
}

double Pizza::coperto = 1.50;

Pizza::Pizza(const QString& descr, const QStringList& ingr)
    : Prodotto(descr, 3), ingredienti(ingr) {}

double Pizza::getPrezzo() const {
    return Prodotto::getPrezzo() + coperto + 0.5 * ingredienti.size();
}

bool Pizza::operator== (const Pizza& p) {
    return  Prodotto::operator==(p) &&
            ingredienti== p.ingredienti;
}

QStringList Pizza::getIngredienti() const {
    return ingredienti;
}

/*
ostream& operator<< (ostream& os, const Prodotto& p) {
        os << "Ingrediente: " << (p.getDescrizione).toStdString() << "Prezzo: " << p.getPrezzo() << endl;
        return os;
}
*/