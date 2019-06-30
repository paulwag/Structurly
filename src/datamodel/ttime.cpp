#include <string>
#include <ctime>
#include "ttime.h"

using namespace std;



/////////////////////////////////////////////////////////// Konstruktoren
ttime::ttime()
{
    set_current_time();
}

ttime::ttime(int h, int m, int s)
: hour{h}, minute{m}, second{s} {}

/////////////////////////////////////////////////////////// Operatoren
ostream &operator<< (ostream &ostr, const ttime &t)
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
void ttime::set_time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void ttime::set_current_time()
{
    time_t rawtime = time(NULL);
    struct tm *time = localtime(&rawtime);

    hour = time->tm_hour;
    minute = time->tm_min;
    second = time->tm_sec;
}
