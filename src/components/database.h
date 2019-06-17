#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "database_intf.h"
#include "task.h"

class database : public database_intf
{
    private:
    std::vector<task> tasks = {};

    public:
         database(std::string name) : database_intf(name) {}
         ~database(){}

        /**
         * @brief start zieht alle Tasks und laedt diese in Timelines
         */
        void start();

        /**
         * @brief stop
         */
        void stop(bool exit = false);

        void loadFile();
        void loadTask();
        void loadLookUpTable();
        void loadCategories();

        void storeFile();
        void storeTask();
        void storeLookUpTable();
        void storeCategories();
};

#endif // DATABASE_H
