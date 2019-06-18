#include "database.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void database::start()
{
    loadFile();
    std::cout << getName() << " gestartet \n";
}

void database::stop(bool exit)
{
    storeFile();
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void database::loadFile() {
    string line;
    ifstream in("database.xml");
    task newTask = *new task();

    while(getline(in, line))
    {
        string tag;             //Tag without Whitespaces
        for(int i=0; i<line.length(); ++i)
        {
            if((line[i] == ' ' || line[i] == 9) && tag.size() == 0)   // Tabs checken?
            {
            }
            else
                tag += line[i];
        }

        if(tag == "<Task>")
        {
            newTask = database::loadTask(in);
            tasks.push_back(newTask);
        }
    }

    //cout << tag << endl;
    //Fehlerbehandlung

    in.close();
}


task database::loadTask(ifstream &in){
/*
 * Objekt der Klasse Task erstellen
 * Parameter einzeln einlesen und Objekt zuweisen  ->Funktion fuer jeden einzelnen Parameter?
 * nicht vorhandende Parameter? Leer schreiben? Leere Strings bzw Int = 0
 * Objekt returnen bzw Referenz
 *
*/
    string tag;
    string line;
    task newTask = *new task();

    do
    {
        getline(in, line);
        tag="";             //Tag without Whitespaces

        for(int i=0; i<line.length(); ++i)
        {
            if((line[i] == ' ' || line[i] == 9) && tag.size() == 0)   // Tabs checken?
            {
            }
            else
                tag += line[i];
        }

        //identifier
        if(tag.compare(0,12,"<identifier>") == 0)
        {
            int identifier;

            tag.erase(0,12);
            tag.erase(tag.end()-13, tag.end());
            //cout << tag << endl;
            identifier = stoi(tag);
            newTask.set_identifier(identifier);
        }

        //Testen zu Hause --> Erase Function genaue Stelle etc
    }while(tag != "</Task>");

    newTask.set_identifier(3);

    return newTask;
}

void database::loadLookUpTable()
{

}

void database::loadCategories()
{

}

void database::storeFile() {}

void database::storeTask(){}
void database::storeLookUpTable(){}
void database::storeCategories(){}


/*
<Data>
    <Tasks>
        <Task>
            <identifier>    </identifier>
            <title>         </title>
            <description>   </description>
        </Task>
        <Task>
            <identifier>    </identifier>
            <title>         </title>
            <description>   </description>
        </Task>
    </Tasks>
    <Timelines>
        <Timeline>
            <identifier>    </identifier>
            <tasks>
                <identifier>    </identifier>
                <identifier>    </identifier>
                <identifier>    </identifier>
                <identifier>    </identifier>
            </tasks>
        </Timeline>
    </Timelines>
    <LookupTable>
        <identifier>    </identifier>
        <identifier>    </identifier>
        <identifier>    </identifier>
        <identifier>    </identifier>
        <identifier>    </identifier>
    </LookupTable>
    <Categories>
        <title>     </title>
        <title>     </title>
        <title>     </title>
        <title>     </title>
    </Categories>
</Data>
*/
