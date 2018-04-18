TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += main.cpp

CONFIG += c++11

HEADERS += \
    ed_base.h \
    ed_mat.h

DISTFILES += \
    ed_font.ttf


