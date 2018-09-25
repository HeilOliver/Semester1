/*
 * uebung8_a2.c
 *
 *  Created on: 19 Dec 2016
 *      Author: Oliver Heil
 * Description: Wurzel via näherungsverfahren
 */

// ------------- Declare Includes ---------------------------------------------------
#include <stdio.h>


// ------------- Forward declaration ------------------------------------------------
double WurzelViaHeron(float, double);



// ------------- MAIN ---------------------------------------------------------------
int main (void) {
	// ------------- Declare variables ----------------------------------------------
	float wurzel = 5.0;
	float genauigkeit = 0.00002;

//	float wurzel = 0;
//	float genauigkeit = 0.00000000000006;

//	float wurzel = 39876;
//	float genauigkeit = 0.000004;

//	float wurzel = 39876;
//	float genauigkeit = 1;



	// ------------- Here is where the Magic happens ---------------------------------
	printf("%.10f\n",WurzelViaHeron(genauigkeit, wurzel));


	return 0;
}



// ------------- WURZEL VIA HERON ----------------------------------------------------
double WurzelViaHeron(float prezision, double wurzel) {
	//Erste näherung - geteilt durch zwei
	double w_value_n = wurzel /2;
	double w_value_o;

	double w_deviation = prezision + 1;

	// Exeption wenn Wurzel von 0
	if (0 == wurzel) {
		return 0;
	}

	//Durchläuft das ganze bis genauigkeit erreicht
	for(int n = 1; w_deviation > prezision; n++) {
		w_value_o = w_value_n;
		w_value_n = 0.5 * (w_value_n + wurzel / w_value_o);

		w_deviation = (w_value_n - w_value_o);
		if (w_deviation < 0) {
			w_deviation = w_deviation * -1;
		}
	}
	return w_value_n;
}
