/*
 * uebung10_a2.c
 *
 *  Created on: 20 JAN 2017
 *      Author: Oliver Heil
 * Description: Wortlängenstatistik
 */


// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// ------------- Global Variablen ---------------------------------------------------
struct word_length_statistik_struct {
	char* text;
	unsigned int word_length[512];
	char* word_adr[512];
	unsigned int words;
} wlss;


// ------------- Forward declaration ------------------------------------------------
void WordLengthStatistik_fill(struct word_length_statistik_struct *str_ptr);
void WordLengthStatistik_print(struct word_length_statistik_struct *str_ptr);
void WordLengthStatistik_printWort(struct word_length_statistik_struct *str_ptr, unsigned int wordindex);



// ************************************************************************************
// MAIN
// ************************************************************************************
int main(int argc, char* argv[]) {
	char Mytext[512] = "Hallo das ist ein sehr langer String und ich moechte sicher gehen das er reicht ";

	wlss.text = (void*) &Mytext;
	WordLengthStatistik_fill(&wlss);
	WordLengthStatistik_print(&wlss);


	return 0;
}


// ************************************************************************************
// WordLengthStatistik_fill			- Füllt den word_length_statistik_struct mit Wortlängen und Adressen der Wörter
// ************************************************************************************
void WordLengthStatistik_fill(struct word_length_statistik_struct *str_ptr) {
	unsigned int curr_pos = 0;
	unsigned int newWord = 0;
	char curr_char;
	(*str_ptr).words = 0;											// setze zu anfang alles null

	while ((*str_ptr).text[curr_pos] != '\0') {						// Bis ich das ende gefunden habe
		curr_char = (*str_ptr).text[curr_pos];
		if ((curr_char >= 'A' && curr_char <= 'Z') || (curr_char >= 'a' && curr_char <= 'z')) {	// Falls ein Wort gefunden wurde
			if (newWord != 0) {										// Falls es kein Wortanfang ist
				(*str_ptr).word_length[(*str_ptr).words] += 1;		// Erhöhe wortlänge
			} else {												// Falls es ein Wortanfang ist
				newWord = 1;										// sonst lege es neu an
				(*str_ptr).word_length[(*str_ptr).words] = 0;
				(*str_ptr).word_adr[(*str_ptr).words] = &(*str_ptr).text[curr_pos];
				(*str_ptr).word_length[(*str_ptr).words] += 1;
			}

		} else {													// Falls es kein Wort ist
			if ((*str_ptr).word_length[(*str_ptr).words] != 0) {	// Springe zum nächsten Wort
				newWord = 0;
				(*str_ptr).words += 1;
			}
		}
		curr_pos++;
	}
	if (newWord == 1) {
		(*str_ptr).words += 1;
	}
}


// ************************************************************************************
// WordLengthStatistik_print		- Gibt den word_length_statistik_struct in der Console aus
// ************************************************************************************
void WordLengthStatistik_print(struct word_length_statistik_struct *str_ptr) {
	unsigned int words_printed = 0;
	unsigned int curr_length = 1;

	printf("Original Text:\n %s\n\n",(*str_ptr).text);

	while (words_printed < (*str_ptr).words) {						// Bis es nix mehr zum anzeigen gibt
		for(int i = 0; i < (*str_ptr).words; i++) {					// Bis ich alles angeschaut habe
			if ((*str_ptr).word_length[i] == curr_length) {
				printf("Word: ");
				WordLengthStatistik_printWort(&wlss,i);				// Gibt nur das Wart aus
				printf("\tLength: %d\n", curr_length);
				words_printed++;
			}
		}
		curr_length++;
	}
}


// ************************************************************************************
// WordLengthStatistik_printWort	- Gibt ein Wort anhand seines indexes und länge auf der console aus
// ************************************************************************************
void WordLengthStatistik_printWort(struct word_length_statistik_struct *str_ptr, unsigned int wordindex) {
	char* word_adr = (*str_ptr).word_adr[wordindex];
	unsigned int word_length = (*str_ptr).word_length[wordindex];

	for(unsigned int i = 0; i < word_length; i++) {					// Gibt jeden Char einzeln aus
		printf("%c",word_adr[i]);
	}

}
