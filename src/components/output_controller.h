#ifndef OUTPUT_CONTROLLER_H
    #define OUTPUT_CONTROLLER_H

    #include "controller_intf.h"

    using namespace std;



    class output_controller: public controller_intf
    {
        output_controller() : output_controller("output_controller") {}                 // Singleton: both constructors are needed
        output_controller(string n) : controller_intf(n) {}

        output_controller(const output_controller& orig) = delete;                      // Singleton: disable copy constructor
        const output_controller& operator= (const output_controller& orig) = delete;    // Singleton: disable " operator

        static output_controller oc_instance;                                           // Singleton: important static

        public:
            static output_controller& get_instance();

            void start();
            void stop(bool exit = false);

            void updateGUI();
    };

#endif
