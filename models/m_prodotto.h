#ifndef M_PRODOTTO_H
#define M_PRODOTTO_H
#include <QStringList>
#include <QString>
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

class Prodotto {
private:
    QString descrizione;
    double prezzo;
public:
    virtual ~Prodotto();
    Prodotto(const QString& d, double p);
    virtual double getPrezzo() const;
    QString getDescrizione() const;
    virtual bool operator== (const Prodotto& p);
    friend ostream& operator<< (ostream& os, const Prodotto& p);
};

class Banco : public Prodotto {
private:
    QString categoria;
public:
    ~Banco() {};
    bool operator== (const Banco& b);
    QString getCategoria() const;
    Banco(const QString& descr, double pr, const QString& cat);
};

class Pizza : public Prodotto {
private:
    QStringList ingredienti;
    static double coperto; // =1,50
public:
    ~Pizza() {};
    double getPrezzo() const;
    QStringList getIngredienti() const;
    Pizza(const QString& descr, const QStringList& ingr);
    bool operator== (const Pizza& b);
};
#endif
