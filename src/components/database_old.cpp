#include "database_old.h"
#include "timeline.h"
#include <string>

using namespace std;

void Database::saveAll()
{
    /* 1. FilePointer erstellen
       2. File oeffnen, ansonsten erstellen wenn nicht vorhanden
       3. <Data> Tag reinschreiben
       4. saveTasks() aufrufen mit Filepointer
       5. saveTimelines aufrufen mit Filepointer
       6. saveLookuptable() aufrufen mit Filepointer
       7. </Data> schreiben
       8. Filestream schließen
    */
}

void Database::saveTasks()
{

}

void Database::saveTimelines()
{

}

void Database::saveLookuptable()
{

}

void Database::saveCategories()
{

}
