/*
 * validacionFahrenheit.c
 *
 *  Created on: 5 sep. 2022
 *      Author: ahuit
 */
int validacionFahrenheit(int temperatura) {
	int retorno;
	if (temperatura >= 32 && temperatura <= 212) {
		retorno = 0;
	} else {
		retorno = -1;
	}
	return retorno;
}

