#include <iostream>
#include "singletons.h"
#include "task.h"



void task_manager::start()
{
    if (getStarted())
            return;

    setStarted(true);

    tasks = db_c.get_tasks_from_DB();                           // Tasks aus der Datenbank holen
    //lookUpTable = db_c.getLookUpTable();                      // LookUpTable aus Datenbank holen
    std::cout << getName() << " gestartet" << endl;
}



void task_manager::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    std::cout << getName() << " beendet" << endl;
}



void task_manager::createTask(string title, string description)
{
    task *newTask = new task();

    newTask->set_title(title);                                  // quick and dirty, sollte gleich beim Anlegen passieren, Konstruktor und so (Peter)
    newTask->set_description(description);
    newTask->set_identifier(tasks.size()+1);

    tasks.push_back(newTask);                                   // In eigenen Vector speichern
    db_c.save_task_in_DB(newTask);                              // In Datenbank Vektor speichern



    /* Stuff vom Conflict (Peter)
    if(lookUpTable.size() == 0)
    {
        newTask->set_identifier(tasks.size() + 1);
        tasks.push_back(newTask);                       //Task am Ende einfuegen, Eigenschaften koennen anschließend gesetzt werden oder?
    }
    else
    {
        int identifier = createIdentifier();
        newTask->set_identifier(identifier);
        tasks.insert(tasks.begin() + identifier-1, newTask);  // Task an entsprechende Stelle fuegen
    }
    // restliche Eigenschaften setzen*/

    // db_c.save_task_in_DB(newTask)                         // am Ende in DB auch speichern
}



void task_manager::printTasks() // Kann später weg, wenn wirklich alles funktioniert (Peter)
{
    for (auto task : tasks)
        cout << "ID: " << task->get_identifier() << " | Titel: " << task->get_title() << " | Beschreibung: " << task->get_description() << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
}



void task_manager::delTask()
{
    //bekommt die Funktion als Parameter den Identifier(damit die Position im Vektor?)
    /*int identifier;
    tasks.at(identifier-1) = NULL;  //Zeiger im Vektor auf NULL setzen
    db_c.deleteTask(identifier);    //Zeiger im Vektor der DB auch aktualisieren
    //Position in LookupTable vermerken
    lookUpTable.push_back(identifier);
    db_c.save_position_in_LUT(identifier);
    */
}
void task_manager::updateTask() {}

/* Stuff vom Conflict (Peter)
int task_manager::createIdentifier()
{
    int identifier = lookUpTable.at(0);                       // gibt niedrigsten identifier zurueck
    lookUpTable.erase(lookUpTable.begin());                   // aus lookUpTable entfernen
    db_c.remove_from_LUT();                                   // evtl sinnvoller die LUT erst am Ende der DB zu geben

    return identifier;
}*/

