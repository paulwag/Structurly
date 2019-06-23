#include <QApplication>
#include "mainwindow.h"
#include "singeltons.h"

mainController mainCntrl("main_controller");
task_manager tm_c = task_manager("task_manager_component");
input_controller ic_c = input_controller("input_controller_component");



int main(int argc, char **argv)
{
    //calender_manager *cm_c = new calender_manager("calender_manager_component");
    //database *db_c = new database("database_component");
    //output_controller *oc_c = new output_controller("output_controller_component");

    //mainCntrl->inject(cm_c);
    //mainCntrl->inject(db_c);
    //mainCntrl->inject(oc_c);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.launch();

    return a.exec();
}


