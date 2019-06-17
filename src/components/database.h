#ifndef DATABASE_H
#define DATABASE_H

#include "database_intf.h"

class database : public database_intf
{
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
    void storeFile();
};

#endif // DATABASE_H
