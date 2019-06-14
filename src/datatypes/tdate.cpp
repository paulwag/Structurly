/*#include <string>
#include <ctime>
#include "tdate.h"
#include "toolbox.h"

using namespace std;



/////////////////////////////////////////////////////////// Konstruktoren
TDate::TDate()
{
    set_today();
}

TDate::TDate(int d, int m, int y)
: day{d}, month{m}, year{y} {}

/////////////////////////////////////////////////////////// Operatoren
ostream &operator<< (ostream &ostr, const TDate &d)
{
    ostr.fill('0');
    ostr.width(2);
    ostr << d.day << '.';
    ostr.width(2);
    ostr << d.month << '.' << d.year;
    ostr.fill(' ');
    
    return ostr;
}

/////////////////////////////////////////////////////////// setter
inline void TDate::set_date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void TDate::set_today()
{
    time_t rawtime = time(NULL);
    struct tm *time = localtime(&rawtime);

    day = time->tm_mday;
    month = time->tm_mon + 1;
    year = time->tm_year + 1900;
}

/////////////////////////////////////////////////////////// load
void TDate::load(ifstream &file)
{
    string input;

    do
    {
        getline(file, input);

        if (input.find("<Day>") != string::npos)
        {
            remove_tags(input, "Day");
            day = stoi(input);
        }
        else if (input.find("<Month>") != string::npos)
        {
            remove_tags(input, "Month");
            month = stoi(input);
        }
        else if (input.find("<Year>") != string::npos)
        {
            remove_tags(input, "Year");
            year = stoi(input);
        }
    } while ( (input.find("</Birthday>") == string::npos)
               && !file.eof());
}
*/
