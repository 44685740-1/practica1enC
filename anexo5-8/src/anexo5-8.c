/*
 ============================================================================
 Name        : anexo5-8.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : anexo5-8
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "promedioArrayEdad.h"
int main(void) {
	setbuf(stdout, NULL);
	int arrayEdades[5];
	int retornoValidacionPromedio;
	float promedio;
	// el asterisco * asigna el valor
	// el & la direccion de memoria a la que apunta
	retornoValidacionPromedio = promedioArrayEdad(arrayEdades, &promedio);
	printf("%d", retornoValidacionPromedio);
	if(retornoValidacionPromedio == 0){
		//pasar promedio por puntero
		printf(" main %.2f", promedio);//el .2 despues de la mascara indica que tiene que tener 2 numeros despues de la coma
	}
	return 0;
}
