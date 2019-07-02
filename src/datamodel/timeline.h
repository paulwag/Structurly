#ifndef TIMELINE_H 
    #define TIMELINE_H TIMELINE_H

    #include <vector>
    #include "task.h"

    using namespace std;

    #define MAXSLOTS 96



    class timeline
    {
        vector<task *> timeslots;   // muss im constructor mit NULL initialisiert werden
        int id;                     // wird im constructor gesetzt, anschließend fix

        public:
            timeline(int identifier);

            int get_identifier() const {return identifier;}

            void instert_task(task *new_task);
    };

#endif
