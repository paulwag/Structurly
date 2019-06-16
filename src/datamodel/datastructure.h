#ifndef DATASTRUCTURE_H_INCLUDED
    #define DATASTRUCTURE_H_INCLUDED

    #include <string>
    #include "ttime.h"

    using namespace std;

    enum priority {high, medium, low};
    enum repetition {Taeglich, Woechentlich, Monatlich, Jaehrlich};

    #define maxtasks 96 //solange noch keine Ueberschneidungen moeglich sind(24 * 4)

    typedef struct
    {
        int identifier;
        string title;
        string description;
        string priority;
        ttime startingtime;
        int length;
        repetition trepetition;
        string category;            // keine dynamischen enums moeglich --> strings und speichern
    } task;

    typedef struct
    {
        string identifier;          // 07062019, Datum als Identifier?
        //task tasks[maxtasks];     // direkt Array von Tasks, oder die IDs rein?
        int tasks[maxtasks];        // die Nummern bzw jeweiligen Identifier der Tasks
    } timeline;

#endif // DATASTRUCTURE_H_INCLUDED

/*Aufkommende Fragen:
-Enums erstellen?
-dynamische Enums, Beispiel Kategorien?
-Dauer in welcher Einheit? Minuten?
-Benennung der Structs, eigene structs oder vorgegebene Bib?
-deadline: eigenes struct? Datum + Uhrzeit, Deadline Funktion mit rein?
-tools klasse fuer zeit funktionen, umwandlungen etc
*/
