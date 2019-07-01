#ifndef TASK_MANAGER_H
    #define TASK_MANAGER_H

    #include <vector>
    #include "controller_intf.h"
    #include "task.h"
    #include "tdate.h"
    #include "ttime.h"

    using namespace std;



    class task_manager: public controller_intf
    {
        vector<task *> tasks;
        //vector<int> lookUpTable;

        public:
            task_manager(string n) : controller_intf(n) {}

            void start();
            void stop(bool exit = false);

            vector<task *>& getTasks() {return tasks;}              // Referenz auf Vektor fuer calendar_manager

            void createTask(string title, string description, tdate date, ttime starttime);
            void delTask();
            void updateTask();
            //void editTask(int identifier);  //better name for changing a task(Frank)

            void printTasks();                                      // Kann später weg, wenn wirklich alles funktioniert (Peter)
    };

#endif // TASK_MANAGER_H
