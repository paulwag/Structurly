#ifndef CONTROLLER_INTF_H
#define CONTROLLER_INTF_H

#include <string>
#include <iostream>

class controller_intf
{
public:
    controller_intf(std::string name) {
        this->name = name;
    }
    virtual ~controller_intf() {}
    virtual void start() = 0;
    virtual void stop(bool exit = false) = 0;
    virtual std::string getName() const { return name; }

private:
    std::string name;

};

#endif
