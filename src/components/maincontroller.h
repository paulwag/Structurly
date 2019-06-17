#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <vector>
#include "controller_intf.h"

class mainController: public controller_intf
{
public:

    mainController(std::string name) : controller_intf(name) {}
    virtual ~mainController() {}

    void start();
    void stop(bool exit = false);

    /**
     * @brief inject
     * @param controller
     */
    void inject(controller_intf& controller);

private:
    std::vector <controller_intf *> componentList = {};
    enum OpState { init, startet, stopped };
    OpState opstate = OpState::init;

};


//extern mainController& mainController;

#endif // MAINCONTROLLER_H
