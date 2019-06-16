TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



INCLUDEPATH += \
    src \
    src/components \
    src/datamodel
    
SOURCES += \
    src/main.cpp \
    src/components/database.cpp \
    src/datamodel/tdate.cpp \
    src/datamodel/ttime.cpp

HEADERS += \
    src/components/calender_manager_intf.h \
    src/components/controller_intf.h \
    src/components/database.h \
    src/components/database_intf.h \
    src/components/input_controller_intf.h \
    src/components/output_controller_intf.h \
    src/components/task_manager_intf.h \
    src/datamodel/datastructure.h \
    src/datamodel/tdate.h \
    src/datamodel/ttime.h
