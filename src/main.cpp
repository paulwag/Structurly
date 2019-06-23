#include <QApplication>
#include "mainwindow.h"
#include "singeltons.h"

mainController mainCntrl("main_controller");
calender_manager cm_c = calender_manager("calender_manager_component");
database db_c = database("database_component");
input_controller ic_c = input_controller("input_controller_component");
output_controller oc_c = output_controller("output_controller_component");
task_manager tm_c = task_manager("task_manager_component");



int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.launch();

    return a.exec();
}


