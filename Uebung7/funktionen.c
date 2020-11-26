/*******************************************************************
// Programm    : Zahlenraten / Funktionen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 7.11.2012                                           
// Aufgabe     : Benutzer muss Zahl zwischen 1 und 100 erraten
// Aenderungen  : 7.11.2012
*******************************************************************/
#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include "funktionen.h"
#include <time.h>
#include <stdlib.h>

/* globale Konstanten fuer boolesche Ausdruecke */
const int FALSE = 0;
const int TRUE = 1;

void strich(int n, char c) // gibt n mal das Zeichen c aus
{
    int i;
    for (i = 1; i <= n; i++)
        printf("%c", c);
    printf("\n");
}

void zahlenraten(int MaxZahl) {
    srand((unsigned int) time(NULL));
    int gesZahl = rand() % MaxZahl;
    printf("Ich habe mir eine Zahl zwischen 1 und %d ausgedacht. Welche ist es?\n", MaxZahl);
    rate(gesZahl);
}

void rate(int gesZahl) {
    int guess = 1;
    while (guess != 0) {
        int eingabe = 0;
        scanf("%d", &eingabe);
        if (eingabe == gesZahl) {
            printf("Richtig!\n");
            guess = 0;
        }
        if (eingabe < gesZahl) {
            printf("Die ist zu klein!\n");
        } else {
            printf("Die ist zu gross!\n");
        }
    }
}