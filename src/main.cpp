#include <iostream>
#include <cstdlib>

#include "maincontroller.h"
#include "database.h"
#include "task_manager.h"
#include "calender_manager.h"
#include "input_controller.h"
#include "output_controller.h"

using namespace std;

int main()
{
    cout << "Application started." << endl;
    //QCoreApplication a();

//    mainController.start();
    mainController& main = *new mainController("mainController");
    database& db = *new database( "Component_Database" );
    task_manager& task_man_ref = *new task_manager( "Component_TaskManager" );
    calender_manager& cal_man_ref = *new calender_manager( "Component_Calender_Manager" );
    input_controller& input_ref = *new input_controller( "Component_Input_Controller" );
    output_controller& output_ref = *new output_controller( "Component_Output_Controller" );

    main.inject( db );
    main.inject( task_man_ref );
    main.inject( cal_man_ref );
    main.inject( input_ref );
    main.inject( output_ref );

    main.start();
    main.stop();

    //return a.exec;
    return 0;
}
