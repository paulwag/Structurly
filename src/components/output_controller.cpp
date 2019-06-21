#include "output_controller.h"

void output_controller::start()
{
    if(getStarted())
        return;

    started(); // started = true, stopped = false

    std::cout << getName() << " gestartet \n";
}

void output_controller::stop(bool exit)
{
    if(getStopped())
        return;

    stopped(); // started = false, stopped = true

    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void output_controller::updateGUI() {}
