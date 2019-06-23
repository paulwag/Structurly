#ifndef MAIN_CONTROLLER_H
    #define MAIN_CONTROLLER_H

    #include <vector>
    #include "controller_intf.h"

    using namespace std;


    class mainController: public controller_intf
    {
        vector <controller_intf *> injected_components;

        public:
            mainController(string n) : controller_intf(n) {}

            void start();
            void stop(bool exit = false);

            void inject(controller_intf *component);
    };

#endif
