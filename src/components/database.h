#ifndef DATABASE_H
    #define DATABASE_H

    #include <vector>
    #include <iostream>
    #include <fstream>
    #include "controller_intf.h"
    #include "task.h"

    using namespace std;



    class database: public controller_intf
    {
        vector<task *> tasks;
        vector<int> lookUpTable;

        void freeTasks();                                                   // Lieber als Funktion in .cpp und nicht als Methode??? (Peter)
        task *loadTask(ifstream &in);

        public:
             database(string n) : controller_intf(n) {}

            /**
             * @brief Lädt die Daten aus einer XML-File
             */
            void start();




            void stop(bool exit = false);

            void save_task_in_DB(task *Task);
            void storeFile();
            void loadFile();
            vector<task *> get_tasks_from_DB()  const {return tasks;}

            //vector<int>& getLookUpTable() {return lookUpTable;}           // Lookup table stuff, WIP
            //void loadLookUpTable(ifstream &in);
            //void storeLookUpTable(ofstream &out);
    };

#endif
