#ifndef V_PRODOTTOVIEW_H
#define V_PRODOTTOVIEW_H
#include "models/m_prodotto.h"
#include<QPushButton>
#include<QGridLayout>

class ProdottoView {
private:
    Prodotto* punt_prod;
    QPushButton prod_button;
public:
    ProdottoView(Prodotto* p, QGridLayout* area);
};

#endif // V_BANCO