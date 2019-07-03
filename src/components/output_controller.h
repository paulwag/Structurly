#ifndef OUTPUT_CONTROLLER_H
    #define OUTPUT_CONTROLLER_H

    #include "controller_intf.h"
    #include "tdate.h"
    #include "timeline.h"
    #include "mainwindow.h"

    using namespace std;

    enum changeStates { no_changes, new_timeline };               // possible states of change



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
        //changeStates changeFlag = no_changes;                              // change Flag

        public:
            static output_controller& get_instance();

            void start();
            void stop(bool exit = false);

            void set_date_seen_on_gui(int day, int month, int year) {date_seen_on_gui.set_date(day, month, year);}
            void set_tl_for_gui(timeline *tl)                       {tl_for_gui = tl;}

            timeline *get_timeline_for_gui() const {return tl_for_gui;}

            //changeStates getChangeFlag() { return changeFlag; }
            //void setChangeFlag(changeStates new_state) { changeFlag = new_state; }

            void update_gui_new_task();                                                 // nachdem Timeline vom calenderManager übergeben -> gui refresh
            int update_gui_date_changed();                                             // nachdem ein anderes Datum in der gui ausgewaehlt -> gui refresh

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
             * Fall 3:  timeline wurde aktualisiert, weil neuer task wird angelegt wurde
             *          - calenderManager setzt tl_for_gui auf die aktualisierte timeline
             *          - calenderManager ruft update_gui_date_changed auf:
             *              - output_controller checkt, ob die aktualisierte timeline gerade überhaupt auf der gui zu sehen ist
             *              - wenn nein -> nichts tun
             *              - wenn ja -> gui aktualisieren
             * ------------------------------------------
             *  Erweiterung für meine Changes
             * Überlegung: OC bekommt keinen direkten Zugriff auf UI - übersetzt aber die Daten des Models für GUI (z.B. bei Timeline durch Aufbau in Array für GUI Zuordnung)
             * Lösung: UI hat timer mit 0.5s Interval - dann checkForUpdate slot das Flag hier checkt. (oben als enum für verschiedene Fälle die später bei UI Update passieren können)
             * Umsetzung:
             *  1. wenn sich etwas verändert (Task wird erstellt und in Timeline eingefügt, andere Timeline wird ausgewählt, ...) wird Flag hier gesetzt
             *  2. UI erkennt mit checkForUpdate gesetztes Flag und ruft entsprechende Funktion auf (z.b. timelineChanged)
             *        2. a) timelineChanged ruft oc_c.update_gui_date_changed und erhält ein entsprechendes Array für tag zurück
             *        2. b) timelineChanged updated mit dem Array die ui timeline
             *  3. UI ruft setChangeFlag auf und setzt es auf no_changes
             */
    };

#endif
