TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



INCLUDEPATH += \
    src \
    src/components
    
SOURCES += \
    src/main.cpp

HEADERS += \
    src/components/database.h \
    src/components/datastructure.h
