#ifndef OUTPUT_CONTROLLER_INTF_H
#define OUTPUT_CONTROLLER_INTF_H

#include "controller_intf.h"

class output_controller_intf : public controller_intf
{
    virtual ~output_controller_intf();

    void start();
    void stop();

    /**
     * @brief updateGUI updated alle GUI Elemente
     */
    virtual void updateGUI() = 0;
};

#endif // OUTPUT_CONTROLLER_INTF_H
