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
             ~database()
             {
                 // Tasks im Vector freigeben
             }

            /**
             * @brief Lädt die Daten aus einer XML-File
             */
            void start();

            /**
             * @brief Speichert die Daten in eine XML-File
             */
            void stop(bool exit = false);

            vector<task *>& getTasks() {return tasks;}

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
