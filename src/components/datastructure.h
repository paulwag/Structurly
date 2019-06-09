#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

enum repetition{daily, weekly, monthly, yearly};
enum category{Arbeit, Freizeit, Haushalt, Studium};

typedef struct
{
    int hour;
    int minute;
}time;

typedef struct
{
    int day;
    int month;
    int year;
}date;

typedef struct
{

}task;

typedef struct
{

}timeline;

#endif // DATASTRUCTURE_H
