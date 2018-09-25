/*
 * main.c
 *
 *  Created on: 09.11.2016
 *      Author: Oliver H
 */
#include <stdio.h>



int main(void) {
	int arr[] = {1,-4,3,5,-1};
	int arr_length = sizeof(arr) / sizeof(int);

	int validcounter = 0;

	printf("i|n|arr[i]|Überprüfung|Befehl \n");
	printf("0|0|1|i< arr_length|-\n");
	for (int i = 0, n= 0; i< arr_length; i++) {
		printf("%d|%d|%d|true|-\n",i,n,arr[i]);
		printf("%d|%d|%d|arr[i] >= 0|-\n",i,n,arr[i]);
		if (arr[i] >= 0) {
			printf("%d|%d|%d|true|-\n",i,n,arr[i]);
			arr[n] = arr[i];
			n++;
			validcounter++;
			printf("%d|%d|%d|-|n++, arr[n]=arr[i]\n",i,n,arr[i]);
		} else {
			printf("%d|%d|%d|false|-\n",i,n,arr[i]);
		}
		printf("%d|%d|%d|i< arr_length|i++\n",i,n,arr[i]);
	}




	return 0;
}
