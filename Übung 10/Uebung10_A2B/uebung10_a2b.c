/*
 * uebung10_a2b.c
 *
 *  Created on: 20 JAN 2017
 *      Author: Oliver Heil
 * Description: Wortlängenstatistik
 */


// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// ------------- Global Variablen ---------------------------------------------------
typedef struct WordList_Node {
    int length;
    char* adr;
    struct WordList_Node* next;
} WLNode_t;


// ------------- Forward declaration ------------------------------------------------
WLNode_t* WordLengthStatistik_fill(char* text);
WLNode_t* SaveToList(WLNode_t* entryPoint, unsigned int word_length,char* word_adres);
void WordLengthStatistik_print(WLNode_t* entryPoint, char text[]);
void WordLengthStatistik_printWort(unsigned int length, char* word_adr);
void WordLengthStatistik_free(WLNode_t* entryPoint);


// ************************************************************************************
// MAIN
// ************************************************************************************
int main(int argc, char* argv[]) {
	char Mytext[] = "Am zehnten Tage dieses Monats nehme ein jeglicher ein Lamm, wo ein Hausvater ist, je ein Lamm zu einem Haus. Wo ihrer aber in einem Hause zu einem Lamm zu wenig sind, so nehme ers und sein naechster Nachbar an seinem Hause, bis ihrer so viel wird, daß sie das Lamm aufessen koennen";
	WLNode_t* Data = WordLengthStatistik_fill(Mytext);
	WordLengthStatistik_print(Data,Mytext);
	WordLengthStatistik_free(Data);

	return 0;
}


// ************************************************************************************
// WordLengthStatistik_fill			- Füllt den word_length_statistik_struct mit Wortlängen und Adressen der Wörter
// ************************************************************************************
WLNode_t* WordLengthStatistik_fill(char text[]) {
	WLNode_t* entryPoint = NULL;

	unsigned int curr_pos = 0;
	unsigned int word_length;
	char* word_adres;

	while (text[curr_pos] != '\0') {
		word_length = 0;
		word_adres = &text[curr_pos];

		while((text[curr_pos] >= 'A' && text[curr_pos] <= 'Z') || (text[curr_pos] >= 'a' && text[curr_pos] <= 'z')){
			++word_length;
			++curr_pos;
		}
		if (word_length != 0) {
			entryPoint = SaveToList(entryPoint, word_length,word_adres);
		} else {
			++curr_pos;
		}
	}
	return entryPoint;
}


// ************************************************************************************
// SaveToList		- Speichert die Wörter in einer Linked List (sortiert nach länge!)
// ************************************************************************************
WLNode_t* SaveToList(WLNode_t* entryPoint, unsigned int word_length,char* word_adres) {
	WLNode_t* newData = malloc(sizeof(WLNode_t));
	if (newData == NULL) {
		return NULL;
	}
	newData->adr = word_adres;
	newData->length = word_length;
	newData->next = NULL;

	if (entryPoint == NULL) {

			return newData;
	}

	WLNode_t* oldData = NULL;
	WLNode_t* nextData = entryPoint;
	int nextData_length = nextData->length;
	while (nextData_length <= newData->length && nextData_length > 0) {		// Suche nach geeigneter Position
		oldData = nextData;
		nextData = (void*)oldData->next;
		if (nextData != NULL) {
			nextData_length = nextData->length;
		} else {
			nextData_length = -1;
		}
	}

	newData->next = nextData;
	if (oldData != NULL)  {
		oldData->next = newData;
	} else {
		return newData;
	}

	return entryPoint;
}


// ************************************************************************************
// WordLengthStatistik_print		- Gibt den word_length_statistik_struct in der Console aus
// ************************************************************************************
void WordLengthStatistik_print(WLNode_t* entryPoint, char text[]) {
	printf("Original Text:\n %s\n\n",text);
	WLNode_t* nextData = entryPoint;
	unsigned int searchWordLength = 0;
	unsigned int foundSearchWordLength = 0;

	while (nextData != NULL) {																	// Geht bis ans Ende Welt/Liste
				if(searchWordLength != nextData->length) {
					if(searchWordLength != 0){
						printf("\tLänge %d, %d mal gefunden!\n-----------------------------------\n",searchWordLength,foundSearchWordLength);
					}
					searchWordLength = nextData->length;
					foundSearchWordLength = 1;
				} else {
					++foundSearchWordLength;
				}
				printf("Word: ");
				WordLengthStatistik_printWort(nextData->length,nextData->adr);					// Gibt nur das Wort aus
				printf("\tLength: %d\n", nextData->length);
				nextData = nextData->next;
	}
	if(searchWordLength != 0){
		printf("\tLänge %d, %d mal gefunden!\n",searchWordLength,foundSearchWordLength);
	} else {
		printf(":( Nichts gefunden");
	}
}



// ************************************************************************************
// WordLengthStatistik_printWort	- Gibt ein Wort anhand seines indexes und länge auf der console aus
// ************************************************************************************
void WordLengthStatistik_printWort(unsigned int length, char* word_adr) {
	for(unsigned int i = 0; i < length; i++) {					// Gibt jeden Char einzeln aus
		printf("%c",word_adr[i]);
	}
}



// ************************************************************************************
// WordLengthStatistik_free			- Gibt die LinkedList im heap wieder Frei
// ************************************************************************************
void WordLengthStatistik_free(WLNode_t* entryPoint) {
	WLNode_t* nextData = entryPoint;
	WLNode_t* oldData = NULL;

	while (nextData != NULL) {
		oldData = nextData;
		nextData = oldData->next;
		free(oldData);
	}
}

