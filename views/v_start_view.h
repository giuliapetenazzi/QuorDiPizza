#ifndef LISTINO_H
#define LISTINO_H
#include <QObject>
#include <QString>
#include <QTableWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QToolBar>

class ListinoWindow : public QMainWindow {
    Q_OBJECT
private:
    QPushButton* dettagli;
    QPushButton* elimina;
    QPushButton* inserisci;
    QStringList* intestaz_col;
    QTableWidget* tabella_listino;
    QToolBar* toolbar;
    ControllerListino* controller;
signals:
    bool clicked();
    //bool QTableWidget::cellClicked(int, int);
public:
    ListinoWindow(QMainWindow* parent=0);
    QTableWidget* centralWidget();
public slots:
    void abilitaDettagli ();
    void abilitaElimina ();
    //void slotELimina ();
};

#endif // LISTINO_H

