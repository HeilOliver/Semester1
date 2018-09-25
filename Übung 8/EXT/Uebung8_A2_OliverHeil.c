/*
 * uebung8_a2.c
 *
 *  Created on: 14 Dec 2016
 *      Author: Oliver Heil
 * Description: Suche nach einer Teilzeichenkette
 */

// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>

// ------------- Forward declaration ------------------------------------------------
void getPatterninString(char*,char*);

// ------------- MAIN ---------------------------------------------------------------
int main(int argc, char* argv[]) {

	char text[] = {"Fischers Fritz fischt frische Fische, frische Fische fischt Fischers Fritz"};
	char pattern[] = {"isch"};

	getPatterninString(text,pattern);






	return 0;
}

// ------------- getPatterninString -------------------------------------------------
void getPatterninString(char* string,char* pattern) {

	int txt_pos = 0;	// Zeiger auf die Position im String
	int ptr_pos = 0;	// Position bei Überprüfung
	int ptr_found = 0;
	int matchcounter = 0;
	printf("Hier hab ich was gefunden:\n");

	while(string[txt_pos] != '\0') {
		if (string[txt_pos] == pattern[0]) {
			ptr_pos = 0;
			ptr_found = 1;
			while(pattern[ptr_pos] != '\0' && 1 == ptr_found) {
				if(pattern[ptr_pos] != string[txt_pos + ptr_pos] && '\0' != string[txt_pos + ptr_pos]) {
					ptr_found = 0;
				}
				++ptr_pos;
			}

			if (1 == ptr_found) {
				++matchcounter;
				printf(" %d ", txt_pos);
			}
		}
		txt_pos++;
	}

	printf("\nIch habe %d Matches gefunden!", matchcounter);
}
