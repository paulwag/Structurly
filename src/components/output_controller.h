#ifndef OUTPUT_CONTROLLER_H
    #define OUTPUT_CONTROLLER_H

    #include "controller_intf.h"
    #include "tdate.h"
    #include "timeline.h"

    using namespace std;



    class output_controller: public controller_intf
    {
        output_controller() : output_controller("output_controller") {}
        output_controller(string n)
        : controller_intf(n), date_seen_on_gui(), tl_for_gui(nullptr) {}

        output_controller(const output_controller& orig) = delete;
        const output_controller& operator= (const output_controller& orig) = delete;

        static output_controller oc_instance;

        tdate date_seen_on_gui;                                                         // Tag, der gerade auf der GUI zu sehen ist
        timeline *tl_for_gui;                                                        // Timeline, die sich geändert hat, übergeben

        public:
            static output_controller& get_instance();

            void start();
            void stop(bool exit = false);

            void set_tl_for_gui(timeline *tl)                    {tl_for_gui = tl;}
            void set_date_seen_on_gui(int day, int month, int year) {date_seen_on_gui.set_date(day, month, year);}

            void update_gui_new_task();                                                 // nachdem Timeline vom calenderManager übergeben -> gui refresh
            void update_gui_date_changed();                                             // nachdem ein anderes Datum in der gui ausgewöhlt -> gui refresh
    };

#endif
