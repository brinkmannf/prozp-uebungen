/*******************************************************************
 * Expected Behavior example with "L A Z B" input
    ** Begin Snipped

    Bitte geben Sie vier einzelne Zeichen ein: L A Z B
    Eingegeben wurden: L A Z B
    ASCII Codes: 76 65 90 66
    ASCII Code (Mittel,int): 74
    ASCII Code (Mittel,int): 4a
    ASCII Code (Mittel,fl): 74.250000
    "Mittleres" Zeichen: J
    Kleinstes Zeichen: A
    Groesstes Zeichen: Z
    Abstand Max/Min: 25 Zeichen

    ** End Snipped
/*******************************************************************/

/* Einbinden von noetigen Header-Dateien */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. f�r system */

char kleinstesZeichen(char Zeichen[]);

char groesstesZeichen(char Zeichen[]);

void readLine(char Eingabespeicher[]);

void extractChars(char Source[], char Sorted[]);

void printAscii(char Input[]);

int main() {
    char Eingabe[8]; //Pure Eingabe
    char ZeichenAsInt[5]; //Speicher für extrahierte und in int gewandelte Buchstaben aus Eingabe
    readLine(&Eingabe);
    extractChars(&Eingabe, &ZeichenAsInt);
    printf("Eingegeben wurden: %s \n", Eingabe);
    printAscii(&ZeichenAsInt);
    int min = kleinstesZeichen(&ZeichenAsInt);
    int max = groesstesZeichen(&ZeichenAsInt);
    printf("Kleinstes Zeichen: %c \n", min);
    printf("Groesstes Zeichen: %c \n", max);
    printf("Abstand Max/Min: %d Zeichen\n", (max - min));
    return (0);
}


void readLine(char Eingabespeicher[]) {
    printf("Bitte geben Sie vier einzelne Zeichen ein: ");
    fgets(Eingabespeicher, 8, stdin); // fgets statt scanf, da bei scanf nach einem Leerzeichen schluss ist
}

void printAscii(char Input[]) {
    int _0 = Input[0];
    int _1 = Input[1];
    int _2 = Input[2];
    int _3 = Input[3];
    float mittel = ((float) (_0 + _1 + _2 + _3)) / (float) 4;
    printf("ASCII Codes: %d %d %d %d \n", _0, _1, _2, _3);
    printf("ASCII Code (Mittel,int): %d \n", (int) mittel);
    printf("ASCII Code (Mittel,int): %x \n", (int) mittel);
    printf("ASCII Code (Mittel,fl): %f \n", mittel);
    printf("\"Mittleres\" Zeichen: %c \n", (int) mittel);
}

void extractChars(char Source[], char Sorted[]) {
    int inc = 0; // Wird verwendet, um im Sorted Array zu iterieren
    for (int i = 0; i < 7; i++) {
        int charId = (int) Source[i];
        if (charId != 32) {
            Sorted[inc] = (int) Source[i];
            inc++;
        }
    }
    Sorted[5] = '\0'; //Nullterminierung
}

char kleinstesZeichen(char Zeichen[]) {
    int min = Zeichen[0];
    for (int i = 1; i < 4; ++i) {
        if (Zeichen[i] < min) {
            min = Zeichen[i];
        }
    }
    return (char) min;
}

char groesstesZeichen(char Zeichen[]) {
    int max = Zeichen[0];
    for (int i = 1; i < 4; ++i) {
        if (Zeichen[i] > max) {
            max = Zeichen[i];
        }
    }
    return (char) max;
}

