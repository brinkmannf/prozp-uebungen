/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Aenderungen  : 07.12.2020 - Felix Brinkmann
*******************************************************************/

/*
 * Erwartete Anzahl Primzahlen für jeweilige OBERGRENZE:
 *
 * OBERGRENZE -> ANZAHL
 *
 * 100 -> 25
 * 1000 -> 169
 * 10000 -> 1229
 * 100000 -> 9592
 * 1000000 -> 78498
 *
 */

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. fuer system */
#include <math.h>
#include "funktionen.c"

void sieb(int *prim, int size);

void ausgabe(int *prim, int size);

int main() {
    strich(50, '-');
    printf("Sieb des Eratosthenes\n");
    strich(50, '-');
    int size = 0;
    char again[2];
    int *primArray = NULL;
    int *primArrayStart = NULL;

    do {
        printf("\nBis welche Zahl soll gesiebt werden: ");
        scanf("%d", &size);
        while (size >= 1500000) {
            printf("Zahl muss < 1500000 sein: ");
            scanf("%d", &size);
        }
        primArray = (int *) malloc(size * sizeof(int));
        primArrayStart = primArray;

        if (primArray != NULL) {
            sieb(primArray, size);
            primArray = primArrayStart;
            ausgabe(primArray, size);
        } else {
            printf("Es konnte kein Speicherplatz reserviert werden!\n");
            return 0;
        }
        free(primArray);
        primArray = NULL;
        primArrayStart = NULL;

        printf("Erneut starten? y/n: ");
        scanf("%s", &again);

    } while (again[0] == 'y' || again[0] == 'Y');

    printf("\nServus! \n");
    return 0;
}

void ausgabe(int *prim, int size) {
    int anzahl = 1;
    for (int i = 0; i < size; ++i) {
        if ((anzahl % 10) == NICHT_PRIM && prim[i] == PRIM) {
            printf("%d,\n", i);
            anzahl++;
        } else if (prim[i] == PRIM) {
            printf("%d, ", i);
            anzahl++;
        }
    }
    printf("\nEs wurden %d Primzahlen bis %d gefunden!\n", anzahl - 1, size);
}

void sieb(int *prim, int arrSize) {
    int max = sqrt(arrSize);
    for (int i = 0; i < arrSize; i++) {
        if (i == NICHT_PRIM || i == PRIM) {
            prim[i] = NICHT_PRIM;
        } else {
            prim[i] = PRIM;
        }
    }
    for (int i = 2; i < max; ++i) {
        if (prim[i] == PRIM) {
            for (int j = 2; j < arrSize; ++j) {
                int mult = i * j;
                if (mult <= arrSize) {
                    prim[mult] = NICHT_PRIM;
                }
            }
        }
    }
}