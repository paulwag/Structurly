#ifndef INPUT_CONTROLLER_H
    #define INPUT_CONTROLLER_H

    #include "controller_intf.h"

    using namespace std;



    class input_controller: public controller_intf
    {
        public:
             input_controller(string n) : controller_intf(n) {}

            /**
             * @brief start zieht alle Tasks und laedt diese in Timelines
             */
            void start();

            /**
             * @brief stop
             */
            void stop(bool exit = false);

            void buttonPressed();
    };

#endif // INPUT_CONTROLLER_H
