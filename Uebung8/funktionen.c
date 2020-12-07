/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// �nderungen  : 13.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include "funktionen.h"

void strich (int n, char c) // gibt n mal das Zeichen c aus
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}

