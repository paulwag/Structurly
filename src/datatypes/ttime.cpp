#include <string>
#include <ctime>
#include "ttime.h"
#include "toolbox.h"

using namespace std;



/////////////////////////////////////////////////////////// Konstruktoren
TTime::TTime()
{
    set_current_time();
}

TTime::TTime(int h, int m, int s)
: hour{h}, minute{m}, second{s} {}

/////////////////////////////////////////////////////////// Operatoren
ostream &operator<< (ostream &ostr, const TTime &t)
{
    ostr.fill('0');
    ostr.width(2);
    ostr << t.hour << ':';
    ostr.width(2);
    ostr << t.minute; 

    if (t.second)
    {
        ostr << ':';
        ostr.width(2);
        ostr << t.second; 
    }
    ostr.fill(' ');
    
    return ostr;
}

/////////////////////////////////////////////////////////// setter
inline void TTime::set_time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void TTime::set_current_time()
{
    time_t rawtime = time(NULL);
    struct tm *time = localtime(&rawtime);

    hour = time->tm_hour;
    minute = time->tm_min;
    second = time->tm_sec;
}

/////////////////////////////////////////////////////////// load
void TTime::load(ifstream &file)
{
    string input;

    do
    {
        getline(file, input);

        if (input.find("<Second>") != string::npos)
        {
            remove_tags(input, "Second");
            second = stoi(input);
        }
        else if (input.find("<Minute>") != string::npos)
        {
            remove_tags(input, "Minute");
            minute = stoi(input);
        }
        else if (input.find("<Hour>") != string::npos)
        {
            remove_tags(input, "Hour");
            hour = stoi(input);
        }
    } while ( (input.find("</MUSSNOCH>") == string::npos)
               && !file.eof());
}
