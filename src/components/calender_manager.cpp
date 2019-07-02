#include <iostream>
#include "singletons.h"

using namespace std;

timeline *check_for_tl_existence(const int id, vector<timeline *> &timelines);



// /////////////////////////////////////////////////////////////////////////// Singleton Stuff
calender_manager calender_manager::cm_instance;
calender_manager& calender_manager::get_instance()
{
    return cm_instance;
}


// /////////////////////////////////////////////////////////////////////////// Start | Stop
void calender_manager::start()
{
    if (getStarted())
        return;

    setStarted(true);

    int id;
    timeline *new_tl, *existing;
    vector<task *> tasks_from_task_manager = tm_c.getTasks();

    for (auto task: tasks_from_task_manager)
    {
        id = calc_id(task->get_date());
        existing = check_for_tl_existence(id, timelines);

        if (existing)
        {
            // insert taks in existing timeline
        }
        else
        {
            new_tl = new timeline(id);
            // insert taks in new timeline
            timelines.push_back(new_tl);
        }

    }

    cout << getName() << " gestartet" << endl;
}

void calender_manager::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    for (auto tl : timelines)
    {
        cout << "CM: Timeline ID(" << tl->get_id() << ") wird geloescht..." << endl;
        delete tl;
    }
    std::cout << getName() << " beendet" << endl;
}


// /////////////////////////////////////////////////////////////////////////// Methods
void calender_manager::updateTimelines() {}


// /////////////////////////////////////////////////////////////////////////// Functions
int calc_id(tdate date)
{
    int year = date.get_year();
    int month = date.get_month();
    int day = date.get_day();
    int id = year*10000 + month*100 + day;

    return id;
}

timeline *check_for_tl_existence(const int id, vector<timeline *> &timelines)
{
    for (auto tl: timelines)
    {
        if (tl->get_id() == id)
            return tl;
    }

    return nullptr;
}
