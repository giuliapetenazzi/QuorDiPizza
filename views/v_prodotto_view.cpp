#include "views/v_prodotto_view.h"

ProdottoView::ProdottoView(Prodotto* p, QGridLayout* area)
    :punt_prod(p), prod_button(new QPushButton(p->getDescrizione(), area))
    //{prod_button.setGeometry();}
    {}