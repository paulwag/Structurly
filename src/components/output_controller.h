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
        timeline *tl_for_gui;                                                           // Timeline, die sich geändert hat, übergeben

        public:
            static output_controller& get_instance();

            void start();
            void stop(bool exit = false);

            void set_tl_for_gui(timeline *tl)                       {tl_for_gui = tl;}
            void set_date_seen_on_gui(int day, int month, int year) {date_seen_on_gui.set_date(day, month, year);}

            void update_gui_new_task();                                                 // nachdem Timeline vom calenderManager übergeben -> gui refresh
            void update_gui_date_changed();                                             // nachdem ein anderes Datum in der gui ausgewaehlt -> gui refresh

            /* Erklaerung:
             * Fall 1:  start()
             *          - output_controller setzt date_seen_on_gui auf heute (im constructor), passiert bei der GUI ja auch
             *          - output_controller holt sich alle daten, die im calenderManager vorhanden sind
             *          - output_controller durchsucht diese timelines und zeigt (irgendwie) den timeline des heutigen tages in der gui an
             * Fall 2:  in der gui wird ein anderer tag ausgewarhlt
             *          - gui setzt date_seen_on_gui auf den entsprechenden tag
             *          - gui ruft update_gui_date_changed auf:
             *              - output_controller holt sich alle daten, die im calenderManager vorhanden sind
             *              - output_controller durchsucht diese timelines und zeigt (irgendwie) den timeline des ausgewählten tages in der gui an
             * Fall 2:  timeline wurde aktualisiert, weil neuer task wird angelegt wurde
             *          - calenderManager setzt tl_for_gui auf die aktualisierte timeline
             *          - calenderManager ruft update_gui_date_changed auf:
             *              - output_controller checkt, ob die aktualisierte timeline gerade überhaupt auf der gui zu sehen ist
             *              - wenn nein -> nichts tun
             *              - wenn ja -> gui aktualisieren
             */
    };

#endif
