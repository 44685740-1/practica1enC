/*
 ============================================================================
 Name        : pruebaLibrerias.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : pruebaLibrerias.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "dividirDosEnteros.h"
int main(void) {
	setbuf(stdout, NULL);
	int dividendo;
	int divisor;
	int resultado;
	printf("ingrese el dividendo");
	scanf("%d", &dividendo);
	printf("ingrese el divisor");
	fflush(stdin);
	scanf("%d", &divisor);
	resultado = dividirDosEnteros(dividendo,divisor);
	printf("%d", resultado);
	return 0;
}
