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
    src/datamodel/tdate.cpp \
    src/datamodel/ttime.cpp \
    src/components/database_old.cpp \
    src/components/database.cpp \
    src/components/input_controller.cpp \
    src/components/output_controller.cpp \
    src/components/task_manager.cpp \
    src/components/maincontroller.cpp \
    src/components/calender_manager.cpp \
    src/datamodel/task.cpp \
    src/datamodel/timeline.cpp

HEADERS += \
    src/components/calender_manager_intf.h \
    src/components/controller_intf.h \
    src/components/database_intf.h \
    src/components/input_controller_intf.h \
    src/components/output_controller_intf.h \
    src/components/task_manager_intf.h \
    src/datamodel/tdate.h \
    src/datamodel/ttime.h \
    src/components/calender_manager.h \
    src/components/input_controller.h \
    src/components/output_controller.h \
    src/components/task_manager.h \
    src/components/database_old.h \
    src/components/database.h \
    src/components/maincontroller.h \
    src/datamodel/task.h \
    src/datamodel/timeline.h
