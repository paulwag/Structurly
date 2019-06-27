#ifndef INPUT_CONTROLLER_H
    #define INPUT_CONTROLLER_H

    #include "controller_intf.h"

    using namespace std;

    #define BUT_CREATE  0
    #define BUT_PRINT   1



    class input_controller: public controller_intf
    {
        input_controller() : input_controller("input_controller") {}                // Singleton: both constructors are needed
        input_controller(string n)
        : controller_intf(n), task_title(""), task_description("") {}

        input_controller(const input_controller& orig) = delete;                    // Singleton: disable copy constructor
        const input_controller& operator= (const input_controller& orig) = delete;  // Singleton: disable " operator

        string task_title;
        string task_description;
        static input_controller ic_instance;                                        // Singleton: important static

        public:
            static input_controller& get_instance();

            void start();
            void stop(bool exit = false);

            void set_task_parameter(string t, string d);
            void button_pressed(int button);
    };

#endif
