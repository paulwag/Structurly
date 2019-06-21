#include "maincontroller.h"
#include <algorithm>    //reverse

void mainController::start()
{
    if(getStarted())
        return;

    started(); // started = true, stopped = false

    std::cout << getName() << " gestartet \n";
    for(auto *component: componentList)
            component->start();

}

void mainController::stop(bool exit)
{
    if(getStopped())
        return;

    stopped(); // started = false, stopped = true

    std::reverse(componentList.begin(),componentList.end());

    for(auto *component: componentList)
            component->stop();

    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}


void mainController::inject(controller_intf& controller)
{
    componentList.push_back(&controller);
}

