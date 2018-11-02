#-------------------------------------------------
#
# Project created by QtCreator 2016-02-20T15:50:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QuorDiPizza20
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp\
        models/m_prodotto.cpp\
        models/m_tavolo.cpp\
        v_listino_container.cpp\
        views/v_prodotto_view.cpp\
        views/v_start.cpp

HEADERS  += mainwindow.h\
        models/m_prodotto.h\
        models/m_tavolo.h\
        v_listino_container.h\
        views/v_prodotto_view.h\
        views/v_start.h
