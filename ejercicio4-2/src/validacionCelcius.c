/*
 * validacionCelcius.c
 *
 *  Created on: 5 sep. 2022
 *      Author: ahuit
 */
int validacionCelcius(int temperatura){
	int retorno;
	if(temperatura >= 0 && temperatura <= 100){
		retorno = 0;
	} else{
		retorno = -1;
	}
	return retorno;
}

