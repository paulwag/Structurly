#ifndef DATABASE_INTF_H
#define DATABASE_INTF_H
#include "task.h"
#include "controller_intf.h"

class database_intf: public controller_intf
{
public:
     database_intf(std::string name) : controller_intf(name) {}
     virtual ~database_intf(){}

    /**
     * @brief loadFile läd alle Daten aus File
     */
    virtual void loadFile() = 0;

    /**
     * @brief storeFile speichert alle Daten in File
     */
    virtual void storeFile() = 0;

     virtual std::vector<task>& getVector() = 0;
};

#endif // DATABASE_INTF_H
