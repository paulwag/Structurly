#ifndef INPUT_CONTROLLER_H
    #define INPUT_CONTROLLER_H

    #include "controller_intf.h"

    using namespace std;



    class input_controller: public controller_intf
    {
        public:
             input_controller(string n) : controller_intf(n) {}

            void start();
            void stop(bool exit = false);

            void buttonPressed(string titel);
    };

#endif // INPUT_CONTROLLER_H
