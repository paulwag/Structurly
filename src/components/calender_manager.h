#ifndef CALENDER_MANAGER_H
    #define CALENDER_MANAGER_H

    #include <vector>
    #include "controller_intf.h"
    #include "timeline.h"

    using namespace std;



    class calender_manager: public controller_intf
    {
        calender_manager() : calender_manager("calender_manager") {}                // Singleton Stuff
        calender_manager(string n) : controller_intf(n) {}

        calender_manager(const calender_manager& orig) = delete;                    // Singleton: disable copy constructor
        const calender_manager& operator= (const calender_manager& orig) = delete;  // Singleton: disable " operator

        static calender_manager cm_instance;

        vector<timeline *> timelines;


        public:
            static calender_manager& get_instance();

            /**
             * @brief start zieht alle Tasks und laedt diese in Timelines
             */
            void start();

            /**
             * @brief stop gibt Timelines frei.
             */
            void stop(bool exit = false);

            void updateTimelines();
    };

#endif
