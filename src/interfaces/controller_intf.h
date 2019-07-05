#ifndef CONTROLLER_INTF_H
    #define CONTROLLER_INTF_H

    #include <string>
    #include <iostream>

    using namespace std;



    class controller_intf
    {
        string name;
        bool started;

        public:
            controller_intf(string n) : name{n}, started{false} {}
            virtual ~controller_intf() {}

            virtual string getName() const {return name;}
            virtual bool getStarted() {return started;}

            virtual void setStarted(bool s) {started = s;}

            virtual void start() = 0;
            virtual void stop(bool exit = false) = 0;
    };

#endif
