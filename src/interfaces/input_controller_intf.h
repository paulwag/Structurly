#ifndef INPUT_CONTROLLER_INTF_H
    #define INPUT_CONTROLLER_INTF_H

    #include "controller_intf.h"

    using namespace std;



    class input_controller_intf : public controller_intf
    {
    public:
         input_controller_intf(string name) : controller_intf(name) {}
         ~input_controller_intf() {}

        virtual int set_task_parameter(string title, string decription, int hour, int minute, int day, int month, int year) = 0;
        virtual void button_pressed(int button) = 0;
    };

#endif
