/*
 * uebung7_a3.c
 *
 *  Created on: 14 Dec 2016
 *      Author: Oliver Heil
 * Description: Reihenentwicklung der Exponentialfunktion
 */

// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>


// ------------- Forward declaration ------------------------------------------------
double rowexpo(double, int);



int main(int argc, char* argv[]) {
	// ------------- Declare variables ----------------------------------------------
	double val = 2.456;
	int glied = 15;
//
//	double val = 1.00;
//	int glied = 0;
//
//	double val = 36.44;
//	int glied = 6;

//	double val = 0.00;
//	int glied = 15;

	// ------------- Here is where the Magic happens ---------------------------------
	printf("%f",rowexpo(val,glied));

	return 0;
}

double rowexpo(double powOfe, int glied) {
	int fakul = 1;
	double result = 0;
	double expon = 1;

	for(int i= 0; i < glied; i++, fakul = fakul * i, expon = expon * powOfe) {
		result += expon/fakul;
	}

	return result;
}

