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
            vector<int>& getLookUpTable() {return lookUpTable;}

            void loadFile();
            task *loadTask(ifstream &in);
            void loadLookUpTable(ifstream &in);
            void loadCategories();

            void storeFile();
            void storeTask();
            void storeLookUpTable(ofstream &out);
            void storeCategories();
    };

#endif // DATABASE_H
