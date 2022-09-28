/*
 ============================================================================
 Name        : ejercicio6-2.c
 Author      : Ahuitz Caracciolo
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio6-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>//biblioteca de strings
#include "inicializarArray.h"
#include "ordenarArray.h"
#include "mostrarArray.h"
#define VUELTAS 5
int main(void) {
	setbuf(stdout, NULL);
	int arrayNumeros[VUELTAS];
	//inicilizo el array en c antes de empezar a pedir los verdaderos numeros
	incializarArray(arrayNumeros, VUELTAS);

	for(int i=0;i<VUELTAS;i++){
		printf("\ningrese un numero\n");
		scanf("%d", &arrayNumeros[i]);
	}
	printf("sin ordenar\n");
	mostrarArray(arrayNumeros, VUELTAS);
	ordenarArrayCrecientePositivos(arrayNumeros, VUELTAS);
	printf("ordenado\n");
	mostrarArray(arrayNumeros, VUELTAS);
	return 0;
}
