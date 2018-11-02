#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <views/v_start.h>

class ListinoContainer;
class MainWindow : public QMainWindow {
    friend class ListinoContainer;
private:
    Q_OBJECT
    v_start* view_principale;
    ListinoContainer* listino;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H