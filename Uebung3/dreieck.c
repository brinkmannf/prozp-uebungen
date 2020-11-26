//*******************************************************************
// Programm    : Dreieck                                          
// Verfasser   : Schmidt                                           
// Datum       : Urprogramm: 11.10.2012                                          
// Eingabe     : Seite + Winkel eines rechtwinkligen Dreiecks                            
// Verarbeitung: Berechnung aller Seiten und Winkel                   
// Ausgabe     : Ergebnis als Tabelle
// �nderungen  : 11.10.2012
//*******************************************************************

// Einbinden von noetigen Header-Dateien
#include <stdio.h>    // Standard Input/ Output  z.B. scanf, printf
#include <stdlib.h>   // Standard-Bibliothek, z.B. fuer system
#include <math.h>     // Standard-Bibliothek fuer math. Funktionen z.B. sqrt
#include "dreieck.h" // eigene Header-Datei mit Funktionsprototypen

int main() // Beginn Hauptprogramm          **************************
{
    // Aufgabe: Dreieck
    dreieck();

    // system("pause");
    return (0);
} //***************** Ende Hauptprogramm ***************************

// Definition der benoetigten Funktionen

void dreieck(void) {
    double a;
    double b, c;  // Seitenlaenge von Seite a
    double alpha_deg, beta_deg, gamma_deg;  // Winkel in Grad
    //double alpha_rad,beta_rad,gamma_rad; //Winkel in Bogenmaß
    int ret = 1; //Um eingabe bei Scanf zu überprüfen

    // Dialogeroeffnung
    strich(50, '-');
    printf("Rechtwinkliges Dreieck\n");
    strich(50, '-');

    // Seite/Winkel einlesen
    printf("Bitte Laenge Seite a eingeben: ");
    ret = scanf("%lf", &a);
    while (a < 0 || ret == 0) {
        printf("Bitte Positive Laenge Seite a eingeben: \n");
        ret = scanf("%lf", &a);
    }

    printf("Bitte Winkel Alpha in Grad eingeben: ");
    ret = scanf("%lf", &alpha_deg);
    while (alpha_deg >= 90 || ret == 0) {
        printf("Bitte Winkel Alpha kleiner 90 in Grad eingeben: ");
        ret = scanf("%lf", &alpha_deg);
    }

    // Berechnung aller Seiten und Winkel
    // speichern aller Ergebnisse in einer neuen Variablen
    gamma_deg = 90.0; // Konstante (immer 90°)
    beta_deg = 180.0 - gamma_deg - alpha_deg;
    b = a / tan(deg2rad(alpha_deg));
    c = sqrt(pow(a, 2) + pow(b, 2));

    // abrunden aller Seiten auf die naechste ganze Zahl
    // aufrunden aller Seiten auf die naechste ganze Zahl
    // (korrektes) runden aller Seiten auf die naechste ganze Zahl
    // Ausgabe aller Seiten und Winkel
    printf("       2 NK-Stellen   gerundet   abgerundet   aufgerundet\n");
    strich(57, '-');
    printf("a        %10.2f %10.0f   %10.0f    %10.0f\n", a, round(a), floor(a), ceil(a));
    printf("b        %10.2f %10.0f   %10.0f    %10.0f\n", b, round(b), floor(b), ceil(b));
    printf("c        %10.2f %10.0f   %10.0f    %10.0f\n", c, round(c), floor(c), ceil(c));

    printf("Alpha (Grad) %7.2f\n"
           "Beta  (Grad) %7.2f\n"
           "Gamma (Grad) %7.2f\n"
           "Alpha (rad) %8.3f\n"
           "Beta  (rad) %8.3f\n"
           "Gamma (rad) %8.3f\n",
           alpha_deg, beta_deg, gamma_deg, deg2rad(alpha_deg), deg2rad(beta_deg), deg2rad(gamma_deg));
}

// Eingabe: w_deg, Winkel in Grad
// Ausgabe: w_rad, Winkel in rad
double deg2rad(double w_deg) {
    double w_rad = 0.0;
    // Grad in rad umrechnen, Ergebnis in w_rad
    w_rad = (w_deg * PI) / 180;
    return w_rad;
}

// gibt n mal das Zeichen c aus 
void strich(int n, char c) {
    int i;
    for (i = 1; i <= n; i++)
        printf("%c", c);
    printf("\n");
}
