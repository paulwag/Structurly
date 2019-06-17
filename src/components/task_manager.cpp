#include "task_manager.h"

void task_manager::start()
{
    std::cout << getName() << " gestartet \n";
}

void task_manager::stop(bool exit)
{
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}
