#include <QApplication>
#include "mainwindow.h"
#include "singletons.h"

mainController mainCntrl("main_controller");                        // Muss noch zum Singleton werden!!!
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


