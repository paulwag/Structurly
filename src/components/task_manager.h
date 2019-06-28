#ifndef TASK_MANAGER_H
    #define TASK_MANAGER_H

    #include "controller_intf.h"
    #include <vector>
    #include "task.h"

    using namespace std;



    class task_manager: public controller_intf
    {
        vector<task *> tasks;

        public:
             task_manager(string n) : controller_intf(n) {}

            /**
             * @brief start liest bei Start alle Daten aus der Datenbank aus (Paul) <-- Wichtig
             */
            void start();

            /**
             * @brief stop speichert alle Daten bei Programmende (Paul) //unnötig, da neue Tasks sowieso sofort in die DB gespeichert werden (Peter))
             */
            void stop(bool exit = false);

            void createTask(string title, string description);
            void printTasks();  // Kann später weg, wenn wirklich alles funktioniert (Peter)

            void delTask();
            void updateTask();

        private:
            int createIdentifier();
    };

#endif // TASK_MANAGER_H
