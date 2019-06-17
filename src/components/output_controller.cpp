#include "output_controller.h"

void output_controller::start()
{
    std::cout << getName() << " gestartet \n";
}

void output_controller::stop(bool exit)
{
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void output_controller::updateGUI() {}
