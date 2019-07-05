#include <QApplication>
#include "mainwindow.h"
#include "singletons.h"

main_controller& mc_c = main_controller::get_instance();
calender_manager& cm_c = calender_manager::get_instance();
database& db_c = database::get_instance();
input_controller& ic_c = input_controller::get_instance();
output_controller& oc_c = output_controller::get_instance();
task_manager& tm_c = task_manager::get_instance();



int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    w.launch();

    return a.exec();
}


