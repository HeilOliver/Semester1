/*
 * Uebung4.c
 *
 *  Created on: 16.11.2016
 *      Author: Oliver H
 * Description: Rechner
 */
	// ------------- Declare Includes -----------------------------------------------
#include <stdio.h>

	// ------------- Declare definitions --------------------------------------------
#define FALSE 0
#define TRUE 1



int main(int argc, char* argv[]) {
	// ------------- Declare variables ----------------------------------------------
    int result, value0 = 0, value1 = 0, expr_pointer = 0, error = FALSE;
    char operator;


    // ------------- Declare expresion ----------------------------------------------
//    const char expr[] = {"2 / 0 - 4 + 6 ="};				// Fehler da geteilt durch 0
    const char expr[] = {"1 ="};							// 1
//    const char expr[] = {"1 + 5 * 3 + 4 ="};				// 22
//    const char expr[] = {"5 / 2 ="};						// 2
//    const char expr[] = {"1 + 8 - 4 / 2 + 8 / 4 * 6 ="};	// 12
//    const char expr[] = {"1 x 2 ="};						// Fehler da x != *


    // ------------- Here is where the Magic happens ---------------------------------
    value1 = expr[expr_pointer] - '0';						// Set Value1 auf erste Zahl
    expr_pointer += 2;

    while (expr[expr_pointer] != '=' && error == FALSE){

    	operator = expr[expr_pointer];						// Set Operator
    	expr_pointer += 2;

    	value0 = expr[expr_pointer] - '0'; 					// Set Value0 auf nächste Zahl
    	expr_pointer += 2;

    	switch (operator) {									// Wählt rechenoperation aus und rechnet
    	case '+':
    		value1 = value1 + value0;
		break;

    	case '-':
    		value1 = value1 - value0;
		break;

    	case '*':
    		value1 = value1 * value0;
		break;

    	case '/':
		if (value0 != 0) {
			value1 = value1 / value0;
			break;
		}
		/* no break */

    	default:
    		error = TRUE;
		break;
    	}
    }


    // ------------- Output -----------------------------------------------------------
    if(error == FALSE) {
        result = value1;
        printf("%d",result);
    } else {
    	printf("Fehler");
    }

 return 0;
}
