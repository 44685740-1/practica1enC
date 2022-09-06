/*
 * validacionNumeroPositivo.c
 *
 *  Created on: 5 sep. 2022
 *      Author: ahuit
 */
//hago de vuelta la validacion de si el numero es positivo
int validacionNumeroPositivo(int numero){
	int retorno;
	if(numero > 0){
		retorno = 0;
	} else{
		retorno = -1;
	}
	return retorno;
}


