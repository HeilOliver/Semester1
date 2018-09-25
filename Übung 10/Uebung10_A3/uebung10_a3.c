/*
 * uebung10_a2.c
 *
 *  Created on: 20 JAN 2017
 *      Author: Oliver Heil
 * Description: Rekursive Berechnung der Summe
 */


// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// ------------- Forward declaration ------------------------------------------------
unsigned int sum(unsigned int n);



// ************************************************************************************
// MAIN
// ************************************************************************************
int main(int argc, char* argv[]) {
	int n = 5;
	printf("Summe von %d = %d\n",n, sum(n));
	return 0;
}

unsigned int sum(unsigned int n) {
	if (n < 1) {
		return 0;
	} else {
		return sum(n-1) + n;
	}
}









