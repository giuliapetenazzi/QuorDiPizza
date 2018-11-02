#include "models/m_tavolo.h"

tavolo::tavolo() :numero(0), first(0) {}
tavolo::tavolo(int n, nodo* f) : numero(n), first(f) {}
tavolo::tavolo(tavolo* b) :first(copia(b->first)) {}; // copia(first) restituisce un nodo*

tavolo::nodo::nodo(Prodotto* prod_ric, nodo* nodo_ric) // implementazione del costruttore di un nodo con due param
    : info(prod_ric), next(nodo_ric) {}

tavolo::~tavolo() {if (first) delete first;}// distruttore: prima esegue il corpo cioè distruggi first
                                            // e poi chiama il distruttore di default di tavolo che distrugge
                                            // il puntatore first che sta sullo stack e che serve per raggiungere la lista

tavolo::nodo::~nodo() {if (next != 0) delete next;}// distruttore: prima esegue il corpo cioè distruggi first
                                            // e poi chiama il distruttore di default di tavolo che distrugge
                                            // il puntatore first che sta sullo stack e che serve per raggiungere la lista
bool tavolo::vuoto() const {
	return first == 0;
}

//metodi di iteratore========================================================================
bool tavolo::iteratore::operator==(iteratore i_ric) const {return punt == i_ric.punt;}
bool tavolo::iteratore::operator!=(iteratore i_ric) const {return punt != i_ric.punt;}
tavolo::iteratore& tavolo::iteratore::operator++() { // operatore ++ prefisso
    if (punt) punt = punt->next;
    return *this;
}
tavolo::iteratore  tavolo::iteratore::operator++(int) {// operatore ++ postfisso
    iteratore aux = *this;
    if (punt) punt = punt->next;
    return aux;
}
tavolo::iteratore tavolo::begin() const {
    iteratore aux;
    aux.punt = first;
    return aux;
}
tavolo::iteratore tavolo::end() const {
    iteratore aux;
    aux.punt = 0;
    return aux;
}
Prodotto* tavolo::operator[](tavolo::iteratore i) const { //PRE punt != 0
    return (i.punt)->info;
}
//===========================================================================================

tavolo::nodo* tavolo::ultimoNodo() const {
    nodo* n = first;
    while(n) n=n->next;
    delete n;
    return n;
}
int tavolo::getNumero() const {
    return numero;
}

int tavolo::contaProdotti() const {
    nodo*n = first; double count=0;
    while(n) {count ++; n=n->next;}
    delete n;
    return count;
}

void tavolo::aggiungiProdotto(Prodotto* p) { // aggiunge un prodotto in testa al tavolo
    first = new nodo(p, first);
}

void tavolo::togliProdotto(Prodotto* t) {
	nodo* n = first, *prec = 0;
    while(n && !(*(n->info) == *t)) {
		prec = n;
		n = n -> next;
	} // o non ci sono più n cioè non abbiamo trovato niente con info==t oppure abbiamo trovato il nodo->info==t
	if (!n) return;
    if (*(n->info) == *t) { // abbiamo trovato il nodo
		if (!prec) first = n->next;
		else prec -> next = n -> next;
		delete n;
	}
}

void tavolo::modificaProdotto(Prodotto* vecchio, Prodotto* nuovo) {
    nodo* n = first, *prec = 0;
    while(n && !(n->info == vecchio)) {
        prec = n;
        n = n -> next;
    } // o non ci sono più n cioè non abbiamo trovato niente con info==t oppure abbiamo trovato il nodo->info==t
    if (!n) return;
    if (n->info == vecchio) { // abbiamo trovato il nodo
        if (!prec)  first = new nodo(nuovo, n->next);
        else prec -> next = new nodo(nuovo, n->next);
        delete n;
    }
}

void tavolo::spostaTavolo(const tavolo& p) {
     if(vuoto()) *this = p;
}

void tavolo::unisciTavolo(tavolo& p) {
    if (vuoto() && p.vuoto()) return;
    if (vuoto()) first=p.first;
    if (p.vuoto()) p.first=first;
    //i tavoli sono non vuoti
    //ultimo nodo è una funzione privata
    ultimoNodo()->next = (p.first);
    p.first=first;
}

double tavolo::contoTavolo() const {
    nodo*n = first; double totale=0;
    while(n) {totale += n->info->getPrezzo(); /*qDebug() << n->info->getPrezzo();*/ n=n->next;}
    delete n;
    return totale;
}

double tavolo::chiudiContoTavolo() {
    nodo*n = first; double totale=0;
    while(n) {totale += n->info->getPrezzo(); /*qDebug() << n->info->getPrezzo();*/ n=n->next;}
    delete n;
    delete this;
    return totale;
}

tavolo::nodo* tavolo::copia(nodo* n) {
    if (!n) return 0;
    return new nodo(n->info, copia(n->next));
}

tavolo& tavolo::operator= (tavolo* b) {
    if(this != b) {
        delete(first);
        first = copia(b->first);
    }
    return *this;
}

/*
bool tavolo::operator== (const tavolo& t) {
    return (numero==t.numero && *(first) == *(t.first));
}
*/
ostream& operator<< (ostream& os, tavolo* t_ric) {
    os << endl << "===========================TAVOLO===========================" << endl;
    tavolo::nodo* p = t_ric->first;
    int i = 0;
    while(p) {
           i++;
           os << p->info->getPrezzo() << endl;
           p=p->next;
    }
    return os;
}
