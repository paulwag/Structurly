#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task_manager_intf.h"

class task_manager : public task_manager_intf
{
public:
     task_manager(std::string name) : task_manager_intf(name) {}
     ~task_manager(){}

    /**
     * @brief start liest bei Start alle Daten aus der Datenbank aus
     */
    void start();

    /**
     * @brief stop speichert alle Daten bei Programmende
     */
    void stop(bool exit = false);

    void createTask();
    void delTask();
    void updateTask();
};

#endif // TASK_MANAGER_H
