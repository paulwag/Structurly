#include <iostream>
#include "singletons.h"

using namespace std;

int calc_id(tdate date);



// /////////////////////////////////////////////////////////////////////////// Singleton Stuff
output_controller output_controller::oc_instance;
output_controller& output_controller::get_instance()
{
    return oc_instance;
}


// /////////////////////////////////////////////////////////////////////////// Start | Stop
void output_controller::start()
{
    if (getStarted())
        return;

    setStarted(true);

    update_gui_date_changed();
    cout << getName() << " gestartet" << endl;
}

void output_controller::stop(bool exit)
{
    if (!getStarted())
        return;

    setStarted(false);

    cout << getName() << " beendet" << endl;
}


// /////////////////////////////////////////////////////////////////////////// Methods
void output_controller::update_gui_new_task()
{
    int id_seen_on_gui = calc_id(date_seen_on_gui);

    if (id_seen_on_gui == tl_for_gui->get_id())
    {
        // irgendwie an die elemente der GUI kommen und Daten übergeben
    }
}
void output_controller::update_gui_date_changed()
{
    int today_id = calc_id(date_seen_on_gui);                                       // id vom in der gui angezeigten tag berechnen
    cout << "OC: neue ID von gui: " << today_id << endl;

    //vector<timeline *> timelines_from_calender_manager = cm_c.get_timelines();    // alle vorhandenen Timelines laden

    //for (auto tl: timelines_from_calender_manager)                                // timeleines durchgehen und schauen, ob es für den tag eine gibt
    //{
    //    if (tl->get_id() == today_id)                                             // wenn ja -> zum updaten vormerken...
    //    {
    //        tl_for_update = tl;
    //        break;
    //    }
    //}

    // irgendwie an die elemente der GUI kommen und Daten übergeben
}
