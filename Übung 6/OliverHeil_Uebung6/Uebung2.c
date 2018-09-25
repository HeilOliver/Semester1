/*
 * Uebung2.c
 *
 *  Created on: 16.11.2016
 *      Author: Oliver H
 * Description: Ausgabe der Quadratzahlen
 */
// ------------- Declare Includes -----------------------------------------------
#include <stdio.h>

int main(int argc, char* argv[]) {

	printf("n\t|   n^2\n-------------------\n");	// Header ausgeben
	for (int n= 1; n<=25; n++) {
	printf("%d\t|   %d\n",n,n*n);					// Ausgeben von n und n^2
	}

	return 0;
}
