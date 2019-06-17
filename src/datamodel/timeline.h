#ifndef DATASTRUCTURE_H_INCLUDED
    #define DATASTRUCTURE_H_INCLUDED

#include <string>
#include <vector>
#include "task.h"


using namespace std;

#define maxtasks 96 //solange noch keine Ueberschneidungen moeglich sind(24 * 4)

class timeline{
    private:
        string identifier;                 //07062019, Datum als Identifier? String wegen fuehrender 0
        std::vector<int> tasks = {};       // die Nummern bzw jeweiligen Identifier der Tasks, Groesse Maxtasks?

    public:
        timeline();
        timeline(string identifier);

        //Setter
        void set_identifier(string identifier);

        //Getter
        string get_identifier() {return identifier;}

        void addTask(int task);
        void deleteTask(int task);


};


#endif // DATASTRUCTURE_H_INCLUDED

/*Aufkommende Fragen:
-Enums erstellen?
-dynamische Enums, Beispiel Kategorien?
-Dauer in welcher Einheit? Minuten?
-Benennung der Structs, eigene structs oder vorgegebene Bib?
-deadline: eigenes struct? Datum + Uhrzeit, Deadline Funktion mit rein?
-tools klasse fuer zeit funktionen, umwandlungen etc
*/
