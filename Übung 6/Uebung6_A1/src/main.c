/* A simple program for calculation decimal(only positive) to binary
 *
 * Created by Oliver Heil @ 13.6.2017
 */

#include <stdio.h>

#define BIN_NUMBER_LENGTH 32    // Maximal count of binary digits


int main(int argc, char *argv[]) {
    short bin_number[BIN_NUMBER_LENGTH];

    unsigned int dec_number[] = {
            56,
            8,
            0,
            96758,
            1
    };

    for (int j = 0; j < 5; ++j) {
        unsigned int rest, tempNum = dec_number[j], index = 0;

        do {
            rest = tempNum % 2;             // Rest abspeichern
            tempNum = tempNum / 2;          // Decmalzahl durch 2 teilen

            if (rest > 0) {                 // Rest �berpr�fen
                bin_number[index] = 1;
            } else {
                bin_number[index] = 0;
            }
            index++;
        } while (tempNum > 0);

        printf("\n The binary number Of %d is:\t", dec_number[j]);
        for (int i = index; i > 0; i--) {    // Array von hinten nach vorne lesen um richtige reihenfolge zu bekommen
            printf(" %d", bin_number[i - 1]);
        }
    }

    return 0;
}