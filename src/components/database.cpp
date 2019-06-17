#include "database.h"

void database::start()
{
    std::cout << getName() << " gestartet \n";
}

void database::stop(bool exit)
{
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void database::loadFile() {}

void database::storeFile() {}
