#include "maincontroller.h"
#include <algorithm>    //reverse

void mainController::start()
{
    std::cout << getName() << " gestartet \n";
    for(auto *component: componentList)
            component->start();

}

void mainController::stop(bool exit)
{
    std::cout << getName() << " beendet \n";
    std::reverse(componentList.begin(),componentList.end());

    for(auto *component: componentList)
            component->stop();

    if (exit)
        std::cout << "exit is true \n";
}


void mainController::inject(controller_intf& controller)
{
    componentList.push_back(&controller);
}

