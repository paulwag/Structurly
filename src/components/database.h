#ifndef DATABASE_H
    #define DATABASE_H

    #include <vector>
    #include <iostream>
    #include <fstream>
    #include "controller_intf.h"
    #include "task.h"

    using namespace std;

    /**
     * Komponente "Database"
     * Autor: Frank Ehlert
     * Beschreibung:    Die Datenbankkomponente ist fuer das Laden und Sichern der in "Structurly"
     *                  angelegten Tasks zustaendig, sodass nach Schließen des Programms, die Tasks
     *                  in einem externen File gesichtert sind. Zu Programmstart werden diese aus-
     *                  gelesen und dem Task-Manager fuer die weitere Verarbeitung uebergeben.
     */

    class database: public controller_intf
    {
        database() : database("database") {}
        database(string n) : controller_intf(n) {}

        database(const database& orig) = delete;                    // Singleton: disable copy constructor
        const database& operator= (const database& orig) = delete;  // Singleton: disable " operator

        static database db_instance;

        vector<task *> tasks;
        vector<int> lookUpTable;

        void freeTasks();                                                   // Lieber als Funktion in .cpp und nicht als Methode??? (Peter)
        task *loadTask(ifstream &in);

        public:
            static database& get_instance();

            void start();
            void stop(bool exit = false);

            void save_task_in_DB(task *Task);

            void storeFile();
            void loadFile();
            vector<task *> get_tasks_from_DB()  const {return tasks;}

            //vector<int> getLookUpTable() {return lookUpTable;}           //Preparation for deleted Tasks
            //void loadLookUpTable(ifstream &in);
            //void storeLookUpTable(ofstream &out);

            void save_position_in_LUT(int position);                        // bekommt Wert von task_manager
            void deleteTask(int position);
            void remove_from_LUT();
    };

#endif
