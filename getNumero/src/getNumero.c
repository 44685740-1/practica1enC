/*
 ============================================================================
 Name        : getNumero.c
 Author      : Ahuitz Carcciolo
 Version     :
 Copyright   : Your copyright notice
 Description : getNumero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getNuemero.h"
int main(void) {
	setbuf(stdout, NULL);
	int pResultado;
	int retornoGetNumero;
	retornoGetNumero = getNumero(&pResultado, "ingrese un numero", "error", 0, 3, 2);
	printf("%d", retornoGetNumero);
	printf("%d", pResultado);

	return 0;
}
