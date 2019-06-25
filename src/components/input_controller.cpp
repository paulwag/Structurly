#include <iostream>
#include "input_controller.h"
#include "singletons.h"



void input_controller::start()
{
    if (getStarted())
        return;

    setStarted(true);

    std::cout << getName() << " gestartet" << endl;
}



void input_controller::stop(bool exit)
{
    if (!getStarted())
        return;

    setStarted(false);

    std::cout << getName() << " beendet" << endl;
}



void input_controller::buttonPressed()
{
    cout << "IC: Button pressed..." << endl;
    tm_c.createTask();
}
