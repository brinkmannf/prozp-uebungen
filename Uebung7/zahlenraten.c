/*******************************************************************
// Programm    : Zahlenraten / Hauptdatei                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 7.11.2012                                           
// Aufgabe     : Benutzer muss Zahl zwischen 1 und 100 erraten
// Aenderungen  : 7.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include "funktionen.c"

#define MAX_ZAHL 100


int main() {
    strich(50, '-');
    printf("Zahlenraten\n");
    strich(50, '-');

    char again[2];
    do {
        zahlenraten(MAX_ZAHL);
        printf("Nochmal spielen? (j/n)\n");
        scanf("%s", &again);
    } while (again[0] == 'j' || again[0] == 'J');

    printf("Servus! \n");
    return 0;
}