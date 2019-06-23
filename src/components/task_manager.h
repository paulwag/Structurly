#ifndef TASK_MANAGER_H
    #define TASK_MANAGER_H

    #include "controller_intf.h"

    using namespace std;



    class task_manager: public controller_intf
    {
        public:
             task_manager(string n) : controller_intf(n) {}

            /**
             * @brief start liest bei Start alle Daten aus der Datenbank aus
             */
            void start();

            /**
             * @brief stop speichert alle Daten bei Programmende
             */
            void stop(bool exit = false);

            void createTask();
            void delTask();
            void updateTask();
    };

#endif // TASK_MANAGER_H
