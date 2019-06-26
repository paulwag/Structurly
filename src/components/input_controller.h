#ifndef INPUT_CONTROLLER_H
    #define INPUT_CONTROLLER_H

    #include "controller_intf.h"
    #include <string>

    using namespace std;

    #define BUT_CREATE  0
    #define BUT_PRINT   1



    class input_controller: public controller_intf
    {
        string task_title;
        string task_description;

        public:
             input_controller(string n)
             : controller_intf(n), task_title(""), task_description("") {}

            void start();
            void stop(bool exit = false);

            void set_task_parameter(string t, string d);
            void button_pressed(int button);
    };

#endif
