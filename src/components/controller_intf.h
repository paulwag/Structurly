#ifndef CONTROLLER_INTF_H
#define CONTROLLER_INTF_H

#include <string>
#include <iostream>

class controller_intf
{
public:
    controller_intf(std::string name) {
        this->name = name;
        this->component_started = false;
        this->component_stopped = true;
    }
    virtual ~controller_intf() {}
    virtual void start() = 0;
    virtual void stop(bool exit = false) = 0;
    virtual std::string getName() const { return name; }
    virtual bool getStarted() { return component_started; }
    virtual bool getStopped() { return component_stopped; }
    virtual void started() {
        component_started = true;
        component_stopped = false;
    }
    virtual void stopped() {
        component_started = false;
        component_stopped = true;
    }

private:
    std::string name;
    bool component_started;
    bool component_stopped;
};

#endif
