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
    src/components/calender_manager_intf.h \
    src/components/controller_intf.h \
    src/components/database.h \
    src/components/database_intf.h \
    src/components/input_controller_intf.h \
    src/components/output_controller_intf.h \
    src/components/task_manager_intf.h \
    src/datatypes/datastructure.h \
    src/datatypes/tdate.h \
    src/datatypes/ttime.h
