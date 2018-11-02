#ifndef TAVOLO
#define TAVOLO_H
#include "models/m_prodotto.h"

class tavolo {
    friend class iteratore; // tavolo userà la parte privata di iteratore
private:
    class nodo {
    public:
        nodo();
        ~nodo();
        nodo(Prodotto*, nodo*);
        Prodotto* info;
        nodo* next;
        bool operator== (const nodo& n);
    };
    int numero;
    nodo* first;
    static nodo* copia(nodo*);
    nodo* ultimoNodo() const;
public:
    class iteratore {
    friend class tavolo; // iteratore userà òa parte privata di bolletta
    private:
           tavolo::nodo* punt;
    public:
           bool operator==(iteratore) const;
           bool operator!=(iteratore) const;
           iteratore& operator++(); // operatore ++ prefisso
           iteratore  operator++(int); // operatore ++ postfisso
    };
    iteratore begin() const;
    iteratore end() const;
    Prodotto* operator[](iteratore) const;
    tavolo();
    tavolo(int n, nodo* f=0);
    tavolo(tavolo*);//costruttore di copia PROFOND // serve??
    ~tavolo();
    bool operator== (const tavolo& t);
    bool operator!= (const tavolo& t);
    bool vuoto() const;
    int getNumero() const;
    int contaProdotti() const;
    void aggiungiProdotto(Prodotto* t);
    void togliProdotto(Prodotto* t);
    void modificaProdotto(Prodotto*, Prodotto*);
    void spostaTavolo(const tavolo& t);
    void unisciTavolo(tavolo& t);
    double contoTavolo() const;
    double chiudiContoTavolo();
    tavolo& operator= (tavolo*);
    void stampaTavolo(int) const;
    friend ostream& operator<< (ostream& os, tavolo*);
};

#endif