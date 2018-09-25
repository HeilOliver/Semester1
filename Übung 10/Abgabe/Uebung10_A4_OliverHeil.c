/*
 * uebung10_a2.c
 *
 *  Created on: 20 JAN 2017
 *      Author: Oliver Heil
 * Description: Rekursive Berechnung der Summe
 */

// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// ------------- Forward declaration ------------------------------------------------
unsigned int getNumInPascal_Triangle(unsigned int row,unsigned int column);



// ************************************************************************************
// MAIN
// ************************************************************************************
int main(int argc, char* argv[]) {
	int erweiterungen = 0;													// Gibt die Anzahl der Erweiterungen an, Maximal 13 da Ausgabe auf 4Ziffern beschränkt.

    for (int cur_row = 0; cur_row < erweiterungen; cur_row++) {					// Geht alle Erweiterungen durch
        for (int spaces = 0; spaces < 2*(erweiterungen-cur_row); spaces ++) {	// Fülle mit Lehrzeichen auf bis zum Start
            printf(" ");
        }

        for (int column = 0; column <= cur_row; column++) {						// Fülle die einzelnen Positionen
            printf("%*i", 4, getNumInPascal_Triangle(cur_row, column));
        }
        printf("\n");
    }

	return 0;
}


// ************************************************************************************
// num_pascal_triangle			- Gibt die jeweilige zahl an der Position im Dreieck zurück
// ************************************************************************************
unsigned int getNumInPascal_Triangle(unsigned int row,unsigned int column) {
	if (row == 0 || column == 0 || row==column) {							// Falls ein ende erreicht wurde, Oben oder Seite
		return 1;
	} else {
		return getNumInPascal_Triangle(row-1, column-1) + getNumInPascal_Triangle(row-1, column);
	}
}

