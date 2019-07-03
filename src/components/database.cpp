#include "database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //setfill, setw

using namespace std;

database database::db_instance;
database& database::get_instance()
{
    return db_instance;
}

void database::start()
{
    if (getStarted())
            return;

    setStarted(true);

    loadFile();
    std::cout << getName() << " gestartet" << endl;

    /*for(int i=0; i<lookUpTable.size(); ++i)
        cout << lookUpTable.at(i) << endl;*/
}



void database::stop(bool exit)
{
    if (!getStarted())
        return;

    setStarted(false);

    storeFile();
    freeTasks();
    std::cout << getName() << " beendet" << endl;
}



void database::save_task_in_DB(task *Task)
{
    tasks.push_back(Task);                  //Task an Vektor anhaengen
    // Preparation for deleted Tasks
    // int identifier = Task->get_identifier;
    // tasks.insert(tasks.begin() + identifier-1, newTask);
}



void database::storeFile()
{
    // erstmal nur Tasks speichern
    // ToDo: Probleme mit leeren Strings bei title, description, category aktuell fixed mit Space
    //       storeTask() auslagern aus storeFile(), bzw nur fuer Schreiben eines Tasks an bestimmte Position

    //ofstream out("database.xml");                                                                         // is saving database.xml in build/debug
    ofstream out("../../database/database.xml");
    //ofstream out("../../database/test.xml");

    out << "<Data>\n";
    out << "    <Tasks>\n";

    for (auto i: tasks)
    {
        //if(i != nullptr){        Preparation for deleted Tasks
        string random = "";
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
        //}                     Preparation for deleted Tasks
    }
    out << "    </Tasks>\n";

    //storeLookUpTable(out);        //ready to test
    out << "</Data>";

    out.close();
}



void database::loadFile()
{
    task *newTask = new task();
    string line;
    string tag = "";             //Tag without Whitespaces

    //ifstream in("../../../../../database/database.xml");
    ifstream in("../../database/database.xml");
    //ifstream in("../../database/test.xml");

    if(!in)
    {
        cout << "File not found" << endl;
        return;
    }

    while(getline(in, line))
    {
        for(uint i=0; i<line.length(); ++i)
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
            //if(newTask->identifier == (tasks.size() + 1))     Preparation for deleted Tasks
            tasks.push_back(newTask);

            /*else                                              Preparation for deleted Tasks
            {
                //alles vor Task mit Identifier bekommt Nullzeiger
                while(tasks.size() != (newTask->identifier - 1))
                    tasks.push_back(nullptr);

                tasks.push_back(newTask);
            }
            */
        }

        /*if(tag == "<LookUpTable>")                            Preparation for deleted Tasks
        {
            loadLookUpTable(in);
        }*/
        tag = "";
    }

    in.close();
}



task *database::loadTask(ifstream &in){
    string tag;
    string line;
    task *newTask = new task();

    do
    {
        getline(in, line);
        tag="";             //Tag without Whitespaces

        for(uint i=0; i<line.length(); ++i)
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
        else if(tag.compare(0,7,"<title>") == 0)
        {
            string title;

            tag.erase(0,7);
            tag.erase(tag.end()-8, tag.end());
            //cout << tag << endl;
            title = tag;
            newTask->set_title(title);
        }

        //description
        else if(tag.compare(0,13,"<description>") == 0)
        {
            string description;

            tag.erase(0,13);
            tag.erase(tag.end()-14, tag.end());
            //cout << tag << endl;
            description = tag;
            newTask->set_description(description);
        }

        //priority
        else if(tag.compare(0,10,"<priority>") == 0)
        {
            tag.erase(0,10);
            tag.erase(tag.end()-11, tag.end());

            newTask->set_priority_from_string(tag);
        }

        //repetition
        else if(tag.compare(0,12,"<repetition>") == 0)
        {
            tag.erase(0,12);
            tag.erase(tag.end()-13, tag.end());

            newTask->set_repetition_from_string(tag);
        }

        //date
        else if(tag.compare(0,6,"<date>") == 0)
        {
            int day, month, year;

            tag.erase(0,6);
            tag.erase(tag.end()-7, tag.end());

            day = stoi(tag.substr(0,2));
            month = stoi(tag.substr(2,2));
            year = stoi(tag.substr(4,4));

            tdate date(day, month, year);

            newTask->set_date(date);
        }

        //startingtime
        else if(tag.compare(0,14,"<startingtime>") == 0)
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
        else if(tag.compare(0,8,"<length>") == 0)
        {

            int length;

            tag.erase(0,8);
            tag.erase(tag.end()-9, tag.end());
            //cout << tag << endl;
            length = stoi(tag);

            newTask->set_length(length);
        }

        //category
        else if(tag.compare(0,10,"<category>") == 0)
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



/*void database::loadLookUpTable(ifstream &in)          Preparation for deleted Tasks
{
    string tag;
    string line;

    do
    {
        getline(in, line);
        tag="";             //Tag without Whitespaces

        for(uint i=0; i<line.length(); ++i)
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
}*/



/*void database::storeLookUpTable(ofstream& out)            Preparation for deleted Tasks
{
    out << "    <LookUpTable>\n";
    for(uint i=0; i<lookUpTable.size(); ++i)
    {
        out << "        <identifier>" << lookUpTable.at(i) << "</identifier>\n";
    }
    out << "    </LookUpTable>\n";
}*/

/* READY
void database::deleteTask(int position)                     Preparation for deleted Tasks
{
    tasks.at(position-1) = nullptr;
}

void database::save_position_in_LUT(int identifier)         Preparation for deleted Tasks
{
    lookUpTable.push_back(identifier);
}


void database::remove_from_LUT()                            Preparation for deleted Tasks
{
    lookUpTable.erase(lookUpTable.begin());
}
*/
void database::freeTasks()
{
    for(auto task: tasks)
        delete task;
}
