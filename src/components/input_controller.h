#ifndef INPUT_CONTROLLER_H
    #define INPUT_CONTROLLER_H

    #include "input_controller_intf.h"
    #include "tdate.h"
    #include "ttime.h"

    using namespace std;

    #define BUT_CREATE  0
    #define BUT_PRINT   1
    #define BUT_DELETE  2
    #define BUT_EDIT    3



    /**
     * @brief   The input_controller class is the interface between the GUI and the main-prog. functions.
     *          The GUI just has to set the data for processing and call the button_pressed-method
     *          with button-ID (see defines on the top on this file). The input_controller is callen
     *          the necessary functions of the main program.
     *
     * @maintainer:     Peter Hanne
     * @last update:    04.07.2019
     */



    class input_controller: public input_controller_intf
    {
        input_controller() : input_controller("input_controller") {}                // Singleton: both constructors are needed
        input_controller(string n)
        : input_controller_intf(n), task_id(0), task_title(""), task_description(""), task_date(0, 0, 0), task_time(0, 0) {}

        input_controller(const input_controller& orig) = delete;                    // Singleton: disable copy constructor
        const input_controller& operator= (const input_controller& orig) = delete;  // Singleton: disable = operator

        static input_controller ic_instance;                                        // Singleton: important static

        int     task_id;                                                            // Buffer for task informations
        string  task_title;
        string  task_description;
        tdate   task_date;
        ttime   task_time;


        public:
            static input_controller& get_instance();

            /**
             * @brief start() starts the input_controller component.
             */
            void start();

            /**
             * @brief stops() starts the input_controller component.
             */
            void stop(bool exit = false);


            /**
             * @brief   set_task_parameter will set all important parameters of a task.
             *          This is needed if a Task will be created or changed.
             *          The GUI is calling this method to set there informations.
             *
             * @param   All parameters are parts of the task class.
             * @return  -1, if important parameters are missing / wrong
             *           0, if all important parameters are ok
             */
            int input_controller::set_task_parameter(int id);
            int set_task_parameter(string title, string decription, int hour, int minute, int day, int month, int year, int id = 0);


            /**
             * @brief   button_pressed() is called by the GUI, when a button ins pressed.
             *          Depending on the button, button_pressed() will call important methods
             *          for e.g. processing tasks.
             *
             * @param   The button that was clicked. See defindes on the top of this file.
             */
            void button_pressed(int button);
    };

#endif
