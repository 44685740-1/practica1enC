/*
 ============================================================================
 Name        : ordenar5numeros.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ordenar5numeros.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "ordenarArray.h"
int main(void) {
	setbuf(stdout, NULL);
	int arrayNumeros[5];

	for (int i = 0; i < 5; i++) {
		arrayNumeros[i] = 1;
	}

	for (int i = 0; i < 5; i++) {
		printf("ingrese un numero");
		scanf("%d", &arrayNumeros[i]);
	}

	printf("antes del ordenamiento\n");
	for (int i = 0; i < 5; i++) {
		printf("%d", arrayNumeros[i]);
	}

	//funcion de ordenar array
	ordenarArray(arrayNumeros, 5);

	printf("\ndespues de ordenar el array\n");

	for (int i = 0; i < 5; i++) {
		printf("%d", arrayNumeros[i]);
	}

	return 0;
}
