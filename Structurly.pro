TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



INCLUDEPATH += \
    src \
    src/components \
    src/datatypes
    
SOURCES += \
    src/main.cpp \
    src/tools.cpp \
    src/components/database.cpp \
    src/datatypes/tdate.cpp \
    src/datatypes/ttime.cpp

HEADERS += \
    scr/tool.h \
    src/components/database.h \
    src/components/inputController.h \
    src/datatypes/datastructure.h \
    src/datatypes/tdate.h \
    src/datatypes/ttime.h
