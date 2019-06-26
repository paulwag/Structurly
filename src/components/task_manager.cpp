#include <iostream>
#include "task_manager.h"
#include "singletons.h"
#include "task.h"


vector<task *>& tasks = db_c.getTasks(); //reference to task vector, global lassen oder in createTask? dann wird es jedoch jedes Mal aufgerufen
vector<int>& lookUpTable = db_c.getLookUpTable();   // reference to lookUpTable

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
    int identifier;

    cout << "TM: Task wird erstellt..." << endl;

    task *newTask = new task();

    if(lookUpTable.size() == 0)
    {
        newTask->set_identifier(tasks.size() + 1);
        tasks.push_back(newTask);                       //Task am Ende einfuegen, Eigenschaften koennen anschließend gesetzt werden oder?
    }
    else
    {
        int identifier = createIdentifier();
        newTask->set_identifier(identifier);
        tasks.erase(tasks.begin() + identifier-1);            // Template an Stelle identifier entfernen
        tasks.insert(tasks.begin() + identifier-1, newTask);  // Task an entsprechende Stelle fuegen
    }
    // restliche Eigenschaften setzen

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
    int identifier = lookUpTable.at(1);     //gibt niedrigsten identifier zurueck
    lookUpTable.erase(lookUpTable.begin());                   //aus lookUpTable entfernen

    return identifier;
}
