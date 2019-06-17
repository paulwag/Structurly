#ifndef TASK_H
#define TASK_H

#include <string>
#include "ttime.h"
#include "tdate.h"

using namespace std;

enum priority {high, medium, low};
enum repetition {Taeglich, Woechentlich, Monatlich, Jaehrlich};



class task{
    private:
        int identifier;
        string title;
        string description;
        priority tpriority;
        ttime startingtime;
        int length;                 //in minutes
        repetition trepetition;
        string category;

    public:
        task();
        task(int identifier, string title, string description, priority tpriority, ttime startingtime, int length, repetition trepetition, string category);     //if not set, empty string?

        void set_identifier(int identifier);
        void set_title( string title);
        void set_description( string description);
        void set_priority( priority tpriority);
        void set_startingtime( ttime startingtime);
        void set_repetition( repetition trepetition);
        void set_category( string category);

        int get_identifier()        {return identifier;}
        string get_title()          {return title;}
        string get_description()    {return description;}
        priority get_priority()     {return tpriority;}
        ttime get_startingtime()    {return startingtime;}
        int get_length()            {return length;}
        repetition get_repetition() {return trepetition;}
        string get_category()       {return category;}
};

#endif // TASK_H
