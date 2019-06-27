#include <QApplication>
#include "mainwindow.h"
#include "singletons.h"

mainController mainCntrl("main_controller");                                    // Muss noch zum Singleton werden!!!
calender_manager cm_c = calender_manager("calender_manager_component");         // Muss noch zum Singleton werden!!!
database db_c = database("database_component");                                 // Muss noch zum Singleton werden!!!
input_controller& ic_c = input_controller::get_instance();
output_controller& oc_c = output_controller::get_instance();
task_manager tm_c = task_manager("task_manager_component");                     // Muss noch zum Singleton werden!!!



int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.launch();

    return a.exec();
}


