#include "input_controller.h"



void input_controller::start()
{
    if (getStarted())
        return;

    setStarted(true);

    std::cout << getName() << " gestartet" << endl;
}



void input_controller::stop(bool exit)
{
    if (!getStarted())
        return;

    setStarted(false);

    std::cout << getName() << " beendet" << endl;
}



void input_controller::buttonPressed()
{

}
