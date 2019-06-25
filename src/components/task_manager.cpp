#include <iostream>
#include "task_manager.h"



void task_manager::start()
{
    if (getStarted())
            return;

    setStarted(true);

    std::cout << getName() << " gestartet" << endl;
}



void task_manager::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    std::cout << getName() << " beendet" << endl;
}



void task_manager::createTask()
{
    cout << "TM: Task wird erstellt..." << endl;
}



void task_manager::delTask() {}
void task_manager::updateTask() {}
