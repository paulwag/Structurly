#ifndef CONTROLLER_INTF_H
#define CONTROLLER_INTF_H

class controller_intf
{
    virtual ~controller_intf();
    virtual void start() = 0;
    virtual void stop() = 0;

};

#endif
