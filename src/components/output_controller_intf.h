#ifndef OUTPUT_CONTROLLER_INTF_H
#define OUTPUT_CONTROLLER_INTF_H

#include "controller_intf.h"

class output_controller_intf : public controller_intf
{
public:
     output_controller_intf(std::string name) : controller_intf(name) {}
     ~output_controller_intf(){}

    /**
     * @brief updateGUI updated alle GUI Elemente
     */
    virtual void updateGUI() = 0;
};

#endif // OUTPUT_CONTROLLER_INTF_H
