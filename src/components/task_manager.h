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
        task_manager() : task_manager("task_manager") {}
        task_manager(string n) : controller_intf(n) {}

        task_manager(const task_manager& orig) = delete;                    // Singleton: disable copy constructor
        const task_manager& operator= (const task_manager& orig) = delete;  // Singleton: disable " operator

        static task_manager task_manager_instance;

        vector<task *> tasks;
        vector<int> lookUpTable;

        public:
            static task_manager& get_instance();

            void start();
            void stop(bool exit = false);

            vector<task *>& getTasks() {return tasks;}              // Referenz auf Vektor fuer calendar_manager

            void createTask(string title, string description, tdate date, ttime starttime);
            void delTask(int identifier);
            int createIdentifier();
            void updateTask();
            //void editTask(int identifier);  //better name for changing a task(Frank)

            void printTasks();                                      // Kann später weg, wenn wirklich alles funktioniert (Peter)
    };

#endif // TASK_MANAGER_H
