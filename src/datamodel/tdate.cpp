#include <string>
#include <ctime>
#include "tdate.h"

using namespace std;



/////////////////////////////////////////////////////////// Konstruktoren
tdate::tdate()
{
    set_today();
}

tdate::tdate(int d, int m, int y)
: day{d}, month{m}, year{y} {}

/////////////////////////////////////////////////////////// Operatoren
ostream &operator<< (ostream &ostr, const tdate &d)
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
inline void tdate::set_date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void tdate::set_today()
{
    time_t rawtime = time(NULL);
    struct tm *time = localtime(&rawtime);

    day = time->tm_mday;
    month = time->tm_mon + 1;
    year = time->tm_year + 1900;
}
