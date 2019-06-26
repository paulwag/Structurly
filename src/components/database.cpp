#include "database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //setfill setw

using namespace std;



void database::start()
{
    if (getStarted())
            return;

    setStarted(true);

    std::cout << getName() << " gestartet" << endl;

    loadFile();
    //cout << tasks.at(1)->get_identifier() << endl;
    /*for (auto i : tasks)        //for debug
    {
        cout << i->get_identifier() << endl;
        cout << i->get_title() << endl;
        cout << i->get_description() << endl;
    }
    */
    for(int i=0; i<lookUpTable.size(); ++i)
    {
        cout << lookUpTable.at(i) << endl;
    }
    //storeFile();
}



void database::stop(bool exit)
{
    if (!getStarted())
        return;

    setStarted(false);

    for (auto i : tasks)        //for debug
    {
        cout << i->get_identifier() << endl;
        cout << i->get_title() << endl;
        cout << i->get_description() << endl;
    }
    storeFile();
    std::cout << getName() << " beendet" << endl;
}



void database::loadFile()
{
    task *newTask = new task();
    string line;
    string tag = "";             //Tag without Whitespaces
    ifstream in("/home/frank/Dokumente/TI/5.Semester/Projekt/Structurly/src/datamodel/database.xml");
    //Oeffnen klappt mit absolutem Pfad
    //relativer Pfad ifstream in("../datamodel/database.xml");

    if(!in)
    {
        cout << "File not found" << endl;
        return;
    }

    while(getline(in, line))
    {
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

        if(tag == "<LookUpTable>")
        {
            loadLookUpTable(in);
        }
        tag = "";
    }

    //cout << tag << endl;
    //Fehlerbehandlung

    in.close();
}



task *database::loadTask(ifstream &in){
/*
 * Objekt der Klasse Task erstellen
 * Parameter einzeln einlesen und Objekt zuweisen  ->Funktion fuer jeden einzelnen Parameter?
 * nicht vorhandende Parameter? Leer schreiben? Leere Strings bzw Int = 0
 * Objekt returnen bzw Referenz
 *ToDo: elseifs schreiben
*/
    string tag;
    string line;
    task *newTask = new task();

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
            newTask->set_identifier(identifier);
        }

        //title
        if(tag.compare(0,7,"<title>") == 0)
        {
            string title;

            tag.erase(0,7);
            tag.erase(tag.end()-8, tag.end());
            //cout << tag << endl;
            title = tag;
            newTask->set_title(title);
        }

        //description
        if(tag.compare(0,13,"<description>") == 0)
        {
            string description;

            tag.erase(0,13);
            tag.erase(tag.end()-14, tag.end());
            //cout << tag << endl;
            description = tag;
            newTask->set_description(description);
        }

        //priority
        if(tag.compare(0,10,"<priority>") == 0)
        {
            priority tpriority;

            tag.erase(0,10);
            tag.erase(tag.end()-11, tag.end());
            //cout << tag << endl;
            //typecasten fuer enum priority

            //tpriority = stoi(tag);
            newTask->set_priority_from_string(tag);
        }

        //repetition
        if(tag.compare(0,12,"<repetition>") == 0)
        {
            repetition trepetition;

            tag.erase(0,12);
            tag.erase(tag.end()-13, tag.end());
            newTask->set_repetition_from_string(tag);
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

            newTask->set_date(date);
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
            //wenn keine Starting Time zugewiesen......9999? 0000 ist naemlich theoretisch moeglich als startzeit
            newTask->set_startingtime(startingtime);
        }

        //length
        if(tag.compare(0,8,"<length>") == 0)
        {

            int length;

            tag.erase(0,8);
            tag.erase(tag.end()-9, tag.end());
            //cout << tag << endl;
            length = stoi(tag);

            newTask->set_length(length);
        }

        //category
        if(tag.compare(0,10,"<category>") == 0)
        {
            string category;

            tag.erase(0,10);
            tag.erase(tag.end()-11, tag.end());
            //cout << tag << endl;
            category = tag;
            newTask->set_category(category);
        }

        //ToDo
        //mit case statt if arbeiten
        //laeuft noch nicht wenn es ueber mehrere Zeilen geht(Bsp. Descr.)
        //Funktionen fuer Umwandlung in time und date struct
        //typecasten auf enum fuer priority?
        //Datum Attribut in Task.h etc
    } while (tag != "</Task>");


    return newTask;
}

void database::loadLookUpTable(ifstream &in)
{
    string tag;
    string line;

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
            cout << tag << endl;
            identifier = stoi(tag);
            lookUpTable.push_back(identifier);
        }
    }while(tag != "</LookUpTable>");
}

void database::loadCategories()
{

}

void database::storeFile() {
    //erstmal nur Tasks speichern
    ofstream out("/home/frank/Dokumente/TI/5.Semester/Projekt/Structurly/src/datamodel/test.xml");      //for debugging

    out << "<Data>\n";
    out << "    <Tasks>\n";

    for(auto i: tasks)
    {
        out << "        <Task>\n";
        out << "            <identifier>"   << i->get_identifier() << "</identifier>\n";
        out << "            <title>"        << i->get_title() << "</title>\n";
        out << "            <description>"  << i->get_description() << "</description>\n";
        out << "            <priority>"     << i->get_priority_string() << "</priority>\n";
        out << "            <date>"         << setfill('0') << setw(2) << i->get_date().get_day() << setfill('0') << setw(2) << i->get_date().get_month() << setfill('0') << setw(4) << i->get_date().get_year() << "</date>\n";
        out << "            <startingtime>" << setfill('0') << setw(2) << i->get_startingtime().get_hour() << setfill('0') << setw(2) << i->get_startingtime().get_minute() << "</startingtime>\n";
        out << "            <length>"       << i->get_length() << "</length>\n";
        out << "            <repetition>"   << i->get_repetition_string() << "</repetition>\n";
        out << "            <category>"     << i->get_category() << "</category>\n";
        out << "        </Task>\n";
    }
    out << "    </Tasks>\n";
    storeLookUpTable(out);
    out << "</Data>";

    out.close();
}

void database::storeTask(){} // auslagern aus storeFile()

void database::storeLookUpTable(ofstream& out)
{
    out << "    <LookUpTable>\n";
    for(int i=0; i<lookUpTable.size(); ++i)
    {
        out << "        <identifier>" << lookUpTable.at(i) << "</identifier>\n";
    }
    out << "    </LookUpTable>\n";
}
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
