#include "database.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void database::start()
{
    if(getStarted())
        return;

    started(); // started = true, stopped = false

    std::cout << getName() << " gestartet \n";
    loadFile();
    //for debug
    for(int i = 0; i < tasks.size(); ++i)
    {
        std::cout << tasks.at(i).get_identifier() << endl;
        std::cout << tasks.at(i).get_title() << endl;
        std::cout << tasks.at(i).get_description() << endl;
    }

}

void database::stop(bool exit)
{
    if(getStopped())
        return;

    stopped(); // started = false, stopped = true

    storeFile();
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

std::vector<task>& database::getVector()
{
    return tasks;
}

void database::loadFile() {
    string line;
    ifstream in("/home/frank/Dokumente/TI/5.Semester/Projekt/Structurly/src/datamodel/database.xml");
    //Oeffnen klappt mit absolutem Pfad
    //relativer Pfad ifstream in("../datamodel/database.xml");
    task newTask;

    if(in)
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
        //cout << tag << endl;

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

        //priority
        if(tag.compare(0,10,"<priority>") == 0)
        {
            priority tpriority;

            tag.erase(0,10);
            tag.erase(tag.end()-11, tag.end());
            //cout << tag << endl;
            //typecasten fuer enum priority
            //tpriority = (priority)tag;
            //newTask.set_priority(tpriority);
        }

        //repetition
        if(tag.compare(0,12,"<repetition>") == 0)
        {
            repetition trepetition;

            tag.erase(0,12);
            tag.erase(tag.end()-13, tag.end());
            //cout << tag << endl;
            //typecasten fuer enum repetition
            //trepetition = (repetition)tag;
            //newTask.set_repetition(trepetition);
        }

        //date
        if(tag.compare(0,6,"<date>") == 0)
        {

            int day, month, year;


            tag.erase(0,6);
            tag.erase(tag.end()-7, tag.end());
            //cout << tag << endl;
            day = stoi(tag.substr(0,2));
            month = stoi(tag.substr(2,2));
            year = stoi(tag.substr(4,4));

            tdate date(day, month, year);    //geht ditte?

            newTask.set_date(date);
        }

        //startingtime
        if(tag.compare(0,14,"<startingtime>") == 0)
        {

            int hour, minute;


            tag.erase(0,14);
            tag.erase(tag.end()-15, tag.end());
            //cout << tag << endl;
            hour = stoi(tag.substr(0,2));
            minute = stoi(tag.substr(2,2));
            ttime startingtime(hour, minute, 0);    //geht ditte?

            newTask.set_startingtime(startingtime);
        }

        //length
        if(tag.compare(0,8,"<length>") == 0)
        {

            int length;

            tag.erase(0,8);
            tag.erase(tag.end()-9, tag.end());
            //cout << tag << endl;
            length = stoi(tag);

            newTask.set_length(length);
        }

        //category
        if(tag.compare(0,10,"<category>") == 0)
        {
            string category;

            tag.erase(0,10);
            tag.erase(tag.end()-11, tag.end());
            //cout << tag << endl;
            category = tag;
            newTask.set_category(category);
        }

        //ToDo
        //mit case statt if arbeiten
        //laeuft noch nicht wenn es ueber mehrere Zeilen geht(Bsp. Descr.)
        //Funktionen fuer Umwandlung in time und date struct
        //typecasten auf enum fuer priority?
        //Datum Attribut in Task.h etc
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
