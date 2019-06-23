#ifndef CALENDER_MANAGER_H
    #define CALENDER_MANAGER_H

    #include "controller_intf.h"

    using namespace std;



    class calender_manager: public controller_intf
    {
        public:
             calender_manager(string n) : controller_intf(n) {}

            /**
             * @brief start zieht alle Tasks und laedt diese in Timelines
             */
            void start();

            /**
             * @brief stop
             */
            void stop(bool exit = false);

            void updateTimelines();
    };

#endif // CALENDER_MANAGER_H
