#ifndef DATABASE_H
#define DATABASE_H

#include "database_intf.h"

class database : public database_intf
{
    ~database();

    /**
     * @brief start zieht alle Tasks und laedt diese in Timelines
     */
    void start();

    /**
     * @brief stop
     */
    void stop(bool exit = false);
};

#endif // DATABASE_H
