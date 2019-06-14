#ifndef CALENDER_MANAGER_INTF_H
#define CALENDER_MANAGER_INTF_H

#include "controller_intf.h"

class calender_manager_intf : controller_intf
{
    virtual ~calender_manager_intf();

    /**
     * @brief start zieht alle Tasks und laedt diese in Timelines
     */
    void start();
    void stop();

    /**
     * @brief updateTimelines zieht neue Daten für Update der Timelines
     */
    virtual void updateTimelines() = 0;
};

#endif // CALENDER_MANAGER_INTF_H
