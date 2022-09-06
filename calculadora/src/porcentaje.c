/*
 * porcentaje.c
 *
 *  Created on: 3 sep. 2022
 *      Author: ahuit
 */
#include "validacionDividirDosNumeros.h"
#include "dividirDosEnteros.h"
int porcentajeDosEnteros(int numero1, int numero2){
	int retorno;
	int division;
	division = dividirDosEnteros(numero1, numero2);
	retorno = division * 100;
	return retorno;
}

