#ifndef TASK_MANAGER_INTF_H
#define TASK_MANAGER_INTF_H

#include "controller_intf.h"

class task_manager_intf : public controller_intf
{
    virtual ~task_manager_intf();

    /**
     * @brief taskAnlegen Task Objekt erstellen und speichern und gibt Veränderung an CalenderManager weiter
     */
    virtual void createTask() = 0;

    /**
     * @brief updateTask Task Objekt updaten und speichern und gibt Veränderung an CalenderManager weiter
     */
    virtual void updateTask() = 0;

    /**
     * @brief delTask Task Objekt löschen und Datenbank aktualisieren und gibt Veränderung an CalenderManager weiter
     */
    virtual void delTask() = 0;
};

#endif // TASK_MANAGER_INTF_H
