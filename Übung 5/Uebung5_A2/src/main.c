/*
 * main.c
 *
 *  Created on: 09.11.2016
 *      Author: Oliver H
 */

#include <stdio.h>

int * mindetermination(int data[], int data_length);
int * maxdetermination(int data[], int data_length);

int main(void) {
	int arr[] = {1,3,5,4,6};
	int arr_length = sizeof(arr) / sizeof(int);

	int *min;
	int *max;

	min = mindetermination(arr, arr_length);
	max = maxdetermination(arr, arr_length);



	printf("Es gibt %d Maximas an den Stellen:", *max);
	for (int i = 1; i <= *max; i++ ){
		printf(" %d ", *(max + i));
	}
	printf("\n");

	printf("Es gibt %d Minimas an den Stellen:", *min);
	for (int i = 1; i <= *min; i++ ){
		printf(" %d ", *(min + i));
	}
	printf("\n");

	return 0;
}

int * mindetermination(int data[], int data_length){
	static int localminima[100];
	int localminima_counter = 0;

	for (int i = 1; i < data_length-1; i++) {
		if (data[i-1] > data[i] && data[i+1] > data[i]){
			localminima[localminima_counter + 1] = i;
			localminima_counter++;
		}
	}
	localminima[0] = localminima_counter;
	return localminima;
}

int * maxdetermination(int data[], int data_length){
	static int localmaxima[100];
	int localmaxima_counter = 0;

	for (int i = 1; i < data_length-1; i++) {
		if (data[i-1] < data[i] && data[i+1] < data[i]){
			localmaxima[localmaxima_counter + 1] = i;
			localmaxima_counter++;
		}
	}
	localmaxima[0] = localmaxima_counter;
	return localmaxima;
}
