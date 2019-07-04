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
            existing->insert_task(task);
        }
        else
        {
            new_tl = new timeline(id);
            new_tl->insert_task(task);
            timelines.push_back(new_tl);
        }

    }

    cout << getName() << " gestartet" << endl;
/*
    //YEAH Timelines with tasks!!!!!!!11!!1!
    for(auto test: timelines){
        cout << "Timeline: " << test->get_id() << endl;
        for(int i = 0; i < MAXSLOTS; i++){
            task *x;
            if((x = test->get_task(i)))
                cout << "\tTask: "<< x->get_title() << endl;
        }
    }*/
}

void calender_manager::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    for (auto tl : timelines)
        delete tl;

    std::cout << getName() << " beendet" << endl;
}


// /////////////////////////////////////////////////////////////////////////// Methods
void calender_manager::updateTimelines(task *new_task)
{
    cout << "CM: updateTimelines()..." << endl;

    int id = calc_id(new_task->get_date());
    timeline *existing = check_for_tl_existence(id, timelines);

    if (existing)
    {
        cout << "...timeline gibt es schon! -> Task wird eingefügt" << endl;
        existing->insert_task(new_task);
        oc_c.set_tl_for_gui(existing);

    }
    else
    {
        cout << "...neue timeline!" << endl;
        timeline *new_tl = new timeline(id);
        new_tl->insert_task(new_task);
        timelines.push_back(new_tl);
        oc_c.set_tl_for_gui(new_tl);
    }


}


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
