#include "database.h"

void database::start()
{
    loadFile();
    std::cout << getName() << " gestartet \n";
}

void database::stop(bool exit)
{
    storeFile();
    std::cout << getName() << " beendet \n";

    if (exit)
        std::cout << "exit is true \n";
}

void database::loadFile() {
/*
 * Datei oeffnen
 * Filestream
 * Data Tag abgleichen
 * Task Tag abgleichen
 * Dann in loadTask und Filepointer uebergeben
 * Task wird returned und in den Task Vector appended(push_back)
 * Datei schließen
 */
}


void database::loadTask(){
/*
 * Objekt der Klasse Task erstellen
 * Parameter einzeln einlesen und Objekt zuweisen  ->Funktion fuer jeden einzelnen Parameter?
 * nicht vorhandende Parameter? Leer schreiben? Leere Strings bzw Int = 0
 * Objekt returnen bzw Referenz
 *
*/
}

void database::loadLookUpTable()
{

}

void database::loadCategories()
{

}

void database::storeFile() {}

void database::storeTask(){}
void database::storeLookUpTable(){}
void database::storeCategories(){}


/*
<Data>
    <Tasks>
        <Task>
            <identifier>    </identifier>
            <title>         </title>
            <description>   </description>
        </Task>
        <Task>
            <identifier>    </identifier>
            <title>         </title>
            <description>   </description>
        </Task>
    </Tasks>
    <Timelines>
        <Timeline>
            <identifier>    </identifier>
            <tasks>
                <identifier>    </identifier>
                <identifier>    </identifier>
                <identifier>    </identifier>
                <identifier>    </identifier>
            </tasks>
        </Timeline>
    </Timelines>
    <LookupTable>
        <identifier>    </identifier>
        <identifier>    </identifier>
        <identifier>    </identifier>
        <identifier>    </identifier>
        <identifier>    </identifier>
    </LookupTable>
    <Categories>
        <title>     </title>
        <title>     </title>
        <title>     </title>
        <title>     </title>
    </Categories>
</Data>
*/
