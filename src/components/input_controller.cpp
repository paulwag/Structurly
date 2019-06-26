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
    cout << "parameter werden gesetzt..." << endl;
    task_title = t;
    task_description = d;
}



void input_controller::button_pressed(int button)
{
    cout << "IC: Button pressed..." << endl;
    switch(button)
    {
        case BUT_CREATE:    cout << "...Task anlegen" << endl;      break;
        case BUT_PRINT:     cout << "...print Tasks" << endl;    break;
    }
    //Ui::MainWindow().task_name_edit->setText("asdf");
    //tm_c.createTask();
}
