/*
 * uebung7_a2.c
 *
 *  Created on: 14 Dec 2016
 *      Author: Oliver Heil
 * Description: Arithmetisches Mittel + Ausreisser
 */

// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>


// ------------- Forward declaration ------------------------------------------------
void arrMitwAus(int*,const int);


int main(int argc, char* argv[]) {
	// ------------- Declare variables ----------------------------------------------
	int values[] = { 3, 5, 7, 8, 1, -1, 4, 0 };
	int values_length = 8;

//	int values[] = { 3, 5, 7, 8 };
//	int values_length = 4;
//
//	int values[] = { -10 };
//	int values_length = 1;
//
//	int values[] = { };
//	int values_length = 0;
//
//	int values[] = { -3, -4, -5, -234521, 5, 4 };
//	int values_length = 6;

	// ------------- Here is where the Magic happens ---------------------------------
	arrMitwAus(values, values_length);


	return 0;
}

void arrMitwAus(int *values, const int length) {
	int min = values[0];
	int max = values[0];
	int arr = 0;

	for (int i = 0; i < length; i++) {
		if (min > values[i]) {
			min = values[i];
		}
		if (max < values[i]) {
			max = values[i];
		}
		arr += values[i];
	}
	arr = arr / length;
	printf("Min: %d\tMax: %d\tAvr: %d",min,max,arr);
}




