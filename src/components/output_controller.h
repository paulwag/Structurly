#ifndef OUTPUT_CONTROLLER_H
#define OUTPUT_CONTROLLER_H

#include "output_controller_intf.h"

class output_controller : public output_controller_intf
{
    ~output_controller();

    /**
     * @brief start zieht alle Tasks und laedt diese in Timelines
     */
    void start();

    /**
     * @brief stop
     */
    void stop(bool exit = false);
};

#endif // OUTPUT_CONTROLLER_H
