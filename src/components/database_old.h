#ifndef DATABASE_H
    #define DATABASE_H

    #include "timeline.h"
    #include "database.h"
    #include <iostream>
    #include <string>

    using namespace std;

    class database_intf
    {
        public:

            virtual ~database_intf();

            virtual void save_one_task() = 0;
            virtual void get_LUT() = 0;
            virtual void set_ID() = 0;
            virtual void load_all() = 0;
    };

    class Database
    {
        private:

        public:
            Database();

            /**************************************************
            Name: saveAll
            Aufgabe:
            Parameter:
            Return:
            **************************************************/
            void saveAll(void);

            /**************************************************
            Name: saveTasks
            Aufgabe:
            Parameter:
            Return:
            **************************************************/
            void saveTasks();

            /**************************************************
            Name: saveTimelines
            Aufgabe:
            Parameter:
            Return:
            **************************************************/
            void saveTimelines();

            /**************************************************
            Name: saveLookuptable
            Aufgabe:
            Parameter:
            Return:
            **************************************************/
            void saveLookuptable();

            /**************************************************
            Name: saveCategories
            Aufgabe:
            Parameter:
            Return:
            **************************************************/
            void saveCategories();

    };

    #endif // DATABASE_H_INCLUDED


