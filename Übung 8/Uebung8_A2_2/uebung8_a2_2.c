/*
 * uebung8_a2_2.c
 *
 *  Created on: 20 Dec 2016
 *      Author: Oliver Heil
 * Description: Suche nach einer Teilzeichenkette nach Boyer-Moore-Horspool Algorithm
 */

// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// ------------- Forward declaration ------------------------------------------------
int getlength(char*);
int getPatterninString(char*,char*);

// ------------- MAIN ---------------------------------------------------------------
int main (int argc, char* argv[]) {
	char string[] = "Fischers Fritz fischt frische Fische, frische Fische fischt Fischers Fritz";
	char pattern[] = "isch";
	if(getPatterninString(string,pattern)){
		printf("DA IST WAS KAPUTT\n");
	}


	return 0;
}

// ------------- GET LENGTH ---------------------------------------------------------
int getlength(char* text) {
	int length = 0;

	while (text[length] != '\0')  {
		++length;
	}
	return length;
}

// ------------- getPatterninString -------------------------------------------------
int getPatterninString(char* string,char* pattern) {
	char* pat_str = pattern;		// Pattern String
	char* txt_str = string; 		// Text String

	int pat_str_length = getlength(pat_str);
	int txt_str_length = getlength(txt_str);

	char* pat_tbl_chr = NULL;		// Char
	char* pat_tbl_jmp = NULL;		// Jump to Char
	int pat_tbl_length = 0; 		// Table Length

	pat_tbl_chr = (char*) malloc(sizeof(char));	// Speicher allokieren
	pat_tbl_jmp = (char*) malloc(sizeof(char)); // Ein char groß
	if(NULL == pat_tbl_chr || NULL == pat_tbl_jmp){ // Überprüfe ob eine Adresse da ist
		return -1;
	}


	// ************************************************************************************
	// START OF TABLE CREATION
	// ************************************************************************************

	int pat_str_pos = 0;
	int pat_tbl_pos = 0;
	int tbl_found = 0;

	while (pat_str_pos < pat_str_length) {
		tbl_found = 0;
		pat_tbl_pos = 0;
		while(pat_tbl_pos < pat_tbl_length && tbl_found == 0) { //Schaue ob char schon in Tabelle vorhanden ist
			if(pat_str[pat_str_pos] == pat_tbl_chr[pat_tbl_pos]) {
				tbl_found = 1;
			} else {
				++pat_tbl_pos;
			}
		}
		if (tbl_found == 1) {	// Gibt mich schon
			if((pat_str_pos+1) < pat_str_length) {
				pat_tbl_jmp[pat_tbl_pos] = pat_str_length - pat_str_pos - 1; // New Jump
			} else {
				pat_tbl_jmp[pat_tbl_pos] = pat_str_length;	// Last Char :D =pattern length
			}
		} else {	// Gibt mich nicht
			++pat_tbl_length;
			pat_tbl_chr = (char*) realloc(pat_tbl_chr ,sizeof(char)*pat_tbl_length); // Reallokiere Speicher mit neuer Größe
			pat_tbl_jmp = (char*) realloc(pat_tbl_jmp ,sizeof(char)*pat_tbl_length);
			if(NULL == pat_tbl_chr || NULL == pat_tbl_jmp){ // Überprüfe ob eine Adresse da ist
				return -1;
			} else {
				pat_tbl_chr[pat_tbl_length -1] = pat_str[pat_str_pos]; // Trage char ein
				pat_tbl_jmp[pat_tbl_length -1] = pat_str_length - pat_str_pos - 1; // Trage jump ein
			}
		}
		++pat_str_pos; // Nächste Position
	}

//	printf("Length of String: %d\n",txt_str_length);
//	printf("Length of Pattern: %d\n\n",pat_str_length);
//
//	printf("Adress of CHR-TBL: %p\n",pat_tbl_chr);
//	printf("Adress of JMP-TBL: %p\n",pat_tbl_jmp);
//	printf("Length of Table: %d\n",pat_tbl_length);
//	printf("----TABLE-------------------\n");
//	for(int i = 0; i < pat_tbl_length; i++) {
//		printf(" %c ",pat_tbl_chr[i]);
//	}
//	printf("\n");
//	for(int i = 0; i < pat_tbl_length; i++) {
//		printf(" %d ",pat_tbl_jmp[i]);
//	}
//	printf("\n");

	// ************************************************************************************
	// END OF TABLE CREATION
	// ************************************************************************************

	int txt_str_pointer = pat_str_length-1;
	int pat_str_pointer = pat_str_length-1;
	int matchcounter = 0;
	int pointerOffset = 0;
	int nextShift = 0;
	int matchfound = 1;

	printf("Hier hab ich was gefunden:\n");

	while (txt_str_pointer < txt_str_length) {
		pointerOffset = 0;
		matchfound = 1;
		while(pointerOffset < pat_str_length && matchfound == 1) {	// Gleiche Pattern mit String ab
			if (txt_str[txt_str_pointer - pointerOffset] != pat_str[pat_str_pointer - pointerOffset]){	// Falls Char von String ungleich Char Pattern
				matchfound = 0;
			} else { // Passt alles
				++pointerOffset;
			}
		}
		if(matchfound == 1) {
			// Hurra wir haben ein Muster gefunden
			++matchcounter;
			printf(" %d ",txt_str_pointer - pat_str_pointer);
			txt_str_pointer += pat_str_length;
		} else {
			// Leider nicht :(
			nextShift = pat_str_length;
			for(int i = 0; i <=  pat_tbl_length; i++){	// Falls char in Tabelle dann nehme diesen jump Wert
				if (pat_tbl_chr[i] == txt_str[txt_str_pointer]){
					nextShift = pat_tbl_jmp[i];
				}
			}
			txt_str_pointer += nextShift;	// Springe
		}

	}

	printf("\nIch habe %d Matches gefunden!", matchcounter);
	
	free(pat_tbl_chr);
	free(pat_tbl_jmp);
	return 0;
}



