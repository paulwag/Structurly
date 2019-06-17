#include "task.h"

task::task(int identifier, string title, string description, priority tpriority, ttime startingtime, int length, repetition trepetition, string category)     //if not set, empty string?
{
    this->identifier    = identifier;
    this->title         = title;
    this->description   = description;
    this->tpriority     = tpriority;
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

void task::set_startingtime( ttime startingtime)
{
    this->startingtime = startingtime;
}

void task::set_repetition( repetition trepetition)
{
    this->trepetition = trepetition;
}

void task::set_category( string category)
{
    this->category = category;
}
