#ifndef CALENDER_MANAGER_H
#define CALENDER_MANAGER_H

#include "calender_manager_intf.h"

class calender_manager : public calender_manager_intf
{
     ~calender_manager();

    /**
     * @brief start zieht alle Tasks und laedt diese in Timelines
     */
    void start();

    /**
     * @brief stop
     */
    void stop(bool exit = false);

};

#endif // CALENDER_MANAGER_H
