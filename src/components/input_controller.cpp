#include "input_controller.h"

void input_controller::start()
{
    std::cout << getName() << " gestartet \n";
}

void input_controller::stop(bool exit)
{
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}
