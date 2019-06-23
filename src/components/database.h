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

        public:
             database(string n) : controller_intf(n) {}

            /**
             * @brief start zieht alle Tasks und laedt diese in Timelines
             */
            void start();

            /**
             * @brief stop
             */
            void stop(bool exit = false);

            vector<task *> getTasks() const {return tasks;}

            void loadFile();
            task *loadTask(ifstream &in);
            void loadLookUpTable();
            void loadCategories();

            void storeFile();
            void storeTask();
            void storeLookUpTable();
            void storeCategories();
    };

#endif // DATABASE_H
