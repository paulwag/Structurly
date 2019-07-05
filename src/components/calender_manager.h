#ifndef CALENDER_MANAGER_H
    #define CALENDER_MANAGER_H

    #include <vector>
    #include "controller_intf.h"
    #include "timeline.h"

    using namespace std;

    int calc_id(tdate date);    // Prototyp, wird auch im output_controller benoetigt

    /**
     * @brief The calender_manager class is used to generate the needed Timelines for the GUI
     *        from the loaded Task Vector. It creates the Timelines for every different day that
     *        has Tasks located in the Database. It also updates Timelines if a new Task is
     *        created.
     *
     * authors: Peter Hanne, Dawid Kohl
     * @last update: 04.07.2019
     */

    class calender_manager: public controller_intf
    {
        calender_manager() : calender_manager("calender_manager") {}
        calender_manager(string n) : controller_intf(n) {}

        calender_manager(const calender_manager& orig) = delete;
        const calender_manager& operator= (const calender_manager& orig) = delete;

        static calender_manager cm_instance;

        vector<timeline *> timelines;


        public:
            static calender_manager& get_instance();

            void start();
            void stop(bool exit = false);

            vector<timeline *> get_timelines() const {return timelines;}

            void updateTimelines(task *new_task);

            //WIP Stuff for deleted Tasks
            void deleteTaskFromTL(task *removed_task);
    };

#endif
