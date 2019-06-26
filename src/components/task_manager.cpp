#include <iostream>
#include "task_manager.h"
#include "singletons.h"
#include "task.h"


vector<task *>& tasks = db_c.getTasks(); //reference to task vector, global lassen oder in createTask? dann wird es jedoch jedes Mal aufgerufen

void task_manager::start()
{
    if (getStarted())
            return;

    setStarted(true);

    std::cout << getName() << " gestartet" << endl;
}



void task_manager::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    std::cout << getName() << " beendet" << endl;
}



void task_manager::createTask()
{
    cout << "TM: Task wird erstellt..." << endl;

    task *newTask = new task();

    //int identifier = createIdentifier();
    int identifier = tasks.size() + 1; //zunaechst wird der Identifier uber die Groesse des Vektors erstellt, spaeter mit LookupTable
    newTask->set_identifier(identifier);
    tasks.push_back(newTask);
    //an entsprechende Stelle einfuegen im Vektor! entsprechend identifier

    db_c.storeFile(); // Aenderungen speichern
}



void task_manager::delTask()
{
    //aus Vektor entfernen --> an dieser Stelle mit Template arbeiten und dieses ersetzen wenn anderer Task identifier bekommt
    //identifier/position in LookupTable speichern

}
void task_manager::updateTask() {}

int task_manager::createIdentifier()
{
    //erst in Lookup Table schauen
    //if LookupTable empty --> return tasks.size() + 1
}
