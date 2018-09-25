/*
 * uebung7_a1.c
 *
 *  Created on: 26 Nov 2016
 *      Author: Oliver Heil
 * Description: Zinsrechnung
 */

// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>


// ------------- Forward declaration ------------------------------------------------
void equity(unsigned long, int, int);


int main(int argc, char* argv[]) {
	// ------------- Declare variables ----------------------------------------------
	int test0[3] = {1000,1000,1000};


	// ------------- Here is where the Magic happens ---------------------------------
	equity(test0[0],test0[1],test0[2]);


	return 0;
}

void equity(unsigned long fortune, int interest_rate, int year) {
	printf(	"Kapitalentwicklung für Grundkapital: %lu Cent\n"
			"Fixzinssatz: %d%%, Laufzeit %d Jahre"
			"\n\n\nJahr \t\tKapital\n-------------------------\n"
			, fortune, interest_rate,year);

	for(int i=1; i<= year; i++) {
		fortune += (fortune * interest_rate) / 100;
		printf("%d \t\t%lu\n",i, fortune);
	}
}



