#ifndef CALENDER_MANAGER_INTF_H
#define CALENDER_MANAGER_INTF_H

#include "controller_intf.h"

class calender_manager_intf : public controller_intf
{
public:
     calender_manager_intf(std::string name) : controller_intf(name) {}
     virtual ~calender_manager_intf(){}

    /**
     * @brief updateTimelines zieht neue Daten für Update der Timelines
     */
    virtual void updateTimelines() = 0;
};

#endif // CALENDER_MANAGER_INTF_H
