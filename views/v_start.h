#ifndef VISUAL_TAVOLO
#define VISUAL_TAVOLO
#include <QWidget>
#include <QPushButton>
#include <QTabWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>

class v_start : public QWidget {
    //Q_OBJECT
private:
    QLabel* label;
    QTableWidget* table_ordini;
    //AreaCucina* area_cucina;
    QPushButton* quit;
    QPushButton* elimina;
    QPushButton* modifica;
    QPushButton* unisci;
    QPushButton* separa;
    QPushButton* totale;
    QPushButton* chiudi_conto;
    QStringList* intestaz_col;
    QVBoxLayout* layout_est;
    QHBoxLayout* layout;
    QVBoxLayout* layout_int;
public:
    QTabWidget* tab_reparto;
    QWidget* area_banco;
    QWidget* area_pizzeria;
    v_start(QWidget* parent =0);
};

#endif