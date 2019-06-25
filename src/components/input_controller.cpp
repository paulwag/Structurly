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



void input_controller::buttonPressed(string title)
{
    cout << "IC: Button pressed..." << endl;
    //Ui::MainWindow().task_name_edit->setText("asdf");
    cout << "Task name " << title << endl;
    tm_c.createTask();
}
