#include "calender_manager.h"

void calender_manager::start()
{
    if(getStarted())
        return;

    started(); // started = true, stopped = false

    std::cout << getName() << " gestartet \n";
}

void calender_manager::stop(bool exit)
{
    if(getStopped())
        return;

    stopped(); // started = false, stopped = true

    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void calender_manager::updateTimelines() {}
