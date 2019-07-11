#ifndef TASK_H
#define TASK_H

#include <string>
#include "ttime.h"
#include "tdate.h"

//Workaround for WIN...
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    typedef unsigned int uint;
#endif



using namespace std;

enum priority {high, medium, low, none};
enum repetition {Taeglich, Woechentlich, Monatlich, Jaehrlich, keine};



class task{
    private:
        unsigned long   identifier;
        string          title;
        string          description;
        priority        tpriority;
        tdate           date;
        ttime           startingtime;
        uint            length;                 //in minutes
        repetition      trepetition;
        string          category;

    public:
        task();
        task(unsigned long id, string t, string des, priority p, tdate d, ttime tim, int l, repetition r, string c);     //if not set, empty string?

        void set_identifier(unsigned long i)    {identifier = i;}
        void set_title(string t)                {title = t;}
        void set_description(string d)          {description = d;}
        void set_priority(priority p)           {tpriority = p;}
        void set_date(tdate d)                  {date = d;}
        void set_startingtime(ttime s)          {startingtime = s;}
        void set_repetition(repetition r)       {trepetition = r;}
        void set_length(int l)                  {length = l;}
        void set_category(string c)             {category = c;}

        void set_repetition_from_string(string tag);
        void set_priority_from_string(string tag);

        unsigned long get_identifier()  const   {return identifier;}
        string get_title()              const   {return title;}
        string get_description()        const   {return description;}
        priority get_priority()         const   {return tpriority;}
        tdate get_date()                const   {return date;}
        ttime get_startingtime()        const   {return startingtime;}
        int get_length()                const   {return length;}
        repetition get_repetition()     const   {return trepetition;}
        string get_category()           const   {return category;}

        string get_priority_string();
        string get_repetition_string();
};

#endif
