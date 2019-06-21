#include "input_controller.h"

void input_controller::start()
{
    if(getStarted())
        return;

    started(); // started = true, stopped = false

    std::cout << getName() << " gestartet \n";
}

void input_controller::stop(bool exit)
{
    if(getStopped())
        return;

    stopped(); // started = false, stopped = true

    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void input_controller::buttonPressed() {}
