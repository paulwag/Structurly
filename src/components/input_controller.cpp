#include <iostream>
#include "input_controller.h"
#include "singletons.h"

using namespace std;



void input_controller::start()
{
    if (getStarted())
        return;

    setStarted(true);

    cout << getName() << " gestartet" << endl;
}



void input_controller::stop(bool exit)
{
    if (!getStarted())
        return;

    setStarted(false);

    cout << getName() << " beendet" << endl;
}



void input_controller::set_task_parameter(string t, string d)
{
    task_title = t;
    task_description = d;
}



void input_controller::button_pressed(int button)
{
    switch(button)
    {
        case BUT_CREATE:    tm_c.createTask(task_title, task_description);  break;
        case BUT_PRINT:     tm_c.printTasks();                              break;
    }
}
