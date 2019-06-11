#include <iostream>
#include "datastructure.h"
#include <ctime>

using namespace std;
// Hilfsfunktionen, Konvertierungen, etc

TTime setTime()
{
    TTime timestamp;

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    timestamp.hour = timePtr->tm_hour;
    timestamp.minute = timePtr->tm_min;

    return timestamp;
}

TDate setDate()
{
    TDate timestamp;

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    timestamp.year = timePtr->tm_year + 1900;
    timestamp.month = timePtr->tm_mon + 1;
    timestamp.day =timePtr->tm_yday;

    return timestamp;
}
