/*******************************************************************
/ Programm    : Bruchrechnung                                         
/ Verfasser   : Schmidt                                           
/ Datum       : Urprogramm: 24.10.2012                                          
/ Eingabe     : 2 rationale Zahlen                          
/ Verarbeitung: diverse Berechnungen                   
/ �nderungen  : 24.10.2012
/ *******************************************************************/

/* Einbinden von noetigen Header-Dateien                             */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. fuer system       */
#include "brueche.h"

int ggT(int a, int b) {
    int r;
    if (a == 0) return abs(b);
    if (b == 0) return abs(a);
    do {
        r = a % b;
        a = b;
        b = r;
    } while (b != 0);

    return abs(a);
}

int kgV(int a, int b) {
    //TODO Implement KGV -> Then rework berechne() with subfunctions
}

int main() {
    struct bruch_s bruchEins;
    bruchEins.nenner = 0;
    bruchEins.zaehler = 1;
    struct bruch_s bruchZwei;
    bruchZwei.zaehler = 0;
    bruchZwei.nenner = 1;

    readInput(&bruchEins, &bruchZwei);
    printf("===== Ausgabe ===== \n");
    //printf("ggT von %d und %d ist: %d", bruchEins.zaehler, bruchEins.nenner, ggT(bruchEins.zaehler, bruchEins.nenner));
    berechnung(&bruchEins, &bruchZwei);

    return (0);
}

void berechnung(struct bruch_s *bruchEins, struct bruch_s *bruchZwei) {
    struct bruch_s zwi;
    zwi = multiply(&*bruchEins, &*bruchZwei);
    printf("%d/%d * %d/%d = %d/%d\n", bruchEins->zaehler, bruchEins->nenner, bruchZwei->zaehler, bruchZwei->nenner,
           zwi.zaehler, zwi.nenner);
    zwi = divide(&*bruchEins, &*bruchZwei);
    printf("%d/%d / %d/%d = %d/%d\n", bruchEins->zaehler, bruchEins->nenner, bruchZwei->zaehler, bruchZwei->nenner,
           zwi.zaehler, zwi.nenner);
    zwi = sum(&*bruchEins, &*bruchZwei);
    printf("%d/%d + %d/%d = %d/%d\n", bruchEins->zaehler, bruchEins->nenner, bruchZwei->zaehler, bruchZwei->nenner,
           zwi.zaehler, zwi.nenner);
    zwi = subtract(&*bruchEins, &*bruchZwei);
    printf("%d/%d - %d/%d = %d/%d\n", bruchEins->zaehler, bruchEins->nenner, bruchZwei->zaehler, bruchZwei->nenner,
           zwi.zaehler, zwi.nenner);
}

void readInput(struct bruch_s *bruch1, struct bruch_s *bruch2) {
    printf("Getestet fuer: \nGib Bruch 1 ein: 1 3 \nund Bruch 2: -2 3\n\n");
    printf("Bitte Zaehler und Nenner Bruch 1 eingeben: ");
    scanf("%d ", &(bruch1->zaehler));
    scanf("%d", &(bruch1->nenner));
    while (bruch1->nenner == 0) {
        printf("Nenner muss > 0 sein! \nBitte Zaehler und Nenner Bruch 1 eingeben: ");
        scanf("%d ", &(bruch1->zaehler));
        scanf("%d", &(bruch1->nenner));
    }
    printf("1. Bruch: %d/%d \n", bruch1->zaehler, bruch1->nenner);

    printf("Bitte Zaehler und Nenner Bruch 2 eingeben: ");
    scanf("%d ", &(bruch2->zaehler));
    scanf("%d", &(bruch2->nenner));
    while (bruch2->nenner == 0) {
        printf("Nenner muss > 0 sein! \nBitte Zaehler und Nenner Bruch 2 eingeben: ");
        scanf("%d ", &(bruch2->zaehler));
        scanf("%d", &(bruch2->nenner));
    }
    printf("2. Bruch: %d/%d \n", bruch2->zaehler, bruch2->nenner);
}

struct bruch_s sum(struct bruch_s *bruch1, struct bruch_s *bruch2) {
    struct bruch_s newFraction;
    newFraction.nenner = (bruch1->nenner) * (bruch2->nenner);
    newFraction.zaehler = (bruch1->zaehler + bruch2->zaehler) * bruch1->nenner;
    int ggt = ggT(newFraction.nenner, newFraction.zaehler);
    newFraction.nenner = newFraction.nenner / ggt;
    newFraction.zaehler = newFraction.zaehler / ggt;
    return newFraction;
}

struct bruch_s subtract(struct bruch_s *bruch1, struct bruch_s *bruch2) {
    struct bruch_s newFraction;
    newFraction.zaehler = bruch1->zaehler - bruch2->zaehler;
    newFraction.nenner = bruch1->nenner;
    int ggt = ggT(newFraction.nenner, newFraction.zaehler);
    newFraction.nenner = newFraction.nenner / ggt;
    newFraction.zaehler = newFraction.zaehler / ggt;
    return newFraction;
}

struct bruch_s multiply(struct bruch_s *bruch1, struct bruch_s *bruch2) {
    struct bruch_s newFraction;
    newFraction.zaehler = (bruch1->zaehler) * (bruch2->zaehler);
    newFraction.nenner = (bruch1->nenner) * (bruch2->nenner);
    int ggt = ggT(newFraction.nenner, newFraction.zaehler);
    newFraction.nenner = newFraction.nenner / ggt;
    newFraction.zaehler = newFraction.zaehler / ggt;
    return newFraction;
}

struct bruch_s divide(struct bruch_s *bruch1, struct bruch_s *bruch2) {
    struct bruch_s newFraction;
    struct bruch_s inversed;
    inversed.zaehler = bruch2->nenner;
    inversed.nenner = bruch2->zaehler;
    newFraction.zaehler = bruch1->zaehler / bruch2->zaehler;
    newFraction.nenner = (bruch1->nenner) * (bruch2->nenner);
    int ggt = ggT(newFraction.nenner, newFraction.zaehler);
    newFraction.nenner = newFraction.nenner / ggt;
    newFraction.zaehler = newFraction.zaehler / ggt;
    return multiply(&*bruch1, &inversed);
}

