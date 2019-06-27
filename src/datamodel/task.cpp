#include "task.h"



task::task()
: identifier(0), title(""), description(""), tpriority(none), date(0, 0, 0), startingtime(99, 99, 0), length(0), trepetition(keine), category("") {}

task::task(unsigned long id, string t, string des, priority p, tdate d, ttime tim, int l, repetition r, string c)                   //if not set, empty string?
: identifier(id), title(t), description(des), tpriority(p), date(d), startingtime(tim), length(l), trepetition(r), category(c) {}



void task::set_repetition_from_string(string tag)
{
         if (tag == "Taeglich")     trepetition = Taeglich;
    else if (tag == "Woechentlich") trepetition = Woechentlich;
    else if (tag == "Monatlich")    trepetition = Monatlich;
    else if (tag == "Jaehrlich")    trepetition = Jaehrlich;
    else if (tag == "keine")        trepetition = keine;
    else if (tag == "")             trepetition = keine;
}

void task::set_priority_from_string(string tag)
{
         if (tag == "high")     tpriority = high;
    else if (tag == "medium")   tpriority = medium;
    else if (tag == "low")      tpriority = low;
    else if (tag == "none")     tpriority = none;
    else if (tag == "")         tpriority = none;
}

string task::get_repetition_string()
{
    switch (trepetition)
    {
        case Taeglich:      return "Taeglich";
        case Woechentlich:  return "Woechentlich";
        case Monatlich:     return "Monatlich";
        case Jaehrlich:     return "Jaehrlich";
        case keine:         return "keine";
    }
    return "ERR";
}

string task::get_priority_string()
{
    switch (tpriority)
    {
        case high:      return "high";
        case medium:    return "medium";
        case low:       return "low";
        case none:      return "none";
    }
    return "ERR";
}
