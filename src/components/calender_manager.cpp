#include "calender_manager.h"


// /////////////////////////////////////////////////////////////////////////// Singleton Stuff
calender_manager calender_manager::cm_instance;
calender_manager& calender_manager::get_instance()
{
    return cm_instance;
}
// ///////////////////////////////////////////////////////////////////////////


void calender_manager::start()
{
    if (getStarted())
            return;

    setStarted(true);

    std::cout << getName() << " gestartet" << endl;
}



void calender_manager::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    std::cout << getName() << " beendet" << endl;
}

void calender_manager::updateTimelines()
{

}
