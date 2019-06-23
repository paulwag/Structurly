#include <iostream>
#include <QApplication>
#include "mainwindow.h"
#include "main_controller.h"

#include "calender_manager.h"
#include "database.h"
#include "input_controller.h"
#include "output_controller.h"
#include "task_manager.h"



int main(int argc, char **argv)
{
    mainController *mainCntrl = new mainController("main_controller");

    calender_manager *cm_c = new calender_manager("calender_manager_component");
    database *db_c = new database("database_component");
    input_controller *ic_c = new input_controller("input_controller_component");
    output_controller *oc_c = new output_controller("output_controller_component");
    task_manager *tm_c = new task_manager("task_manager_component");

    mainCntrl->inject(cm_c);
    mainCntrl->inject(db_c);
    mainCntrl->inject(ic_c);
    mainCntrl->inject(oc_c);
    mainCntrl->inject(tm_c);

    mainCntrl->start();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    mainCntrl->stop();

    return a.exec();
}


