/*
 * main.c
 *
 *  Created on: 09.11.2016
 *      Author: Oliver H
 */

#include <stdio.h>
int searchformissingnumber(int numbers[], int lengthofnumbers);

#define true 1
#define false 0


int main(void) {
	int arr[] = {7,3,9,5,6,4,2,1,0};			// Hier das Array abändern
	int result = -1;

	result = searchformissingnumber(arr,sizeof(arr)/sizeof(int));
	printf("Die fehlende Zahl lautet: %d \n",result);

	return 0;
}

int searchformissingnumber(int numbers[], int lengthofnumbers) {
	int numtrue = false;

	for (int num = 0; num <= lengthofnumbers; num++) {
		numtrue = false;
		for(int n = 0; n < lengthofnumbers && numtrue == false; n++ ) {
			if (numbers[n]==num) {
				numtrue = true;
			}
		}
		if (numtrue == false) {
			return num;
		}
	}
	return -1;
}
