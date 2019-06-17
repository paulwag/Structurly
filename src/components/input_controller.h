#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include "input_controller_intf.h"

class input_controller: public input_controller_intf {

    ~input_controller();

    /**
     * @brief start zieht alle Tasks und laedt diese in Timelines
     */
    void start();

    /**
     * @brief stop
     */
    void stop(bool exit = false);
};

#endif // INPUT_CONTROLLER_H
