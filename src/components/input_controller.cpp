#include <iostream>
#include "singletons.h"

using namespace std;

int check_task_parameter(string title, string description);



// /////////////////////////////////////////////////////////////////////////// important singleton stuff
input_controller input_controller::ic_instance;
input_controller& input_controller::get_instance()
{
    return ic_instance;
}


// /////////////////////////////////////////////////////////////////////////// Start | Stop
void input_controller::start()
{
    if (getStarted())                                                       // Dont start again, if already running
        return;

    setStarted(true);

    cout << getName() << " gestartet" << endl;                              // Information in Terminal
}

void input_controller::stop(bool exit)
{
    if (!getStarted())                                                      // Dont stop again, if not running
        return;

    setStarted(false);

    cout << getName() << " beendet" << endl;                                // Information in Terminal
}


// /////////////////////////////////////////////////////////////////////////// Methods
int input_controller::set_task_parameter(string title, string description, int hour, int minute, int day, int month, int year)
{
    int minute_to_set;

    if (check_task_parameter(title, description))                           // check important parameters
        return -1;

    if (minute < 15)                                                        // setting minute to 0 | 15 | 30 | 45. important for timeline
        minute_to_set = 0;
    else if (minute < 30)
        minute_to_set = 15;
    else if (minute < 45)
        minute_to_set = 30;
    else
        minute_to_set = 45;

    task_title = title;                                                     // set task info buffer
    task_description = description;
    task_date.set_date(day, month, year);
    task_time.set_time(hour, minute_to_set);

    return 0;
}

void input_controller::button_pressed(int button)
{
    switch(button)
    {
        case BUT_CREATE:    tm_c.createTask(task_title, task_description, task_date, task_time);
                            break;
        case BUT_PRINT:     tm_c.printTasks();
                            break;
    }
}


// /////////////////////////////////////////////////////////////////////////// Functions
int check_task_parameter(string title, string description)
{
    int err = 0;

    if (title == "")                                                        // error, if so titel is set
    {
        cout << "title input error" << endl;
        err = -1;
    }

    return err;
}
