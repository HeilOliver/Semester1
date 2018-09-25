/*
 * uebung9_a1.c
 *
 *  Created on: 15 JAN 2017
 *      Author: Oliver Heil
 * Description: Dreiecksmatrix
 */


// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>



// ------------- Forward declaration ------------------------------------------------
unsigned int getRows(unsigned int);
unsigned int** getTriangelArr (unsigned int, unsigned int);
void freeTriangelArr(unsigned int**,unsigned int);


// ************************************************************************************
// MAIN					-	Consolen ausgabe
// ************************************************************************************
int main(int argc, char* argv[]) {
	unsigned int number = 22;					// Gibt die Zahl an bis wohin gefüllt werden soll
	unsigned int rows = getRows(number);		// Gibt die Anzahl der Benötigten Zeilen an
	unsigned int fields_left = number / 2;		// Gibt die Anzahl der Felder an die noch befüllt werden müssen

	unsigned int** T_Arr	= getTriangelArr(number, rows);
	if (T_Arr == NULL) {						// Falls ein fehler aufgetreten ist :(
		printf("Speicher Problem!");
		return 1;
	}

	for (unsigned int row = 0; row < rows; row++) {		// Gibt die Matrix Reihenweise aus
		for (unsigned int column = 0; column <= row && fields_left > 0; ++column) {
			printf("%d ",T_Arr[row][column]);
			fields_left -= 1;
		}
		printf("\n");
	}

	freeTriangelArr(T_Arr, rows);				// Gibt den Speicherplatz wieder frei

	return 0;
}


// ************************************************************************************
// getRows				-	Gibt die Anzahl der Zeilen zurück die benötigt werden
// ************************************************************************************
unsigned int getRows(unsigned int number) {
	int fields_left = number / 2;				// Gibt die Anzahl der Felder an die noch befüllt werden müssen
	unsigned int rows = 0;

	while (fields_left > 0) {					// Rechnet die Reihen aus
		++rows;
		fields_left -= rows;
	}
	return rows;
}


// ************************************************************************************
// freeTriangelArr		-	Gibt den Allocierten Speicherplatz wieder frei
// ************************************************************************************
void freeTriangelArr(unsigned int** T_Arr_toFree,unsigned int rows) {
	for (unsigned int row = 0; row < rows; row++) {
		free(T_Arr_toFree[row]);				// Befreie jede einselne Zeile einzeln
	}
	free(T_Arr_toFree);							// Befreie alle Spalten
}


// ************************************************************************************
// getTriangelArr		-	Erstellt eine Dreiecksmatrix mit Malloc
// ************************************************************************************
unsigned int** getTriangelArr (unsigned int number, unsigned int rows) {
	unsigned int curr_number = 1;
	unsigned int fields_left = number / 2;

	unsigned int** p_arr = (unsigned int**) malloc(sizeof(unsigned int*) * rows);	// Erstelle das Pointer Array
	if(NULL == p_arr){ 							// Überprüfe ob eine Adresse da ist
			return NULL;
	}

	for (unsigned int row = 0; row < rows; row++) {		// Fülle nun die Dreiecksmatrix und lege die Speicherplätze an
		if (fields_left > (row+1)) {
			p_arr[row] = (unsigned int*) malloc(sizeof(unsigned int)*(row+1));		// Falls alle plätze gebraucht werden
		} else {
			p_arr[row] = (unsigned int*) malloc(sizeof(unsigned int)*fields_left);	// Falls weniger plätze gebraucht werden (am Ende)
		}
		if(NULL == p_arr[row]){ 				// Überprüfe ob die Adresse da ist
			freeTriangelArr(p_arr, row);		// Falls weitergearbeitet werden soll /will :D
			return NULL;
		}

		for (unsigned int column = 0; column <= row && fields_left > 0; ++column) {
			p_arr[row][column] = curr_number;	// Fülle die einzelnen Plätze im neu generiertem Platz
			curr_number += 2;
			fields_left -= 1;
		}
	}
	return p_arr;								// Gebe die Adresse zurück
}
