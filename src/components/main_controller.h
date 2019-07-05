#ifndef MAIN_CONTROLLER_H
    #define MAIN_CONTROLLER_H

    #include <vector>
    #include "controller_intf.h"

    using namespace std;



    class main_controller: public controller_intf
    {
        main_controller() : main_controller("main_controller") {}
        main_controller(string n) : controller_intf(n) {}

        main_controller(const main_controller& orig) = delete;
        const main_controller& operator= (const main_controller& orig) = delete;

        static main_controller mc_instance;

        vector <controller_intf *> injected_components;

        public:
            static main_controller& get_instance();

            void start();
            void stop(bool exit = false);

            void inject(controller_intf *component);
    };

#endif
