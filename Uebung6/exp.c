/*******************************************************************
// Programm    : exp1                                                
// Verfasser   : Feindor/Schmidt                                             
// Datum       : Urprogramm: 1.10.1996                                           
// Eingabe     : obere und untere Grenzen                            
// Verarbeitung: Berechnung von Funktionen, Zählen, Summieren
// Ausgabe     : Zahlentabellen                                      
// Änderungen  : 30.10.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>   /* Standard-Bibliothek f�r math. Funktionen  z.B. sqrt */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. f�r system       */
#include "exp.h"


int main() {
    strich(50, '-');
    printf("Exp: Berechnung von einfachen Funktionen\n");
    strich(50, '-');
    int grenze;
    readInput(&grenze);
    strich(75, '-');
    tabelleAusgeben(grenze);
    printf("Servus! \n");
    system("pause");
    return 0;
}

void tabelleAusgeben(int grenze) {
    double summeEinsDurchI = 0;
    double euler = 1;
    printf("   i   1/i Summe(1/i)                   i!            1/i!      Naeherung e \n");
    strich(75, '-');
    for (int i = 1; i <= grenze; ++i) {
        double einsDurchI = 1.0 / (double) i;
        euler = euler + (1.0 / fakultaet(i));
        summeEinsDurchI = summeEinsDurchI + einsDurchI;
        printf("%4d %0.4f %2.7f %19.0f  %0.14f  %0.12f \n", i, einsDurchI, summeEinsDurchI, fakultaet(i),
               1.0 / fakultaet(i), euler);
    }
}

double fakultaet(double i) {
    double fak = 1;
    for (int j = 1; j <= i; ++j) {
        fak = fak * (double) j;
    }
    return fak;
}

void readInput(int *grenze) {
    printf("Bitte positive obere Grenze eingeben (ganzzahlig <= 20): ");
    scanf("%d", &*grenze);
    while (*grenze > 20 || *grenze < 1) {
        printf("Grenze kleiner <= 20! Bitte neue Grenze: ");
        scanf("%d", &*grenze);
    }
}

/* gibt n mal das Zeichen c aus */
void strich(int n, char c) {
    int i;
    for (i = 1; i <= n; i++)
        printf("%c", c);
    printf("\n");
}