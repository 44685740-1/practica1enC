/*
 ============================================================================
 Name        : utnValidacionesRobadas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesInput.h"
int main(void) {
	setbuf(stdout, NULL);
	float numero;
	utn_getFloat("ingrese un nuemro flotante", "ERROR", 2, 10, 0, 1000, 1, &numero);
	printf("%f", numero);
	return 0;
}
