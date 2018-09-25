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
void equity(int, int, int);


int main(int argc, char* argv[]) {
	// ------------- Declare variables ----------------------------------------------
	int test0[3] = {1000,100,5};
	int test1[3] = {0,1,5};
	int test2[3] = {1000,0,5};
	int test3[3] = {1000,1,0};

	// ------------- Here is where the Magic happens ---------------------------------
	equity(test0[0],test0[1],test0[2]);
	printf("\n\n");
	equity(test1[0],test1[1],test1[2]);
	printf("\n\n");
	equity(test2[0],test2[1],test2[2]);
	printf("\n\n");
	equity(test3[0],test3[1],test3[2]);



	return 0;
}

void equity(int fortune, int interest_rate, int year) {
	printf(	"Kapitalentwicklung für Grundkapital: %d EUR\n"
			"Fixzinssatz: %d%%, Laufzeit %d Jahre"
			"\n\n\nJahr \t\tKapital\n-------------------------\n"
			, fortune, interest_rate,year);

	for(int i=1; i<= year; i++) {
		fortune += (fortune * interest_rate) / 100;
		printf("%d \t\t%d\n",i, fortune);
	}
}



