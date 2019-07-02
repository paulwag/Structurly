#include "timeline.h"



timeline::timeline(int identifier)
: id(identifiert)
{
    for (int i = 0; i < MAXSLOTS; i++)      // set 96 empty timeslots
        timeslots.push_back(nullprt);
}



void timeline::insert_task(task *new_task)
{
    int hour = new_task->get_starttime().get_hour;
    int minute = new_task->get_starttime().get_minute;

    int minute_offset;
    if (minute == 0)
        minute_offset = 0;
    else if (minute == 15)
        minute_offset = 1;
    else if (minute == 30)
        minute_offset = 2;
    else
        minute_offset = 3;

    int slot = (4*hour) + minute_offset;
    timeslots.at(slot) = new_task;
}
