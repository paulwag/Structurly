#include "task_manager.h"

void task_manager::start()
{
    if(getStarted())
        return;

    started(); // started = true, stopped = false

    std::cout << getName() << " gestartet \n";
}

void task_manager::stop(bool exit)
{
    if(getStopped())
        return;

    stopped(); // started = false, stopped = true

    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void task_manager::createTask() {}
void task_manager::delTask() {}
void task_manager::updateTask() {}
