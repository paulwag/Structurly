#include "main_controller.h"
#include <algorithm>



main_controller main_controller::mc_instance;
main_controller& main_controller::get_instance()
{
    return mc_instance;
}



void main_controller::start()
{
    if (getStarted())
            return;

    setStarted(true);

    std::cout << getName() << " gestartet " << endl;

    for(auto component: injected_components)
            component->start();
}



void main_controller::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    reverse(injected_components.begin(), injected_components.end());
    for (auto i : injected_components)
        i->stop();

    std::cout << getName() << " beendet \n";
}



void main_controller::inject(controller_intf *component)
{
    for (auto i : injected_components)
    {
        if (i == component)
            return;
    }

    injected_components.push_back(component);
}

