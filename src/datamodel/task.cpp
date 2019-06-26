#include "task.h"

//initial values
task::task()
{
    this->identifier = 0;
    this->title = "";
    this->description = "";
    this->tpriority = none;
    tdate date(0, 0, 0);
    this->date = date;
    ttime startingtime(99, 99, 0);
    this->startingtime = startingtime;
    this->length = 0;
    this->trepetition = keine;
    this->category = "";
}

task::task(int identifier, string title, string description, priority tpriority,tdate date, ttime startingtime, int length, repetition trepetition, string category)     //if not set, empty string?
{
    this->identifier    = identifier;
    this->title         = title;
    this->description   = description;
    this->tpriority     = tpriority;
    this->date          = date;
    this->startingtime  = startingtime;
    this->length        = length;
    this->trepetition   = trepetition;
    this->category      = category;
}

void task::set_identifier(int identifier)
{
    this->identifier = identifier;
}

void task::set_title( string title)
{
    this->title = title;
}

void task::set_description( string description)
{
    this->description = description;
}

void task::set_priority( priority tpriority)
{
    this->tpriority = tpriority;
}

void task::set_date( tdate date)
{
    this->date = date;
}

void task::set_startingtime( ttime startingtime)
{
    this->startingtime = startingtime;
}


void task::set_length(int length)
{
    this->length = length;
}

void task::set_repetition( repetition trepetition)
{
    this->trepetition = trepetition;
}

void task::set_category( string category)
{
    this->category = category;
}

void task::set_repetition_from_string(string tag)
{
    if(tag == "Taeglich") this->trepetition = Taeglich;
    else if(tag =="Woechentlich") this->trepetition = Woechentlich;
    else if(tag == "Monatlich") this->trepetition = Monatlich;
    else if(tag == "Jaehrlich") this->trepetition = Jaehrlich;
    else if(tag == "keine") this->trepetition = keine;
    else if(tag == "") this->trepetition = keine;
}

void task::set_priority_from_string(string tag)
{
    if(tag == "high") this->tpriority = high;
    else if(tag =="medium") this->tpriority = medium;
    else if(tag == "low") this->tpriority = low;
    else if(tag == "none") this->tpriority = none;
    else if(tag == "") this->tpriority = none;
}

string task::get_repetition_string()
{
    switch (trepetition)
    {
        case Taeglich: return "Taeglich";
        case Woechentlich: return "Woechentlich";
        case Monatlich: return "Monatlich";
        case Jaehrlich: return "Jaehrlich";
        case keine: return "keine";
    }
}

string task::get_priority_string()
{
    switch (tpriority)
    {
        case high: return "high";
        case medium: return "medium";
        case low: return "low";
        case none: return "none";
    }
}
