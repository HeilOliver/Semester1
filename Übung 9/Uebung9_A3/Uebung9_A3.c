/*
 * uebung9_a2.c
 *
 *  Created on: 15 JAN 2017
 *      Author: Oliver Heil
 * Description: Tokenizer
 */


// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <string.h>


// ------------- Defines ------------------------------------------------------------
#define MAX_LENGTH_TEXT 100
#define MAX_LENGTH_INDEX 50
#define MAX_LENGTH_ADRES 50



// ------------- Global Variablen ---------------------------------------------------
struct WordInText {
	char text[MAX_LENGTH_TEXT];
	unsigned int index[MAX_LENGTH_INDEX];
	char* adr[MAX_LENGTH_ADRES];
	unsigned int index_words;
	unsigned int adres_words;
} WordsInText;



// ------------- Forward declaration ------------------------------------------------
void getWordsinStruct_Indices (struct WordInText*);
void getWordsinStruct_Adres (struct WordInText*);


// ************************************************************************************
// MAIN								-	Consolen ausgabe
// ************************************************************************************
int main(int argc, char* argv[]) {
//	struct WordInText WordsInText;

	char TheText[MAX_LENGTH_TEXT] = "Blub Blubber am Blubbesten";		// Hier kommt der Text rein
	memcpy((void*) &WordsInText.text,(void*) &TheText, MAX_LENGTH_TEXT * sizeof(char));

	getWordsinStruct_Indices(&WordsInText);
	for(int i = 0; i < WordsInText.index_words; i++){			// Gebe Indices aus
		printf("%d ",WordsInText.index[i]);
	}
	printf("\n");

	getWordsinStruct_Adres(&WordsInText);
	for(int i = 0; i < WordsInText.adres_words; i++){			// Gebe Adressen aus
		printf("%p ",WordsInText.adr[i]);
	}

	return 0;
}


// ************************************************************************************
// getWordsinStruct_Indices			-	Füllt den Struckt mit den Indices der einzelnen Wörter
// ************************************************************************************
void getWordsinStruct_Indices (struct WordInText *struct_ptr) {
	int i = 0;
	int wordcount = 0;
	if((*struct_ptr).text[i] != '\0') {				// Falls ein Wort da ist
		(*struct_ptr).index[0] = 0;					// Fülle erste Position mit 0
		++wordcount;
		++i;
	}

	while ((*struct_ptr).text[i] != '\0') {		
		if ((*struct_ptr).text[i] == ' ') {			// Falls ein Lehrzeichen gefunden wurde
			(*struct_ptr).index[wordcount] = i + 1;
			++wordcount;
			i += 2;
		} else {									// Falls KEIN ein Lehrzeichen gefunden wurde
			i += 1;
		}
	}
	(*struct_ptr).index_words = wordcount;
}


// ************************************************************************************
// getWordsinStruct_Adres			-	Füllt den Struckt mit den Adressen der einzelnen Wörter
// ************************************************************************************
void getWordsinStruct_Adres (struct WordInText *struct_ptr) {
	int i = 0;
	int wordcount = 0;

	if((*struct_ptr).text[i] != '\0') {				// Falls ein Wort da ist
		(*struct_ptr).adr[0] = &(*struct_ptr).text[0];	// Fülle erste Position mit 0
		++wordcount;
		++i;
	}

	while ((*struct_ptr).text[i] != '\0') {
		if ((*struct_ptr).text[i] == ' ') {			// Falls ein Lehrzeichen gefunden wurde
			(*struct_ptr).adr[wordcount] = &(*struct_ptr).text[i + 1];
			++wordcount;
			i += 2;
		} else {									// Falls KEIN ein Lehrzeichen gefunden wurde
			i += 1;
		}
	}
	(*struct_ptr).adres_words = wordcount;
}

