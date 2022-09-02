/*
 ============================================================================
 Name        : ejercicio1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio1-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL); //importante sino no funciona
	int numeroUno;
	int numeroDos;
	int resultado;

	printf("ingrese un numero \n");
	scanf("%d", &numeroUno);
	printf("ingrese un numero \n");
	scanf("%d", &numeroDos);

	resultado = numeroUno + numeroDos;

	printf("El resultado es: %d", resultado);

	return 0;
}
