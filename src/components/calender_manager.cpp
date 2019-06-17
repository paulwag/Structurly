#include "calender_manager.h"

void calender_manager::start()
{
    std::cout << getName() << " gestartet \n";
}

void calender_manager::stop(bool exit)
{
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void calender_manager::updateTimelines() {}
