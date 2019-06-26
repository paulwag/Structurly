#include <iostream>
#include "task_manager.h"
#include "singletons.h"
#include "task.h"



//vector<task *>& tasks = db_c.getTasks(); //reference to task vector, global lassen oder in createTask? dann wird es jedoch jedes Mal aufgerufen
// Peter: der Vector kommt als Attribut in die Klasse, da der taskManager ja die Tasks beinhalten soll

// vector<int>& lookUpTable = db_c.getLookUpTable();   // reference to lookUpTable


void task_manager::start()
{
    if (getStarted())
            return;

    setStarted(true);

    // Hier müssen die Daten aus der Datenbank geladen werden (Und damit meine ich: geladen! Also keine Referenz darauf!)

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

    newTask->set_title(title);                  // quick and dirty, sollte gleich beim Anlegen passieren, Konstruktor und so (Peter)
    newTask->set_description(description);
    newTask->set_identifier(tasks.size()+1);

    tasks.push_back(newTask);                   // In Vector speichern
    //db_c.storeFile();                         // In Datenbank übertragen



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
        tasks.erase(tasks.begin() + identifier-1);            // Template an Stelle identifier entfernen
        tasks.insert(tasks.begin() + identifier-1, newTask);  // Task an entsprechende Stelle fuegen
    }
    // restliche Eigenschaften setzen*/
}



void task_manager::printTasks() // Kann später weg, wenn wirklich alles funktioniert (Peter)
{
    for (auto task : tasks)
        cout << "ID: " << task->get_identifier() << " | Titel: " << task->get_title() << " | Beschreibung: " << task->get_description() << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
}



void task_manager::delTask()
{
    //aus Vektor entfernen --> an dieser Stelle mit Template arbeiten und dieses ersetzen wenn anderer Task identifier bekommt
    //identifier/position in LookupTable speichern

}
void task_manager::updateTask() {}

/* Stuff vom Conflict (Peter)
int task_manager::createIdentifier()
{
    int identifier = lookUpTable.at(1);     //gibt niedrigsten identifier zurueck
    lookUpTable.erase(lookUpTable.begin());                   //aus lookUpTable entfernen

    return identifier;
}*/
