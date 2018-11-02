#include <QVector>
#include "views/v_prodotto_view.h"
#include "models/m_prodotto.h"
#include <QFile>
#include <QTextStream>
#include <mainwindow.h>

class ListinoContainer {
private:
    QVector<Prodotto*> listino;
public:
    ListinoContainer();
    int load();
};