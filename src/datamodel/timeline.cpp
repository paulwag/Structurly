#include "timeline.h"

unsigned long calcSlot(int hour, int minute);

timeline::timeline(int identifier)
: id(identifier)
{
    for (int i = 0; i < MAXSLOTS; i++)      // set 96 empty timeslots
        timeslots.push_back(nullptr);
}



void timeline::insert_task(task *new_task)
{
    int hour = new_task->get_startingtime().get_hour();
    int minute = new_task->get_startingtime().get_minute();

    unsigned long slot = calcSlot(hour, minute);
    if (timeslots.at(slot) == nullptr)
        timeslots.at(slot) = new_task;
    else
        cout << "timeslot in timeline schon belegt...\n";
}


//WIP Stuff for removing Task from the timelines
void timeline::remove_task(task *removed_task){

    int hour = removed_task->get_startingtime().get_hour();
    int minute = removed_task->get_startingtime().get_minute();

    unsigned long slot = calcSlot(hour, minute);
    if(timeslots.at(slot) != nullptr)
        timeslots.at(slot) = nullptr;
    else
        cout << "Task konnte nicht entfernt werden!\n";
}


task *timeline::get_task(u_int ts){
    if(timeslots.at(ts)){
        return timeslots.at(ts);
    }
    return nullptr;
}

// ////////////////////////////////////////////////////// Functions
unsigned long calcSlot(int hour, int minute){

    int minute_offset;
    if (minute == 0)
        minute_offset = 0;
    else if (minute == 15)
        minute_offset = 1;
    else if (minute == 30)
        minute_offset = 2;
    else
        minute_offset = 3;

    return static_cast<unsigned long>(4*hour + minute_offset);
}

