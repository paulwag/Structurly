#include "database.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void database::start()
{
    loadFile();
    std::cout << getName() << " gestartet \n";
    //for debug
    std::cout << tasks.at(1).get_identifier() << endl;
    std::cout << tasks.at(1).get_title() << endl;
    std::cout << tasks.at(1).get_description() << endl;
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
    ifstream in("../datamodel/database.xml");
    //Oeffnen klappt nicht
    task newTask;

    if(in.is_open())
        cout << "File open" << endl;

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
        cout << tag << endl;

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
    task newTask;

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

        //title
        if(tag.compare(0,7,"<title>") == 0)
        {
            string title;

            tag.erase(0,7);
            tag.erase(tag.end()-8, tag.end());
            //cout << tag << endl;
            title = tag;
            newTask.set_title(title);
        }

        //description
        if(tag.compare(0,13,"<description>") == 0)
        {
            string description;

            tag.erase(0,13);
            tag.erase(tag.end()-14, tag.end());
            //cout << tag << endl;
            description = tag;
            newTask.set_description(description);
        }
        //mit case statt if arbeiten
        //laeuft noch nicht wenn es ueber mehrere Zeilen geht(Bsp. Descr.)
        //Testen zu Hause --> Erase Function genaue Stelle etc
    }while(tag != "</Task>");


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
