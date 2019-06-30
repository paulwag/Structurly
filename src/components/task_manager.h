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

            void start();
            void stop(bool exit = false);

            vector<task *>& getTasks() {return tasks;}              // Referenz auf Vektor fuer calendar_manager

            void createTask(string title, string description);
            void delTask();
            void updateTask();

            void printTasks();                                      // Kann später weg, wenn wirklich alles funktioniert (Peter)
    };

#endif // TASK_MANAGER_H
