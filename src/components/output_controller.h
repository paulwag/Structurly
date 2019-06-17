#ifndef OUTPUT_CONTROLLER_H
#define OUTPUT_CONTROLLER_H

#include "output_controller_intf.h"

class output_controller : public output_controller_intf
{
public:
     output_controller(std::string name) : output_controller_intf(name) {}
     ~output_controller(){}

     /**
      * @brief start zieht alle Tasks und laedt diese in Timelines
      */
     void start();

    /**
     * @brief stop
     */
    void stop(bool exit = false);

    void updateGUI();

};

#endif // OUTPUT_CONTROLLER_H
