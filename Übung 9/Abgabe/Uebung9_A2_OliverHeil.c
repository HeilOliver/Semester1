/*
 * uebung9_a2.c
 *
 *  Created on: 16.01.2017
 *      Author: Oliver H
 * Description: Pointer Test Aufgabe C
 */

// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>



// ************************************************************************************
// MAIN					-	Consolen ausgabe
// ************************************************************************************
int main(int argc, char* argv[]) {
	int i = 1234, k = 5678;
	int* pl = NULL;
	printf("Adresse pl = %p\tWert von pl = -\t\tWert von i = %d\tWert von k = %d\n",pl,i,k);	// Pointer Wert hardcoded da sonst Probleme bei wertabruf an adresse 0

	pl = &i;
	printf("Adresse pl = %p\tWert von pl = %d\tWert von i = %d\tWert von k = %d\n",pl,*pl,i,k);

	*pl = 2323;
	printf("Adresse pl = %p\tWert von pl = %d\tWert von i = %d\tWert von k = %d\n",pl,*pl,i,k);

	++*pl;
	printf("Adresse pl = %p\tWert von pl = %d\tWert von i = %d\tWert von k = %d\n",pl,*pl,i,k);

	pl = &k;
	printf("Adresse pl = %p\tWert von pl = %d\tWert von i = %d\tWert von k = %d\n",pl,*pl,i,k);

	return 0;
}
