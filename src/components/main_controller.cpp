#include "main_controller.h"
#include <algorithm>



void mainController::start()
{
    if (getStarted())
            return;

    setStarted(true);

    std::cout << getName() << " gestartet " << endl;

    for(auto component: injected_components)
            component->start();
}



void mainController::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    reverse(injected_components.begin(), injected_components.end());
    for (auto i : injected_components)
        i->stop();

    std::cout << getName() << " beendet \n";
}



void mainController::inject(controller_intf *component)
{
    for (auto i : injected_components)
    {
        if (i == component)
            return;
    }

    injected_components.push_back(component);
}

