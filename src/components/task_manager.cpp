#include <iostream>
#include "singletons.h"
#include "task.h"


// Frage allgemein: Wie wollen wir Aenderungen der Vektoren zwischen TaskManager und Database waehrend
// der Laufzeit handlen? Entweder schickt Task Manager dann den Vektor(bad) oder ruft entsprechende Funktion in Database auf
// "save_task_in_DB" - muss noch angepasst werden

task_manager task_manager::task_manager_instance;
task_manager& task_manager::get_instance()
{
    return task_manager_instance;
}

void task_manager::start()
{
    if (getStarted())
            return;

    setStarted(true);

    tasks = db_c.get_tasks_from_DB();                           // Tasks aus der Datenbank holen
    lookUpTable = db_c.getLookUpTable();                        // LookUpTable aus Datenbank holen
    std::cout << getName() << " gestartet" << endl;
}



void task_manager::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    std::cout << getName() << " beendet" << endl;
}



void task_manager::createTask(string title, string description, tdate date, ttime starttime)
{
    cout << "TM: createTask()" << endl;

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
        tasks.at(identifier - 1) = newTask;  // Task an entsprechende Stelle fuegen
    }

    newTask->set_title(title);                                  // quick and dirty, sollte gleich beim Anlegen passieren, Konstruktor und so (Peter)
    newTask->set_description(description);
    newTask->set_date(date);
    newTask->set_startingtime(starttime);

    //tasks.push_back(newTask);                                   // In eigenen Vector speichern
    cm_c.updateTimelines(newTask);                              // An den calenderManger weiterreichen
    db_c.save_task_in_DB(newTask);                              // In Datenbank Vektor speichern
}



void task_manager::printTasks() // Kann später weg, wenn wirklich alles funktioniert (Peter)
{
    for (auto task : tasks)
        cout << "ID: " << task->get_identifier() << " | Titel: " << task->get_title() << " | Beschreibung: " << task->get_description() << " | Datum: " << task->get_date() << " | Startzeit: " << task->get_startingtime() << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
}



void task_manager::delTask(int identifier)
{
    //bekommt die Funktion als Parameter den Identifier
    tasks.at(identifier-1) = nullptr;  //Zeiger im Vektor auf NULL setzen
    db_c.deleteTask(identifier);       //Zeiger im Vektor der DB auch aktualisieren
    //Position in LookupTable vermerken
    lookUpTable.push_back(identifier);
    db_c.save_position_in_LUT(identifier);
}
void task_manager::updateTask() {}

/*void task_manager::editTask(int identifier, string title, string description, tdate date, ttime starttime)
{
    tasks.at(identifier)->set_title(title);
    tasks.at(identifier)->set_description(description);
    tasks.at(identifier)->set_date(date);
    tasks.at(identifier)->set_startingtime(starttime);
    // ToDo Aenderung auch in DB speichern, nicht erst beim stoppen
}

*/

int task_manager::createIdentifier()
{
    int identifier = lookUpTable.at(0);                       // gibt niedrigsten identifier zurueck
    lookUpTable.erase(lookUpTable.begin());                   // aus lookUpTable entfernen
    db_c.remove_from_LUT();                                   // evtl sinnvoller die LUT erst am Ende der DB zu geben

    return identifier;
}

