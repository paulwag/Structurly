#ifndef TIMELINE_H 
    #define TIMELINE_H TIMELINE_H

    #include <vector>
    #include "task.h"

    using namespace std;

    #define MAXSLOTS 96



    class timeline
    {
        int id;                     // wird im constructor gesetzt, anschließend fix
        vector<task *> timeslots;   // muss im constructor mit NULL initialisiert werden

        public:
            timeline(int identifier);

            int get_id() const {return id;}

            void insert_task(task *new_task);
            /*
             *  get_task returns *task, needs a slot (0-95) as index
             *  ts : index
             */
            task *get_task(u_int ts);
    };

#endif
