/*
 * dividirDosEnteros.c
 *
 *  Created on: 1 sep. 2022
 *      Author: ahuit
 */
#include <stdio.h>
#include <stdlib.h>
int dividirDosEnteros(int dividendo, int divisor){
	setbuf(stdout, NULL);
	int retorno;
	retorno = dividendo / divisor;
	return retorno;

}

