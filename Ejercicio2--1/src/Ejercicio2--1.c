/*
 ============================================================================
 Name        : Ejercicio2--1.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio2-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero;
	int promedio;
	int i;
	int acumulador;

	//inicializar
	acumulador = 0;

	for(i=0; i<3;i++){
		printf("ingrese un numero \n");
		scanf("%d", &numero);
		acumulador = acumulador + numero;
	}

	promedio = acumulador / 3;
	printf("el promedio es %d", promedio);
	return 0;
}
