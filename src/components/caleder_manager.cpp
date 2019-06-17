#include "calender_manager.h"

void calender_manager::start()
{
    std::cout << getName() << " gestartet \n";
}

void database::stop(bool exit)
{
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}
