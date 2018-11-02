#include "mainwindow.h"
#include <v_listino_container.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), view_principale(new v_start()),
      listino(new ListinoContainer(view_principale->area_banco, view_principale->area_pizzeria)) {}

MainWindow::~MainWindow()
{

}
