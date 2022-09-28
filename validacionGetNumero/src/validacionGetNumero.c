/*
 ============================================================================
 Name        : validacionGetNumero.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : validacionGetNumero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getNumero.h"
int main(void) {
	setbuf(stdout, NULL);
	char mensaje[6] = {'n', 'u', 'm', 'e', 'r', 'o'};
	char errorMensaje[5] = {'E', 'R', 'R', 'O', 'R'};
	int maximo;
	int minimo;
	int reintentos;
	int pResultado;
	int retornoGetNumero;
	//incializar
	maximo = 3;
	minimo = 0;
	reintentos = 1;
	pResultado = 2;
	retornoGetNumero = getNumero(mensaje, errorMensaje, pResultado, maximo, minimo, reintentos);
	printf("%d", retornoGetNumero);
	printf("%d", pResultado);
	return 0;
}
