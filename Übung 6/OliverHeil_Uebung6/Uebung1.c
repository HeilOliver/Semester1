/*
 * Uebung1.c
 *
 *  Created on: 16.11.2016
 *      Author: Oliver H
 * Description: Umrechnung von Dec in Binär
 */
		// ------------- Declare Includes -----------------------------------------------
#include <stdio.h>

		// ------------- Declare definitions --------------------------------------------
#define BIN_ZAHL_LENGTH 32


int main(int argc, char* argv[]) {
		// ------------- Declare variables -----------------------------------------------
        unsigned int rest, index = 0;
        short bin_zahl[BIN_ZAHL_LENGTH];

        unsigned int dec_zahl = 56;
//        unsigned int dec_zahl = 8;
//        unsigned int dec_zahl = 0;
//        unsigned int dec_zahl = 96758;
//        unsigned int dec_zahl = 1;


        // ------------- Here is where the Magic happens ---------------------------------
        do {
			rest = dec_zahl % 2;						// Rest abspeichern
			dec_zahl = dec_zahl / 2;					// Decmalzahl durch 2 teilen

			if(rest > 0) {								// Rest überprüfen
				bin_zahl[index]	= 1;
			} else {
				bin_zahl[index]	= 0;
			}
			index++;
		} while(dec_zahl > 0);


        // ------------- Output -----------------------------------------------------------
        printf("\n Die Binaere Zahl lautet:");
        for (int i = index; i > 0; i--) {				// Array von hinten nach vorne lesen um richtige reihenfolge zu bekommen
        	printf(" %d",bin_zahl[i-1]);
        }

        return 0;
}
