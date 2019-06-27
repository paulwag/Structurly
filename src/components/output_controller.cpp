#include <iostream>
#include "singletons.h"

using namespace std;



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
void output_controller::updateGUI() {}
