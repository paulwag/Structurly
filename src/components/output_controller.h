#ifndef OUTPUT_CONTROLLER_H
    #define OUTPUT_CONTROLLER_H

    #include "controller_intf.h"

    using namespace std;



    class output_controller:public controller_intf
    {
        public:
             output_controller(string n) : controller_intf(n) {}

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
