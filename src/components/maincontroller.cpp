#include "maincontroller.h"

void mainController::start()
{
    std::cout << getName() << " gestartet \n";


}

void mainController::stop(bool exit)
{
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}


void mainController::inject(controller_intf& controller)
{
    componentList.push_back(controller);
}

