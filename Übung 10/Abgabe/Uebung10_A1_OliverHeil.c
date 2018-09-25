/*
 * uebung10_a1.c
 *
 *  Created on: 20 JAN 2017
 *      Author: Oliver Heil
 * Description: Zeichenkette kopieren mit dynamischem Speicher
 */


// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// ------------- Forward declaration ------------------------------------------------
char* strDuplicate(const char*);


// ************************************************************************************
// MAIN					-	Consolen ausgabe
// ************************************************************************************
int main(int argc, char* argv[]) {
	char* strToCopy = "Hallo ich bin ein Test";			// Stellt den ersten String bereit
	char* newString =  strDuplicate(strToCopy);			// Stellt den String im heap bereit
	if (newString == NULL) {							// Falls ein Fehler aufgetreten ist
		return 1;
	}

														// Ausgabe der beiden Texte
	printf("%s \n",strToCopy);
	printf("%s \n",newString);


	free(newString);									// gib dem Heap wieder frei
	return 0;
}


// ************************************************************************************
// strDuplicate			-	Kopiert einen String in den Heap und gibt dessen Adresse zurück
// ************************************************************************************
char* strDuplicate(const char * pSrc) {
	unsigned int length = 0;
	char* newString;
	while (pSrc[length] != '\0') {						// Wie lang ist der String?
		length++;
	}

	length++;											// +1 für '\0'
	newString = (char*) malloc(sizeof(char)*(length));	// Lege neuen Speicher im heap an
	if (newString == NULL) {
		return NULL;
	}

	for (int i = 0; i < length; i++) {					// Kopiere alles vom Alten in neuen Speicher
		newString[i] = pSrc[i];
	}
	//memcpy((void*) newString,(void*) pSrc, sizeof(char)*(length+1));

	return newString;
}
